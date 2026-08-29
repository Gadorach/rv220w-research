#!/usr/bin/env python3
"""Analyze read-only SSB PCI SPROM/OTP evidence and safely build fallback data.

The matching kernel diagnostics expose numeric 16-bit OTP words. Passive captures
perform no controller command. Explicit BCM4322 post-INIT captures may carry
``status_fresh=1`` after the separately gated Broadcom OTP INIT opcode; INIT
refreshes controller shadow/status and is not a programming opcode. This tool
reconstructs the Broadcom hardware SROM candidate from the geometry-defined
General-Use hardware region, validates both Linux's stored CRC convention and
Broadcom's full-image CRC residue, and can serialize a CRC-valid candidate in
the byte order expected by OpenWrt's ``brcm,ssb-sprom`` firmware loader.

No target identity, MAC address, RF calibration field or device ID is injected.
An arbitrary scan hit is diagnostic only and is never eligible for automatic
fallback emission.
"""
from __future__ import annotations

import argparse
import hashlib
import json
import re
import shlex
from pathlib import Path

HEX_RE = re.compile(r"^[0-9A-Fa-f]+$")
SUPPORTED_REVISIONS = {4, 5, 8}
SROM_WORDS = 220
SROM_BYTES = SROM_WORDS * 2


def parse_info(path: Path) -> dict[str, str]:
    text = path.read_text(errors="replace").strip()
    result: dict[str, str] = {}
    for token in shlex.split(text.replace("\n", " ")):
        if "=" in token:
            key, value = token.split("=", 1)
            result[key] = value
    return result


def parse_int(info: dict[str, str], key: str) -> int | None:
    value = info.get(key)
    if value is None:
        return None
    try:
        return int(value, 0)
    except ValueError:
        return None


def parse_words(path: Path) -> list[int]:
    text = "".join(path.read_text(errors="replace").split())
    if not text or len(text) % 4 or not HEX_RE.fullmatch(text):
        raise ValueError("OTP raw input must contain four hexadecimal characters per numeric u16 word")
    return [int(text[i:i + 4], 16) for i in range(0, len(text), 4)]


def words_to_crc_bytes(words: list[int]) -> bytes:
    # Broadcom/Linux CRC walks low byte then high byte of each numeric SROM word.
    return b"".join(w.to_bytes(2, "little") for w in words)


def words_to_openwrt_blob(words: list[int]) -> bytes:
    # OpenWrt fallback-sprom.c reconstructs a numeric word as (byte0 << 8)|byte1.
    return b"".join(w.to_bytes(2, "big") for w in words)


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


def candidate_report(words: list[int], start: int) -> dict[str, object]:
    candidate = words[start:start + SROM_WORDS]
    if len(candidate) != SROM_WORDS:
        return {
            "start_word": start,
            "complete": False,
            "word_count": len(candidate),
            "valid": False,
        }
    raw = words_to_crc_bytes(candidate)
    revision = raw[-2]
    stored_crc = raw[-1]
    calculated_crc = hndcrc8(raw[:-1], 0xFF) ^ 0xFF
    residue = hndcrc8(raw, 0xFF)
    linux_crc_valid = stored_crc == calculated_crc
    broadcom_residue_valid = residue == 0x9F
    first_word_valid = candidate[0] != 0xFFFF
    revision_supported = revision in SUPPORTED_REVISIONS
    valid = first_word_valid and revision_supported and linux_crc_valid and broadcom_residue_valid
    return {
        "start_word": start,
        "complete": True,
        "word_count": len(candidate),
        "byte_count": len(raw),
        "canonical_sha256": hashlib.sha256(raw).hexdigest(),
        "openwrt_blob_sha256": hashlib.sha256(words_to_openwrt_blob(candidate)).hexdigest(),
        "first_word": f"0x{candidate[0]:04x}",
        "first_word_valid": first_word_valid,
        "revision": revision,
        "revision_supported": revision_supported,
        "stored_crc": stored_crc,
        "calculated_crc": calculated_crc,
        "linux_crc_valid": linux_crc_valid,
        "broadcom_crc_residue": residue,
        "broadcom_residue_valid": broadcom_residue_valid,
        "valid": valid,
    }


def parse_physical(path: Path | None) -> dict[str, object] | None:
    if not path:
        return None
    data = path.read_bytes()
    stripped = data.rstrip(b"\x00\r\n\t ")
    out: dict[str, object] = {"path": str(path), "source_sha256": hashlib.sha256(data).hexdigest()}
    if stripped and len(stripped) % 4 == 0 and re.fullmatch(rb"[0-9A-Fa-f]+", stripped):
        decoded = bytes.fromhex(stripped.decode("ascii"))
        out.update({"format": "linux-sysfs-ascii-hex", "decoded_size": len(decoded), "decoded_sha256": hashlib.sha256(decoded).hexdigest()})
    else:
        out.update({"format": "unknown", "source_size": len(data)})
    return out


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument("--otp-info", required=True, type=Path)
    ap.add_argument("--otp-raw", required=True, type=Path)
    ap.add_argument("--physical-sprom", type=Path)
    ap.add_argument("--json", dest="json_path", type=Path)
    ap.add_argument("--text", dest="text_path", type=Path)
    ap.add_argument("--candidate-bin", type=Path, help="write geometry-defined candidate in canonical low-byte/high-byte CRC order")
    ap.add_argument("--emit-openwrt-fallback", type=Path, help="write only when the geometry-defined candidate is CRC-valid")
    args = ap.parse_args()

    try:
        info = parse_info(args.otp_info)
        words = parse_words(args.otp_raw)
    except ValueError as exc:
        ap.error(str(exc))

    declared_words = parse_int(info, "otp_words")
    hwbase = parse_int(info, "hwbase")
    hwlim = parse_int(info, "hwlim")
    status_fresh = parse_int(info, "status_fresh")
    hw_programmed = parse_int(info, "hw_programmed")
    chipstatus = parse_int(info, "chipstatus")
    otpcontrol = parse_int(info, "otpcontrol")
    otpprog = parse_int(info, "otpprog")
    selector = parse_int(info, "bcm4322_sprom_otp_sel")
    stock_source = info.get("bcm4322_stock_source")

    if hwbase is None:
        ap.error("OTP metadata does not provide hwbase")
    if hwbase < 0 or hwbase >= len(words):
        ap.error(f"geometry-defined hwbase {hwbase} lies outside {len(words)} captured words")

    primary = candidate_report(words, hwbase)
    candidate_words = words[hwbase:hwbase + SROM_WORDS]

    scan_hits: list[dict[str, object]] = []
    if len(words) >= SROM_WORDS:
        for start in range(0, len(words) - SROM_WORDS + 1):
            if start == hwbase:
                continue
            candidate = candidate_report(words, start)
            if candidate.get("valid"):
                scan_hits.append(candidate)

    primary_valid = bool(primary.get("valid"))
    if args.candidate_bin and len(candidate_words) == SROM_WORDS:
        args.candidate_bin.write_bytes(words_to_crc_bytes(candidate_words))

    emission_requested = args.emit_openwrt_fallback is not None
    emitted = False
    if emission_requested and primary_valid:
        assert args.emit_openwrt_fallback is not None
        args.emit_openwrt_fallback.write_bytes(words_to_openwrt_blob(candidate_words))
        emitted = True
    elif emission_requested and args.emit_openwrt_fallback:
        args.emit_openwrt_fallback.unlink(missing_ok=True)

    chip_id = parse_int(info, "chip")
    init_eligible = (chip_id == 0x4322 and selector == 2 and stock_source == "otp" and not bool(status_fresh))
    if chip_id == 0x4322 and stock_source == "sprom":
        next_action = "stock BCM4322 selector chooses external SPROM; do not issue OTP INIT"
    elif init_eligible:
        next_action = "stock BCM4322 selector chooses OTP; explicit init-shadow before/after capture is eligible"
    elif chip_id == 0x4322 and stock_source == "otp" and bool(status_fresh):
        next_action = "OTP status/shadow was explicitly initialized; review the post-INIT geometry candidate"
    elif chip_id == 0x4322 and stock_source in {"none", "reserved"}:
        next_action = "BCM4322 source selector is not a valid OTP configuration; do not issue OTP INIT"
    else:
        next_action = "review passive NVM evidence; no BCM4322 OTP INIT eligibility established"

    report: dict[str, object] = {
        "schema": "ssb-pci-nvmem-analysis-v2",
        "otp_info": str(args.otp_info),
        "otp_raw": str(args.otp_raw),
        "metadata": info,
        "capture": {
            "word_count": len(words),
            "declared_word_count": declared_words,
            "declared_word_count_matches": declared_words == len(words) if declared_words is not None else None,
            "raw_numeric_words_sha256": hashlib.sha256(b"".join(w.to_bytes(2, "big") for w in words)).hexdigest(),
            "status_fresh": bool(status_fresh) if status_fresh is not None else None,
            "hw_programmed": bool(hw_programmed) if hw_programmed is not None else None,
            "chipstatus": chipstatus,
            "otpcontrol": otpcontrol,
            "otpprog": otpprog,
            "bcm4322_sprom_otp_sel": selector,
            "bcm4322_stock_source": stock_source,
            "explicit_init_shadow_eligible": init_eligible,
            "hwbase": hwbase,
            "hwlim": hwlim,
        },
        "geometry_candidate": primary,
        "diagnostic_scan_valid_hits": scan_hits,
        "physical_sprom": parse_physical(args.physical_sprom),
        "openwrt_fallback": {
            "eligible": primary_valid,
            "emitted": emitted,
            "path": str(args.emit_openwrt_fallback) if emitted else None,
            "serialization": "numeric u16 big-endian per word for OpenWrt brcm,ssb-sprom firmware loader",
        },
        "policy": {
            "automatic_mac_injection": False,
            "arbitrary_scan_hit_eligible_for_emission": False,
            "analyzer_hardware_writes": False,
            "capture_may_follow_explicit_init_only": bool(status_fresh),
            "rf_qualified": False,
            "interpretation": "CRC-valid OTP proves candidate integrity, not board/regulatory RF qualification",
            "next_action": next_action,
        },
    }

    lines = [
        "SSB PCI NVM read-only analysis",
        f"chip={info.get('chip', 'unknown')} ccrev={info.get('ccrev', 'unknown')} BDF={info.get('bdf', 'unspecified')}",
        f"OTP capture: {len(words)} words; declared={declared_words if declared_words is not None else 'unknown'} status_fresh={status_fresh if status_fresh is not None else 'unknown'}",
        f"source selector: chipstatus={info.get('chipstatus', 'unknown')} bcm4322_sel={selector if selector is not None else 'unknown'} stock_source={stock_source or 'unknown'} init_eligible={'yes' if init_eligible else 'no'}",
        f"OTP registers: control={info.get('otpcontrol', 'unknown')} program={info.get('otpprog', 'unknown')}",
        f"geometry: GU={info.get('otpgu_base', 'unknown')} hwbase={hwbase} hwlim={hwlim if hwlim is not None else 'unknown'} hw_programmed={hw_programmed if hw_programmed is not None else 'unknown'}",
        f"candidate: start={hwbase} words={primary.get('word_count')} rev={primary.get('revision', 'unknown')}",
    ]
    if primary.get("complete"):
        lines.extend([
            f"Linux stored CRC: {'PASS' if primary.get('linux_crc_valid') else 'FAIL'} calculated=0x{int(primary['calculated_crc']):02x} stored=0x{int(primary['stored_crc']):02x}",
            f"Broadcom full-image residue: {'PASS' if primary.get('broadcom_residue_valid') else 'FAIL'} residue=0x{int(primary['broadcom_crc_residue']):02x} expected=0x9f",
            f"candidate integrity: {'PASS' if primary_valid else 'FAIL'} sha256={primary.get('canonical_sha256')}",
        ])
    else:
        lines.append("candidate integrity: FAIL (incomplete geometry-defined 220-word SROM image)")
    lines.append(f"other CRC-valid 220-word diagnostic windows: {len(scan_hits)} (never auto-emitted)")
    lines.append(f"OpenWrt fallback emission: {'ELIGIBLE' if primary_valid else 'BLOCKED'}")
    lines.append("MAC injection: none")
    lines.append("RF qualification: BLOCKED pending board-specific calibration/regulatory validation")
    lines.append(f"Next action: {next_action}")
    rendered = "\n".join(lines) + "\n"

    if args.json_path:
        args.json_path.write_text(json.dumps(report, indent=2, sort_keys=True) + "\n")
    if args.text_path:
        args.text_path.write_text(rendered)
    print(rendered, end="")
    return 0 if (not emission_requested or emitted) else 3


if __name__ == "__main__":
    raise SystemExit(main())
