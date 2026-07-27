# Ethernet and BCM53115 switch

## Confirmed modern topology

The BCM53115 is controlled by Linux B53/DSA at pseudo-PHY address `0x1e`. All five external RJ45 ports are operational in the current RAM-boot image.

| Function | BCM53115 port | Octeon path | Linux interface |
|---|---:|---|---|
| WAN | 0 | CPU port 5 -> `eth1` | `wan` |
| LAN1 | 1 | CPU port 8 -> `eth0` | `lan1` |
| LAN2 | 2 | CPU port 8 -> `eth0` | `lan2` |
| LAN3 | 3 | CPU port 8 -> `eth0` | `lan3` |
| LAN4 | 4 | CPU port 8 -> `eth0` | `lan4` |

Switch ports 5 and 8 use `rgmii-rxid` and operate as independent CPU conduits. `eth2` has no observed external link and is strongly associated with the unpopulated optional RJ45/magnetics footprint.

## VLAN and conduit result

The hardware isolation domains are:

```text
WAN: {0,5}
LAN: {1,2,3,4,8}
```

Run9 proved that WAN ingress through CPU port 5 failed when that firmware-described CPU port was excluded from B53's active-port mask and therefore skipped by generic default VLAN/PVID setup. Toolkit patch `998-b53-enable-dt-cpu-ports.patch` merges DSA CPU ports into `enabled_ports` before normal B53 configuration.

This replaces the earlier diagnostic-only state. No userspace MDIO repair is required in the current `rj45-full` image.

## Stock architecture

The factory software used Cavium Ethernet, a Broadcom-tag path, `mii.ko`, and a module named `bcm5398.ko` that contains BCM53115 register, VLAN, port, and IMP management logic. That stack remains useful as historical evidence, but the modern image uses B53/DSA.

## Remaining Ethernet work

- Long-duration and repeated cold-boot regression testing.
- Tagged WAN subinterface regression testing where required by an ISP.
- Performance characterization beyond functional traffic validation.
- Upstream-quality review and separation of generic versus RV220W-specific patches.
