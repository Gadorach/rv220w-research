/*
 * Ghidra reconstructed C; not original Cisco source.
 * RV220W boot-chain/U-Boot analysis v1.1.0
 * Entry: ffffffffbfc0c090
 * Function: FUN_ffffffffbfc0c090
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

undefined8 FUN_ffffffffbfc0c090(long param_1,undefined8 param_2,undefined2 param_3)

{
  ushort *puVar1;
  ushort uVar2;
  undefined8 unaff_s0;
  int iVar3;
  undefined8 unaff_s1;
  undefined8 unaff_s2;
  undefined8 unaff_s3;
  undefined8 *puVar4;
  undefined8 in_ra;
  
  puVar4 = (undefined8 *)(long)((int)&stack0x00000000 + -0x30);
  puVar4[4] = &_gp;
  puVar4[2] = unaff_s2;
  puVar4[3] = unaff_s3;
  puVar1 = (ushort *)(long)DAT_ffffffffbfc43830;
  puVar4[1] = unaff_s1;
  uVar2 = *puVar1;
  *puVar4 = unaff_s0;
  puVar4[5] = in_ra;
  iVar3 = (int)param_1 + 6;
  if (uVar2 == 0xffff) {
    (*(code *)(long)DAT_ffffffffbfc43e84)(param_1,param_2,6);
    (*(code *)(long)DAT_ffffffffbfc43e84)(iVar3,DAT_ffffffffbfc43fa8,6);
    *(undefined2 *)(param_1 + 0xc) = param_3;
  }
  else {
    (*(code *)(long)DAT_ffffffffbfc43e84)(param_1,param_2,6);
    (*(code *)(long)DAT_ffffffffbfc43e84)(iVar3,DAT_ffffffffbfc43fa8,6);
    uVar2 = uVar2 & 0xfff;
    if (uVar2 != 0xfff) {
      *(undefined2 *)(param_1 + 0x10) = param_3;
      *(undefined2 *)(param_1 + 0xc) = 0x8100;
      *(ushort *)(param_1 + 0xe) = uVar2;
      return 0x12;
    }
    *(undefined2 *)(param_1 + 0xc) = param_3;
  }
  return 0xe;
}

