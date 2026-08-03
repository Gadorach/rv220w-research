# scm-led.ko — per-function annotations

> All C is Ghidra reconstruction, not original Cisco source. Confidence is deliberately conservative.

## `gpio_config_output` @ `0x00100050`

- **Subsystem:** led-gpio
- **Evidence:** retained or recovered ELF/source symbol
- **Confidence:** high for identity; medium for detailed semantics
- **Interpretation:** Configures an Octeon GPIO line for output before LED control.
- **Decompiler:** success; reconstructed C SHA-256 `f1f14fca5e71923fd9dbb160dc6d9c0d7160052d712b26495d417025e24d4910`
- **Artifacts:** `decompiled/00100050_gpio_config_output.c`, `assembly/00100050_gpio_config_output.asm`
- **Recognized calls:** none; relocatable MIPS/GOT indirection may hide additional edges

## `led_off` @ `0x00100080`

- **Subsystem:** led-gpio
- **Evidence:** retained or recovered ELF/source symbol
- **Confidence:** high for identity; medium for detailed semantics
- **Interpretation:** Drives a selected board LED to its inactive state.
- **Decompiler:** success; reconstructed C SHA-256 `2a2b078b52549b13bc6835809326afbf16688645726c606fb1d4dc8f65a13d91`
- **Artifacts:** `decompiled/00100080_led_off.c`, `assembly/00100080_led_off.asm`
- **Recognized calls:** `gpio_config_output` ×1

## `led_on` @ `0x001000e0`

- **Subsystem:** led-gpio
- **Evidence:** retained or recovered ELF/source symbol
- **Confidence:** high for identity; medium for detailed semantics
- **Interpretation:** Drives a selected board LED to its active state; polarity and logical LED identifiers are encoded in callers/data tables.
- **Decompiler:** success; reconstructed C SHA-256 `ddbd26f2d02c4457c0c864d8b063aa260d3f61f8d00454f5339c9e3475fa7a03`
- **Artifacts:** `decompiled/001000e0_led_on.c`, `assembly/001000e0_led_on.asm`
- **Recognized calls:** `gpio_config_output` ×1

## `local_led_proc_read` @ `0x00100140`

- **Subsystem:** led-gpio
- **Evidence:** function boundary recovered from MIPS .pdr relocation
- **Confidence:** high for boundary; low-to-medium for inferred role
- **Interpretation:** Stock /proc LED read handler recovered from a function pointer and .pdr entry.
- **Decompiler:** success; reconstructed C SHA-256 `63bb685276d5830d50dd370073ec6f7e44ea18a420149b6f2de1455c9f0025a5`
- **Artifacts:** `decompiled/00100140_local_led_proc_read.c`, `assembly/00100140_local_led_proc_read.asm`
- **Recognized calls:** `__copy_user` ×1, `memset` ×1, `printk` ×1, `sprintf` ×1, `strlen` ×1

## `led_blink` @ `0x00100378`

- **Subsystem:** led-gpio
- **Evidence:** retained or recovered ELF/source symbol
- **Confidence:** high for identity; medium for detailed semantics
- **Interpretation:** Exported board LED blink API used by other stock modules, including reset-button feedback.
- **Decompiler:** success; reconstructed C SHA-256 `192b5d040e773439259e01d832e8be96d4e8add5ec56d3ab226e29c0868f7d9c`
- **Artifacts:** `decompiled/00100378_led_blink.c`, `assembly/00100378_led_blink.asm`
- **Recognized calls:** `__mod_timer` ×2

## `blink_wlan` @ `0x00100608`

- **Subsystem:** led-gpio
- **Evidence:** retained or recovered ELF/source symbol
- **Confidence:** high for identity; medium for detailed semantics
- **Interpretation:** WLAN-specific blink helper; likely services the front-panel WIRELESS indicator rather than switch PHY LEDs.
- **Decompiler:** success; reconstructed C SHA-256 `c87eca7303f25f8138fe9140c633bcd2c30cb77a24601302b959c3861090d9dc`
- **Artifacts:** `decompiled/00100608_blink_wlan.c`, `assembly/00100608_blink_wlan.asm`
- **Recognized calls:** `__mod_timer` ×1

## `local_led_proc_write` @ `0x00100638`

- **Subsystem:** led-gpio
- **Evidence:** function boundary recovered from MIPS .pdr relocation
- **Confidence:** high for boundary; low-to-medium for inferred role
- **Interpretation:** Stock /proc LED command parser/write handler; decompilation exposes accepted LED identifiers and actions.
- **Decompiler:** success; reconstructed C SHA-256 `7ce0f9288f83e4a749c0d52d5698040515fc66f2fd0a90f3a556b1acfdd9a8ce`
- **Artifacts:** `decompiled/00100638_local_led_proc_write.c`, `assembly/00100638_local_led_proc_write.asm`
- **Recognized calls:** `__copy_user` ×1, `__down_interruptible` ×1, `__up` ×1, `led_blink` ×1, `led_off` ×1, `led_on` ×1

## `gpio_config_input_sense` @ `0x00100d90`

- **Subsystem:** led-gpio
- **Evidence:** retained or recovered ELF/source symbol
- **Confidence:** high for identity; medium for detailed semantics
- **Interpretation:** Configures an Octeon GPIO line as an input with sensing/interrupt behavior.
- **Decompiler:** success; reconstructed C SHA-256 `b998e4a7e892769c75258b4f147a45f896030c138695cc4d2c99decd860bb437`
- **Artifacts:** `decompiled/00100d90_gpio_config_input_sense.c`, `assembly/00100d90_gpio_config_input_sense.asm`
- **Recognized calls:** none; relocatable MIPS/GOT indirection may hide additional edges

## `local_led_timer_callback` @ `0x00100dc0`

- **Subsystem:** led-gpio
- **Evidence:** function boundary recovered from MIPS .pdr relocation
- **Confidence:** high for boundary; low-to-medium for inferred role
- **Interpretation:** Timer callback that advances software-driven LED blink state.
- **Decompiler:** success; reconstructed C SHA-256 `985ba46125210cc667d34ecf997c21123f21c6c2aa9f08589df26d504f7448bd`
- **Artifacts:** `decompiled/00100dc0_local_led_timer_callback.c`, `assembly/00100dc0_local_led_timer_callback.asm`
- **Recognized calls:** `led_off` ×1, `led_on` ×1

## `cleanup_module` @ `0x00101120`

- **Subsystem:** module-lifecycle
- **Evidence:** retained or recovered ELF/source symbol
- **Confidence:** high for identity; medium for detailed semantics
- **Interpretation:** Module teardown path; reverses registrations and frees runtime resources.
- **Decompiler:** success; reconstructed C SHA-256 `77a5515c6e10bfd508f0708c9b112e08870cc5f51afdad83d3e75a455b6de81a`
- **Artifacts:** `decompiled/00101120_cleanup_module.c`, `assembly/00101120_cleanup_module.asm`
- **Recognized calls:** `del_timer` ×2, `remove_proc_entry` ×1

## `init_module` @ `0x00101258`

- **Subsystem:** module-lifecycle
- **Evidence:** retained or recovered ELF/source symbol
- **Confidence:** high for identity; medium for detailed semantics
- **Interpretation:** Initializes board LED GPIO state, timers and proc interface. WAN/LAN PHY activity LEDs may instead remain hardware-driven by BCM53115.
- **Decompiler:** success; reconstructed C SHA-256 `ef924e5bdefef56d12a73c09a7234ad9245d6d89ca87130a469747c85cce9891`
- **Artifacts:** `decompiled/00101258_init_module.c`, `assembly/00101258_init_module.asm`
- **Recognized calls:** `create_proc_entry` ×1, `init_timer` ×2, `init_waitqueue_head` ×1, `printk` ×1
