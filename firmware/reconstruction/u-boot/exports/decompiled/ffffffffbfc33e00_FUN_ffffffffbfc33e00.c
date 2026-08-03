/*
 * Ghidra reconstructed C; not original Cisco source.
 * RV220W boot-chain/U-Boot analysis v1.1.0
 * Entry: ffffffffbfc33e00
 * Function: FUN_ffffffffbfc33e00
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

undefined8 FUN_ffffffffbfc33e00(undefined8 param_1)

{
  long lVar1;
  ulong uVar2;
  undefined8 uVar3;
  undefined8 in_t0;
  undefined8 unaff_s0;
  undefined8 unaff_s1;
  undefined8 unaff_s2;
  long lVar4;
  long unaff_s3;
  undefined8 unaff_s4;
  undefined8 unaff_s5;
  int iVar5;
  undefined8 unaff_s6;
  int iVar6;
  code *pcVar7;
  undefined8 *puVar8;
  undefined8 in_ra;
  undefined8 in_HW_RESIM31;
  
  puVar8 = (undefined8 *)(long)((int)&stack0x00000000 + -0x50);
  puVar8[7] = &_gp;
  puVar8[4] = unaff_s4;
  pcVar7 = (code *)(long)DAT_ffffffffbfc43c60;
  puVar8[2] = unaff_s2;
  puVar8[8] = in_ra;
  puVar8[6] = unaff_s6;
  puVar8[5] = unaff_s5;
  puVar8[3] = unaff_s3;
  puVar8[1] = unaff_s1;
  *puVar8 = unaff_s0;
  lVar1 = (*pcVar7)();
  uVar2 = (ulong)(long)(int)((ulong)*(uint *)(lVar1 + 0x38) * 0x10624dd3 >> 0x20) >> 6;
  getHWRegister(in_HW_RESIM31);
  special2(param_1,unaff_s3,0x1b,0x32);
  iVar6 = DAT_ffffffffbfc436f0 + 0x3798;
  (*(code *)(long)iVar6)(unaff_s3 + -0x7ffee7ff6ffffcb8,0x83f);
  lVar1 = uVar2 * 1000;
  iVar5 = DAT_ffffffffbfc436f0 + 0x37c8;
  (*(code *)(long)iVar5)(lVar1);
  (*(code *)(long)iVar6)
            ((ulong *)(unaff_s3 + -0x7ffee7ff6ffffca0),
             *(ulong *)(unaff_s3 + -0x7ffee7ff6ffffca0) | 0x100);
  (*(code *)(long)DAT_ffffffffbfc4400c)(DAT_ffffffffbfc436f4 + 0x24f8,param_1);
  (*(code *)(long)iVar5)(lVar1);
  lVar1 = getHWRegister(in_HW_RESIM31);
  lVar4 = special2(uVar2,600000,0,3);
  uVar2 = getHWRegister(in_HW_RESIM31);
  if ((ulong)(lVar1 + lVar4) < uVar2) {
    (*(code *)(long)DAT_ffffffffbfc4400c)(DAT_ffffffffbfc436f4 + 0x24a8,param_1);
    uVar3 = 0xffffffffffffffff;
  }
  else {
    setCopReg(2,in_t0,*(undefined4 *)(*(long *)(unaff_s3 + -0x7ffee7ff6ffffcb0) + -0x12));
    uVar3 = 0;
  }
  return uVar3;
}

