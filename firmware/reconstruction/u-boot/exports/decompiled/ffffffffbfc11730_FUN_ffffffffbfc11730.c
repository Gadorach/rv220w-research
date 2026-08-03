/*
 * Ghidra reconstructed C; not original Cisco source.
 * RV220W boot-chain/U-Boot analysis v1.1.0
 * Entry: ffffffffbfc11730
 * Function: FUN_ffffffffbfc11730
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
FUN_ffffffffbfc11730
          (undefined8 param_1,undefined8 param_2,int param_3,undefined8 param_4,uint param_5)

{
  uint uVar1;
  undefined8 in_zero;
  int iVar2;
  undefined8 unaff_s0;
  undefined8 unaff_s1;
  undefined8 unaff_s2;
  undefined8 unaff_s3;
  int iVar3;
  undefined8 unaff_s4;
  undefined8 unaff_s5;
  undefined8 unaff_s6;
  code *pcVar4;
  char *pcVar5;
  undefined8 in_ra;
  int iVar6;
  
  iVar6 = (int)&stack0x00000000;
  pcVar5 = (char *)(long)(iVar6 + -0x60);
  *(undefined1 **)(pcVar5 + 0x48) = &_gp;
  *(undefined8 *)(pcVar5 + 0x40) = unaff_s6;
  pcVar4 = (code *)(long)DAT_ffffffffbfc43910;
  *(undefined8 *)(pcVar5 + 0x38) = unaff_s5;
  *(undefined8 *)(pcVar5 + 0x30) = unaff_s4;
  *(undefined8 *)(pcVar5 + 0x28) = unaff_s3;
  *(undefined8 *)(pcVar5 + 0x20) = unaff_s2;
  *(undefined8 *)(pcVar5 + 0x18) = unaff_s1;
  *(undefined8 *)(pcVar5 + 0x50) = in_ra;
  *(undefined8 *)(pcVar5 + 0x10) = unaff_s0;
  iVar3 = 0x10;
  (*pcVar4)(param_1,param_2,4,0);
  do {
    (*(code *)(long)DAT_ffffffffbfc43910)(param_1,param_2,iVar3,0xffffffffffffffff);
    (*(code *)(long)DAT_ffffffffbfc43fa0)(param_1,param_2,iVar3,iVar6 + -0x5c);
    uVar1 = *(uint *)(pcVar5 + 4);
    if ((long)(int)uVar1 != 0) {
      iVar2 = (param_3 - 1U | -(uVar1 & 0xfffffffc) - 1) + 1;
      setCopReg(2,in_zero,*(undefined4 *)((long)(int)uVar1 + 4));
      param_3 = iVar2 + -(uVar1 & 0xfffffffc);
      (*(code *)(long)DAT_ffffffffbfc43910)(param_1,param_2,iVar3,iVar2,-(uVar1 & 0xfffffff0));
    }
    iVar3 = iVar3 + 4;
  } while (iVar3 < 0x24);
  (*(code *)(long)DAT_ffffffffbfc437a4)(param_1,param_2,0xc,8);
  (*(code *)(long)DAT_ffffffffbfc437a4)(param_1,param_2,0xd,0x80);
  (*(code *)(long)DAT_ffffffffbfc43744)(param_1,param_2,0x3d,pcVar5);
  if (*pcVar5 != '\0') {
    (*(code *)(long)DAT_ffffffffbfc437a4)(param_1,param_2,0x3c,0xff);
  }
  (*(code *)(long)DAT_ffffffffbfc43fa0)(param_1,param_2,4,iVar6 + -0x58);
  (*(code *)(long)DAT_ffffffffbfc43910)
            (param_1,param_2,4,*(uint *)(pcVar5 + 8) & 0xffff0000 | param_5);
  return 0;
}

