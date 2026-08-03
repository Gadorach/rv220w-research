/*
 * Ghidra reconstructed C; not original Cisco source.
 * RV220W boot-chain/U-Boot analysis v1.1.0
 * Entry: ffffffffbfc0eae4
 * Function: FUN_ffffffffbfc0eae4
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

void FUN_ffffffffbfc0eae4(long param_1)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  long lVar4;
  int iVar5;
  undefined8 unaff_s0;
  long lVar6;
  undefined8 unaff_s1;
  code *pcVar7;
  undefined8 *puVar8;
  undefined8 in_ra;
  
  puVar8 = (undefined8 *)(long)((int)&stack0x00000000 + -0x20);
  puVar8[2] = &_gp;
  *puVar8 = unaff_s0;
  puVar8[1] = unaff_s1;
  iVar2 = DAT_ffffffffbfc436f4;
  lVar6 = (long)DAT_ffffffffbfc436f4;
  puVar3 = (undefined4 *)(long)DAT_ffffffffbfc43efc;
  iVar1 = *(int *)(lVar6 + 0x4a78);
  iVar5 = DAT_ffffffffbfc436f4 + -23000;
  puVar8[3] = in_ra;
  pcVar7 = (code *)(long)DAT_ffffffffbfc43f0c;
  *puVar3 = 0;
  if ((long)iVar1 != 0) {
    if (param_1 != 0) {
      *(int *)((long)DAT_ffffffffbfc436f4 + 0x4a70) = iVar1;
    }
    *(undefined4 *)(lVar6 + 0x4a78) = *(undefined4 *)((long)iVar1 + 0x30);
    lVar4 = (*pcVar7)(iVar5);
    if (lVar4 == 0) {
      (*(code *)(long)DAT_ffffffffbfc43b14)(iVar2 + -23000,*(undefined4 *)(lVar6 + 0x4a78));
    }
    if (*(int *)((long)DAT_ffffffffbfc436f4 + 0x4a70) == *(int *)(lVar6 + 0x4a78)) {
      *(undefined4 *)(long)DAT_ffffffffbfc43a04 = 1;
    }
  }
  return;
}

