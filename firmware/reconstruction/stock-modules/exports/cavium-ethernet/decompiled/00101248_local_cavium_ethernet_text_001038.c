/*
 * Ghidra reconstructed C; not original Cisco source.
 * Analysis: rv220w-stock-modules-v1.0.0
 * Module: cavium-ethernet
 * Entry: 00101248
 * Function: local_cavium_ethernet_text_001038
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

void local_cavium_ethernet_text_001038(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  longlong lVar4;
  longlong lVar5;
  longlong *plVar6;
  longlong lVar7;
  longlong *plVar8;
  int iVar9;
  int iVar10;
  longlong lVar11;
  
  if (iRam001111f0 < 0x28) {
    lVar5 = *(longlong *)(cvm_oct_device + iRam001111f0 * 8);
    if (lVar5 != 0) {
      iVar1 = (int)lVar5;
      if (*(longlong *)(iVar1 + 0x7e8) != 0) {
        (*(code *)*(longlong *)(iVar1 + 0x7e8))();
      }
      if ((((iRam001111f0 < 0x10) || (iRam001111f0 < 0x20)) || (iRam001111f0 < 0x24)) ||
         (iRam001111f0 < 0x28)) {
        iVar9 = 0;
        lVar11 = 0;
        iVar10 = 0;
        do {
          iVar2 = iVar1 + 0x570 + iVar10;
          if ((*(uint *)(iVar2 + 0x10) != 0) &&
             (iVar3 = iVar9 * 4,
             *(uint *)(*(int *)(iVar1 + 0x568) + iVar3 & 0x7ff) < *(uint *)(iVar2 + 0x10))) {
            lVar7 = lVar5 + lVar11 * 0x18 + 0x570;
            do {
              while( true ) {
                plVar8 = (longlong *)lVar7;
                if (lVar7 != *plVar8) break;
                (*(code *)&kfree_skb)(0);
                if (*(uint *)(iVar2 + 0x10) <= *(uint *)(*(int *)(iVar1 + 0x568) + iVar3 & 0x7ff))
                goto LAB_0010141c;
              }
              plVar6 = (longlong *)*plVar8;
              lVar4 = *plVar6;
              *(int *)(plVar8 + 2) = *(int *)(plVar8 + 2) + -1;
              *plVar8 = lVar4;
              *(longlong *)((int)lVar4 + 8) = lVar7;
              *plVar6 = 0;
              plVar6[1] = 0;
              (*(code *)&kfree_skb)();
            } while (*(uint *)(*(int *)(iVar1 + 0x568) + iVar3 & 0x7ff) < *(uint *)(iVar2 + 0x10));
          }
LAB_0010141c:
          iVar9 = iVar9 + 1;
          lVar11 = lVar11 + 1;
          iVar10 = iVar10 + 0x18;
        } while (iVar9 < 1);
      }
      (*(code *)*(undefined8 *)((int)*(undefined8 *)(cvm_oct_device + iRam001111f0 * 8) + 0x78))();
    }
    iRam001111f0 = iRam001111f0 + 1;
    lVar5 = _jiffies + 5;
  }
  else {
    iRam001111f0 = 0;
    lVar5 = _jiffies + 0xfa;
  }
  (*(code *)&mod_timer)(0x1111f8,lVar5);
  return;
}

