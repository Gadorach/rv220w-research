/*
 * Ghidra reconstructed C; not original Cisco source.
 * RV220W boot-chain/U-Boot analysis v1.1.0
 * Entry: ffffffffbfc1ad3c
 * Function: FUN_ffffffffbfc1ad3c
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

void FUN_ffffffffbfc1ad3c(undefined8 param_1,long param_2)

{
  int iVar1;
  uint uVar2;
  undefined8 unaff_s0;
  undefined8 unaff_s1;
  int iVar3;
  undefined8 unaff_s2;
  undefined8 unaff_s3;
  int iVar4;
  undefined8 unaff_s4;
  code *pcVar5;
  char *pcVar6;
  undefined8 in_ra;
  
  pcVar6 = (char *)(long)((int)&stack0x00000000 + -0x50);
  *(undefined1 **)(pcVar6 + 0x38) = &_gp;
  *(undefined8 *)(pcVar6 + 0x20) = unaff_s2;
  iVar4 = DAT_ffffffffbfc436f4;
  pcVar5 = (code *)(long)DAT_ffffffffbfc4400c;
  *(undefined8 *)(pcVar6 + 0x30) = unaff_s4;
  *(undefined8 *)(pcVar6 + 0x40) = in_ra;
  *(undefined8 *)(pcVar6 + 0x28) = unaff_s3;
  *(undefined8 *)(pcVar6 + 0x18) = unaff_s1;
  *(undefined8 *)(pcVar6 + 0x10) = unaff_s0;
  (*pcVar5)(iVar4 + -0x1150,param_1);
  iVar4 = 0;
  if (param_2 != 0) {
    (*(code *)(long)DAT_ffffffffbfc4400c)(DAT_ffffffffbfc436f4 + -0x1130);
    (*(code *)(long)DAT_ffffffffbfc4400c)(DAT_ffffffffbfc436f4 + -0x10f0);
    iVar4 = 0;
  }
  do {
    *pcVar6 = 0;
    iVar3 = 0;
    pcVar6[2] = '\0';
    pcVar6[3] = '\0';
    uVar2 = 0;
    do {
      uVar2 = iVar4 << 0xb | (int)param_1 << 0x10 | uVar2;
      if ((iVar3 != 0) && (-1 < *pcVar6)) break;
      (*(code *)(long)DAT_ffffffffbfc43b3c)(uVar2,0,(int)&stack0x00000000 + -0x4e);
      if ((ushort)(*(short *)(pcVar6 + 2) - 1U) < 0xfffe) {
        if (iVar3 == 0) {
          (*(code *)(long)DAT_ffffffffbfc437d4)(uVar2,0xe,pcVar6);
        }
        if (param_2 == 0) {
          (*(code *)(long)DAT_ffffffffbfc4400c)(DAT_ffffffffbfc436f4 + -0x1098,param_1,iVar4,iVar3);
          iVar1 = DAT_ffffffffbfc43db8;
        }
        else {
          (*(code *)(long)DAT_ffffffffbfc4400c)(DAT_ffffffffbfc436f4 + -0x10b0,param_1,iVar4);
          iVar1 = DAT_ffffffffbfc43770;
        }
        (*(code *)(long)iVar1)(uVar2);
      }
      iVar3 = iVar3 + 1;
      uVar2 = iVar3 * 0x100;
    } while (iVar3 != 8);
    iVar4 = iVar4 + 1;
    if (iVar4 == 0x20) {
      return;
    }
  } while( true );
}

