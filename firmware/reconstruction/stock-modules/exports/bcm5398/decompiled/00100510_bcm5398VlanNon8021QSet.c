/*
 * Ghidra reconstructed C; not original Cisco source.
 * Analysis: rv220w-stock-modules-v1.0.0
 * Module: bcm5398
 * Entry: 00100510
 * Function: bcm5398VlanNon8021QSet
 * Subsystem: bcm53115-switch
 * Evidence: retained-or-recovered-symbol
 *
 * Embedded Ghidra annotation:
 * RV220W STOCK MODULE SEMANTIC ANNOTATION v1.0.0
 * Module: bcm5398
 * Subsystem: BCM53115 switch/VLAN datapath
 * Evidence class: retained or recovered ELF/source symbol
 * Confidence: high for identity; medium for detailed semantics
 * Interpretation: Semantics inferred conservatively from the retained source symbol, direct callers/callees, imported APIs and referenced strings. See the per-function exports for evidence.
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
   Interpretation: Semantics inferred conservatively from the retained source symbol, direct
   callers/callees, imported APIs and referenced strings. See the per-function exports for evidence.
   Callers: 
   Callees: 
   Referenced strings: none recovered
   Safety note: decompiler output is reconstructed C, not original Cisco source. Register meanings
   remain hypotheses unless tied to constants, vendor strings, runtime behavior or upstream register
   definitions.
    */

undefined8 bcm5398VlanNon8021QSet(undefined8 param_1,ulonglong param_2,longlong param_3)

{
  ushort uVar1;
  ushort auStack_30 [8];
  
  auStack_30[0] = 0;
  miiSwitchRegisterRead16(0x34,3,auStack_30);
  uVar1 = (ushort)(1L << (param_2 & 0xffff));
  if (param_3 == 1) {
    auStack_30[0] = auStack_30[0] | uVar1;
  }
  else {
    auStack_30[0] = ~uVar1 & auStack_30[0];
  }
  miiSwitchRegisterWrite(0x34,3,auStack_30[0]);
  return 0;
}

