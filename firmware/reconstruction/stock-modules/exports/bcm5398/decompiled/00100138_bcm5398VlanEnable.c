/*
 * Ghidra reconstructed C; not original Cisco source.
 * Analysis: rv220w-stock-modules-v1.0.0
 * Module: bcm5398
 * Entry: 00100138
 * Function: bcm5398VlanEnable
 * Subsystem: bcm53115-switch
 * Evidence: retained-or-recovered-symbol
 *
 * Embedded Ghidra annotation:
 * RV220W STOCK MODULE SEMANTIC ANNOTATION v1.0.0
 * Module: bcm5398
 * Subsystem: BCM53115 switch/VLAN datapath
 * Evidence class: retained or recovered ELF/source symbol
 * Confidence: high for identity; medium for detailed semantics
 * Interpretation: Enables IEEE 802.1Q VLAN processing in the Broadcom switch through the module's MII register-access layer.
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
   Interpretation: Enables IEEE 802.1Q VLAN processing in the Broadcom switch through the module's
   MII register-access layer.
   Callers: 
   Callees: 
   Referenced strings: none recovered
   Safety note: decompiler output is reconstructed C, not original Cisco source. Register meanings
   remain hypotheses unless tied to constants, vendor strings, runtime behavior or upstream register
   definitions.
    */

undefined8 bcm5398VlanEnable(void)

{
  miiSwitchRegisterWrite(0x34,0,0xe2);
  miiSwitchRegisterWrite(0x34,1,2);
  miiSwitchRegisterWrite(0x34,2,0x70);
  miiSwitchRegisterWrite(0x34,3,0);
  miiSwitchRegisterWrite(0x34,5,0x70);
  miiSwitchRegisterWrite(0x34,6,0x10);
  return 0;
}

