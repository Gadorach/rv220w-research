/*
 * Ghidra reconstructed C; not original Cisco source.
 * RV220W boot-chain/U-Boot analysis v1.1.0
 * Entry: ffffffffbfc05560
 * Function: FUN_ffffffffbfc05560
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

undefined8 FUN_ffffffffbfc05560(void)

{
  int iVar1;
  long lVar2;
  undefined8 unaff_s0;
  ulong uVar3;
  undefined8 unaff_s1;
  code *pcVar4;
  undefined8 unaff_s2;
  undefined8 *puVar5;
  undefined8 in_ra;
  
  puVar5 = (undefined8 *)(long)((int)&stack0x00000000 + -0x30);
  puVar5[3] = &_gp;
  puVar5[1] = unaff_s1;
  *puVar5 = unaff_s0;
  iVar1 = DAT_ffffffffbfc436ec;
  puVar5[4] = in_ra;
  pcVar4 = (code *)(long)(iVar1 + 0x4d40);
  puVar5[2] = unaff_s2;
  lVar2 = (*pcVar4)(0x30d0100);
  if ((lVar2 == 0) && (lVar2 = (*pcVar4)(0x30d0200), lVar2 == 0)) {
    lVar2 = (*pcVar4)(0x30d0600);
    if (lVar2 == 0) goto LAB_ffffffffbfc055f0;
  }
  (*(code *)(long)(DAT_ffffffffbfc436ec + 0x4eb8))(&DAT_80010700000008a8,0xf00);
LAB_ffffffffbfc055f0:
  pcVar4 = (code *)(long)(DAT_ffffffffbfc436ec + 0x4eb8);
  (*pcVar4)(0x8001180000000000,0xb23f1dc0);
  uVar3 = 0xfc0000000343;
  lVar2 = (*(code *)(long)(DAT_ffffffffbfc436ec + 0x4d40))(0x30d0100);
  if (lVar2 != 0) {
    uVar3 = 0x100fc0000000343;
  }
  (*pcVar4)(0x8001180000000040,uVar3 | 0x700024724d000);
  (*pcVar4)(0x8001180000000010,0x90001d01);
  (*pcVar4)(0x8001180000000050,0x3ffc049a9b3200);
  (*pcVar4)(0x8001180000000018,0x90001d00);
  (*pcVar4)(0x8001180000000058,0x403f78021a9a0200);
  (*pcVar4)(0x8001180000000020,0x80001d02);
  (*pcVar4)(0x8001180000000028,0x80001d03);
  (*pcVar4)(&DAT_8001180000001000,0x8c00000300000028);
  return 0;
}

