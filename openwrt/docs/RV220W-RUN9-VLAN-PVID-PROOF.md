# RV220W run9: ordinary VLAN/PVID proof

## Result

Run9 isolated the remaining WAN failure to the BCM53115 ordinary VLAN table,
not to RGMII timing, DSA tagging, EAP mode, firewall policy, or port-based VLAN
(PVLAN) affinity.

The failed boot-time state was:

```text
wan@eth1
port 0 PVID = 0
port 5 PVID = 1
VID 0 members = {0,1,2,3,4,8}
VID 1 members = {}
PVLAN port 0 = {0,5}
PVLAN port 5 = {0,5}
```

Changing only port 5's PVID from 1 to 0 did not restore forwarding because
port 5 still was not a member of VID 0.

Adding port 5 to VID 0 while keeping both ends at PVID 0 restored ARP, normal
ICMP, and a 1472-byte ICMP payload.  Restoring the original table restored the
failure.  A separate VLAN-1 domain with ports 0 and 5 also passed, proving that
the absolute VID is not special; consistent ingress classification and egress
membership are what matter.

## Root cause

Upstream B53 defines BCM53115 `enabled_ports` as `0x11f`, which contains ports
0-4 and the normal IMP at port 8 but omits alternate IMP/CPU port 5.  The
RV220W device tree legitimately describes both port 5 and port 8 as DSA CPU
ports.  Generic `b53_configure_vlan()` iterates `dev->enabled_ports`, so it
initializes port 8 but skips port 5 when it writes the default PVID and creates
the default VLAN entry.

The multi-conduit PVLAN callback therefore produced the correct `{0,5}` WAN
domain while the separate 802.1Q table still rejected port-0 ingress from
reaching port 5.

## Production rule

The driver must merge firmware-described DSA CPU ports into the active-port
mask before generic switch configuration:

```c
dev->enabled_ports |= (u16)dsa_cpu_ports(ds);
```

The existing B53 setup then applies its normal default PVID and VLAN entry to
both CPU conduits.  No board-specific WAN VID is introduced.

WAN isolation remains layered:

1. BCM53115 PVLAN masks isolate `{0,5}` from `{1,2,3,4,8}`.
2. Linux keeps `wan` outside `br-lan`.
3. firewall4 rejects WAN-to-LAN forwarding and permits LAN-to-WAN NAT.
4. ISP VLANs remain software-defined as `wan.<VID>`.

## Preserved evidence

The complete UART DSA and passive B53 reports are under
`evidence/run9-vlan-pvid/`.
