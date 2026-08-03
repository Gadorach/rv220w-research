/*
 * Ghidra reconstructed C; not original Cisco source.
 * Analysis: rv220w-stock-modules-v1.0.0
 * Module: bcm5398
 * Entry: 00102660
 * Function: miiSwitchRegisterWrite
 * Subsystem: mdio-pseudophy
 * Evidence: retained-or-recovered-symbol
 *
 * Embedded Ghidra annotation:
 * RV220W STOCK MODULE SEMANTIC ANNOTATION v1.0.0
 * Module: bcm5398
 * Subsystem: MDIO/pseudo-PHY access
 * Evidence class: retained or recovered ELF/source symbol
 * Confidence: high for identity; medium for detailed semantics
 * Interpretation: Writes an arbitrary-width BCM switch register using the pseudo-PHY/MII transaction protocol.
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
   Interpretation: Writes an arbitrary-width BCM switch register using the pseudo-PHY/MII
   transaction protocol.
   Callers: 
   Callees: 
   Referenced strings: none recovered
   Safety note: decompiler output is reconstructed C, not original Cisco source. Register meanings
   remain hypotheses unless tied to constants, vendor strings, runtime behavior or upstream register
   definitions.
    */

undefined8 miiSwitchRegisterWrite(undefined8 param_1,undefined8 param_2,ulonglong param_3)

{
  uint uVar1;
  longlong lVar2;
  undefined8 uVar3;
  ushort auStack_60 [8];
  
  uVar1 = ((uint)param_1 & 0xff) << 8 | 1;
  uVar3 = 0;
  auStack_60[0] = (ushort)uVar1;
  (*(code *)&mii_phy_write)(0x1e,0x10,uVar1);
  auStack_60[0] = (ushort)param_3;
  (*(code *)&mii_phy_write)(0x1e,0x18,param_3 & 0xffff);
  auStack_60[0] = (ushort)(param_3 >> 0x10);
  (*(code *)&mii_phy_write)(0x1e,0x19,param_3 >> 0x10 & 0xffff);
  auStack_60[0] = (ushort)(param_3 >> 0x20);
  (*(code *)&mii_phy_write)(0x1e,0x1a,param_3 >> 0x20 & 0xffff);
  auStack_60[0] = (ushort)(param_3 >> 0x30);
  (*(code *)&mii_phy_write)(0x1e,0x1b,param_3 >> 0x30);
  auStack_60[0] = (ushort)((int)param_2 << 8) | 1;
  (*(code *)&mii_phy_write)(0x1e,0x11);
  lVar2 = _jiffies + 0x19;
  do {
    (*(code *)&mii_phy_read)(0x1e,0x11,auStack_60);
    if (lVar2 - _jiffies < 0) {
      uVar3 = 0xffffffffffffffff;
      (*(code *)&printk)(&UNK_001030f0,&DAT_00103000,param_1,param_2);
    }
  } while ((auStack_60[0] & 3) != 0);
  (*(code *)&mii_phy_read)(0x1e,0x11,auStack_60);
  auStack_60[0] = auStack_60[0] & 0xfffe;
  (*(code *)&mii_phy_write)(0x1e,0x11);
  return uVar3;
}

