#!/usr/bin/env python3
"""Analyze explicit RV220W b43 receiver/firmware initialization evidence."""
from __future__ import annotations
import argparse, json, re
from pathlib import Path

MAC_RE = re.compile(r"(?:[0-9a-f]{2}:){5}[0-9a-f]{2}", re.I)


def first(text: str, key: str):
    m = re.search(rf"^{re.escape(key)}=(.*)$", text, re.M)
    return m.group(1).strip() if m else None


def last(text: str, key: str):
    matches = re.findall(rf"^{re.escape(key)}=(.*)$", text, re.M)
    return matches[-1].strip() if matches else None


def norm(s):
    return s.lower() if s else None


def parse_int(value):
    if value is None:
        return None
    try:
        return int(value, 0)
    except ValueError:
        try:
            return int(value, 10)
        except ValueError:
            return None


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument('input', type=Path)
    ap.add_argument('--json', dest='json_path', type=Path)
    ap.add_argument('--text', dest='text_path', type=Path)
    args = ap.parse_args()
    text = args.input.read_text(errors='replace')

    expected = first(text, 'stock_expected_wlan_mac')
    explicit_mac = last(text, 'macaddr')
    mtd_source = last(text, 'macaddr_mtd')
    mtd_offset_raw = last(text, 'macaddr_mtd_offset')
    mtd_increment_raw = last(text, 'macaddr_increment')
    pio_raw = last(text, 'pio')
    mtd_offset = parse_int(mtd_offset_raw)
    mtd_increment = parse_int(mtd_increment_raw)
    pio = parse_int(pio_raw)
    perm = first(text, 'permanent_mac')
    status = first(text, 'status')
    transfer = first(text, 'active_transfer')
    radio_on = first(text, 'radio_on')
    phy_type = first(text, 'phy_type')
    phy_rev = first(text, 'phy_rev')
    radio_ver = first(text, 'radio_ver')
    radio_rev = first(text, 'radio_rev')
    link_up = first(text, 'receiver_init_link_up') == '1'
    capture_complete = first(text, 'receiver_init_capture_complete') == '1'
    requested_scan = first(text, 'requested_scan')
    requested_assoc = first(text, 'requested_association')
    requested_ap = first(text, 'requested_ap')
    requested_user_tx = first(text, 'requested_user_tx')
    firmware = re.search(r'Loading (?:OpenSource )?firmware version\s+(\d+)\.(\d+)', text, re.I)
    fwver = f"{firmware.group(1)}.{firmware.group(2)}" if firmware else None
    iface_mac = None
    m = re.search(r'^\s*addr\s+((?:[0-9A-Fa-f]{2}:){5}[0-9A-Fa-f]{2})\s*$', text, re.M)
    if m:
        iface_mac = m.group(1)
    b43_error = bool(re.search(
        r'b43[^\n]*(?:error|failed|failure|firmware[^\n]*(?:not found|too old|unsupported))',
        text, re.I))
    mtd_log_matches = bool(expected and re.search(
        rf'Using MTD-derived permanent MAC address\s+{re.escape(expected)}\b',
        text, re.I))

    gates = {
        'expected_mac_valid': bool(expected and MAC_RE.fullmatch(expected)),
        'explicit_mac_empty': explicit_mac in (None, '', 'empty'),
        'mtd_source_matches': mtd_source == 'boot-chain',
        'mtd_offset_matches': mtd_offset == 0x6ff00,
        'mtd_increment_matches': mtd_increment == 4,
        'pio_matches': pio == 0,
        'mtd_first_probe_log_matches': mtd_log_matches,
        'permanent_mac_matches': bool(expected and perm and norm(expected) == norm(perm)),
        'interface_mac_matches': bool(expected and iface_mac and norm(expected) == norm(iface_mac)),
        'receiver_link_up': link_up,
        'capabilities_started': status == '2',
        'firmware_loaded': fwver is not None,
        'nphy_initialized': phy_type == '4' and phy_rev == '4' and norm(radio_ver) == '0x2056' and radio_rev == '3',
        'radio_on_during_gate': radio_on == '1',
        'capture_complete': capture_complete,
        'no_b43_error': not b43_error,
        'no_scan_requested': requested_scan == '0',
        'no_association_requested': requested_assoc == '0',
        'no_ap_requested': requested_ap == '0',
        'no_user_tx_requested': requested_user_tx == '0',
    }
    problems = [k for k, v in gates.items() if not v]
    data = {
        'schema': 'rv220w-b43-receiver-init-analysis-v2',
        'input': str(args.input),
        'gates': gates,
        'expected_mac': expected,
        'explicit_mac': explicit_mac,
        'mtd_source': mtd_source,
        'mtd_offset': mtd_offset,
        'mtd_increment': mtd_increment,
        'pio': pio,
        'permanent_mac': perm,
        'interface_mac': iface_mac,
        'status': status,
        'active_transfer': transfer,
        'radio_on': radio_on,
        'firmware_version': fwver,
        'phy_type': phy_type,
        'phy_rev': phy_rev,
        'radio_ver': radio_ver,
        'radio_rev': radio_rev,
        'problems': problems,
    }
    lines = [
        'RV220W b43 receiver/firmware initialization analysis',
        f"stock expected WLAN MAC: {expected or 'unknown'}",
        f"b43 MTD MAC source: {mtd_source or 'unknown'} offset={mtd_offset_raw or 'unknown'} increment={mtd_increment_raw or 'unknown'} pio={pio_raw or 'unknown'} "
        f"({'PASS' if all(gates[k] for k in ('mtd_source_matches','mtd_offset_matches','mtd_increment_matches','pio_matches')) else 'FAIL'})",
        f"explicit b43 MAC override empty: {'PASS' if gates['explicit_mac_empty'] else 'FAIL'}",
        f"first-probe MTD-derived MAC log: {'PASS' if gates['mtd_first_probe_log_matches'] else 'FAIL'}",
        f"b43 permanent MAC initialized: {perm or 'unknown'} ({'PASS' if gates['permanent_mac_matches'] else 'FAIL'})",
        f"temporary managed interface MAC: {iface_mac or 'unknown'} ({'PASS' if gates['interface_mac_matches'] else 'FAIL'})",
        f"b43 state: status={status or 'unknown'} ({'STARTED/PASS' if gates['capabilities_started'] else 'FAIL'}) transfer={transfer or 'unknown'} radio_on={radio_on or 'unknown'}",
        f"firmware load: {'PASS ' + fwver if fwver else 'FAIL/not observed'}",
        f"N-PHY initialized: {'PASS' if gates['nphy_initialized'] else 'FAIL'} (phy={phy_type or '?'} rev={phy_rev or '?'} radio={radio_ver or '?'} rev={radio_rev or '?'})",
        f"explicit no-operation markers: scan={requested_scan or '?'} association={requested_assoc or '?'} AP={requested_ap or '?'} user_tx={requested_user_tx or '?'}",
        f"kernel b43 error indication: {'NO' if gates['no_b43_error'] else 'YES'}",
        f"receiver-init gate: {'PASS' if not problems else 'FAIL'}",
    ]
    if problems:
        lines.append('failed gates: ' + ', '.join(problems))
    else:
        lines.append('Next action: receiver/firmware initialization is qualified; keep active scanning/association/AP blocked until a separate passive-scan gate is authorized and reviewed.')
    rendered = '\n'.join(lines) + '\n'
    if args.json_path:
        args.json_path.write_text(json.dumps(data, indent=2, sort_keys=True) + '\n')
    if args.text_path:
        args.text_path.write_text(rendered)
    print(rendered, end='')
    return 0 if not problems else 3


if __name__ == '__main__':
    raise SystemExit(main())
