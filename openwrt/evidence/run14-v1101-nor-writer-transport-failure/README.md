# Run14: v1.10.1 NOR-writer boot and host-transfer failure

The dedicated writer built and TFTP/RAM-booted. The kernel exposed the intended six-partition map with only the 22 MiB `openwrt-slot` writable. `nor-stage status` passed and two complete slot backups were saved. The uploaded backup copies are exactly 23,068,672 bytes, byte-identical, and hash to:

```text
47b546d826e9016d3fa0a8e08356e1ba614cba7290d11eba79a6bd80e0671c6d
```

The first write attempt stopped while modern `scp` attempted SFTP:

```text
ash: /usr/libexec/sftp-server: not found
scp: Connection closed
```

The target writer was not invoked. No NOR erase or write occurred. v1.10.2 fixes only the host transfer and transient host-key handling. Large backup binaries are intentionally not duplicated in the repository.
