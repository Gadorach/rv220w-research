/*
 * Ghidra reconstructed C; not original Cisco source.
 * Analysis: rv220w-stock-modules-v1.0.0
 * Module: bcm5398
 * Entry: 00100898
 * Function: bcm5398PortConfigSet
 * Subsystem: bcm53115-switch
 * Evidence: retained-or-recovered-symbol
 *
 * Embedded Ghidra annotation:
 * RV220W STOCK MODULE SEMANTIC ANNOTATION v1.0.0
 * Module: bcm5398
 * Subsystem: BCM53115 switch/VLAN datapath
 * Evidence class: retained or recovered ELF/source symbol
 * Confidence: high for identity; medium for detailed semantics
 * Interpretation: Programs per-port switch configuration, including policy fields supplied by the vendor control plane.
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
   Interpretation: Programs per-port switch configuration, including policy fields supplied by the
   vendor control plane.
   Callers: 
   Callees: 
   Referenced strings: none recovered
   Safety note: decompiler output is reconstructed C, not original Cisco source. Register meanings
   remain hypotheses unless tied to constants, vendor strings, runtime behavior or upstream register
   definitions.
    */

undefined8 bcm5398PortConfigSet(undefined8 param_1,undefined1 param_2,char param_3,char param_4)

{
  longlong lVar1;
  undefined8 uVar2;
  char in_t0_lo;
  ushort auStack_40 [8];
  
  auStack_40[0] = 0;
  lVar1 = (*(code *)&mii_phy_read)(param_2,0,auStack_40);
  if (lVar1 != 0) {
    return 0xffffffffffffffff;
  }
  auStack_40[0] = auStack_40[0] & 0xcebf;
  if (param_3 != '\0') {
    auStack_40[0] = auStack_40[0] | 0x1000;
  }
  if (param_4 == '\x01') {
    auStack_40[0] = auStack_40[0] | 0x100;
  }
  else if (param_4 != '\x02') {
    return 0xffffffffffffffff;
  }
  if (in_t0_lo == '\x02') {
    auStack_40[0] = auStack_40[0] | 0x2000;
    uVar2 = (*(code *)&mii_phy_write)(param_2,0,auStack_40[0]);
  }
  else {
    if (in_t0_lo == '\x03') {
      auStack_40[0] = auStack_40[0] | 0x1040;
    }
    else if (in_t0_lo != '\x01') {
      return 0xffffffffffffffff;
    }
    uVar2 = (*(code *)&mii_phy_write)(param_2,0,auStack_40[0]);
  }
  return uVar2;
}

