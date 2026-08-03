/*
 * Ghidra reconstructed C; not original Cisco source.
 * RV220W boot-chain/U-Boot analysis v1.1.0
 * Entry: ffffffffbfc1fa80
 * Function: FUN_ffffffffbfc1fa80
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

undefined8 FUN_ffffffffbfc1fa80(void)

{
  char cVar1;
  long lVar2;
  undefined8 uVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  code *pcVar7;
  long in_k0;
  undefined4 *puVar8;
  undefined8 in_ra;
  
  puVar8 = (undefined4 *)(long)((int)&stack0x00000000 + -0x40);
  *(undefined1 **)(puVar8 + 0xc) = &_gp;
  iVar4 = *(int *)(in_k0 + 0x18);
  *(undefined8 *)(puVar8 + 0xe) = in_ra;
  piVar6 = (int *)(long)DAT_ffffffffbfc43974;
  pcVar7 = (code *)(long)DAT_ffffffffbfc43948;
  *piVar6 = *piVar6 + iVar4;
  piVar6[1] = piVar6[1] + iVar4;
  piVar6[2] = piVar6[2] + iVar4;
  lVar2 = (*pcVar7)(0x2c);
  pcVar7 = (code *)(long)DAT_ffffffffbfc43a54;
  *(int *)(long)DAT_ffffffffbfc43a24 = (int)lVar2;
  if (lVar2 == 0) {
    (*(code *)(long)DAT_ffffffffbfc4378c)(2,DAT_ffffffffbfc436f4 + 0xe00);
    uVar3 = 0xffffffffffffffff;
  }
  else {
    (*pcVar7)(puVar8,0,0x2c);
    iVar5 = (int)&stack0x00000000 + -0x38;
    iVar4 = DAT_ffffffffbfc436f0 + 29000;
    do {
      cVar1 = *(char *)(long)iVar4;
      iVar4 = iVar4 + 1;
      *(char *)(long)iVar5 = cVar1;
      iVar5 = iVar5 + 1;
    } while (cVar1 != '\0');
    pcVar7 = (code *)(long)DAT_ffffffffbfc43a84;
    *puVar8 = 0x80000003;
    puVar8[6] = DAT_ffffffffbfc43b54;
    puVar8[7] = DAT_ffffffffbfc4395c;
    puVar8[9] = DAT_ffffffffbfc43844;
    puVar8[8] = DAT_ffffffffbfc43bf0;
    (*pcVar7)(puVar8);
    uVar3 = 0;
  }
  return uVar3;
}

