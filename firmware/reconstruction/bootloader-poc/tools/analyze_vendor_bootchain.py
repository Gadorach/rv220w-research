#!/usr/bin/env python3
"""Reproduce the RV220W bootcmd/recovery reconstruction from exact bytes.

The script is read-only. It accepts the preserved 512 KiB boot-chain image,
checks the matching 320 KiB extraction, resolves the late-init GOT references,
and emits a machine-readable proof report.
"""
from __future__ import annotations
import argparse, binascii, hashlib, json, pathlib, struct

BASE = 0xFFFFFFFFBFC00000
BOOT_SIZE = 0x80000
BOOT_SHA = "0630714e3e86edfeeed064088266c59524d970e0b74780e903b68b45e8982e7d"
UBOOT_OFF = 0x30000
UBOOT_SIZE = 0x50000
UBOOT_SHA = "1b68453e055dee56a8724b17a927df36ff201a44c8e450c5d17a3b8e9117000d"
LATE_INIT = 0x13084
GP = 0x436E0
STOCK_COMMAND_OFF = 0x363B0
STOCK_COMMAND = (
    b"cp.b BDC80000 0x2a00000 580000;bootoctlinux 0x2a00200 "
    b"mtdparts=phys_mapped_flash:512k(bootloader)ro,6M(kernel),16M(rootfs),"
    b"1024k(data),128k(bootload-env)"
)

def sha(data: bytes) -> str:
    return hashlib.sha256(data).hexdigest()

def be32(data: bytes, off: int) -> int:
    return struct.unpack_from(">I", data, off)[0]

def cstring(data: bytes, off: int, limit: int = 4096) -> str:
    end = data.find(b"\0", off, min(len(data), off + limit))
    if end < 0:
        raise ValueError(f"unterminated string at 0x{off:x}")
    return data[off:end].decode("ascii", errors="replace")

def require(condition: bool, message: str) -> None:
    if not condition:
        raise SystemExit(f"error: {message}")

def address(off: int) -> str:
    return f"0x{BASE + off:016x}"

def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument("boot_chain", type=pathlib.Path)
    ap.add_argument("--u-boot", type=pathlib.Path)
    ap.add_argument("--output", type=pathlib.Path, required=True)
    ns = ap.parse_args()

    data = ns.boot_chain.read_bytes()
    require(len(data) == BOOT_SIZE, f"boot-chain size is {len(data)}, expected {BOOT_SIZE}")
    require(sha(data) == BOOT_SHA, "boot-chain SHA-256 differs from preserved baseline")
    upper = data[UBOOT_OFF:UBOOT_OFF + UBOOT_SIZE]
    require(sha(upper) == UBOOT_SHA, "embedded U-Boot slice differs from preserved baseline")
    if ns.u_boot:
        separate = ns.u_boot.read_bytes()
        require(separate == upper, "separate U-Boot extraction is not byte-identical to boot-chain slice")

    # Reconstruct gp exactly from the PIC prologue: t9 + 0x30000 + 0x65c.
    require(be32(data, LATE_INIT + 0x08) == 0x3C1C0003, "late-init LUI gp instruction mismatch")
    require(be32(data, LATE_INIT + 0x18) == 0x279C065C, "late-init ADDIU gp instruction mismatch")
    computed_gp = (BASE + LATE_INIT + 0x30000 + 0x65C) & 0xFFFFFFFFFFFFFFFF
    require(computed_gp == BASE + GP, "late-init gp reconstruction mismatch")

    got_setenv = GP + 0x434
    got_checker = GP + 0x34C
    got_recovery = GP + 0x2D0
    got_base0 = GP + 0x10
    got_base1 = GP + 0x14
    setenv_wrapper = be32(data, got_setenv)
    checker = be32(data, got_checker)
    recovery = be32(data, got_recovery)
    string_base0 = be32(data, got_base0)
    string_base1 = be32(data, got_base1)

    require(setenv_wrapper == 0xBFC19B60, "late-init GOT does not resolve to recovered setenv wrapper")
    require(checker == 0xBFC22834, "firmware-check GOT target mismatch")
    require(recovery == 0xBFC22BD4, "HTTP-recovery GOT target mismatch")
    name_off = (string_base1 - 0x5260) - 0xBFC00000
    value_off = (string_base0 + 0x63B0) - 0xBFC00000
    require(name_off == 0x3ADA0 and cstring(data, name_off) == "bootcmd", "bootcmd name resolution failed")
    require(value_off == STOCK_COMMAND_OFF, "stock boot command pointer resolution failed")
    require(data[value_off:value_off + len(STOCK_COMMAND)] == STOCK_COMMAND, "stock boot command bytes mismatch")

    # Verify exact late-init control-flow bytes used by the patch generator.
    late_words = {f"0x{off:x}": f"0x{be32(data, off):08x}" for off in
                  (0x1312C, 0x13130, 0x13138, 0x1313C, 0x13140, 0x13148,
                   0x1314C, 0x13150, 0x13154, 0x13158, 0x1315C, 0x13160,
                   0x13164, 0x13168, 0x1316C)}
    require(be32(data, 0x13138) == 0x04410003, "firmware-check branch bytes mismatch")
    require(be32(data, 0x13168) == 0x03200008, "setenv tail-call bytes mismatch")

    # Verify setenv wrapper structure: local 32-bit argv table, argc=3, core call.
    require(be32(data, 0x19B84) == 0xAFA40004, "setenv wrapper does not store name into argv[1]")
    require(be32(data, 0x19B8C) == 0xAFA50008, "setenv wrapper does not store value into argv[2]")
    require(be32(data, 0x19B98) == 0x24050003, "setenv wrapper argc is not three")
    core_setenv = be32(data, GP + 0x72C)
    require(core_setenv == 0xBFC190F4, "setenv core GOT target mismatch")

    # Firmware checker constants and trailer.
    trailer_off = data.find(b"FWCHKADDISABABA\0")
    require(trailer_off == 0x41080, f"unexpected trailer string offset 0x{trailer_off:x}")
    require(data[0x22834:0x22838] != b"\xff" * 4, "firmware checker function missing")

    report = {
        "schema": "rv220w-bootchain-byte-proof-v1",
        "input": str(ns.boot_chain),
        "size": len(data),
        "sha256": sha(data),
        "crc32": f"{binascii.crc32(data) & 0xffffffff:08x}",
        "u_boot_slice": {
            "offset": UBOOT_OFF,
            "size": UBOOT_SIZE,
            "sha256": sha(upper),
            "separate_extraction_verified": bool(ns.u_boot),
        },
        "late_init": {
            "entry": address(LATE_INIT),
            "file_offset": LATE_INIT,
            "reconstructed_gp": address(GP),
            "bootcmd_name": {"offset": name_off, "address": address(name_off), "value": "bootcmd"},
            "stock_command": {"offset": value_off, "address": address(value_off),
                              "length_without_nul": len(STOCK_COMMAND),
                              "value": STOCK_COMMAND.decode("ascii")},
            "setenv_wrapper": f"0xffffffff{setenv_wrapper:08x}",
            "setenv_core": f"0xffffffff{core_setenv:08x}",
            "tail_call": {"offset": 0x13168, "original_be32": "0x03200008",
                          "meaning": "jr t9 (tail-call setenv)",
                          "suppression_be32": "0x03e00008",
                          "suppression_meaning": "jr ra (return without setting bootcmd)"},
            "firmware_check": f"0xffffffff{checker:08x}",
            "http_recovery": f"0xffffffff{recovery:08x}",
            "firmware_check_branch": {"offset": 0x13138, "original_be32": "0x04410003",
                                      "experimental_bypass_be32": "0x10000003"},
            "instruction_words": late_words,
        },
        "firmware_header_check": {
            "function": "0xffffffffbfc22834",
            "image_name_flash_address": "0xffffffffbdc80074",
            "image_size_flash_address": "0xffffffffbdc80010",
            "maximum_size": 0x02000000,
            "trailer_address_formula": "0xffffffffbdc80000 + image_size - 0x80",
            "trailer_magic": "FWCHKADDISABABA",
            "trailer_string_file_offset": trailer_off,
        },
        "board_data": {
            "base_mac_flash_offset": 0x6FF00,
            "actual_environment_flash_offset": 0x1FE0000,
            "actual_environment_size": 0x20000,
        },
        "patch_policy": {
            "upper_string_redirect": "preferred first persistent experiment; no lower code bytes changed",
            "suppress_force": "one-byte lower-region code change at 0x13169; external recovery required",
            "bypass_recovery": "two-byte lower-region branch change at 0x13138-0x13139; experimental only",
        },
    }
    ns.output.parent.mkdir(parents=True, exist_ok=True)
    ns.output.write_text(json.dumps(report, indent=2) + "\n", encoding="utf-8")
    print(ns.output)
    print("bootcmd override proof=passed")
    return 0

if __name__ == "__main__":
    raise SystemExit(main())
