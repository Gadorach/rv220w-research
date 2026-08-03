# Risk and recovery

## Recovery requirements

Persistent promotion requires all of the following before any destructive step:

- canonical 32 MiB NOR image with verified hashes;
- JP1 serial access and a proven U-Boot interruption path;
- external parallel-NOR recovery capability;
- preserved first 512 KiB boot chain and final environment sector;
- a current 22 MiB slot backup before every slot write.

## Recovery paths

1. **TFTP RAM boot:** interrupt U-Boot and launch a known-good `nor-writer` or LuCI ELF.
2. **Slot restore:** RAM-boot `nor-writer` and restore a verified exact 22 MiB backup with `RV220W_RESTORE_OPENWRT_SLOT`.
3. **Physical recovery button:** the combined boot-policy patch preserves active-low Sercomm download mode.
4. **Boot-sector restore:** the focused flasher can restore recognized stock or intermediate sector identities.
5. **External programming:** restore the complete NOR image when U-Boot cannot run.

## Stop conditions

Stop without resetting or saving the environment when:

- the live boot sector is not a recognized identity;
- staged sector CRC or instruction bytes differ;
- the writer profile exposes any protected MTD region as writable;
- the slot backup is not exactly 23,068,672 bytes;
- local, uploaded, or read-back SHA-256 differs;
- manual `cp.b` plus `bootoctlinux` does not boot the expected ELF;
- the physical recovery button no longer reaches Sercomm download mode.

## Image-specific environment

`openwrt_boot` contains the exact ELF byte count. Generate it from the current
manifest after every build. Saving a stale copy length is an avoidable boot
failure and must be treated as a failed promotion gate.
