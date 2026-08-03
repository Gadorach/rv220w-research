# Stage 6 — LAN DSA hardware validation complete

## Result

Toolkit v1.7.6 established a working Linux DSA data path for all four RV220W LAN jacks while booted entirely from RAM.

Validated topology:

```text
LAN1 / BCM53115 port 1 ┐
LAN2 / BCM53115 port 2 │
LAN3 / BCM53115 port 3 ├─ BCM53115 CPU port 8 ─ Octeon eth0
LAN4 / BCM53115 port 4 ┘
```

The CPU-port link uses `rgmii-rxid`. The Broadcom DSA tag driver is loaded before B53, `eth0` is associated with its per-port device-tree node, and the Octeon receive path accepts length-mismatch error 10 only when the receiving MAC is an active DSA conduit.

## Hardware evidence

Each external LAN port negotiated 1000BASE-T full duplex, entered bridge forwarding, and passed bidirectional host-to-router traffic through `br-lan` at `192.168.240.2/24`.

Observed test-window deltas:

| Port | RX packet delta | TX packet delta | Interface errors/drops |
|---|---:|---:|---:|
| LAN1 | 27 | 12 | 0 |
| LAN2 | 64 | 22 | 0 |
| LAN3 | 78 | 22 | 0 |
| LAN4 | 60 | 22 | 0 |

LAN1 additionally passed 20/20 ICMP exchanges at payload sizes 0, 18, 56, 512, 1400 and 1472 bytes with DF set. The 1472-byte case produces a complete 1500-byte IPv4 packet and proves that the DSA conduit's 1504-byte MTU accommodates the four-byte Broadcom tag.

No sustained Octeon receive-error-10 messages returned after the v1.7.6 patch. BCM53115 MIB counters did not accumulate FCS, alignment or receive-drop errors during the validation windows.

## Proven kernel changes

The working image carries two narrow Octeon driver fixes:

1. Associate each legacy Octeon netdev with its individual device-tree Ethernet node so DSA can resolve the CPU-port `ethernet` phandle.
2. Permit Octeon PIP length-mismatch error 10 to continue only on a netdev currently used as a DSA conduit; the normal DSA tag parser remains responsible for validating the frame.

Neither patch modifies B53 or OpenWrt core.

## Baseline status

The `dsa-lan` / `rv220w-dsa-lan-rxid` build is now the hardware-proven LAN reference. The `txid` and plain `rgmii` alternatives are retained only for diagnostics and should not replace the proven timing.

WAN was intentionally absent from this profile. Testing a cable in the WAN jack therefore left `eth1` down and did not create a `wan` DSA user port; that result was expected rather than a hardware failure.
