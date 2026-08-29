# Run15: verified NOR write and incorrect direct-flash loader

The v1.10.2 host transport completed the first full write of the 22 MiB
`openwrt-slot`. Target-side read-back matched:

```text
51340539fff729869bab36181662e36648768663c9774e5f98646d4283bc86a5
```

The mandatory pre-write stock slot backup was 23,068,672 bytes and matched:

```text
47b546d826e9016d3fa0a8e08356e1ba614cba7290d11eba79a6bd80e0671c6d
```

The proposed `bootoct 0xbdc80000 forceboot` command failed before Linux. The
loader treated the flash-resident Linux ELF as an in-place Octeon Executive
application and failed a read-only TLB mapping. This is a loader-selection
error, not evidence of a corrupt write.

The corrected path copies the exact ELF bytes from `0xbdc80000` to the proven
RAM staging address `0x05500000`, then runs `bootoctlinux`.
