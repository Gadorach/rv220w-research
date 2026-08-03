/*
 * Ghidra reconstructed C; not original Cisco source.
 * RV220W boot-chain/U-Boot analysis v1.1.0
 * Entry: ffffffffbfc0c188
 * Function: FUN_ffffffffbfc0c188
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

void FUN_ffffffffbfc0c188
               (undefined1 *param_1,undefined4 param_2,undefined2 param_3,undefined2 param_4,
               long param_5)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined8 in_zero;
  ushort uVar4;
  int iVar5;
  int *piVar6;
  undefined8 unaff_s0;
  undefined8 unaff_s1;
  undefined8 unaff_s2;
  undefined8 unaff_s3;
  undefined8 unaff_s4;
  code *pcVar7;
  undefined4 *puVar8;
  undefined8 in_ra;
  
  puVar8 = (undefined4 *)(long)((int)&stack0x00000000 + -0x50);
  *(undefined1 **)(puVar8 + 0xe) = &_gp;
  *(undefined8 *)(puVar8 + 6) = unaff_s1;
  iVar2 = DAT_ffffffffbfc436fc;
  *(undefined8 *)(puVar8 + 0xc) = unaff_s4;
  *(undefined8 *)(puVar8 + 4) = unaff_s0;
  *(undefined8 *)(puVar8 + 10) = unaff_s3;
  *(undefined8 *)(puVar8 + 8) = unaff_s2;
  iVar5 = (int)param_1;
  *puVar8 = param_2;
  *(undefined8 *)(puVar8 + 0x10) = in_ra;
  uVar3 = DAT_ffffffffbfc43f80;
  piVar6 = (int *)(long)DAT_ffffffffbfc43bec;
  setCopReg(2,in_zero,*(undefined4 *)(param_5 + 2));
  *(undefined1 *)((long)(iVar5 + (int)param_5) + 0x1c) = 0;
  *param_1 = 0x45;
  param_1[1] = 0;
  iVar1 = *piVar6;
  *(short *)(param_1 + 2) = (short)param_5 + 0x1c;
  *(short *)(param_1 + 4) = (short)iVar1;
  *(undefined2 *)(param_1 + 6) = 0x4000;
  *piVar6 = iVar1 + 1;
  param_1[8] = 0xff;
  param_1[9] = 0x11;
  *(undefined2 *)(param_1 + 10) = 0;
  (*(code *)(long)(iVar2 + -0x3e90))(iVar5 + 0xc,uVar3);
  (*(code *)(long)(iVar2 + -0x3e90))(iVar5 + 0x10,puVar8);
  pcVar7 = (code *)(long)DAT_ffffffffbfc43a5c;
  *(undefined2 *)(param_1 + 0x14) = param_4;
  *(undefined2 *)(param_1 + 0x16) = param_3;
  *(short *)(param_1 + 0x18) = (short)param_5 + 8;
  *(undefined2 *)(param_1 + 0x1a) = 0;
  uVar4 = (*pcVar7)(param_1,10);
  *(ushort *)(param_1 + 10) = ~uVar4;
  return;
}

