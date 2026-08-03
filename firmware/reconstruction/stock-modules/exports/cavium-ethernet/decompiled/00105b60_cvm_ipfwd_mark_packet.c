/*
 * Ghidra reconstructed C; not original Cisco source.
 * Analysis: rv220w-stock-modules-v1.0.0
 * Module: cavium-ethernet
 * Entry: 00105b60
 * Function: cvm_ipfwd_mark_packet
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

void cvm_ipfwd_mark_packet(int param_1,int param_2,ulonglong param_3)

{
  undefined1 uVar1;
  int iVar2;
  int iVar3;
  bool bVar4;
  int *piVar5;
  uint uVar6;
  longlong lVar7;
  ulonglong *puVar8;
  longlong lVar9;
  longlong lVar10;
  
  lVar10 = *(longlong *)(param_1 + 0x140);
  lVar9 = lVar10 + (ulonglong)*(byte *)(param_2 + 0x11);
  lVar7 = isMarkable(lVar9);
  if (lVar7 != 0) {
    puVar8 = (ulonglong *)((int)*(undefined8 *)(param_1 + 0x150) + 0x13fU & 0xfffffff8);
    iVar2 = (int)lVar10;
    if (imp_port_enable == 1) {
      bVar4 = *(short *)(iVar2 + 0x10) == -0x7f00;
      *puVar8 = (ulonglong)bVar4;
      if (bVar4) {
        *(uint *)(puVar8 + 4) = (uint)*(ushort *)(iVar2 + 0x12);
      }
    }
    else {
      bVar4 = *(short *)(iVar2 + 0xc) == -0x7f00;
      *puVar8 = (ulonglong)bVar4;
      if (bVar4) {
        *(uint *)(puVar8 + 4) = (uint)*(ushort *)(iVar2 + 0xe);
      }
    }
    *(ushort *)param_3 = (ushort)*(undefined4 *)(param_2 + 0xc) & 0x7ff;
    puVar8[2] = param_3;
    puVar8[1] = 0xfffffffffffedcba;
    piVar5 = (int *)lVar9;
    iVar2 = piVar5[3];
    uVar1 = *(undefined1 *)((int)piVar5 + 9);
    iVar3 = piVar5[4];
    *(short *)((int)puVar8 + 0x26) = (short)*piVar5;
    *(undefined1 *)((int)puVar8 + 0x2d) = uVar1;
    *(int *)(puVar8 + 6) = iVar2;
    *(int *)((int)puVar8 + 0x34) = iVar3;
    puVar8[4] = puVar8[4] & 0xfffffffff0ffffff |
                ((ulonglong)(longlong)*piVar5 >> 0x18 & 0xf) << 0x18;
    uVar6 = (int)(char)((uint)*piVar5 >> 0x18) & 0xf;
    *(int *)((int)puVar8 + uVar6 * 4 + 0x24) = piVar5[uVar6];
    if (*(char *)((int)piVar5 + 9) == '\x06') {
      uVar6 = (int)(char)((uint)*piVar5 >> 0x18) & 0xf;
      *(int *)(puVar8 + 3) = piVar5[uVar6 + 1];
      *(int *)((int)puVar8 + 0x1c) = piVar5[uVar6 + 2];
    }
  }
  return;
}

