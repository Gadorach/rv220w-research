/*
 * Ghidra reconstructed C; not original Cisco source.
 * RV220W boot-chain/U-Boot analysis v1.1.0
 * Entry: ffffffffbfc17f30
 * Function: FUN_ffffffffbfc17f30
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

void FUN_ffffffffbfc17f30(ushort *param_1,uint param_2,uint param_3)

{
  ushort uVar1;
  ushort uVar2;
  short sVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  undefined8 unaff_s0;
  short *psVar7;
  undefined8 unaff_s1;
  uint uVar8;
  undefined8 unaff_s2;
  uint uVar9;
  undefined8 unaff_s3;
  undefined8 unaff_s4;
  short *psVar10;
  int iVar11;
  undefined8 unaff_s5;
  uint uVar12;
  undefined8 unaff_s6;
  ushort *puVar13;
  undefined8 unaff_s7;
  int iVar15;
  uint *puVar16;
  undefined8 unaff_s8;
  uint uVar17;
  undefined8 in_ra;
  int iVar14;
  
  puVar16 = (uint *)(long)((int)&stack0x00000000 + -0x70);
  *(undefined1 **)(puVar16 + 0x14) = &_gp;
  *(undefined8 *)(puVar16 + 0xc) = unaff_s4;
  iVar14 = DAT_ffffffffbfc43cd8;
  iVar11 = DAT_ffffffffbfc43b30;
  *(undefined8 *)(puVar16 + 0x10) = unaff_s6;
  iVar14 = iVar14 + 4;
  *(undefined8 *)(puVar16 + 0xe) = unaff_s5;
  uVar12 = 0;
  *(undefined8 *)(puVar16 + 10) = unaff_s3;
  *(undefined8 *)(puVar16 + 0x18) = in_ra;
  *(undefined8 *)(puVar16 + 0x16) = unaff_s8;
  *(undefined8 *)(puVar16 + 0x12) = unaff_s7;
  *(undefined8 *)(puVar16 + 8) = unaff_s2;
  *(undefined8 *)(puVar16 + 6) = unaff_s1;
  *(undefined8 *)(puVar16 + 4) = unaff_s0;
  *puVar16 = param_2 & 0xff;
  puVar16[1] = param_3 & 0xff;
  do {
    puVar13 = (ushort *)(long)iVar14;
    psVar10 = (short *)(long)iVar11;
    if ((*puVar16 <= uVar12) && (uVar12 <= puVar16[1])) {
      uVar1 = *param_1;
      uVar9 = (uint)uVar1;
      iVar15 = 0;
      (*(code *)(long)DAT_ffffffffbfc4400c)
                (DAT_ffffffffbfc436f4 + -0x2d58,*psVar10,uVar9,*(undefined4 *)(psVar10 + 2));
      uVar2 = *puVar13;
      for (uVar17 = 0; uVar17 < uVar2; uVar17 = uVar17 + 1) {
        psVar7 = (short *)(long)(iVar15 + *(int *)(puVar13 + -2));
        uVar5 = (uint)(ushort)psVar7[2] << ((ushort)psVar7[1] & 0x1f) & 0xffff;
        uVar8 = uVar9 & uVar5;
        (*(code *)(long)DAT_ffffffffbfc4400c)(DAT_ffffffffbfc436f4 + -0x2d28,uVar5,uVar8,*psVar10);
        sVar3 = *psVar10;
        if (sVar3 == 0) {
          if (psVar7[1] == 6) {
            if ((uVar9 & 0x2040) == 0x40) {
              iVar6 = DAT_ffffffffbfc436f4 + -0x2d10;
            }
            else if ((uVar9 & 0x2040) == 0x2000) {
              iVar6 = DAT_ffffffffbfc436f4 + -0x2d08;
            }
            else if ((uVar1 & 0x2040) == 0) {
              iVar6 = DAT_ffffffffbfc436f4 + -0x5ff8;
            }
            else {
              iVar6 = DAT_ffffffffbfc436f4 + -0x2d00;
            }
            (*(code *)(long)DAT_ffffffffbfc4400c)
                      (DAT_ffffffffbfc436f4 + -0x2cf8,6,0xd,uVar1 >> 6 & 1,uVar1 >> 0xd & 1,iVar6);
          }
          else {
            if (psVar7[1] != 8) goto LAB_ffffffffbfc181ac;
            if ((uVar1 >> 8 & 1) == 0) {
              iVar6 = DAT_ffffffffbfc436f4 + -0x2cc8;
            }
            else {
              iVar6 = DAT_ffffffffbfc436f4 + -0x2cc0;
            }
            (*(code *)(long)DAT_ffffffffbfc4400c)
                      (DAT_ffffffffbfc436f4 + -0x2cb8,8,uVar1 >> 8 & 1,iVar6);
          }
        }
        else {
          if (sVar3 == 4) {
            if (psVar7[1] == 0) {
              uVar2 = uVar1 & psVar7[2];
              sVar3 = *psVar7;
              if (uVar2 == 1) {
                iVar6 = DAT_ffffffffbfc436f4 + -0x2c98;
              }
              else if (uVar2 == 2) {
                iVar6 = DAT_ffffffffbfc436f4 + -0x2c88;
              }
              else {
                iVar6 = DAT_ffffffffbfc436f4 + -0x2d00;
              }
              iVar4 = DAT_ffffffffbfc436f4 + -0x2c70;
LAB_ffffffffbfc1819c:
              (*(code *)(long)DAT_ffffffffbfc4400c)(iVar4,sVar3,0,uVar2,iVar6);
              goto LAB_ffffffffbfc18200;
            }
          }
          else if ((sVar3 == 5) && (psVar7[1] == 0)) {
            uVar2 = uVar1 & psVar7[2];
            sVar3 = *psVar7;
            if (uVar2 == 1) {
              iVar6 = DAT_ffffffffbfc436f4 + -0x2c98;
            }
            else if (uVar2 == 2) {
              iVar6 = DAT_ffffffffbfc436f4 + -0x2c88;
            }
            else {
              iVar6 = DAT_ffffffffbfc436f4 + -0x2d00;
            }
            iVar4 = DAT_ffffffffbfc436f4 + -0x2c50;
            goto LAB_ffffffffbfc1819c;
          }
LAB_ffffffffbfc181ac:
          if (*psVar7 == psVar7[1]) {
            (*(code *)(long)DAT_ffffffffbfc4400c)(DAT_ffffffffbfc436f4 + -0x2c28,psVar7[1]);
            uVar2 = psVar7[1];
          }
          else {
            (*(code *)(long)DAT_ffffffffbfc4400c)(DAT_ffffffffbfc436f4 + -0x2c20);
            uVar2 = psVar7[1];
          }
          (*(code *)(long)DAT_ffffffffbfc4400c)
                    (DAT_ffffffffbfc436f4 + -0x2c18,(int)uVar8 >> (uVar2 & 0x1f),
                     *(undefined4 *)(psVar7 + 4));
        }
LAB_ffffffffbfc18200:
        iVar15 = iVar15 + 0xc;
        (*(code *)(long)DAT_ffffffffbfc4400c)(DAT_ffffffffbfc436f4 + 0x1150);
        uVar2 = *puVar13;
      }
      (*(code *)(long)DAT_ffffffffbfc4400c)(DAT_ffffffffbfc436f4 + 0x1150);
    }
    uVar12 = uVar12 + 1;
    iVar14 = iVar14 + 8;
    param_1 = (ushort *)(long)((int)param_1 + 2);
    iVar11 = iVar11 + 8;
    if (uVar12 == 6) {
      return;
    }
  } while( true );
}

