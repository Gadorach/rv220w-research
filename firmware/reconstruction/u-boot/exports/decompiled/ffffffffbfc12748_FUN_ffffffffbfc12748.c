/*
 * Ghidra reconstructed C; not original Cisco source.
 * RV220W boot-chain/U-Boot analysis v1.1.0
 * Entry: ffffffffbfc12748
 * Function: FUN_ffffffffbfc12748
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

uint FUN_ffffffffbfc12748(char *param_1,undefined8 param_2)

{
  char cVar1;
  undefined4 uVar2;
  uint uVar3;
  ulong uVar4;
  char *pcVar5;
  int iVar8;
  char cVar9;
  long lVar6;
  long lVar7;
  int iVar10;
  char *pcVar11;
  undefined4 *puVar12;
  char cVar13;
  bool bVar14;
  undefined8 unaff_s0;
  char *pcVar15;
  int iVar16;
  undefined8 unaff_s1;
  uint uVar17;
  undefined8 unaff_s2;
  undefined8 unaff_s3;
  uint uVar18;
  undefined8 unaff_s4;
  undefined8 unaff_s5;
  code *pcVar19;
  char *pcVar20;
  undefined8 in_ra;
  int iVar21;
  
  iVar21 = (int)&stack0x00000000;
  pcVar20 = (char *)(long)(iVar21 + -0x450);
  *(undefined1 **)(pcVar20 + 0x440) = &_gp;
  *(undefined8 *)(pcVar20 + 0x438) = unaff_s5;
  pcVar19 = (code *)(long)DAT_ffffffffbfc4386c;
  *(undefined8 *)(pcVar20 + 0x410) = unaff_s0;
  *(undefined8 *)(pcVar20 + 0x448) = in_ra;
  *(undefined8 *)(pcVar20 + 0x430) = unaff_s4;
  *(undefined8 *)(pcVar20 + 0x428) = unaff_s3;
  *(undefined8 *)(pcVar20 + 0x420) = unaff_s2;
  *(undefined8 *)(pcVar20 + 0x418) = unaff_s1;
  (*pcVar19)();
  if ((param_1 != (char *)0x0) && (*param_1 != '\0')) {
    uVar4 = (*(code *)(long)DAT_ffffffffbfc437c8)(param_1);
    pcVar5 = pcVar20;
    if (uVar4 < 0x100) {
      do {
        cVar13 = *param_1;
        param_1 = (char *)(long)((int)param_1 + 1);
        *pcVar5 = cVar13;
        pcVar5 = (char *)(long)((int)pcVar5 + 1);
      } while (cVar13 != '\0');
      iVar10 = 2;
      iVar8 = DAT_ffffffffbfc436f4 + -0x5370;
      pcVar5 = pcVar20;
      while( true ) {
        cVar13 = *pcVar5;
        cVar1 = *(char *)(long)iVar8;
        cVar9 = cVar1;
        if (iVar10 == 0) break;
        iVar10 = iVar10 + -1;
        pcVar5 = (char *)(long)((int)pcVar5 + 1);
        cVar9 = cVar13;
        if ((cVar1 != cVar13) || (iVar8 = iVar8 + 1, cVar9 = cVar1, cVar13 == '\0')) break;
      }
      iVar8 = 0x1e;
      if (cVar9 != cVar1) {
        do {
          iVar16 = 0x100;
          pcVar15 = (char *)(long)(iVar21 + -0x250);
          iVar10 = 0x100;
          pcVar5 = pcVar20;
          pcVar11 = pcVar15;
          do {
            cVar13 = *pcVar5;
            iVar10 = iVar10 + -1;
            *pcVar11 = cVar13;
            pcVar11 = (char *)(long)((int)pcVar11 + 1);
            if (cVar13 == '\0') break;
            pcVar5 = (char *)(long)((int)pcVar5 + 1);
          } while (iVar10 != 0);
          (*(code *)(long)(DAT_ffffffffbfc436fc + 0x24f0))(pcVar15,pcVar20);
          pcVar5 = pcVar20;
          while( true ) {
            cVar13 = *pcVar15;
            cVar1 = *pcVar5;
            cVar9 = cVar1;
            if (iVar16 == 0) break;
            iVar16 = iVar16 + -1;
            pcVar15 = (char *)(long)((int)pcVar15 + 1);
            cVar9 = cVar13;
            if ((cVar1 != cVar13) ||
               (pcVar5 = (char *)(long)((int)pcVar5 + 1), cVar9 = cVar1, cVar13 == '\0')) break;
          }
          iVar8 = iVar8 + -1;
        } while ((cVar9 != cVar1) && (iVar8 != 0));
      }
      uVar18 = 1;
      uVar17 = 0;
      pcVar5 = pcVar20;
LAB_ffffffffbfc12a74:
      cVar13 = *pcVar5;
      if (cVar13 == '\0') {
        if (uVar17 == 0) {
          return uVar18;
        }
        return uVar17;
      }
      bVar14 = false;
      pcVar11 = pcVar5;
      do {
        if ((cVar13 == '\'') && (pcVar11[-1] != '\\')) {
          bVar14 = !bVar14;
        }
        if ((((!bVar14) && (cVar13 == ';')) && (pcVar11 != pcVar5)) && (pcVar11[-1] != '\\')) {
          *pcVar11 = '\0';
          pcVar11 = (char *)(long)((int)pcVar11 + 1);
          break;
        }
        pcVar11 = (char *)(long)((int)pcVar11 + 1);
        cVar13 = *pcVar11;
      } while (cVar13 != '\0');
      pcVar15 = (char *)(long)(iVar21 + -0x350);
      iVar8 = 0;
      (*(code *)(long)(DAT_ffffffffbfc436fc + 0x24f0))(pcVar5,pcVar15);
      puVar12 = (undefined4 *)(long)(iVar21 + -0x150);
      do {
        cVar13 = *pcVar15;
        if ((cVar13 != ' ') && (cVar13 != '\t')) {
          iVar10 = iVar8 * 4;
          if (cVar13 == '\0') {
            *(undefined4 *)(long)(iVar10 + iVar21 + -0x150) = 0;
            goto LAB_ffffffffbfc129e0;
          }
          iVar8 = iVar8 + 1;
          iVar16 = (int)pcVar15;
          *(int *)(long)(iVar10 + iVar21 + -0x150) = iVar16;
          puVar12 = (undefined4 *)(long)((int)puVar12 + 4);
          do {
            iVar16 = iVar16 + 1;
            pcVar15 = (char *)(long)iVar16;
            cVar13 = *pcVar15;
            if (cVar13 == '\0') {
              *puVar12 = 0;
              goto LAB_ffffffffbfc129e0;
            }
          } while ((cVar13 != ' ') && (cVar13 != '\t'));
          *pcVar15 = '\0';
          if (0x3f < iVar8) goto code_r0xffffffffbfc129cc;
        }
        pcVar15 = (char *)(long)((int)pcVar15 + 1);
      } while( true );
    }
    (*(code *)(long)DAT_ffffffffbfc43e38)(DAT_ffffffffbfc436f4 + -0x5388);
  }
  return 0xffffffff;
code_r0xffffffffbfc129cc:
  (*(code *)(long)DAT_ffffffffbfc4400c)(DAT_ffffffffbfc436f4 + -0x5368,0x40);
LAB_ffffffffbfc129e0:
  lVar6 = (*(code *)(long)DAT_ffffffffbfc43be8)(*(undefined4 *)(pcVar20 + 0x300));
  pcVar5 = pcVar11;
  if (lVar6 == 0) {
    uVar2 = *(undefined4 *)(pcVar20 + 0x300);
    iVar8 = DAT_ffffffffbfc436f4 + -0x5348;
  }
  else {
    if (iVar8 <= *(int *)(lVar6 + 4)) {
      lVar7 = (*(code *)(long)*(int *)(lVar6 + 0xc))(lVar6,param_2,iVar8,iVar21 + -0x150);
      if (lVar7 != 0) {
        uVar17 = 0xffffffff;
      }
      uVar3 = *(uint *)(lVar6 + 8);
      lVar6 = (*(code *)(long)DAT_ffffffffbfc43940)();
      uVar18 = uVar18 & uVar3;
      if (lVar6 != 0) {
        return 0;
      }
      goto LAB_ffffffffbfc12a74;
    }
    uVar2 = *(undefined4 *)(lVar6 + 0x10);
    iVar8 = DAT_ffffffffbfc436f4 + -0x5320;
  }
  uVar17 = 0xffffffff;
  (*(code *)(long)DAT_ffffffffbfc4400c)(iVar8,uVar2);
  goto LAB_ffffffffbfc12a74;
}

