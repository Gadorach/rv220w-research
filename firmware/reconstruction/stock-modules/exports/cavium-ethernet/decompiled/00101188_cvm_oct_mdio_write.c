/*
 * Ghidra reconstructed C; not original Cisco source.
 * Analysis: rv220w-stock-modules-v1.0.0
 * Module: cavium-ethernet
 * Entry: 00101188
 * Function: cvm_oct_mdio_write
 * Subsystem: mdio-pseudophy
 * Evidence: retained-or-recovered-symbol
 *
 * Embedded Ghidra annotation:
 * RV220W STOCK MODULE SEMANTIC ANNOTATION v1.0.0
 * Module: cavium-ethernet
 * Subsystem: MDIO/pseudo-PHY access
 * Evidence class: retained or recovered ELF/source symbol
 * Confidence: high for identity; medium for detailed semantics
 * Interpretation: Vendor Octeon MDIO write implementation exported to the MII wrapper module.
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
   Interpretation: Vendor Octeon MDIO write implementation exported to the MII wrapper module.
   Callers: 
   Callees: 
   Referenced strings: none recovered
   Safety note: decompiler output is reconstructed C, not original Cisco source. Register meanings
   remain hypotheses unless tied to constants, vendor strings, runtime behavior or upstream register
   definitions.
    */

void cvm_oct_mdio_write(undefined8 param_1,ulonglong param_2,ulonglong param_3,ulonglong param_4)

{
  int iVar1;
  undefined4 uVar2;
  int unaff_gp_lo;
  
  uRam00001808 = param_4 & 0xffff;
  uRam00001800 = (param_2 & 0x1f) << 8 | param_3 & 0x1f;
  iVar1 = *(int *)(unaff_gp_lo + 0x24);
  while (((ulonglong)(longlong)iVar1 >> 8 & 0xfffff) != 0) {
    setCopReg(2,0x112020,*(undefined4 *)((int)uRam00001808 + 10));
    iVar1 = *(int *)(unaff_gp_lo + 0x24);
  }
  (*(code *)&yield)(0x8001180000001808,0x8001180000001800,uRam000000f8);
  uVar2 = getCopReg(2,0x11);
  *(undefined4 *)((int)uRam00001808 + -8) = uVar2;
  return;
}

