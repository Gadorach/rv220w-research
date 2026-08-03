/*
 * Ghidra reconstructed C; not original Cisco source.
 * Analysis: rv220w-stock-modules-v1.0.0
 * Module: scm-led
 * Entry: 00101258
 * Function: init_module
 * Subsystem: module-lifecycle
 * Evidence: retained-or-recovered-symbol
 *
 * Embedded Ghidra annotation:
 * RV220W STOCK MODULE SEMANTIC ANNOTATION v1.0.0
 * Module: scm-led
 * Subsystem: Kernel module lifecycle
 * Evidence class: retained or recovered ELF/source symbol
 * Confidence: high for identity; medium for detailed semantics
 * Interpretation: Initializes board LED GPIO state, timers and proc interface. WAN/LAN PHY activity LEDs may instead remain hardware-driven by BCM53115.
 * Callers: 
 * Callees: 
 * Referenced strings: none recovered
 * Safety note: decompiler output is reconstructed C, not original Cisco source. Register meanings remain hypotheses unless tied to constants, vendor strings, runtime behavior or upstream register definitions.
 */

/* RV220W STOCK MODULE SEMANTIC ANNOTATION v1.0.0
   Module: scm-led
   Subsystem: Kernel module lifecycle
   Evidence class: retained or recovered ELF/source symbol
   Confidence: high for identity; medium for detailed semantics
   Interpretation: Initializes board LED GPIO state, timers and proc interface. WAN/LAN PHY activity
   LEDs may instead remain hardware-driven by BCM53115.
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
  
  (*(code *)&printk)(&UNK_001018a8);
  uRam00101ea0 = (*(code *)&create_proc_entry)(&DAT_00101870,0x1b6,&proc_root);
  iVar1 = (int)uRam00101ea0;
  *(ulonglong *)(iVar1 + 0x40) = ZEXT48(__this_module);
  *(ulonglong *)(iVar1 + 0x30) = ZEXT48(&DAT_00101940);
  (*(code *)&init_timer)(0x101e40);
  uRam00101e58 = ZEXT48(local_led_timer_callback);
  (*(code *)&init_timer)(0x101e70);
  uRam00101e88 = ZEXT48(local_led_timer_callback);
  uRam00101e28 = 1;
  (*(code *)&init_waitqueue_head)(0x101e30);
  uRam00101e20 = uRam00101e10;
  uRam00101e18 = 1;
  uRam00101e10 = ZEXT48(blink_wlan);
  return 0;
}

