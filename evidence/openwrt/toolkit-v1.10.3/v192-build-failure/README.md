# v1.9.2 build failure evidence

The v1.9.2 patch applied successfully and compilation reached
`arch/mips/cavium-octeon/setup.c`, but failed because toolkit v1.9.2 called
`early_init_dt_verify(initial_boot_params)` with one argument while the pinned
Linux 6.12.94 tree declares:

```c
bool early_init_dt_verify(void *dt_virt, phys_addr_t dt_phys);
```

v1.9.3 changes the call to:

```c
early_init_dt_verify(initial_boot_params, __pa(initial_boot_params))
```

Files:

- `rv220w-rj45-rxid-build.log`: complete normal/serial retry build output.
- `rv220w-rj45-rxid-build-serial.log`: focused serial build output.
- `rv220w-rj45-rxid-build-error-tail.txt`: operator-pasted final failure excerpt.
- `failure-summary.txt`: concise diagnosis.

These logs are build evidence only. No router or flash operation was involved.
