# RV220W physical-jack mapping campaign

Use only the v1.4.0 discovery image. Keep UART open throughout the campaign.

## Preparation gate

Collect:

```fish
./rv220w.fish collect-snapshot no-cable-baseline
./rv220w.fish collect-snapshot known-working-jack
```

Confirm the second snapshot still shows the expected legacy link and that no B53/DSA switch device has bound.

## Per-jack sequence

Repeat for `WAN`, `LAN1`, `LAN2`, `LAN3`, and `LAN4`:

1. Disconnect all Ethernet cables.
2. Connect only the test laptop to the selected physical jack.
3. Collect `<JACK>-before`.
4. Generate ARP, ICMP, and broadcast traffic for 20 seconds.
5. Collect `<JACK>-after`.
6. Record link and activity LED behavior.
7. Save the host NIC counter delta for the same interval.

Example:

```fish
./rv220w.fish collect-snapshot LAN1-before
ping -c 20 192.168.240.2
./rv220w.fish collect-snapshot LAN1-after
```

Repeat the complete campaign after a cold power cycle. Do not infer BCM53115 internal port numbering from front-panel order or from an Octeon `ethX` result alone.

## Safety

- Do not run `mdio ... raw REG DATA`.
- Do not bind B53 manually.
- Do not load a candidate DSA device-tree overlay.
- Do not run MTD erase/write commands.
- Reboot to stock immediately if the legacy management path disappears unexpectedly.
