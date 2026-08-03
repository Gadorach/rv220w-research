/*
 * Ghidra reconstructed C; not original Cisco source.
 * RV220W boot-chain/U-Boot analysis v1.1.0
 * Entry: ffffffffbfc35ba0
 * Function: FUN_ffffffffbfc35ba0
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

undefined8 FUN_ffffffffbfc35ba0(ulong param_1,ulong param_2,undefined8 param_3)

{
  ulong uVar1;
  long lVar2;
  undefined8 unaff_s0;
  undefined8 unaff_s1;
  ulong uVar3;
  undefined8 unaff_s2;
  undefined8 unaff_s3;
  int iVar4;
  code *pcVar5;
  undefined8 *puVar6;
  undefined8 in_ra;
  ulong uVar7;
  
  puVar6 = (undefined8 *)(long)((int)&stack0x00000000 + -0x30);
  puVar6[4] = &_gp;
  puVar6[5] = in_ra;
  puVar6[3] = unaff_s3;
  pcVar5 = (code *)(long)DAT_ffffffffbfc43c60;
  puVar6[2] = unaff_s2;
  puVar6[1] = unaff_s1;
  *puVar6 = unaff_s0;
  lVar2 = (*pcVar5)();
  uVar7 = ((ulong)*(uint *)(lVar2 + 0x38) << 4) / param_2;
  if (param_2 == 0) {
    trap(7);
  }
  iVar4 = DAT_ffffffffbfc436f0 + 0x5288;
  uVar3 = special2(uVar7,param_3,0,3);
  uVar1 = uVar7 * 0xc0;
  special2(uVar1,uVar1,8,0x3a);
  special2(uVar3,uVar3,8,0x3a);
  (*(code *)(long)iVar4)
            (0x8001180050001020,
             param_1 & 0x3f | (uVar1 & 0xffffff) << 8 | (uVar7 * 0x40 & 0x7ffff) << 0x20);
  (*(code *)(long)iVar4)(0x8001180050001028,param_1 & 0x3f | (uVar3 & 0xffffff) << 8);
  return 0;
}

