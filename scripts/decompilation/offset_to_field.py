#!/usr/bin/env python3
"""Parse C header files to map (struct, offset) -> field_name.

Reads struct definitions from black/ headers and builds a lookup table
mapping byte offsets to field names. Handles:
  - Explicit offset comments: /* 0x50 */
  - Implicit offsets (sequential field layout with known sizes)
  - Nested struct padding via inheritance comments

Usage:
    # As a library
    from offset_to_field import FieldMapper
    mapper = FieldMapper("/path/to/black/")
    name = mapper.lookup("Object", 0x50)  # -> "scale"

    # Standalone: dump all mappings
    python3 scripts/decompilation/offset_to_field.py
"""

import re
import sys
from pathlib import Path
from dataclasses import dataclass


# Standard C type sizes for i686 (32-bit MSVC)
TYPE_SIZES = {
    "char": 1, "signed char": 1, "unsigned char": 1,
    "int8_t": 1, "uint8_t": 1, "bool": 1,
    "short": 2, "unsigned short": 2, "int16_t": 2, "uint16_t": 2,
    "int": 4, "unsigned int": 4, "unsigned": 4,
    "long": 4, "unsigned long": 4,
    "int32_t": 4, "uint32_t": 4, "bool32_t": 4,
    "float": 4, "double": 8,
    "size_t": 4, "ptrdiff_t": 4,
    # Pointers are 4 bytes on 32-bit
}

# Known base class sizes (manually maintained for key types)
# These cover the inheritance chain: GameThing -> GameThingWithPos -> Object
KNOWN_BASE_SIZES = {
    "GameThing": 0x10,
    "GameThingWithPos": 0x28,
    "Object": 0xFC,       # approximate
    "FixedObject": 0xFC,  # inherits Object
}


@dataclass
class FieldInfo:
    name: str
    offset: int
    size: int
    type_name: str


class FieldMapper:
    def __init__(self, header_dir: str | Path):
        self.header_dir = Path(header_dir)
        self._cache: dict[str, dict[int, FieldInfo]] = {}
        self._parse_all_headers()

    def _parse_all_headers(self):
        """Parse all .h files in the header directory."""
        for hfile in sorted(self.header_dir.glob("**/*.h")):
            self._parse_header(hfile)

    def _parse_header(self, filepath: Path):
        """Parse a single header file for struct/class definitions."""
        try:
            text = filepath.read_text()
        except Exception:
            return

        # Match C-style struct definitions (bw1-decomp uses C structs in headers)
        # Pattern: struct Name { ... };
        struct_pattern = re.compile(
            r'(?:struct|class)\s+(\w+)\s*(?::\s*public\s+(\w+))?\s*\{',
            re.MULTILINE,
        )

        for match in struct_pattern.finditer(text):
            struct_name = match.group(1)
            base_class = match.group(2)

            # Find the closing brace
            brace_start = match.end() - 1
            depth = 1
            pos = brace_start + 1
            while pos < len(text) and depth > 0:
                if text[pos] == '{':
                    depth += 1
                elif text[pos] == '}':
                    depth -= 1
                pos += 1

            body = text[brace_start + 1 : pos - 1]
            fields = self._parse_struct_body(body, base_class)

            if fields:
                self._cache[struct_name] = {f.offset: f for f in fields}

    def _parse_struct_body(self, body: str, base_class: str | None) -> list[FieldInfo]:
        """Parse field declarations from a struct body."""
        fields = []

        # Start offset from base class
        current_offset = KNOWN_BASE_SIZES.get(base_class, 0) if base_class else 0

        # Process line by line
        for line in body.split('\n'):
            line = line.strip()

            # Skip non-field lines
            if not line or line.startswith('//') or line.startswith('#') or line.startswith('/*'):
                continue
            if line.startswith('virtual') or line.startswith('static') or line.startswith('enum'):
                continue
            if '(' in line and ')' in line and '{' not in line:
                # Function declaration
                continue
            if line.startswith('DECLARE_') or line.startswith('typedef'):
                continue

            # Check for explicit offset comment: /* 0xNN */
            offset_match = re.search(r'/\*\s*0x([0-9a-fA-F]+)\s*\*/', line)

            # Parse field type and name
            # Handle: type name; or type name[N]; or type* name;
            field_match = re.match(
                r'(?:const\s+)?(?:struct\s+|class\s+|enum\s+)?'
                r'(\w[\w\s*]*?)\s+'      # type (may include pointer stars)
                r'(\w+)'                   # field name
                r'(?:\[(\d+)\])?'          # optional array size
                r'\s*;',
                line,
            )

            if not field_match:
                continue

            type_name = field_match.group(1).strip()
            field_name = field_match.group(2)
            array_size_str = field_match.group(3)

            # Determine offset
            if offset_match:
                offset = int(offset_match.group(1), 16)
                current_offset = offset
            else:
                offset = current_offset

            # Determine size
            is_pointer = '*' in type_name
            if is_pointer:
                field_size = 4  # 32-bit pointer
            elif type_name in TYPE_SIZES:
                field_size = TYPE_SIZES[type_name]
            else:
                field_size = 4  # default assumption for unknown types

            if array_size_str:
                field_size *= int(array_size_str)

            fields.append(FieldInfo(
                name=field_name,
                offset=offset,
                size=field_size,
                type_name=type_name,
            ))

            current_offset = offset + field_size

        return fields

    def lookup(self, struct_name: str, offset: int) -> str | None:
        """Look up field name by struct and byte offset."""
        fields = self._cache.get(struct_name, {})
        field = fields.get(offset)
        return field.name if field else None

    def lookup_with_type(self, struct_name: str, offset: int) -> FieldInfo | None:
        """Look up full field info by struct and byte offset."""
        fields = self._cache.get(struct_name, {})
        return fields.get(offset)

    def get_all_fields(self, struct_name: str) -> dict[int, FieldInfo]:
        """Get all fields for a struct."""
        return self._cache.get(struct_name, {})

    def get_all_structs(self) -> list[str]:
        """Get all known struct names."""
        return sorted(self._cache.keys())


def main():
    header_dir = Path(__file__).parent.parent.parent / "black"
    mapper = FieldMapper(header_dir)

    if len(sys.argv) > 2:
        struct_name = sys.argv[1]
        offset = int(sys.argv[2], 0)
        result = mapper.lookup_with_type(struct_name, offset)
        if result:
            print(f"{struct_name}+0x{offset:x} -> {result.type_name} {result.name} (size={result.size})")
        else:
            print(f"{struct_name}+0x{offset:x} -> NOT FOUND")
        return

    # Dump all structs with fields
    structs = mapper.get_all_structs()
    print(f"Parsed {len(structs)} structs from {header_dir}")
    print()

    # Show structs that have the most fields with explicit offsets
    for struct_name in structs:
        fields = mapper.get_all_fields(struct_name)
        if len(fields) < 3:
            continue
        print(f"\n{struct_name} ({len(fields)} fields):")
        for offset in sorted(fields.keys()):
            f = fields[offset]
            print(f"  0x{offset:04x}: {f.type_name:<20} {f.name}")


if __name__ == "__main__":
    main()
