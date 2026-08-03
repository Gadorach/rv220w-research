/*
 * Ghidra reconstructed C; not original Cisco source.
 * Analysis: rv220w-stock-modules-v1.0.0
 * Module: cavium-ethernet
 * Entry: 00105188
 * Function: local_cavium_ethernet_text_004f78
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
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

longlong local_cavium_ethernet_text_004f78(undefined8 param_1,int param_2)

{
  longlong lVar1;
  longlong lVar2;
  
  lVar2 = -0xc;
  lVar1 = (*(code *)&kmem_cache_alloc)(_single_release,0xd0);
  if (lVar1 != 0) {
    lVar2 = (*(code *)&seq_open)(param_2,0x110d10);
    if (lVar2 == 0) {
      *(longlong *)((int)*(undefined8 *)(param_2 + 0xb8) + 0x50) = lVar1;
      (*(code *)&memset)(lVar1,0,4);
      return 0;
    }
    (*(code *)&kfree)(lVar1);
  }
  return lVar2;
}

