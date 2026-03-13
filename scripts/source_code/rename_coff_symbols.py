#!/usr/bin/env python3
"""
Rename symbols in a COFF object file's string table.

Supports both same-length and variable-length renames.
For variable-length renames, new strings are appended to the string table
and symbol table entries are updated to point to the new offsets.

Usage:
  rename_coff_symbols(path, {"old_sym": "new_sym", ...})
"""

import struct
from pathlib import Path

# COFF constants
_FILE_HDR_FMT = '<HHIIIHH'
_FILE_HDR_SIZE = struct.calcsize(_FILE_HDR_FMT)
_SYMBOL_SIZE = 18


def rename_coff_symbols(obj_path: Path, renames: dict[str, str]) -> int:
    """Rename symbols in a COFF .obj file in-place.

    Args:
        obj_path: Path to the COFF object file.
        renames: Mapping of old symbol name -> new symbol name.
                 Supports both same-length and variable-length renames.

    Returns:
        Number of symbols actually renamed.
    """
    data = bytearray(obj_path.read_bytes())

    # Parse file header to find symbol table
    (machine, num_sections, timestamp, sym_table_offset,
     num_symbols, opt_hdr_size, characteristics) = struct.unpack_from(_FILE_HDR_FMT, data, 0)

    if sym_table_offset == 0 or num_symbols == 0:
        return 0

    # String table starts right after the symbol table
    string_table_offset = sym_table_offset + num_symbols * _SYMBOL_SIZE

    # Read string table size (first 4 bytes)
    string_table_size = struct.unpack_from('<I', data, string_table_offset)[0]

    # Separate renames into same-length and variable-length
    same_len = {}
    var_len = {}
    for old_name, new_name in renames.items():
        old_bytes = old_name.encode('ascii')
        new_bytes = new_name.encode('ascii')
        if len(old_bytes) == len(new_bytes):
            same_len[old_bytes] = new_bytes
        else:
            var_len[old_bytes] = new_bytes

    count = 0

    # Handle same-length renames (simple byte substitution in string table)
    if same_len:
        string_table_end = string_table_offset + string_table_size
        pos = string_table_offset + 4  # skip the size field
        while pos < string_table_end:
            null_pos = data.index(b'\x00', pos)
            current_string = bytes(data[pos:null_pos])

            for old_bytes, new_bytes in same_len.items():
                if current_string == old_bytes:
                    data[pos:null_pos] = new_bytes
                    count += 1
                    break

            pos = null_pos + 1

    # Handle variable-length renames
    if var_len:
        # Build a map of string table offset -> symbol string for all symbols
        # Then scan symbol table entries to find which ones reference old names
        # For long names (>8 chars): first 4 bytes are 0, next 4 are string table offset
        # For short names (<=8 chars): 8-byte null-padded name

        # First, build map of old_name -> new string table offset
        # by appending new names to the end of the string table
        new_strings = bytearray()
        old_to_new_offset = {}

        for old_bytes, new_bytes in var_len.items():
            new_offset = string_table_size + len(new_strings)
            old_to_new_offset[old_bytes] = new_offset
            new_strings.extend(new_bytes)
            new_strings.append(0)  # null terminator

        # Scan symbol table entries
        i = 0
        while i < num_symbols:
            sym_offset = sym_table_offset + i * _SYMBOL_SIZE
            name_field = data[sym_offset:sym_offset + 8]

            # Check if this is a long name (first 4 bytes are zero)
            if name_field[:4] == b'\x00\x00\x00\x00':
                str_offset = struct.unpack_from('<I', name_field, 4)[0]
                # Read the string at this offset
                abs_offset = string_table_offset + str_offset
                null_pos = data.index(b'\x00', abs_offset)
                current_string = bytes(data[abs_offset:null_pos])

                if current_string in old_to_new_offset:
                    # Update the symbol table entry to point to new string
                    new_offset = old_to_new_offset[current_string]
                    struct.pack_into('<I', data, sym_offset + 4, new_offset)
                    count += 1
            else:
                # Short name - check if it matches any old name
                null_idx = name_field.find(b'\x00')
                if null_idx == -1:
                    short_name = bytes(name_field)
                else:
                    short_name = bytes(name_field[:null_idx])

                if short_name in old_to_new_offset:
                    # Convert to long name format: 4 zero bytes + 4 byte offset
                    new_offset = old_to_new_offset[short_name]
                    struct.pack_into('<II', data, sym_offset, 0, new_offset)
                    count += 1

            # Skip auxiliary symbol records
            num_aux = data[sym_offset + 17]
            i += 1 + num_aux

        if count > 0 or new_strings:
            # Append new strings to the data
            data.extend(new_strings)
            # Update string table size
            new_string_table_size = string_table_size + len(new_strings)
            struct.pack_into('<I', data, string_table_offset, new_string_table_size)

    if count > 0:
        obj_path.write_bytes(data)

    return count
