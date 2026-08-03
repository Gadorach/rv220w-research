# Flash layout

See [`../../docs/openwrt/flash-layout-and-images.md`](../../docs/openwrt/flash-layout-and-images.md).

Only the explicit RAM-boot `nor-writer` profile exposes the 22 MiB
`openwrt-slot` as writable. Boot chain, stock data, vendor tail, and U-Boot
environment remain protected from Linux writes.
