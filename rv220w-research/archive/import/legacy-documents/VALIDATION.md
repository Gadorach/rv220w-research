# Toolkit validation status

Validated in the artifact-generation environment:

- all Python helpers compile with `python3 -m py_compile`;
- the UART dumper's dry-run produces the expected 32 MiB / 460800-baud read-only plan;
- the flash extractor accepts the independently verified RV220W dump, reproduces CRC32 `ce96f3e0` and SHA-256 `03a21d769306feaf3d09ed41749786b5e24caa9c6feb62e6fdf1230e5d324cc5`, splits the flash map, and extracts the expected big-endian JFFS2 files;
- the TFTP helper dry-run recognizes the recovered stock kernel as ELF64 big-endian MIPS, selects an interface/server/device address plan, and calculates the RAM boot address;
- every generated Bash inner-build script passes `bash -n`;
- the existing UART dumper v0.8.1 already completed two byte-identical hardware acquisitions with target/host CRC validation.

Not yet hardware-validated:

- the generated OpenWrt generic initramfs on the RV220W;
- the RAM-only SquashFS launcher on the RV220W;
- which physical jack and `octeth` value provide U-Boot TFTP access after the bootloader reports `disable 53115`;
- the future RV220W-specific DTS and B53/BCM53115 configuration.

Run `./rv220w.fish doctor` on CachyOS before provisioning and keep the first build and boot logs intact.
