#!/usr/bin/env python3
import argparse, json, re, sys
from pathlib import Path

CA_FREQS={2412,2417,2422,2427,2432,2437,2442,2447,2452,2457,2462}

def kv(text,key):
    m=re.search(rf'(?m)^{re.escape(key)}=(.*)$',text)
    return m.group(1).strip() if m else None

def iv(text,key,default=None):
    v=kv(text,key)
    try: return int(v) if v is not None else default
    except ValueError: return default

def freq_iv(text,key,default=None):
    v=kv(text,key)
    if v is None:
        return default
    try:
        f=float(v)
    except ValueError:
        return default
    i=int(round(f))
    return i if abs(f-i) < 1e-6 else default

def main():
    ap=argparse.ArgumentParser()
    ap.add_argument('input')
    ap.add_argument('--json',dest='json_out')
    ap.add_argument('--text',dest='text_out')
    a=ap.parse_args()
    p=Path(a.input); text=p.read_text(errors='replace')

    req_ssid=kv(text,'managed_assoc_requested_ssid')
    link_ssid=kv(text,'managed_assoc_link_ssid')
    bssid=kv(text,'managed_assoc_link_bssid')
    freq=freq_iv(text,'managed_assoc_link_frequency')
    tx_before=iv(text,'managed_assoc_txstatus_before',0)
    tx_after=iv(text,'managed_assoc_txstatus_after',0)
    irq_before=iv(text,'managed_assoc_host_irq_count_before',0)
    irq_after=iv(text,'managed_assoc_host_irq_count_after',0)
    station_count=iv(text,'managed_assoc_station_count',0)
    transfer=kv(text,'managed_assoc_b43_transfer')
    module_pio=kv(text,'b43_module_pio')
    host_rc=iv(text,'managed_assoc_transport_rc')
    wpastart=iv(text,'managed_assoc_wpa_supplicant_start_rc')
    wpa_alive=iv(text,'managed_assoc_wpa_supplicant_alive_after_start')
    supplicant_usage=bool(re.search(r'(?m)^usage:$',text) and re.search(r'(?m)^\s*wpa_supplicant \[',text))
    connected=iv(text,'managed_assoc_connected',0)
    stable=iv(text,'managed_assoc_stable_after_5s',0)
    capture=iv(text,'managed_assoc_capture_complete',0)
    revision=kv(text,'managed_assoc_probe_revision')
    existing_iface_count=iv(text,'managed_assoc_existing_wireless_interface_count')
    global_daemon_only=iv(text,'managed_assoc_global_daemon_only_preflight')
    old_daemon_block=bool(re.search(r'(?m)^managed-assoc blocked: a wireless userspace daemon is already running\.$',text))
    new_iface_block=bool(re.search(r'(?m)^managed-assoc blocked: a wireless interface is already active after wifi down\.$',text))
    no_kernel_error = not re.search(r'(?im)(^|\b)(BUG:|Oops:|Kernel panic|b43-phy\d+.*(?:ERROR|fatal)|DMA.*(?:error|failed))',text)

    gates={
      'probe_supported': revision in ('v1.14.82','v1.14.83','v1.14.84','v1.14.85'),
      'daemon_preflight': (global_daemon_only==1 and existing_iface_count==0) if revision in ('v1.14.83','v1.14.84','v1.14.85') else not old_daemon_block,
      'country_ca': kv(text,'managed_assoc_country')=='CA',
      'credentials_stdin': kv(text,'managed_assoc_credentials_source')=='stdin',
      'credentials_nonpersistent': kv(text,'managed_assoc_credentials_persistent')=='0',
      'normal_path_no_interposed_gates': all(kv(text,k)=='1' for k in ('managed_assoc_no_debugfs_calibration','managed_assoc_no_monitor_handoff','managed_assoc_no_channel_gate')),
      'native_dma_requested': module_pio=='0',
      'active_dma': transfer=='dma',
      'identity': kv(text,'managed_assoc_interface_mac')==kv(text,'stock_expected_wlan_mac') and kv(text,'managed_assoc_interface_mac') not in (None,'missing'),
      'interface_started': iv(text,'managed_assoc_interface_add_rc')==0 and iv(text,'managed_assoc_interface_up_rc')==0 and kv(text,'managed_assoc_b43_operating')=='1' and kv(text,'managed_assoc_b43_status')=='2',
      'supplicant_started': wpastart==0 and (wpa_alive==1 if revision in ('v1.14.84','v1.14.85') else True),
      'connected': connected==1,
      'stable_5s': stable==1,
      'ssid_match': req_ssid is not None and link_ssid==req_ssid,
      'bssid_present': bool(bssid and re.fullmatch(r'[0-9a-f]{2}(?::[0-9a-f]{2}){5}',bssid)),
      'frequency_ca_2g': freq in CA_FREQS,
      'station_present': station_count is not None and station_count>=1,
      'tx_status_advanced': tx_after is not None and tx_before is not None and tx_after>tx_before,
      'pci_irq_active': irq_after is not None and irq_before is not None and irq_after>irq_before and iv(text,'managed_assoc_host_irq')==109,
      'no_dhcp_ap_injection_persistence': kv(text,'requested_dhcp')=='0' and kv(text,'requested_ap')=='0' and kv(text,'requested_frame_injection')=='0' and kv(text,'requested_persistent_network_config')=='0' and kv(text,'requested_nvm_write')=='0' and kv(text,'requested_nor_write')=='0',
      'private_config_removed': iv(text,'managed_assoc_private_config_removed')==1,
      'interface_removed': iv(text,'managed_assoc_interface_removed')==1,
      'supplicant_stopped': iv(text,'managed_assoc_supplicant_stopped')==1,
      'capture_complete': capture==1,
      'transport_succeeded': host_rc==0,
      'no_kernel_error': no_kernel_error,
    }
    problems=[k for k,v in gates.items() if not v]
    passed=not problems
    if passed:
        finding='b43-normal-managed-dma-wpa-psk-association-qualified'
    elif old_daemon_block:
        finding='managed-assoc-global-daemon-preflight-false-positive'
    elif new_iface_block or (revision in ('v1.14.83','v1.14.84','v1.14.85') and existing_iface_count not in (None,0)):
        finding='managed-assoc-preexisting-wireless-interface'
    elif not gates['active_dma']:
        finding='managed-assoc-native-dma-not-active'
    elif supplicant_usage:
        finding='managed-assoc-supplicant-launch-cli-unsupported'
    elif not gates['supplicant_started']:
        finding='managed-assoc-supplicant-start-failed'
    elif not gates['connected']:
        finding='managed-assoc-authentication-or-association-failed'
    elif not gates['stable_5s']:
        finding='managed-assoc-link-not-stable'
    elif not gates['tx_status_advanced']:
        finding='managed-assoc-no-b43-txstatus'
    elif not gates['pci_irq_active']:
        finding='managed-assoc-no-host-irq-progress'
    else:
        finding='managed-assoc-qualification-failed'

    result={
      'schema':'rv220w-b43-managed-assoc-analysis-v4',
      'input':str(p), 'passed':passed, 'finding':finding, 'problems':problems, 'gates':gates,
      'network':{'requested_ssid':req_ssid,'linked_ssid':link_ssid,'bssid':bssid,'frequency':freq,'station_count':station_count},
      'transport':{'module_pio':module_pio,'active':transfer,'host_rc':host_rc},
      'tx':{'before':tx_before,'after':tx_after,'delta':(tx_after-tx_before) if tx_after is not None and tx_before is not None else None},
      'irq':{'irq':iv(text,'managed_assoc_host_irq'),'before':irq_before,'after':irq_after,'delta':(irq_after-irq_before) if irq_after is not None and irq_before is not None else None},
      'supplicant':{'start_rc':wpastart,'alive_after_start':wpa_alive,'usage_output':supplicant_usage,'connected':bool(connected),'stable_5s':bool(stable)},
      'preflight':{'revision':revision,'existing_wireless_interface_count':existing_iface_count,'global_daemon_only':global_daemon_only,'old_daemon_block':old_daemon_block},
    }
    lines=[
      'RV220W BCM4322/b43 native-DMA WPA-PSK managed association qualification',
      f"transport: host_rc={host_rc} module_pio={module_pio} active={transfer} ({'PASS' if gates['native_dma_requested'] and gates['active_dma'] and gates['transport_succeeded'] else 'FAIL'})",
      f"preflight: revision={revision} wireless_ifaces={existing_iface_count} global_daemon_only={global_daemon_only} ({'PASS' if gates['daemon_preflight'] else 'FAIL'})",
      f"managed interface/supplicant: start={wpastart} alive={wpa_alive} connected={connected} stable5s={stable} stations={station_count} ({'PASS' if gates['interface_started'] and gates['supplicant_started'] and gates['connected'] and gates['stable_5s'] and gates['station_present'] else 'FAIL'})",
      f"network: requested={req_ssid!r} linked={link_ssid!r} bssid={bssid} freq={freq} ({'PASS' if gates['ssid_match'] and gates['bssid_present'] and gates['frequency_ca_2g'] else 'FAIL'})",
      f"b43 TX status: {tx_before}->{tx_after} delta={(tx_after-tx_before) if tx_after is not None and tx_before is not None else 'missing'} ({'PASS' if gates['tx_status_advanced'] else 'FAIL'})",
      f"PCI/host IRQ: irq={iv(text,'managed_assoc_host_irq')} count={irq_before}->{irq_after} delta={(irq_after-irq_before) if irq_after is not None and irq_before is not None else 'missing'} ({'PASS' if gates['pci_irq_active'] else 'FAIL'})",
      f"teardown: config_removed={iv(text,'managed_assoc_private_config_removed')} iface_removed={iv(text,'managed_assoc_interface_removed')} supplicant_stopped={iv(text,'managed_assoc_supplicant_stopped')} ({'PASS' if gates['private_config_removed'] and gates['interface_removed'] and gates['supplicant_stopped'] else 'FAIL'})",
      f'finding: {finding}', f"overall: {'PASS' if passed else 'FAIL'}"
    ]
    if problems: lines.append('failed gates: '+','.join(problems))
    out='\n'.join(lines)+'\n'
    if a.json_out: Path(a.json_out).write_text(json.dumps(result,indent=2,sort_keys=True)+'\n')
    if a.text_out: Path(a.text_out).write_text(out)
    print(out,end='')
    return 0 if passed else 1

if __name__=='__main__': sys.exit(main())
