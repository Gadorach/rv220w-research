# SW2 — unpopulated momentary-switch footprint

## Current measurement

SW2 appears to be a conventional four-pad tactile-switch footprint with two pads per side:

- Two pads: direct GND.
- Two pads: one common signal measuring approximately 16 kΩ to GND with the board unpowered.

A fitted switch would therefore short the candidate signal to ground when pressed.

## Function status

`RESET` is a plausible hypothesis, but it is **not yet established**. Other realistic functions include:

- factory reset,
- recovery or boot-mode request,
- WPS or user-button option,
- manufacturing-test input,
- board-variant strap.

The 16 kΩ unpowered reading does not prove whether the signal is normally high or low while powered.

## Safe promotion test

1. Measure the signal-side voltage after power-up and throughout reset.
2. Observe it with a scope during cold boot.
3. Search the UART boot log for button, reset, recovery, or GPIO messages.
4. For the first active test, pull it toward ground through approximately 1 kΩ rather than hard-shorting it.
5. Record whether the board resets immediately, changes LED state, enters a bootloader/recovery path, or has no observable effect.
6. Repeat with controlled timing: held before power-on, asserted during early boot, and momentarily asserted after Linux is running.
7. Trace the net to a reset supervisor or CN5010 GPIO before permanently labeling it.

Do not hold the signal low for an extended period until powered voltage and current are measured.
