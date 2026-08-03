/*
 * Ghidra reconstructed C; not original Cisco source.
 * Analysis: rv220w-stock-modules-v1.0.0
 * Module: cavium-ethernet
 * Entry: 00105f80
 * Function: cvm_ipfwd_cache_flow
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

undefined8 cvm_ipfwd_cache_flow(int param_1,undefined8 param_2,ulonglong param_3)

{
  longlong *plVar1;
  int iVar2;
  uint uVar3;
  longlong lVar4;
  ulonglong uVar5;
  longlong lVar6;
  ulonglong uVar7;
  undefined4 *puVar8;
  longlong lVar9;
  longlong lVar10;
  int iVar11;
  undefined8 in_HW_RESIM31;
  undefined8 uStack_60;
  undefined8 uStack_58;
  undefined8 uStack_50;
  undefined2 uStack_48;
  ushort uStack_46;
  undefined4 uStack_44;
  
  if (imp_port_enable == 1) {
    iVar11 = (int)*(undefined8 *)(param_1 + 0x140);
    if (*(short *)(iVar11 + 0x10) == -0x7f00) {
      puVar8 = (undefined4 *)(iVar11 + 0x16);
    }
    else {
      puVar8 = (undefined4 *)(iVar11 + 0x12);
    }
  }
  else {
    iVar11 = (int)*(undefined8 *)(param_1 + 0x140);
    puVar8 = (undefined4 *)(iVar11 + 0x12);
    if (*(short *)(iVar11 + 0xc) != -0x7f00) {
      puVar8 = (undefined4 *)(iVar11 + 0xe);
    }
  }
  plVar1 = (longlong *)param_3;
  uVar3 = (int)(char)((uint)*puVar8 >> 0x18) & 0xf;
  if (plVar1[1] != -0x12346) {
    return 0;
  }
  lVar10 = plVar1[2];
  lVar9 = param_3 + 0x24;
  if (lVar10 == 0) {
    return 0;
  }
  if (*(short *)((int)plVar1 + 0x26) != *(short *)((int)puVar8 + 2)) {
    return 0;
  }
  if (*(char *)((int)puVar8 + 9) == '\x06') {
    if (*(int *)(plVar1 + 3) != puVar8[uVar3 + 1]) {
      return 0;
    }
    if (*(int *)((int)plVar1 + 0x1c) != puVar8[uVar3 + 2]) {
      return 0;
    }
    lVar4 = *plVar1;
  }
  else {
    lVar4 = *plVar1;
  }
  if (lVar4 == 0) {
    lVar4 = cvm_ipfwd_find_entry(lVar10,lVar9,0,&uStack_60);
  }
  else {
    lVar4 = cvm_ipfwd_find_entry(lVar10,lVar9,*(undefined2 *)((int)plVar1 + 0x22),&uStack_60);
  }
  if (lVar4 == -1) {
    lVar4 = cvm_ipfwd_get_free_entry(lVar10,&uStack_60);
    iVar11 = (int)lVar4;
    lVar6 = cvm_ipfwd_check_timestamp_just_created(uStack_50 >> 0x20 & 0xfffffff);
    if (lVar6 != 0) {
      return 0;
    }
    cvm_ipfwd_setup_entry(lVar9,&uStack_60);
    uStack_46 = *(ushort *)plVar1[2];
    if (*(longlong *)(param_1 + 0xb0) != 0) {
      iVar2 = (int)*(longlong *)(param_1 + 0xb0);
      if ((int)*(uint *)(iVar2 + 0xc0) < 1) {
        *(uint *)(iVar2 + 0xc0) = (uint)uStack_46;
      }
      else {
        *(uint *)(iVar2 + 0xc0) = (uint)uStack_46 << 0x10 | *(uint *)(iVar2 + 0xc0);
      }
    }
    if (*plVar1 != 0) {
      uStack_48 = (undefined2)*(undefined4 *)(plVar1 + 4);
    }
    if (uStack_50._4_4_ != 0) goto code_r0x00106150;
  }
  else {
    lVar9 = cvm_ipfwd_check_timestamp(uStack_50 >> 0x20 & 0xfffffff);
    if (lVar9 == 1) {
      return 0;
    }
    if ((longlong)uStack_50._4_4_ != 0) {
      special2((longlong)uStack_50._4_4_,param_3,7,0x32);
      if (param_3 == 0) {
        (*(code *)&cvmx_warn)(&UNK_0010eae0);
      }
      cvm_ipfwd_ptr_free(param_3 | 0x8000000000000000);
      uStack_50 = uStack_50 & 0xffffffff00000000;
    }
  }
  iVar11 = (int)lVar4;
  uVar5 = cvm_ipfwd_ptr_alloc();
  if (uVar5 == 0) {
    (*(code *)&cvmx_warn)(&UNK_0010eb10);
    uVar7 = 0;
  }
  else {
    uVar7 = uVar5 >> 7 & 0x7fffff;
    if ((longlong)uVar5 >> 0x3e != 3) {
      special2(uVar5,uVar7,7,0x3a);
    }
  }
  uStack_50 = CONCAT44(uStack_50._0_4_,(int)uVar7);
  if (uVar7 == 0) {
    lVar9 = (*(code *)&__printk_ratelimit)(0xfa,10);
    if (lVar9 == 0) {
      return 0;
    }
    (*(code *)&printk)(&UNK_0010ecc8,&UNK_0010da08);
    return 0;
  }
  special2(uVar7,param_3,7,0x32);
  if (param_3 == 0) {
    (*(code *)&cvmx_warn)(&UNK_0010eae0);
  }
  cvm_ipfwd_setup_flow_info(param_3 | 0x8000000000000000,param_1,param_2);
code_r0x00106150:
  uVar5 = getHWRegister(in_HW_RESIM31);
  special2(uVar5,uVar5,0x1b,0x3a);
  special2(uVar5,uVar5,0,0x33);
  iVar11 = iVar11 * 0x20 + (int)lVar10;
  *(ulonglong *)(iVar11 + 0x20) = CONCAT44(CONCAT22(uStack_48,uStack_46),uStack_44);
  *(undefined8 *)(iVar11 + 8) = uStack_60;
  *(undefined8 *)(iVar11 + 0x10) = uStack_58;
  *(ulonglong *)(iVar11 + 0x18) = uStack_50 & 0xf0000000ffffffff | uVar5;
  return 0;
}

