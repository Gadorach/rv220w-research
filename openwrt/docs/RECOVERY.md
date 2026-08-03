# Recovery

Use TFTP RAM boot for normal recovery. RAM-boot `nor-writer` to restore a
verified 22 MiB slot backup. The combined boot-policy patch retains physical
Sercomm download mode. External parallel-NOR programming remains the final
recovery path.

See [`../../docs/operations/risk-and-recovery.md`](../../docs/operations/risk-and-recovery.md).
