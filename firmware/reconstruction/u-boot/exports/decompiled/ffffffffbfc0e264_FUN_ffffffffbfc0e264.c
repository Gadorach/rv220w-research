/*
 * Ghidra reconstructed C; not original Cisco source.
 * RV220W boot-chain/U-Boot analysis v1.1.0
 * Entry: ffffffffbfc0e264
 * Function: FUN_ffffffffbfc0e264
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

void FUN_ffffffffbfc0e264(char *param_1,long param_2,long param_3,ulong param_4)

{
  char cVar1;
  byte bVar2;
  byte bVar3;
  int iVar6;
  long lVar4;
  undefined2 uVar7;
  char *pcVar5;
  undefined2 *puVar8;
  int *piVar9;
  int iVar10;
  undefined8 uVar11;
  undefined8 unaff_s0;
  undefined8 unaff_s1;
  byte *pbVar12;
  code *pcVar13;
  undefined8 unaff_s2;
  undefined8 unaff_s3;
  byte *pbVar14;
  undefined8 unaff_s4;
  byte *pbVar15;
  int *piVar16;
  undefined8 in_ra;
  
  piVar16 = (int *)(long)((int)&stack0x00000000 + -0x50);
  *(undefined1 **)(piVar16 + 0xe) = &_gp;
  *(undefined8 *)(piVar16 + 10) = unaff_s3;
  *(undefined8 *)(piVar16 + 4) = unaff_s0;
  *(undefined8 *)(piVar16 + 0x10) = in_ra;
  *(undefined8 *)(piVar16 + 0xc) = unaff_s4;
  *(undefined8 *)(piVar16 + 8) = unaff_s2;
  *(undefined8 *)(piVar16 + 6) = unaff_s1;
  if (((((param_2 == 0x44) && (param_3 == 0x43)) && (0xeb < param_4)) &&
      (((cVar1 = *param_1, (byte)(cVar1 - 1U) < 2 || (cVar1 == '\x05')) || (cVar1 == '\x06')))) &&
     ((param_1[1] == '\x01' && (param_1[2] == '\x06')))) {
    iVar10 = (int)param_1;
    iVar6 = (*(code *)(long)(DAT_ffffffffbfc436fc + -0x2058))(iVar10 + 4);
    if (iVar6 == *(int *)(long)DAT_ffffffffbfc43af4) {
      pcVar13 = (code *)(long)(DAT_ffffffffbfc436fc + -0x20ac);
      (*pcVar13)(DAT_ffffffffbfc43f80,iVar10 + 0x10);
      (*pcVar13)(piVar16,iVar10 + 0x14);
      if (*piVar16 != 0) {
        (*pcVar13)(DAT_ffffffffbfc43f00,iVar10 + 0x14);
      }
      (*(code *)(long)DAT_ffffffffbfc43e84)
                (DAT_ffffffffbfc43ce0,*(int *)(long)DAT_ffffffffbfc43ad4 + 6,6);
      lVar4 = (*(code *)(long)DAT_ffffffffbfc437c8)(iVar10 + 0x6c);
      if (lVar4 != 0) {
        (*(code *)(long)DAT_ffffffffbfc43fe4)(DAT_ffffffffbfc43d3c,iVar10 + 0x6c,0x80);
      }
      if (*(char *)(long)DAT_ffffffffbfc43d3c != '\0') {
        (*(code *)(long)DAT_ffffffffbfc43b14)(DAT_ffffffffbfc436f0 + 0x7740);
      }
      lVar4 = (*(code *)(long)(DAT_ffffffffbfc436fc + -0x2058))(iVar10 + 0xec);
      if (lVar4 == 0x63825363) {
        pbVar15 = (byte *)(long)(iVar10 + 0xf0 + (int)param_4);
        pbVar14 = (byte *)(long)(iVar10 + 0xf0);
LAB_ffffffffbfc0e51c:
        do {
          do {
            pbVar12 = pbVar14;
            if ((pbVar15 <= pbVar12) || (*pbVar12 == 0xff)) goto LAB_ffffffffbfc0e538;
            iVar6 = (int)pbVar12;
            pbVar14 = (byte *)(long)(iVar6 + 1);
          } while (*pbVar12 == 0);
          bVar2 = pbVar12[1];
          pbVar14 = (byte *)(long)(int)(iVar6 + (uint)bVar2 + 2);
          puVar8 = (undefined2 *)(long)DAT_ffffffffbfc43c54;
        } while (pbVar15 < pbVar14);
        *puVar8 = 0;
        bVar3 = *pbVar12;
        if (bVar3 == 0xc) {
          pcVar5 = (char *)(long)DAT_ffffffffbfc43b38;
          if (*pcVar5 != '\0') goto LAB_ffffffffbfc0e51c;
          uVar11 = 0x20;
          iVar10 = DAT_ffffffffbfc436f4 + -0x5a38;
        }
        else {
          if (bVar3 < 0xd) {
            iVar10 = DAT_ffffffffbfc43a90;
            if ((bVar3 == 3) || (iVar10 = DAT_ffffffffbfc43868, bVar3 == 6)) {
              piVar9 = (int *)(long)iVar10;
              iVar10 = *piVar9;
            }
            else {
              piVar9 = (int *)(long)DAT_ffffffffbfc43c58;
              if (bVar3 != 1) goto LAB_ffffffffbfc0e51c;
              iVar10 = *piVar9;
            }
            if (iVar10 == 0) {
              (*(code *)(long)(DAT_ffffffffbfc436fc + -0x20ac))(piVar9,iVar6 + 2);
            }
            goto LAB_ffffffffbfc0e51c;
          }
          if (bVar3 == 0x11) {
            pcVar5 = (char *)(long)DAT_ffffffffbfc43764;
            if (*pcVar5 != '\0') goto LAB_ffffffffbfc0e51c;
            uVar11 = 0x40;
            iVar10 = DAT_ffffffffbfc436f4 + -0x5a28;
          }
          else {
            if (bVar3 != 0x28) {
              if (bVar3 == 0xd) {
                if (bVar2 == 2) {
                  uVar7 = *(undefined2 *)(pbVar12 + 2);
                }
                else {
                  if (bVar2 != 4) goto LAB_ffffffffbfc0e51c;
                  uVar7 = (undefined2)*(undefined4 *)(pbVar12 + 2);
                }
                *puVar8 = uVar7;
              }
              goto LAB_ffffffffbfc0e51c;
            }
            pcVar5 = (char *)(long)DAT_ffffffffbfc43e18;
            if (*pcVar5 != '\0') goto LAB_ffffffffbfc0e51c;
            uVar11 = 0x20;
            iVar10 = DAT_ffffffffbfc436f4 + -0x5a18;
          }
        }
        uVar11 = (*(code *)(long)(DAT_ffffffffbfc436fc + -0x2110))(iVar10,uVar11);
        (*(code *)(long)DAT_ffffffffbfc43e84)(pcVar5,iVar6 + 2,uVar11);
        *(undefined1 *)(long)((int)uVar11 + (int)pcVar5) = 0;
        goto LAB_ffffffffbfc0e51c;
      }
LAB_ffffffffbfc0e538:
      (*(code *)(long)DAT_ffffffffbfc43fec)(0,0);
      pcVar5 = (char *)(*(code *)(long)DAT_ffffffffbfc43f0c)(DAT_ffffffffbfc436f4 + -0x5a08);
      if ((pcVar5 == (char *)0x0) || (*pcVar5 != 'n')) {
        (*(code *)(long)DAT_ffffffffbfc43758)();
      }
      else {
        *(undefined4 *)(long)DAT_ffffffffbfc43d80 = 3;
      }
    }
  }
  return;
}

