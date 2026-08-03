/*
 * Ghidra reconstructed C; not original Cisco source.
 * Analysis: rv220w-stock-modules-v1.0.0
 * Module: cavium-ethernet
 * Entry: 00109ff8
 * Function: cvm_oct_tx_shutdown
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

void cvm_oct_tx_shutdown(longlong param_1)

{
  longlong *plVar1;
  ulonglong uVar2;
  int iVar3;
  longlong lVar4;
  longlong *plVar5;
  longlong lVar6;
  longlong lVar7;
  
  lVar7 = 0;
  do {
    uVar2 = Status;
    Status = Status & 0xfffffffffffffffe;
    lVar6 = lVar7 + param_1 + 0x570;
    plVar1 = (longlong *)lVar6;
    iVar3 = *(int *)(plVar1 + 2);
    if (iVar3 != 0) {
      lVar4 = *plVar1;
      while( true ) {
        if (lVar6 == lVar4) {
          (*(code *)&dev_kfree_skb_any)(0);
          iVar3 = *(int *)(plVar1 + 2);
        }
        else {
          plVar5 = (longlong *)lVar4;
          lVar4 = *plVar5;
          *(int *)(plVar1 + 2) = iVar3 + -1;
          *plVar1 = lVar4;
          *(longlong *)((int)lVar4 + 8) = lVar6;
          *plVar5 = 0;
          plVar5[1] = 0;
          (*(code *)&dev_kfree_skb_any)();
          iVar3 = *(int *)(plVar1 + 2);
        }
        if (iVar3 == 0) break;
        lVar4 = *plVar1;
      }
    }
    setCopReg(0,Status,(longlong)Status._4_4_ & 0xfffffffffffffffeU | uVar2 & 1);
    lVar7 = lVar7 + 0x18;
  } while (lVar7 != 0x180);
  return;
}

