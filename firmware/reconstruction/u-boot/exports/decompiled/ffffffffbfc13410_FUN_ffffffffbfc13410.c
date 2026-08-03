/*
 * Ghidra reconstructed C; not original Cisco source.
 * RV220W boot-chain/U-Boot analysis v1.1.0
 * Entry: ffffffffbfc13410
 * Function: FUN_ffffffffbfc13410
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

undefined8 FUN_ffffffffbfc13410(undefined8 param_1)

{
  char *pcVar1;
  int iVar3;
  int iVar4;
  long lVar2;
  int *piVar5;
  char *pcVar6;
  undefined8 unaff_s0;
  undefined8 uVar7;
  int *piVar8;
  char *pcVar9;
  undefined8 unaff_s1;
  undefined8 unaff_s2;
  undefined8 unaff_s3;
  code *pcVar10;
  undefined8 *puVar11;
  undefined8 in_ra;
  
  puVar11 = (undefined8 *)(long)((int)&stack0x00000000 + -0x30);
  puVar11[4] = &_gp;
  puVar11[2] = unaff_s2;
  iVar4 = DAT_ffffffffbfc436f4;
  pcVar10 = (code *)(long)DAT_ffffffffbfc43f0c;
  puVar11[5] = in_ra;
  puVar11[3] = unaff_s3;
  puVar11[1] = unaff_s1;
  *puVar11 = unaff_s0;
  pcVar1 = (char *)(*pcVar10)(iVar4 + -0x5220);
  if (pcVar1 != (char *)0x0) {
    special2((long)*pcVar1,1,0xe,0x2f);
  }
  piVar5 = (int *)(long)DAT_ffffffffbfc43924;
  (*(code *)(long)DAT_ffffffffbfc43f84)(piVar5,param_1,0x40);
  if (*piVar5 == 0x27051956) {
    pcVar10 = (code *)(long)DAT_ffffffffbfc43ba4;
    iVar4 = piVar5[1];
    piVar5[1] = 0;
    iVar3 = (*pcVar10)(0,piVar5,0x40);
    if (iVar3 == iVar4) {
      piVar8 = (int *)(long)((int)param_1 + 0x40);
      iVar4 = (*(code *)(long)DAT_ffffffffbfc43ba4)(0,piVar8,piVar5[3]);
      if (iVar4 == piVar5[6]) {
        if (*(char *)((long)DAT_ffffffffbfc43924 + 0x1e) == '\x06') {
          iVar4 = *piVar8;
          if (iVar4 == 0) {
            uVar7 = 1;
            pcVar10 = (code *)(long)DAT_ffffffffbfc43e38;
            pcVar1 = (char *)(long)(DAT_ffffffffbfc436f4 + -0x51d0);
          }
          else {
            pcVar1 = (char *)(*(code *)(long)DAT_ffffffffbfc43e1c)(iVar4 + 1);
            if (pcVar1 == (char *)0x0) {
              return 1;
            }
            do {
              iVar3 = *piVar8;
              piVar8 = (int *)(long)((int)piVar8 + 4);
            } while (iVar3 != 0);
            (*(code *)(long)DAT_ffffffffbfc43f84)(pcVar1,piVar8,iVar4);
            *(undefined1 *)(long)((int)pcVar1 + iVar4) = 0;
            pcVar6 = pcVar1;
            pcVar9 = pcVar1;
            while( true ) {
              iVar4 = (int)pcVar9;
              if (*pcVar9 == '\0') break;
              pcVar10 = (code *)(long)DAT_ffffffffbfc43fcc;
              if (*pcVar9 == '\n') {
                *pcVar9 = '\0';
                if ((1 < iVar4 - (int)pcVar6) && (lVar2 = (*pcVar10)(pcVar6,0), lVar2 < 0)) {
                  uVar7 = 1;
                  goto LAB_ffffffffbfc135e0;
                }
                pcVar6 = (char *)(long)(iVar4 + 1);
              }
              pcVar9 = (char *)(long)(iVar4 + 1);
            }
            uVar7 = 0;
LAB_ffffffffbfc135e0:
            pcVar10 = (code *)(long)DAT_ffffffffbfc43734;
          }
        }
        else {
          uVar7 = 1;
          pcVar10 = (code *)(long)DAT_ffffffffbfc43e38;
          pcVar1 = (char *)(long)(DAT_ffffffffbfc436f4 + -0x51e0);
        }
      }
      else {
        uVar7 = 1;
        pcVar10 = (code *)(long)DAT_ffffffffbfc43e38;
        pcVar1 = (char *)(long)(DAT_ffffffffbfc436f4 + -0x51f0);
      }
    }
    else {
      uVar7 = 1;
      pcVar10 = (code *)(long)DAT_ffffffffbfc43e38;
      pcVar1 = (char *)(long)(DAT_ffffffffbfc436f4 + -0x5200);
    }
  }
  else {
    uVar7 = 1;
    pcVar10 = (code *)(long)DAT_ffffffffbfc43e38;
    pcVar1 = (char *)(long)(DAT_ffffffffbfc436f4 + -0x5218);
  }
  (*pcVar10)(pcVar1);
  return uVar7;
}

