/*
 * Ghidra reconstructed C; not original Cisco source.
 * Analysis: rv220w-stock-modules-v1.0.0
 * Module: scm-led
 * Entry: 00101120
 * Function: cleanup_module
 * Subsystem: module-lifecycle
 * Evidence: retained-or-recovered-symbol
 *
 * Embedded Ghidra annotation:
 * RV220W STOCK MODULE SEMANTIC ANNOTATION v1.0.0
 * Module: scm-led
 * Subsystem: Kernel module lifecycle
 * Evidence class: retained or recovered ELF/source symbol
 * Confidence: high for identity; medium for detailed semantics
 * Interpretation: Module teardown path; reverses registrations and frees runtime resources.
 * Callers: 
 * Callees: 
 * Referenced strings: none recovered
 * Safety note: decompiler output is reconstructed C, not original Cisco source. Register meanings remain hypotheses unless tied to constants, vendor strings, runtime behavior or upstream register definitions.
 */

/* WARNING: Control flow encountered bad instruction data */
/* RV220W STOCK MODULE SEMANTIC ANNOTATION v1.0.0
   Module: scm-led
   Subsystem: Kernel module lifecycle
   Evidence class: retained or recovered ELF/source symbol
   Confidence: high for identity; medium for detailed semantics
   Interpretation: Module teardown path; reverses registrations and frees runtime resources.
   Callers: 
   Callees: 
   Referenced strings: none recovered
   Safety note: decompiler output is reconstructed C, not original Cisco source. Register meanings
   remain hypotheses unless tied to constants, vendor strings, runtime behavior or upstream register
   definitions.
    */

void cleanup_module(void)

{
  (*(code *)&remove_proc_entry)(&DAT_00101870,&proc_root);
  (*(code *)&del_timer)(0x101e70);
  (*(code *)&del_timer)(0x101e40);
  uRam00101e18 = 1;
  uRam00101e10 = uRam00101e20;
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

