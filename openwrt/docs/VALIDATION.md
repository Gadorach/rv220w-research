# Toolkit validation status

## Hardware-proven state — 2026-07-27

Toolkit v1.9.0 has been built and booted on the Cisco RV220W through the stock U-Boot TFTP path. The resulting `rj45-full` image reaches a running OpenWrt userspace entirely from RAM and initializes and operates all five RJ45 ports.

Confirmed topology:

```text
WAN  -> BCM53115 port 0 -> CPU port 5 -> Octeon eth1 -> DSA wan
LAN1 -> BCM53115 port 1 \
LAN2 -> BCM53115 port 2  \
LAN3 -> BCM53115 port 3   > CPU port 8 -> Octeon eth0 -> DSA -> br-lan
LAN4 -> BCM53115 port 4  /
```

Confirmed implementation state:

- both switch CPU links use `rgmii-rxid`;
- patch 998 includes firmware-described DSA CPU ports in B53's active-port mask before default VLAN/PVID initialization;
- the WAN hardware domain remains `{0,5}`;
- the LAN hardware domain remains `{1,2,3,4,8}`;
- the Linux LAN bridge contains only `lan1`–`lan4`;
- LAN DHCP, WAN DHCP/DHCPv6, firewall4, LAN-to-WAN forwarding, masquerading, and PPP/PPPoE packages are present in the profile;
- NOR remains untouched by the build and boot workflow.

## Current validation boundary

The result is experimental test firmware, not a polished release. The following are not part of the proven result:

- LuCI;
- BCM4322 Wi-Fi operation;
- persistent SquashFS/sysupgrade installation;
- erase, program, or boot from the onboard NOR;
- qualified reset-button, LED, or watchdog integration;
- interrupted-write and power-loss recovery.

Preserve the final hardware run as a reproducible regression package containing:

- toolkit version and `source-lock.json`;
- expanded OpenWrt configuration;
- artifact SHA-256 and ELF inspection output;
- build log;
- U-Boot/TFTP serial log;
- post-boot network state;
- traffic results for every RJ45 port;
- WAN DHCP/routing/firewall results where exercised.

## Static regression suite

Run:

```bash
python3 tests/test_static_toolkit.py
python3 tests/test_rj45_full_profile.py
```

The suite validates platform overlay structure, build-mode selection, noninteractive build guards, UART framing, B53 selector safety, DSA profiles, kernel patch structure, full-RJ45 UCI policy, and the absence of unsafe flash commands in the tested helpers.

## Historical validation records

Versioned stage, hotfix, and setup-failure documents in this directory describe the evidence and implementation state at the time they were produced. Use [`CURRENT_STATUS.md`](CURRENT_STATUS.md) for the current hardware result.
