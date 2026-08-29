#!/usr/bin/env python3
import argparse, json, re, sys
from ipaddress import ip_address
from pathlib import Path

CA_FREQS={2412,2417,2422,2427,2432,2437,2442,2447,2452,2457,2462}

def kv(text,key):
    m=re.search(rf'(?m)^{re.escape(key)}=(.*)$',text)
    return m.group(1).strip() if m else None

def iv(text,key,default=None):
    v=kv(text,key)
    try: return int(v) if v is not None else default
    except (TypeError,ValueError): return default

def freq_iv(text,key):
    v=kv(text,key)
    try: return int(float(v)) if v is not None else None
    except (TypeError,ValueError): return None

def ipv4(v):
    try: return bool(v and ip_address(v).version==4)
    except ValueError: return False

def main():
    ap=argparse.ArgumentParser()
    ap.add_argument('input')
    ap.add_argument('--json',dest='json_out')
    ap.add_argument('--text',dest='text_out')
    a=ap.parse_args(); p=Path(a.input); text=p.read_text(errors='replace')

    revision=kv(text,'managed_l3_probe_revision')
    req_ssid=kv(text,'managed_l3_requested_ssid'); link_ssid=kv(text,'managed_l3_link_ssid')
    bssid=kv(text,'managed_l3_link_bssid'); freq=freq_iv(text,'managed_l3_link_frequency')
    module_pio=kv(text,'b43_module_pio'); transfer=kv(text,'managed_l3_b43_transfer')
    connected=iv(text,'managed_l3_connected',0); stable=iv(text,'managed_l3_stable_after_5s',0)
    stations=iv(text,'managed_l3_station_count',0)
    dhcp_rc=iv(text,'managed_l3_dhcp_rc'); dhcp_bound=iv(text,'managed_l3_dhcp_bound',0)
    addr=kv(text,'managed_l3_ipv4_address'); prefix=iv(text,'managed_l3_ipv4_prefix')
    gateway=kv(text,'managed_l3_dhcp_router'); dns=kv(text,'managed_l3_dns_server') or (kv(text,'managed_l3_dhcp_dns') or '').split(' ')[0]
    gateway_rc=iv(text,'managed_l3_gateway_ping_rc'); gateway_rx=iv(text,'managed_l3_gateway_ping_received',0)
    route_rc=iv(text,'managed_l3_internet_route_rc'); internet_rc=iv(text,'managed_l3_internet_ping_rc')
    internet_rx=iv(text,'managed_l3_internet_ping_received',0); route_removed=iv(text,'managed_l3_internet_route_removed',0)
    dns_rc=iv(text,'managed_l3_dns_query_rc'); dns_answer=iv(text,'managed_l3_dns_answer_present',0)
    tx_before=iv(text,'managed_l3_txstatus_before',0); tx_after=iv(text,'managed_l3_txstatus_after',0)
    irq_before=iv(text,'managed_l3_host_irq_count_before',0); irq_after=iv(text,'managed_l3_host_irq_count_after',0)
    host_rc=iv(text,'managed_l3_transport_rc')
    fatal_kernel_error=bool(re.search(
        r'(?im)((?:^|\s)BUG:|(?:^|\s)Oops:|Kernel panic|b43-phy\d+[^\n]*(?:\bERROR\b|\bfatal\b)|(?:DMA|dma)[^\n]*(?:initialization|mapping|descriptor|engine)[^\n]*(?:error|failed|failure))',text))
    rx_underruns=len(re.findall(r'(?im)b43-phy\d+[^\n]*RX: Packet size underrun',text))

    gates={
      'probe_v11487':revision=='v1.14.87',
      'internet_requested':kv(text,'managed_l3_internet_requested')=='1' and kv(text,'requested_internet')=='1' and kv(text,'requested_dns')=='1' and kv(text,'requested_public_icmp')=='1' and kv(text,'requested_host_route_only')=='1',
      'country_ca':kv(text,'managed_l3_country')=='CA',
      'credentials_nonpersistent':kv(text,'managed_l3_credentials_source')=='stdin' and kv(text,'managed_l3_credentials_persistent')=='0',
      'normal_path_no_interposed_gates':all(kv(text,k)=='1' for k in ('managed_l3_no_debugfs_calibration','managed_l3_no_monitor_handoff','managed_l3_no_channel_gate')),
      'native_dma':module_pio=='0' and transfer=='dma',
      'identity':kv(text,'managed_l3_interface_mac')==kv(text,'stock_expected_wlan_mac') and kv(text,'managed_l3_interface_mac') not in (None,'missing'),
      'interface_started':iv(text,'managed_l3_interface_add_rc')==0 and iv(text,'managed_l3_interface_up_rc')==0 and kv(text,'managed_l3_b43_operating')=='1' and kv(text,'managed_l3_b43_status')=='2',
      'association':connected==1 and stable==1 and stations>=1 and req_ssid is not None and link_ssid==req_ssid and bool(bssid and re.fullmatch(r'[0-9a-f]{2}(?::[0-9a-f]{2}){5}',bssid)) and freq in CA_FREQS,
      'dhcp':dhcp_rc==0 and dhcp_bound==1 and ipv4(addr) and prefix is not None and 1<=prefix<=32 and ipv4(gateway),
      'gateway_ping':gateway_rc==0 and gateway_rx>=1,
      'no_default_route_requested':kv(text,'requested_default_route')=='0',
      'public_host_route_added':route_rc==0,
      'public_icmp':internet_rc==0 and internet_rx>=1,
      'dns_server_present':ipv4(dns),
      'dns_query':dns_rc==0 and dns_answer==1,
      'public_host_route_removed':route_removed==1,
      'tx_status_advanced':tx_after>tx_before,
      'pci_irq_active':iv(text,'managed_l3_host_irq')==109 and irq_after>irq_before,
      'no_ap_injection_persistence':kv(text,'requested_ap')=='0' and kv(text,'requested_frame_injection')=='0' and kv(text,'requested_persistent_network_config')=='0' and kv(text,'requested_nvm_write')=='0' and kv(text,'requested_nor_write')=='0',
      'teardown':all(iv(text,k)==1 for k in ('managed_l3_private_config_removed','managed_l3_dhcp_files_removed','managed_l3_interface_removed','managed_l3_supplicant_stopped')),
      'capture_complete':iv(text,'managed_l3_capture_complete')==1,
      'transport_succeeded':host_rc==0,
      'no_fatal_kernel_error':not fatal_kernel_error,
    }
    problems=[k for k,v in gates.items() if not v]; passed=not problems
    if passed: finding='b43-normal-managed-dma-wpa-psk-dhcp-internet-dns-qualified'
    elif not gates['native_dma']: finding='managed-internet-native-dma-not-active'
    elif not gates['association']: finding='managed-internet-association-failed'
    elif not gates['dhcp']: finding='managed-internet-dhcp-failed'
    elif not gates['gateway_ping']: finding='managed-internet-gateway-unreachable'
    elif not gates['public_host_route_added']: finding='managed-internet-host-route-failed'
    elif not gates['public_icmp']: finding='managed-internet-public-icmp-failed'
    elif not gates['dns_query']: finding='managed-internet-dns-query-failed'
    elif not gates['public_host_route_removed']: finding='managed-internet-host-route-cleanup-failed'
    else: finding='managed-internet-qualification-failed'

    result={
      'schema':'rv220w-b43-managed-internet-analysis-v1','input':str(p),'passed':passed,'finding':finding,'problems':problems,'gates':gates,
      'network':{'ssid':link_ssid,'bssid':bssid,'frequency':freq,'address':addr,'prefix':prefix,'gateway':gateway,'dns_server':dns},
      'internet':{'target':kv(text,'managed_l3_internet_target'),'route_rc':route_rc,'ping_rc':internet_rc,'ping_received':internet_rx,'route_removed':bool(route_removed),'dns_rc':dns_rc,'dns_answer_present':bool(dns_answer)},
      'transport':{'module_pio':module_pio,'active':transfer,'host_rc':host_rc},
      'tx':{'before':tx_before,'after':tx_after,'delta':tx_after-tx_before},
      'irq':{'irq':iv(text,'managed_l3_host_irq'),'before':irq_before,'after':irq_after,'delta':irq_after-irq_before},
      'rx_telemetry':{'packet_size_underrun_count':rx_underruns},
    }
    lines=[
      'RV220W BCM4322/b43 native-DMA WPA-PSK Internet/DNS qualification',
      f"transport/association: dma={transfer} connected={connected} stable5s={stable} stations={stations} ({'PASS' if gates['native_dma'] and gates['association'] else 'FAIL'})",
      f"DHCP/gateway: address={addr}/{prefix} gateway={gateway} gateway_rx={gateway_rx} ({'PASS' if gates['dhcp'] and gates['gateway_ping'] else 'FAIL'})",
      f"public ICMP: target={kv(text,'managed_l3_internet_target')} route_rc={route_rc} ping_rc={internet_rc} received={internet_rx} route_removed={route_removed} ({'PASS' if gates['public_host_route_added'] and gates['public_icmp'] and gates['public_host_route_removed'] else 'FAIL'})",
      f"DNS: server={dns} query_rc={dns_rc} answer_present={dns_answer} ({'PASS' if gates['dns_server_present'] and gates['dns_query'] else 'FAIL'})",
      f"b43 TX/IRQ: tx={tx_before}->{tx_after} irq109={irq_before}->{irq_after} ({'PASS' if gates['tx_status_advanced'] and gates['pci_irq_active'] else 'FAIL'})",
      f"RX diagnostic telemetry: packet_size_underrun_count={rx_underruns} (INFO)",
      f"teardown/no-default-route: teardown={int(gates['teardown'])} default_route_requested={kv(text,'requested_default_route')} ({'PASS' if gates['teardown'] and gates['no_default_route_requested'] else 'FAIL'})",
      f'finding: {finding}', f"overall: {'PASS' if passed else 'FAIL'}",
    ]
    if problems: lines.append('failed gates: '+','.join(problems))
    out='\n'.join(lines)+'\n'
    if a.text_out: Path(a.text_out).write_text(out)
    if a.json_out: Path(a.json_out).write_text(json.dumps(result,indent=2,sort_keys=True)+'\n')
    print(out,end=''); return 0 if passed else 1

if __name__=='__main__': sys.exit(main())
