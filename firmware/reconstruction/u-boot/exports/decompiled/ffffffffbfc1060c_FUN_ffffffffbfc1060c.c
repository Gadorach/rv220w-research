/*
 * Ghidra reconstructed C; not original Cisco source.
 * RV220W boot-chain/U-Boot analysis v1.1.0
 * Entry: ffffffffbfc1060c
 * Function: FUN_ffffffffbfc1060c
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

int FUN_ffffffffbfc1060c(void)

{
  bool bVar1;
  int iVar2;
  long lVar3;
  short sVar8;
  ushort uVar9;
  byte bVar10;
  uint uVar5;
  char cVar11;
  char cVar12;
  char cVar13;
  ulong uVar4;
  int iVar6;
  uint uVar7;
  undefined1 uVar14;
  long lVar15;
  int iVar16;
  undefined8 uVar17;
  long lVar18;
  long lVar19;
  undefined8 unaff_s0;
  int *piVar20;
  int iVar21;
  undefined8 unaff_s1;
  int iVar22;
  int iVar23;
  undefined8 unaff_s2;
  int iVar24;
  undefined8 unaff_s3;
  int iVar25;
  undefined8 unaff_s4;
  uint uVar26;
  undefined8 unaff_s5;
  undefined8 unaff_s6;
  undefined8 unaff_s7;
  code *pcVar27;
  int *piVar28;
  undefined8 unaff_s8;
  int iVar29;
  undefined8 in_ra;
  
  piVar28 = (int *)(long)((int)&stack0x00000000 + -0x70);
  *(undefined1 **)(piVar28 + 0x14) = &_gp;
  *(undefined8 *)(piVar28 + 0x18) = in_ra;
  *(undefined8 *)(piVar28 + 0x16) = unaff_s8;
  pcVar27 = (code *)(long)DAT_ffffffffbfc43d90;
  *(undefined8 *)(piVar28 + 0x12) = unaff_s7;
  *(undefined8 *)(piVar28 + 0x10) = unaff_s6;
  *(undefined8 *)(piVar28 + 0xe) = unaff_s5;
  *(undefined8 *)(piVar28 + 0xc) = unaff_s4;
  *(undefined8 *)(piVar28 + 10) = unaff_s3;
  *(undefined8 *)(piVar28 + 8) = unaff_s2;
  *(undefined8 *)(piVar28 + 6) = unaff_s1;
  *(undefined8 *)(piVar28 + 4) = unaff_s0;
  lVar3 = (*pcVar27)();
  *(int *)((long)DAT_ffffffffbfc436f4 + 0x4a80) = (int)lVar3;
  if (lVar3 != 0) {
    (*(code *)(long)DAT_ffffffffbfc4400c)(DAT_ffffffffbfc436f4 + -0x54f0);
  }
  lVar3 = (long)DAT_ffffffffbfc43fc4;
  *(undefined4 *)(lVar3 + 8) = 0xffff;
  *(undefined1 *)(lVar3 + 0xa0c) = 1;
  *(undefined2 *)(lVar3 + 0xa1e) = 0xf0;
  *(undefined4 *)(lVar3 + 0xc) = 0xbdc00000;
  do {
    *(undefined1 *)((long)DAT_ffffffffbfc43fc4 + 0xa0d) = 1;
    while( true ) {
      piVar20 = (int *)(long)DAT_ffffffffbfc43fc4;
      iVar22 = DAT_ffffffffbfc436fc + -0xd40;
      if (*(byte *)(piVar20 + 0x283) < *(byte *)((long)piVar20 + 0xa0d)) break;
      (*(code *)(long)iVar22)(piVar20,0,0,0xf0);
      uVar17 = 0xaa;
      if (*(char *)((long)piVar20 + 0xa0d) != '\x01') {
        uVar17 = 0x55;
      }
      (*(code *)(long)iVar22)(piVar20,0,uVar17,0x98);
      uVar17 = 0x20;
      if (*(char *)((long)piVar20 + 0xa0d) != '\x01') {
        uVar17 = 0x10;
      }
      pcVar27 = (code *)(long)(DAT_ffffffffbfc436fc + -0xb9c);
      lVar3 = (*pcVar27)(piVar20,0,uVar17,0x51);
      if (lVar3 != 0) {
        uVar17 = 0x22;
        if (*(char *)((long)piVar20 + 0xa0d) != '\x01') {
          uVar17 = 0x11;
        }
        lVar3 = (*pcVar27)(piVar20,0,uVar17,0x52);
        if (lVar3 != 0) {
          uVar17 = 0x24;
          if (*(char *)((long)piVar20 + 0xa0d) != '\x01') {
            uVar17 = 0x12;
          }
          lVar3 = (*pcVar27)(piVar20,0,uVar17,0x59);
          if (lVar3 != 0) {
            iVar22 = 1;
            iVar24 = 0x50;
            if (*(char *)((long)piVar20 + 0xa0d) == '\x01') {
              iVar22 = 2;
            }
            else {
              iVar24 = 0x28;
            }
            lVar3 = (long)DAT_ffffffffbfc43fc4;
            sVar8 = (*(code *)(long)DAT_ffffffffbfc438b8)(lVar3,iVar24 + iVar22);
            uVar17 = 0x50;
            cVar11 = *(char *)(lVar3 + 0xa0d);
            pcVar27 = (code *)(long)DAT_ffffffffbfc438b8;
            *(short *)(lVar3 + 0xa20) = sVar8 << 8;
            if (cVar11 != '\x01') {
              uVar17 = 0x28;
            }
            uVar9 = (*pcVar27)(lVar3,uVar17);
            *(ushort *)(lVar3 + 0xa20) = sVar8 << 8 | uVar9;
            if (cVar11 == '\x01') {
              uVar17 = 0x26;
            }
            else {
              uVar17 = 0x13;
            }
            lVar3 = (*(code *)(long)DAT_ffffffffbfc438b8)(DAT_ffffffffbfc43fc4,uVar17);
            lVar15 = (long)DAT_ffffffffbfc43fc4;
            *(short *)(lVar15 + 0xa1c) = (short)lVar3;
            if ((lVar3 == 2) || (lVar3 == 4)) {
              *(undefined2 *)((long)DAT_ffffffffbfc43fc4 + 0xa1e) = 0xf0;
            }
            else {
              *(undefined2 *)(lVar15 + 0xa1e) = 0xf0;
            }
            lVar3 = (long)DAT_ffffffffbfc43fc4;
            bVar10 = *(byte *)(lVar3 + 0xa0d);
            if (bVar10 == 0) {
              trap(7);
            }
            piVar28[1] = (uint)*(byte *)(lVar3 + 0xa0c) / (uint)bVar10;
            if (bVar10 == 1) {
              iVar22 = (*(code *)(long)DAT_ffffffffbfc438b8)(lVar3,0x2c);
              uVar5 = (*(code *)(long)DAT_ffffffffbfc438b8)(lVar3,0x2a);
              uVar5 = (iVar22 << 8 | uVar5) & 0xffff;
              cVar11 = (*(code *)(long)DAT_ffffffffbfc438b8)(lVar3,uVar5 << 1);
              cVar12 = (*(code *)(long)DAT_ffffffffbfc438b8)(lVar3,(uVar5 + 1) * 2);
              cVar13 = (*(code *)(long)DAT_ffffffffbfc438b8)(lVar3,(uVar5 + 2) * 2);
            }
            else {
              iVar22 = (*(code *)(long)DAT_ffffffffbfc438b8)(lVar3,0x16);
              uVar5 = (*(code *)(long)DAT_ffffffffbfc438b8)(lVar3,0x15);
              uVar5 = (iVar22 << 8 | uVar5) & 0xffff;
              cVar11 = (*(code *)(long)DAT_ffffffffbfc438b8)(lVar3,uVar5);
              cVar12 = (*(code *)(long)DAT_ffffffffbfc438b8)(lVar3,uVar5 + 1);
              cVar13 = (*(code *)(long)DAT_ffffffffbfc438b8)(lVar3,uVar5 + 2);
            }
            if ((((cVar11 == 'P') && (cVar12 == 'R')) && (cVar13 == 'I')) && (uVar5 != 0)) {
              iVar22 = uVar5 + 0xf;
              if (bVar10 == 1) {
                iVar22 = iVar22 * 2;
              }
              lVar3 = (*(code *)(long)DAT_ffffffffbfc438b8)(DAT_ffffffffbfc43fc4,iVar22);
            }
            else {
              lVar3 = 0;
            }
            uVar17 = 0x58;
            if (bVar10 != 1) {
              uVar17 = 0x2c;
            }
            uVar4 = (*(code *)(long)DAT_ffffffffbfc438b8)(DAT_ffffffffbfc43fc4,uVar17);
            if (4 < uVar4) {
              (*(code *)(long)DAT_ffffffffbfc4400c)(DAT_ffffffffbfc436f4 + -0x54c8,uVar4,4);
              uVar4 = 4;
            }
            if (lVar3 == 3) {
              iVar22 = (int)uVar4 + -1;
              piVar28[2] = -1;
              piVar28[3] = -1;
            }
            else {
              iVar22 = 0;
              piVar28[2] = (int)uVar4;
              piVar28[3] = 1;
            }
            iVar24 = iVar22 * 4 + 2;
            uVar5 = 0;
            iVar29 = -0x42400000;
            *piVar28 = piVar28[3] << 2;
            for (; lVar3 = (long)DAT_ffffffffbfc43fc4, iVar22 != piVar28[2];
                iVar22 = iVar22 + piVar28[3]) {
              if (*(char *)(lVar3 + 0xa0d) == '\x01') {
                iVar6 = (*(code *)(long)DAT_ffffffffbfc438b8)(lVar3,iVar24 * 2 + 0x58);
                uVar7 = (*(code *)(long)DAT_ffffffffbfc438b8)(lVar3,iVar24 * 2 + 0x56);
                uVar26 = (*(code *)(long)DAT_ffffffffbfc438b8)(lVar3,iVar24 * 2 + 0x5c);
                uVar26 = (iVar6 << 8 | uVar7) << 8 | uVar26;
                iVar16 = 0x5a;
                iVar6 = iVar24 << 1;
              }
              else {
                iVar6 = (*(code *)(long)DAT_ffffffffbfc438b8)(lVar3,iVar24 + 0x2c);
                uVar7 = (*(code *)(long)DAT_ffffffffbfc438b8)(lVar3,iVar24 + 0x2b);
                uVar26 = (*(code *)(long)DAT_ffffffffbfc438b8)(lVar3,iVar24 + 0x2e);
                uVar26 = (iVar6 << 8 | uVar7) << 8 | uVar26;
                iVar16 = 0x2d;
                iVar6 = iVar24;
              }
              uVar7 = (*(code *)(long)DAT_ffffffffbfc438b8)(DAT_ffffffffbfc43fc4,iVar16 + iVar6);
              uVar7 = uVar26 << 8 | uVar7;
              uVar26 = uVar7 & 0xffff;
              if (uVar26 == 0) {
                iVar6 = 0x80;
              }
              else {
                iVar6 = uVar26 << 8;
              }
              iVar16 = piVar28[1];
              iVar25 = 0;
              iVar21 = uVar5 + DAT_ffffffffbfc43fc4 + 0x80c;
              iVar23 = uVar5 * 4 + DAT_ffffffffbfc43fc4 + 0xc;
              while( true ) {
                iVar2 = DAT_ffffffffbfc436fc;
                lVar3 = (long)DAT_ffffffffbfc43fc4;
                bVar1 = (int)((uVar7 >> 0x10) + 1) <= iVar25;
                iVar25 = iVar25 + 1;
                if (bVar1) break;
                cVar11 = *(char *)(lVar3 + 0xa0d);
                uVar17 = 4;
                *(int *)(long)iVar23 = iVar29;
                if (cVar11 != '\x01') {
                  uVar17 = 2;
                }
                iVar29 = iVar29 + iVar6 * iVar16;
                uVar14 = (*(code *)(long)(iVar2 + -0xaac))(lVar3,uVar5,uVar17,1);
                iVar23 = iVar23 + 4;
                *(undefined1 *)(long)iVar21 = uVar14;
                iVar21 = iVar21 + 1;
                uVar5 = uVar5 + 1;
              }
              iVar24 = iVar24 + *piVar28;
            }
            iVar22 = *(int *)((long)DAT_ffffffffbfc436f4 + 0x4a80);
            uVar26 = uVar5;
            if (iVar22 != 0) {
              uVar26 = uVar5 << 1;
              lVar15 = (long)(int)(uVar5 * 4 + DAT_ffffffffbfc43fc4 + 0xc);
              lVar3 = (long)(int)(uVar5 + DAT_ffffffffbfc43fc4 + 0x80c);
              lVar19 = (long)(DAT_ffffffffbfc43fc4 + 0x80c);
              lVar18 = (long)(DAT_ffffffffbfc43fc4 + 0xc);
              while( true ) {
                bVar1 = uVar26 <= uVar5;
                lVar18 = (long)((int)lVar18 + 4);
                uVar5 = uVar5 + 1;
                lVar15 = (long)((int)lVar15 + 4);
                lVar19 = (long)((int)lVar19 + 1);
                lVar3 = (long)((int)lVar3 + 1);
                if (bVar1) break;
                uVar14 = *(undefined1 *)(lVar19 + -1);
                *(int *)(lVar15 + -4) = *(int *)(lVar18 + -4) + 0x800000;
                *(undefined1 *)(lVar3 + -1) = uVar14;
              }
            }
            piVar20 = (int *)(long)DAT_ffffffffbfc43fc4;
            pcVar27 = (code *)(long)DAT_ffffffffbfc438b8;
            uVar17 = 0x4e;
            *(short *)(piVar20 + 1) = (short)uVar26;
            if (*(char *)((long)piVar20 + 0xa0d) != '\x01') {
              uVar17 = 0x27;
            }
            uVar5 = (*pcVar27)(piVar20,uVar17);
            iVar24 = piVar28[1];
            *piVar20 = iVar24 << (uVar5 & 0x1f);
            if (iVar22 != 0) {
              *piVar20 = (iVar24 << (uVar5 & 0x1f)) << 1;
            }
            if (*(char *)((long)piVar20 + 0xa0d) == '\x01') {
              (*(code *)(long)DAT_ffffffffbfc438b8)(piVar20,0x56);
              uVar17 = 0x54;
            }
            else {
              (*(code *)(long)DAT_ffffffffbfc438b8)(DAT_ffffffffbfc43fc4,0x2b);
              uVar17 = 0x2a;
            }
            lVar3 = (long)DAT_ffffffffbfc43fc4;
            uVar5 = (*(code *)(long)DAT_ffffffffbfc438b8)(lVar3,uVar17);
            *(short *)(lVar3 + 0xa0e) = (short)(1 << (uVar5 & 0x1f));
            if (*(char *)(lVar3 + 0xa0d) == '\x01') {
              uVar5 = (*(code *)(long)DAT_ffffffffbfc438b8)(lVar3,0x42);
              uVar17 = 0x4a;
            }
            else {
              uVar5 = (*(code *)(long)DAT_ffffffffbfc438b8)(lVar3,0x21);
              uVar17 = 0x25;
            }
            lVar3 = (long)DAT_ffffffffbfc43fc4;
            uVar26 = (*(code *)(long)DAT_ffffffffbfc438b8)(lVar3,uVar17);
            *(int *)(lVar3 + 0xa10) = (1 << (uVar5 & 0x1f)) << (uVar26 & 0x1f);
            if (*(char *)(lVar3 + 0xa0d) == '\x01') {
              uVar5 = (*(code *)(long)DAT_ffffffffbfc438b8)(lVar3,0x40);
              uVar17 = 0x48;
            }
            else {
              uVar5 = (*(code *)(long)DAT_ffffffffbfc438b8)(lVar3,0x20);
              uVar17 = 0x24;
            }
            lVar3 = (long)DAT_ffffffffbfc43fc4;
            uVar26 = (*(code *)(long)DAT_ffffffffbfc438b8)(lVar3,uVar17);
            *(int *)(lVar3 + 0xa18) = (1 << (uVar5 & 0x1f)) << (uVar26 & 0x1f);
            if (*(char *)(lVar3 + 0xa0d) == '\x01') {
              uVar5 = (*(code *)(long)DAT_ffffffffbfc438b8)(lVar3,0x3e);
              uVar17 = 0x46;
            }
            else {
              uVar5 = (*(code *)(long)DAT_ffffffffbfc438b8)(lVar3,0x1f);
              uVar17 = 0x23;
            }
            lVar3 = (long)DAT_ffffffffbfc43fc4;
            uVar26 = (*(code *)(long)DAT_ffffffffbfc438b8)(lVar3,uVar17);
            *(undefined4 *)(lVar3 + 8) = 0x1000000;
            *(uint *)(lVar3 + 0xa14) = (uint)((1 << (uVar5 & 0x1f)) << (uVar26 & 0x1f)) / 1000;
            piVar20 = (int *)(long)DAT_ffffffffbfc43fc4;
            goto LAB_ffffffffbfc10cd8;
          }
        }
      }
      *(char *)((long)DAT_ffffffffbfc43fc4 + 0xa0d) =
           *(char *)((long)DAT_ffffffffbfc43fc4 + 0xa0d) << 1;
    }
    bVar10 = *(byte *)(piVar20 + 0x283) << 1;
    *(byte *)(piVar20 + 0x283) = bVar10;
    if (8 < bVar10) {
LAB_ffffffffbfc10cd8:
      (*(code *)(long)(DAT_ffffffffbfc436fc + -0xd40))
                (piVar20,0,0,*(undefined1 *)((long)piVar20 + 0xa1f));
      iVar22 = *piVar20;
      *piVar20 = iVar22;
      if (piVar20[2] == 0xffff) {
        (*(code *)(long)DAT_ffffffffbfc4400c)
                  (DAT_ffffffffbfc436f4 + -0x54a0,0,iVar22,iVar22 << 0x14);
      }
      piVar20 = (int *)(long)DAT_ffffffffbfc43fc4;
      (*(code *)(long)DAT_ffffffffbfc43e64)(2,&DAT_ffffffffbdc00000,*piVar20 + -0x42400000,piVar20);
      (*(code *)(long)DAT_ffffffffbfc43e64)(1,&DAT_ffffffffbdc00000,0xffffffffbdc7ffff,piVar20);
      (*(code *)(long)DAT_ffffffffbfc43e64)(1,&DAT_ffffffffbfbe0000,0xffffffffbfbfffff,piVar20);
      return iVar22;
    }
  } while( true );
}

