/*
 * Ghidra reconstructed C; not original Cisco source.
 * Analysis: rv220w-stock-modules-v1.0.0
 * Module: cavium-ethernet
 * Entry: 00101ac0
 * Function: brcm_miiphy_write
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

void brcm_miiphy_write(undefined8 param_1,uint param_2,uint param_3,ushort *param_4)

{
  longlong lVar1;
  longlong in_t0;
  int iVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  undefined8 in_HW_RESIM31;
  
  if (in_t0 == 2) {
    uVar3 = (ulonglong)*param_4;
    uVar4 = 0;
  }
  else if (in_t0 == 4) {
    uVar4 = (ulonglong)(longlong)*(int *)param_4 >> 0x10 & 0xffff;
    uVar3 = (longlong)*(int *)param_4 & 0xffff;
  }
  else if (in_t0 == 1) {
    uVar3 = (ulonglong)*(byte *)param_4;
    uVar4 = 0;
  }
  else {
    uVar3 = 0;
    uVar4 = 0;
  }
  local_cavium_ethernet_text_001568(param_1,0x1e,0x10,(param_2 & 0xff) << 8 | 1);
  iVar2 = 0;
  local_cavium_ethernet_text_001568(param_1,0x1e,0x18,uVar3);
  local_cavium_ethernet_text_001568(param_1,0x1e,0x19,uVar4);
  local_cavium_ethernet_text_001568(param_1,0x1e,0x1a,0);
  local_cavium_ethernet_text_001568(param_1,0x1e,0x1b,0);
  local_cavium_ethernet_text_001568(param_1,0x1e,0x11,(param_3 & 0xff) << 8 | 1);
  do {
    uVar4 = local_cavium_ethernet_text_001638(param_1,0x1e,0x11);
    lVar1 = getHWRegister(in_HW_RESIM31);
    do {
      uVar3 = getHWRegister(in_HW_RESIM31);
    } while (uVar3 < lVar1 + ((longlong)(int)((ulonglong)_mips_hpt_frequency * 10 >> 0x20) << 0x20 |
                             (ulonglong)_mips_hpt_frequency * 10 & 0xffffffff) / 1000000);
  } while ((iVar2 != 5) && (iVar2 = iVar2 + 1, (uVar4 & 3) != 0));
  return;
}

