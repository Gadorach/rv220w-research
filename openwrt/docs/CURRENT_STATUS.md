# Current status

The integrated v1.10.3 toolkit builds the hardware-proven LuCI and dedicated
NOR-writer profiles. The slot writer completed a verified 22 MiB write on the
RV220W. The separate combined boot-policy patch and saved environment now boot
the LuCI ELF automatically by copying its exact byte count to RAM and invoking
`bootoctlinux`.

The persistent image is initramfs, so configuration remains volatile. Wi-Fi,
persistent overlay, and sysupgrade remain unsupported.
