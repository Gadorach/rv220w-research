/*
 * Ghidra reconstructed C; not original Cisco source.
 * RV220W boot-chain/U-Boot analysis v1.1.0
 * Entry: ffffffffbfc31da0
 * Function: FUN_ffffffffbfc31da0
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

undefined8 FUN_ffffffffbfc31da0(undefined8 param_1)

{
  long lVar1;
  long extraout_v1;
  undefined8 unaff_s0;
  int iVar2;
  int iVar3;
  undefined8 unaff_s1;
  undefined8 unaff_s2;
  undefined8 unaff_s3;
  code *pcVar4;
  undefined8 *puVar5;
  undefined8 in_ra;
  undefined1 auVar6 [16];
  
  puVar5 = (undefined8 *)(long)((int)&stack0x00000000 + -0x30);
  puVar5[4] = &_gp;
  puVar5[3] = unaff_s3;
  puVar5[2] = unaff_s2;
  pcVar4 = (code *)(long)DAT_ffffffffbfc43d30;
  puVar5[1] = unaff_s1;
  *puVar5 = unaff_s0;
  puVar5[5] = in_ra;
  auVar6 = (*pcVar4)();
  lVar1 = auVar6._8_8_;
  iVar2 = (int)param_1 * 0x10;
  for (iVar3 = iVar2; special2((long)iVar3,lVar1,3,0x32), (long)iVar3 < (long)(iVar2 + auVar6._4_4_)
      ; iVar3 = iVar3 + 1) {
    (*(code *)(long)(DAT_ffffffffbfc436f0 + 0x1b90))
              ((ulong *)(lVar1 + -0x7ffee7ff5ffffe00),
               *(ulong *)(lVar1 + -0x7ffee7ff5ffffe00) | 0x1000);
    lVar1 = extraout_v1;
  }
  lVar1 = (*(code *)(long)DAT_ffffffffbfc43c60)();
  if (*(short *)(lVar1 + 0x40) != 1) {
    (*(code *)(long)DAT_ffffffffbfc43a70)(param_1,3,10,auVar6._0_8_);
    lVar1 = (*(code *)(long)DAT_ffffffffbfc43aa8)(param_1);
    if (lVar1 != 0) {
      (*(code *)(long)DAT_ffffffffbfc43d54)(param_1);
    }
  }
  return 0;
}

