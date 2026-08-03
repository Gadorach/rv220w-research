/*
 * Ghidra reconstructed C; not original Cisco source.
 * Analysis: rv220w-stock-modules-v1.0.0
 * Module: cavium-ethernet
 * Entry: 001035e8
 * Function: cvm_oct_fill_hw_memory
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

ulonglong cvm_oct_fill_hw_memory(ulonglong param_1,int param_2,int param_3)

{
  int iVar1;
  ulonglong uVar2;
  longlong lVar3;
  ulonglong uVar4;
  undefined8 extraout_a0;
  undefined8 extraout_a1;
  
  uVar2 = 0xffffffffffffffff;
  param_3 = param_3 + -1;
  if (param_3 != -1) {
    do {
      while( true ) {
        lVar3 = (*(code *)&__kmalloc)(param_2 + 0x7f,0x20);
        uVar4 = lVar3 + 0x7f;
        if ((uVar4 & 0xffffffffffffff80) == 0) {
          (*(code *)&panic)(&UNK_0010e438,param_2 * param_3,param_1);
          iVar1 = (int)extraout_a0;
          (*(code *)*(undefined8 *)(iVar1 + 2000))();
          lVar3 = (*(code *)*(undefined8 *)(iVar1 + 0x7c8))(extraout_a0,extraout_a1,0x1e);
          uVar2 = (*(code *)*(undefined8 *)(iVar1 + 0x7c8))(extraout_a0,extraout_a1,0x1f);
          return lVar3 << 0x10 | uVar2;
        }
        if ((longlong)uVar4 >> 0x3e != 3) break;
        SYNC(4);
        SYNC(4);
        *(undefined8 *)(uVar4 & 0x3fffff80) = 0;
        param_3 = param_3 + -1;
        if (param_3 == -1) {
          return uVar4 & 0x3fffff80 | (param_1 | 0x800128) << 0x28;
        }
      }
      uVar2 = uVar4 & 0xffffffff80 | (param_1 | 0x800128) << 0x28;
      SYNC(4);
      SYNC(4);
      *(undefined8 *)(uVar4 & 0xffffffff80) = 0;
      param_3 = param_3 + -1;
    } while (param_3 != -1);
  }
  return uVar2;
}

