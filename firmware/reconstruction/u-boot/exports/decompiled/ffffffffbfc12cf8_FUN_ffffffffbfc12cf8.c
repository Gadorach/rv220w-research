/*
 * Ghidra reconstructed C; not original Cisco source.
 * RV220W boot-chain/U-Boot analysis v1.1.0
 * Entry: ffffffffbfc12cf8
 * Function: FUN_ffffffffbfc12cf8
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

int FUN_ffffffffbfc12cf8(long param_1)

{
  int iVar1;
  int iVar2;
  int iVar4;
  long lVar3;
  char cVar6;
  int iVar5;
  undefined8 unaff_s0;
  undefined8 unaff_s1;
  char *pcVar7;
  undefined8 unaff_s2;
  undefined8 unaff_s3;
  code *pcVar8;
  int *piVar9;
  undefined8 in_ra;
  int iVar10;
  
  iVar10 = (int)&stack0x00000000;
  piVar9 = (int *)(long)(iVar10 + -0x40);
  *(undefined1 **)(piVar9 + 0xc) = &_gp;
  *(undefined8 *)(piVar9 + 8) = unaff_s2;
  *(undefined8 *)(piVar9 + 0xe) = in_ra;
  *(undefined8 *)(piVar9 + 10) = unaff_s3;
  *(undefined8 *)(piVar9 + 6) = unaff_s1;
  *(undefined8 *)(piVar9 + 4) = unaff_s0;
  *piVar9 = 0;
  if (param_1 == 0) {
    iVar4 = 0;
  }
  else {
    iVar4 = (*(code *)(long)DAT_ffffffffbfc437c8)();
    (*(code *)(long)DAT_ffffffffbfc43e38)(param_1);
  }
  pcVar7 = (char *)(long)DAT_ffffffffbfc44084;
  piVar9[1] = iVar4;
LAB_ffffffffbfc12d74:
  do {
    pcVar8 = (code *)(long)DAT_ffffffffbfc43c5c;
    while( true ) {
      lVar3 = (*pcVar8)();
      if (lVar3 == 0) break;
      cVar6 = (*(code *)(long)DAT_ffffffffbfc43e94)();
      iVar2 = DAT_ffffffffbfc44084;
      iVar1 = DAT_ffffffffbfc436f4;
      if (cVar6 == '\n') {
LAB_ffffffffbfc12e0c:
        pcVar8 = (code *)(long)DAT_ffffffffbfc43e38;
        *pcVar7 = '\0';
        (*pcVar8)(iVar1 + -0x52f0);
        return (int)pcVar7 - DAT_ffffffffbfc44084;
      }
      if (cVar6 < '\v') {
        if (cVar6 == '\x03') {
          *(undefined1 *)(long)DAT_ffffffffbfc44084 = 0;
          return -1;
        }
        if (cVar6 == '\b') {
LAB_ffffffffbfc12ecc:
          pcVar7 = (char *)(*(code *)(long)(DAT_ffffffffbfc436fc + 0x2ba0))
                                     (DAT_ffffffffbfc44084,pcVar7,iVar10 + -0x3c,piVar9,iVar4);
          goto LAB_ffffffffbfc12d74;
        }
        pcVar8 = (code *)(long)DAT_ffffffffbfc43c5c;
        if (cVar6 != '\0') {
          iVar5 = *piVar9;
LAB_ffffffffbfc12ef0:
          if (iVar5 < 0xfe) {
            if (cVar6 == '\t') {
              pcVar8 = (code *)(long)DAT_ffffffffbfc43cb4;
              *pcVar7 = '\0';
              lVar3 = (*pcVar8)(param_1,iVar2,piVar9,iVar10 + -0x3c);
              if (lVar3 != 0) {
                pcVar7 = (char *)(long)(*piVar9 + DAT_ffffffffbfc44084);
                goto LAB_ffffffffbfc12d74;
              }
              (*(code *)(long)DAT_ffffffffbfc43e38)
                        ((piVar9[1] & 7U) + DAT_ffffffffbfc436f4 + 0x28d0);
              piVar9[1] = (piVar9[1] & 0xfffffff8U) + 8;
            }
            else {
              pcVar8 = (code *)(long)DAT_ffffffffbfc439f0;
              piVar9[1] = piVar9[1] + 1;
              (*pcVar8)(cVar6);
            }
            *pcVar7 = cVar6;
            pcVar7 = (char *)(long)((int)pcVar7 + 1);
            *piVar9 = *piVar9 + 1;
            goto LAB_ffffffffbfc12d74;
          }
          (*(code *)(long)DAT_ffffffffbfc439f0)(7);
          pcVar8 = (code *)(long)DAT_ffffffffbfc43c5c;
        }
      }
      else {
        if (cVar6 == '\x15') goto LAB_ffffffffbfc12e4c;
        if (cVar6 < '\x16') {
          iVar5 = *piVar9;
          if (cVar6 == '\r') goto LAB_ffffffffbfc12e0c;
          goto LAB_ffffffffbfc12ef0;
        }
        if (cVar6 != '\x17') {
          iVar5 = *piVar9;
          if (cVar6 == '\x7f') goto LAB_ffffffffbfc12ecc;
          goto LAB_ffffffffbfc12ef0;
        }
        do {
          pcVar7 = (char *)(*(code *)(long)(DAT_ffffffffbfc436fc + 0x2ba0))
                                     (DAT_ffffffffbfc44084,pcVar7,iVar10 + -0x3c,piVar9,iVar4);
          if (*piVar9 < 1) goto LAB_ffffffffbfc12d74;
          pcVar8 = (code *)(long)DAT_ffffffffbfc43c5c;
        } while (*pcVar7 != ' ');
      }
    }
    if (*(int *)(long)*(int *)(long)DAT_ffffffffbfc43e88 == 1) {
      return -3;
    }
  } while( true );
LAB_ffffffffbfc12e4c:
  while( true ) {
    if (piVar9[1] <= iVar4) break;
    (*(code *)(long)DAT_ffffffffbfc43e38)(DAT_ffffffffbfc436f4 + 0x28c8);
    piVar9[1] = piVar9[1] + -1;
  }
  pcVar7 = (char *)(long)DAT_ffffffffbfc44084;
  *piVar9 = 0;
  goto LAB_ffffffffbfc12d74;
}

