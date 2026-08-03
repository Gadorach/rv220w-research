/*
 * Ghidra reconstructed C; not original Cisco source.
 * Analysis: rv220w-stock-modules-v1.0.0
 * Module: cavium-ethernet
 * Entry: 00100a10
 * Function: allocateCacheMemory
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

undefined8 allocateCacheMemory(void)

{
  int iVar1;
  longlong lVar2;
  longlong lVar3;
  longlong lVar4;
  longlong in_t1;
  
  (*(code *)&printk)(&UNK_0010dd00,0);
  cvm_gbl_ipfwd_cache = (*(code *)&cvmx_bootmem_alloc)(0x54000,0x80);
  (*(code *)&printk)(&UNK_0010dd28);
  lVar4 = 0;
  lVar2 = cvm_gbl_ipfwd_cache;
  if (cvm_gbl_ipfwd_cache == 0) {
    (*(code *)&panic)(&UNK_0010dd58,0x54000);
    if (in_t1 != 0) {
      flushFlowInfo();
    }
    return 0;
  }
  while( true ) {
    lVar3 = 0;
    do {
      iVar1 = (int)lVar2;
      *(undefined8 *)(iVar1 + 8) = 0;
      lVar3 = lVar3 + 1;
      *(undefined8 *)(iVar1 + 0x10) = 0;
      *(undefined8 *)(iVar1 + 0x18) = 0;
      lVar2 = lVar2 + 0x20;
    } while (lVar3 != 5);
    lVar4 = lVar4 + 0xa8;
    if (lVar4 == 0x54000) break;
    lVar2 = lVar4 + cvm_gbl_ipfwd_cache;
  }
  return 0x54000;
}

