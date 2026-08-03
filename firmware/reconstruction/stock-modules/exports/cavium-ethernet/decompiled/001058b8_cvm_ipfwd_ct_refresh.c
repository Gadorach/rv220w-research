/*
 * Ghidra reconstructed C; not original Cisco source.
 * Analysis: rv220w-stock-modules-v1.0.0
 * Module: cavium-ethernet
 * Entry: 001058b8
 * Function: cvm_ipfwd_ct_refresh
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

undefined8 cvm_ipfwd_ct_refresh(int param_1)

{
  ushort uVar1;
  int iVar2;
  undefined8 uVar3;
  longlong lVar4;
  ulonglong uVar5;
  ulonglong unaff_s3;
  
  if (param_1 != 0) {
    iVar2 = *(int *)(param_1 + 0xc0);
    if ((longlong)iVar2 < 1) {
      return 0;
    }
    if (*(char *)(param_1 + 0x106) == '\x06') {
      uVar3 = (*(code *)&tcp_ct_conn_timeout)();
      special2(uVar3,unaff_s3,0,0x3a);
    }
    else {
      if (*(char *)(param_1 + 0x106) != '\x11') {
        return 0;
      }
      uVar3 = (*(code *)&udp_ct_conn_timeout)();
      special2(uVar3,unaff_s3,0,0x3a);
    }
    uVar5 = (longlong)iVar2 & 0xffff;
    if (uVar5 < 0x800) {
      lVar4 = cvm_ipfwd_ct_match_find(param_1 + 0xf8,uVar5 * 0xa8 + cvm_gbl_ipfwd_cache,unaff_s3);
      if (lVar4 != -1) goto code_r0x001059c8;
      uVar1 = *(ushort *)(param_1 + 0xc2);
    }
    else {
      uVar1 = *(ushort *)(param_1 + 0xc2);
    }
    if (((ulonglong)uVar1 < 0x800) &&
       (lVar4 = cvm_ipfwd_ct_match_find
                          (param_1 + 0x118,(ulonglong)uVar1 * 0xa8 + cvm_gbl_ipfwd_cache,unaff_s3),
       lVar4 != -1)) {
code_r0x001059c8:
      (*(code *)&del_timer)(param_1 + 0x18);
      *(ulonglong *)(param_1 + 0x28) = (unaff_s3 & 0xffffffff) + _jiffies;
      if (*(longlong *)(param_1 + 0x18) != 0) {
        trap(0x200);
      }
      (*(code *)&__mod_timer)(param_1 + 0x18,*(undefined8 *)(param_1 + 0x28));
      return 1;
    }
  }
  return 0;
}

