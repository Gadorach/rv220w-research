/*
 * Ghidra reconstructed C; not original Cisco source.
 * Analysis: rv220w-stock-modules-v1.0.0
 * Module: cavium-ethernet
 * Entry: 00104db8
 * Function: cvm_ipfwd_ct_match_find
 * Subsystem: octeon-offload
 * Evidence: retained-or-recovered-symbol
 *
 * Embedded Ghidra annotation:
 * RV220W STOCK MODULE SEMANTIC ANNOTATION v1.0.0
 * Module: cavium-ethernet
 * Subsystem: Octeon hardware-offload/fast-forward path
 * Evidence class: retained or recovered ELF/source symbol
 * Confidence: high for identity; medium for detailed semantics
 * Interpretation: Vendor hardware-offload/fast-forward support. This is not required for initial upstream OpenWrt bring-up and should remain disabled until independently validated.
 * Callers: 
 * Callees: 
 * Referenced strings: none recovered
 * Safety note: decompiler output is reconstructed C, not original Cisco source. Register meanings remain hypotheses unless tied to constants, vendor strings, runtime behavior or upstream register definitions.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* RV220W STOCK MODULE SEMANTIC ANNOTATION v1.0.0
   Module: cavium-ethernet
   Subsystem: Octeon hardware-offload/fast-forward path
   Evidence class: retained or recovered ELF/source symbol
   Confidence: high for identity; medium for detailed semantics
   Interpretation: Vendor hardware-offload/fast-forward support. This is not required for initial
   upstream OpenWrt bring-up and should remain disabled until independently validated.
   Callers: 
   Callees: 
   Referenced strings: none recovered
   Safety note: decompiler output is reconstructed C, not original Cisco source. Register meanings
   remain hypotheses unless tied to constants, vendor strings, runtime behavior or upstream register
   definitions.
    */

undefined4 cvm_ipfwd_ct_match_find(int *param_1,int param_2,ulonglong param_3)

{
  char cVar1;
  short sVar2;
  short sVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  longlong lVar7;
  undefined4 uVar8;
  
  lVar7 = 0;
  param_2 = param_2 + 8;
  sVar2 = *(short *)(param_1 + 3);
  iVar4 = *param_1;
  iVar5 = param_1[2];
  cVar1 = *(char *)((int)param_1 + 0xe);
  sVar3 = *(short *)(param_1 + 1);
  do {
    uVar8 = (undefined4)lVar7;
    lVar7 = lVar7 + 1;
    if ((((*(int *)(param_2 + 4) == iVar4) && (*(int *)(param_2 + 0xc) == iVar5)) &&
        (*(char *)(param_2 + 1) == cVar1)) &&
       ((*(short *)(param_2 + 2) == sVar3 && (*(short *)(param_2 + 10) == sVar2)))) {
      iVar6 = *(int *)(param_2 + 0x14);
      if (iVar6 == 0) {
        (*(code *)&cvmx_warn)(&UNK_0010eae0);
      }
      if ((ulonglong)(_jiffies - *(longlong *)(iVar6 * 0x80 + 0x28)) < (param_3 & 0xffffffff)) {
        return uVar8;
      }
    }
    param_2 = param_2 + 0x20;
    if (lVar7 == 5) {
      return 0xffffffff;
    }
  } while( true );
}

