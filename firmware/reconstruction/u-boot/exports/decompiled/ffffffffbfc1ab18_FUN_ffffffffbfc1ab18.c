/*
 * Ghidra reconstructed C; not original Cisco source.
 * RV220W boot-chain/U-Boot analysis v1.1.0
 * Entry: ffffffffbfc1ab18
 * Function: FUN_ffffffffbfc1ab18
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

void FUN_ffffffffbfc1ab18(undefined8 param_1)

{
  byte bVar1;
  int iVar2;
  undefined8 unaff_s0;
  code *pcVar3;
  byte *pbVar4;
  undefined8 in_ra;
  
  iVar2 = (int)&stack0x00000000;
  pbVar4 = (byte *)(long)(iVar2 + -0x30);
  *(undefined1 **)(pbVar4 + 0x18) = &_gp;
  *(undefined8 *)(pbVar4 + 0x20) = in_ra;
  pcVar3 = (code *)(long)DAT_ffffffffbfc43b3c;
  *(undefined8 *)(pbVar4 + 0x10) = unaff_s0;
  (*pcVar3)(param_1,0,iVar2 + -0x2e);
  (*(code *)(long)DAT_ffffffffbfc43b3c)(param_1,2,iVar2 + -0x2c);
  (*(code *)(long)DAT_ffffffffbfc437d4)(param_1,0xb,pbVar4);
  (*(code *)(long)DAT_ffffffffbfc437d4)(param_1,10,iVar2 + -0x2f);
  bVar1 = *pbVar4;
  if (bVar1 == 8) {
    iVar2 = DAT_ffffffffbfc436f4 + -0x1ad8;
    goto LAB_ffffffffbfc1ad14;
  }
  if (bVar1 < 9) {
    if (bVar1 == 3) {
      iVar2 = DAT_ffffffffbfc436f4 + -0x1b48;
      goto LAB_ffffffffbfc1ad14;
    }
    if (bVar1 < 4) {
      if (bVar1 == 1) {
        iVar2 = DAT_ffffffffbfc436f4 + -0x1b78;
      }
      else if (bVar1 < 2) {
        iVar2 = DAT_ffffffffbfc436f4 + -0x1b90;
      }
      else {
        iVar2 = DAT_ffffffffbfc436f4 + -0x1b60;
      }
      goto LAB_ffffffffbfc1ad14;
    }
    if (bVar1 == 5) {
      iVar2 = DAT_ffffffffbfc436f4 + -0x1b18;
      goto LAB_ffffffffbfc1ad14;
    }
    if (bVar1 < 5) {
      iVar2 = DAT_ffffffffbfc436f4 + -0x1b30;
      goto LAB_ffffffffbfc1ad14;
    }
    if (bVar1 == 6) {
      iVar2 = DAT_ffffffffbfc436f4 + -0x1b00;
      goto LAB_ffffffffbfc1ad14;
    }
    if (bVar1 == 7) {
      iVar2 = DAT_ffffffffbfc436f4 + -0x1af0;
      goto LAB_ffffffffbfc1ad14;
    }
  }
  else {
    if (bVar1 == 0xe) {
      iVar2 = DAT_ffffffffbfc436f4 + -0x1a78;
      goto LAB_ffffffffbfc1ad14;
    }
    if (bVar1 < 0xf) {
      if (bVar1 == 10) {
        iVar2 = DAT_ffffffffbfc436f4 + -0x1ab0;
        goto LAB_ffffffffbfc1ad14;
      }
      if (bVar1 < 10) {
        iVar2 = DAT_ffffffffbfc436f4 + -0x1ac0;
        goto LAB_ffffffffbfc1ad14;
      }
      if (bVar1 == 0xb) {
        iVar2 = DAT_ffffffffbfc436f4 + -0x1aa0;
        goto LAB_ffffffffbfc1ad14;
      }
      if (bVar1 == 0xc) {
        iVar2 = DAT_ffffffffbfc436f4 + -0x1a90;
        goto LAB_ffffffffbfc1ad14;
      }
    }
    else {
      if (bVar1 == 0x10) {
        iVar2 = DAT_ffffffffbfc436f4 + -0x1a48;
        goto LAB_ffffffffbfc1ad14;
      }
      if (bVar1 < 0x10) {
        iVar2 = DAT_ffffffffbfc436f4 + -0x1a60;
        goto LAB_ffffffffbfc1ad14;
      }
      if (bVar1 == 0x11) {
        iVar2 = DAT_ffffffffbfc436f4 + -0x1a30;
        goto LAB_ffffffffbfc1ad14;
      }
      if (bVar1 == 0xff) {
        iVar2 = DAT_ffffffffbfc436f4 + -0x1ba8;
        goto LAB_ffffffffbfc1ad14;
      }
    }
  }
  iVar2 = DAT_ffffffffbfc436f4 + -0x2d00;
LAB_ffffffffbfc1ad14:
  (*(code *)(long)DAT_ffffffffbfc4400c)
            (DAT_ffffffffbfc436f4 + -0x1178,*(undefined2 *)(pbVar4 + 2),*(undefined2 *)(pbVar4 + 4),
             iVar2,pbVar4[1]);
  return;
}

