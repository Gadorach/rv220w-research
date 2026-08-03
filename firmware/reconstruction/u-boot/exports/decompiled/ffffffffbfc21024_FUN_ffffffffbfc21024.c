/*
 * Ghidra reconstructed C; not original Cisco source.
 * RV220W boot-chain/U-Boot analysis v1.1.0
 * Entry: ffffffffbfc21024
 * Function: FUN_ffffffffbfc21024
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

int FUN_ffffffffbfc21024
              (undefined8 param_1,undefined4 param_2,undefined4 *param_3,int param_4,int param_5)

{
  int iVar3;
  undefined8 uVar1;
  long lVar2;
  int iVar4;
  undefined8 unaff_s0;
  int iVar5;
  undefined8 unaff_s1;
  undefined8 unaff_s2;
  int iVar6;
  undefined8 unaff_s3;
  int iVar7;
  undefined8 unaff_s4;
  undefined8 unaff_s5;
  undefined8 unaff_s6;
  int iVar8;
  undefined8 unaff_s7;
  code *pcVar9;
  int *piVar10;
  undefined8 unaff_s8;
  undefined8 in_ra;
  
  *param_3 = 0;
  piVar10 = (int *)(long)((int)&stack0x00000000 + -0x70);
  *(undefined1 **)(piVar10 + 0x14) = &_gp;
  *(undefined8 *)(piVar10 + 0x16) = unaff_s8;
  pcVar9 = (code *)(long)DAT_ffffffffbfc437c8;
  *(undefined8 *)(piVar10 + 0x12) = unaff_s7;
  *(undefined8 *)(piVar10 + 0x10) = unaff_s6;
  *(undefined8 *)(piVar10 + 0xe) = unaff_s5;
  *(undefined8 *)(piVar10 + 0xc) = unaff_s4;
  *(undefined8 *)(piVar10 + 8) = unaff_s2;
  iVar6 = 0;
  *(undefined8 *)(piVar10 + 4) = unaff_s0;
  iVar5 = 0;
  *(undefined8 *)(piVar10 + 0x18) = in_ra;
  *(undefined8 *)(piVar10 + 10) = unaff_s3;
  *(undefined8 *)(piVar10 + 6) = unaff_s1;
  *piVar10 = param_2;
  iVar3 = (*pcVar9)();
  do {
    lVar2 = (*(code *)(long)*(int *)(long)DAT_ffffffffbfc43dbc)(iVar5);
    iVar8 = (int)param_3;
    iVar4 = iVar5;
    if (lVar2 == 0) {
LAB_ffffffffbfc21198:
      *(undefined4 *)(long)(iVar6 * 4 + iVar8) = 0;
      return iVar6;
    }
    do {
      iVar7 = iVar4;
      lVar2 = (*(code *)(long)*(int *)(long)DAT_ffffffffbfc43dbc)(iVar7);
      iVar4 = iVar7 + 1;
    } while (lVar2 != 0);
    uVar1 = (*(code *)(long)DAT_ffffffffbfc43c08)(iVar5);
    lVar2 = (*(code *)(long)DAT_ffffffffbfc43798)(uVar1,0x3d);
    iVar5 = (int)lVar2 - (int)uVar1;
    if (lVar2 == 0) {
      iVar5 = (*(code *)(long)DAT_ffffffffbfc437c8)(uVar1);
    }
    if ((iVar3 < 1) ||
       ((iVar3 <= iVar5 &&
        (lVar2 = (*(code *)(long)DAT_ffffffffbfc43ab4)(uVar1,param_1,iVar3), lVar2 == 0)))) {
      if ((*piVar10 + -2 <= iVar6) || (param_4 < iVar5 + 1)) {
        iVar3 = iVar6 * 4;
        iVar6 = iVar6 + 1;
        *(int *)(long)(iVar3 + iVar8) = DAT_ffffffffbfc436f4 + 0xb60;
        goto LAB_ffffffffbfc21198;
      }
      pcVar9 = (code *)(long)DAT_ffffffffbfc43e84;
      *(int *)(long)(iVar6 * 4 + iVar8) = param_5;
      iVar6 = iVar6 + 1;
      (*pcVar9)(param_5,uVar1,iVar5);
      iVar4 = param_5 + iVar5;
      param_5 = iVar4 + 1;
      *(undefined1 *)(long)iVar4 = 0;
      param_4 = (param_4 - iVar5) + -1;
    }
    iVar5 = iVar7 + 1;
  } while( true );
}

