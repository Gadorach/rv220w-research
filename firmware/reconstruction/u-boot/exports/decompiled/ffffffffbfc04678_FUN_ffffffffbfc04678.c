/*
 * Ghidra reconstructed C; not original Cisco source.
 * RV220W boot-chain/U-Boot analysis v1.1.0
 * Entry: ffffffffbfc04678
 * Function: FUN_ffffffffbfc04678
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
FUN_ffffffffbfc04678
          (undefined4 param_1,undefined4 param_2,long param_3,undefined8 param_4,undefined4 param_5,
          undefined4 param_6,uint param_7,undefined8 param_8)

{
  char cVar1;
  byte bVar2;
  undefined1 uVar3;
  undefined1 uVar4;
  undefined1 uVar5;
  undefined2 uVar6;
  ushort uVar7;
  uint uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  undefined4 uVar14;
  undefined4 uVar15;
  undefined4 uVar16;
  bool bVar17;
  int iVar20;
  int iVar21;
  undefined4 *puVar18;
  long lVar19;
  int iVar22;
  ulong uVar23;
  byte *pbVar24;
  undefined4 *puVar25;
  ulong uVar26;
  undefined8 uVar27;
  undefined8 unaff_s0;
  long lVar28;
  undefined8 uVar29;
  int *piVar30;
  undefined8 unaff_s1;
  int iVar31;
  undefined8 unaff_s2;
  byte *pbVar32;
  undefined8 unaff_s3;
  undefined1 *puVar33;
  undefined4 *puVar34;
  undefined8 unaff_s4;
  undefined8 unaff_s5;
  undefined8 unaff_s6;
  int iVar36;
  undefined8 unaff_s7;
  code *pcVar37;
  long in_k0;
  undefined1 *puVar38;
  undefined8 unaff_s8;
  undefined8 in_ra;
  int iVar35;
  
  puVar38 = (undefined1 *)(long)((int)&stack0x00000000 + -0x1a0);
  *(undefined1 **)(puVar38 + 0x180) = &_gp;
  *(undefined8 *)(puVar38 + 0x160) = unaff_s4;
  pcVar37 = (code *)(long)DAT_ffffffffbfc43a54;
  *(undefined8 *)(puVar38 + 0x158) = unaff_s3;
  iVar20 = 0;
  *(undefined8 *)(puVar38 + 0x150) = unaff_s2;
  *(undefined8 *)(puVar38 + 0x148) = unaff_s1;
  iVar31 = 0;
  *(undefined8 *)(puVar38 + 0x140) = unaff_s0;
  *(undefined4 *)(puVar38 + 0x118) = param_1;
  *(undefined4 *)(puVar38 + 0x11c) = param_2;
  *(undefined8 *)(puVar38 + 400) = in_ra;
  *(undefined8 *)(puVar38 + 0x188) = unaff_s8;
  *(undefined8 *)(puVar38 + 0x178) = unaff_s7;
  *(undefined8 *)(puVar38 + 0x170) = unaff_s6;
  *(undefined8 *)(puVar38 + 0x168) = unaff_s5;
  *(undefined8 *)(puVar38 + 0x120) = param_4;
  *(undefined4 *)(puVar38 + 0x128) = param_5;
  *(undefined4 *)(puVar38 + 300) = param_6;
  *(undefined8 *)(puVar38 + 0x130) = param_8;
  (*pcVar37)(puVar38,0,0x100);
  iVar21 = *(int *)(puVar38 + 0x11c);
  lVar28 = param_3;
  while( true ) {
    lVar28 = (long)((int)lVar28 + 4);
    bVar17 = iVar21 <= iVar31;
    iVar31 = iVar31 + 1;
    if (bVar17) break;
    iVar21 = (*(code *)(long)DAT_ffffffffbfc437c8)(*(undefined4 *)(lVar28 + -4));
    iVar20 = iVar20 + iVar21 + 1;
    iVar21 = *(int *)(puVar38 + 0x11c);
  }
  lVar28 = (*(code *)(long)DAT_ffffffffbfc43a08)(iVar20 + 0x40,0,0x7fffffff,0,0);
  if (lVar28 < 0) {
    (*(code *)(long)DAT_ffffffffbfc4400c)(DAT_ffffffffbfc436f0 + 0x7f00);
  }
  else {
    iVar21 = (int)lVar28;
    iVar31 = 0;
    puVar33 = puVar38;
    while( true ) {
      puVar33 = (undefined1 *)(long)((int)puVar33 + 4);
      param_3 = (long)((int)param_3 + 4);
      if (*(int *)(puVar38 + 0x11c) <= iVar31) break;
      *(int *)(puVar33 + -4) = iVar21;
      iVar20 = *(int *)(param_3 + -4);
      iVar22 = iVar21;
      do {
        cVar1 = *(char *)(long)iVar20;
        iVar20 = iVar20 + 1;
        *(char *)(long)iVar22 = cVar1;
        iVar22 = iVar22 + 1;
      } while (cVar1 != '\0');
      iVar31 = iVar31 + 1;
      iVar20 = (*(code *)(long)DAT_ffffffffbfc437c8)(*(undefined4 *)(param_3 + -4));
      iVar21 = iVar21 + iVar20 + 1;
      (*(code *)(long)DAT_ffffffffbfc437c8)(*(undefined4 *)(param_3 + -4));
    }
  }
  if (*(int *)(in_k0 + 0x38) == 1) {
    param_7 = param_7 | 8;
  }
  lVar28 = (*(code *)(long)DAT_ffffffffbfc43f0c)(DAT_ffffffffbfc436f0 + 0x70d0);
  if (lVar28 != 0) {
    param_7 = param_7 | 0x10;
  }
  iVar21 = (*(code *)(long)DAT_ffffffffbfc44074)(*(undefined4 *)(puVar38 + 0x118));
  *(uint *)(puVar38 + 0x10c) = param_7 | 4;
  do {
    if (iVar21 < 0) {
      piVar30 = (int *)(long)DAT_ffffffffbfc43c00;
      (*(code *)(long)DAT_ffffffffbfc43c68)(*piVar30);
      *piVar30 = *piVar30 + 0x1000;
      return 0;
    }
    lVar28 = (*(code *)(long)DAT_ffffffffbfc43f0c)(DAT_ffffffffbfc436f0 + 0x7f38);
    if (lVar28 != 0) {
      lVar28 = (long)(iVar21 * 0x530 + DAT_ffffffffbfc43b88);
      *(ulong *)(lVar28 + 0x528) = *(ulong *)(lVar28 + 0x528) | 1;
    }
    uVar8 = *(uint *)(puVar38 + 0x1a4);
    uVar26 = *(long *)(puVar38 + 0x130) + (ulong)*(uint *)(puVar38 + 0x128);
    puVar18 = (undefined4 *)(long)DAT_ffffffffbfc43c00;
    *(uint *)(puVar38 + 0x114) = uVar8 & 1;
    uVar27 = *(undefined8 *)(puVar38 + 0x120);
    lVar28 = (long)(iVar21 * 0x530 + DAT_ffffffffbfc43b88);
    *(undefined4 *)(lVar28 + 0x518) = *puVar18;
    *(ulong *)(lVar28 + 0x510) = uVar26 & 0xfffffffffffffff0;
    *(undefined8 *)(lVar28 + 0x500) = uVar27;
    iVar31 = DAT_ffffffffbfc43e30;
    if ((uVar8 & 1) == 0) {
      uVar8 = *(uint *)(puVar38 + 300);
      uVar23 = (uVar26 + uVar8) - 400 & 0xfffffffffffffff8;
      *(ulong *)(lVar28 + 0x508) = uVar23;
      lVar28 = (long)(iVar21 * 400 + iVar31);
      *(ulong *)(lVar28 + 0x188) = uVar23 - 0x98;
      *(ulong *)(lVar28 + 0x10) = uVar26;
      *(ulong *)(lVar28 + 0x18) = uVar26 + uVar8;
    }
    else {
      lVar19 = (*(code *)(long)DAT_ffffffffbfc43a08)(400,0,0x7fffffff,0,0);
      if (lVar19 < 0) {
        iVar21 = DAT_ffffffffbfc436f0 + 0x7f50;
LAB_ffffffffbfc047d8:
        (*(code *)(long)DAT_ffffffffbfc4400c)(iVar21);
        return 0xffffffffffffffff;
      }
      pcVar37 = (code *)(long)DAT_ffffffffbfc43a08;
      *(long *)(lVar28 + 0x508) = lVar19;
      lVar28 = (*pcVar37)(0x98,0,0x7fffffff,0,0);
      if (lVar28 < 0) {
        iVar21 = DAT_ffffffffbfc436f0 + 0x7f88;
        goto LAB_ffffffffbfc047d8;
      }
      *(long *)((long)(iVar21 * 400 + DAT_ffffffffbfc43e30) + 0x188) = lVar28;
    }
    iVar20 = iVar21 * 400;
    pcVar37 = (code *)(long)DAT_ffffffffbfc43e84;
    puVar18 = (undefined4 *)(long)(iVar20 + DAT_ffffffffbfc43e30);
    iVar31 = iVar20 + 0x40 + DAT_ffffffffbfc43e30;
    puVar18[0xf] = *(undefined4 *)(puVar38 + 0x11c);
    (*pcVar37)(iVar31,puVar38,0x100);
    *puVar18 = 6;
    iVar31 = *(int *)(long)DAT_ffffffffbfc44018;
    puVar18[1] = 400;
    puVar18[0x54] = 0xa28;
    if (iVar21 == iVar31) {
      lVar28 = (long)(iVar21 * 0x98 + DAT_ffffffffbfc44070);
      *(uint *)(lVar28 + 0x30) = *(uint *)(lVar28 + 0x30) | 1;
    }
    iVar35 = iVar21 * 0x98 + DAT_ffffffffbfc44070;
    puVar34 = (undefined4 *)(long)iVar35;
    iVar36 = 0x14;
    pbVar32 = (byte *)(long)(iVar35 + 0x58);
    uVar8 = *(uint *)(puVar38 + 0x10c);
    uVar26 = *(ulong *)(in_k0 + 0x10);
    uVar9 = *(undefined4 *)(puVar38 + 0x118);
    pcVar37 = (code *)(long)DAT_ffffffffbfc43ac8;
    *puVar34 = 1;
    puVar34[0xc] = puVar34[0xc] | uVar8;
    puVar34[0xe] = (int)(uVar26 >> 0x14);
    puVar34[0xd] = uVar9;
    puVar34[1] = 2;
    lVar28 = (*pcVar37)();
    iVar31 = *(int *)(in_k0 + 0x28);
    iVar22 = *(int *)(in_k0 + 0x24);
    puVar25 = (undefined4 *)(long)DAT_ffffffffbfc43c00;
    *(int *)(puVar38 + 0x110) = iVar35 + 0x6c;
    uVar6 = *(undefined2 *)(in_k0 + 0x44);
    puVar34[10] = *puVar25;
    puVar34[0x12] = iVar31 * 1000000;
    puVar34[0xf] = (uint)((ulong)(lVar28 << 0x25) >> 0x25);
    puVar34[0x11] = iVar22 * 1000000;
    *(undefined2 *)(puVar34 + 0x14) = uVar6;
    uVar9 = *(undefined4 *)(puVar38 + 0x110);
    *(undefined1 *)((long)puVar34 + 0x52) = *(undefined1 *)(in_k0 + 0x46);
    iVar31 = DAT_ffffffffbfc43b88;
    *(undefined1 *)((long)puVar34 + 0x53) = *(undefined1 *)(in_k0 + 0x47);
    pcVar37 = (code *)(long)DAT_ffffffffbfc43e84;
    lVar19 = (long)(iVar21 * 0x530 + iVar31);
    uVar27 = *(undefined8 *)(lVar19 + 0x510);
    *(undefined1 *)((long)puVar34 + 0x72) = *(undefined1 *)(in_k0 + 0x7e);
    uVar10 = *(undefined4 *)(puVar38 + 0x128);
    *(undefined8 *)(puVar34 + 2) = uVar27;
    puVar34[0xb] = uVar10;
    (*pcVar37)(uVar9,(int)in_k0 + 0x78,6);
    iVar21 = (int)in_k0 + 0x4c;
    lVar28 = 0x14;
    pbVar24 = pbVar32;
    do {
      bVar2 = *(byte *)(long)iVar21;
      lVar28 = (long)((int)lVar28 + -1);
      *pbVar24 = bVar2;
      pbVar24 = (byte *)(long)((int)pbVar24 + 1);
      if ((ulong)bVar2 == 0) break;
      iVar21 = iVar21 + 1;
    } while (lVar28 != 0);
    uVar7 = *(ushort *)(in_k0 + 0x6c);
    *(undefined8 *)(puVar34 + 0x1e) = 0x1d000800;
    *(undefined8 *)(puVar34 + 0x20) = 0x1d010000;
    *(undefined1 **)(puVar34 + 0x22) = &DAT_1d0200f8;
    setCopReg(2,(ulong)bVar2,*(undefined4 *)((long)*(int *)(puVar38 + 0x10c) + 4));
    puVar34[0x24] = (uint)(uVar7 >> 3) * 1000000;
    puVar34[0x25] = puVar34[0x25] | 4;
    setCopReg(2,lVar28,*(undefined4 *)((long)*(int *)(puVar38 + 0x10c) + 5));
    iVar21 = puVar34[0x25];
    puVar34[0x25] = (int)((long)iVar21 | 0x20U);
    setCopReg(2,(long)iVar21 | 0x20U,*(undefined4 *)((long)*(int *)(puVar38 + 0x10c) + 4));
    puVar34[0x25] = puVar34[0x25] | 8;
    uVar9 = *(undefined4 *)(long)DAT_ffffffffbfc43c00;
    uVar3 = *(undefined1 *)((long)puVar34 + 0x52);
    iVar21 = iVar20 + DAT_ffffffffbfc43e30;
    uVar4 = *(undefined1 *)((long)puVar34 + 0x53);
    uVar5 = *(undefined1 *)((long)puVar34 + 0x72);
    uVar10 = puVar34[0xd];
    uVar11 = puVar34[0xc];
    uVar12 = puVar34[0x11];
    uVar13 = puVar34[0x12];
    uVar14 = puVar34[0xe];
    uVar15 = puVar34[0xf];
    uVar16 = *(undefined4 *)(puVar38 + 0x110);
    pcVar37 = (code *)(long)DAT_ffffffffbfc43e84;
    puVar34[0x25] = puVar34[0x25] | 1 | *(uint *)(puVar38 + 0x1ac);
    *(undefined2 *)(puVar18 + 0x58) = *(undefined2 *)(puVar34 + 0x14);
    puVar18[0x51] = uVar10;
    puVar18[0x50] = uVar11;
    puVar18[0x55] = uVar12;
    puVar18[0x56] = uVar13;
    *(undefined1 *)((long)puVar18 + 0x162) = uVar3;
    *(undefined1 *)((long)puVar18 + 0x163) = uVar4;
    *(undefined1 *)((long)puVar18 + 0x182) = uVar5;
    puVar18[0x52] = uVar14;
    puVar18[0x53] = uVar15;
    puVar18[0xc] = uVar9;
    (*pcVar37)(iVar21 + 0x17c,uVar16,6);
    iVar21 = iVar20 + DAT_ffffffffbfc43e30 + 0x168;
    do {
      bVar2 = *pbVar32;
      iVar36 = iVar36 + -1;
      *(byte *)(long)iVar21 = bVar2;
      iVar21 = iVar21 + 1;
      if (bVar2 == 0) break;
      pbVar32 = (byte *)(long)((int)pbVar32 + 1);
    } while (iVar36 != 0);
    if (*(int *)(puVar38 + 0x114) == 0) {
      iVar21 = DAT_ffffffffbfc436ec + 0x422c;
      uVar29 = *(undefined8 *)(lVar19 + 0x508);
      uVar27 = (*(code *)(long)iVar21)(puVar18);
      (*(code *)(long)DAT_ffffffffbfc43a18)(lVar19,uVar29,uVar27,puVar18[1]);
      uVar29 = *(undefined8 *)(puVar18 + 0x62);
      uVar27 = (*(code *)(long)iVar21)(puVar34);
      (*(code *)(long)DAT_ffffffffbfc43a18)(lVar19,uVar29,uVar27,0x98);
    }
    else {
      (*(code *)(long)DAT_ffffffffbfc43e84)(*(undefined4 *)(lVar19 + 0x50c),puVar18,puVar18[1]);
      (*(code *)(long)DAT_ffffffffbfc43e84)(puVar18[99],puVar34,0x98);
    }
    iVar21 = (*(code *)(long)DAT_ffffffffbfc43c20)();
  } while( true );
}

