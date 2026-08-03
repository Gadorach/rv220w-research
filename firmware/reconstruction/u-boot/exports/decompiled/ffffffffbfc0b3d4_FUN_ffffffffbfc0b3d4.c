/*
 * Ghidra reconstructed C; not original Cisco source.
 * RV220W boot-chain/U-Boot analysis v1.1.0
 * Entry: ffffffffbfc0b3d4
 * Function: FUN_ffffffffbfc0b3d4
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

undefined8 FUN_ffffffffbfc0b3d4(ulong param_1,ulong param_2,long param_3)

{
  int iVar1;
  ulong uVar2;
  undefined8 unaff_s0;
  long lVar3;
  undefined8 unaff_s1;
  long lVar4;
  undefined8 unaff_s2;
  undefined8 unaff_s3;
  undefined8 unaff_s4;
  code *pcVar5;
  undefined8 *puVar6;
  undefined8 in_ra;
  
  puVar6 = (undefined8 *)(long)((int)&stack0x00000000 + -0x40);
  puVar6[5] = &_gp;
  puVar6[4] = unaff_s4;
  puVar6[2] = unaff_s2;
  *puVar6 = unaff_s0;
  puVar6[6] = in_ra;
  puVar6[3] = unaff_s3;
  puVar6[1] = unaff_s1;
  if (param_3 == 0) {
    iVar1 = DAT_ffffffffbfc436f4 + -0x60e0;
  }
  else {
    if (0x400000000 < param_1) {
      (*(code *)(long)DAT_ffffffffbfc4400c)(DAT_ffffffffbfc436f4 + -0x60a8);
      param_1 = 0x400000000;
    }
    lVar4 = (long)DAT_ffffffffbfc436f4;
    if (*(int *)(lVar4 + 0x4830) != 0) {
      return 1;
    }
    pcVar5 = (code *)(long)DAT_ffffffffbfc43a54;
    *(int *)(lVar4 + 0x4830) = (int)param_3;
    (*pcVar5)(param_3,0,0x38);
    lVar4 = (long)*(int *)(lVar4 + 0x4830);
    pcVar5 = (code *)(long)DAT_ffffffffbfc43ed0;
    param_2 = param_2 & 0xffffffff;
    *(undefined4 *)(lVar4 + 0x10) = 3;
    *(undefined8 *)(lVar4 + 8) = 0;
    *(undefined4 *)(lVar4 + 0x14) = 0;
    if (param_1 < 0x10000001) {
      uVar2 = param_1 - param_2;
    }
    else {
      uVar2 = param_1 - 0x10000000;
      (*pcVar5)(param_2,0x10000000 - param_2,0);
      pcVar5 = (code *)(long)DAT_ffffffffbfc43ed0;
      if (uVar2 < 0x10000001) {
        param_2 = 0x410000000;
      }
      else {
        (*pcVar5)(0x410000000,0x10000000,0);
        uVar2 = param_1 - 0x20000000;
        pcVar5 = (code *)(long)DAT_ffffffffbfc43ed0;
        param_2 = 0x20000000;
      }
    }
    lVar3 = (long)DAT_ffffffffbfc436f4;
    (*pcVar5)(param_2,uVar2,0);
    lVar4 = (long)*(int *)(lVar3 + 0x4830);
    pcVar5 = (code *)(long)DAT_ffffffffbfc43a08;
    *(undefined4 *)(lVar4 + 0x2c) = 0x80;
    *(undefined4 *)(lVar4 + 0x28) = 0x40;
    *(undefined8 *)(lVar4 + 0x30) = 0;
    lVar4 = (*pcVar5)(0x2400,0,0x10000000,0,1);
    if (-1 < lVar4) {
      *(long *)((long)*(int *)(lVar3 + 0x4830) + 0x30) = lVar4;
    }
    lVar4 = *(long *)((long)*(int *)(lVar3 + 0x4830) + 0x30);
    if (lVar4 != 0) {
      (*(code *)(long)DAT_ffffffffbfc43a54)((int)lVar4,0,0x2400);
      return 1;
    }
    iVar1 = DAT_ffffffffbfc436f4 + -0x6060;
  }
  (*(code *)(long)DAT_ffffffffbfc4400c)(iVar1);
  return 0;
}

