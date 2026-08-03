# RV220W reconstruction results — v1.4.0-r1

## Hardware-validated persistent boot policy

Two byte-exact changes in NOR sector 0 are now validated on the physical RV220W:

```text
0x13138  04 41 00 03 -> 10 00 00 03
0x13168  03 20 00 08 -> 03 e0 00 08
```

The combined sector has CRC32 `b77a94de`. The first change converts the
post-firmware-check `bgez` into an unconditional branch to the existing success
path, skipping only `do_http`. The earlier active-low GPIO branch and
`do_download` call are untouched. The second change returns from the vendor
late-init routine after its epilogue instead of tail-calling the environment
setter with the compiled stock `bootcmd`.

Hardware observations establish that:

- the patched sector survives reset and reads back exactly;
- `bootcmd=version` persisted across `saveenv` and reset;
- with the button released, the invalid proprietary header is printed but HTTP
  recovery is not launched;
- the saved OpenWrt command runs and Linux boots from the NOR image;
- with the button held, `PUSH_BUTTON--> 0` still enters Sercomm download mode;
- the final environment uses a three-second boot delay and no duplicate
  `preboot` launch.

## Integrated combined flasher

`bootloader-poc/flash-tools/rv220w-combined-boot-policy-patch-flasher-v1.0.0`
accepts stock, bootcmd-only, HTTP-only and already-combined known identities. It
constructs the requested target from the live protected sector in RAM and
writes only `0xbdc00000-0xbdc1ffff` after verification.

The tool was run on the validated combined state and correctly reported:

```text
Live sector CRC32=b77a94de; branch=10000003; bootcmd=03e00008
Recognized live sector identity: combined
Flash already matches target combined; no write performed
Operation complete; destructive_started=False
```

The exact target bytes and the underlying sector write procedure were exercised
through the sequential bootcmd and selective-HTTP tools. The combined wrapper's
one-step destructive transition directly from stock remains unexercised.

## D-Link donor evidence retained

The eleven-package multiversion scan found no complete U-Boot source tree or
`bootoctlinux` source. It did recover matching SDK lineage, private board IDs,
three-port RGMII topology, descriptor-v6/bootinfo v1.2 ABI, and the vendor ELF
restriction against non-empty `PT_NOTE` headers.

## RAM stage2 status

The v1.4 stage2 artifact remains 93,096 bytes, entry
`0xffffffff84000000`, SHA-256
`1369e9c240aedd33e624498a8932b076074e105a45785f19e8e658ceb9caed1a`.
Host regressions pass, but this separate RAM monitor has not been executed on
the board.
