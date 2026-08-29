#!/usr/bin/env python3
"""Decode and conservatively audit a Linux SSB ``ssb_sprom`` dump.

Linux exposes this sysfs attribute as 4 hexadecimal characters per 16-bit word
plus a newline/NUL terminator.  This tool accepts that representation or an
already-decoded 440-byte image.  It is read-only and never writes hardware.

The output deliberately does *not* pronounce an invalid-CRC shadow safe for RF.
"""
from __future__ import annotations

import argparse
import hashlib
import json
import re
from pathlib import Path

HEX_RE = re.compile(rb"^[0-9A-Fa-f]+$")


def decode_input(path: Path) -> tuple[bytes, str, int]:
    data = path.read_bytes()
    stripped = data.rstrip(b"\x00\r\n\t ")
    if len(stripped) in (256, 880, 920, 936) and HEX_RE.fullmatch(stripped) and len(stripped) % 4 == 0:
        return bytes.fromhex(stripped.decode("ascii")), "linux-sysfs-ascii-hex", len(data)
    if len(data) in (128, 440, 460, 468):
        return data, "raw-binary", len(data)
    if HEX_RE.fullmatch(stripped) and len(stripped) % 2 == 0:
        decoded = bytes.fromhex(stripped.decode("ascii"))
        return decoded, "ascii-hex", len(data)
    raise ValueError(f"unsupported SPROM input: {len(data)} bytes and not recognized ASCII hex")


def u16le(raw: bytes, offset: int) -> int | None:
    if offset + 2 > len(raw):
        return None
    return int.from_bytes(raw[offset:offset + 2], "little")


def mac_at(raw: bytes, offset: int) -> str | None:
    if offset + 6 > len(raw):
        return None
    # Linux sprom_get_mac() emits the high byte and then low byte of each
    # 16-bit SPROM word.  The decoded sysfs byte stream is little-endian per
    # word, so swap each adjacent byte pair to match the driver's MAC view.
    b = raw[offset:offset + 6]
    b = bytes((b[1], b[0], b[3], b[2], b[5], b[4]))
    return ":".join(f"{x:02x}" for x in b)


def valid_unicast(mac: str | None) -> bool:
    if not mac:
        return False
    b = bytes.fromhex(mac.replace(":", ""))
    return b not in (b"\x00" * 6, b"\xff" * 6) and not (b[0] & 1)


def crc8_byte(crc: int, data: int) -> int:
    # Reflected form of the Broadcom SSB CRC-8 polynomial used by Linux.
    crc ^= data
    for _ in range(8):
        crc = ((crc >> 1) ^ 0xAB) if (crc & 1) else (crc >> 1)
    return crc & 0xFF


def sprom_crc(raw: bytes) -> int | None:
    if len(raw) < 2:
        return None
    crc = 0xFF
    # Last byte is the stored CRC; the preceding low byte contains revision.
    for b in raw[:-1]:
        crc = crc8_byte(crc, b)
    return crc ^ 0xFF


def word_block(raw: bytes, offset: int, size: int = 0x20) -> list[str]:
    end = min(offset + size, len(raw))
    return [f"{u16le(raw, p):04x}" for p in range(offset, end, 2)]


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument("input", type=Path)
    ap.add_argument("--decoded-bin", type=Path)
    ap.add_argument("--json", dest="json_path", type=Path)
    ap.add_argument("--text", dest="text_path", type=Path)
    args = ap.parse_args()

    try:
        raw, source_format, source_size = decode_input(args.input)
    except ValueError as exc:
        ap.error(str(exc))

    if args.decoded_bin:
        args.decoded_bin.write_bytes(raw)

    revision = raw[-2] if len(raw) >= 2 else None
    stored_crc = raw[-1] if len(raw) >= 1 else None
    calculated_crc = sprom_crc(raw)
    crc_valid = calculated_crc == stored_crc if calculated_crc is not None else None
    erased_words = sum(1 for p in range(0, len(raw) - 1, 2) if u16le(raw, p) == 0xFFFF)
    total_words = len(raw) // 2

    report: dict[str, object] = {
        "schema": "rv220w-ssb-sprom-analysis-v1",
        "input": str(args.input),
        "source_format": source_format,
        "source_size_bytes": source_size,
        "decoded_size_bytes": len(raw),
        "decoded_sha256": hashlib.sha256(raw).hexdigest(),
        "revision": revision,
        "stored_crc": stored_crc,
        "calculated_crc": calculated_crc,
        "crc_valid": crc_valid,
        "erased_words": erased_words,
        "total_words": total_words,
        "safe_for_rf": bool(crc_valid),
        "interpretation": "physical SPROM shadow evidence; invalid/incomplete data must not be used as RF calibration" if not crc_valid else "CRC-valid SPROM image; board identity/calibration still requires platform validation before RF",
    }

    if revision == 8 and len(raw) >= 440:
        il0 = mac_at(raw, 0x8C)
        txrxc = u16le(raw, 0xA2)
        report["rev8"] = {
            "subsystem_product_id": u16le(raw, 0x04),
            "subsystem_vendor_id": u16le(raw, 0x06),
            "pci_product_id": u16le(raw, 0x08),
            "board_rev": u16le(raw, 0x82),
            "boardflags_lo": u16le(raw, 0x84),
            "boardflags_hi": u16le(raw, 0x86),
            "boardflags2_lo": u16le(raw, 0x88),
            "boardflags2_hi": u16le(raw, 0x8A),
            "il0mac": il0,
            "il0mac_valid_unicast": valid_unicast(il0),
            "txrx_word": txrxc,
            "txchain": (txrxc & 0x000F) if txrxc is not None else None,
            "rxchain": ((txrxc & 0x00F0) >> 4) if txrxc is not None else None,
            "rssiparm2g": u16le(raw, 0xA4),
            "rssiparm5g": u16le(raw, 0xA6),
            "fem2g": u16le(raw, 0xAE),
            "core0_power_words": word_block(raw, 0xC0),
            "core1_power_words": word_block(raw, 0xE0),
            "core2_power_words": word_block(raw, 0x100),
            "core3_power_words": word_block(raw, 0x120),
        }

    crc_text = "unknown" if calculated_crc is None else f"0x{calculated_crc:02x}"
    stored_text = "unknown" if stored_crc is None else f"0x{stored_crc:02x}"
    lines = [
        "RV220W SSB SPROM evidence analysis",
        f"source format: {source_format} ({source_size} bytes)",
        f"decoded image: {len(raw)} bytes sha256={report['decoded_sha256']}",
        f"revision: {revision if revision is not None else 'unknown'}",
        f"CRC: {'PASS' if crc_valid else 'FAIL'} calculated={crc_text} stored={stored_text}",
        f"erased words: {erased_words}/{total_words}",
    ]
    if "rev8" in report:
        r = report["rev8"]
        assert isinstance(r, dict)
        lines.extend([
            f"SVID=0x{r['subsystem_vendor_id']:04x} PID=0x{r['pci_product_id']:04x} boardrev=0x{r['board_rev']:04x}",
            f"boardflags=0x{r['boardflags_hi']:04x}{r['boardflags_lo']:04x} boardflags2=0x{r['boardflags2_hi']:04x}{r['boardflags2_lo']:04x}",
            f"IL0 MAC={r['il0mac']} valid_unicast={r['il0mac_valid_unicast']}",
            f"TX/RX chain masks={r['txchain']}/{r['rxchain']} FEM2G=0x{r['fem2g']:04x}",
            "core0 power words: " + " ".join(r["core0_power_words"]),
            "core1 power words: " + " ".join(r["core1_power_words"]),
        ])
    lines.append("RF qualification: BLOCKED" if not crc_valid else "RF qualification: still requires RV220W board-specific validation")
    rendered = "\n".join(lines) + "\n"

    if args.json_path:
        args.json_path.write_text(json.dumps(report, indent=2, sort_keys=True) + "\n")
    if args.text_path:
        args.text_path.write_text(rendered)
    print(rendered, end="")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
