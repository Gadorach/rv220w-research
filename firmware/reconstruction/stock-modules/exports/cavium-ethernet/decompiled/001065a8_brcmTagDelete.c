/*
 * Ghidra reconstructed C; not original Cisco source.
 * Analysis: rv220w-stock-modules-v1.0.0
 * Module: cavium-ethernet
 * Entry: 001065a8
 * Function: brcmTagDelete
 * Subsystem: bcm53115-switch
 * Evidence: retained-or-recovered-symbol
 *
 * Embedded Ghidra annotation:
 * RV220W STOCK MODULE SEMANTIC ANNOTATION v1.0.0
 * Module: cavium-ethernet
 * Subsystem: BCM53115 switch/VLAN datapath
 * Evidence class: retained or recovered ELF/source symbol
 * Confidence: high for identity; medium for detailed semantics
 * Interpretation: Removes/parses the vendor Broadcom switch tag from received traffic.
 * Callers: 
 * Callees: 
 * Referenced strings: none recovered
 * Safety note: decompiler output is reconstructed C, not original Cisco source. Register meanings remain hypotheses unless tied to constants, vendor strings, runtime behavior or upstream register definitions.
 */

/* RV220W STOCK MODULE SEMANTIC ANNOTATION v1.0.0
   Module: cavium-ethernet
   Subsystem: BCM53115 switch/VLAN datapath
   Evidence class: retained or recovered ELF/source symbol
   Confidence: high for identity; medium for detailed semantics
   Interpretation: Removes/parses the vendor Broadcom switch tag from received traffic.
   Callers: 
   Callees: 
   Referenced strings: none recovered
   Safety note: decompiler output is reconstructed C, not original Cisco source. Register meanings
   remain hypotheses unless tied to constants, vendor strings, runtime behavior or upstream register
   definitions.
    */

void brcmTagDelete(int param_1)

{
  (*(code *)&memmove)(*(longlong *)(param_1 + 0x140) + 4,*(longlong *)(param_1 + 0x140),0xc);
  *(longlong *)(param_1 + 0x40) = *(longlong *)(param_1 + 0x40) + 4;
  *(longlong *)(param_1 + 0x140) = *(longlong *)(param_1 + 0x140) + 4;
  *(int *)(param_1 + 0x88) = *(int *)(param_1 + 0x88) + -4;
  return;
}

