#!/usr/bin/env python3
import argparse, ipaddress, json, re, sys
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
    if v is None: return default
    try: f=float(v)
    except ValueError: return default
    i=int(round(f))
    return i if abs(f-i) < 1e-6 else default

def ipv4(v):
    if not v or v=='missing': return False
    try: return isinstance(ipaddress.ip_address(v), ipaddress.IPv4Address)
    except ValueError: return False

def main():
    ap=argparse.ArgumentParser()
    ap.add_argument('input')
    ap.add_argument('--json',dest='json_out')
    ap.add_argument('--text',dest='text_out')
    a=ap.parse_args()
    p=Path(a.input); text=p.read_text(errors='replace')

    req_ssid=kv(text,'managed_l3_requested_ssid')
    link_ssid=kv(text,'managed_l3_link_ssid')
    bssid=kv(text,'managed_l3_link_bssid')
    freq=freq_iv(text,'managed_l3_link_frequency')
    transfer=kv(text,'managed_l3_b43_transfer')
    module_pio=kv(text,'b43_module_pio')
    host_rc=iv(text,'managed_l3_transport_rc')
    connected=iv(text,'managed_l3_connected',0)
    stable=iv(text,'managed_l3_stable_after_5s',0)
    station_count=iv(text,'managed_l3_station_count',0)
    wpastart=iv(text,'managed_l3_wpa_supplicant_start_rc')
    wpa_alive=iv(text,'managed_l3_wpa_supplicant_alive_after_start')
    dhcp_rc=iv(text,'managed_l3_dhcp_rc')
    dhcp_bound=iv(text,'managed_l3_dhcp_bound',0)
    address=kv(text,'managed_l3_ipv4_address')
    prefix=iv(text,'managed_l3_ipv4_prefix')
    gateway=kv(text,'managed_l3_dhcp_router')
    gateway_ping_rc=iv(text,'managed_l3_gateway_ping_rc')
    gateway_ping_rx=iv(text,'managed_l3_gateway_ping_received',0)
    tx_before=iv(text,'managed_l3_txstatus_before',0)
    tx_after=iv(text,'managed_l3_txstatus_after',0)
    irq_before=iv(text,'managed_l3_host_irq_count_before',0)
    irq_after=iv(text,'managed_l3_host_irq_count_after',0)
    capture=iv(text,'managed_l3_capture_complete',0)
    revision=kv(text,'managed_l3_probe_revision')
    existing_iface_count=iv(text,'managed_l3_existing_wireless_interface_count')
    global_daemon_only=iv(text,'managed_l3_global_daemon_only_preflight')
    fatal_kernel_error = bool(re.search(
        r'(?im)((?:^|\s)BUG:|(?:^|\s)Oops:|Kernel panic|b43-phy\d+[^\n]*(?:\bERROR\b|\bfatal\b)|(?:DMA|dma)[^\n]*(?:initialization|mapping|descriptor|engine)[^\n]*(?:error|failed|failure))',
        text,
    ))
    rx_packet_underrun_count = len(re.findall(r'(?im)b43-phy\d+[^\n]*RX: Packet size underrun', text))
    no_kernel_error = not fatal_kernel_error

    gates={
      'probe_supported': revision in {'v1.14.85','v1.14.87'},
      'daemon_preflight': global_daemon_only==1 and existing_iface_count==0,
      'country_ca': kv(text,'managed_l3_country')=='CA',
      'credentials_stdin': kv(text,'managed_l3_credentials_source')=='stdin',
      'credentials_nonpersistent': kv(text,'managed_l3_credentials_persistent')=='0',
      'normal_path_no_interposed_gates': all(kv(text,k)=='1' for k in ('managed_l3_no_debugfs_calibration','managed_l3_no_monitor_handoff','managed_l3_no_channel_gate')),
      'native_dma_requested': module_pio=='0',
      'active_dma': transfer=='dma',
      'identity': kv(text,'managed_l3_interface_mac')==kv(text,'stock_expected_wlan_mac') and kv(text,'managed_l3_interface_mac') not in (None,'missing'),
      'interface_started': iv(text,'managed_l3_interface_add_rc')==0 and iv(text,'managed_l3_interface_up_rc')==0 and kv(text,'managed_l3_b43_operating')=='1' and kv(text,'managed_l3_b43_status')=='2',
      'supplicant_started': wpastart==0 and wpa_alive==1,
      'connected': connected==1,
      'stable_5s': stable==1,
      'ssid_match': req_ssid is not None and link_ssid==req_ssid,
      'bssid_present': bool(bssid and re.fullmatch(r'[0-9a-f]{2}(?::[0-9a-f]{2}){5}',bssid)),
      'frequency_ca_2g': freq in CA_FREQS,
      'station_present': station_count is not None and station_count>=1,
      'dhcp_requested': kv(text,'requested_dhcp')=='1' and kv(text,'requested_l3_gateway_ping')=='1',
      'no_default_route_requested': kv(text,'requested_default_route')=='0',
      'dhcp_bound': dhcp_rc==0 and dhcp_bound==1 and ipv4(address) and prefix is not None and 1<=prefix<=32,
      'gateway_present': ipv4(gateway),
      'gateway_ping': gateway_ping_rc==0 and gateway_ping_rx is not None and gateway_ping_rx>=1,
      'tx_status_advanced': tx_after is not None and tx_before is not None and tx_after>tx_before,
      'pci_irq_active': irq_after is not None and irq_before is not None and irq_after>irq_before and iv(text,'managed_l3_host_irq')==109,
      'no_ap_injection_persistence': kv(text,'requested_ap')=='0' and kv(text,'requested_frame_injection')=='0' and kv(text,'requested_persistent_network_config')=='0' and kv(text,'requested_nvm_write')=='0' and kv(text,'requested_nor_write')=='0',
      'private_config_removed': iv(text,'managed_l3_private_config_removed')==1,
      'dhcp_files_removed': iv(text,'managed_l3_dhcp_files_removed')==1,
      'interface_removed': iv(text,'managed_l3_interface_removed')==1,
      'supplicant_stopped': iv(text,'managed_l3_supplicant_stopped')==1,
      'capture_complete': capture==1,
      'transport_succeeded': host_rc==0,
      'no_kernel_error': no_kernel_error,
    }
    problems=[k for k,v in gates.items() if not v]
    passed=not problems
    if passed:
        finding='b43-normal-managed-dma-wpa-psk-dhcp-gateway-l3-qualified'
    elif not gates['active_dma']:
        finding='managed-l3-native-dma-not-active'
    elif not gates['connected']:
        finding='managed-l3-authentication-or-association-failed'
    elif not gates['dhcp_bound']:
        finding='managed-l3-dhcp-failed'
    elif not gates['gateway_ping']:
        finding='managed-l3-gateway-unreachable'
    elif not gates['tx_status_advanced']:
        finding='managed-l3-no-b43-txstatus'
    elif not gates['pci_irq_active']:
        finding='managed-l3-no-host-irq-progress'
    else:
        finding='managed-l3-qualification-failed'

    result={
      'schema':'rv220w-b43-managed-l3-analysis-v2',
      'input':str(p),'passed':passed,'finding':finding,'problems':problems,'gates':gates,
      'network':{'requested_ssid':req_ssid,'linked_ssid':link_ssid,'bssid':bssid,'frequency':freq,'station_count':station_count},
      'dhcp':{'rc':dhcp_rc,'bound':bool(dhcp_bound),'address':address,'prefix':prefix,'gateway':gateway,'gateway_ping_rc':gateway_ping_rc,'gateway_ping_received':gateway_ping_rx},
      'transport':{'module_pio':module_pio,'active':transfer,'host_rc':host_rc},
      'tx':{'before':tx_before,'after':tx_after,'delta':(tx_after-tx_before) if tx_after is not None and tx_before is not None else None},
      'irq':{'irq':iv(text,'managed_l3_host_irq'),'before':irq_before,'after':irq_after,'delta':(irq_after-irq_before) if irq_after is not None and irq_before is not None else None},
      'rx_telemetry':{'packet_size_underrun_count':rx_packet_underrun_count},
    }
    lines=[
      'RV220W BCM4322/b43 native-DMA WPA-PSK DHCP/gateway L3 qualification',
      f"transport: host_rc={host_rc} module_pio={module_pio} active={transfer} ({'PASS' if gates['native_dma_requested'] and gates['active_dma'] and gates['transport_succeeded'] else 'FAIL'})",
      f"association: connected={connected} stable5s={stable} stations={station_count} ssid={link_ssid!r} bssid={bssid} freq={freq} ({'PASS' if all(gates[k] for k in ('connected','stable_5s','station_present','ssid_match','bssid_present','frequency_ca_2g')) else 'FAIL'})",
      f"DHCP: rc={dhcp_rc} bound={dhcp_bound} address={address}/{prefix} gateway={gateway} ({'PASS' if gates['dhcp_bound'] and gates['gateway_present'] else 'FAIL'})",
      f"gateway ICMP: rc={gateway_ping_rc} received={gateway_ping_rx} ({'PASS' if gates['gateway_ping'] else 'FAIL'})",
      f"b43 TX status: {tx_before}->{tx_after} delta={(tx_after-tx_before) if tx_after is not None and tx_before is not None else 'missing'} ({'PASS' if gates['tx_status_advanced'] else 'FAIL'})",
      f"PCI/host IRQ: irq={iv(text,'managed_l3_host_irq')} count={irq_before}->{irq_after} delta={(irq_after-irq_before) if irq_after is not None and irq_before is not None else 'missing'} ({'PASS' if gates['pci_irq_active'] else 'FAIL'})",
      f"teardown: config={iv(text,'managed_l3_private_config_removed')} dhcp_files={iv(text,'managed_l3_dhcp_files_removed')} iface={iv(text,'managed_l3_interface_removed')} supplicant={iv(text,'managed_l3_supplicant_stopped')} ({'PASS' if all(gates[k] for k in ('private_config_removed','dhcp_files_removed','interface_removed','supplicant_stopped')) else 'FAIL'})",
      f"RX diagnostic telemetry: packet_size_underrun_count={rx_packet_underrun_count} (INFO; not a fatal-kernel gate)",
      f'finding: {finding}', f"overall: {'PASS' if passed else 'FAIL'}"
    ]
    if problems: lines.append('failed gates: '+','.join(problems))
    out='\n'.join(lines)+'\n'
    if a.json_out: Path(a.json_out).write_text(json.dumps(result,indent=2,sort_keys=True)+'\n')
    if a.text_out: Path(a.text_out).write_text(out)
    print(out,end='')
    return 0 if passed else 1

if __name__=='__main__': sys.exit(main())
