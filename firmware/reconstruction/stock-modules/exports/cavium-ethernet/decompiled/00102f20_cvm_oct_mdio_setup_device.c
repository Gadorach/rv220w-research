/*
 * Ghidra reconstructed C; not original Cisco source.
 * Analysis: rv220w-stock-modules-v1.0.0
 * Module: cavium-ethernet
 * Entry: 00102f20
 * Function: cvm_oct_mdio_setup_device
 * Subsystem: mdio-pseudophy
 * Evidence: retained-or-recovered-symbol
 *
 * Embedded Ghidra annotation:
 * RV220W STOCK MODULE SEMANTIC ANNOTATION v1.0.0
 * Module: cavium-ethernet
 * Subsystem: MDIO/pseudo-PHY access
 * Evidence class: retained or recovered ELF/source symbol
 * Confidence: high for identity; medium for detailed semantics
 * Interpretation: Semantics inferred conservatively from the retained source symbol, direct callers/callees, imported APIs and referenced strings. See the per-function exports for evidence.
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
   Interpretation: Semantics inferred conservatively from the retained source symbol, direct
   callers/callees, imported APIs and referenced strings. See the per-function exports for evidence.
   Callers: 
   Callees: 
   Referenced strings: none recovered
   Safety note: decompiler output is reconstructed C, not original Cisco source. Register meanings
   remain hypotheses unless tied to constants, vendor strings, runtime behavior or upstream register
   definitions.
    */

undefined8 cvm_oct_mdio_setup_device(undefined8 param_1)

{
  int iVar1;
  longlong lVar2;
  
  iVar1 = (int)param_1;
  lVar2 = (*(code *)&cvmx_helper_board_get_mii_address)(*(undefined4 *)(iVar1 + 0x560));
  if (lVar2 != -1) {
    *(ulonglong *)(iVar1 + 2000) = ZEXT48(local_cavium_ethernet_text_002ee0);
    *(undefined8 *)(iVar1 + 0x7c0) = param_1;
    *(ulonglong *)(iVar1 + 0x7b8) =
         *(ulonglong *)(iVar1 + 0x7b8) & 0xdfffffffffffffff | 0x2000000000000000;
    *(undefined4 *)(iVar1 + 0x7b0) = 0xff;
    *(int *)(iVar1 + 0x7a8) = (int)lVar2;
    *(undefined4 *)(iVar1 + 0x7b4) = 0x1f;
    *(ulonglong *)(iVar1 + 0x7c8) = ZEXT48(local_cavium_ethernet_text_002fa0);
    return 0;
  }
  *(ulonglong *)(iVar1 + 2000) = ZEXT48(local_cavium_ethernet_text_002c68);
  *(ulonglong *)(iVar1 + 0x7c8) = ZEXT48(local_cavium_ethernet_text_002c60);
  return 0;
}

