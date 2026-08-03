#!/usr/bin/env python3
from __future__ import annotations

import importlib.util
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
TOOL = ROOT / "tools" / "rv220w_flash_combined_boot_policy.py"
spec = importlib.util.spec_from_file_location("flasher", TOOL)
assert spec and spec.loader
flasher = importlib.util.module_from_spec(spec)
sys.modules[spec.name] = flasher
spec.loader.exec_module(flasher)


def main() -> int:
    paths = flasher.validate_artifacts(ROOT / "artifacts")
    assert set(paths) == {"stock", "bootcmd-only", "http-only", "combined"}

    expected = {
        "stock": (0xCE86D667, bytes.fromhex("04410003"), bytes.fromhex("03200008")),
        "bootcmd-only": (0x36DB247B, bytes.fromhex("04410003"), bytes.fromhex("03e00008")),
        "http-only": (0x4F2766C2, bytes.fromhex("10000003"), bytes.fromhex("03200008")),
        "combined": (0xB77A94DE, bytes.fromhex("10000003"), bytes.fromhex("03e00008")),
    }
    for name, (crc, branch, bootcmd) in expected.items():
        data = paths[name].read_bytes()
        assert data[0x13138:0x1313C] == branch
        assert data[0x13168:0x1316C] == bootcmd
        assert flasher.EXPECTED[name]["crc32"] == crc

    stock = paths["stock"].read_bytes()
    combined = paths["combined"].read_bytes()
    diffs = [i for i, (a, b) in enumerate(zip(stock, combined)) if a != b]
    assert diffs == [0x13138, 0x13139, 0x13169]

    assert flasher.parse_crc32(
        "CRC32 for bdc00000 ... bdc1ffff ==> b77a94de\nrv200w#"
    ) == 0xB77A94DE
    assert flasher.parse_md_bytes(
        "bdc13168: 03 e0 00 08    ....\nrv200w#", 0xBDC13168, 4
    ) == bytes.fromhex("03e00008")

    flinfo_text = """
Bank # 1: CFI conformant FLASH (portwidth:16 x chipwidth: 16)  Size: 32 MB in 256 Sectors
 Erase timeout 4096 ms, write timeout 0 ms, buffer write timeout 2048 ms, buffer size 64
  Sector Start Addresses:
    BDC00000 (RO) BDC20000 (RO) BDC40000 (RO) BDC60000 (RO) BDC80000
    BFBE0000 (RO)
rv200w#
"""
    flasher.validate_flinfo(flinfo_text)

    # MIPS branch target remains PC+4 + (3 << 2) = 0xffffffffbfc13148.
    pc = 0xFFFFFFFFBFC13138
    assert pc + 4 + (3 << 2) == 0xFFFFFFFFBFC13148

    class FakeLogger:
        def line(self, text: str) -> None:
            pass

    class FakeConsole:
        def __init__(self) -> None:
            self.commands: list[str] = []

        def command(self, command: str, timeout: float = 10.0) -> str:
            self.commands.append(command)
            if command.startswith("cmp.b "):
                return "Total of 131072 bytes were the same\nrv200w#"
            responses = {
                "crc32 0x05700000 0x20000": "CRC32 for 05700000 ... 0571ffff ==> ce86d667\nrv200w#",
                "md.b 0x05713138 4": "05713138: 04 41 00 03\nrv200w#",
                "md.b 0x05713168 4": "05713168: 03 20 00 08\nrv200w#",
                "crc32 0x05500000 0x20000": "CRC32 for 05500000 ... 0551ffff ==> b77a94de\nrv200w#",
                "md.b 0x05513138 4": "05513138: 10 00 00 03\nrv200w#",
                "md.b 0x05513168 4": "05513168: 03 e0 00 08\nrv200w#",
            }
            return responses.get(command, "rv200w#")

    fake = FakeConsole()
    flasher.stage_verified_ram_images(fake, FakeLogger(), "stock", "combined")
    assert fake.commands == [
        "cp.b 0xbdc00000 0x05700000 0x20000",
        "cmp.b 0xbdc00000 0x05700000 0x20000",
        "crc32 0x05700000 0x20000",
        "md.b 0x05713138 4",
        "md.b 0x05713168 4",
        "cp.b 0x05700000 0x05500000 0x20000",
        "mw.b 0x05513138 0x10 1",
        "mw.b 0x05513139 0x00 1",
        "mw.b 0x05513169 0xe0 1",
        "crc32 0x05500000 0x20000",
        "md.b 0x05513138 4",
        "md.b 0x05513168 4",
    ]

    # The tool must remain serial-only and write only the first NOR sector.
    source = TOOL.read_text()
    assert "tftpboot" not in source
    assert "SingleFileTFTPServer" not in source
    assert "SECTOR_SIZE = 0x20000" in source
    assert '"combined": "RV220W_FLASH_COMBINED_BOOT_POLICY_PATCHES"' in source

    for failure in (
        "ERROR: flash operation failed",
        "Timed out waiting for device",
        "Retry count exceeded; starting again",
        "Unknown command 'erase'",
    ):
        try:
            flasher.ensure_no_command_error(failure, "test")
        except flasher.FlasherError:
            pass
        else:
            raise AssertionError(f"failure text was not rejected: {failure}")

    print("offline combined RV220W boot-policy flasher tests passed")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
