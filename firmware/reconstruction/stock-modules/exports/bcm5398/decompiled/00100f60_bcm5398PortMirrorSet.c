/*
 * Ghidra reconstructed C; not original Cisco source.
 * Analysis: rv220w-stock-modules-v1.0.0
 * Module: bcm5398
 * Entry: 00100f60
 * Function: bcm5398PortMirrorSet
 * Subsystem: bcm53115-switch
 * Evidence: retained-or-recovered-symbol
 *
 * Embedded Ghidra annotation:
 * RV220W STOCK MODULE SEMANTIC ANNOTATION v1.0.0
 * Module: bcm5398
 * Subsystem: BCM53115 switch/VLAN datapath
 * Evidence class: retained or recovered ELF/source symbol
 * Confidence: high for identity; medium for detailed semantics
 * Interpretation: Programs port-mirroring source/destination controls.
 * Callers: 
 * Callees: 
 * Referenced strings: none recovered
 * Safety note: decompiler output is reconstructed C, not original Cisco source. Register meanings remain hypotheses unless tied to constants, vendor strings, runtime behavior or upstream register definitions.
 */

/* RV220W STOCK MODULE SEMANTIC ANNOTATION v1.0.0
   Module: bcm5398
   Subsystem: BCM53115 switch/VLAN datapath
   Evidence class: retained or recovered ELF/source symbol
   Confidence: high for identity; medium for detailed semantics
   Interpretation: Programs port-mirroring source/destination controls.
   Callers: 
   Callees: 
   Referenced strings: none recovered
   Safety note: decompiler output is reconstructed C, not original Cisco source. Register meanings
   remain hypotheses unless tied to constants, vendor strings, runtime behavior or upstream register
   definitions.
    */

undefined8 bcm5398PortMirrorSet(undefined8 param_1,short param_2,ushort param_3)

{
  longlong lVar1;
  ushort auStack_40 [8];
  
  auStack_40[0] = 0;
  miiSwitchRegisterRead16(2,0x10,auStack_40);
  if (param_2 == 0) {
    auStack_40[0] = auStack_40[0] & 0x7ff0;
    miiSwitchRegisterWrite(2,0x10);
    auStack_40[0] = 0;
    miiSwitchRegisterRead16(2,0x12,auStack_40);
    auStack_40[0] = auStack_40[0] & 0xfff0;
    lVar1 = (*(code *)&strcmp)(uRam00103368,&UNK_00103048);
    if (lVar1 == 0) {
      auStack_40[0] = auStack_40[0] & 0xff0f;
    }
    else {
      lVar1 = (*(code *)&strcmp)(uRam00103368,&UNK_00103050);
      if ((lVar1 == 0) && (lVar1 = wanportCheck(uRam00103362), lVar1 != 0)) {
        auStack_40[0] = auStack_40[0] & 0xffef;
      }
    }
    miiSwitchRegisterWrite(2,0x12,auStack_40[0]);
    auStack_40[0] = 0;
    miiSwitchRegisterRead16(2,0x1c,auStack_40);
    auStack_40[0] = auStack_40[0] & 0xfff0;
    lVar1 = (*(code *)&strcmp)(uRam00103368,&UNK_00103048);
    if (lVar1 == 0) {
      auStack_40[0] = auStack_40[0] & 0xff0f;
      miiSwitchRegisterWrite(2,0x1c,auStack_40[0]);
      return 0;
    }
    lVar1 = (*(code *)&strcmp)(uRam00103368,&UNK_00103050);
    if ((lVar1 == 0) && (lVar1 = wanportCheck(uRam00103362), lVar1 != 0)) {
      auStack_40[0] = auStack_40[0] & 0xffef;
    }
  }
  else {
    auStack_40[0] = auStack_40[0] & 0xfff8 | 0x8000 | param_3;
    miiSwitchRegisterWrite(2,0x10);
    auStack_40[0] = 0;
    miiSwitchRegisterRead16(2,0x12,auStack_40);
    auStack_40[0] = auStack_40[0] | 0xf;
    lVar1 = (*(code *)&strcmp)(uRam00103368,&UNK_00103048);
    if (lVar1 == 0) {
      auStack_40[0] = auStack_40[0] | 0xf0;
    }
    else {
      lVar1 = (*(code *)&strcmp)(uRam00103368,&UNK_00103050);
      if ((lVar1 == 0) && (lVar1 = wanportCheck(uRam00103362), lVar1 != 0)) {
        auStack_40[0] = auStack_40[0] | 0x10;
      }
    }
    miiSwitchRegisterWrite(2,0x12,auStack_40[0]);
    auStack_40[0] = 0;
    miiSwitchRegisterRead16(2,0x1c,auStack_40);
    auStack_40[0] = auStack_40[0] | 0xf;
    lVar1 = (*(code *)&strcmp)(uRam00103368,&UNK_00103048);
    if (lVar1 == 0) {
      auStack_40[0] = auStack_40[0] | 0xf0;
    }
    else {
      lVar1 = (*(code *)&strcmp)(uRam00103368,&UNK_00103050);
      if ((lVar1 == 0) && (lVar1 = wanportCheck(uRam00103362), lVar1 != 0)) {
        auStack_40[0] = auStack_40[0] | 0x10;
      }
    }
  }
  miiSwitchRegisterWrite(2,0x1c,auStack_40[0]);
  return 0;
}

