# RV220W stock Broadcom `wl.ko` SROM/OTP path

## Evidence source

This note is derived from the preserved RV220W Broadcom `wl.ko` supplied in the stock firmware archive:

```text
size:     5222416 bytes
sha256:   59097fc90ef2af55ce22000c7cd4ee0567bebae8ea6243963539008c6307ad0d
version:  Broadcom 5.60.120.9
vermagic: 2.6.21.7-Cavium-Octeon mod_unload OCTEON 64BIT
```

The binary is unstripped enough to retain the relevant symbol names, including `srom_read`, `srom_var_init`, `si_is_sprom_available`, `otp_read_region`, `otp_init`, `otp_status`, `otp_size` and `hndcrc8`.

## Reconstructed decision path

The stock module has a distinct OTP-backed SROM path rather than treating the PCI SPROM shadow as the only source.

In `srom_var_init()`:

1. the code calls `si_is_sprom_available()` at `.text+0x8688`;
2. the false branch at `0x86a8` reaches `.text+0x89dc`;
3. that branch calls the internal helper at `.text+0x7d18`;
4. after a successful return, the SROM revision is read from byte offset `0x1b7`, i.e. the final high-level revision/CRC word of a 440-byte rev4+ image.

The helper at `.text+0x7d18` behaves like Broadcom's OTP-to-SROM reader:

- initializes a maximum length of `0x180` words (384 words);
- allocates `0x300` bytes;
- calls `otp_read_region(..., 1, ...)`, where region `1` is the hardware OTP region;
- copies the returned hardware-region words to the destination SROM buffer;
- rejects an initial `0xffff` word;
- byte-swaps the words for CRC processing;
- runs `hndcrc8` across exactly `0x1b8` bytes with initial value `0xff`;
- requires the Broadcom full-image residue `0x9f`;
- restores word byte order before returning.

The important consequence for the RV220W is that the invalid/mostly-erased PCI SPROM shadow observed by modern Linux does **not** prove the stock driver lacked valid board data. The proprietary driver explicitly knows how to source a complete SROM image from the chip's OTP hardware region when an external SPROM is not considered available.

## Why v1.14.8 does not copy the stock implementation

The v1.14.8 OpenWrt work does not transplant Broadcom code. It uses the public SSB/ChipCommon register definitions and implements only a read-only evidence interface in the existing Linux SSB PCI driver.

The diagnostic kernel patch:

- performs no OTP programming;
- deliberately does not issue the Broadcom OTP `INIT` command;
- performs no PCI configuration writes;
- performs no SPROM writes;
- performs no radio initialization;
- exposes the physical SPROM shadow separately from fallback data;
- exposes IPX OTP geometry/status and raw `sromotp[]` words when the PCI BAR layout can be validated safely.

Because no OTP `INIT` command is issued, `ssb_otp_info` explicitly reports `status_fresh=0`. The raw shadow remains useful evidence; userspace must validate the geometry-defined SROM candidate rather than trusting status bits alone.

## Portable boundary

The kernel diagnostic is intentionally not keyed to the RV220W or BCM4322 PCI IDs. It requires:

- an SSB PCI device;
- a BAR0 of at least 16 KiB;
- the fixed 12 KiB ChipCommon window to identify as Broadcom ChipCommon;
- a supported IPX OTP geometry.

Older HND-OTP or different BAR layouts fail with an unsupported/error result instead of being guessed.

## Host integrity gate

`scripts/analyze-ssb-nvmem.py` reconstructs the candidate only at the geometry-defined `hwbase = otpgu_base + 4` location and requires all of the following before it will serialize an OpenWrt fallback blob:

1. complete 220-word / 440-byte candidate;
2. first word not erased (`0xffff`);
3. supported SROM revision (4, 5 or 8);
4. Linux-style stored CRC matches;
5. Broadcom `hndcrc8` full-image residue is `0x9f`.

The analyzer may report CRC-valid 220-word windows elsewhere in OTP for diagnosis, but those scan hits are never eligible for automatic fallback emission.

A CRC-valid candidate proves integrity of the recovered image, **not** RF/regulatory suitability. RF remains blocked until board-specific calibration and identity are independently reviewed.
