/*
 * Ghidra reconstructed C; not original Cisco source.
 * RV220W boot-chain/U-Boot analysis v1.1.0
 * Entry: ffffffffbfc03ce0
 * Function: FUN_ffffffffbfc03ce0
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

uint FUN_ffffffffbfc03ce0(void)

{
  undefined4 uVar1;
  long lVar2;
  uint uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 unaff_s0;
  ulong uVar6;
  undefined8 unaff_s1;
  undefined8 unaff_s2;
  code *pcVar7;
  undefined8 unaff_s3;
  code *pcVar8;
  undefined8 *puVar9;
  undefined8 in_ra;
  
  puVar9 = (undefined8 *)(long)((int)&stack0x00000000 + -0x30);
  puVar9[4] = &_gp;
  puVar9[5] = in_ra;
  puVar9[3] = unaff_s3;
  puVar9[2] = unaff_s2;
  puVar9[1] = unaff_s1;
  *puVar9 = unaff_s0;
  uVar5 = _DAT_8001070000000728;
  pcVar7 = (code *)(long)(DAT_ffffffffbfc436ec + 0x2f40);
  lVar2 = (*pcVar7)(0xd0000);
  pcVar8 = (code *)(long)DAT_ffffffffbfc43ef8;
  if (lVar2 != 0) {
LAB_ffffffffbfc03db8:
    uVar3 = (*pcVar8)();
    return uVar3;
  }
  uVar6 = (ulong)(int)uVar5;
  lVar2 = (*pcVar7)(0x30d0001);
  if (lVar2 == 0) {
    lVar2 = (*pcVar7)(0x30d0300);
    if ((lVar2 != 0) || (lVar2 = (*pcVar7)(0x30d0400), lVar2 != 0)) {
      uVar4 = special2(uVar6 & 0xaaaa,0,0,0x2c);
      uVar5 = special2(uVar6 & 0x5555,0,0,0x2c);
      return 0x5555 >> ((int)uVar5 * -2 + 0x10U & 0x1f) | 0xaaaa >> ((int)uVar4 * -2 + 0x10U & 0x1f)
      ;
    }
  }
  else if ((uVar6 & 0xffff) == 0xffff) {
    lVar2 = (*pcVar7)(0xd0000);
    pcVar8 = (code *)(long)DAT_ffffffffbfc43ef8;
    if (lVar2 == 0) {
      (*(code *)(long)(DAT_ffffffffbfc436ec + 0x30b8))(&DAT_8001180000001500,0x100f);
      lVar2 = _DAT_8001180000001500;
      if (_DAT_8001180000001500 != 0) {
        uVar1 = getCopReg(2,0xc);
        *(undefined4 *)(_DAT_8001180000001500 + -4) = uVar1;
      }
      uVar1 = getCopReg(2,0x13);
      *(undefined4 *)(lVar2 + 0x23) = uVar1;
      pcVar8 = (code *)(long)DAT_ffffffffbfc43ef8;
    }
    goto LAB_ffffffffbfc03db8;
  }
  uVar5 = special2(uVar6 & 0xffff,0,0,0x2c);
  return (1 << ((uint)uVar5 & 0x1f)) - 1;
}

