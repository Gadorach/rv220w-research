/*
 * Ghidra reconstructed C; not original Cisco source.
 * Analysis: rv220w-stock-modules-v1.0.0
 * Module: bcm5398
 * Entry: 00100ca8
 * Function: bcm5398VlanEntryGet
 * Subsystem: bcm53115-switch
 * Evidence: retained-or-recovered-symbol
 *
 * Embedded Ghidra annotation:
 * RV220W STOCK MODULE SEMANTIC ANNOTATION v1.0.0
 * Module: bcm5398
 * Subsystem: BCM53115 switch/VLAN datapath
 * Evidence class: retained or recovered ELF/source symbol
 * Confidence: high for identity; medium for detailed semantics
 * Interpretation: Reads a VLAN table entry from the switch.
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
   Interpretation: Reads a VLAN table entry from the switch.
   Callers: 
   Callees: 
   Referenced strings: none recovered
   Safety note: decompiler output is reconstructed C, not original Cisco source. Register meanings
   remain hypotheses unless tied to constants, vendor strings, runtime behavior or upstream register
   definitions.
    */

undefined8 bcm5398VlanEntryGet(undefined8 param_1,ulonglong param_2,ushort *param_3,ushort *param_4)

{
  longlong lVar1;
  undefined8 uVar2;
  byte *in_t0_lo;
  undefined8 uVar3;
  undefined8 uVar4;
  char acStack_50 [4];
  int aiStack_4c [3];
  
  acStack_50[0] = -0x7f;
  lVar1 = (*(code *)&strcmp)(uRam00103368,&UNK_00103050);
  if (lVar1 != 0) {
    lVar1 = (*(code *)&strcmp)(uRam00103368,&UNK_001030c8);
    uVar4 = 99;
    if (lVar1 != 0) {
      uVar2 = 0x61;
      uVar3 = 0x60;
      goto code_r0x00100d44;
    }
  }
  uVar4 = 0x83;
  uVar2 = 0x81;
  uVar3 = 0x80;
code_r0x00100d44:
  miiSwitchRegisterWrite(5,uVar2,param_2 & 0xfff);
  miiSwitchRegisterWrite(5,uVar3,acStack_50[0]);
  lVar1 = _jiffies + 0x7d;
  do {
    miiSwitchRegisterRead8(5,uVar3,acStack_50);
    if (-1 < acStack_50[0]) {
      miiSwitchRegisterRead32(5,uVar4,aiStack_4c);
      *param_3 = (ushort)aiStack_4c[0] & 0x1ff;
      *param_4 = (ushort)((ulonglong)(longlong)aiStack_4c[0] >> 9) & 0x1ff;
      *in_t0_lo = (byte)((ulonglong)(longlong)aiStack_4c[0] >> 0x12) & 0xf;
      return 0;
    }
  } while (_jiffies - lVar1 < 0);
  return 0xffffffffffffffff;
}

