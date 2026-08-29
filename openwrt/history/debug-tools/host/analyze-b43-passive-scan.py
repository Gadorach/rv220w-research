#!/usr/bin/env python3
"""Analyze RV220W b43 constrained 2.4 GHz passive-scan qualification evidence."""
from __future__ import annotations
import argparse, json, re
from pathlib import Path

MAC_RE = re.compile(r"(?:[0-9a-f]{2}:){5}[0-9a-f]{2}", re.I)
ALLOWED_FREQS = {2412,2417,2422,2427,2432,2437,2442,2447,2452,2457,2462}


def first(text: str, key: str):
    m = re.search(rf"^{re.escape(key)}=(.*)$", text, re.M)
    return m.group(1).strip() if m else None


def norm(s):
    return s.lower() if s else None


def main() -> int:
    ap=argparse.ArgumentParser()
    ap.add_argument('input', type=Path)
    ap.add_argument('--json', dest='json_path', type=Path)
    ap.add_argument('--text', dest='text_path', type=Path)
    args=ap.parse_args()
    text=args.input.read_text(errors='replace')

    expected=first(text,'stock_expected_wlan_mac')
    iface_mac=first(text,'passive_scan_interface_mac')
    perm=first(text,'permanent_mac')
    source=first(text,'b43_macaddr_mtd')
    offset=first(text,'b43_macaddr_mtd_offset')
    increment=first(text,'b43_macaddr_increment')
    pio=first(text,'b43_module_pio')
    country=first(text,'passive_scan_country')
    scan_mode=first(text,'requested_scan_mode')
    req_probe=first(text,'requested_probe_requests')
    req_ssids=first(text,'requested_ssid_count')
    req_assoc=first(text,'requested_association')
    req_ap=first(text,'requested_ap')
    req_user_tx=first(text,'requested_user_tx')
    link_not_connected=first(text,'post_scan_link_not_connected')
    station_count=first(text,'post_scan_station_count')
    cmd_rc=first(text,'passive_scan_command_rc')
    capture_complete=first(text,'passive_scan_capture_complete')
    status=first(text,'status')
    radio_on=first(text,'radio_on')
    requested_freqs=[]
    raw_freqs=first(text,'requested_frequencies') or ''
    for tok in raw_freqs.split():
        try: requested_freqs.append(int(tok))
        except ValueError: pass

    # Restrict BSS parsing to the captured scan-results section.
    scan_section=''
    m=re.search(r'^=== passive scan results ===\n(.*?)^=== post-scan link ===$', text, re.M|re.S)
    if m: scan_section=m.group(1)
    bss_count=len(re.findall(r'^BSS\s+[0-9a-f:]+', scan_section, re.M|re.I))
    bss_freqs=[int(x) for x in re.findall(r'^\s*freq:\s*(\d+)\s*$', scan_section, re.M)]
    signals=[float(x) for x in re.findall(r'^\s*signal:\s*(-?\d+(?:\.\d+)?)\s+dBm', scan_section, re.M)]
    ssids=re.findall(r'^\s*SSID:\s*(.*)$', scan_section, re.M)
    scan_aborted='scan aborted!' in scan_section.lower()
    b43_error=bool(re.search(r'b43[^\n]*(?:error|failed|failure|firmware[^\n]*(?:not found|too old|unsupported))', text, re.I))

    gates={
        'expected_mac_valid': bool(expected and MAC_RE.fullmatch(expected)),
        'mtd_source_matches': source=='boot-chain' and offset=='458496' and increment=='4' and pio=='0',
        'permanent_mac_matches': bool(expected and perm and norm(expected)==norm(perm)),
        'interface_mac_matches': bool(expected and iface_mac and norm(expected)==norm(iface_mac)),
        'country_ca': country=='CA',
        'passive_mode_requested': scan_mode=='passive',
        'no_probe_requests_requested': req_probe=='0' and req_ssids=='0',
        'exact_2ghz_frequency_scope': set(requested_freqs)==ALLOWED_FREQS and len(requested_freqs)==len(ALLOWED_FREQS),
        'scan_command_succeeded': cmd_rc=='0' and not scan_aborted,
        'received_bss': bss_count > 0,
        'results_within_scope': bool(bss_freqs) and all(f in ALLOWED_FREQS for f in bss_freqs),
        'not_associated_after_scan': link_not_connected=='1' and station_count=='0',
        'no_association_requested': req_assoc=='0',
        'no_ap_requested': req_ap=='0',
        'no_user_tx_requested': req_user_tx=='0',
        'b43_started': status=='2' and radio_on=='1',
        'capture_complete': capture_complete=='1',
        'no_b43_error': not b43_error,
    }
    problems=[k for k,v in gates.items() if not v]
    data={
        'schema':'rv220w-b43-passive-scan-analysis-v1',
        'input':str(args.input), 'gates':gates, 'problems':problems,
        'expected_mac':expected, 'interface_mac':iface_mac, 'permanent_mac':perm,
        'country':country, 'requested_frequencies':requested_freqs,
        'bss_count':bss_count, 'bss_frequencies':bss_freqs,
        'signals_dbm':signals, 'ssids':ssids,
    }
    lines=[
        'RV220W b43 constrained passive-scan analysis',
        f"stock expected WLAN MAC: {expected or 'unknown'}",
        f"b43 MTD source: {source or 'unknown'} offset={offset or '?'} increment={increment or '?'} pio={pio or '?'} ({'PASS' if gates['mtd_source_matches'] else 'FAIL'})",
        f"initialized permanent MAC: {perm or 'unknown'} ({'PASS' if gates['permanent_mac_matches'] else 'FAIL'})",
        f"scan interface MAC: {iface_mac or 'unknown'} ({'PASS' if gates['interface_mac_matches'] else 'FAIL'})",
        f"regulatory country: {country or 'unknown'} ({'PASS' if gates['country_ca'] else 'FAIL'})",
        f"scan request: mode={scan_mode or 'unknown'} SSIDs={req_ssids or '?'} probe_requests={req_probe or '?'} ({'PASS' if gates['passive_mode_requested'] and gates['no_probe_requests_requested'] else 'FAIL'})",
        f"frequency scope: {' '.join(map(str,requested_freqs)) or 'unknown'} ({'PASS' if gates['exact_2ghz_frequency_scope'] else 'FAIL'})",
        f"scan execution: rc={cmd_rc or 'unknown'} aborted={scan_aborted} ({'PASS' if gates['scan_command_succeeded'] else 'FAIL'})",
        f"received BSS entries: {bss_count} ({'PASS' if gates['received_bss'] else 'FAIL'})",
        f"received frequencies: {sorted(set(bss_freqs)) if bss_freqs else []} ({'PASS' if gates['results_within_scope'] else 'FAIL'})",
        f"post-scan unassociated: link_not_connected={link_not_connected or '?'} station_count={station_count or '?'} ({'PASS' if gates['not_associated_after_scan'] else 'FAIL'})",
        f"explicit no-operation markers: association={req_assoc or '?'} AP={req_ap or '?'} user_tx={req_user_tx or '?'}",
        f"b43 initialized: status={status or '?'} radio_on={radio_on or '?'} ({'PASS' if gates['b43_started'] else 'FAIL'})",
        f"kernel b43 error indication: {'NO' if gates['no_b43_error'] else 'YES'}",
        f"2.4 GHz passive-receive gate: {'PASS' if not problems else 'FAIL'}",
    ]
    if signals:
        lines.append(f"signal range observed: {min(signals):.1f}..{max(signals):.1f} dBm")
    if problems:
        lines.append('failed gates: '+', '.join(problems))
    else:
        lines.append('Next action: 2.4 GHz passive receive is qualified; keep 5 GHz/DFS, active scan, association and AP blocked pending separate gates.')
    rendered='\n'.join(lines)+'\n'
    if args.json_path: args.json_path.write_text(json.dumps(data,indent=2,sort_keys=True)+'\n')
    if args.text_path: args.text_path.write_text(rendered)
    print(rendered,end='')
    return 0 if not problems else 3

if __name__=='__main__':
    raise SystemExit(main())
