/*
 * Ghidra reconstructed C; not original Cisco source.
 * RV220W boot-chain/U-Boot analysis v1.1.0
 * Entry: ffffffffbfc1556c
 * Function: FUN_ffffffffbfc1556c
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

void FUN_ffffffffbfc1556c(undefined4 param_1)

{
  undefined4 uVar1;
  undefined1 uVar2;
  char cVar3;
  int *piVar4;
  uint *puVar5;
  undefined8 unaff_s0;
  int iVar6;
  undefined8 unaff_s1;
  int iVar7;
  undefined8 unaff_s2;
  long lVar8;
  int iVar9;
  undefined8 unaff_s3;
  long lVar10;
  undefined8 unaff_s4;
  undefined8 unaff_s5;
  undefined1 *puVar11;
  undefined8 unaff_s6;
  undefined8 unaff_s7;
  char *pcVar12;
  code *pcVar13;
  undefined4 *puVar14;
  undefined8 unaff_s8;
  undefined1 *puVar15;
  undefined8 in_ra;
  
  puVar14 = (undefined4 *)(long)((int)&stack0x00000000 + -0x70);
  *(undefined1 **)(puVar14 + 0x14) = &_gp;
  *(undefined8 *)(puVar14 + 0x12) = unaff_s7;
  *(undefined8 *)(puVar14 + 8) = unaff_s2;
  iVar7 = DAT_ffffffffbfc437c0;
  piVar4 = (int *)(long)DAT_ffffffffbfc43b84;
  lVar8 = (long)DAT_ffffffffbfc437c0;
  pcVar12 = (char *)(long)DAT_ffffffffbfc43928;
  *(undefined8 *)(puVar14 + 0x16) = unaff_s8;
  *(undefined8 *)(puVar14 + 0xe) = unaff_s5;
  puVar5 = (uint *)(long)DAT_ffffffffbfc4375c;
  puVar11 = (undefined1 *)(long)DAT_ffffffffbfc43d08;
  puVar15 = (undefined1 *)(long)DAT_ffffffffbfc4389c;
  iVar9 = *piVar4;
  *(undefined8 *)(puVar14 + 0x18) = in_ra;
  *(undefined8 *)(puVar14 + 0x10) = unaff_s6;
  *(undefined8 *)(puVar14 + 0xc) = unaff_s4;
  *(undefined8 *)(puVar14 + 10) = unaff_s3;
  *(undefined8 *)(puVar14 + 6) = unaff_s1;
  *(undefined8 *)(puVar14 + 4) = unaff_s0;
  *puVar14 = param_1;
  *pcVar12 = '\r';
  *puVar5 = 0;
  *puVar11 = 0;
  *puVar15 = 0x23;
  if (iVar9 == iVar7 + 0x13) {
    *piVar4 = iVar7 + 0x12;
  }
  iVar7 = *piVar4 - iVar7;
  if (iVar7 < 1) {
    iVar9 = 3;
  }
  else {
    lVar10 = (long)(DAT_ffffffffbfc436f4 + 0x4bb0);
    *(undefined1 *)(lVar10 + 4) = 0x7e;
    if (iVar7 + -1 < 1) {
      iVar9 = 4;
    }
    else {
      *(undefined1 *)(lVar10 + 5) = 0x21;
      if (iVar7 + -2 < 1) {
        iVar9 = 5;
      }
      else {
        cVar3 = *(char *)(lVar8 + 2);
        *(undefined1 *)(lVar10 + 6) = 0x20;
        *puVar5 = (int)cVar3 - 0x20U & 0xff;
        if (iVar7 + -3 < 1) {
          iVar9 = 6;
        }
        else {
          uVar2 = (*(code *)(long)DAT_ffffffffbfc438e4)(*(undefined1 *)(lVar8 + 3));
          *puVar11 = uVar2;
          *(undefined1 *)(lVar10 + 7) = 0x40;
          if (iVar7 + -4 < 1) {
            iVar9 = 7;
          }
          else {
            cVar3 = *(char *)(lVar8 + 4);
            *(undefined1 *)(lVar10 + 8) = 0x2d;
            *pcVar12 = cVar3 + -0x20;
            if (iVar7 + -5 < 1) {
              iVar9 = 8;
            }
            else {
              uVar2 = *(undefined1 *)(lVar8 + 5);
              *(undefined1 *)(lVar10 + 9) = 0x23;
              *puVar15 = uVar2;
              if (iVar7 + -6 < 1) {
                iVar9 = 9;
              }
              else {
                *(undefined1 *)(lVar10 + 10) = 0x4e;
                if (iVar7 + -7 < 1) {
                  iVar9 = 10;
                }
                else {
                  *(undefined1 *)(lVar10 + 0xb) = 0x31;
                  if (iVar7 + -8 < 1) {
                    iVar9 = 0xb;
                  }
                  else {
                    *(undefined1 *)(lVar10 + 0xc) = 0x4e;
                    if (iVar7 + -9 < 1) {
                      iVar9 = 0xc;
                    }
                    else {
                      iVar9 = 0x10;
                      *(undefined1 *)(lVar10 + 0x10) = 0x7e;
                      *(undefined1 *)(lVar10 + 0xd) = 0x22;
                      *(undefined1 *)(lVar10 + 0xe) = 0x20;
                      *(undefined1 *)(lVar10 + 0xf) = 0x7e;
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  uVar1 = *puVar14;
  pcVar13 = (code *)(long)DAT_ffffffffbfc43a34;
  iVar6 = DAT_ffffffffbfc436f4 + 0x4bb0;
  lVar8 = (long)iVar6;
  *(undefined1 *)((long)DAT_ffffffffbfc436f4 + 0x4bb0) = 1;
  *(char *)(lVar8 + 2) = (char)uVar1 + ' ';
  iVar7 = DAT_ffffffffbfc436f4;
  pcVar12 = (char *)(long)(iVar9 + 1 + iVar6);
  *(char *)(lVar8 + 1) = (char)iVar9 + ' ';
  *(undefined1 *)(lVar8 + 3) = 0x59;
  *pcVar12 = '\0';
  cVar3 = (*pcVar13)(iVar7 + 0x4bb1);
  puVar11 = (undefined1 *)(long)(iVar9 + 2 + iVar6);
  uVar2 = *(undefined1 *)(long)DAT_ffffffffbfc43928;
  *pcVar12 = cVar3 + ' ';
  *puVar11 = uVar2;
  puVar11[1] = 0;
  (*(code *)(long)DAT_ffffffffbfc43fb4)(lVar8);
  return;
}

