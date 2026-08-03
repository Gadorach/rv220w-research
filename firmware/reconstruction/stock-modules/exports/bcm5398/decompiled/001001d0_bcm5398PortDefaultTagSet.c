/*
 * Ghidra reconstructed C; not original Cisco source.
 * Analysis: rv220w-stock-modules-v1.0.0
 * Module: bcm5398
 * Entry: 001001d0
 * Function: bcm5398PortDefaultTagSet
 * Subsystem: bcm53115-switch
 * Evidence: retained-or-recovered-symbol
 *
 * Embedded Ghidra annotation:
 * RV220W STOCK MODULE SEMANTIC ANNOTATION v1.0.0
 * Module: bcm5398
 * Subsystem: BCM53115 switch/VLAN datapath
 * Evidence class: retained or recovered ELF/source symbol
 * Confidence: high for identity; medium for detailed semantics
 * Interpretation: Programs the per-port default VLAN tag/PVID state used for untagged ingress traffic.
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
   Interpretation: Programs the per-port default VLAN tag/PVID state used for untagged ingress
   traffic.
   Callers: 
   Callees: 
   Referenced strings: none recovered
   Safety note: decompiler output is reconstructed C, not original Cisco source. Register meanings
   remain hypotheses unless tied to constants, vendor strings, runtime behavior or upstream register
   definitions.
    */

undefined8 bcm5398PortDefaultTagSet(undefined8 param_1,uint param_2,uint param_3,uint param_4)

{
  uint in_t0_lo;
  
  miiSwitchRegisterWrite
            (0x34,(param_2 & 0xff) * 2 + 0x10,
             (in_t0_lo & 1) << 0xc | param_3 & 0xfff | (param_4 & 7) << 0xd);
  return 0;
}

