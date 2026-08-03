/*
 * Ghidra reconstructed C; not original Cisco source.
 * Analysis: rv220w-stock-modules-v1.0.0
 * Module: cavium-ethernet
 * Entry: 00101848
 * Function: local_cavium_ethernet_text_001638
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

ulonglong local_cavium_ethernet_text_001638(undefined8 param_1,ulonglong param_2,ulonglong param_3)

{
  undefined4 uVar1;
  ulonglong uVar2;
  int iVar3;
  
  uVar2 = Status;
  Status = Status & 0xfffffffffffffffe;
  uRam00001800 = (param_2 & 0x1f) << 8 | 0x10000 | param_3 & 0x1f;
  iVar3 = 100000;
  do {
    iVar3 = iVar3 + -1;
    if ((uRam00001810 & 0x20000) == 0) break;
  } while (iVar3 != -1);
  setCopReg(0,Status,(longlong)Status._4_4_ | uVar2 & 1);
  iVar3 = (int)uRam00001810;
  if ((uRam00001810 & 0x20000) == 0) {
    setCopReg(2,uRam00001810,*(undefined4 *)(iVar3 + 0x16));
    return uRam00001810 & 0xffff;
  }
  (*(code *)&printk)(&UNK_0010e2d8,uRam00001810 >> 0x10 & 1,0x20000,uVar2 & 1);
  uVar1 = getCopReg(2,0x10);
  *(undefined4 *)(iVar3 + -0x14) = uVar1;
  return 0;
}

