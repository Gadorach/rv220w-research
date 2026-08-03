/*
 * Ghidra reconstructed C; not original Cisco source.
 * RV220W boot-chain/U-Boot analysis v1.1.0
 * Entry: ffffffffbfc05748
 * Function: FUN_ffffffffbfc05748
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

char FUN_ffffffffbfc05748(void)

{
  bool bVar1;
  long lVar2;
  long lVar3;
  undefined8 in_t7;
  undefined8 unaff_s0;
  ulong uVar4;
  undefined8 unaff_s1;
  undefined8 unaff_s2;
  undefined8 unaff_s3;
  char cVar5;
  undefined8 *puVar6;
  undefined8 in_ra;
  
  puVar6 = (undefined8 *)(long)((int)&stack0x00000000 + -0x30);
  puVar6[4] = &_gp;
  *puVar6 = unaff_s0;
  puVar6[5] = in_ra;
  puVar6[3] = unaff_s3;
  puVar6[2] = unaff_s2;
  puVar6[1] = unaff_s1;
  uVar4 = _DAT_8001180080000010;
  cVar5 = (_DAT_8001180080000010 & 0x18) != 0;
  if ((bool)cVar5) {
    (*(code *)(long)DAT_ffffffffbfc4400c)(DAT_ffffffffbfc436f4 + -0x7fa8);
    (*(code *)(long)(DAT_ffffffffbfc436ec + 0x4eb8))(&DAT_8001180080000010,uVar4);
  }
  uVar4 = _DAT_8001180080000008;
  if ((_DAT_8001180080000008 & 0x18) != 0) {
    cVar5 = cVar5 + '\x01';
    (*(code *)(long)DAT_ffffffffbfc4400c)(DAT_ffffffffbfc436f4 + -0x7f80);
    (*(code *)(long)(DAT_ffffffffbfc436ec + 0x4eb8))(&DAT_8001180080000008,uVar4);
  }
  lVar3 = (*(code *)(long)(DAT_ffffffffbfc436ec + 0x4d40))(0x30d0400);
  lVar2 = _DAT_8001180080000000;
  if (lVar3 == 0) {
    if ((_DAT_8001180088000000 & 0x1fe00000) == 0) {
      return cVar5;
    }
    cVar5 = cVar5 + '\x01';
    (*(code *)(long)(DAT_ffffffffbfc436ec + 0x4eb8))();
  }
  else {
    setCopReg(2,in_t7,*(undefined4 *)(_DAT_8001180080000000 + 0x12));
    bVar1 = (_DAT_8001180088000000 & 0x1fe00000) != 0;
    if (bVar1) {
      cVar5 = cVar5 + '\x01';
      (*(code *)(long)(DAT_ffffffffbfc436ec + 0x4eb8))();
    }
    uVar4 = (ulong)bVar1;
    setCopReg(2,uVar4,*(undefined4 *)(lVar2 + 0x1f));
    if ((_DAT_80011800e8000000 & 0x1fe00000) != 0) {
      cVar5 = cVar5 + '\x01';
      uVar4 = (ulong)(int)(bVar1 + 1);
      (*(code *)(long)(DAT_ffffffffbfc436ec + 0x4eb8))();
    }
    if (uVar4 == 0) {
      return cVar5;
    }
  }
  (*(code *)(long)DAT_ffffffffbfc4400c)(DAT_ffffffffbfc436f4 + -0x7f58);
  return cVar5;
}

