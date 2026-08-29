#!/usr/bin/env python3
"""Analyze RV220W b43 fixed-channel receive-only monitor evidence."""
from __future__ import annotations
import argparse, json, re
from pathlib import Path

ALLOWED = {
    '2g': {2412,2417,2422,2427,2432,2437,2442,2447,2452,2457,2462},
    '5g': {5180,5200,5220,5240},
}

def first(text: str, key: str):
    m=re.search(rf'^{re.escape(key)}=(.*)$', text, re.M)
    return m.group(1).strip() if m else None

def ints(text: str, key: str):
    v=first(text,key) or ''
    out=[]
    for tok in v.split():
        try: out.append(int(tok))
        except ValueError: pass
    return out

def main() -> int:
    ap=argparse.ArgumentParser()
    ap.add_argument('input', type=Path)
    ap.add_argument('--json', dest='json_path', type=Path)
    ap.add_argument('--text', dest='text_path', type=Path)
    args=ap.parse_args()
    text=args.input.read_text(errors='replace')

    band=first(text,'monitor_rx_band')
    country=first(text,'monitor_rx_country')
    expected=first(text,'stock_expected_wlan_mac')
    source=first(text,'b43_macaddr_mtd')
    offset=first(text,'b43_macaddr_mtd_offset')
    increment=first(text,'b43_macaddr_increment')
    pio=first(text,'b43_module_pio')
    req_freqs=ints(text,'requested_frequencies')
    total_delta=first(text,'monitor_total_rx_packets_delta')
    total_lines=first(text,'monitor_total_tcpdump_summary_lines')
    capture=first(text,'monitor_rx_capture_complete')
    status=first(text,'status')
    radio_on=first(text,'radio_on')
    try: total_delta_i=int(total_delta or '0')
    except ValueError: total_delta_i=0
    try: total_lines_i=int(total_lines or '0')
    except ValueError: total_lines_i=0

    blocks=[]
    for m in re.finditer(r'^=== monitor frequency (\d+) ===\n(.*?)(?=^=== monitor frequency |^monitor_total_rx_packets_delta=|\Z)', text, re.M|re.S):
        freq=int(m.group(1)); body=m.group(2)
        def bfirst(k):
            mm=re.search(rf'^{re.escape(k)}=(.*)$',body,re.M)
            return mm.group(1).strip() if mm else None
        try: delta=int(bfirst('monitor_rx_packets_delta') or '0')
        except ValueError: delta=0
        try: lines=int(bfirst('monitor_tcpdump_summary_lines') or '0')
        except ValueError: lines=0
        try: setrc=int(bfirst('monitor_setfreq_rc') or '999')
        except ValueError: setrc=999
        try: reported=int(bfirst('monitor_reported_freq') or '0')
        except ValueError: reported=0
        blocks.append({'frequency':freq,'setfreq_rc':setrc,'reported_frequency':reported,'rx_packets_delta':delta,'tcpdump_summary_lines':lines})

    allowed=ALLOWED.get(band,set())
    all_set_ok=bool(blocks) and all(b['setfreq_rc']==0 for b in blocks)
    all_reported_ok=bool(blocks) and all(b['reported_frequency']==b['frequency'] for b in blocks)
    any_rx=total_delta_i>0 or any(b['rx_packets_delta']>0 for b in blocks)
    any_summary=total_lines_i>0 or any(b['tcpdump_summary_lines']>0 for b in blocks)
    b43_error=bool(re.search(r'b43[^\n]*(?:ERROR:|error:|failed to|failure|DMA error|RX error|firmware error)',text,re.I))
    gates={
        'band_supported': band in ALLOWED,
        'country_ca': country=='CA',
        'mtd_identity_source': source=='boot-chain' and offset=='458496' and increment=='4' and pio=='1',
        'expected_mac_present': bool(expected),
        'exact_frequency_scope': bool(allowed) and set(req_freqs)==allowed and len(req_freqs)==len(allowed),
        'all_channel_switches_succeeded': all_set_ok,
        'all_reported_frequencies_match': all_reported_ok,
        'receive_activity_observed': any_rx,
        'no_probe_requests': first(text,'requested_probe_requests')=='0',
        'no_ssid_requests': first(text,'requested_ssid_count')=='0',
        'no_association_requested': first(text,'requested_association')=='0',
        'no_ap_requested': first(text,'requested_ap')=='0',
        'no_user_tx_requested': first(text,'requested_user_tx')=='0',
        'no_frame_injection_requested': first(text,'requested_frame_injection')=='0',
        'b43_started': status=='2' and radio_on=='1',
        'capture_complete': capture=='1',
        'no_b43_error': not b43_error,
    }
    problems=[k for k,v in gates.items() if not v]
    data={
        'schema':'rv220w-b43-monitor-rx-analysis-v2',
        'input':str(args.input),
        'band':band,
        'country':country,
        'expected_mac':expected,
        'requested_frequencies':req_freqs,
        'total_rx_packets_delta':total_delta_i,
        'total_tcpdump_summary_lines':total_lines_i,
        'channels':blocks,
        'gates':gates,
        'problems':problems,
    }
    lines=[
        'RV220W b43 fixed-channel monitor receive analysis',
        f"band: {band or 'unknown'} ({'PASS' if gates['band_supported'] else 'FAIL'})",
        f"country: {country or 'unknown'} ({'PASS' if gates['country_ca'] else 'FAIL'})",
        f"MTD identity source: {source or '?'} offset={offset or '?'} increment={increment or '?'} pio={pio or '?'} ({'PASS' if gates['mtd_identity_source'] else 'FAIL'})",
        f"frequency scope: {' '.join(map(str,req_freqs)) or 'unknown'} ({'PASS' if gates['exact_frequency_scope'] else 'FAIL'})",
        f"channel changes: {'PASS' if gates['all_channel_switches_succeeded'] else 'FAIL'}; reported frequencies: {'PASS' if gates['all_reported_frequencies_match'] else 'FAIL'}",
        f"RX packet delta total: {total_delta_i} ({'PASS' if gates['receive_activity_observed'] else 'FAIL'})",
        f"tcpdump nonempty received-frame summaries: {total_lines_i} ({'observed' if any_summary else 'none'})",
        f"b43 initialized: status={status or '?'} radio_on={radio_on or '?'} ({'PASS' if gates['b43_started'] else 'FAIL'})",
        'explicit no-TX markers: probe=%s SSIDs=%s association=%s AP=%s user_tx=%s injection=%s' % (
            first(text,'requested_probe_requests') or '?', first(text,'requested_ssid_count') or '?',
            first(text,'requested_association') or '?', first(text,'requested_ap') or '?',
            first(text,'requested_user_tx') or '?', first(text,'requested_frame_injection') or '?'),
        f"kernel b43 error indication: {'NO' if gates['no_b43_error'] else 'YES'}",
        f"{band or '?'} monitor-RX gate: {'PASS' if not problems else 'FAIL'}",
    ]
    for b in blocks:
        lines.append(f"  {b['frequency']} MHz: set_rc={b['setfreq_rc']} reported={b['reported_frequency']} rx_delta={b['rx_packets_delta']} tcpdump_lines={b['tcpdump_summary_lines']}")
    if problems:
        lines.append('failed gates: '+', '.join(problems))
        if not gates['receive_activity_observed']:
            lines.append('Interpretation: forced-PIO monitor RX observed no frames. Because v1.14.21 DMA monitor RX also observed zero frames with a strong nearby 2.4 GHz AP and antennas attached on the repeat run, a second zero here points below the host transfer engine toward N-PHY/radio/FEM/channel initialization.')
    else:
        lines.append('Interpretation: forced-PIO receive works. Since v1.14.21 DMA receive was zero under a strong nearby beacon, investigate the Octeon/b43 DMA mapping/descriptor path before changing N-PHY or RF calibration.')
    rendered='\n'.join(lines)+'\n'
    if args.json_path: args.json_path.write_text(json.dumps(data,indent=2,sort_keys=True)+'\n')
    if args.text_path: args.text_path.write_text(rendered)
    print(rendered,end='')
    return 0 if not problems else 3

if __name__=='__main__':
    raise SystemExit(main())
