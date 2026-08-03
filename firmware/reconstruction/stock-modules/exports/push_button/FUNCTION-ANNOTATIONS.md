# push_button.ko — per-function annotations

> All C is Ghidra reconstruction, not original Cisco source. Confidence is deliberately conservative.

## `gpio_config_input_sense` @ `0x00100050`

- **Subsystem:** led-gpio
- **Evidence:** retained or recovered ELF/source symbol
- **Confidence:** high for identity; medium for detailed semantics
- **Interpretation:** Configures an Octeon GPIO line as an input with sensing/interrupt behavior.
- **Decompiler:** success; reconstructed C SHA-256 `09feb96771c5f03a2d340f3ccb1a73dbbb2dccb8a95d5aa7ad251ad57dde6dbb`
- **Artifacts:** `decompiled/00100050_gpio_config_input_sense.c`, `assembly/00100050_gpio_config_input_sense.asm`
- **Recognized calls:** none; relocatable MIPS/GOT indirection may hide additional edges

## `set_input` @ `0x00100080`

- **Subsystem:** module-support
- **Evidence:** retained or recovered ELF/source symbol
- **Confidence:** high for identity; medium for detailed semantics
- **Interpretation:** Reset-button helper that updates input/proc state and wakeup/timer behavior.
- **Decompiler:** success; reconstructed C SHA-256 `5b5e6999ba97f11510660704a683ce88add4780b586084e12ba2f7a3b65ad4db`
- **Artifacts:** `decompiled/00100080_set_input.c`, `assembly/00100080_set_input.asm`
- **Recognized calls:** `gpio_config_input_sense` ×1

## `local_push_button_proc_write_or_ack` @ `0x001000e0`

- **Subsystem:** reset-button
- **Evidence:** function boundary recovered from MIPS .pdr relocation
- **Confidence:** high for boundary; low-to-medium for inferred role
- **Interpretation:** Stock /proc push-button control/acknowledgement handler; semaphore-protected state update rather than the read-to-userspace path.
- **Decompiler:** success; reconstructed C SHA-256 `a46d0f6f983d0e311281229d52b2ffd1eb51e9b93e679faf51d886d8d06f3aba`
- **Artifacts:** `decompiled/001000e0_local_push_button_proc_write_or_ack.c`, `assembly/001000e0_local_push_button_proc_write_or_ack.asm`
- **Recognized calls:** `__up` ×1

## `local_push_button_proc_read` @ `0x00100198`

- **Subsystem:** reset-button
- **Evidence:** function boundary recovered from MIPS .pdr relocation
- **Confidence:** high for boundary; low-to-medium for inferred role
- **Interpretation:** Stock /proc push-button read handler; copies the current button state to userspace and advances the file position.
- **Decompiler:** success; reconstructed C SHA-256 `9d8e9a2337d85e38da036086a1390a45778351542b2c452ca61d7ba240097d0e`
- **Artifacts:** `decompiled/00100198_local_push_button_proc_read.c`, `assembly/00100198_local_push_button_proc_read.asm`
- **Recognized calls:** `__copy_user` ×1, `__down_interruptible` ×1, `__mod_timer` ×1, `strlen` ×1

## `local_push_button_timer_callback` @ `0x00100408`

- **Subsystem:** reset-button
- **Evidence:** function boundary recovered from MIPS .pdr relocation
- **Confidence:** high for boundary; low-to-medium for inferred role
- **Interpretation:** Polling/debounce timer callback for the reset button; decompilation contains press-duration and LED-feedback behavior.
- **Decompiler:** success; reconstructed C SHA-256 `8adc6caa13230df7f1233b5e6ec92134079b0229cb762a902ad46b4e74647bc9`
- **Artifacts:** `decompiled/00100408_local_push_button_timer_callback.c`, `assembly/00100408_local_push_button_timer_callback.asm`
- **Recognized calls:** `led_blink` ×1, `strcpy` ×1

## `cleanup_module` @ `0x00100770`

- **Subsystem:** module-lifecycle
- **Evidence:** retained or recovered ELF/source symbol
- **Confidence:** high for identity; medium for detailed semantics
- **Interpretation:** Module teardown path; reverses registrations and frees runtime resources.
- **Decompiler:** success; reconstructed C SHA-256 `64ed0cbc9675f46db527569cad2f995c90c2b3b8a6fa58d28295aae9f917c03c`
- **Artifacts:** `decompiled/00100770_cleanup_module.c`, `assembly/00100770_cleanup_module.asm`
- **Recognized calls:** `del_timer` ×1, `remove_proc_entry` ×1, `unregister_sysctl_table` ×1

## `init_module` @ `0x00100880`

- **Subsystem:** module-lifecycle
- **Evidence:** retained or recovered ELF/source symbol
- **Confidence:** high for identity; medium for detailed semantics
- **Interpretation:** Registers the RV220W push-button GPIO input, timers, wait state and proc/sysctl interface; imports led_blink for visual feedback.
- **Decompiler:** success; reconstructed C SHA-256 `5f4084862b4fc16bb4b291e1a06cad1a611e9531b0020caa6c49fdfd55d1a0bc`
- **Artifacts:** `decompiled/00100880_init_module.c`, `assembly/00100880_init_module.asm`
- **Recognized calls:** `create_proc_entry` ×1, `init_timer` ×1, `init_waitqueue_head` ×1, `printk` ×1, `register_sysctl_table` ×1, `set_input` ×1
