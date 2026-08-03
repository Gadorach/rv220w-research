# Persistent OpenWrt installation

This procedure is destructive. A complete verified NOR image and external
parallel-flash recovery must be available.

## Required order

The boot-chain patch is a prerequisite. Do not reverse the first two promotion
stages.

### 1. Preserve and verify recovery material

Keep the canonical 32 MiB image and hashes, a current 22 MiB `openwrt-slot`
backup, JP1 UART access, and an external NOR recovery method.

### 2. Patch the boot policy first

Follow [`../firmware/bootchain-policy-patch.md`](../firmware/bootchain-policy-patch.md).
Verify:

```text
crc32 0xbdc00000 0x20000 -> b77a94de
md.b 0xbdc13138 4         -> 10 00 00 03
md.b 0xbdc13168 4         -> 03 e0 00 08
```

Confirm that holding the physical recovery button still enters Sercomm download
mode before proceeding.

### 3. Build the LuCI payload and writer

```fish
cd openwrt
cp config/toolkit.env.fish.example config/toolkit.env.fish
./rv220w.fish doctor
./rv220w.fish setup-host
./rv220w.fish setup-box
./rv220w.fish prepare-sources
./rv220w.fish build rj45-luci
./rv220w.fish build nor-writer
```

The LuCI build produces an ELF, a 22 MiB `0xff`-padded slot image, and a JSON
manifest containing the exact ELF `source_size` and boot commands.

### 4. RAM-boot the dedicated writer

```fish
./rv220w.fish tftp-boot \
    --profile nor-writer \
    --interface <host-interface> \
    --configure-interface
```

Set a temporary root password over UART, then verify the writer identity:

```fish
./rv220w.fish nor-stage status
```

It must report only `openwrt-slot` writable, with size 23,068,672 bytes and
128 KiB erase blocks.

### 5. Back up and write the slot

```fish
./rv220w.fish nor-stage backup
./rv220w.fish nor-stage write --confirm RV220W_WRITE_OPENWRT_SLOT
```

The write path validates the local manifest and ELF, creates a mandatory full
slot backup, writes only `openwrt-slot`, and verifies the complete read-back
SHA-256. It does not reboot or save the U-Boot environment.

### 6. Test the flash-resident ELF manually

Generate the exact commands for the current image:

```fish
./rv220w.fish nor-stage boot-plan
```

At U-Boot, run the printed `cp.b` and `bootoctlinux` commands separately. The
validated 18,179,536-byte image used:

```text
cp.b 0xbdc80000 0x05500000 0x11565d0
bootoctlinux 0x05500000 console=ttyS0,115200
```

Do not save the environment until this manual boot reaches the expected LuCI
system.

### 7. Save automatic boot policy

Return to U-Boot and use the current manifest-derived copy length:

```text
setenv preboot
setenv bootdelay 3
setenv openwrt_boot 'cp.b 0xbdc80000 0x05500000 <source_size_hex>; bootoctlinux 0x05500000 console=ttyS0,115200'
setenv bootcmd 'run openwrt_boot'
saveenv
reset
```

Verify automatic OpenWrt boot, all five RJ45 ports, LuCI, and the three-second
interrupt window.

## Updating the image

For every new ELF:

1. RAM-boot the writer.
2. create a fresh slot backup;
3. write and verify the new slot artifact;
4. generate a new boot plan;
5. manually test it;
6. update `openwrt_boot` with the new source length and save the environment.

A stale copy length can truncate the ELF or copy unnecessary data and must not
be reused.
