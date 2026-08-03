# RV220W focused flash tools

## Combined boot-policy patch flasher

`rv220w-combined-boot-policy-patch-flasher-v1.0.0` is the distribution path for
applying both validated policy changes in one target sector:

- preserve the saved `bootcmd`;
- tolerate non-Sercomm firmware while retaining physical-button recovery.

Use dry-run first, then `--stage-only`. Destructive operation requires
`--execute`, explicit external-recovery acknowledgement and the exact token.

Validation scope is recorded in the top-level hardware-validation document.
