/*
 * Ghidra reconstructed C; not original Cisco source.
 * RV220W boot-chain/U-Boot analysis v1.1.0
 * Entry: ffffffffbfc1af2c
 * Function: FUN_ffffffffbfc1af2c
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

undefined8
FUN_ffffffffbfc1af2c(undefined8 param_1,int param_2,long param_3,undefined8 param_4,long param_5)

{
  long lVar1;
  undefined8 uVar2;
  int iVar3;
  uint uVar4;
  undefined8 unaff_s0;
  undefined8 unaff_s1;
  undefined8 unaff_s2;
  undefined8 unaff_s3;
  code *pcVar5;
  byte *pbVar6;
  undefined8 in_ra;
  int iVar7;
  
  iVar7 = (int)&stack0x00000000;
  pbVar6 = (byte *)(long)(iVar7 + -0x40);
  *(undefined1 **)(pbVar6 + 0x30) = &_gp;
  *(undefined8 *)(pbVar6 + 0x28) = unaff_s3;
  *(undefined8 *)(pbVar6 + 0x20) = unaff_s2;
  *(undefined8 *)(pbVar6 + 0x18) = unaff_s1;
  *(undefined8 *)(pbVar6 + 0x10) = unaff_s0;
  *(undefined8 *)(pbVar6 + 0x38) = in_ra;
  while( true ) {
    while( true ) {
      (*(code *)(long)DAT_ffffffffbfc4400c)(DAT_ffffffffbfc436f4 + -0x3ca0,param_2);
      if (param_3 == 4) {
        (*(code *)(long)DAT_ffffffffbfc43d88)(param_1,param_2,iVar7 + -0x3c);
        pcVar5 = (code *)(long)DAT_ffffffffbfc4400c;
        uVar4 = *(uint *)(pbVar6 + 4);
        iVar3 = DAT_ffffffffbfc436f4 + -0x3c98;
      }
      else if (param_3 == 2) {
        (*(code *)(long)DAT_ffffffffbfc43b3c)(param_1,param_2,iVar7 + -0x3e);
        pcVar5 = (code *)(long)DAT_ffffffffbfc4400c;
        uVar4 = (uint)*(ushort *)(pbVar6 + 2);
        iVar3 = DAT_ffffffffbfc436f4 + -0x3c90;
      }
      else {
        (*(code *)(long)DAT_ffffffffbfc437d4)(param_1,param_2,pbVar6);
        pcVar5 = (code *)(long)DAT_ffffffffbfc4400c;
        uVar4 = (uint)*pbVar6;
        iVar3 = DAT_ffffffffbfc436f4 + -0x3c88;
      }
      (*pcVar5)(iVar3,uVar4);
      lVar1 = (*(code *)(long)DAT_ffffffffbfc43e4c)(DAT_ffffffffbfc436f4 + -0x3c80);
      iVar3 = (int)param_3;
      if ((lVar1 != 0) && ((lVar1 != 1 || (*(char *)(long)DAT_ffffffffbfc44084 != '-')))) break;
      if (param_5 != 0) {
        if (lVar1 != 0) {
          iVar3 = -iVar3;
        }
        param_2 = param_2 + iVar3;
      }
    }
    uVar2 = (*(code *)(long)DAT_ffffffffbfc438b0)(DAT_ffffffffbfc44084,iVar7 + -0x38,0x10);
    if (*(int *)(pbVar6 + 8) == DAT_ffffffffbfc44084) break;
    (*(code *)(long)(DAT_ffffffffbfc43700 + -0x5144))(param_1,param_2,param_3,uVar2);
    if (param_5 != 0) {
      param_2 = param_2 + iVar3;
    }
  }
  return 0;
}

