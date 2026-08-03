/*
 * Ghidra reconstructed C; not original Cisco source.
 * RV220W boot-chain/U-Boot analysis v1.1.0
 * Entry: ffffffffbfc124f0
 * Function: FUN_ffffffffbfc124f0
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

void FUN_ffffffffbfc124f0(char *param_1,char *param_2)

{
  bool bVar1;
  int iVar3;
  char *pcVar2;
  ulong uVar4;
  int iVar5;
  int iVar6;
  char cVar7;
  char cVar8;
  undefined1 *puVar9;
  undefined8 unaff_s0;
  undefined8 unaff_s1;
  char cVar10;
  undefined8 unaff_s2;
  undefined8 unaff_s3;
  int iVar11;
  undefined8 unaff_s4;
  int iVar12;
  undefined8 unaff_s5;
  char *pcVar13;
  code *pcVar14;
  long lVar15;
  undefined8 in_ra;
  int iVar16;
  
  iVar16 = (int)&stack0x00000000 + -0x140;
  lVar15 = (long)iVar16;
  *(undefined1 **)(lVar15 + 0x130) = &_gp;
  *(undefined8 *)(lVar15 + 0x128) = unaff_s5;
  pcVar14 = (code *)(long)DAT_ffffffffbfc437c8;
  *(undefined8 *)(lVar15 + 0x120) = unaff_s4;
  *(undefined8 *)(lVar15 + 0x118) = unaff_s3;
  *(undefined8 *)(lVar15 + 0x110) = unaff_s2;
  *(undefined8 *)(lVar15 + 0x100) = unaff_s0;
  *(undefined8 *)(lVar15 + 0x138) = in_ra;
  *(undefined8 *)(lVar15 + 0x108) = unaff_s1;
  iVar3 = (*pcVar14)();
  uVar4 = 0;
  pcVar13 = (char *)0x0;
  iVar11 = 0x100;
  cVar8 = '\0';
LAB_ffffffffbfc126fc:
  do {
    if (iVar3 == 0) {
      if (iVar11 != 0) {
LAB_ffffffffbfc1271c:
        *param_2 = '\0';
      }
      return;
    }
    if (iVar11 == 0) {
      return;
    }
    cVar10 = *param_1;
    iVar6 = (int)param_1;
    param_1 = (char *)(long)(iVar6 + 1);
    iVar12 = iVar3 + -1;
    iVar5 = (int)param_2;
    cVar7 = cVar8;
    if (uVar4 == 3) {
LAB_ffffffffbfc126c4:
      if ((cVar10 == '\'') && (iVar6 = iVar11, cVar7 != '\\')) {
LAB_ffffffffbfc126e8:
        uVar4 = 0;
        iVar11 = iVar6;
        cVar8 = cVar10;
        iVar3 = iVar12;
      }
      else {
        *param_2 = cVar10;
        param_2 = (char *)(long)(iVar5 + 1);
        uVar4 = 3;
        iVar11 = iVar11 + -1;
        cVar8 = cVar10;
        iVar3 = iVar12;
      }
      goto LAB_ffffffffbfc126fc;
    }
    if ((cVar10 == '\\') && (cVar8 != '\\')) {
      iVar12 = iVar3 + -2;
      cVar7 = '\\';
      if (iVar12 == -1) goto LAB_ffffffffbfc1271c;
      cVar10 = *param_1;
      param_1 = (char *)(long)(iVar6 + 2);
    }
    cVar8 = cVar10;
    iVar3 = iVar12;
    if (uVar4 != 1) {
      if (uVar4 < 2) {
        if (uVar4 == 0) {
          if (cVar10 == '\'') {
            if (cVar7 != '\\') {
              uVar4 = 3;
              goto LAB_ffffffffbfc126fc;
            }
          }
          else if ((cVar10 == '$') && (cVar7 != '\\')) {
            uVar4 = 1;
            goto LAB_ffffffffbfc126fc;
          }
          *param_2 = cVar10;
          param_2 = (char *)(long)(iVar5 + 1);
          iVar11 = iVar11 + -1;
        }
      }
      else if (uVar4 == 2) {
        if ((cVar10 == ')') || (cVar10 == '}')) {
          iVar5 = 0;
          while( true ) {
            bVar1 = ((int)param_1 - (int)pcVar13) + -1 <= iVar5;
            iVar6 = (int)pcVar13 + iVar5;
            puVar9 = (undefined1 *)(long)(iVar16 + iVar5);
            iVar5 = iVar5 + 1;
            if (bVar1) break;
            *puVar9 = *(undefined1 *)(long)iVar6;
          }
          pcVar14 = (code *)(long)DAT_ffffffffbfc43f0c;
          *puVar9 = 0;
          pcVar2 = (char *)(*pcVar14)(lVar15);
          uVar4 = 0;
          if (pcVar2 != (char *)0x0) {
            while( true ) {
              cVar7 = *pcVar2;
              pcVar2 = (char *)(long)((int)pcVar2 + 1);
              iVar6 = iVar11;
              if (cVar7 == '\0') break;
              if (iVar11 == 0) {
                uVar4 = 0;
                goto LAB_ffffffffbfc126fc;
              }
              *param_2 = cVar7;
              iVar11 = iVar11 + -1;
              param_2 = (char *)(long)((int)param_2 + 1);
            }
            goto LAB_ffffffffbfc126e8;
          }
        }
      }
      else if (uVar4 == 3) goto LAB_ffffffffbfc126c4;
      goto LAB_ffffffffbfc126fc;
    }
    if ((cVar10 != '(') && (cVar10 != '{')) {
      *param_2 = '$';
      param_2 = (char *)(long)(iVar5 + 1);
      iVar6 = 0;
      if (iVar11 != 1) {
        *param_2 = cVar10;
        iVar6 = iVar11 + -2;
        param_2 = (char *)(long)(iVar5 + 2);
      }
      goto LAB_ffffffffbfc126e8;
    }
    uVar4 = 2;
    pcVar13 = param_1;
  } while( true );
}

