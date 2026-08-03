/*
 * Ghidra reconstructed C; not original Cisco source.
 * Analysis: rv220w-stock-modules-v1.0.0
 * Module: cavium-ethernet
 * Entry: 00102238
 * Function: local_cavium_ethernet_text_002028
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

undefined1  [16] local_cavium_ethernet_text_002028(longlong param_1)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  longlong lVar4;
  uint *puVar5;
  undefined8 extraout_v1;
  longlong extraout_a0;
  longlong lVar6;
  uint uVar7;
  int iVar8;
  ulonglong *puVar9;
  ulonglong uVar10;
  ulonglong uVar11;
  longlong lVar12;
  undefined1 auVar13 [16];
  undefined1 auVar14 [16];
  undefined1 auVar15 [16];
  undefined1 auVar16 [16];
  undefined1 auVar17 [16];
  uint auStack_e0 [2];
  ulonglong uStack_d8;
  undefined1 auStack_c8 [4];
  uint uStack_c4;
  uint uStack_b4;
  uint uStack_90;
  uint uStack_7c;
  ulonglong uStack_78;
  ushort uStack_70;
  
  lVar4 = param_1 + 0x560;
  iVar2 = (int)param_1;
  lVar6 = (longlong)*(int *)(iVar2 + 0x560);
  puVar5 = (uint *)lVar4;
  if (lVar6 < 0x20) {
    lVar12 = lVar6 >> 4;
LAB_00102264:
    uVar7 = *puVar5;
LAB_00102268:
    bVar1 = lVar12 < 2;
    if ((int)uVar7 < 0x20) {
LAB_00102274:
      bVar1 = lVar12 < 2;
      uVar7 = uVar7 & 0xf;
      goto joined_r0x00102278;
    }
  }
  else {
    if (0x23 < lVar6) {
      lVar12 = 3;
      if (lVar6 < 0x28) goto LAB_00102264;
      lVar12 = 4;
      if (lVar6 != 0x28) {
        (*(code *)&panic)(&UNK_0010e2f8);
        iVar2 = (int)extraout_a0;
        if (0x27 < *(int *)(iVar2 + 0x560)) {
          auVar15._0_8_ = extraout_a0 + 0x6f0;
          auVar15._8_8_ = extraout_v1;
          return auVar15;
        }
        lVar4 = (*(code *)&octeon_is_simulation)();
        if (lVar4 != 0) {
          (*(code *)&memset)(auStack_c8,0,0x60);
          (*(code *)&memset)(auStack_e0,0,0x18);
          goto LAB_00102754;
        }
        uVar7 = *(uint *)(iVar2 + 0x560) & 0x3f;
        iVar3 = uVar7 * 0x50;
        uRama0000018 = 1;
        iVar8 = uVar7 * 0x20;
        uStack_c4 = (uint)((ulonglong)*(undefined8 *)(iVar3 + -0x5ffff800) >> 0x20);
        uStack_90 = (uint)((ulonglong)*(undefined8 *)(iVar3 + -0x5ffff7c8) >> 0x20);
        uStack_b4 = (uint)*(undefined8 *)(iVar3 + -0x5ffff7e8);
        uVar7 = *(uint *)(iVar2 + 0x560);
        uStack_70 = (ushort)*(undefined8 *)(iVar8 + -0x5fffe5f0);
        uStack_7c = (uint)*(undefined8 *)(iVar8 + -0x5fffe600);
        uStack_78 = *(ulonglong *)(iVar8 + -0x5fffe5f8) & 0xffffffffffff;
        uVar10 = (ulonglong)(int)uVar7;
        auStack_e0[0] = (uint)uRam50001080;
        uRam50001080 = uRam50001080 & 0xffffffff00000000 | (ulonglong)uVar7;
        uStack_d8 = uRam50001088 & 0xffffffffffff;
        uRam50001088 = uRam50001088 & 0xffff000000000000 | (longlong)(int)uVar7 & 0xffffffffffffU;
        if ((uint)((ulonglong)((longlong)PRId << 0x28) >> 0x2e) << 6 < 0xd0300) {
          if (0xf < (longlong)uVar10) {
            uRam50000008 = uVar10 & 0xff;
            if ((uVar7 - 0x10 < 0x10) || (uRam50000008 = uVar10 & 0xff, uVar7 - 0x20 < 4))
            goto LAB_00102754;
            if (3 < uVar7 - 0x24) {
              uRam50000008 = 0xff;
              goto LAB_00102754;
            }
          }
          uRam50000008 = uVar10 & 0xff;
          goto LAB_00102754;
        }
        if ((0xf < (longlong)uVar10) && (0xf < uVar7 - 0x10)) {
          uRam50000008 = uVar10 & 0xff;
          if (uVar7 - 0x20 < 4) goto LAB_00102754;
          if (3 < uVar7 - 0x24) {
            uRam50000008 = 0xff;
            goto LAB_00102754;
          }
        }
        uRam50000008 = uVar10 & 0xff;
LAB_00102754:
        *(ulonglong *)(iVar2 + 0x6f0) = *(longlong *)(iVar2 + 0x6f0) + (ulonglong)uStack_7c;
        auVar17._8_8_ =
             CONCAT71(0,0xd02ff < (uint)((ulonglong)((longlong)PRId << 0x28) >> 0x2e) << 6);
        *(ulonglong *)(iVar2 + 0x6f8) = *(longlong *)(iVar2 + 0x6f8) + (ulonglong)auStack_e0[0];
        *(ulonglong *)(iVar2 + 0x700) = *(longlong *)(iVar2 + 0x700) + uStack_78;
        *(ulonglong *)(iVar2 + 0x708) = *(longlong *)(iVar2 + 0x708) + uStack_d8;
        *(ulonglong *)(iVar2 + 0x730) = *(longlong *)(iVar2 + 0x730) + (ulonglong)uStack_b4;
        *(ulonglong *)(iVar2 + 0x750) = *(longlong *)(iVar2 + 0x750) + (ulonglong)uStack_70;
        *(ulonglong *)(iVar2 + 0x758) = *(longlong *)(iVar2 + 0x758) + (ulonglong)uStack_90;
        if (auVar17._8_8_ != 0) {
          special2(extraout_a0 + 0x720,(ulonglong)uStack_c4,0,0x19);
          auVar17._0_8_ = extraout_a0 + 0x6f0;
          return auVar17;
        }
        *(ulonglong *)(iVar2 + 0x720) = *(longlong *)(iVar2 + 0x720) + (ulonglong)uStack_c4;
        auVar16._0_8_ = extraout_a0 + 0x6f0;
        auVar16._8_8_ = 1;
        return auVar16;
      }
      uVar7 = *puVar5;
      goto LAB_00102268;
    }
    uVar7 = *puVar5;
    lVar12 = 2;
    if ((int)uVar7 < 0x20) goto LAB_00102274;
    bVar1 = false;
  }
  uVar7 = uVar7 & 3;
joined_r0x00102278:
  if (bVar1) {
    lVar6 = (*(code *)&cvmx_helper_interface_get_mode)(lVar12);
    lVar4 = 3;
    special2(lVar6,lVar6,0,0x3a);
    if (lVar6 != 3) {
      if ((*(longlong *)(iVar2 + 0xe0) == 0) && ((*(ulonglong *)(iVar2 + 0x98) >> 0x28 & 3) == 0)) {
        uVar10 = 3;
      }
      else {
        uVar10 = 5;
      }
      if ((*(uint *)(iVar2 + 0x98) & 0x100) == 0) {
        uVar10 = uVar10 | 8;
      }
      special2(lVar12,3,0x10,0x32);
      iVar3 = ((uVar7 & 3) + 3) * 0x800;
      puVar9 = (ulonglong *)(iVar3 + 0x8000010);
      uVar11 = *puVar9;
      *puVar9 = uVar11 & 0xfffffffffffffffe;
      *(ulonglong *)(iVar3 + 0x8000100) = uVar10;
      if ((*(uint *)(iVar2 + 0x98) & 0x100) == 0) {
        *(undefined8 *)(iVar3 + 0x8000108) = 1;
      }
      else {
        *(undefined8 *)(iVar3 + 0x8000108) = 0;
      }
      *puVar9 = uVar11;
      auVar14._0_8_ = 0x80011800000000f8;
      auVar14._8_8_ = uRam000000f8;
      return auVar14;
    }
  }
  else {
    lVar6 = 0;
  }
  auVar13._0_8_ = lVar6;
  auVar13._8_8_ = lVar4;
  return auVar13;
}

