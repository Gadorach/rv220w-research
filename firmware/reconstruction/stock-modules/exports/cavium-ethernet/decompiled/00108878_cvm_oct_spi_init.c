/*
 * Ghidra reconstructed C; not original Cisco source.
 * Analysis: rv220w-stock-modules-v1.0.0
 * Module: cavium-ethernet
 * Entry: 00108878
 * Function: cvm_oct_spi_init
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

undefined8 cvm_oct_spi_init(int param_1)

{
  int iVar1;
  
  if (iRam001113c0 == 0) {
    (*(code *)&request_irq)(0x36,local_cavium_ethernet_text_008a90,0x80,&UNK_0010ef60);
  }
  iRam001113c0 = iRam001113c0 + 1;
  iVar1 = *(int *)(param_1 + 0x560);
  if ((iVar1 != 0) && (iVar1 != 0x10)) {
    cvm_oct_common_init(param_1);
    return 0;
  }
  local_cavium_ethernet_text_008600(iVar1 >> 4);
  *(ulonglong *)(param_1 + 0x7e8) = ZEXT48(local_cavium_ethernet_text_008810);
  cvm_oct_common_init(param_1);
  return 0;
}

