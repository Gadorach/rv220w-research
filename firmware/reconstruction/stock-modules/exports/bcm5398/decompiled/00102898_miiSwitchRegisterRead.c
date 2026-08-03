/*
 * Ghidra reconstructed C; not original Cisco source.
 * Analysis: rv220w-stock-modules-v1.0.0
 * Module: bcm5398
 * Entry: 00102898
 * Function: miiSwitchRegisterRead
 * Subsystem: mdio-pseudophy
 * Evidence: retained-or-recovered-symbol
 *
 * Embedded Ghidra annotation:
 * RV220W STOCK MODULE SEMANTIC ANNOTATION v1.0.0
 * Module: bcm5398
 * Subsystem: MDIO/pseudo-PHY access
 * Evidence class: retained or recovered ELF/source symbol
 * Confidence: high for identity; medium for detailed semantics
 * Interpretation: Reads an arbitrary-width BCM switch register using the pseudo-PHY/MII transaction protocol.
 * Callers: 
 * Callees: 
 * Referenced strings: none recovered
 * Safety note: decompiler output is reconstructed C, not original Cisco source. Register meanings remain hypotheses unless tied to constants, vendor strings, runtime behavior or upstream register definitions.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* RV220W STOCK MODULE SEMANTIC ANNOTATION v1.0.0
   Module: bcm5398
   Subsystem: MDIO/pseudo-PHY access
   Evidence class: retained or recovered ELF/source symbol
   Confidence: high for identity; medium for detailed semantics
   Interpretation: Reads an arbitrary-width BCM switch register using the pseudo-PHY/MII transaction
   protocol.
   Callers: 
   Callees: 
   Referenced strings: none recovered
   Safety note: decompiler output is reconstructed C, not original Cisco source. Register meanings
   remain hypotheses unless tied to constants, vendor strings, runtime behavior or upstream register
   definitions.
    */

undefined8 miiSwitchRegisterRead(ulonglong param_1,ulonglong param_2,ulonglong *param_3)

{
  ulonglong in_v0;
  ulonglong extraout_a2;
  undefined8 uVar1;
  longlong lVar2;
  undefined8 uVar3;
  ushort auStack_60 [8];
  
  uVar1 = special2(param_1 & 0xffff,in_v0,8,0x32);
  uVar3 = 0;
  auStack_60[0] = (ushort)(in_v0 | 1);
  (*(code *)&mii_phy_write)(0x1e,0x10,in_v0 | 1,uVar1);
  uVar1 = special2(param_2 & 0xffff,extraout_a2,8,0x32);
  auStack_60[0] = (ushort)(extraout_a2 | 2);
  (*(code *)&mii_phy_write)(0x1e,0x11,extraout_a2 | 2,uVar1);
  lVar2 = _jiffies + 0x19;
  do {
    (*(code *)&mii_phy_read)(0x1e,0x11,auStack_60);
    if (lVar2 - _jiffies < 0) {
      uVar3 = 0xffffffffffffffff;
      (*(code *)&printk)(&UNK_00103130,&UNK_00103018,param_1 & 0xffff,param_2 & 0xffff);
    }
  } while ((auStack_60[0] & 3) != 0);
  (*(code *)&mii_phy_read)(0x1e,0x18,auStack_60);
  *param_3 = (ulonglong)auStack_60[0];
  (*(code *)&mii_phy_read)(0x1e,0x19,auStack_60);
  *param_3 = *param_3 | (longlong)(short)auStack_60[0] << 0x10;
  (*(code *)&mii_phy_read)(0x1e,0x1a,auStack_60);
  *param_3 = *param_3 | (ulonglong)auStack_60[0] << 0x20;
  (*(code *)&mii_phy_read)(0x1e,0x1b,auStack_60);
  *param_3 = *param_3 | (ulonglong)auStack_60[0] << 0x30;
  (*(code *)&mii_phy_read)(0x1e,0x11,auStack_60);
  auStack_60[0] = auStack_60[0] & 0xfffe;
  (*(code *)&mii_phy_write)(0x1e,0x11);
  return uVar3;
}

