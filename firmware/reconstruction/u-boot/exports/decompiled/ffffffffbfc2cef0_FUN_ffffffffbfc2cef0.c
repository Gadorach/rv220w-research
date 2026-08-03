/*
 * Ghidra reconstructed C; not original Cisco source.
 * RV220W boot-chain/U-Boot analysis v1.1.0
 * Entry: ffffffffbfc2cef0
 * Function: FUN_ffffffffbfc2cef0
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
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

undefined8 FUN_ffffffffbfc2cef0(void)

{
  int iVar1;
  undefined8 in_zero;
  long lVar2;
  ulong uVar3;
  undefined8 unaff_s0;
  undefined8 unaff_s1;
  code *pcVar4;
  undefined8 unaff_s2;
  undefined8 unaff_s3;
  undefined8 unaff_s4;
  undefined8 *puVar5;
  undefined8 in_ra;
  undefined8 in_HW_RESIM31;
  
  puVar5 = (undefined8 *)(long)((int)&stack0x00000000 + -0x40);
  puVar5[5] = &_gp;
  *puVar5 = unaff_s0;
  iVar1 = DAT_ffffffffbfc436f0;
  puVar5[1] = unaff_s1;
  pcVar4 = (code *)(long)(iVar1 + -0x3140);
  puVar5[6] = in_ra;
  puVar5[4] = unaff_s4;
  puVar5[3] = unaff_s3;
  puVar5[2] = unaff_s2;
  (*pcVar4)(0x80014f0000000028,0x20000);
  (*pcVar4)(0x80014f00000000a8,0x20000);
  (*pcVar4)(0x80014f0000000148,1000);
  (*pcVar4)(0x80014f0000000148,0x200003e8);
  lVar2 = getHWRegister(in_HW_RESIM31);
  do {
    uVar3 = getHWRegister(in_HW_RESIM31);
  } while (uVar3 < lVar2 + 500U);
  pcVar4 = (code *)(long)(DAT_ffffffffbfc436f0 + -0x3140);
  (*pcVar4)(0x80011f0000000008,0x9004);
  lVar2 = _DAT_80011f00000001e8;
  (*pcVar4)(0x80011f0000000008,0x9804);
  (*pcVar4)(0x80014f0000000148,0x1fffc18);
  (*pcVar4)(0x80014f0000000148,0x21fffc18);
  (*pcVar4)(0x80014f0000000028,0);
  (*pcVar4)(0x80014f00000000a8,0);
  (*pcVar4)(0x80014f0000000168,0x1f);
  if (_DAT_80011800080007f8 != 3) {
    lVar2 = 0;
  }
  setCopReg(2,in_zero,*(undefined4 *)(lVar2 + 3));
  return 0;
}

