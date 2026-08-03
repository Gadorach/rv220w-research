# First RV220W-specific RAM boot validation

At the serial shell, collect:

```sh
uname -a
ubus call system board
printf 'model: '; tr -d '\0' </sys/firmware/devicetree/base/model; echo
printf 'compatible:\n'; tr '\0' '\n' </sys/firmware/devicetree/base/compatible
cat /proc/cmdline
cat /proc/mtd
ip -o link show
ip -o addr show
ip route show
cat /proc/net/dev
lspci -nn 2>/dev/null
dmesg
```

Expected changes from the generic image:

- Model and board name report Cisco RV220W / `cisco,rv220w`.
- No `UBNT board DTS pruning...` message.
- No `octeon_usb_probe()` stall.
- Seven read-only command-line partitions cover the complete 32 MiB NOR.
- `eth0` remains the working LAN/switch path and `eth1` remains configured as the WAN candidate.
- The disabled switch and reset nodes are visible in the live tree but no B53 or gpio-keys driver claims them.

Verify the preserved immutable regions read identically, without writing:

```sh
dd if=/dev/mtd0ro bs=131072 count=4 2>/dev/null | sha256sum
dd if=/dev/mtd1ro bs=131072 count=48 2>/dev/null | sha256sum
dd if=/dev/mtd2ro bs=131072 count=128 2>/dev/null | sha256sum
```

Expected boot-chain hash depends on policy state:

```text
0630714e3e86edfeeed064088266c59524d970e0b74780e903b68b45e8982e7d  stock boot-chain
df830b85dffa1de0eab2e85d754fc451fbd344c0cfc248e4d0f29df7f12c9186  validated combined boot-chain
a4aadfe8aff6d44157672efd5c52c3f1d403195da90adedbea26d9b44499a8b4  stock-kernel
e1360881a07134108d00f2b5aec1baf1507698513be8c63f232d4b8377a2de88  stock-rootfs
```

Do not write MTD from Linux during validation. The validated boot-policy
changes are applied only through the focused U-Boot sector flasher documented
under `bootloader-poc/flash-tools`.
