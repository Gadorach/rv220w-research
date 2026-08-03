/*
 * Ghidra reconstructed C; not original Cisco source.
 * Analysis: rv220w-stock-modules-v1.0.0
 * Module: cavium-ethernet
 * Entry: 00104090
 * Function: cvm_oct_rgmii_init
 * Subsystem: mdio-pseudophy
 * Evidence: retained-or-recovered-symbol
 *
 * Embedded Ghidra annotation:
 * RV220W STOCK MODULE SEMANTIC ANNOTATION v1.0.0
 * Module: cavium-ethernet
 * Subsystem: MDIO/pseudo-PHY access
 * Evidence class: retained or recovered ELF/source symbol
 * Confidence: high for identity; medium for detailed semantics
 * Interpretation: Initializes an Octeon RGMII interface; critical for correlating the three GMX/RGMII ports reported on RV220W.
 * Callers: 
 * Callees: 
 * Referenced strings: none recovered
 * Safety note: decompiler output is reconstructed C, not original Cisco source. Register meanings remain hypotheses unless tied to constants, vendor strings, runtime behavior or upstream register definitions.
 */

/* RV220W STOCK MODULE SEMANTIC ANNOTATION v1.0.0
   Module: cavium-ethernet
   Subsystem: MDIO/pseudo-PHY access
   Evidence class: retained or recovered ELF/source symbol
   Confidence: high for identity; medium for detailed semantics
   Interpretation: Initializes an Octeon RGMII interface; critical for correlating the three
   GMX/RGMII ports reported on RV220W.
   Callers: 
   Callees: 
   Referenced strings: none recovered
   Safety note: decompiler output is reconstructed C, not original Cisco source. Register meanings
   remain hypotheses unless tied to constants, vendor strings, runtime behavior or upstream register
   definitions.
    */

undefined8 cvm_oct_rgmii_init(int param_1)

{
  longlong lVar1;
  
  cvm_oct_common_init();
  *(ulonglong *)(param_1 + 0x260) = ZEXT48(local_cavium_ethernet_text_004638);
  *(ulonglong *)(param_1 + 0x268) = ZEXT48(local_cavium_ethernet_text_003f88);
  local_cavium_ethernet_text_003f88(param_1);
  if (*(int *)(param_1 + 0x56c) == 2) {
    if (*(int *)(param_1 + 0x560) != 0) {
      return 0;
    }
  }
  else if (*(int *)(param_1 + 0x56c) != 1) {
    return 0;
  }
  lVar1 = (*(code *)&octeon_is_simulation)();
  if (lVar1 != 0) {
    return 0;
  }
  *(ulonglong *)(param_1 + 0x7e8) = ZEXT48(local_cavium_ethernet_text_004088);
  return 0;
}

