/*
 * Ghidra reconstructed C; not original Cisco source.
 * Analysis: rv220w-stock-modules-v1.0.0
 * Module: cavium-ethernet
 * Entry: 00104c38
 * Function: cvm_ipfwd_find_entry
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

undefined1  [16]
cvm_ipfwd_find_entry(int param_1,undefined4 *param_2,short param_3,ulonglong *param_4)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  ulonglong uVar5;
  ulonglong uVar6;
  ulonglong uVar7;
  ulonglong *puVar8;
  int iVar9;
  longlong lVar10;
  ulonglong unaff_s1;
  undefined1 auVar11 [16];
  
  puVar8 = (ulonglong *)(param_1 + 8);
  lVar10 = 0;
  cVar1 = *(char *)((int)param_2 + 9);
  iVar2 = param_2[3];
  iVar3 = param_2[4];
  iVar4 = param_2[(int)(char)((uint)*param_2 >> 0x18) & 0xf];
  do {
    iVar9 = 4;
    uVar5 = puVar8[1];
    uVar6 = puVar8[2];
    uVar7 = puVar8[3];
    *param_4 = *puVar8;
    param_4[1] = uVar5;
    param_4[2] = uVar6;
    param_4[3] = uVar7;
    do {
      uVar5 = *param_4 >> 0x3e;
      iVar9 = iVar9 + -1;
      if (uVar5 == param_4[2] >> 0x3e) {
        if ((((*(short *)(param_4 + 3) == param_3) && ((int)*param_4 == iVar2)) &&
            (*(int *)((int)param_4 + 0xc) == iVar3)) &&
           ((*(char *)((int)param_4 + 1) == cVar1 &&
            (uVar5 = (ulonglong)*(ushort *)((int)param_4 + 10),
            ((longlong)(int)((uint)*(ushort *)((int)param_4 + 2) << 0x10) | uVar5) ==
            (longlong)iVar4)))) {
          special2((longlong)*(int *)((int)param_4 + 0x14),unaff_s1,7,0x32);
          if ((longlong)*(int *)((int)param_4 + 0x14) != 0) {
            if (unaff_s1 == 0) {
              (*(code *)&cvmx_warn)(&UNK_0010eae0);
            }
            uVar5 = 0xffffffffffffffff;
            prefetch(unaff_s1 & 0x7fffffffffffffff | 0x8000000000000000,0);
          }
          goto code_r0x00104cf8;
        }
        break;
      }
      uVar5 = puVar8[1];
      uVar6 = puVar8[2];
      uVar7 = puVar8[3];
      *param_4 = *puVar8;
      param_4[1] = uVar5;
      param_4[2] = uVar6;
      param_4[3] = uVar7;
    } while (iVar9 != -1);
    lVar10 = (longlong)((int)lVar10 + 1);
    puVar8 = puVar8 + 4;
    if (lVar10 == 5) {
      lVar10 = -1;
code_r0x00104cf8:
      auVar11._0_8_ = lVar10;
      auVar11._8_8_ = uVar5;
      return auVar11;
    }
  } while( true );
}

