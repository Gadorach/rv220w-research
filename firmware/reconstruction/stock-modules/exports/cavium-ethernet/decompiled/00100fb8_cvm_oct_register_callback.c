/*
 * Ghidra reconstructed C; not original Cisco source.
 * Analysis: rv220w-stock-modules-v1.0.0
 * Module: cavium-ethernet
 * Entry: 00100fb8
 * Function: cvm_oct_register_callback
 * Subsystem: octeon-ethernet
 * Evidence: retained-or-recovered-symbol
 *
 * Embedded Ghidra annotation:
 * RV220W STOCK MODULE SEMANTIC ANNOTATION v1.0.0
 * Module: cavium-ethernet
 * Subsystem: Octeon Ethernet datapath
 * Evidence class: retained or recovered ELF/source symbol
 * Confidence: high for identity; medium for detailed semantics
 * Interpretation: Semantics inferred conservatively from the retained source symbol, direct callers/callees, imported APIs and referenced strings. See the per-function exports for evidence.
 * Callers: 
 * Callees: 
 * Referenced strings: none recovered
 * Safety note: decompiler output is reconstructed C, not original Cisco source. Register meanings remain hypotheses unless tied to constants, vendor strings, runtime behavior or upstream register definitions.
 */

/* RV220W STOCK MODULE SEMANTIC ANNOTATION v1.0.0
   Module: cavium-ethernet
   Subsystem: Octeon Ethernet datapath
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

undefined8 cvm_oct_register_callback(undefined8 param_1,undefined8 param_2)

{
  longlong lVar1;
  int iVar2;
  undefined1 *puVar3;
  undefined8 *puVar4;
  
  puVar3 = cvm_oct_device;
  iVar2 = 0;
  puVar4 = (undefined8 *)puVar3;
  while( true ) {
    lVar1 = *(longlong *)puVar3;
    iVar2 = iVar2 + 1;
    puVar3 = (undefined1 *)((int)puVar3 + 8);
    if ((lVar1 != 0) && (lVar1 = (*(code *)&strcmp)(param_1), lVar1 == 0)) break;
    puVar4 = puVar4 + 1;
    if (iVar2 == 0x29) {
      return 0;
    }
  }
  *(undefined8 *)((int)*puVar4 + 0x7d8) = param_2;
  SYNC(4);
  SYNC(4);
  return *puVar4;
}

