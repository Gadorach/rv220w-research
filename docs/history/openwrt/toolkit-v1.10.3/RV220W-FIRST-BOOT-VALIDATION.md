# First RV220W-specific RAM boot validation

## v1.9.3 FDT verification API hotfix

See `RV220W-V1.9.3-FDT-VERIFY-API-HOTFIX.md`. Patch 999 now calls the Linux 6.12 two-argument `early_init_dt_verify()` API with the flat-tree virtual address and `__pa()` physical address. The v1.9.2 stable patch context and all production DTS, NOR, firewall and RJ45 behavior remain unchanged.


## v1.9.2 patch-999 context hotfix

See `RV220W-V1.9.2-PATCH999-CONTEXT-HOTFIX.md`. This release changes only the textual context used to apply patch 999 after OpenWrt patch 400; the v1.9.1 production DTS, NOR/FDT cleanup semantics, firewall policy and full-RJ45 topology are unchanged.


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

Expected hashes:

```text
0630714e3e86edfeeed064088266c59524d970e0b74780e903b68b45e8982e7d  boot-chain
a4aadfe8aff6d44157672efd5c52c3f1d403195da90adedbea26d9b44499a8b4  stock-kernel
e1360881a07134108d00f2b5aec1baf1507698513be8c63f232d4b8377a2de88  stock-rootfs
```

Do not run `mtd`, `flash_erase`, `dd of=/dev/mtd*`, `saveenv`, or sysupgrade.


## v1.9.1 production cleanup

See `RV220W-V1.9.1-PRODUCTION-CLEANUP.md`. The full-RJ45 production profile uses fixed internal MAC links, explicit Octeon BootBus flash ownership, refreshed post-fixup FDT verification, no out-of-tree MDIO module, strict default WAN isolation, and standard read-only status collection.
