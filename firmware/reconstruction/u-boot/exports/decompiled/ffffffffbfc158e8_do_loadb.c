/*
 * Ghidra reconstructed C; not original Cisco source.
 * RV220W boot-chain/U-Boot analysis v1.1.0
 * Entry: ffffffffbfc158e8
 * Function: do_loadb
 * Subsystem: u-boot-command
 *
 * RV220W BOOT-CHAIN / U-BOOT SEMANTIC ANNOTATION v1.1.0
 * Region: early-boot-and-board-support
 * Subsystem: u-boot-command
 * Evidence: U-Boot command-table entry
 * Confidence: high for identity; medium for exact types
 * Interpretation: U-Boot command handler recovered from the command-table record. Name identity is high confidence; detailed semantics follow the reconstructed C, strings and callees.
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
 * 
 * Recovered from U-Boot command table: command='loadb', maxargs=3, repeatable=0, usage=''.
 */

/* RV220W BOOT-CHAIN / U-BOOT SEMANTIC ANNOTATION v1.1.0
   Region: early-boot-and-board-support
   Subsystem: u-boot-command
   Evidence: U-Boot command-table entry
   Confidence: high for identity; medium for exact types
   Interpretation: U-Boot command handler recovered from the command-table record. Name identity is
   high confidence; detailed semantics follow the reconstructed C, strings and callees.
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
   switch writes without readback and recovery safeguards.
   
   Recovered from U-Boot command table: command='loadb', maxargs=3, repeatable=0, usage=''. */

bool do_loadb(undefined8 param_1,undefined8 param_2,long param_3,long param_4)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  int *piVar5;
  long lVar6;
  int iVar7;
  byte bVar8;
  byte bVar9;
  byte bVar10;
  char cVar11;
  int iVar12;
  uint *puVar13;
  undefined4 *puVar14;
  long lVar15;
  long lVar16;
  long lVar17;
  long lVar18;
  undefined8 unaff_s0;
  int iVar19;
  undefined8 unaff_s1;
  undefined8 unaff_s2;
  uint uVar21;
  ulong uVar20;
  undefined8 unaff_s3;
  uint uVar22;
  undefined8 unaff_s4;
  ulong uVar23;
  uint uVar24;
  undefined8 unaff_s5;
  undefined8 unaff_s6;
  int iVar25;
  undefined8 unaff_s7;
  code *pcVar26;
  long in_k0;
  long lVar27;
  undefined8 unaff_s8;
  undefined8 in_ra;
  
  lVar27 = (long)((int)&stack0x00000000 + -0x80);
  *(undefined1 **)(lVar27 + 0x60) = &_gp;
  *(undefined8 *)(lVar27 + 0x68) = unaff_s8;
  piVar5 = (int *)(long)DAT_ffffffffbfc43d48;
  pcVar26 = (code *)(long)DAT_ffffffffbfc43f0c;
  iVar12 = DAT_ffffffffbfc436f4 + -0x4378;
  *(undefined8 *)(lVar27 + 0x58) = unaff_s7;
  *(undefined8 *)(lVar27 + 0x48) = unaff_s5;
  *(undefined8 *)(lVar27 + 0x28) = unaff_s1;
  *(undefined8 *)(lVar27 + 0x20) = unaff_s0;
  *(undefined8 *)(lVar27 + 0x70) = in_ra;
  *(undefined8 *)(lVar27 + 0x50) = unaff_s6;
  *(undefined8 *)(lVar27 + 0x40) = unaff_s4;
  *(undefined8 *)(lVar27 + 0x38) = unaff_s3;
  *(undefined8 *)(lVar27 + 0x30) = unaff_s2;
  iVar1 = *(int *)(in_k0 + 8);
  iVar7 = *piVar5;
  lVar6 = (*pcVar26)(iVar12);
  iVar12 = iVar1;
  if (lVar6 != 0) {
    iVar12 = (*(code *)(long)DAT_ffffffffbfc438b0)(lVar6,0,0);
  }
  if ((1 < param_3) &&
     (iVar7 = (*(code *)(long)DAT_ffffffffbfc438b0)(*(undefined4 *)(param_4 + 4),0,0x10), iVar7 == 0
     )) {
    iVar7 = *(int *)(long)DAT_ffffffffbfc43d48;
  }
  if (((param_3 != 3) ||
      (iVar12 = (*(code *)(long)DAT_ffffffffbfc438b0)(*(undefined4 *)(param_4 + 8),0,10),
      iVar25 = iVar1, iVar12 != 0)) && (iVar25 = iVar12, iVar25 != iVar1)) {
    (*(code *)(long)DAT_ffffffffbfc4400c)(DAT_ffffffffbfc436f4 + -0x4360,iVar25);
    (*(code *)(long)DAT_ffffffffbfc4400c)(DAT_ffffffffbfc436f4 + -0x4328,iVar7,iVar25);
    (*(code *)(long)DAT_ffffffffbfc43b18)(50000);
    pcVar26 = (code *)(long)DAT_ffffffffbfc43da4;
    *(int *)(in_k0 + 8) = iVar25;
    (*pcVar26)();
    (*(code *)(long)DAT_ffffffffbfc43b18)(50000);
  }
  pcVar26 = (code *)(long)DAT_ffffffffbfc43fb8;
  *(int *)(long)DAT_ffffffffbfc43c74 = DAT_ffffffffbfc436fc + 0x52e4;
  *(int *)(long)DAT_ffffffffbfc43a1c = DAT_ffffffffbfc436fc + 0x5314;
  *(undefined1 *)(long)DAT_ffffffffbfc43928 = 0xd;
  *(undefined1 *)(long)DAT_ffffffffbfc4389c = 0x23;
  *(int *)((long)DAT_ffffffffbfc436f4 + 0x4bdc) = iVar7;
  *(undefined4 *)(long)DAT_ffffffffbfc4375c = 0;
  *(undefined1 *)(long)DAT_ffffffffbfc43d08 = 0;
  (*pcVar26)();
  lVar6 = (long)DAT_ffffffffbfc436f4;
  uVar2 = *(undefined4 *)(long)DAT_ffffffffbfc43ca0;
  uVar3 = *(undefined4 *)((long)DAT_ffffffffbfc436f4 + 0x4bd4);
  *(undefined4 *)((long)DAT_ffffffffbfc436f4 + 0x4be4) =
       *(undefined4 *)((long)DAT_ffffffffbfc436f4 + 0x4be0);
  *(undefined4 *)((long)DAT_ffffffffbfc436f4 + 0x4bcc) = *(undefined4 *)(lVar6 + 0x4bc8);
  *(undefined4 *)((long)DAT_ffffffffbfc436f4 + 0x4bd0) = uVar2;
  *(undefined4 *)((long)DAT_ffffffffbfc436f4 + 0x4bd8) = uVar3;
  uVar24 = 0;
  uVar21 = 0xffffffff;
  do {
    while( true ) {
      *(int *)(long)DAT_ffffffffbfc43b84 = DAT_ffffffffbfc437c0;
      while (lVar6 = (*(code *)(long)DAT_ffffffffbfc43e94)(), lVar6 != 1) {
        iVar12 = 0;
        if (lVar6 == 3) goto LAB_ffffffffbfc15dd8;
      }
      bVar8 = (*(code *)(long)DAT_ffffffffbfc43e94)();
      uVar22 = uVar21;
      if (((long)(char)bVar8 & 0xe0U) != 0) break;
LAB_ffffffffbfc15d48:
      iVar12 = DAT_ffffffffbfc43d4c;
      lVar6 = (long)DAT_ffffffffbfc436f4;
      uVar2 = *(undefined4 *)((long)DAT_ffffffffbfc436f4 + 0x4bd0);
      uVar3 = *(undefined4 *)((long)DAT_ffffffffbfc436f4 + 0x4bd8);
      *(undefined4 *)((long)DAT_ffffffffbfc436f4 + 0x4be0) =
           *(undefined4 *)((long)DAT_ffffffffbfc436f4 + 0x4be4);
      *(undefined4 *)((long)DAT_ffffffffbfc436f4 + 0x4bc8) = *(undefined4 *)(lVar6 + 0x4bcc);
      *(undefined4 *)(long)DAT_ffffffffbfc43ca0 = uVar2;
      *(undefined4 *)((long)DAT_ffffffffbfc436f4 + 0x4bd4) = uVar3;
LAB_ffffffffbfc15da8:
      (*(code *)(long)iVar12)(uVar24);
      uVar21 = uVar22;
    }
    bVar9 = (*(code *)(long)DAT_ffffffffbfc43e94)();
    if (((long)(char)bVar9 & 0xe0U) == 0) goto LAB_ffffffffbfc15d48;
    uVar22 = (int)(char)bVar9 - 0x20U & 0xff;
    lVar16 = (long)DAT_ffffffffbfc436f4;
    lVar6 = (long)DAT_ffffffffbfc436f4;
    lVar17 = (long)DAT_ffffffffbfc436f4;
    puVar14 = (undefined4 *)(long)DAT_ffffffffbfc43ca0;
    lVar18 = (long)DAT_ffffffffbfc436f4;
    lVar15 = (long)DAT_ffffffffbfc436f4;
    if (uVar22 == uVar21) {
      uVar2 = *(undefined4 *)(lVar18 + 0x4bd8);
      *(undefined4 *)((long)DAT_ffffffffbfc436f4 + 0x4be0) =
           *(undefined4 *)((long)DAT_ffffffffbfc436f4 + 0x4be4);
      *(undefined4 *)(lVar6 + 0x4bc8) = *(undefined4 *)(lVar16 + 0x4bcc);
      *puVar14 = *(undefined4 *)(lVar17 + 0x4bd0);
      *(undefined4 *)(lVar15 + 0x4bd4) = uVar2;
    }
    else {
      uVar2 = *puVar14;
      *(undefined4 *)((long)DAT_ffffffffbfc436f4 + 0x4be4) =
           *(undefined4 *)((long)DAT_ffffffffbfc436f4 + 0x4be0);
      *(undefined4 *)(lVar16 + 0x4bcc) = *(undefined4 *)(lVar6 + 0x4bc8);
      *(undefined4 *)(lVar17 + 0x4bd0) = uVar2;
      *(undefined4 *)(lVar18 + 0x4bd8) = *(undefined4 *)(lVar15 + 0x4bd4);
    }
    bVar10 = (*(code *)(long)DAT_ffffffffbfc43e94)();
    uVar23 = (ulong)(char)bVar10;
    uVar24 = uVar22;
    if ((uVar23 & 0xe0) == 0) goto LAB_ffffffffbfc15d48;
    uVar21 = (int)(char)bVar8 - 0x20U & 0xff;
    iVar19 = (uint)bVar8 + (uint)bVar10 + (uint)bVar9;
    uVar20 = (ulong)iVar19;
    iVar12 = uVar21 - 2;
    if (uVar21 == 0) {
      bVar8 = (*(code *)(long)DAT_ffffffffbfc43e94)();
      if ((((long)(char)bVar8 & 0xe0U) != 0) &&
         (bVar9 = (*(code *)(long)DAT_ffffffffbfc43e94)(), ((long)(char)bVar9 & 0xe0U) != 0)) {
        bVar10 = (*(code *)(long)DAT_ffffffffbfc43e94)();
        if (((long)(char)bVar10 & 0xe0U) != 0) {
          iVar12 = (uint)bVar8 + iVar19 + (uint)bVar9;
          if ((long)(char)bVar10 ==
              (long)(int)((iVar12 + ((uint)((ulong)(long)iVar12 >> 6) & 3) & 0x3f) + 0x20)) {
            uVar20 = (ulong)(int)(iVar12 + (uint)bVar10);
            iVar12 = ((int)(char)bVar8 - 0x20U & 0xff) * 0x5f + ((int)(char)bVar9 - 0x20U & 0xff);
            goto LAB_ffffffffbfc15cf0;
          }
        }
      }
      goto LAB_ffffffffbfc15d48;
    }
LAB_ffffffffbfc15cf0:
    while( true ) {
      if (iVar12 < 2) break;
      bVar8 = (*(code *)(long)DAT_ffffffffbfc43e94)();
      iVar19 = DAT_ffffffffbfc437c0;
      if (((long)(char)bVar8 & 0xe0U) == 0) goto LAB_ffffffffbfc15d48;
      if (uVar23 == 0x44) {
        (*(code *)(long)DAT_ffffffffbfc43bb8)((long)(char)bVar8);
      }
      else {
        puVar13 = (uint *)(long)DAT_ffffffffbfc43b84;
        if (uVar23 == 0x53) {
          uVar21 = *puVar13;
          *(byte *)(long)(int)uVar21 = bVar8;
          *puVar13 = uVar21 + 1;
          if (iVar19 + 0x14U <= uVar21 + 1) {
            *puVar13 = uVar21;
          }
        }
      }
      iVar12 = iVar12 + -1;
      uVar20 = (ulong)(int)((int)uVar20 + (uint)bVar8);
    }
    cVar11 = (*(code *)(long)DAT_ffffffffbfc43e94)();
    if (((((long)cVar11 & 0xe0U) == 0) ||
        ((long)cVar11 != (long)(int)(((int)uVar20 + ((uint)(uVar20 >> 6) & 3) & 0x3f) + 0x20))) ||
       (cVar11 = (*(code *)(long)DAT_ffffffffbfc43e94)(), cVar11 != '\r'))
    goto LAB_ffffffffbfc15d48;
    iVar12 = DAT_ffffffffbfc43f74;
    if (uVar23 == 0x53) goto LAB_ffffffffbfc15da8;
    (*(code *)(long)DAT_ffffffffbfc43794)(uVar22);
    uVar21 = uVar22;
    if (uVar23 == 0x42) {
      iVar12 = *(int *)((long)DAT_ffffffffbfc436f4 + 0x4bd4) -
               *(int *)((long)DAT_ffffffffbfc436f4 + 0x4bdc);
LAB_ffffffffbfc15dd8:
      iVar19 = 0;
      do {
        iVar19 = iVar19 + 1;
        lVar6 = (*(code *)(long)DAT_ffffffffbfc43c5c)();
        if (lVar6 != 0) {
          (*(code *)(long)DAT_ffffffffbfc43e94)();
        }
        (*(code *)(long)DAT_ffffffffbfc43b18)(1000);
        iVar4 = DAT_ffffffffbfc436f4;
      } while (iVar19 != 100);
      (*(code *)(long)DAT_ffffffffbfc43e48)(iVar7,iVar12);
      (*(code *)(long)DAT_ffffffffbfc4400c)(DAT_ffffffffbfc436f4 + -0x42e8,iVar12,iVar12);
      (*(code *)(long)DAT_ffffffffbfc439a4)(lVar27,iVar4 + -0x42c0,iVar12);
      (*(code *)(long)DAT_ffffffffbfc43b14)(DAT_ffffffffbfc436f0 + 0x7b80,lVar27);
      (*(code *)(long)DAT_ffffffffbfc439a4)(lVar27,iVar4 + -0x42c0,iVar7);
      (*(code *)(long)DAT_ffffffffbfc43b14)(DAT_ffffffffbfc436f0 + 0x7b70,lVar27);
      (*(code *)(long)DAT_ffffffffbfc43944)();
      if (iVar7 != -1) {
        (*(code *)(long)DAT_ffffffffbfc4400c)(DAT_ffffffffbfc436f4 + -0x4290,iVar7);
      }
      else {
        (*(code *)(long)DAT_ffffffffbfc4400c)(DAT_ffffffffbfc436f4 + -0x42b8);
      }
      if (iVar25 != iVar1) {
        (*(code *)(long)DAT_ffffffffbfc4400c)(DAT_ffffffffbfc436f4 + -0x4270,iVar1);
        (*(code *)(long)DAT_ffffffffbfc43b18)(50000);
        pcVar26 = (code *)(long)DAT_ffffffffbfc43da4;
        *(int *)(in_k0 + 8) = iVar1;
        (*pcVar26)();
        (*(code *)(long)DAT_ffffffffbfc43b18)(50000);
      }
      return iVar7 == -1;
    }
  } while( true );
}

