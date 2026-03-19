#!/usr/bin/env python3
"""Tests for objdiff.py suggestion engine, alignment, and symbol index."""

import re
import unittest
from objdiff import (
    suggest_fixes, suggest_function_fixes,
    align_instructions, build_symbol_index, find_asm_function,
    bytes_match, ASM_DIR,
)


class TestOpcodeSuggestions(unittest.TestCase):
    """Test OPCODE_SUGGESTIONS (single-byte opcode pairs)."""

    def test_reversed_add(self):
        fixes = suggest_fixes(bytes([0x03, 0xC1]), bytes([0x01, 0xC8]))
        self.assertTrue(any("msvc6_regalloc" in f for f in fixes))

    def test_reversed_or(self):
        fixes = suggest_fixes(bytes([0x0B, 0xC1]), bytes([0x09, 0xC8]))
        self.assertTrue(any("msvc6_regalloc" in f for f in fixes))

    def test_reversed_xor(self):
        fixes = suggest_fixes(bytes([0x33, 0xC0]), bytes([0x31, 0xC0]))
        self.assertTrue(any("XOR32rr_REV" in f for f in fixes))

    def test_reversed_mov(self):
        fixes = suggest_fixes(bytes([0x8B, 0xC1]), bytes([0x89, 0xC8]))
        self.assertTrue(any("MOV32rr_REV" in f for f in fixes))

    def test_reversed_sub(self):
        fixes = suggest_fixes(bytes([0x2B, 0xC1]), bytes([0x29, 0xC8]))
        self.assertTrue(any("msvc6_regalloc" in f for f in fixes))

    def test_reversed_cmp(self):
        fixes = suggest_fixes(bytes([0x3B, 0xC1]), bytes([0x39, 0xC8]))
        self.assertTrue(any("msvc6_regalloc" in f for f in fixes))

    def test_prefer_xor8_vs_33(self):
        fixes = suggest_fixes(bytes([0x32, 0xC0]), bytes([0x33, 0xC0]))
        self.assertTrue(any("prefer_xor8" in f for f in fixes))

    def test_prefer_xor8_vs_31(self):
        fixes = suggest_fixes(bytes([0x32, 0xC0]), bytes([0x31, 0xC0]))
        self.assertTrue(any("prefer_xor8" in f for f in fixes))

    def test_matching_bytes_no_suggestion(self):
        fixes = suggest_fixes(bytes([0x8B, 0xC1]), bytes([0x8B, 0xC1]))
        self.assertEqual(fixes, [])


class TestPatternSuggestions(unittest.TestCase):
    """Test PATTERN_SUGGESTIONS (multi-byte prefix matching)."""

    def test_prefer_or_minus_one(self):
        fixes = suggest_fixes(
            bytes([0x83, 0xC8, 0xFF]),
            bytes([0xB8, 0xFF, 0xFF, 0xFF, 0xFF]))
        self.assertTrue(any("prefer_or_minus_one" in f for f in fixes))

    def test_prefer_pop_cleanup(self):
        fixes = suggest_fixes(
            bytes([0x59]),
            bytes([0x83, 0xC4, 0x04]))
        self.assertTrue(any("prefer_pop_cleanup" in f for f in fixes))

    def test_suppress_fp_imm_fldz(self):
        fixes = suggest_fixes(
            bytes([0xD9, 0xEE]),
            bytes([0xD9, 0x05, 0x00, 0x00, 0x00, 0x00]))
        self.assertTrue(any("suppress_fp_imm" in f for f in fixes))

    def test_suppress_fp_imm_fld1(self):
        fixes = suggest_fixes(
            bytes([0xD9, 0xE8]),
            bytes([0xD9, 0x05, 0x00, 0x00, 0x00, 0x00]))
        self.assertTrue(any("suppress_fp_imm" in f for f in fixes))

    def test_expand_movzx_from_xor(self):
        fixes = suggest_fixes(
            bytes([0x33, 0xC0]),
            bytes([0x0F, 0xB6, 0x41, 0x08]))
        self.assertTrue(any("expand_movzx" in f for f in fixes))

    def test_expand_movzx_any_expected(self):
        """movzx in compiled should suggest expand_movzx regardless of expected."""
        fixes = suggest_fixes(
            bytes([0x8B, 0x41, 0x08]),
            bytes([0x0F, 0xB6, 0x41, 0x08]))
        self.assertTrue(any("expand_movzx" in f for f in fixes))

    def test_prefer_sete_ecx(self):
        fixes = suggest_fixes(
            bytes([0x0F, 0x94, 0xC1]),
            bytes([0x0F, 0x94, 0xC0]))
        self.assertTrue(any("prefer_sete_ecx" in f for f in fixes))

    def test_prefer_sete_ecx_movzx(self):
        fixes = suggest_fixes(
            bytes([0x0F, 0xB6, 0xC1]),
            bytes([0x0F, 0xB6, 0xC0]))
        self.assertTrue(any("prefer_sete_ecx" in f for f in fixes))

    def test_prefer_neg_sbb_neg_eax(self):
        fixes = suggest_fixes(
            bytes([0xF7, 0xD8]),
            bytes([0x33, 0xC0]))
        self.assertTrue(any("prefer_neg_sbb" in f for f in fixes))

    def test_prefer_neg_sbb_sbb_vs_test(self):
        fixes = suggest_fixes(
            bytes([0x1B, 0xC0]),
            bytes([0x85, 0xC0]))
        self.assertTrue(any("prefer_neg_sbb" in f for f in fixes))

    def test_no_test_sete_fold_not_al(self):
        fixes = suggest_fixes(
            bytes([0xF6, 0xD0]),
            bytes([0xA8, 0x04]))
        self.assertTrue(any("no_test_sete_fold" in f for f in fixes))

    def test_no_test_sete_fold_shr_vs_sete(self):
        fixes = suggest_fixes(
            bytes([0xC1, 0xE8, 0x03]),
            bytes([0x0F, 0x94, 0xC0]))
        self.assertTrue(any("no_test_sete_fold" in f for f in fixes))

    def test_no_bool_mask_and_al(self):
        """and al,1 in compiled should suggest no_bool_mask."""
        fixes = suggest_fixes(
            bytes([0xC3]),  # expected: ret
            bytes([0x24, 0x01]))  # got: and al, 1
        self.assertTrue(any("no_bool_mask" in f for f in fixes))

    def test_no_bool_mask_and_eax(self):
        fixes = suggest_fixes(
            bytes([0xC3]),
            bytes([0x83, 0xE0, 0x01]))
        self.assertTrue(any("no_bool_mask" in f for f in fixes))

    def test_prefer_fmul_mem_fmulp(self):
        """fmulp in compiled should suggest prefer_fmul_mem."""
        fixes = suggest_fixes(
            bytes([0xD8, 0x0D, 0x00, 0x00, 0x00, 0x00]),
            bytes([0xDE, 0xC9]))
        self.assertTrue(any("prefer_fmul_mem" in f for f in fixes))

    def test_prefer_inc_dec_byte(self):
        fixes = suggest_fixes(
            bytes([0xFE, 0x81, 0x90, 0x00, 0x00, 0x00]),
            bytes([0x0F, 0xB6, 0x41, 0x08]))
        self.assertTrue(any("prefer_inc_dec_byte" in f for f in fixes))


class TestFunctionSuggestions(unittest.TestCase):
    """Test suggest_function_fixes (whole-function analysis)."""

    def _make_instrs(self, byte_list):
        """Helper: convert list of byte sequences to instruction tuples."""
        return [(b, "", set()) for b in byte_list]

    def test_no_callee_saves(self):
        expected = self._make_instrs([
            bytes([0x8B, 0xC1]),  # mov eax, ecx
            bytes([0xC3]),        # ret
        ])
        compiled = self._make_instrs([
            bytes([0x56]),        # push esi
            bytes([0x8B, 0xC1]),  # mov eax, ecx
            bytes([0x5E]),        # pop esi
            bytes([0xC3]),        # ret
        ])
        fixes = suggest_function_fixes(expected, compiled)
        self.assertTrue(any("no_callee_saves" in f for f in fixes))

    def test_forced_callee_saves_mismatch(self):
        expected = self._make_instrs([
            bytes([0x56]),        # push esi
            bytes([0x57]),        # push edi
            bytes([0xC3]),        # ret
        ])
        compiled = self._make_instrs([
            bytes([0x53]),        # push ebx
            bytes([0x56]),        # push esi
            bytes([0x57]),        # push edi
            bytes([0xC3]),        # ret
        ])
        fixes = suggest_function_fixes(expected, compiled)
        self.assertTrue(any("forced_callee_saves" in f for f in fixes))

    def test_no_ret(self):
        expected = self._make_instrs([
            bytes([0x8B, 0xC1]),  # mov eax, ecx (no ret)
        ])
        compiled = self._make_instrs([
            bytes([0x8B, 0xC1]),  # mov eax, ecx
            bytes([0xC3]),        # ret
        ])
        fixes = suggest_function_fixes(expected, compiled)
        self.assertTrue(any("no_ret" in f for f in fixes))

    def test_ret_cleanup_override_different_n(self):
        expected = self._make_instrs([
            bytes([0x8B, 0xC1]),
            bytes([0xC2, 0x04, 0x00]),  # ret 4
        ])
        compiled = self._make_instrs([
            bytes([0x8B, 0xC1]),
            bytes([0xC2, 0x08, 0x00]),  # ret 8
        ])
        fixes = suggest_function_fixes(expected, compiled)
        self.assertTrue(any("ret_cleanup_override" in f for f in fixes))
        self.assertTrue(any("ret 4" in f for f in fixes))

    def test_ret_cleanup_override_ret_vs_retn(self):
        expected = self._make_instrs([
            bytes([0xC2, 0x04, 0x00]),  # ret 4
        ])
        compiled = self._make_instrs([
            bytes([0xC3]),  # ret
        ])
        fixes = suggest_function_fixes(expected, compiled)
        self.assertTrue(any("ret_cleanup_override" in f for f in fixes))

    def test_expand_movzx_count(self):
        expected = self._make_instrs([
            bytes([0x33, 0xC0]),        # xor eax, eax
            bytes([0x8A, 0x41, 0x08]),  # mov al, [ecx+8]
            bytes([0xC3]),
        ])
        compiled = self._make_instrs([
            bytes([0x0F, 0xB6, 0x41, 0x08]),  # movzx eax, [ecx+8]
            bytes([0xC3]),
        ])
        fixes = suggest_function_fixes(expected, compiled)
        self.assertTrue(any("expand_movzx" in f for f in fixes))

    def test_prefer_fmul_mem_count(self):
        expected = self._make_instrs([
            bytes([0xD8, 0x0D, 0x00, 0x00, 0x00, 0x00]),  # fmul dword ptr [mem]
            bytes([0xC3]),
        ])
        compiled = self._make_instrs([
            bytes([0xD9, 0x05, 0x00, 0x00, 0x00, 0x00]),  # fld dword ptr [mem]
            bytes([0xDE, 0xC9]),                            # fmulp
            bytes([0xC3]),
        ])
        fixes = suggest_function_fixes(expected, compiled)
        self.assertTrue(any("prefer_fmul_mem" in f for f in fixes))

    def test_prefer_inc_dec_byte_count(self):
        expected = self._make_instrs([
            bytes([0xFE, 0x81, 0x90, 0x00, 0x00, 0x00]),  # inc byte ptr [ecx+0x90]
            bytes([0xC3]),
        ])
        compiled = self._make_instrs([
            bytes([0x0F, 0xB6, 0x81, 0x90, 0x00, 0x00, 0x00]),  # movzx eax, byte ptr
            bytes([0x83, 0xC0, 0x01]),                            # add eax, 1
            bytes([0x88, 0x81, 0x90, 0x00, 0x00, 0x00]),         # mov byte ptr, al
            bytes([0xC3]),
        ])
        fixes = suggest_function_fixes(expected, compiled)
        self.assertTrue(any("prefer_inc_dec_byte" in f for f in fixes))

    def test_matching_function_no_suggestions(self):
        instrs = self._make_instrs([
            bytes([0x8B, 0xC1]),
            bytes([0xC3]),
        ])
        fixes = suggest_function_fixes(instrs, instrs)
        self.assertEqual(fixes, [])

    def test_empty_inputs(self):
        self.assertEqual(suggest_function_fixes([], []), [])
        self.assertEqual(suggest_function_fixes(None, None), [])


class TestAlignment(unittest.TestCase):
    """Test Needleman-Wunsch instruction alignment."""

    def _make_instrs(self, byte_list):
        return [(b, f"instr_{i}", set()) for i, b in enumerate(byte_list)]

    def test_identical_sequences(self):
        instrs = self._make_instrs([b'\x8b\xc1', b'\xc3'])
        aligned = align_instructions(instrs, instrs)
        self.assertEqual(len(aligned), 2)
        for exp, got in aligned:
            self.assertIsNotNone(exp)
            self.assertIsNotNone(got)
            self.assertEqual(exp[0], got[0])

    def test_one_extra_in_compiled(self):
        """Compiled has an extra instruction; alignment should gap it."""
        expected = self._make_instrs([b'\x8b\xc1', b'\xc3'])
        compiled = self._make_instrs([b'\x8b\xc1', b'\x56', b'\xc3'])
        aligned = align_instructions(expected, compiled)
        # Should have 3 aligned pairs, with one gap
        self.assertEqual(len(aligned), 3)
        # First and last should match
        self.assertEqual(aligned[0][0][0], aligned[0][1][0])  # 8b c1
        self.assertEqual(aligned[2][0][0], aligned[2][1][0])  # c3
        # Middle should be a gap in expected
        self.assertIsNone(aligned[1][0])
        self.assertIsNotNone(aligned[1][1])

    def test_one_missing_in_compiled(self):
        """Expected has an extra instruction; alignment should gap it."""
        expected = self._make_instrs([b'\x8b\xc1', b'\x56', b'\xc3'])
        compiled = self._make_instrs([b'\x8b\xc1', b'\xc3'])
        aligned = align_instructions(expected, compiled)
        self.assertEqual(len(aligned), 3)
        self.assertEqual(aligned[0][0][0], aligned[0][1][0])
        self.assertEqual(aligned[2][0][0], aligned[2][1][0])
        self.assertIsNotNone(aligned[1][0])
        self.assertIsNone(aligned[1][1])

    def test_movzx_vs_xor_mov(self):
        """The classic expand_movzx case: 1 movzx vs 2 instructions (xor+mov)."""
        expected = self._make_instrs([
            b'\x33\xc0',        # xor eax, eax
            b'\x8a\x41\x08',   # mov al, [ecx+8]
            b'\xc3',            # ret
        ])
        compiled = self._make_instrs([
            b'\x0f\xb6\x41\x08',  # movzx eax, byte ptr [ecx+8]
            b'\xc3',               # ret
        ])
        aligned = align_instructions(expected, compiled)
        # ret should be aligned with ret
        ret_pairs = [(e, g) for e, g in aligned if e and g and e[0] == b'\xc3' and g[0] == b'\xc3']
        self.assertTrue(len(ret_pairs) >= 1, "ret should align with ret")

    def test_empty_expected(self):
        compiled = self._make_instrs([b'\xc3'])
        aligned = align_instructions([], compiled)
        self.assertEqual(len(aligned), 1)
        self.assertIsNone(aligned[0][0])
        self.assertIsNotNone(aligned[0][1])

    def test_empty_compiled(self):
        expected = self._make_instrs([b'\xc3'])
        aligned = align_instructions(expected, [])
        self.assertEqual(len(aligned), 1)
        self.assertIsNotNone(aligned[0][0])
        self.assertIsNone(aligned[0][1])

    def test_both_empty(self):
        aligned = align_instructions([], [])
        self.assertEqual(aligned, [])

    def test_complete_mismatch(self):
        """Totally different sequences still produce valid alignment."""
        expected = self._make_instrs([b'\x50', b'\x51'])
        compiled = self._make_instrs([b'\x52', b'\x53'])
        aligned = align_instructions(expected, compiled)
        self.assertEqual(len(aligned), 2)
        for exp, got in aligned:
            self.assertIsNotNone(exp)
            self.assertIsNotNone(got)


class TestRelocationMasking(unittest.TestCase):
    """Test relocation-aware byte comparison."""

    def test_identical_bytes_no_relocs(self):
        self.assertTrue(bytes_match(b'\xe8\x5b\x4e\xfa\xff', b'\xe8\x5b\x4e\xfa\xff', set()))

    def test_different_bytes_no_relocs(self):
        self.assertFalse(bytes_match(b'\xe8\x5b\x4e\xfa\xff', b'\xe8\x00\x00\x00\x00', set()))

    def test_call_relocation_masked(self):
        """call with relocation: opcode matches, displacement masked."""
        exp = b'\xe8\x5b\x4e\xfa\xff'  # call with linked displacement
        got = b'\xe8\x00\x00\x00\x00'  # call with unresolved displacement
        relocs = {1, 2, 3, 4}  # bytes 1-4 are relocation target
        self.assertTrue(bytes_match(exp, got, relocs))

    def test_mov_relocation_masked(self):
        """mov [disp32], imm with data relocation."""
        exp = b'\x8b\x0d\x5c\x19\xd0\x00'  # mov ecx, [0x00d0195c]
        got = b'\x8b\x0d\x00\x00\x00\x00'  # mov ecx, [reloc]
        relocs = {2, 3, 4, 5}
        self.assertTrue(bytes_match(exp, got, relocs))

    def test_opcode_mismatch_not_masked(self):
        """Different opcodes should not match even with relocations."""
        exp = b'\xe8\x5b\x4e\xfa\xff'  # call
        got = b'\xe9\x00\x00\x00\x00'  # jmp (different opcode!)
        relocs = {1, 2, 3, 4}
        self.assertFalse(bytes_match(exp, got, relocs))

    def test_different_lengths_no_match(self):
        self.assertFalse(bytes_match(b'\xe8\x5b\x4e\xfa\xff', b'\xc3', set()))


@unittest.skipUnless(ASM_DIR.exists(), "ASM files not present")
class TestSymbolIndex(unittest.TestCase):
    """Test the symbol index and find_asm_function with index."""

    def test_build_symbol_index_returns_dict(self):
        index = build_symbol_index()
        self.assertIsInstance(index, dict)
        self.assertGreater(len(index), 0)

    def test_known_symbol_in_index(self):
        """A known MSVC-mangled symbol should be in the index."""
        index = build_symbol_index()
        # Look for any ?-prefixed symbol (MSVC mangling)
        msvc_symbols = [k for k in index if k.startswith("?")]
        self.assertGreater(len(msvc_symbols), 0, "Should have MSVC-mangled symbols")

    def test_find_asm_function_known_symbol(self):
        """find_asm_function should return instructions for a known symbol."""
        index = build_symbol_index()
        # Pick a symbol that likely has instructions
        for symbol, (path, _) in index.items():
            if "runblack.reassemble" in str(path):
                instrs = find_asm_function(symbol)
                if instrs:
                    self.assertGreater(len(instrs), 0)
                    # Each instruction should be (bytes, str)
                    self.assertIsInstance(instrs[0][0], bytes)
                    self.assertIsInstance(instrs[0][1], str)
                    return
        self.skipTest("No suitable test symbol found")

    def test_find_asm_function_unknown_symbol(self):
        self.assertEqual(find_asm_function("?NoSuchSymbol@@QAEXXZ"), [])

    def test_label_on_same_line(self):
        """Labels with instruction on same line should include that instruction."""
        from objdiff import _BYTE_COMMENT_RE
        index = build_symbol_index()
        # Find labels that are on the same line as an instruction (byte comment at end of line)
        for symbol, (asm_file, line_idx) in index.items():
            with open(asm_file) as f:
                lines = f.readlines()
            if line_idx < len(lines):
                line = lines[line_idx]
                if ':' in line and _BYTE_COMMENT_RE.search(line):
                    instrs = find_asm_function(symbol)
                    self.assertGreater(len(instrs), 0,
                                       f"Label-on-same-line symbol {symbol} should have instructions")
                    return
        self.skipTest("No label-on-same-line symbols found")

    def test_local_labels_excluded(self):
        """Local labels (.Lbl_*, LAB*) should not appear in the index."""
        index = build_symbol_index()
        for symbol in index:
            self.assertFalse(symbol.startswith(".Lbl_"), f"Local label in index: {symbol}")
            self.assertFalse(symbol.startswith("LAB"), f"Local label in index: {symbol}")


if __name__ == "__main__":
    unittest.main()
