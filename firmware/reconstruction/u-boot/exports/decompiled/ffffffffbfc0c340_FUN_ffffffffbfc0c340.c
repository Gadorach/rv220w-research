/*
 * Ghidra reconstructed C; not original Cisco source.
 * RV220W boot-chain/U-Boot analysis v1.1.0
 * Entry: ffffffffbfc0c340
 * Function: FUN_ffffffffbfc0c340
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

void FUN_ffffffffbfc0c340(void)

{
  undefined4 uVar1;
  int iVar4;
  uint *puVar2;
  int *piVar3;
  undefined8 unaff_s0;
  undefined2 *puVar5;
  undefined8 unaff_s1;
  uint *puVar7;
  undefined8 unaff_s2;
  undefined8 unaff_s3;
  int *piVar8;
  code *pcVar9;
  undefined8 *puVar10;
  undefined8 in_ra;
  int iVar6;
  
  puVar10 = (undefined8 *)(long)((int)&stack0x00000000 + -0x30);
  puVar10[4] = &_gp;
  *puVar10 = unaff_s0;
  puVar10[5] = in_ra;
  uVar1 = DAT_ffffffffbfc43e14;
  pcVar9 = (code *)(long)DAT_ffffffffbfc43cf8;
  iVar6 = *(int *)(long)DAT_ffffffffbfc43904;
  puVar10[3] = unaff_s3;
  puVar10[2] = unaff_s2;
  puVar10[1] = unaff_s1;
  iVar4 = (*pcVar9)(iVar6,uVar1,0x806);
  uVar1 = DAT_ffffffffbfc43fa8;
  iVar6 = iVar6 + iVar4;
  puVar5 = (undefined2 *)(long)iVar6;
  pcVar9 = (code *)(long)DAT_ffffffffbfc43e84;
  puVar5[1] = 0x800;
  puVar5[3] = 1;
  *puVar5 = 1;
  puVar7 = (uint *)(long)DAT_ffffffffbfc43f80;
  puVar5[2] = 0x604;
  (*pcVar9)(iVar6 + 8,uVar1,6);
  piVar8 = (int *)(long)DAT_ffffffffbfc43a90;
  (*(code *)(long)(DAT_ffffffffbfc436fc + -0x3d54))(iVar6 + 0xe,*puVar7);
  puVar2 = (uint *)(long)DAT_ffffffffbfc43dcc;
  *(undefined1 *)(puVar5 + 9) = 0;
  *(undefined1 *)((long)puVar5 + 0x13) = 0;
  *(undefined1 *)(puVar5 + 10) = 0;
  *(undefined1 *)((long)puVar5 + 0x15) = 0;
  *(undefined1 *)(puVar5 + 0xb) = 0;
  *(undefined1 *)((long)puVar5 + 0x17) = 0;
  if ((*puVar2 & *(uint *)(long)DAT_ffffffffbfc43c58) ==
      (*(uint *)(long)DAT_ffffffffbfc43c58 & *puVar7)) {
    *(uint *)(long)DAT_ffffffffbfc43e5c = *puVar2;
    piVar3 = (int *)(long)DAT_ffffffffbfc43e5c;
  }
  else {
    if (*piVar8 == 0) {
      (*(code *)(long)DAT_ffffffffbfc43e38)(DAT_ffffffffbfc436f4 + -0x5eb0);
    }
    piVar3 = (int *)(long)DAT_ffffffffbfc43e5c;
    *piVar3 = *piVar8;
  }
  (*(code *)(long)(DAT_ffffffffbfc436fc + -0x3d54))(iVar6 + 0x18,*piVar3);
  (*(code *)(long)DAT_ffffffffbfc4376c)
            (*(int *)(long)DAT_ffffffffbfc43904,(iVar6 - *(int *)(long)DAT_ffffffffbfc43904) + 0x1c)
  ;
  return;
}

