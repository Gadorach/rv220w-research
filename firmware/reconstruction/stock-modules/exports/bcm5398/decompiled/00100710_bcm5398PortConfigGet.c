/*
 * Ghidra reconstructed C; not original Cisco source.
 * Analysis: rv220w-stock-modules-v1.0.0
 * Module: bcm5398
 * Entry: 00100710
 * Function: bcm5398PortConfigGet
 * Subsystem: bcm53115-switch
 * Evidence: retained-or-recovered-symbol
 *
 * Embedded Ghidra annotation:
 * RV220W STOCK MODULE SEMANTIC ANNOTATION v1.0.0
 * Module: bcm5398
 * Subsystem: BCM53115 switch/VLAN datapath
 * Evidence class: retained or recovered ELF/source symbol
 * Confidence: high for identity; medium for detailed semantics
 * Interpretation: Reads per-port switch configuration for the vendor control plane.
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
   Interpretation: Reads per-port switch configuration for the vendor control plane.
   Callers: 
   Callees: 
   Referenced strings: none recovered
   Safety note: decompiler output is reconstructed C, not original Cisco source. Register meanings
   remain hypotheses unless tied to constants, vendor strings, runtime behavior or upstream register
   definitions.
    */

undefined8
bcm5398PortConfigGet(undefined8 param_1,undefined1 param_2,byte *param_3,undefined1 *param_4)

{
  longlong lVar1;
  undefined1 uVar2;
  undefined1 *in_t0_lo;
  ushort auStack_30 [8];
  
  lVar1 = (*(code *)&mii_phy_read)(param_2,0,auStack_30);
  if (lVar1 == 0) {
    uVar2 = 1;
    if ((auStack_30[0] & 0x100) == 0) {
      uVar2 = 2;
    }
    *param_3 = (byte)(auStack_30[0] >> 0xc) & 1;
    *param_4 = uVar2;
    if ((auStack_30[0] & 0x2040) == 0x40) {
      *in_t0_lo = 3;
      return 0;
    }
    if ((auStack_30[0] & 0x2040) == 0x2000) {
      *in_t0_lo = 2;
      return 0;
    }
    if ((auStack_30[0] & 0x2040) == 0) {
      *in_t0_lo = 1;
      return 0;
    }
  }
  return 0xffffffffffffffff;
}

