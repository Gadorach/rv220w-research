/*
 * Ghidra reconstructed C; not original Cisco source.
 * RV220W boot-chain/U-Boot analysis v1.1.0
 * Entry: ffffffffbfc214f0
 * Function: FUN_ffffffffbfc214f0
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

void FUN_ffffffffbfc214f0(void)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined8 unaff_s0;
  undefined8 unaff_s1;
  undefined8 unaff_s2;
  undefined8 unaff_s3;
  undefined8 unaff_s4;
  code *pcVar5;
  long in_k0;
  undefined8 *puVar6;
  undefined8 in_ra;
  
  puVar6 = (undefined8 *)(long)((int)&stack0x00000000 + -0x40);
  puVar6[5] = &_gp;
  puVar6[4] = unaff_s4;
  pcVar5 = (code *)(long)DAT_ffffffffbfc43e1c;
  puVar6[6] = in_ra;
  puVar6[3] = unaff_s3;
  puVar6[2] = unaff_s2;
  puVar6[1] = unaff_s1;
  *puVar6 = unaff_s0;
  uVar1 = (*pcVar5)(0x8c);
  iVar3 = 0;
  *(undefined4 *)(in_k0 + 0x80) = uVar1;
  iVar4 = DAT_ffffffffbfc43700 + 0x14e0;
  do {
    iVar2 = *(int *)(in_k0 + 0x80) + iVar3;
    iVar3 = iVar3 + 4;
    *(int *)(long)iVar2 = iVar4;
  } while (iVar3 != 0x8c);
  iVar3 = *(int *)(in_k0 + 0x80);
  *(undefined4 *)(long)*(int *)(in_k0 + 0x80) = DAT_ffffffffbfc4382c;
  iVar4 = *(int *)(in_k0 + 0x80);
  *(int *)((long)iVar3 + 0x20) = DAT_ffffffffbfc43e1c;
  iVar3 = *(int *)(in_k0 + 0x80);
  *(undefined4 *)((long)iVar4 + 0x24) = DAT_ffffffffbfc43734;
  iVar4 = *(int *)(in_k0 + 0x80);
  *(undefined4 *)((long)iVar3 + 0x2c) = DAT_ffffffffbfc43d0c;
  iVar3 = *(int *)(in_k0 + 0x80);
  *(undefined4 *)((long)iVar4 + 0x28) = DAT_ffffffffbfc43b18;
  iVar4 = *(int *)(in_k0 + 0x80);
  *(undefined4 *)((long)iVar3 + 0x5c) = DAT_ffffffffbfc438fc;
  iVar3 = *(int *)(in_k0 + 0x80);
  *(undefined4 *)((long)iVar4 + 0x60) = DAT_ffffffffbfc43f38;
  iVar4 = *(int *)(in_k0 + 0x80);
  *(undefined4 *)((long)iVar3 + 100) = DAT_ffffffffbfc43bfc;
  iVar3 = *(int *)(in_k0 + 0x80);
  *(undefined4 *)((long)iVar4 + 0x38) = DAT_ffffffffbfc43b80;
  iVar4 = *(int *)(in_k0 + 0x80);
  *(undefined4 *)((long)iVar3 + 0x3c) = DAT_ffffffffbfc43e84;
  iVar3 = *(int *)(in_k0 + 0x80);
  *(undefined4 *)((long)iVar4 + 0x40) = DAT_ffffffffbfc43a54;
  iVar4 = *(int *)(in_k0 + 0x80);
  *(undefined4 *)((long)iVar3 + 0x44) = DAT_ffffffffbfc43e10;
  iVar3 = *(int *)(in_k0 + 0x80);
  *(undefined4 *)((long)iVar4 + 0x48) = DAT_ffffffffbfc43b24;
  iVar4 = *(int *)(in_k0 + 0x80);
  *(undefined4 *)((long)iVar3 + 0x7c) = DAT_ffffffffbfc43eec;
  iVar3 = *(int *)(in_k0 + 0x80);
  *(undefined4 *)((long)iVar4 + 0x58) = DAT_ffffffffbfc43b08;
  iVar4 = *(int *)(in_k0 + 0x80);
  *(undefined4 *)((long)iVar3 + 0x68) = DAT_ffffffffbfc43d40;
  *(undefined4 *)((long)iVar4 + 0x4c) = DAT_ffffffffbfc43ff0;
  iVar3 = *(int *)(in_k0 + 0x80);
  *(undefined4 *)((long)*(int *)(in_k0 + 0x80) + 0x50) = DAT_ffffffffbfc43a88;
  iVar4 = *(int *)(in_k0 + 0x80);
  *(undefined4 *)((long)iVar3 + 0x6c) = DAT_ffffffffbfc43ab4;
  iVar3 = *(int *)(in_k0 + 0x80);
  *(undefined4 *)((long)iVar4 + 0x54) = DAT_ffffffffbfc43fe8;
  iVar4 = *(int *)(in_k0 + 0x80);
  *(undefined4 *)((long)iVar3 + 0x70) = DAT_ffffffffbfc43b4c;
  iVar3 = *(int *)(in_k0 + 0x80);
  *(undefined4 *)((long)iVar4 + 0x74) = DAT_ffffffffbfc43834;
  iVar4 = *(int *)(in_k0 + 0x80);
  *(undefined4 *)((long)iVar3 + 0x78) = DAT_ffffffffbfc4383c;
  iVar3 = *(int *)(in_k0 + 0x80);
  *(undefined4 *)((long)iVar4 + 0x80) = DAT_ffffffffbfc43a28;
  iVar4 = *(int *)(in_k0 + 0x80);
  *(undefined4 *)((long)iVar3 + 0x84) = DAT_ffffffffbfc439a4;
  *(undefined4 *)((long)iVar4 + 0x88) = DAT_ffffffffbfc43ce8;
  return;
}

