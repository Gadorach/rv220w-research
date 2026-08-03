# Combined boot-policy patch: design and hardware validation

## Purpose

The vendor RV220W boot chain imposed two policies that prevented a persistent
OpenWrt configuration:

1. late board initialization replaced the saved `bootcmd` with the compiled
   stock command;
2. a failed proprietary firmware-format check launched Sercomm HTTP recovery
   before normal U-Boot command processing.

The combined patch changes only the two controlling instructions. The physical
active-low recovery-button path remains intact.

## Patch sites

### Preserve saved `bootcmd`

At combined boot-chain and sector-0 offset `0x13168`:

```text
03 20 00 08  jr t9
03 e0 00 08  jr ra
```

The function epilogue has already restored `ra`, `gp` and `s0`; the existing
delay slot restores `sp`. Returning there suppresses only the final environment
setter tail call.

### Skip invalid-firmware HTTP recovery

At offset `0x13138`:

```text
04 41 00 03  bgez v0, +3
10 00 00 03  b     +3
```

Both branches target `0xffffffffbfc13148`. The replacement always follows the
existing firmware-check success path and skips `do_http`.

The earlier control flow remains:

```text
GPIO 1 == 0 -> active-low recovery button -> do_download -> Sercomm download
GPIO 1 == 1 -> firmware checker -> patched continuation to normal U-Boot flow
```

## Known sector identities

```text
stock         ce86d667  branch=04410003 bootcmd=03200008
bootcmd-only  36db247b  branch=04410003 bootcmd=03e00008
HTTP-only     4f2766c2  branch=10000003 bootcmd=03200008
combined      b77a94de  branch=10000003 bootcmd=03e00008
```

Relative to stock, the combined sector changes exactly three bytes:

```text
0x13138: 04 -> 10
0x13139: 41 -> 00
0x13169: 20 -> e0
```

## Hardware validation

The board was first programmed with the bootcmd-only sector and then with the
selective HTTP-bypass sector. Each operation:

- copied the live protected 128 KiB sector into RAM;
- constructed and CRC-verified the target in a second RAM buffer;
- unprotected exactly one sector;
- erased exactly one sector;
- programmed exactly 131,072 bytes;
- compared all 131,072 bytes;
- verified CRC32 and instruction bytes;
- restored sector protection.

Final readback:

```text
CRC32 for bdc00000 ... bdc1ffff ==> b77a94de
bdc13138: 10 00 00 03
bdc13168: 03 e0 00 08
```

Runtime validation established:

- `bootcmd=version` survived `saveenv` and reset;
- with the button released, the firmware checker printed its invalid-header
  diagnostics but did not launch Sercomm HTTP mode;
- the saved OpenWrt command loaded the ELF and Linux booted normally;
- with the button held, `PUSH_BUTTON--> 0` entered Sercomm download mode;
- the final environment uses `bootdelay=3`, no `preboot`, and
  `bootcmd=run openwrt_boot`.

## Distribution flasher status

The integrated combined flasher recognizes stock, bootcmd-only, HTTP-only and
combined identities. On the validated board it recognized `b77a94de` and exited
without a write:

```text
Recognized live sector identity: combined
Flash already matches target combined; no write performed
Operation complete; destructive_started=False
```

This validates live-state detection and idempotence. The combined target and the
underlying destructive primitives are hardware validated, but one single
combined-tool destructive transition from a completely stock sector has not
been directly exercised.

## Final environment example

```text
bootdelay=3
bootcmd=run openwrt_boot
openwrt_boot=cp.b 0xbdc80000 0x05500000 0x11565d0; bootoctlinux 0x05500000 console=ttyS0,115200
```

The copy length is specific to that ELF and must be updated when the persistent
image changes.
