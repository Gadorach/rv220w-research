/*
 * Ghidra reconstructed C; not original Cisco source.
 * RV220W boot-chain/U-Boot analysis v1.1.0
 * Entry: ffffffffbfc33b3c
 * Function: FUN_ffffffffbfc33b3c
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

undefined8 FUN_ffffffffbfc33b3c(undefined8 param_1,long param_2,undefined8 param_3)

{
  uint uVar1;
  undefined8 uVar2;
  undefined8 extraout_at;
  long lVar3;
  ulong uVar4;
  long lVar5;
  undefined8 in_t2;
  undefined8 unaff_s0;
  undefined8 unaff_s1;
  undefined8 unaff_s2;
  undefined8 unaff_s3;
  code *pcVar6;
  undefined8 *puVar7;
  undefined8 in_ra;
  undefined8 in_HW_RESIM31;
  
  puVar7 = (undefined8 *)(long)((int)&stack0x00000000 + -0x30);
  puVar7[4] = &_gp;
  puVar7[3] = unaff_s3;
  pcVar6 = (code *)(long)DAT_ffffffffbfc43c60;
  puVar7[2] = unaff_s2;
  puVar7[1] = unaff_s1;
  *puVar7 = unaff_s0;
  puVar7[5] = in_ra;
  lVar3 = (*pcVar6)();
  setCopReg(2,extraout_at,*(undefined4 *)(param_2 + 0x13));
  uVar1 = *(uint *)(lVar3 + 0x38);
  lVar3 = (long)(DAT_ffffffffbfc436f4 + 0x2448);
  (*(code *)(long)DAT_ffffffffbfc4400c)(lVar3,param_1);
  uVar2 = special2(param_1,lVar3,0x1b,0x32);
  (*(code *)(long)(DAT_ffffffffbfc436f0 + 0x3798))
            ((ulong *)(lVar3 + -0x7ffee7ff6ffffe00),*(ulong *)(lVar3 + -0x7ffee7ff6ffffe00) | 9);
  setCopReg(2,uVar2,*(undefined4 *)(param_2 + 0x39));
  special2(param_1,param_2,0x1b,0x32);
  (*(code *)(long)(DAT_ffffffffbfc436f0 + 0x3798))(param_2 + -0x7ffee7ff6ffffa00,8);
  (*(code *)(long)DAT_ffffffffbfc4400c)(DAT_ffffffffbfc436f4 + 0x2480,param_1,param_1);
  lVar5 = getHWRegister(in_HW_RESIM31);
  uVar4 = (ulong)(uVar1 / 1000) * 1000;
  lVar3 = special2(param_3,(long)(int)(uVar4 >> 0x20) << 0x20 | uVar4 & 0xffffffff,0,3);
  uVar4 = getHWRegister(in_HW_RESIM31);
  if ((ulong)(lVar5 + lVar3) < uVar4) {
    (*(code *)(long)DAT_ffffffffbfc4400c)(DAT_ffffffffbfc436f4 + 0x24a8,param_1);
    uVar2 = 0xffffffffffffffff;
  }
  else {
    setCopReg(2,in_t2,*(undefined4 *)(*(long *)(param_2 + -0x7ffee7ff6ffffcb0) + -0x12));
    uVar2 = 0;
  }
  return uVar2;
}

