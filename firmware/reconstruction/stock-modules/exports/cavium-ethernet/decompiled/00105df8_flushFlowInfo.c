/*
 * Ghidra reconstructed C; not original Cisco source.
 * Analysis: rv220w-stock-modules-v1.0.0
 * Module: cavium-ethernet
 * Entry: 00105df8
 * Function: flushFlowInfo
 * Subsystem: octeon-offload
 * Evidence: retained-or-recovered-symbol
 *
 * Embedded Ghidra annotation:
 * RV220W STOCK MODULE SEMANTIC ANNOTATION v1.0.0
 * Module: cavium-ethernet
 * Subsystem: Octeon hardware-offload/fast-forward path
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
   Subsystem: Octeon hardware-offload/fast-forward path
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

void flushFlowInfo(void)

{
  undefined8 *puVar1;
  longlong lVar2;
  ulonglong unaff_s1;
  longlong lVar3;
  longlong lVar4;
  
  lVar4 = 0;
  (*(code *)&printk)(&UNK_0010ecb0);
  cvm_ipfwd_ptr_flush();
  do {
    lVar3 = 0;
    lVar2 = lVar4 + cvm_gbl_ipfwd_cache + 8;
    do {
      puVar1 = (undefined8 *)lVar2;
      lVar3 = lVar3 + 1;
      if ((longlong)*(int *)((int)puVar1 + 0x14) != 0) {
        special2((longlong)*(int *)((int)puVar1 + 0x14),unaff_s1,7,0x32);
        if (unaff_s1 == 0) {
          (*(code *)&cvmx_warn)(&UNK_0010eae0);
        }
        cvm_ipfwd_ptr_free(unaff_s1 | 0x8000000000000000);
      }
      *(undefined4 *)((int)puVar1 + 0x14) = 0;
      *puVar1 = 0;
      puVar1[1] = 0;
      puVar1[2] = 0;
      lVar2 = lVar2 + 0x20;
    } while (lVar3 != 5);
    lVar4 = lVar4 + 0xa8;
  } while (lVar4 != 0x54000);
  return;
}

