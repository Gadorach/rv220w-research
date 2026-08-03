/*
 * Ghidra reconstructed C; not original Cisco source.
 * RV220W boot-chain/U-Boot analysis v1.1.0
 * Entry: ffffffffbfc03ea4
 * Function: FUN_ffffffffbfc03ea4
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

ulong FUN_ffffffffbfc03ea4(long param_1)

{
  int iVar1;
  int iVar2;
  ulong uVar3;
  ulong uVar4;
  int iVar5;
  undefined8 unaff_s0;
  undefined8 unaff_s1;
  long lVar6;
  undefined8 unaff_s2;
  ulong uVar7;
  undefined8 unaff_s3;
  undefined8 *puVar8;
  undefined8 in_ra;
  
  puVar8 = (undefined8 *)(long)((int)&stack0x00000000 + -0x30);
  puVar8[4] = &_gp;
  *puVar8 = unaff_s0;
  puVar8[5] = in_ra;
  puVar8[3] = unaff_s3;
  puVar8[2] = unaff_s2;
  puVar8[1] = unaff_s1;
  if (param_1 == 0) {
    uVar3 = 0;
  }
  else {
    uVar7 = 1;
    uVar3 = (*(code *)(long)DAT_ffffffffbfc43738)();
    iVar1 = DAT_ffffffffbfc436f0;
    iVar5 = 1;
    iVar2 = 2;
    do {
      uVar4 = uVar3 & uVar7;
      iVar5 = iVar5 + 1;
      uVar7 = (long)iVar2 | 1;
      lVar6 = special2(uVar4,0,0,0x2c);
      if (lVar6 == param_1) {
        return uVar4;
      }
      iVar2 = (int)uVar7 << 1;
    } while (iVar5 != 0x11);
    (*(code *)(long)DAT_ffffffffbfc4400c)(DAT_ffffffffbfc436f0 + 0x7c98);
    (*(code *)(long)DAT_ffffffffbfc4400c)(DAT_ffffffffbfc436f0 + 0x7cf0,lVar6);
    (*(code *)(long)DAT_ffffffffbfc4400c)(iVar1 + 0x7c98);
    uVar3 = uVar3 & uVar7;
  }
  return uVar3;
}

