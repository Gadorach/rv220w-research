/*
 * Ghidra reconstructed C; not original Cisco source.
 * Analysis: rv220w-stock-modules-v1.0.0
 * Module: cavium-ethernet
 * Entry: 001049d0
 * Function: cvm_ipfwd_get_free_entry
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

int cvm_ipfwd_get_free_entry(int param_1,undefined8 *param_2)

{
  ulonglong uVar1;
  ulonglong *puVar3;
  undefined8 uVar2;
  undefined8 uVar4;
  longlong lVar5;
  int iVar7;
  undefined8 uVar6;
  int iVar8;
  ulonglong uVar9;
  
  iVar8 = 0;
  uVar9 = 0xffffffffffffffff;
  lVar5 = 0;
  puVar3 = (ulonglong *)(param_1 + 0x18);
  do {
    uVar1 = *puVar3;
    iVar7 = (int)lVar5;
    puVar3 = puVar3 + 4;
    uVar1 = uVar1 >> 0x20 & 0xfffffff;
    lVar5 = lVar5 + 1;
    if (uVar1 < uVar9) {
      uVar9 = uVar1;
      iVar8 = iVar7;
    }
  } while (lVar5 != 5);
  param_1 = iVar8 * 0x20 + param_1;
  uVar2 = *(undefined8 *)(param_1 + 8);
  uVar4 = *(undefined8 *)(param_1 + 0x10);
  uVar6 = *(undefined8 *)(param_1 + 0x18);
  param_2[3] = *(undefined8 *)(param_1 + 0x20);
  *param_2 = uVar2;
  param_2[1] = uVar4;
  param_2[2] = uVar6;
  return iVar8;
}

