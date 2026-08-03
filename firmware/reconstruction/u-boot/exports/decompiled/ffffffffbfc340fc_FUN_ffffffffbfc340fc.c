/*
 * Ghidra reconstructed C; not original Cisco source.
 * RV220W boot-chain/U-Boot analysis v1.1.0
 * Entry: ffffffffbfc340fc
 * Function: FUN_ffffffffbfc340fc
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

undefined8 FUN_ffffffffbfc340fc(undefined8 param_1,long param_2)

{
  undefined8 uVar1;
  undefined8 in_at;
  long in_v0;
  long lVar2;
  undefined8 unaff_s0;
  undefined8 unaff_s1;
  undefined8 unaff_s2;
  code *pcVar3;
  undefined8 *puVar4;
  undefined8 in_ra;
  
  puVar4 = (undefined8 *)(long)((int)&stack0x00000000 + -0x30);
  puVar4[3] = &_gp;
  puVar4[1] = unaff_s1;
  *puVar4 = unaff_s0;
  puVar4[4] = in_ra;
  uVar1 = special2(param_1,in_v0,0x1b,0x32);
  setCopReg(2,in_at,*(undefined4 *)(param_2 + 0x12));
  puVar4[2] = unaff_s2;
  (*(code *)(long)(DAT_ffffffffbfc436f0 + 0x3798))
            ((ulong *)(in_v0 + -0x7ffee7ff6ffffe00),*(ulong *)(in_v0 + -0x7ffee7ff6ffffe00) | 1);
  lVar2 = (*(code *)(long)DAT_ffffffffbfc4400c)(DAT_ffffffffbfc436f4 + 0x2518,param_1);
  setCopReg(2,uVar1,*(undefined4 *)(param_2 + 0x12));
  special2(param_1,lVar2,0x1b,0x32);
  (*(code *)(long)(DAT_ffffffffbfc436f0 + 0x3798))
            ((ulong *)(lVar2 + -0x7ffee7ff6ffffa00),*(ulong *)(lVar2 + -0x7ffee7ff6ffffa00) | 1);
  (*(code *)(long)DAT_ffffffffbfc4400c)(DAT_ffffffffbfc436f4 + 0x2530,param_1);
  special2(param_1,param_2,0x1b,0x32);
  pcVar3 = (code *)(long)(DAT_ffffffffbfc436f0 + 0x3798);
  (*pcVar3)(param_2 + -0x7ffee7fff7ffffd8,0x40);
  (*pcVar3)(param_2 + -0x7ffee7fff7ffffd0,0xfffc);
  (*pcVar3)(param_2 + -0x7ffee7fff7ffffc8,0xfffc);
  return 0;
}

