/*
 * Ghidra reconstructed C; not original Cisco source.
 * RV220W boot-chain/U-Boot analysis v1.1.0
 * Entry: ffffffffbfc06970
 * Function: FUN_ffffffffbfc06970
 * Subsystem: bootloader-support
 *
 * RV220W BOOT-CHAIN / U-BOOT SEMANTIC ANNOTATION v1.1.0
 * Region: early-boot-and-board-support
 * Subsystem: bootloader-support
 * Evidence: Ghidra control-flow/GOT recovery
 * Confidence: medium for boundary; low for original name
 * Interpretation: Analysis-created function. Boundary is supported by control flow or a recovered GOT pointer, but original source name and detailed role are unknown.
 * Safety: reconstructed pseudocode is not original Cisco source. Do not replay flash, GPIO, MDIO or switch writes without readback and recovery safeguards.
 * 
 * Prior/recovered evidence:
 * RV220W BOOT-CHAIN / U-BOOT SEMANTIC ANNOTATION v1.1.0
 * Region: early-boot-and-board-support
 * Subsystem: bootloader-support
 * Evidence: Ghidra control-flow/GOT recovery
 * Confidence: medium for boundary; low for original name
 * Interpretation: Analysis-created function. Boundary is supported by control flow or a recovered GOT pointer, but original source name and detailed role are unknown.
 * Safety: reconstructed pseudocode is not original Cisco source. Do not replay flash, GPIO, MDIO or switch writes without readback and recovery safeguards.
 * 
 * Prior/recovered evidence:
 * RV220W BOOT-CHAIN / U-BOOT SEMANTIC ANNOTATION v1.1.0
 * Region: early-boot-and-board-support
 * Subsystem: bootloader-support
 * Evidence: Ghidra control-flow/GOT recovery
 * Confidence: medium for boundary; low for original name
 * Interpretation: Analysis-created function. Boundary is supported by control flow or a recovered GOT pointer, but original source name and detailed role are unknown.
 * Safety: reconstructed pseudocode is not original Cisco source. Do not replay flash, GPIO, MDIO or switch writes without readback and recovery safeguards.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* RV220W BOOT-CHAIN / U-BOOT SEMANTIC ANNOTATION v1.1.0
   Region: early-boot-and-board-support
   Subsystem: bootloader-support
   Evidence: Ghidra control-flow/GOT recovery
   Confidence: medium for boundary; low for original name
   Interpretation: Analysis-created function. Boundary is supported by control flow or a recovered
   GOT pointer, but original source name and detailed role are unknown.
   Safety: reconstructed pseudocode is not original Cisco source. Do not replay flash, GPIO, MDIO or
   switch writes without readback and recovery safeguards.
   
   Prior/recovered evidence:
   RV220W BOOT-CHAIN / U-BOOT SEMANTIC ANNOTATION v1.1.0
   Region: early-boot-and-board-support
   Subsystem: bootloader-support
   Evidence: Ghidra control-flow/GOT recovery
   Confidence: medium for boundary; low for original name
   Interpretation: Analysis-created function. Boundary is supported by control flow or a recovered
   GOT pointer, but original source name and detailed role are unknown.
   Safety: reconstructed pseudocode is not original Cisco source. Do not replay flash, GPIO, MDIO or
   switch writes without readback and recovery safeguards.
   
   Prior/recovered evidence:
   RV220W BOOT-CHAIN / U-BOOT SEMANTIC ANNOTATION v1.1.0
   Region: early-boot-and-board-support
   Subsystem: bootloader-support
   Evidence: Ghidra control-flow/GOT recovery
   Confidence: medium for boundary; low for original name
   Interpretation: Analysis-created function. Boundary is supported by control flow or a recovered
   GOT pointer, but original source name and detailed role are unknown.
   Safety: reconstructed pseudocode is not original Cisco source. Do not replay flash, GPIO, MDIO or
   switch writes without readback and recovery safeguards. */

undefined8
FUN_ffffffffbfc06970
          (undefined8 param_1,undefined8 param_2,undefined4 param_3,undefined4 param_4,
          undefined4 param_5,undefined4 param_6)

{
  undefined4 uVar1;
  undefined8 in_zero;
  undefined8 extraout_at;
  undefined8 extraout_at_00;
  undefined8 extraout_at_01;
  long lVar2;
  uint uVar5;
  long lVar3;
  ulong uVar4;
  int iVar8;
  undefined8 uVar6;
  ulong uVar7;
  int iVar9;
  ulong uVar10;
  ulong uVar11;
  ulong uVar12;
  ulong unaff_s0;
  ulong *puVar13;
  ulong unaff_s1;
  ulong unaff_s2;
  ulong uVar14;
  ulong unaff_s3;
  ulong uVar15;
  ulong unaff_s4;
  int iVar16;
  ulong unaff_s5;
  ulong uVar17;
  ulong unaff_s6;
  ulong uVar18;
  ulong unaff_s7;
  code *pcVar19;
  long in_k0;
  ulong *puVar20;
  ulong unaff_s8;
  ulong in_ra;
  
  puVar20 = (ulong *)(long)((int)&stack0x00000000 + -0x110);
  puVar20[0x1e] = (ulong)&_gp;
  puVar20[0x16] = unaff_s0;
  iVar8 = DAT_ffffffffbfc436f4;
  pcVar19 = (code *)(long)DAT_ffffffffbfc43f0c;
  puVar20[0x20] = in_ra;
  puVar20[0x1f] = unaff_s8;
  puVar20[0x1d] = unaff_s7;
  puVar20[0x1c] = unaff_s6;
  puVar20[0x1b] = unaff_s5;
  puVar20[0x1a] = unaff_s4;
  puVar20[0x19] = unaff_s3;
  puVar20[0x18] = unaff_s2;
  puVar20[0x17] = unaff_s1;
  *(undefined4 *)(puVar20 + 0xd) = param_3;
  *(undefined4 *)((long)puVar20 + 0x6c) = param_4;
  *(undefined4 *)((long)puVar20 + 0x7c) = param_5;
  *(undefined4 *)((long)puVar20 + 0x8c) = param_6;
  lVar2 = (*pcVar19)(iVar8 + -0x6968);
  if (lVar2 != 0) {
    *(uint *)(in_k0 + 4) = *(uint *)(in_k0 + 4) | 0x20;
  }
  uVar5 = (uint)(ushort)((ulong)param_1 >> 8);
  *(uint *)(puVar20 + 0xb) = uVar5 << 8;
  if ((uVar5 == 0xd04) || (uVar5 == 0xd07)) {
    if (*(int *)((long)puVar20 + 0x7c) == 0) {
      uVar1 = getCopReg(2,0xf);
      *(undefined4 *)(_DAT_8001180080000000 + 0x390) = uVar1;
      iVar8 = *(int *)(puVar20 + 0xb);
    }
    else {
      iVar8 = *(int *)(puVar20 + 0xb);
      if (*(int *)((long)puVar20 + 0x7c) == 1) {
        uVar1 = getCopReg(2,0x10);
        *(undefined4 *)(_DAT_8001180080000000 + 0x389) = uVar1;
      }
    }
  }
  else {
    uVar1 = getCopReg(2,0);
    *(undefined4 *)
     (*(long *)(&DAT_8001180088000000 + ((long)*(int *)((long)puVar20 + 0x7c) & 1U) * 0x60000000) +
     0x37a) = uVar1;
    iVar8 = *(int *)(puVar20 + 0xb);
  }
  uVar4 = _DAT_8001180088000010;
  if ((iVar8 == 0xd0100) || (uVar6 = extraout_at, iVar8 == 0xd0200)) {
    pcVar19 = (code *)(long)(DAT_ffffffffbfc436ec + 0x62c8);
    (*pcVar19)(&DAT_8001180088000010,_DAT_8001180088000010 & 0xfffffffffffcffff | 0x800);
    (*(code *)(long)DAT_ffffffffbfc44014)(6000);
    (*pcVar19)(&DAT_8001180088000018,_DAT_8001180088000018 | 0x100);
    (*(code *)(long)DAT_ffffffffbfc44014)(2000);
    (*(code *)(long)DAT_ffffffffbfc44014)(6000);
    (*pcVar19)(&DAT_8001180088000010,uVar4 & 0xfffffffffffcf7ff);
    (*(code *)(long)DAT_ffffffffbfc44014)(2000);
    uVar6 = extraout_at_00;
  }
  iVar8 = *(int *)(puVar20 + 0xb);
  if ((iVar8 == 0xd0300) || (iVar8 == 0xd0600)) {
    if (*(int *)((long)puVar20 + 0x6c) == 0) {
      iVar8 = DAT_ffffffffbfc436f4 + -0x6958;
      goto LAB_ffffffffbfc06dfc;
    }
    iVar8 = DAT_ffffffffbfc436ec + 0x62c8;
    (*(code *)(long)iVar8)(&DAT_8001180088000010,_DAT_8001180088000010 | 0x800);
    uVar5 = *(uint *)(puVar20 + 0xd);
    (*(code *)(long)iVar8)(&DAT_8001180088000018,_DAT_8001180088000018 & 0xfffffffffffffeff);
    uVar11 = 0;
    puVar20[3] = (ulong)uVar5;
    puVar20[9] = 0;
    puVar20[8] = 0;
    uVar4 = (ulong)uVar5;
LAB_ffffffffbfc075b0:
    do {
      puVar20[2] = 0;
      puVar20[0x12] = uVar4 * 10;
      uVar12 = uVar11;
      uVar15 = uVar4;
LAB_ffffffffbfc075a8:
      iVar8 = DAT_ffffffffbfc436ec;
      uVar7 = 5;
      do {
        uVar11 = uVar7;
        uVar10 = (ulong)*(uint *)((long)puVar20 + 0x6c);
        uVar18 = puVar20[2] + 1;
        lVar2 = (long)*(int *)(long)((int)uVar11 * 4 + DAT_ffffffffbfc436f0 + 0x61c8);
        uVar6 = special2(lVar2,uVar18,0,3);
        uVar7 = special2(uVar6,puVar20[0x12],0,3);
        if (uVar10 == 0) {
          trap(7);
        }
        lVar3 = (uVar7 / uVar10) / 10 + (ulong)(4 < (uVar7 / uVar10) % 10);
        uVar10 = special2(uVar10,lVar3,0,3);
        uVar17 = lVar3 - 1;
        if (uVar18 == 0) {
          trap(7);
        }
        uVar14 = (uVar10 / uVar18) / 1000000;
      } while ((0x9c4 < uVar14) && (uVar7 = (long)((int)uVar11 + -1), uVar11 != 0));
      if (0x7f < uVar17) {
LAB_ffffffffbfc06d98:
        uVar11 = uVar12;
        if (0x3f < uVar18) goto LAB_ffffffffbfc06da0;
        puVar20[2] = uVar18;
        uVar12 = uVar11;
        goto LAB_ffffffffbfc075a8;
      }
      uVar7 = special2(uVar18,lVar2,0,3);
      iVar9 = DAT_ffffffffbfc436f4 + -0x6928;
      puVar20[0x14] = uVar12;
      uVar10 = uVar10 / uVar7;
      if (uVar7 == 0) {
        trap(7);
      }
      uVar7 = uVar4 - uVar10;
      (*(code *)(long)(iVar8 + 0x6910))(iVar9,puVar20[2],lVar2,uVar17,uVar14,uVar10,uVar7);
      uVar12 = puVar20[0x14];
      if (((uVar14 < 0x4b0) || (uVar4 < uVar10)) || (uVar15 <= uVar7)) goto LAB_ffffffffbfc06d98;
      (*(code *)(long)(DAT_ffffffffbfc436ec + 0x6910))
                (DAT_ffffffffbfc436f4 + -0x68d8,puVar20[2],lVar2,uVar17,uVar14,uVar10,uVar7);
      if (uVar7 != 0) {
        puVar20[9] = uVar17;
        puVar20[8] = puVar20[2];
        uVar12 = uVar11;
        uVar15 = uVar7;
        goto LAB_ffffffffbfc06d98;
      }
      puVar20[9] = uVar17;
      uVar15 = 0;
      puVar20[8] = puVar20[2];
LAB_ffffffffbfc06da0:
      if (uVar15 == uVar4) {
        iVar8 = *(int *)(puVar20 + 0xd);
        if (uVar4 < puVar20[3] - 10000000) goto LAB_ffffffffbfc06df0;
        *(uint *)(puVar20 + 0xd) = iVar8 - 1000000U;
        uVar4 = (ulong)(iVar8 - 1000000U);
        goto LAB_ffffffffbfc075b0;
      }
      uVar4 = uVar15;
    } while (uVar15 == *(uint *)(puVar20 + 0xd));
    uVar4 = (ulong)(uVar11 == 0);
    special2(uVar11,uVar4,1,0x2e);
    special2(uVar11,uVar4,2,0x2e);
    special2(uVar11,uVar4,3,0x2e);
    special2(uVar11,uVar4,4,0x2e);
    in_zero = special2(uVar11,uVar4,5,0x2e);
    pcVar19 = (code *)(long)(DAT_ffffffffbfc436ec + 0x62c8);
    (*pcVar19)(&DAT_80011800880000a8,
               uVar4 | 0x18000000 | uVar4 << 1 | uVar4 << 2 | uVar4 << 3 | uVar4 << 4 | uVar4 << 5 |
               ((long)(int)puVar20[9] & 0xfffU) << 0xe | ((long)(int)puVar20[8] & 0x3fU) << 8);
    (*(code *)(long)DAT_ffffffffbfc44014)(10000);
    (*pcVar19)(&DAT_80011800880000a8,_DAT_80011800880000a8 | 0x4000000);
    (*(code *)(long)DAT_ffffffffbfc44014)(1000000);
    (*pcVar19)(&DAT_80011800880000a8,_DAT_80011800880000a8 & 0xfffffffff7ffffff);
    (*pcVar19)(&DAT_8001180088000010,_DAT_8001180088000010 | 0x800);
    (*pcVar19)(&DAT_8001180088000018,_DAT_8001180088000018 & 0xfffffffffffffeff);
    (*pcVar19)(&DAT_8001180088000018,_DAT_8001180088000018 | 0x100);
    (*(code *)(long)DAT_ffffffffbfc44014)(10000);
    uVar11 = _DAT_8001180088000010 & 0xfffffffffffff7ff;
    (*pcVar19)(&DAT_8001180088000010,uVar11);
    uVar4 = _DAT_8001180088000090;
    setCopReg(2,uVar11,*(undefined4 *)((long)*(int *)(in_k0 + 4) + -0x238));
    uVar11 = _DAT_8001180088000090 | 0x200;
    lVar2 = (*(code *)(long)DAT_ffffffffbfc43f0c)(DAT_ffffffffbfc436f4 + -0x6840);
    if (lVar2 != 0) {
      uVar12 = (*(code *)(long)DAT_ffffffffbfc438b0)(lVar2,0,0);
      uVar11 = uVar4 & 0xfffffffffffffdff | (uVar12 & 1) << 9;
      (*(code *)(long)DAT_ffffffffbfc4400c)(DAT_ffffffffbfc436f4 + -0x6830,uVar12 & 1);
    }
    (*(code *)(long)(DAT_ffffffffbfc436ec + 0x62c8))(&DAT_8001180088000090,uVar11);
    iVar8 = *(int *)(puVar20 + 0xb);
    uVar6 = extraout_at_01;
  }
  uVar4 = _DAT_8001180080000000;
  if (iVar8 == 0xd0400) {
    puVar20[0xc] = _DAT_8001180080000000;
    iVar8 = DAT_ffffffffbfc436ec;
    if (*(int *)((long)puVar20 + 0x7c) == 0) {
      setCopReg(2,in_zero,*(undefined4 *)((long)*(int *)((long)puVar20 + 0x8c) + 0x269));
      uVar4 = uVar4 | 0x8000;
      puVar20[0xc] = uVar4;
LAB_ffffffffbfc06f0c:
      (*(code *)(long)(iVar8 + 0x62c8))(&DAT_8001180080000000,uVar4);
      *(undefined4 *)(puVar20 + 7) = 1;
      goto LAB_ffffffffbfc06f1c;
    }
    if (*(int *)((long)puVar20 + 0x7c) == 1) {
      setCopReg(2,uVar6,*(undefined4 *)((long)*(int *)((long)puVar20 + 0x8c) + 0x256));
      uVar4 = puVar20[0xc] | 0x10000;
      puVar20[0xc] = uVar4;
      goto LAB_ffffffffbfc06f0c;
    }
    (*(code *)(long)(DAT_ffffffffbfc436ec + 0x62c8))(&DAT_8001180080000000,puVar20[0xc]);
    iVar8 = DAT_ffffffffbfc436f4;
    *(undefined4 *)(puVar20 + 7) = 0;
    iVar8 = iVar8 + -0x67f0;
  }
  else {
    if (iVar8 != 0xd0700) goto LAB_ffffffffbfc07558;
    puVar20[0xc] = _DAT_8001180080000000;
    *(undefined4 *)(puVar20 + 7) = 1;
LAB_ffffffffbfc06f1c:
    iVar8 = DAT_ffffffffbfc436f4 + -0x67f8;
  }
  iVar16 = DAT_ffffffffbfc436ec + 0x6910;
  (*(code *)(long)iVar16)
            (DAT_ffffffffbfc436f4 + -0x67e0,*(undefined4 *)((long)puVar20 + 0x7c),iVar8,
             *(undefined4 *)((long)puVar20 + 0x8c));
  uVar4 = ((long)*(int *)((long)puVar20 + 0x7c) & 1U) * 0x60000000;
  uVar11 = uVar4 + 0x80011800880000c0;
  puVar20[10] = uVar11;
  iVar8 = DAT_ffffffffbfc436ec + 0x62c8;
  puVar20[4] = uVar4;
  (*(code *)(long)iVar8)(uVar11,0x80);
  (*(code *)(long)iVar8)(&DAT_80011800e80000b8,0);
  uVar1 = getCopReg(2,0x1a);
  *(undefined4 *)(_DAT_80011800880000a8 + 0x94) = uVar1;
  uVar5 = *(uint *)(puVar20 + 0xd);
  iVar8 = DAT_ffffffffbfc436f4 + -0x67b8;
  iVar9 = DAT_ffffffffbfc436f4 + -0x6790;
  puVar20[1] = (ulong)uVar5;
  (*(code *)(long)iVar16)
            (iVar8,*(undefined4 *)((long)puVar20 + 0x7c),iVar9,*(undefined4 *)(puVar20 + 0xd));
  uVar11 = 0;
  puVar20[6] = 0;
  puVar20[5] = 0;
  uVar4 = (ulong)uVar5;
LAB_ffffffffbfc07744:
  do {
    *puVar20 = 0;
    puVar20[0x13] = uVar4 * 10;
    uVar12 = uVar11;
    uVar15 = uVar4;
LAB_ffffffffbfc0773c:
    iVar8 = DAT_ffffffffbfc436ec;
    uVar7 = 5;
    do {
      uVar11 = uVar7;
      uVar17 = *puVar20 + 1;
      lVar3 = (long)*(int *)(long)((int)uVar11 * 4 + DAT_ffffffffbfc436f0 + 0x61b0);
      uVar6 = special2(lVar3,uVar17,0,3);
      uVar7 = special2(uVar6,puVar20[0x13],0,3);
      lVar2 = (uVar7 / 50000000) / 10 + (ulong)(4 < (uVar7 / 50000000) % 10);
      uVar10 = special2(lVar2,50000000,0,3);
      uVar18 = lVar2 - 1;
      if (uVar17 == 0) {
        trap(7);
      }
      uVar14 = (uVar10 / uVar17) / 1000000;
    } while ((0x9c4 < uVar14) && (uVar7 = (long)((int)uVar11 + -1), uVar11 != 0));
    if (0x7f < uVar18) {
LAB_ffffffffbfc071e8:
      uVar11 = uVar12;
      if (0x3f < uVar17) goto LAB_ffffffffbfc071f0;
      *puVar20 = uVar17;
      uVar12 = uVar11;
      goto LAB_ffffffffbfc0773c;
    }
    uVar7 = special2(uVar17,lVar3,0,3);
    iVar9 = DAT_ffffffffbfc436f4 + -0x6928;
    puVar20[0x14] = uVar12;
    uVar10 = uVar10 / uVar7;
    if (uVar7 == 0) {
      trap(7);
    }
    uVar7 = uVar4 - uVar10;
    (*(code *)(long)(iVar8 + 0x6910))(iVar9,*puVar20,lVar3,uVar18,uVar14,uVar10,uVar7);
    uVar12 = puVar20[0x14];
    if (((uVar14 < 0x4b0) || (uVar4 < uVar10)) || (uVar15 <= uVar7)) goto LAB_ffffffffbfc071e8;
    (*(code *)(long)(DAT_ffffffffbfc436ec + 0x6910))
              (DAT_ffffffffbfc436f4 + -0x68d8,*puVar20,lVar3,uVar18,uVar14,uVar10,uVar7);
    if (uVar7 != 0) {
      puVar20[6] = uVar18;
      puVar20[5] = *puVar20;
      uVar12 = uVar11;
      uVar15 = uVar7;
      goto LAB_ffffffffbfc071e8;
    }
    puVar20[6] = uVar18;
    uVar15 = 0;
    puVar20[5] = *puVar20;
LAB_ffffffffbfc071f0:
    if (uVar15 == uVar4) {
      iVar8 = *(int *)(puVar20 + 0xd);
      if (uVar4 < puVar20[1] - 10000000) goto LAB_ffffffffbfc06df0;
      *(uint *)(puVar20 + 0xd) = iVar8 - 1000000U;
      uVar4 = (ulong)(iVar8 - 1000000U);
      goto LAB_ffffffffbfc07744;
    }
    uVar4 = uVar15;
  } while (uVar15 == *(uint *)(puVar20 + 0xd));
  uVar4 = (ulong)(uVar11 == 0);
  special2(uVar11,uVar4,1,0x2e);
  special2(uVar11,uVar4,2,0x2e);
  special2(uVar11,uVar4,3,0x2e);
  special2(uVar11,uVar4,4,0x2e);
  special2(uVar11,uVar4,5,0x2e);
  pcVar19 = (code *)(long)(DAT_ffffffffbfc436ec + 0x62c8);
  (*pcVar19)(&DAT_80011800880000a8,
             uVar4 | 0x8000000 | uVar4 << 1 | uVar4 << 2 | uVar4 << 3 | uVar4 << 4 | uVar4 << 5 |
             ((long)(int)puVar20[6] & 0xfffU) << 0xe | ((long)(int)puVar20[5] & 0x3fU) << 8);
  (*(code *)(long)DAT_ffffffffbfc44014)(2000);
  (*pcVar19)(&DAT_80011800880000a8,_DAT_80011800880000a8 | 0x4000000);
  (*(code *)(long)DAT_ffffffffbfc44014)(1000000);
  (*pcVar19)(&DAT_80011800880000a8,_DAT_80011800880000a8 & 0xfffffffff7ffffff);
  iVar8 = *(int *)(puVar20 + 7);
  if ((puVar20[0xc] >> 0xf & 3) == 3) {
    uVar1 = getCopReg(2,7);
    *(undefined4 *)(_DAT_80011800e80000b8 + 0x1c) = uVar1;
    (*(code *)(long)(DAT_ffffffffbfc436ec + 0x6910))
              (DAT_ffffffffbfc436f4 + -0x6778,*(undefined4 *)((long)puVar20 + 0x7c),
               DAT_ffffffffbfc436f4 + -0x6760);
    iVar8 = DAT_ffffffffbfc436ec + 0x62c8;
    (*(code *)(long)iVar8)(&DAT_80011800e80000b8,0);
    (*(code *)(long)iVar8)(&DAT_80011800e80000b8,0);
    iVar8 = *(int *)(puVar20 + 7);
  }
  iVar9 = DAT_ffffffffbfc436f4;
  if (iVar8 == 0) {
    return 0xffffffffffffffff;
  }
  iVar8 = DAT_ffffffffbfc436ec + 0x6910;
  (*(code *)(long)iVar8)
            (DAT_ffffffffbfc436f4 + -0x6778,*(undefined4 *)((long)puVar20 + 0x7c),
             DAT_ffffffffbfc436f4 + -0x6730);
  pcVar19 = (code *)(long)(DAT_ffffffffbfc436ec + 0x62c8);
  (*pcVar19)(puVar20[10],0x80);
  (*pcVar19)((ulong *)puVar20[10],*(ulong *)puVar20[10] | 0x20);
  (*(code *)(long)DAT_ffffffffbfc44014)(2000);
  puVar13 = (ulong *)(puVar20[4] + 0x80011800880000f0);
  uVar4 = *puVar13;
  (*pcVar19)(puVar13);
  (*pcVar19)(puVar13,uVar4 & 0xfffffffffffffffe | 1);
  (*pcVar19)(puVar13,uVar4 & 0xfffffffffffffffe);
  (*(code *)(long)DAT_ffffffffbfc44014)(1000000);
  uVar4 = *(ulong *)(puVar20[4] + 0x80011800880000f8);
  if (uVar4 != 0) {
    (*(code *)(long)DAT_ffffffffbfc4400c)(DAT_ffffffffbfc436f4 + -0x6700,uVar4);
    (*(code *)(long)DAT_ffffffffbfc4400c)(DAT_ffffffffbfc436f4 + -0x66e8,uVar4 >> 10 & 1);
    (*(code *)(long)DAT_ffffffffbfc4400c)(DAT_ffffffffbfc436f4 + -0x66d8,uVar4 >> 9 & 1);
    (*(code *)(long)DAT_ffffffffbfc4400c)(DAT_ffffffffbfc436f4 + -0x66c8,uVar4 >> 8 & 1);
    (*(code *)(long)DAT_ffffffffbfc4400c)(DAT_ffffffffbfc436f4 + -0x66b8,uVar4 >> 5 & 7);
    (*(code *)(long)DAT_ffffffffbfc4400c)(DAT_ffffffffbfc436f4 + -0x66a8,uVar4 >> 4 & 1);
    (*(code *)(long)DAT_ffffffffbfc4400c)(DAT_ffffffffbfc436f4 + -0x6698,uVar4 >> 3 & 1);
    (*(code *)(long)DAT_ffffffffbfc4400c)(DAT_ffffffffbfc436f4 + -0x6688,uVar4 & 7);
    return 0xffffffffffffffff;
  }
  (*pcVar19)((ulong *)puVar20[10],*(ulong *)puVar20[10] & 0xffffffffffffff7f);
  lVar2 = (long)*(int *)((long)puVar20 + 0x7c);
  (*(code *)(long)iVar8)(iVar9 + -0x6778,lVar2,DAT_ffffffffbfc436f4 + -0x6678);
  uVar11 = puVar20[4];
  uVar4 = *(ulong *)(&DAT_8001180088000090 + uVar11) & 0xffffffffffffe1ff;
  setCopReg(2,lVar2,*(undefined4 *)((long)*(int *)(in_k0 + 4) + 0x12));
  uVar12 = uVar4 | 0x100200;
  lVar2 = (*(code *)(long)DAT_ffffffffbfc43f0c)(DAT_ffffffffbfc436f4 + -0x6840);
  if (lVar2 != 0) {
    uVar15 = (*(code *)(long)DAT_ffffffffbfc438b0)(lVar2,0,0);
    uVar12 = uVar4 | 0x100000 | (uVar15 & 1) << 9;
    (*(code *)(long)DAT_ffffffffbfc4400c)(DAT_ffffffffbfc436f4 + -0x6830,uVar15 & 1);
  }
  (*(code *)(long)(DAT_ffffffffbfc436ec + 0x62c8))(&DAT_8001180088000090 + uVar11,uVar12);
LAB_ffffffffbfc07558:
  (*(code *)(long)(DAT_ffffffffbfc436ec + 0x62c8))
            (&DAT_8001180088000000 + ((long)*(int *)((long)puVar20 + 0x7c) & 1U) * 0x60000000,1);
  return 0;
LAB_ffffffffbfc06df0:
  iVar8 = DAT_ffffffffbfc436f4 + -0x6880;
LAB_ffffffffbfc06dfc:
  (*(code *)(long)DAT_ffffffffbfc4400c)(iVar8);
  return 0xffffffffffffffff;
}

