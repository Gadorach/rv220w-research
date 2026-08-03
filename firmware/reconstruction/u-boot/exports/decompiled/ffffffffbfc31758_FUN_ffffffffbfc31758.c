/*
 * Ghidra reconstructed C; not original Cisco source.
 * RV220W boot-chain/U-Boot analysis v1.1.0
 * Entry: ffffffffbfc31758
 * Function: FUN_ffffffffbfc31758
 * Subsystem: bootloader-support
 *
 * RV220W BOOT-CHAIN / U-BOOT SEMANTIC ANNOTATION v1.1.0
 * Region: u-boot-proper
 * Subsystem: bootloader-support
 * Evidence: Ghidra control-flow/GOT recovery
 * Confidence: medium for boundary; low for original name
 * Interpretation: Analysis-created function. Boundary is supported by control flow or a recovered GOT pointer, but original source name and detailed role are unknown.
 * Safety: reconstructed pseudocode is not original Cisco source. Do not replay flash, GPIO, MDIO or switch writes without readback and recovery safeguards.
 * 
 * Prior/recovered evidence:
 * RV220W BOOT-CHAIN / U-BOOT SEMANTIC ANNOTATION v1.1.0
 * Region: u-boot-proper
 * Subsystem: bootloader-support
 * Evidence: Ghidra control-flow/GOT recovery
 * Confidence: medium for boundary; low for original name
 * Interpretation: Analysis-created function. Boundary is supported by control flow or a recovered GOT pointer, but original source name and detailed role are unknown.
 * Safety: reconstructed pseudocode is not original Cisco source. Do not replay flash, GPIO, MDIO or switch writes without readback and recovery safeguards.
 * 
 * Prior/recovered evidence:
 * RV220W BOOT-CHAIN / U-BOOT SEMANTIC ANNOTATION v1.1.0
 * Region: u-boot-proper
 * Subsystem: bootloader-support
 * Evidence: Ghidra control-flow/GOT recovery
 * Confidence: medium for boundary; low for original name
 * Interpretation: Analysis-created function. Boundary is supported by control flow or a recovered GOT pointer, but original source name and detailed role are unknown.
 * Safety: reconstructed pseudocode is not original Cisco source. Do not replay flash, GPIO, MDIO or switch writes without readback and recovery safeguards.
 */

/* RV220W BOOT-CHAIN / U-BOOT SEMANTIC ANNOTATION v1.1.0
   Region: u-boot-proper
   Subsystem: bootloader-support
   Evidence: Ghidra control-flow/GOT recovery
   Confidence: medium for boundary; low for original name
   Interpretation: Analysis-created function. Boundary is supported by control flow or a recovered
   GOT pointer, but original source name and detailed role are unknown.
   Safety: reconstructed pseudocode is not original Cisco source. Do not replay flash, GPIO, MDIO or
   switch writes without readback and recovery safeguards.
   
   Prior/recovered evidence:
   RV220W BOOT-CHAIN / U-BOOT SEMANTIC ANNOTATION v1.1.0
   Region: u-boot-proper
   Subsystem: bootloader-support
   Evidence: Ghidra control-flow/GOT recovery
   Confidence: medium for boundary; low for original name
   Interpretation: Analysis-created function. Boundary is supported by control flow or a recovered
   GOT pointer, but original source name and detailed role are unknown.
   Safety: reconstructed pseudocode is not original Cisco source. Do not replay flash, GPIO, MDIO or
   switch writes without readback and recovery safeguards.
   
   Prior/recovered evidence:
   RV220W BOOT-CHAIN / U-BOOT SEMANTIC ANNOTATION v1.1.0
   Region: u-boot-proper
   Subsystem: bootloader-support
   Evidence: Ghidra control-flow/GOT recovery
   Confidence: medium for boundary; low for original name
   Interpretation: Analysis-created function. Boundary is supported by control flow or a recovered
   GOT pointer, but original source name and detailed role are unknown.
   Safety: reconstructed pseudocode is not original Cisco source. Do not replay flash, GPIO, MDIO or
   switch writes without readback and recovery safeguards. */

ulong FUN_ffffffffbfc31758(undefined8 param_1)

{
  undefined4 uVar1;
  ulong uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  long lVar5;
  long *plVar6;
  ulong uVar7;
  ulong uVar8;
  ulong uVar9;
  undefined8 in_t1;
  undefined8 unaff_s0;
  undefined8 unaff_s1;
  undefined8 unaff_s2;
  undefined8 unaff_s3;
  long unaff_s4;
  code *pcVar10;
  undefined8 *puVar11;
  undefined8 in_ra;
  undefined1 auVar12 [16];
  
  puVar11 = (undefined8 *)(long)((int)&stack0x00000000 + -0x40);
  puVar11[5] = &_gp;
  puVar11[6] = in_ra;
  puVar11[3] = unaff_s3;
  pcVar10 = (code *)(long)DAT_ffffffffbfc43fb0;
  puVar11[2] = unaff_s2;
  puVar11[1] = unaff_s1;
  *puVar11 = unaff_s0;
  puVar11[4] = unaff_s4;
  uVar3 = (*pcVar10)();
  uVar4 = (*(code *)(long)DAT_ffffffffbfc43dd0)(param_1);
  lVar5 = (*(code *)(long)DAT_ffffffffbfc43c60)();
  if (*(short *)(lVar5 + 0x40) == 1) {
    uVar7 = 0xc03e8;
  }
  else {
    special2(uVar3,unaff_s4,0x1b,0x32);
    uVar1 = getCopReg(2,0);
    *(undefined4 *)(*(long *)(&DAT_80011800080007f8 + unaff_s4) + 0x3b) = uVar1;
    plVar6 = (long *)(*(code *)(long)(DAT_ffffffffbfc436f0 + 0x123c))(uVar4,uVar3);
    setCopReg(2,in_t1,*(undefined4 *)(*plVar6 + 0x2f));
    plVar6 = (long *)(*(code *)(long)(DAT_ffffffffbfc436f0 + 0x1294))(uVar4,uVar3);
    uVar1 = getCopReg(2,2);
    *(undefined4 *)(*plVar6 + 9) = uVar1;
    auVar12 = (*(code *)(long)(DAT_ffffffffbfc436f0 + 0x1344))(uVar3,uVar4);
    uVar7 = 0;
    if (auVar12._0_8_ == 0) {
      special2(uVar4,auVar12._8_8_,10,0x32);
      uVar7 = *(ulong *)(unaff_s4 + auVar12._8_8_ + -0x7ffee7ff4fffefe0);
      setCopReg(2,0x80011800b0001020,*(undefined4 *)(uVar7 + 0x11));
      uVar9 = uVar7 >> 3 & 3;
      uVar2 = (uVar7 >> 1 & 1) << 0x12;
      uVar7 = uVar2 | (uVar7 & 1) << 0x13;
      if (uVar9 == 1) {
        uVar8 = 100;
      }
      else {
        uVar8 = 1000;
        if (uVar9 != 2) {
          if (uVar9 != 0) {
            return uVar2;
          }
          return uVar7 | 10;
        }
      }
      uVar7 = uVar7 | uVar8;
    }
  }
  return uVar7;
}

