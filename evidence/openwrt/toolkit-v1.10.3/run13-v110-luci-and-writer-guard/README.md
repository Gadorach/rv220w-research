# v1.10.0 LuCI success and NOR-writer guard failure

The LuCI profile built successfully, generated an 18,179,536-byte ELF and exact
22 MiB padded slot artifact, and TFTP/RAM-booted on hardware. The operator
reported LuCI working normally.

The separate NOR-writer build stopped immediately after `defconfig` because the
v1.10.0 helper incorrectly required `CONFIG_PACKAGE_luci-light=y`. The preserved
expanded config shows that the writer correctly selected the flash-stage target,
retained `mtd`, and intentionally excluded LuCI/uHTTPd. v1.10.1 fixes only this
post-defconfig guard.

No NOR write was attempted in this evidence set.
