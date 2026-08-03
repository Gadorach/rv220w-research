/*
 * Ghidra reconstructed C; not original Cisco source.
 * Analysis: rv220w-stock-modules-v1.0.0
 * Module: cavium-ethernet
 * Entry: 00101938
 * Function: brcm_miiphy_read
 * Subsystem: mdio-pseudophy
 * Evidence: retained-or-recovered-symbol
 *
 * Embedded Ghidra annotation:
 * RV220W STOCK MODULE SEMANTIC ANNOTATION v1.0.0
 * Module: cavium-ethernet
 * Subsystem: MDIO/pseudo-PHY access
 * Evidence class: retained or recovered ELF/source symbol
 * Confidence: high for identity; medium for detailed semantics
 * Interpretation: Broadcom-oriented MDIO callback used by the Octeon Ethernet/switch integration.
 * Callers: 
 * Callees: 
 * Referenced strings: none recovered
 * Safety note: decompiler output is reconstructed C, not original Cisco source. Register meanings remain hypotheses unless tied to constants, vendor strings, runtime behavior or upstream register definitions.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* RV220W STOCK MODULE SEMANTIC ANNOTATION v1.0.0
   Module: cavium-ethernet
   Subsystem: MDIO/pseudo-PHY access
   Evidence class: retained or recovered ELF/source symbol
   Confidence: high for identity; medium for detailed semantics
   Interpretation: Broadcom-oriented MDIO callback used by the Octeon Ethernet/switch integration.
   Callers: 
   Callees: 
   Referenced strings: none recovered
   Safety note: decompiler output is reconstructed C, not original Cisco source. Register meanings
   remain hypotheses unless tied to constants, vendor strings, runtime behavior or upstream register
   definitions.
    */

uint brcm_miiphy_read(undefined8 param_1,uint param_2,uint param_3)

{
  ulonglong uVar1;
  ulonglong uVar2;
  uint uVar3;
  longlong lVar4;
  int iVar5;
  undefined8 in_HW_RESIM31;
  
  local_cavium_ethernet_text_001568(param_1,0x1e,0x10,(param_2 & 0xff) << 8 | 1);
  iVar5 = 0;
  local_cavium_ethernet_text_001568(param_1,0x1e,0x11,(param_3 & 0xff) << 8 | 2);
  do {
    uVar1 = local_cavium_ethernet_text_001638(param_1,0x1e,0x11);
    lVar4 = getHWRegister(in_HW_RESIM31);
    do {
      uVar2 = getHWRegister(in_HW_RESIM31);
    } while (uVar2 < lVar4 + ((longlong)(int)((ulonglong)_mips_hpt_frequency * 10 >> 0x20) << 0x20 |
                             (ulonglong)_mips_hpt_frequency * 10 & 0xffffffff) / 1000000);
  } while ((iVar5 != 5) && (iVar5 = iVar5 + 1, (uVar1 & 3) != 0));
  uVar3 = local_cavium_ethernet_text_001638(param_1,0x1e,0x18);
  iVar5 = local_cavium_ethernet_text_001638(param_1,0x1e,0x19);
  return iVar5 << 0x10 | uVar3;
}

