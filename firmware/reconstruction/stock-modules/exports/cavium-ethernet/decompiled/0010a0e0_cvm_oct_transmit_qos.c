/*
 * Ghidra reconstructed C; not original Cisco source.
 * Analysis: rv220w-stock-modules-v1.0.0
 * Module: cavium-ethernet
 * Entry: 0010a0e0
 * Function: cvm_oct_transmit_qos
 * Subsystem: octeon-ethernet
 * Evidence: retained-or-recovered-symbol
 *
 * Embedded Ghidra annotation:
 * RV220W STOCK MODULE SEMANTIC ANNOTATION v1.0.0
 * Module: cavium-ethernet
 * Subsystem: Octeon Ethernet datapath
 * Evidence class: retained or recovered ELF/source symbol
 * Confidence: high for identity; medium for detailed semantics
 * Interpretation: Transmit datapath routine, including queue/QoS or POW handling according to the selected entry point.
 * Callers: 
 * Callees: 
 * Referenced strings: none recovered
 * Safety note: decompiler output is reconstructed C, not original Cisco source. Register meanings remain hypotheses unless tied to constants, vendor strings, runtime behavior or upstream register definitions.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* RV220W STOCK MODULE SEMANTIC ANNOTATION v1.0.0
   Module: cavium-ethernet
   Subsystem: Octeon Ethernet datapath
   Evidence class: retained or recovered ELF/source symbol
   Confidence: high for identity; medium for detailed semantics
   Interpretation: Transmit datapath routine, including queue/QoS or POW handling according to the
   selected entry point.
   Callers: 
   Callees: 
   Referenced strings: none recovered
   Safety note: decompiler output is reconstructed C, not original Cisco source. Register meanings
   remain hypotheses unless tied to constants, vendor strings, runtime behavior or upstream register
   definitions.
    */

undefined8 cvm_oct_transmit_qos(int param_1,longlong param_2,longlong param_3)

{
  bool bVar1;
  byte bVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  ulonglong uVar6;
  uint uVar7;
  ulonglong uVar8;
  undefined8 in_zero;
  longlong lVar9;
  int *piVar10;
  ulonglong *puVar11;
  ulonglong uVar12;
  longlong lVar13;
  longlong extraout_v1;
  ulonglong uVar14;
  ulonglong uVar15;
  ulonglong extraout_a0;
  undefined8 uVar16;
  ulonglong uVar17;
  ulonglong uVar18;
  ulonglong *puVar19;
  byte *pbVar20;
  ulonglong unaff_s2;
  ulonglong unaff_s3;
  ulonglong uVar21;
  
  setCopReg(2,in_zero,*(undefined4 *)(*(int *)(param_1 + 0x98) + 0xdf));
  lVar9 = (*(code *)&strncmp)(param_1,&UNK_0010f710,4);
  if (lVar9 != 0) {
    (*(code *)&strncmp)(param_1,&UNK_0010f718,3);
  }
  uVar8 = Status;
  Status = Status & 0xfffffffffffffffe;
  uVar7 = (uint)param_2;
  special2(0xffffffffffffffff,unaff_s2,2,0x33);
  uVar15 = (ulonglong)(param_3 == 0) << 0x16;
  uVar14 = *(ulonglong *)(uVar7 + 0x18);
  uVar21 = ((ulonglong)*(byte *)(uVar7 + 0x10) & 0x3f) << 0x10;
  uVar12 = (ulonglong)*(ushort *)(uVar7 + 8);
  special2(0xffffffffffffffff,unaff_s3,0x13,0x33);
  if ((*(ulonglong *)(uVar7 + 0x10) & 0x1200) == 0) {
    if (*(char *)(uVar7 + 0x11) == '\x12') {
      uVar12 = unaff_s2 & 0xffffffff80800000 | uVar15 | uVar21 | uVar12 | 0x13000000;
    }
    else if (*(char *)(uVar7 + 0x11) == '\x16') {
      lVar9 = (*(code *)&strncmp)(param_1,&UNK_0010f710,4);
      if (lVar9 == 0) {
        uVar12 = unaff_s2 & 0xffffffff80800000 | uVar15 | uVar21 | uVar12 | 0x17000000;
      }
      else {
        lVar9 = (*(code *)&strncmp)(param_1,&UNK_0010f718,3);
        if (lVar9 != 0) goto code_r0x0010a1c4;
        uVar12 = unaff_s2 & 0xffffffff80800000 | uVar15 | uVar21 | uVar12 | 0x17000000;
      }
    }
    else {
code_r0x0010a1c4:
      uVar12 = unaff_s2 & 0xffffffff80800000 | uVar15 | uVar21 | uVar12 | 0xf000000;
    }
  }
  else {
    uVar12 = unaff_s2 & 0xffffffff80800000 | uVar15 | uVar21 | uVar12;
  }
  uVar3 = *(uint *)(param_1 + 0x564);
  uVar21 = unaff_s3 & 0x87ffff0000000000 | uVar14 & 0xffffffffff | (uVar14 >> 0x3b & 0xf) << 0x3b;
  uVar15 = (longlong)(int)uVar3 & 0xffff;
  uVar4 = *(uint *)(param_1 + 0x560);
  if ((uVar15 < 0x100) &&
     (lVar9 = ___cvmx_cmd_queue_state_ptr +
              (longlong)(int)(((uint)(uVar15 >> 4) & 0xf) + (uVar3 & 0xf) * 0x10) * 0x10 + 0x2800,
     lVar9 != 0)) {
    prefetch(lVar9,0);
    piVar10 = (int *)((((uint)(uVar15 >> 4) & 0xf) + (uVar3 & 0xf) * 0x10) * 8 +
                     (int)___cvmx_cmd_queue_state_ptr);
    iVar5 = *piVar10;
    uVar14 = (ulonglong)iVar5;
    uVar16 = special2(1,uVar14,0,0x28);
    *piVar10 = (int)uVar16;
    uVar15 = uRam00000000;
    pbVar20 = (byte *)lVar9;
    bVar2 = *pbVar20;
    while (bVar2 != uVar14) {
      lVar9 = (longlong)(int)((iVar5 - (uint)bVar2) + -1);
      special2(lVar9,lVar9,5,0x32);
      do {
        bVar1 = lVar9 != 0;
        lVar9 = (longlong)((int)lVar9 + -1);
      } while (bVar1);
      bVar2 = *pbVar20;
    }
    uVar17 = *(ulonglong *)(pbVar20 + 8);
    uVar6 = uVar17 >> 0x20 & 0x1fffffff;
    if ((ulonglong)(longlong)(int)(((uint)uVar17 & 0x1fff) + 2) < (uVar17 >> 0xd & 0x1fff)) {
      if (uVar6 == 0) {
        (*(code *)&cvmx_warn)(&UNK_0010f720);
        uVar17 = *(ulonglong *)(pbVar20 + 8);
        uVar14 = extraout_a0;
      }
      special2(uVar17,uVar14,3,0x32);
      puVar11 = (ulonglong *)((int)uVar6 * 0x80 + (int)uVar14);
      *(ulonglong *)(pbVar20 + 8) = uVar17 & 0xffffffffffffe000 | uVar17 + 2 & 0x1fff;
      puVar11[1] = uVar21;
      *puVar11 = uVar12;
code_r0x0010a2e0:
      *pbVar20 = *pbVar20 + 1;
      SYNC(4);
      SYNC(4);
      SYNC(4);
      SYNC(4);
      uVar16 = 0;
      *(undefined8 *)((uVar4 & 0x3f) << 0xc | (uint)(((longlong)(int)uVar3 & 0x1ffU) << 3)) = 2;
      bVar1 = false;
      goto code_r0x0010a324;
    }
    if (uRam00000000 != 0) {
      uVar6 = uRam00000000 & 0x7fffffffffffffff;
      uVar18 = uVar6 | 0x8000000000000000;
      uVar14 = uVar17 >> 0x20 & 0x1fffffff;
      if (uVar18 != 0) {
        lVar13 = (longlong)(int)((((uint)(uVar17 >> 0xd) & 0x1fff) - ((uint)uVar17 & 0x1fff)) + -1);
        lVar9 = lVar13;
        if (uVar14 == 0) {
          (*(code *)&cvmx_warn)(&UNK_0010f720);
          uVar17 = *(ulonglong *)(pbVar20 + 8);
          lVar9 = extraout_v1;
        }
        special2(uVar17,lVar9,3,0x32);
        puVar11 = (ulonglong *)((int)uVar14 * 0x80 + (int)lVar9);
        *puVar11 = uVar12;
        puVar19 = puVar11 + 1;
        if (lVar13 != 0) {
          puVar11[1] = uVar21;
          puVar19 = puVar11 + 2;
        }
        if (uVar18 == 0) {
          (*(code *)&cvmx_warn)(&UNK_0010f750,uVar17);
          uVar12 = 0;
        }
        else {
          uVar12 = uVar15 & 0x3fffffff;
          if ((longlong)uVar18 >> 0x3e != 3) {
            uVar12 = uVar15 & 0xffffffffff;
          }
        }
        *puVar19 = uVar12;
        special2(uVar12,uVar12,7,0x3a);
        special2(uVar12,uVar12,0,0x33);
        uVar15 = (*(ulonglong *)(pbVar20 + 8) & 0xe0000000ffffffff | uVar12) & 0xffffffffffffe000;
        *(ulonglong *)(pbVar20 + 8) = uVar15;
        if (lVar13 == 0) {
          *(ulonglong *)(pbVar20 + 8) = uVar15 | 1;
          *(ulonglong *)uVar6 = uVar21;
        }
        goto code_r0x0010a2e0;
      }
    }
    *pbVar20 = *pbVar20 + 1;
    SYNC(4);
    SYNC(4);
  }
  lVar9 = (*(code *)&__printk_ratelimit)(0xfa,10);
  if (lVar9 == 0) {
    uVar16 = 0xffffffffffffffff;
    bVar1 = true;
  }
  else {
    uVar16 = 0xffffffffffffffff;
    (*(code *)&printk)(&UNK_0010f780,param_1);
    bVar1 = true;
  }
code_r0x0010a324:
  setCopReg(0,Status,(longlong)Status._4_4_ & 0xfffffffffffffffeU | uVar8 & 1);
  if (bVar1) {
    if (param_3 == 0) {
      lVar9 = *(longlong *)(param_1 + 0x728);
    }
    else {
      cvm_oct_free_work(param_2);
      lVar9 = *(longlong *)(param_1 + 0x728);
    }
    *(longlong *)(param_1 + 0x728) = lVar9 + 1;
  }
  else if (param_3 != 0) {
    uVar3 = 0x3fffffff;
    if (param_2 >> 0x3e != 3) {
      uVar3 = 0xffffffff;
    }
    SYNC(4);
    SYNC(4);
    *(undefined8 *)(uVar7 & uVar3) = 1;
  }
  return uVar16;
}

