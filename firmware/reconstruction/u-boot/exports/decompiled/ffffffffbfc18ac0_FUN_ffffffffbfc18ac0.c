/*
 * Ghidra reconstructed C; not original Cisco source.
 * RV220W boot-chain/U-Boot analysis v1.1.0
 * Entry: ffffffffbfc18ac0
 * Function: FUN_ffffffffbfc18ac0
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

undefined8 FUN_ffffffffbfc18ac0(undefined8 param_1,long param_2,long param_3,long param_4)

{
  int *piVar1;
  int iVar4;
  long lVar2;
  undefined8 uVar3;
  char *pcVar5;
  undefined8 unaff_s0;
  undefined8 unaff_s1;
  code *pcVar6;
  long lVar7;
  undefined8 in_ra;
  
  lVar7 = (long)((int)&stack0x00000000 + -0x40);
  *(undefined1 **)(lVar7 + 0x30) = &_gp;
  *(undefined8 *)(lVar7 + 0x28) = unaff_s1;
  *(undefined8 *)(lVar7 + 0x20) = unaff_s0;
  *(undefined8 *)(lVar7 + 0x38) = in_ra;
  if (param_3 == 2) {
    pcVar5 = (char *)(long)*(int *)(param_4 + 4);
    if (*pcVar5 != '\"') {
      iVar4 = (*(code *)(long)DAT_ffffffffbfc438b0)(pcVar5,0,0x10);
      goto LAB_ffffffffbfc18b9c;
    }
    (*(code *)(long)DAT_ffffffffbfc43fe4)(DAT_ffffffffbfc43d3c,pcVar5,0x80);
    piVar1 = (int *)(long)DAT_ffffffffbfc43d48;
  }
  else if (param_3 == 3) {
    iVar4 = (*(code *)(long)DAT_ffffffffbfc438b0)(*(undefined4 *)(param_4 + 4),0,0x10);
    (*(code *)(long)DAT_ffffffffbfc43fe4)(DAT_ffffffffbfc43d3c,*(undefined4 *)(param_4 + 8),0x80);
LAB_ffffffffbfc18b9c:
    if (iVar4 != 0) goto LAB_ffffffffbfc18bb0;
    piVar1 = (int *)(long)DAT_ffffffffbfc43d48;
  }
  else {
    if (param_3 != 1) {
      (*(code *)(long)DAT_ffffffffbfc4400c)
                (DAT_ffffffffbfc436f4 + -0x5320,*(undefined4 *)(param_2 + 0x10));
      return 1;
    }
    piVar1 = (int *)(long)DAT_ffffffffbfc43d48;
  }
  iVar4 = *piVar1;
LAB_ffffffffbfc18bb0:
  pcVar6 = (code *)(long)DAT_ffffffffbfc43bf4;
  *(int *)(long)DAT_ffffffffbfc43c14 = iVar4;
  lVar2 = (*pcVar6)(param_1);
  if (lVar2 < 0) {
    uVar3 = 1;
  }
  else {
    if (*(int *)(long)DAT_ffffffffbfc43a90 != 0) {
      (*(code *)(long)DAT_ffffffffbfc43f20)(*(int *)(long)DAT_ffffffffbfc43a90,lVar7);
      (*(code *)(long)DAT_ffffffffbfc43b14)(DAT_ffffffffbfc436f4 + -24000,lVar7);
    }
    if (*(int *)(long)DAT_ffffffffbfc43c58 != 0) {
      (*(code *)(long)DAT_ffffffffbfc43f20)(*(int *)(long)DAT_ffffffffbfc43c58,lVar7);
      (*(code *)(long)DAT_ffffffffbfc43b14)(DAT_ffffffffbfc436f4 + -0x5db0,lVar7);
    }
    if (*(char *)(long)DAT_ffffffffbfc43b38 != '\0') {
      (*(code *)(long)DAT_ffffffffbfc43b14)(DAT_ffffffffbfc436f4 + -0x2380);
    }
    if (*(char *)(long)DAT_ffffffffbfc43764 != '\0') {
      (*(code *)(long)DAT_ffffffffbfc43b14)(DAT_ffffffffbfc436f4 + -0x2370);
    }
    if (*(int *)(long)DAT_ffffffffbfc43f80 != 0) {
      (*(code *)(long)DAT_ffffffffbfc43f20)(*(int *)(long)DAT_ffffffffbfc43f80,lVar7);
      (*(code *)(long)DAT_ffffffffbfc43b14)(DAT_ffffffffbfc436f0 + 0x70c8,lVar7);
    }
    if (*(int *)(long)DAT_ffffffffbfc43f00 != 0) {
      (*(code *)(long)DAT_ffffffffbfc43f20)(*(int *)(long)DAT_ffffffffbfc43f00,lVar7);
      (*(code *)(long)DAT_ffffffffbfc43b14)(DAT_ffffffffbfc436f4 + -0x5d98,lVar7);
    }
    if (*(int *)(long)DAT_ffffffffbfc43868 != 0) {
      (*(code *)(long)DAT_ffffffffbfc43f20)(*(int *)(long)DAT_ffffffffbfc43868,lVar7);
      (*(code *)(long)DAT_ffffffffbfc43b14)(DAT_ffffffffbfc436f4 + -0x2360,lVar7);
    }
    if (*(char *)(long)DAT_ffffffffbfc43e18 != '\0') {
      (*(code *)(long)DAT_ffffffffbfc43b14)(DAT_ffffffffbfc436f4 + -0x2358);
    }
    uVar3 = 0;
    if (lVar2 != 0) {
      (*(code *)(long)DAT_ffffffffbfc43e48)(iVar4,lVar2);
      uVar3 = 0;
    }
  }
  return uVar3;
}

