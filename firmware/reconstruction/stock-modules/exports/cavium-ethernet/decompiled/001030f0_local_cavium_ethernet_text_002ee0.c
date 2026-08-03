/*
 * Ghidra reconstructed C; not original Cisco source.
 * Analysis: rv220w-stock-modules-v1.0.0
 * Module: cavium-ethernet
 * Entry: 001030f0
 * Function: local_cavium_ethernet_text_002ee0
 * Subsystem: octeon-ethernet
 * Evidence: retained-or-recovered-symbol
 *
 * Embedded Ghidra annotation:
 * RV220W STOCK MODULE SEMANTIC ANNOTATION v1.0.0
 * Module: cavium-ethernet
 * Subsystem: Octeon Ethernet datapath
 * Evidence class: function boundary recovered from MIPS .pdr relocation
 * Confidence: high for boundary; low-to-medium for inferred role
 * Interpretation: Function boundary recovered from the compiler-emitted MIPS .pdr table; the original local function name was stripped. Semantics are constrained by code, data-pointer relocations, imported APIs and referenced strings. See the exported reconstructed C and assembly.
 * Callers: 
 * Callees: 
 * Referenced strings: none recovered
 * Safety note: decompiler output is reconstructed C, not original Cisco source. Register meanings remain hypotheses unless tied to constants, vendor strings, runtime behavior or upstream register definitions.
 */

/* RV220W STOCK MODULE SEMANTIC ANNOTATION v1.0.0
   Module: cavium-ethernet
   Subsystem: Octeon Ethernet datapath
   Evidence class: function boundary recovered from MIPS .pdr relocation
   Confidence: high for boundary; low-to-medium for inferred role
   Interpretation: Function boundary recovered from the compiler-emitted MIPS .pdr table; the
   original local function name was stripped. Semantics are constrained by code, data-pointer
   relocations, imported APIs and referenced strings. See the exported reconstructed C and assembly.
   Callers: 
   Callees: 
   Referenced strings: none recovered
   Safety note: decompiler output is reconstructed C, not original Cisco source. Register meanings
   remain hypotheses unless tied to constants, vendor strings, runtime behavior or upstream register
   definitions.
    */

void local_cavium_ethernet_text_002ee0
               (undefined8 param_1,ulonglong param_2,ulonglong param_3,ulonglong param_4)

{
  int iVar1;
  undefined4 uVar2;
  int unaff_gp_lo;
  
  uRam00001808 = param_4 & 0xffff;
  uRam00001800 = (param_2 & 0x1f) << 8 | param_3 & 0x1f;
  iVar1 = *(int *)(unaff_gp_lo + 0x24);
  while (((ulonglong)(longlong)iVar1 >> 8 & 0xfffff) != 0) {
    setCopReg(2,0x112020,*(undefined4 *)((int)uRam00001808 + 10));
    iVar1 = *(int *)(unaff_gp_lo + 0x24);
  }
  (*(code *)&yield)(0x8001180000001808,0x8001180000001800,uRam000000f8);
  uVar2 = getCopReg(2,0x11);
  *(undefined4 *)((int)uRam00001808 + -8) = uVar2;
  return;
}

