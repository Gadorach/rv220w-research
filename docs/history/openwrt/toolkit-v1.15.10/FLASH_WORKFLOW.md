# RV220W guarded NOR workflow

## v1.13.2 sysupgrade-image workflow

1. Upgrade the toolkit to v1.13.2 and source platform v1.7.2.
2. Rebuild only `persistent`; the writer layout is unchanged from v1.12.0.
3. Require the staged sysupgrade tar, JSON report, gzip kernel, SquashFS root
   and all checksum sidecars to pass `./rv220w.fish verify`.
4. Inspect the archive and run `sysupgrade -T` only from a v1.13.2 persistent
   runtime.
5. Bootstrap v1.13.2 components through the guarded writer before the first
   normal sysupgrade; the v1.12.0 SquashFS lacks the new platform script.
6. Retain UART, TFTP, full NOR backups and the RAM writer for the first real
   sysupgrade hardware qualification.

The stage2 writer erases the complete rootfs, integrates the configuration
backup with `mtd -j` when requested, verifies rootfs, then writes and verifies
the gzip kernel. It does not write the boot chain or U-Boot environment.


The RV220W uses a 32 MiB x16 parallel CFI NOR. It does not contain NAND.

## Default policy

Every normal/reference/discovery/DSA/full-RJ45/LuCI target keeps the complete
NOR map read-only. Only the explicit TFTP/RAM-boot `nor-writer` target exposes a
writable partition, and that partition is limited to the combined 22 MiB stock
kernel/rootfs region named `openwrt-slot`.

Protected in the writer profile:

```text
boot-chain
stock-data
legacy-env-gap
vendor-tail
uboot-env
```

The writer does not modify U-Boot, the environment, boot command, reset
configuration, or vendor data.

## Build

```fish
./rv220w.fish build rj45-luci
./rv220w.fish build nor-writer
```

The LuCI build produces the exact-size slot image and JSON manifest. The slot
builder requires an ELF64 big-endian MIPS executable, rejects anything larger
than 22 MiB, and pads the remaining bytes with `0xff`.

## RAM-boot the writer

```fish
./rv220w.fish tftp-boot \
    --profile nor-writer \
    --interface enp0s31f6 \
    --configure-interface
```

Set a temporary root password from UART before using SSH/SCP:

```sh
passwd
```

## Inspect and back up

```fish
./rv220w.fish nor-stage status
./rv220w.fish nor-stage backup
```

Backups are written under:

```text
$RV220W_WORKSPACE/backups/nor/
```

Each backup is exactly 23,068,672 bytes and receives a companion SHA-256 file.

## Write and verify

```fish
./rv220w.fish nor-stage write \
    --confirm RV220W_WRITE_OPENWRT_SLOT
```

The host validates the slot manifest, verifies the local image, checks the
writer profile, creates a mandatory backup, uploads the image, and invokes the
target helper. The target checks board/model/profile/MTD geometry, requires the
exact confirmation token, validates ELF magic and SHA-256, writes only
`openwrt-slot`, and hashes the entire partition after the write.

No reboot is performed.

## Manual first boot from NOR

The staged file is a Linux ELF, not an Octeon Executive application. Direct
`bootoct` execution from memory-mapped NOR attempts an in-place application/TLB
mapping and fails. Reproduce the proven TFTP launch path instead: copy the exact
ELF bytes from NOR into the validated RAM staging address, then invoke
`bootoctlinux`.

Generate the commands from the local manifest:

```fish
./rv220w.fish nor-stage boot-plan
```

For the validated v1.10.0 LuCI image (`source_size=18179536`, hex `0x11565d0`):

```text
cp.b 0xbdc80000 0x05500000 0x11565d0
bootoctlinux 0x05500000 console=ttyS0,115200
```

The source range ends at `0xbedd65cf`; the RAM copy ends at `0x066565cf`, below
the validated staging limit. Enter the commands separately during the first
test. Do not run `saveenv`.

The staged firmware is an initramfs image, so settings remain volatile even
though the image itself is in NOR.

## Restore the preserved slot backup

RAM-boot the same `nor-writer` image, set a temporary password, then restore an
exact 22 MiB backup only to `openwrt-slot`:

```fish
./rv220w.fish nor-stage restore \
    --image ~/src/rv220w-openwrt/backups/nor/rv220w-openwrt-slot-backup-<timestamp>.bin \
    --confirm RV220W_RESTORE_OPENWRT_SLOT
```

The restore action creates a fresh backup of the current slot before writing,
verifies the local size and SHA-256, and checks the complete NOR read-back. It
does not reboot or modify U-Boot state.

## Stop conditions

Stop and retain power/TFTP recovery access if any of these occur:

- target reports anything other than `profile=nor-writer`;
- `openwrt-slot` is absent or is not exactly 22 MiB with 128 KiB erase blocks;
- local or remote SHA-256 differs;
- the automatic backup is not exactly 22 MiB;
- MTD output exposes any protected region as writable;
- read-back verification fails.

## v1.12.0 full-NOR persistent workflow

The legacy `nor-writer` path above remains a recovery mechanism for the saved
22 MiB monolithic slot. Current persistent promotion uses two writable
components:

```text
openwrt-kernel   6 MiB
rootfs           25.375 MiB
```

Only `boot-chain` and the final `uboot-env` partition remain protected outside
that OpenWrt region. `rootfs_data` is not declared explicitly; OpenWrt derives
one JFFS2 child from the erase-aligned end of SquashFS.

Build both changed profiles:

```fish
./rv220w.fish build persistent
./rv220w.fish build persistent-writer
./rv220w.fish verify
```

RAM-boot the v1.12.0 writer, set a temporary password, then require its status
and full-region backup:

```fish
./rv220w.fish tftp-boot \
    --profile persistent-writer \
    --interface enp0s31f6 \
    --configure-interface

./rv220w.fish persistent-stage status
./rv220w.fish persistent-stage backup
```

The rootfs backup must be exactly 26,607,616 bytes. Write the full rootfs only
with the new token:

```fish
./rv220w.fish persistent-stage write-rootfs \
    --confirm RV220W_WRITE_FULL_OPENWRT_ROOTFS
```

This resets the current overlay and reclaims the old Cisco data/tail. There is
no separate `erase-overlay` action.

TFTP-boot the rebuilt persistent kernel and validate:

- `/proc/mtd` has one `rootfs_data` child;
- `/rom` is read-only SquashFS;
- `/overlay` is writable JFFS2;
- expected overlay capacity is about 21.4 MiB with the current SquashFS;
- a hostname and marker survive another reboot and TFTP kernel load.

Stop for review before writing the kernel. After that gate, the guarded command
is still:

```fish
./rv220w.fish persistent-stage write-kernel \
    --confirm RV220W_WRITE_PERSISTENT_KERNEL
./rv220w.fish persistent-stage boot-plan
```

### Persistent stop conditions

Stop without resetting the RAM writer if:

- target status is not the v1.12.0 `persistent-writer` policy;
- rootfs is not exactly 25.375 MiB or erase size is not 128 KiB;
- boot-chain or uboot-env geometry differs;
- the mandatory full-region backup is incomplete;
- local, transfer or complete NOR readback SHA-256 differs;
- any MTD filesystem is mounted in the writer session;
- the TFTP kernel exposes duplicate `rootfs_data` partitions;
- SquashFS, JFFS2 initialization or persistence fails.

No persistent-stage operation changes U-Boot variables or reboots automatically.
