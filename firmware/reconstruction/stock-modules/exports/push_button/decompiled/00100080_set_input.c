/*
 * Ghidra reconstructed C; not original Cisco source.
 * Analysis: rv220w-stock-modules-v1.0.0
 * Module: push_button
 * Entry: 00100080
 * Function: set_input
 * Subsystem: module-support
 * Evidence: retained-or-recovered-symbol
 *
 * Embedded Ghidra annotation:
 * RV220W STOCK MODULE SEMANTIC ANNOTATION v1.0.0
 * Module: push_button
 * Subsystem: Module-local support
 * Evidence class: retained or recovered ELF/source symbol
 * Confidence: high for identity; medium for detailed semantics
 * Interpretation: Reset-button helper that updates input/proc state and wakeup/timer behavior.
 * Callers: 
 * Callees: 
 * Referenced strings: none recovered
 * Safety note: decompiler output is reconstructed C, not original Cisco source. Register meanings remain hypotheses unless tied to constants, vendor strings, runtime behavior or upstream register definitions.
 */

/* RV220W STOCK MODULE SEMANTIC ANNOTATION v1.0.0
   Module: push_button
   Subsystem: Module-local support
   Evidence class: retained or recovered ELF/source symbol
   Confidence: high for identity; medium for detailed semantics
   Interpretation: Reset-button helper that updates input/proc state and wakeup/timer behavior.
   Callers: 
   Callees: 
   Referenced strings: none recovered
   Safety note: decompiler output is reconstructed C, not original Cisco source. Register meanings
   remain hypotheses unless tied to constants, vendor strings, runtime behavior or upstream register
   definitions.
    */

void set_input(void)

{
  gpio_config_input_sense(5);
  gpio_config_input_sense(6);
  gpio_config_input_sense(0xb);
  gpio_config_input_sense(0xc);
  special2(0xd,0xd,3,0x32);
  uRam0000080d = uRam0000080d & 0xfffffffffffffffe;
  return;
}

