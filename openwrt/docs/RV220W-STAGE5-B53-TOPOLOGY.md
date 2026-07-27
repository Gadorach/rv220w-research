# Stage 5 — BCM53115 passive topology result

The selector-only snapshots proved the vendor topology:

- switch port 0 / PHY0 is WAN and is paired by port-based VLAN mask `0x0021` with switch port 5;
- switch ports 1-4 / PHY1-4 are LAN1-LAN4 and share mask `0x011e` with switch port 8;
- ports 5 and 8 remain linked at 1000/full with no external cables and are the two Octeon conduits;
- host counters map port 5 to `eth1` and port 8 to `eth0`;
- ports 6 and 7 are unused;
- port-based VLAN membership provided the captured WAN/LAN split, but run9 later proved that ordinary 802.1Q/PVID membership still gates whether a selected CPU conduit can receive untagged ingress;
- Broadcom header control was enabled for both CPU ports.

Selector registers were restored after every snapshot, closing the passive discovery campaign.

## Subsequent hardware promotion

Toolkit v1.7.6 has now hardware-validated the entire port-8/`eth0` LAN path under upstream B53/DSA:

```text
ports 1-4 -> port 8 -> eth0 -> Linux DSA -> br-lan
```

All four LAN ports negotiated 1000/full and passed host-to-router traffic; LAN1 also passed packet sizes through a full 1500-byte IPv4 frame. Run9 then proved port 0 through CPU port 5/`eth1`: both VID-0 and VID-1 `{0,5}` domains passed, while the original state failed because BCM53115 generic setup omitted port 5 from the selected ordinary VLAN entry. Toolkit v1.9.0 fixes this with generic B53 patch 998 and adds the first complete wired-router profile.
