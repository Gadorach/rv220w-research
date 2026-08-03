/*
 * Ghidra reconstructed C; not original Cisco source.
 * Analysis: rv220w-stock-modules-v1.0.0
 * Module: cavium-ethernet
 * Entry: 00105040
 * Function: cvm_ipfwd_setup_entry
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

void cvm_ipfwd_setup_entry(undefined4 *param_1,longlong *param_2)

{
  undefined4 uVar1;
  longlong lVar2;
  ulonglong unaff_s2;
  
  lVar2 = *param_2;
  if ((longlong)*(int *)((int)param_2 + 0x14) != 0) {
    special2((longlong)*(int *)((int)param_2 + 0x14),unaff_s2,7,0x32);
    if (unaff_s2 == 0) {
      (*(code *)&cvmx_warn)(&UNK_0010eae0);
    }
    cvm_ipfwd_ptr_free(unaff_s2 | 0x8000000000000000);
  }
  lVar2 = (longlong)(int)((uint)((ulonglong)lVar2 >> 0x3e) + 1) << 0x3e;
  param_2[1] = lVar2;
  *param_2 = lVar2;
  *(undefined4 *)(param_2 + 3) = 0;
  param_2[2] = lVar2;
  *(undefined1 *)((int)param_2 + 1) = *(undefined1 *)((int)param_1 + 9);
  *(undefined4 *)((int)param_2 + 4) = param_1[3];
  *(undefined4 *)((int)param_2 + 0xc) = param_1[4];
  uVar1 = param_1[(int)(char)((uint)*param_1 >> 0x18) & 0xf];
  *(short *)((int)param_2 + 10) = (short)uVar1;
  *(short *)((int)param_2 + 2) = (short)((uint)uVar1 >> 0x10);
  return;
}

