/*
 * Ghidra reconstructed C; not original Cisco source.
 * Analysis: rv220w-stock-modules-v1.0.0
 * Module: push_button
 * Entry: 00100880
 * Function: init_module
 * Subsystem: module-lifecycle
 * Evidence: retained-or-recovered-symbol
 *
 * Embedded Ghidra annotation:
 * RV220W STOCK MODULE SEMANTIC ANNOTATION v1.0.0
 * Module: push_button
 * Subsystem: Kernel module lifecycle
 * Evidence class: retained or recovered ELF/source symbol
 * Confidence: high for identity; medium for detailed semantics
 * Interpretation: Registers the RV220W push-button GPIO input, timers, wait state and proc/sysctl interface; imports led_blink for visual feedback.
 * Callers: 
 * Callees: 
 * Referenced strings: none recovered
 * Safety note: decompiler output is reconstructed C, not original Cisco source. Register meanings remain hypotheses unless tied to constants, vendor strings, runtime behavior or upstream register definitions.
 */

/* RV220W STOCK MODULE SEMANTIC ANNOTATION v1.0.0
   Module: push_button
   Subsystem: Kernel module lifecycle
   Evidence class: retained or recovered ELF/source symbol
   Confidence: high for identity; medium for detailed semantics
   Interpretation: Registers the RV220W push-button GPIO input, timers, wait state and proc/sysctl
   interface; imports led_blink for visual feedback.
   Callers: 
   Callees: 
   Referenced strings: none recovered
   Safety note: decompiler output is reconstructed C, not original Cisco source. Register meanings
   remain hypotheses unless tied to constants, vendor strings, runtime behavior or upstream register
   definitions.
    */

undefined8 init_module(void)

{
  int iVar1;
  
  uRam001010f0 = (*(code *)&create_proc_entry)(&DAT_00100a68,0x1b6,&proc_root);
  iVar1 = (int)uRam001010f0;
  *(ulonglong *)(iVar1 + 0x30) = ZEXT48(push_button_fops);
  *(ulonglong *)(iVar1 + 0x40) = ZEXT48(__this_module);
  lRam001010f8 = (*(code *)&register_sysctl_table)(0x100c88);
  if (lRam001010f8 != 0) {
    (*(code *)&printk)(&UNK_00100aa8);
  }
  set_input();
  (*(code *)&init_timer)(0x1010a0);
  uRam00101088 = 0;
  (*(code *)&init_waitqueue_head)(0x101090);
  return 0;
}

