# Generic U-Boot 1.1.1 comparison

The user-supplied generic U-Boot 1.1.1 source archive has SHA-256:

```text
ef242017cea9ce2b5a4419472b39b88c73843ad4cd6c1a3d4ad015437a34f78f
```

It is useful as a semantic map for standard U-Boot behavior:

- `common/env_common.c` — compiled defaults and `env_relocate()`;
- `common/env_flash.c` — CRC generation, erase and `saveenv()`;
- `common/main.c` — `main_loop()` and later consumption of `bootcmd`;
- `common/cmd_elf.c` — `bootelf`, ELF loading and entry invocation.

The generic source confirms that:

- bad-CRC fallback selects compiled defaults;
- a successful `saveenv` writes the current environment and CRC;
- normal `main_loop` reads `bootcmd` after board initialization;
- generic code does not selectively replace only `bootcmd` after importing an otherwise valid environment.

The source tree contains no CN5010/RV220W board port, Cavium Octeon startup, `bootoctlinux`, PIP/PKO Ethernet, BootBus configuration or Sercomm recovery policy. Consequently, it cannot be compiled directly into a cold-start RV220W bootloader.

`evidence/generic-uboot111-comparison.json` records the relevant source files, hashes, line matches and absence of vendor tokens.
