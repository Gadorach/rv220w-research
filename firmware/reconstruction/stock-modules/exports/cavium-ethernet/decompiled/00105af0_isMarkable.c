/*
 * Ghidra reconstructed C; not original Cisco source.
 * Analysis: rv220w-stock-modules-v1.0.0
 * Module: cavium-ethernet
 * Entry: 00105af0
 * Function: isMarkable
 * Subsystem: module-support
 * Evidence: retained-or-recovered-symbol
 *
 * Embedded Ghidra annotation:
 * RV220W STOCK MODULE SEMANTIC ANNOTATION v1.0.0
 * Module: cavium-ethernet
 * Subsystem: Module-local support
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
   Subsystem: Module-local support
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

bool isMarkable(undefined4 *param_1)

{
  undefined4 uVar1;
  longlong lVar2;
  bool bVar3;
  undefined2 uStack_20;
  undefined2 uStack_1e;
  
  uVar1 = param_1[(int)(char)((uint)*param_1 >> 0x18) & 0xf];
  uStack_20 = (undefined2)((uint)uVar1 >> 0x10);
  lVar2 = (*(code *)&findInBlockList)(uStack_20);
  bVar3 = false;
  if (lVar2 == 0) {
    uStack_1e = (undefined2)uVar1;
    lVar2 = (*(code *)&findInBlockList)(uStack_1e);
    bVar3 = lVar2 == 0;
  }
  return bVar3;
}

