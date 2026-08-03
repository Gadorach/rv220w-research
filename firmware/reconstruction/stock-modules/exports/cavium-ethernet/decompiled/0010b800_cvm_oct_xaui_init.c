/*
 * Ghidra reconstructed C; not original Cisco source.
 * Analysis: rv220w-stock-modules-v1.0.0
 * Module: cavium-ethernet
 * Entry: 0010b800
 * Function: cvm_oct_xaui_init
 * Subsystem: octeon-ethernet
 * Evidence: retained-or-recovered-symbol
 *
 * Embedded Ghidra annotation:
 * RV220W STOCK MODULE SEMANTIC ANNOTATION v1.0.0
 * Module: cavium-ethernet
 * Subsystem: Octeon Ethernet datapath
 * Evidence class: retained or recovered ELF/source symbol
 * Confidence: high for identity; medium for detailed semantics
 * Interpretation: Interface-mode-specific Octeon Ethernet initialization retained from the vendor SDK; applicability to RV220W must be established from callers and bootinfo.
 * Callers: 
 * Callees: 
 * Referenced strings: none recovered
 * Safety note: decompiler output is reconstructed C, not original Cisco source. Register meanings remain hypotheses unless tied to constants, vendor strings, runtime behavior or upstream register definitions.
 */

/* RV220W STOCK MODULE SEMANTIC ANNOTATION v1.0.0
   Module: cavium-ethernet
   Subsystem: Octeon Ethernet datapath
   Evidence class: retained or recovered ELF/source symbol
   Confidence: high for identity; medium for detailed semantics
   Interpretation: Interface-mode-specific Octeon Ethernet initialization retained from the vendor
   SDK; applicability to RV220W must be established from callers and bootinfo.
   Callers: 
   Callees: 
   Referenced strings: none recovered
   Safety note: decompiler output is reconstructed C, not original Cisco source. Register meanings
   remain hypotheses unless tied to constants, vendor strings, runtime behavior or upstream register
   definitions.
    */

undefined8 cvm_oct_xaui_init(int param_1)

{
  cvm_oct_common_init();
  *(ulonglong *)(param_1 + 0x268) = ZEXT48(local_cavium_ethernet_text_00b670);
  *(ulonglong *)(param_1 + 0x260) = ZEXT48(local_cavium_ethernet_text_00b770);
  local_cavium_ethernet_text_00b670(param_1);
  return 0;
}

