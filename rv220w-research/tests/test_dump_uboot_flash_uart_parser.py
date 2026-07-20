#!/usr/bin/env python3
"""Regression tests for RV220W U-Boot md.b parsing."""
from __future__ import annotations

import importlib.util
import pathlib
import sys
import unittest

SCRIPT = pathlib.Path(__file__).resolve().parents[1] / "tools/uart/dump_uboot_flash_uart.py"
spec = importlib.util.spec_from_file_location("rv220w_uart_dumper", SCRIPT)
assert spec is not None and spec.loader is not None
module = importlib.util.module_from_spec(spec)
sys.modules[spec.name] = module
spec.loader.exec_module(module)


class MdParserTests(unittest.TestCase):
    def test_all_space_ascii_column_does_not_swallow_next_row(self) -> None:
        response = (
            b"bdc38630: 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20                    \r\n"
            b"bdc38640: 20 20 20 20 20 20 3a 20 25 36 64 20 70 73 0a 00          : %6d ps..\r\n"
            b"rv200w# "
        )
        parsed = module.parse_md_response(response, 0xBDC38630, 0x20)
        self.assertEqual(parsed[:0x10], b" " * 0x10)
        self.assertEqual(
            parsed[0x10:],
            bytes.fromhex("20 20 20 20 20 20 3a 20 25 36 64 20 70 73 0a 00"),
        )

    def test_conflicting_duplicate_rows_are_rejected(self) -> None:
        response = (
            b"bdc00000: 00 01 02 03                                      ....\r\n"
            b"bdc00000: 00 01 02 04                                      ....\r\n"
        )
        with self.assertRaises(module.DumpError):
            module.parse_md_response(response, 0xBDC00000, 4)


if __name__ == "__main__":
    unittest.main()
