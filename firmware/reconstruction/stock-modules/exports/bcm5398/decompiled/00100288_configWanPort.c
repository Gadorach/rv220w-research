/*
 * Ghidra reconstructed C; not original Cisco source.
 * Analysis: rv220w-stock-modules-v1.0.0
 * Module: bcm5398
 * Entry: 00100288
 * Function: configWanPort
 * Subsystem: bcm53115-switch
 * Evidence: retained-or-recovered-symbol
 *
 * Embedded Ghidra annotation:
 * RV220W STOCK MODULE SEMANTIC ANNOTATION v1.0.0
 * Module: bcm5398
 * Subsystem: BCM53115 switch/VLAN datapath
 * Evidence class: retained or recovered ELF/source symbol
 * Confidence: high for identity; medium for detailed semantics
 * Interpretation: Board-policy routine that applies special configuration to the designated WAN port. This is a primary target for recovering WAN-vs-LAN switch-port numbering.
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
   Interpretation: Board-policy routine that applies special configuration to the designated WAN
   port. This is a primary target for recovering WAN-vs-LAN switch-port numbering.
   Callers: 
   Callees: 
   Referenced strings: none recovered
   Safety note: decompiler output is reconstructed C, not original Cisco source. Register meanings
   remain hypotheses unless tied to constants, vendor strings, runtime behavior or upstream register
   definitions.
    */

undefined8 configWanPort(longlong param_1)

{
  undefined4 uVar1;
  undefined8 in_zero;
  longlong lVar2;
  int iVar3;
  undefined2 uStack_30;
  undefined1 auStack_2e [2];
  undefined2 auStack_2c [6];
  
  uStack_30 = 0;
  auStack_2c[0] = 0;
  miiSwitchRegisterRead16(2,0x10,&uStack_30);
  miiSwitchRegisterRead16(2,0x12,auStack_2e);
  miiSwitchRegisterRead16(2,0x1c,auStack_2c);
  if (param_1 == 0) {
    lVar2 = (*(code *)&strcmp)(uRam00103368,&UNK_00103050);
    if (lVar2 == 0) {
      setCopReg(2,in_zero,*(undefined4 *)((0 >> (longlong)(_DAT_00103780 + -1)) + 0x1b));
    }
    auStack_2c[0] = 0;
  }
  else {
    lVar2 = (*(code *)&strcmp)(uRam00103368,&UNK_00103050);
    if (lVar2 == 0) {
      iVar3 = _DAT_00103780 + -1;
      uVar1 = getCopReg(2,0);
      *(undefined4 *)((0 >> (longlong)iVar3) + 0x59) = uVar1;
      auStack_2c[0] = (undefined2)(1L << (longlong)iVar3);
    }
  }
  miiSwitchRegisterWrite(2,0x12,auStack_2c[0]);
  miiSwitchRegisterWrite(2,0x1c,auStack_2c[0]);
  miiSwitchRegisterWrite(2,0x10,uStack_30);
  return 0;
}

