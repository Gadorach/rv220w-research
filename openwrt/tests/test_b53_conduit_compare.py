#!/usr/bin/env python3
from __future__ import annotations
import pathlib, subprocess, sys, tempfile
ROOT=pathlib.Path(__file__).resolve().parents[1]
TOOL=ROOT/'scripts/host/compare_rv220w_b53_snapshots.py'

def report(conduit:str,p0:str,p5:str,p8:str)->str:
    return f'''RV220W passive B53 topology snapshot
live_wan_conduit={conduit}
expected_wan_cpu_port={'5' if conduit=='eth1' else '8'}
conduit_register_check={'ok' if (conduit=='eth1' and p0=='0x0021' and p5=='0x0021') or (conduit=='eth0' and p0=='0x0101' and p8=='0x011f') else 'failed'}
switch_mode=0x02
broadcom_header_control=0x03
broadcom_header_rx_disable=0x0000
broadcom_header_tx_disable=0x0000
=== PORT_REGISTERS ===
[port 0]
port_control=0x00
port_vlan_mask={p0}
default_vlan_tag=0x0001
gmii_override=0x0b
rgmii_control=0x00
[port 5]
port_control=0x00
port_vlan_mask={p5}
default_vlan_tag=0x0001
gmii_override=0x4b
rgmii_control=0x00
[port 8]
port_control=0x00
port_vlan_mask={p8}
default_vlan_tag=0x0001
rgmii_control=0x00
'''
with tempfile.TemporaryDirectory() as d:
    d=pathlib.Path(d); a=d/'a.txt'; b=d/'b.txt'
    a.write_text(report('eth1','0x0101','0x0021','0x011e'))
    b.write_text(report('eth0','0x0101','0x0020','0x011f'))
    out=subprocess.check_output([sys.executable,str(TOOL),str(a),str(b)],text=True)
    assert '! live_wan_conduit' in out
    assert '{0,8}' in out
    assert '{0,1,2,3,4,8}' in out
print('B53 conduit comparison checks passed')
