/*
 * Ghidra reconstructed C; not original Cisco source.
 * Analysis: rv220w-stock-modules-v1.0.0
 * Module: cavium-ethernet
 * Entry: 001015a8
 * Function: cvm_oct_free_work
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

undefined8 cvm_oct_free_work(longlong param_1)

{
  bool bVar1;
  ulonglong uVar2;
  uint uVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  undefined8 *puVar6;
  uint uVar7;
  ulonglong uVar8;
  
  uVar3 = (uint)param_1;
  uVar7 = (uint)*(byte *)(uVar3 + 0x10);
  uVar4 = *(ulonglong *)(uVar3 + 0x18);
  do {
    do {
      uVar7 = uVar7 - 1;
      if (uVar7 == 0xffffffff) {
        uVar7 = 0x3fffffff;
        if (param_1 >> 0x3e != 3) {
          uVar7 = 0xffffffff;
        }
        SYNC(4);
        SYNC(4);
        *(undefined8 *)(uVar3 & uVar7) = 1;
        return 0;
      }
      uVar5 = (uVar4 & 0xffffffffff) - 8 & 0xffffffffff;
      if (uVar5 == 0) {
        (*(code *)&cvmx_warn)(&UNK_0010e120);
      }
      uVar2 = ((uVar4 & 0xffffffffff) >> 7) - (uVar4 >> 0x3b & 0xf) & 0xffffffffff;
      uVar8 = *(ulonglong *)uVar5;
      bVar1 = (longlong)uVar4 < 0;
      uVar5 = uVar2 * 0x80;
      uVar4 = uVar8;
    } while (bVar1);
    uVar8 = uVar5 | 0x8000000000000000;
    if (uVar2 == 0) {
      (*(code *)&cvmx_warn)(&UNK_0010e120);
      uVar8 = 0;
code_r0x00101724:
      puVar6 = (undefined8 *)uVar8;
    }
    else {
      if ((longlong)uVar8 >> 0x3e != 3) goto code_r0x00101724;
      puVar6 = (undefined8 *)((uint)uVar5 & 0x3fffffff);
    }
    SYNC(4);
    SYNC(4);
    *puVar6 = 0x10;
  } while( true );
}

