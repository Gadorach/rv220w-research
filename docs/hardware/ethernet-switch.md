# Ethernet and BCM53115 switch

## Stock architecture

The stock stack is approximately:

```text
CN5010 packet I/O / RGMII
  └─ cavium-ethernet.ko
       ├─ Broadcom tag and hardware-offload hooks
       └─ MDIO API
            └─ mii.ko
                 └─ bcm5398.ko
                      └─ BCM53115 port/VLAN/IMP management
```

The module is named `bcm5398.ko` but contains BCM53115 identification and useful symbols including register access, port state, VLAN, and mirror configuration.

U-Boot reports three RGMII ports and then executes `disable 53115 ... Done`, so TFTP reachability through the front-panel ports must be proven rather than assumed.

## Unknowns

- Physical jack to `octeth0/1/2` mapping.
- MDIO/pseudo-PHY address.
- BCM53115 CPU/IMP port number.
- RGMII RX/TX delay configuration.
- Broadcom tag placement and managed-mode behavior.
- Bootloader switch state during TFTP.

## Promotion sequence

1. Prove a native Octeon interface independently if possible.
2. Capture stock MDIO reads/writes and module parameters.
3. Identify switch chip ID and CPU port.
4. Bring up read-only B53 register access.
5. Establish one untagged CPU-to-front-port VLAN.
6. Add DSA port model and tagging only after basic forwarding works.
7. Validate all five physical ports, link modes, counters, and reset recovery.

Linux B53/DSA support is the preferred modern path, but the BCM53115 managed-mode/tagging details may require a focused patch or an initial VLAN-based compatibility mode.
