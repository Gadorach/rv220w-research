/*
 * Ghidra reconstructed C; not original Cisco source.
 * RV220W boot-chain/U-Boot analysis v1.1.0
 * Entry: ffffffffbfc0cc08
 * Function: FUN_ffffffffbfc0cc08
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

void FUN_ffffffffbfc0cc08(void)

{
  bool bVar1;
  char cVar2;
  char cVar3;
  char cVar4;
  char cVar5;
  char *pcVar6;
  int iVar8;
  long lVar7;
  char cVar10;
  undefined4 uVar9;
  char *pcVar11;
  undefined8 unaff_s0;
  undefined4 *in_k0;
  undefined8 *puVar12;
  undefined8 in_ra;
  
  puVar12 = (undefined8 *)(long)((int)&stack0x00000000 + -0x20);
  puVar12[1] = &_gp;
  puVar12[2] = in_ra;
  *puVar12 = unaff_s0;
  pcVar6 = (char *)(*(code *)(long)DAT_ffffffffbfc43f0c)(DAT_ffffffffbfc436f4 + -0x5e10);
  if (pcVar6 == (char *)0x0) {
    bVar1 = false;
  }
  else {
    iVar8 = DAT_ffffffffbfc436f4 + -0x5e00;
    cVar2 = *pcVar6;
    pcVar11 = pcVar6;
    do {
      cVar3 = *(char *)(long)iVar8;
      pcVar11 = (char *)(long)((int)pcVar11 + 1);
      iVar8 = iVar8 + 1;
      cVar10 = cVar2;
      if (cVar3 != cVar2) break;
      bVar1 = cVar2 != '\0';
      cVar2 = *pcVar11;
      cVar10 = cVar3;
    } while (bVar1);
    iVar8 = DAT_ffffffffbfc436f4 + -0x5df8;
    cVar2 = *pcVar6;
    do {
      cVar4 = *(char *)(long)iVar8;
      pcVar6 = (char *)(long)((int)pcVar6 + 1);
      iVar8 = iVar8 + 1;
      cVar5 = cVar2;
      if (cVar4 != cVar2) break;
      bVar1 = cVar2 != '\0';
      cVar2 = *pcVar6;
      cVar5 = cVar4;
    } while (bVar1);
    bVar1 = cVar5 == cVar4;
    if (cVar10 == cVar3) {
      (*(code *)(long)DAT_ffffffffbfc43eec)();
      uVar9 = 4;
      goto LAB_ffffffffbfc0cd44;
    }
  }
  (*(code *)(long)DAT_ffffffffbfc43eec)();
  (*(code *)(long)DAT_ffffffffbfc43bb4)(*(int *)((long)DAT_ffffffffbfc436f4 + 0x4a10) == 0);
  (*(code *)(long)DAT_ffffffffbfc43874)(*in_k0);
  lVar7 = (long)DAT_ffffffffbfc436f4;
  if (*(int *)(long)DAT_ffffffffbfc43a04 == 0) {
    uVar9 = 2;
  }
  else {
    *(int *)(long)DAT_ffffffffbfc43a04 = 0;
    uVar9 = 4;
    if ((*(int *)(lVar7 + 0x4a14) != 0) && (!bVar1)) {
      (*(code *)(long)DAT_ffffffffbfc43fec)(5000000000,DAT_ffffffffbfc436fc + -0x4370);
      *(int *)((long)DAT_ffffffffbfc436f4 + 0x4a18) = DAT_ffffffffbfc436fc + -0x4354;
      return;
    }
  }
LAB_ffffffffbfc0cd44:
  *(undefined4 *)(long)DAT_ffffffffbfc43d80 = uVar9;
  return;
}

