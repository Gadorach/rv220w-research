# Bootloader, RAM boot, and persistent launch

## U-Boot baseline

The board uses U-Boot 1.1.1 with 32 MiB of parallel NOR at `0xbdc00000` and a
validated RAM staging address of `0x05500000`. Ctrl+C during startup reaches the
`rv200w#` prompt.

## TFTP/RAM boot

The toolkit can interrupt U-Boot, set temporary networking variables, TFTP an
ELF to RAM, and invoke `bootoctlinux`. This remains the recovery and validation
path and does not save the environment or write NOR.

## Persistent launch

The LuCI ELF is stored at `0xbdc80000`, but direct `bootoct` from mapped NOR is
invalid for this Linux ELF. The working path is:

```text
cp.b 0xbdc80000 0x05500000 <manifest source_size in hex>
bootoctlinux 0x05500000 console=ttyS0,115200
```

After the combined boot-policy patch and a successful manual test, save:

```text
setenv preboot
setenv bootdelay 3
setenv openwrt_boot 'cp.b 0xbdc80000 0x05500000 <source_size_hex>; bootoctlinux 0x05500000 console=ttyS0,115200'
setenv bootcmd 'run openwrt_boot'
saveenv
```

The validated LuCI image used `<source_size_hex>` = `0x11565d0`. Never reuse
that value for a different ELF without generating a new boot plan from its
manifest.
