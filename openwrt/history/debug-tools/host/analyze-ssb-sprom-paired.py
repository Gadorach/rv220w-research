#!/usr/bin/env python3
"""Analyze paired read-only 16-bit SSB SPROM captures.

The matching kernel diagnostic performs two consecutive ioread16() transactions
at every SPROM word address and preserves both complete 220-word streams.  This
mirrors the stock Broadcom wl helper's bus-access sequence while retaining the
first value for comparison instead of overwriting it.

No heuristic interleaving, lane repair, MAC injection, or calibration synthesis
is performed.  Only the directly captured *second* stream (the value stock wl
retains) is eligible for optional OpenWrt fallback serialization, and only when
its revision and both Linux/Broadcom CRC checks pass.
"""
from __future__ import annotations

import argparse
import hashlib
import json
import re
from pathlib import Path

HEX_RE = re.compile(r"^[0-9A-Fa-f]+$")
SUPPORTED_REVISIONS = {4, 5, 8}
SROM_WORDS = 220
SROM_BYTES = SROM_WORDS * 2


def crc8_byte(crc: int, data: int) -> int:
    crc ^= data
    for _ in range(8):
        crc = ((crc >> 1) ^ 0xAB) if (crc & 1) else (crc >> 1)
    return crc & 0xFF


def hndcrc8(data: bytes, initial: int = 0xFF) -> int:
    crc = initial
    for byte in data:
        crc = crc8_byte(crc, byte)
    return crc


def words_to_crc_bytes(words: list[int]) -> bytes:
    return b"".join(w.to_bytes(2, "little") for w in words)


def words_to_openwrt_blob(words: list[int]) -> bytes:
    return b"".join(w.to_bytes(2, "big") for w in words)


def report_stream(words: list[int]) -> dict[str, object]:
    if len(words) != SROM_WORDS:
        return {"word_count": len(words), "valid": False, "complete": False}
    raw = words_to_crc_bytes(words)
    revision = raw[-2]
    stored_crc = raw[-1]
    calculated_crc = hndcrc8(raw[:-1], 0xFF) ^ 0xFF
    residue = hndcrc8(raw, 0xFF)
    linux_crc_valid = stored_crc == calculated_crc
    broadcom_residue_valid = residue == 0x9F
    revision_supported = revision in SUPPORTED_REVISIONS
    first_word_valid = words[0] != 0xFFFF
    valid = first_word_valid and revision_supported and linux_crc_valid and broadcom_residue_valid
    non_erased = [i for i, w in enumerate(words) if w not in (0xFFFF, 0x0000)]
    return {
        "word_count": len(words),
        "complete": True,
        "canonical_sha256": hashlib.sha256(raw).hexdigest(),
        "openwrt_blob_sha256": hashlib.sha256(words_to_openwrt_blob(words)).hexdigest(),
        "first_word": f"0x{words[0]:04x}",
        "first_word_valid": first_word_valid,
        "revision": revision,
        "revision_supported": revision_supported,
        "stored_crc": stored_crc,
        "calculated_crc": calculated_crc,
        "linux_crc_valid": linux_crc_valid,
        "broadcom_crc_residue": residue,
        "broadcom_residue_valid": broadcom_residue_valid,
        "nontrivial_word_count": len(non_erased),
        "nontrivial_even_indices": sum(1 for i in non_erased if i % 2 == 0),
        "nontrivial_odd_indices": sum(1 for i in non_erased if i % 2 == 1),
        "valid": valid,
    }


def parse_paired(path: Path) -> tuple[dict[str, str], list[int], list[int]]:
    meta: dict[str, str] = {}
    first_hex = second_hex = None
    for line in path.read_text(errors="replace").splitlines():
        line = line.strip()
        if not line:
            continue
        if line.startswith("first="):
            first_hex = line[6:].strip()
            continue
        if line.startswith("second="):
            second_hex = line[7:].strip()
            continue
        for token in line.split():
            if "=" in token:
                k, v = token.split("=", 1)
                meta[k] = v
    if first_hex is None or second_hex is None:
        raise ValueError("paired SPROM capture must contain first= and second= streams")
    for name, text in (("first", first_hex), ("second", second_hex)):
        if len(text) != SROM_WORDS * 4 or not HEX_RE.fullmatch(text):
            raise ValueError(f"{name} stream must contain exactly {SROM_WORDS} numeric u16 hex words")
    first = [int(first_hex[i:i+4], 16) for i in range(0, len(first_hex), 4)]
    second = [int(second_hex[i:i+4], 16) for i in range(0, len(second_hex), 4)]
    return meta, first, second


def parse_physical_words(path: Path | None) -> list[int] | None:
    if not path:
        return None
    stripped = path.read_bytes().rstrip(b"\x00\r\n\t ")
    if len(stripped) != SROM_WORDS * 4 or not re.fullmatch(rb"[0-9A-Fa-f]+", stripped):
        return None
    # Linux ssb_attr_sprom_show prints swab16(numeric_word) as four hex chars.
    groups = [int(stripped[i:i+4], 16) for i in range(0, len(stripped), 4)]
    return [((w & 0xFF) << 8) | (w >> 8) for w in groups]


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument("paired", type=Path)
    ap.add_argument("--physical-sprom", type=Path)
    ap.add_argument("--json", dest="json_path", type=Path)
    ap.add_argument("--text", dest="text_path", type=Path)
    ap.add_argument("--second-bin", type=Path, help="write the directly captured second stream in CRC byte order")
    ap.add_argument("--emit-openwrt-fallback", type=Path, help="emit only if the directly captured second stream is CRC-valid")
    args = ap.parse_args()

    try:
        meta, first, second = parse_paired(args.paired)
    except ValueError as exc:
        ap.error(str(exc))

    first_report = report_stream(first)
    second_report = report_stream(second)
    mismatches = [i for i, (a, b) in enumerate(zip(first, second)) if a != b]
    declared_mismatches = None
    try:
        declared_mismatches = int(meta.get("mismatch_words", ""), 0)
    except ValueError:
        pass

    physical = parse_physical_words(args.physical_sprom)
    physical_comparison: dict[str, object] | None = None
    if physical is not None:
        physical_comparison = {
            "word_count": len(physical),
            "matches_first": physical == first,
            "matches_second": physical == second,
            "mismatch_vs_first": sum(a != b for a, b in zip(physical, first)),
            "mismatch_vs_second": sum(a != b for a, b in zip(physical, second)),
        }

    second_valid = bool(second_report.get("valid"))
    if args.second_bin:
        args.second_bin.write_bytes(words_to_crc_bytes(second))
    emitted = False
    if args.emit_openwrt_fallback:
        if second_valid:
            args.emit_openwrt_fallback.write_bytes(words_to_openwrt_blob(second))
            emitted = True
        else:
            args.emit_openwrt_fallback.unlink(missing_ok=True)

    report = {
        "schema": "ssb-sprom-paired16-analysis-v1",
        "source": str(args.paired),
        "metadata": meta,
        "capture": {
            "word_count": len(first),
            "mismatch_words": len(mismatches),
            "declared_mismatch_words": declared_mismatches,
            "declared_mismatch_matches": declared_mismatches == len(mismatches) if declared_mismatches is not None else None,
            "mismatch_even_indices": sum(1 for i in mismatches if i % 2 == 0),
            "mismatch_odd_indices": sum(1 for i in mismatches if i % 2 == 1),
            "first_second_identical": not mismatches,
        },
        "first": first_report,
        "second_stock_retained": second_report,
        "physical_single_read_comparison": physical_comparison,
        "openwrt_fallback": {
            "eligible": second_valid,
            "emitted": emitted,
            "path": str(args.emit_openwrt_fallback) if emitted else None,
            "source_policy": "direct second read only; no first/second interleaving or repair",
        },
        "policy": {
            "hardware_writes": False,
            "sprom_read_width_bits": 16,
            "heuristic_interleaving": False,
            "automatic_mac_injection": False,
            "rf_qualified": False,
        },
    }

    def fmt_stream(name: str, r: dict[str, object]) -> list[str]:
        return [
            f"{name}: rev={r.get('revision', 'unknown')} first={r.get('first_word', 'unknown')} nontrivial={r.get('nontrivial_word_count', 'unknown')} even/odd={r.get('nontrivial_even_indices', 'unknown')}/{r.get('nontrivial_odd_indices', 'unknown')}",
            f"{name} Linux CRC: {'PASS' if r.get('linux_crc_valid') else 'FAIL'} calculated=0x{int(r.get('calculated_crc', 0)):02x} stored=0x{int(r.get('stored_crc', 0)):02x}",
            f"{name} Broadcom residue: {'PASS' if r.get('broadcom_residue_valid') else 'FAIL'} residue=0x{int(r.get('broadcom_crc_residue', 0)):02x}",
            f"{name} integrity: {'PASS' if r.get('valid') else 'FAIL'} sha256={r.get('canonical_sha256', 'unknown')}",
        ]

    lines = [
        "SSB SPROM paired 16-bit read analysis",
        f"offset={meta.get('offset', 'unknown')} words={len(first)} mismatch_words={len(mismatches)} declared={declared_mismatches if declared_mismatches is not None else 'unknown'}",
    ]
    lines += fmt_stream("first", first_report)
    lines += fmt_stream("second(stock-retained)", second_report)
    if physical_comparison:
        lines.append(
            "physical single-read comparison: "
            f"matches_first={physical_comparison['matches_first']} "
            f"matches_second={physical_comparison['matches_second']} "
            f"mismatch_first={physical_comparison['mismatch_vs_first']} "
            f"mismatch_second={physical_comparison['mismatch_vs_second']}"
        )
    lines.append(f"OpenWrt fallback from direct second stream: {'ELIGIBLE' if second_valid else 'BLOCKED'}")
    lines.append("heuristic first/second interleaving: FORBIDDEN")
    lines.append("RF qualification: BLOCKED pending board-specific calibration/regulatory validation")
    rendered = "\n".join(lines) + "\n"

    if args.json_path:
        args.json_path.write_text(json.dumps(report, indent=2, sort_keys=True) + "\n")
    if args.text_path:
        args.text_path.write_text(rendered)
    print(rendered, end="")
    return 0 if (args.emit_openwrt_fallback is None or emitted) else 3


if __name__ == "__main__":
    raise SystemExit(main())
