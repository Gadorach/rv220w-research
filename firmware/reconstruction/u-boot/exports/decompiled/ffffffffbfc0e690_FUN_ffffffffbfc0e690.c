/*
 * Ghidra reconstructed C; not original Cisco source.
 * RV220W boot-chain/U-Boot analysis v1.1.0
 * Entry: ffffffffbfc0e690
 * Function: FUN_ffffffffbfc0e690
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

void FUN_ffffffffbfc0e690(void)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined8 unaff_s0;
  undefined2 *puVar5;
  code *pcVar6;
  undefined8 *puVar7;
  undefined8 in_ra;
  
  puVar7 = (undefined8 *)(long)((int)&stack0x00000000 + -0x20);
  puVar7[1] = &_gp;
  puVar7[2] = in_ra;
  *puVar7 = unaff_s0;
  pcVar6 = (code *)(long)DAT_ffffffffbfc4400c;
  iVar4 = DAT_ffffffffbfc436f4 + -0x59f8;
  *(int *)(long)DAT_ffffffffbfc43c88 = *(int *)(long)DAT_ffffffffbfc43c88 + 1;
  (*pcVar6)(iVar4);
  iVar4 = *(int *)(long)DAT_ffffffffbfc43904;
  iVar2 = (*(code *)(long)DAT_ffffffffbfc43cf8)(iVar4,DAT_ffffffffbfc43e14,0x8035);
  pcVar6 = (code *)(long)DAT_ffffffffbfc43e84;
  iVar4 = iVar4 + iVar2;
  puVar5 = (undefined2 *)(long)iVar4;
  *puVar5 = 1;
  puVar5[1] = 0x800;
  uVar1 = DAT_ffffffffbfc43fa8;
  puVar5[2] = 0x604;
  puVar5[3] = 3;
  (*pcVar6)(iVar4 + 8,uVar1,6);
  (*(code *)(long)DAT_ffffffffbfc43e84)(iVar4 + 0xe,DAT_ffffffffbfc43f80,4);
  (*(code *)(long)DAT_ffffffffbfc43e84)(iVar4 + 0x12,DAT_ffffffffbfc43fa8,6);
  iVar2 = 0;
  do {
    iVar3 = iVar4 + iVar2;
    iVar2 = iVar2 + 1;
    *(undefined1 *)((long)iVar3 + 0x18) = 0xff;
  } while (iVar2 != 4);
  (*(code *)(long)DAT_ffffffffbfc437e0)
            (*(int *)(long)DAT_ffffffffbfc43904,(iVar4 - *(int *)(long)DAT_ffffffffbfc43904) + 0x1c)
  ;
  (*(code *)(long)DAT_ffffffffbfc43fec)(2500000000,DAT_ffffffffbfc436fc + -0x17e0);
  (*(code *)(long)DAT_ffffffffbfc4388c)(DAT_ffffffffbfc436fc + -0x1848);
  return;
}

