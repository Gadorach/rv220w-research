/*
 * Ghidra reconstructed C; not original Cisco source.
 * Analysis: rv220w-stock-modules-v1.0.0
 * Module: bcm5398
 * Entry: 00100a18
 * Function: bcm5398VlanEntrySet
 * Subsystem: bcm53115-switch
 * Evidence: retained-or-recovered-symbol
 *
 * Embedded Ghidra annotation:
 * RV220W STOCK MODULE SEMANTIC ANNOTATION v1.0.0
 * Module: bcm5398
 * Subsystem: BCM53115 switch/VLAN datapath
 * Evidence class: retained or recovered ELF/source symbol
 * Confidence: high for identity; medium for detailed semantics
 * Interpretation: Programs a VLAN table entry, including membership and tagging policy.
 * Callers: 
 * Callees: 
 * Referenced strings: none recovered
 * Safety note: decompiler output is reconstructed C, not original Cisco source. Register meanings remain hypotheses unless tied to constants, vendor strings, runtime behavior or upstream register definitions.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* RV220W STOCK MODULE SEMANTIC ANNOTATION v1.0.0
   Module: bcm5398
   Subsystem: BCM53115 switch/VLAN datapath
   Evidence class: retained or recovered ELF/source symbol
   Confidence: high for identity; medium for detailed semantics
   Interpretation: Programs a VLAN table entry, including membership and tagging policy.
   Callers: 
   Callees: 
   Referenced strings: none recovered
   Safety note: decompiler output is reconstructed C, not original Cisco source. Register meanings
   remain hypotheses unless tied to constants, vendor strings, runtime behavior or upstream register
   definitions.
    */

undefined8 bcm5398VlanEntrySet(undefined8 param_1,uint param_2,uint param_3,uint param_4)

{
  longlong lVar1;
  uint uVar2;
  uint in_t0_lo;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  char acStack_40 [16];
  
  uVar2 = param_3 & 0x1ff | (param_4 & 0x1ff) << 9 | (in_t0_lo & 0xf) << 0x12;
  acStack_40[0] = -0x80;
  lVar1 = (*(code *)&strcmp)(uRam00103368,&UNK_00103050);
  if (lVar1 != 0) {
    lVar1 = (*(code *)&strcmp)(uRam00103368,&UNK_001030c8);
    uVar3 = 99;
    if (lVar1 != 0) {
      uVar5 = 0x61;
      uVar4 = 0x60;
      goto code_r0x00100acc;
    }
  }
  uVar3 = 0x83;
  uVar5 = 0x81;
  uVar4 = 0x80;
code_r0x00100acc:
  if ((-1 < _DAT_00103780) && (_DAT_00103360 == (param_2 & 0xffff))) {
    if (uVar2 == 0) {
      configWanPort(1,uVar3);
    }
    else {
      configWanPort(0);
    }
  }
  miiSwitchRegisterWrite(5,uVar3,uVar2);
  miiSwitchRegisterWrite(5,uVar5,param_2 & 0xfff);
  miiSwitchRegisterWrite(5,uVar4,acStack_40[0]);
  lVar1 = _jiffies + 0x7d;
  do {
    miiSwitchRegisterRead8(5,uVar4,acStack_40);
    if (-1 < acStack_40[0]) {
      return 0;
    }
  } while (_jiffies - lVar1 < 0);
  return 0xffffffffffffffff;
}

