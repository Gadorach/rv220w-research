/*
 * Ghidra reconstructed C; not original Cisco source.
 * Analysis: rv220w-stock-modules-v1.0.0
 * Module: bcm5398
 * Entry: 001007e8
 * Function: bcm5398PortStateSet
 * Subsystem: bcm53115-switch
 * Evidence: retained-or-recovered-symbol
 *
 * Embedded Ghidra annotation:
 * RV220W STOCK MODULE SEMANTIC ANNOTATION v1.0.0
 * Module: bcm5398
 * Subsystem: BCM53115 switch/VLAN datapath
 * Evidence class: retained or recovered ELF/source symbol
 * Confidence: high for identity; medium for detailed semantics
 * Interpretation: Sets a switch port's forwarding/state control; likely covers disabled/blocking/listening/learning/forwarding encodings.
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
   Interpretation: Sets a switch port's forwarding/state control; likely covers
   disabled/blocking/listening/learning/forwarding encodings.
   Callers: 
   Callees: 
   Referenced strings: none recovered
   Safety note: decompiler output is reconstructed C, not original Cisco source. Register meanings
   remain hypotheses unless tied to constants, vendor strings, runtime behavior or upstream register
   definitions.
    */

undefined8 bcm5398PortStateSet(undefined8 param_1,undefined1 param_2,short param_3)

{
  longlong lVar1;
  undefined8 uVar2;
  ushort auStack_30 [8];
  
  auStack_30[0] = 0;
  lVar1 = (*(code *)&mii_phy_read)(param_2,0,auStack_30);
  uVar2 = 0xffffffffffffffff;
  if (lVar1 == 0) {
    auStack_30[0] = auStack_30[0] & 0xf7ff;
    if (param_3 == 1) {
      auStack_30[0] = auStack_30[0] | 0x800;
    }
    uVar2 = (*(code *)&mii_phy_write)(param_2,0,auStack_30[0]);
  }
  return uVar2;
}

