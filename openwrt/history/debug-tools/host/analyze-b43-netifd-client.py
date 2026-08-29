#!/usr/bin/env python3
import argparse, json, re, sys
from ipaddress import ip_interface
from pathlib import Path

CA_FREQS={2412,2417,2422,2427,2432,2437,2442,2447,2452,2457,2462}

def kv(text,key):
    m=re.search(rf'(?m)^{re.escape(key)}=(.*)$',text)
    return m.group(1).strip() if m else None

def iv(text,key,default=None):
    v=kv(text,key)
    try: return int(v) if v is not None else default
    except (TypeError,ValueError): return default

def cidr_ok(v):
    try:
        x=ip_interface(v)
        return x.version==4
    except Exception:
        return False

def main():
    ap=argparse.ArgumentParser()
    ap.add_argument('input')
    ap.add_argument('--json',dest='json_out')
    ap.add_argument('--text',dest='text_out')
    a=ap.parse_args(); p=Path(a.input); text=p.read_text(errors='replace')

    req_ssid=kv(text,'netifd_client_requested_ssid')
    cidr=kv(text,'netifd_client_ipv4_cidr')
    transfer=kv(text,'netifd_client_b43_transfer')
    tx0=iv(text,'netifd_client_txstatus_before',0); tx1=iv(text,'netifd_client_txstatus_after',0)
    irq0=iv(text,'netifd_client_host_irq_count_before',0); irq1=iv(text,'netifd_client_host_irq_count_after',0)
    host_rc=iv(text,'netifd_client_transport_rc')
    dmesg_start=text.find('=== netifd-client dmesg tail ===')
    dmesg=text[dmesg_start:] if dmesg_start>=0 else ''
    fatal=bool(re.search(r'(?im)((?:^|\s)BUG:|(?:^|\s)Oops:|Kernel panic|b43-phy\d+[^\n]*(?:\bERROR\b|\bfatal\b)|(?:DMA|dma)[^\n]*(?:initialization|mapping|descriptor|engine)[^\n]*(?:error|failed|failure))',dmesg))
    underruns=len(re.findall(r'(?im)b43-phy\d+[^\n]*RX: Packet size underrun',dmesg))

    gates={
      'probe_v11488':kv(text,'netifd_client_probe_revision')=='v1.14.88',
      'country_ca':kv(text,'netifd_client_country')=='CA',
      'ram_only':kv(text,'netifd_client_ram_only_verified')=='1',
      'credentials_nonpersistent':kv(text,'netifd_client_credentials_source')=='stdin' and kv(text,'netifd_client_credentials_persistent')=='0',
      'netifd_owns_wpa_dhcp':kv(text,'netifd_client_no_manual_wpa_supplicant')=='1' and kv(text,'netifd_client_no_manual_udhcpc')=='1',
      'native_dma_requested':kv(text,'b43_module_pio')=='0',
      'uci_committed':iv(text,'netifd_client_uci_committed')==1,
      'network_reload':iv(text,'netifd_client_network_reload_rc')==0 and iv(text,'netifd_client_wifi_up_rc')==0,
      'wwan_up':iv(text,'netifd_client_wwan_up')==1,
      'associated':iv(text,'netifd_client_connected')==1 and iv(text,'netifd_client_station_count',0)>=1 and req_ssid not in (None,''),
      'dhcp_ipv4':cidr_ok(cidr),
      'active_dma':transfer=='dma' and kv(text,'netifd_client_b43_operating')=='1' and kv(text,'netifd_client_b43_status')=='2',
      'no_wifi_default_route':iv(text,'netifd_client_wifi_default_route_present')==0 and kv(text,'requested_default_route')=='0',
      'no_peer_dns':kv(text,'requested_peer_dns')=='0',
      'tx_status_advanced':tx1>tx0,
      'pci_irq_active':iv(text,'netifd_client_host_irq')==109 and irq1>irq0,
      'no_ap_injection_persistence':kv(text,'requested_ap')=='0' and kv(text,'requested_frame_injection')=='0' and kv(text,'requested_persistent_network_config')=='0' and kv(text,'requested_nvm_write')=='0' and kv(text,'requested_nor_write')=='0',
      'network_restored':iv(text,'netifd_client_network_restored')==1,
      'wireless_restored':iv(text,'netifd_client_wireless_restored')==1,
      'interface_removed':iv(text,'netifd_client_interface_removed')==1,
      'backups_removed':iv(text,'netifd_client_backups_removed')==1,
      'capture_complete':iv(text,'netifd_client_capture_complete')==1,
      'transport_succeeded':host_rc==0,
      'no_fatal_kernel_error':not fatal,
    }
    problems=[k for k,v in gates.items() if not v]; passed=not problems
    if passed: finding='b43-openwrt-netifd-uci-native-dma-sta-dhcp-qualified'
    elif not gates['ram_only']: finding='netifd-client-not-ram-only'
    elif not gates['uci_committed'] or not gates['network_reload']: finding='netifd-client-uci-or-reload-failed'
    elif not gates['wwan_up']: finding='netifd-client-wwan-not-up'
    elif not gates['associated']: finding='netifd-client-association-failed'
    elif not gates['dhcp_ipv4']: finding='netifd-client-dhcp-failed'
    elif not gates['active_dma']: finding='netifd-client-native-dma-not-active'
    elif not gates['network_restored'] or not gates['wireless_restored'] or not gates['interface_removed']: finding='netifd-client-cleanup-restore-failed'
    else: finding='netifd-client-qualification-failed'

    result={
      'schema':'rv220w-b43-netifd-client-analysis-v1','input':str(p),'passed':passed,'finding':finding,'problems':problems,'gates':gates,
      'network':{'ssid':req_ssid,'interface':kv(text,'netifd_client_interface'),'ipv4_cidr':cidr,'radio_section':kv(text,'netifd_client_radio_section')},
      'transport':{'active':transfer,'module_pio':kv(text,'b43_module_pio'),'host_rc':host_rc},
      'tx':{'before':tx0,'after':tx1,'delta':tx1-tx0},
      'irq':{'irq':iv(text,'netifd_client_host_irq'),'before':irq0,'after':irq1,'delta':irq1-irq0},
      'restore':{'network_before':kv(text,'netifd_client_network_sha_before'),'network_after':kv(text,'netifd_client_network_sha_after'),'wireless_before':kv(text,'netifd_client_wireless_sha_before'),'wireless_after':kv(text,'netifd_client_wireless_sha_after')},
      'rx_telemetry':{'packet_size_underrun_count':underruns},
    }
    lines=[
      'RV220W BCM4322/b43 OpenWrt UCI/netifd native-DMA station qualification',
      f"netifd lifecycle: uci={iv(text,'netifd_client_uci_committed')} reload={iv(text,'netifd_client_network_reload_rc')} wifi_up={iv(text,'netifd_client_wifi_up_rc')} wwan_up={iv(text,'netifd_client_wwan_up')} ({'PASS' if gates['uci_committed'] and gates['network_reload'] and gates['wwan_up'] else 'FAIL'})",
      f"station/DHCP: connected={iv(text,'netifd_client_connected')} stations={iv(text,'netifd_client_station_count')} address={cidr} ({'PASS' if gates['associated'] and gates['dhcp_ipv4'] else 'FAIL'})",
      f"native DMA: pio={kv(text,'b43_module_pio')} active={transfer} operating={kv(text,'netifd_client_b43_operating')} status={kv(text,'netifd_client_b43_status')} ({'PASS' if gates['native_dma_requested'] and gates['active_dma'] else 'FAIL'})",
      f"b43 TX/IRQ: tx={tx0}->{tx1} irq109={irq0}->{irq1} ({'PASS' if gates['tx_status_advanced'] and gates['pci_irq_active'] else 'FAIL'})",
      f"routing isolation: wifi_default_route={iv(text,'netifd_client_wifi_default_route_present')} peer_dns={kv(text,'requested_peer_dns')} ({'PASS' if gates['no_wifi_default_route'] and gates['no_peer_dns'] else 'FAIL'})",
      f"config restore: network={iv(text,'netifd_client_network_restored')} wireless={iv(text,'netifd_client_wireless_restored')} iface_removed={iv(text,'netifd_client_interface_removed')} backups_removed={iv(text,'netifd_client_backups_removed')} ({'PASS' if gates['network_restored'] and gates['wireless_restored'] and gates['interface_removed'] and gates['backups_removed'] else 'FAIL'})",
      f"RX diagnostic telemetry: packet_size_underrun_count={underruns} (INFO)",
      f'finding: {finding}', f"overall: {'PASS' if passed else 'FAIL'}",
    ]
    if problems: lines.append('failed gates: '+','.join(problems))
    out='\n'.join(lines)+'\n'
    if a.text_out: Path(a.text_out).write_text(out)
    if a.json_out: Path(a.json_out).write_text(json.dumps(result,indent=2,sort_keys=True)+'\n')
    print(out,end=''); return 0 if passed else 1

if __name__=='__main__': sys.exit(main())
