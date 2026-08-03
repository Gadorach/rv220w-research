/*
 * Ghidra reconstructed C; not original Cisco source.
 * RV220W boot-chain/U-Boot analysis v1.1.0
 * Entry: ffffffffbfc33cd0
 * Function: FUN_ffffffffbfc33cd0
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

undefined8 FUN_ffffffffbfc33cd0(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  uint uVar1;
  long lVar2;
  ulong uVar3;
  long lVar4;
  undefined8 unaff_s0;
  ulong *puVar5;
  undefined8 unaff_s1;
  long lVar6;
  undefined8 unaff_s2;
  code *pcVar7;
  undefined8 *puVar8;
  undefined8 in_ra;
  undefined8 in_HW_RESIM31;
  
  puVar8 = (undefined8 *)(long)((int)&stack0x00000000 + -0x30);
  puVar8[3] = &_gp;
  puVar8[4] = in_ra;
  puVar8[2] = unaff_s2;
  pcVar7 = (code *)(long)DAT_ffffffffbfc43c60;
  puVar8[1] = unaff_s1;
  *puVar8 = unaff_s0;
  lVar2 = (*pcVar7)();
  uVar1 = *(uint *)(lVar2 + 0x38);
  (*(code *)(long)DAT_ffffffffbfc4400c)(DAT_ffffffffbfc436f4 + 0x24b8,param_1);
  uVar3 = (ulong)(long)(int)((ulong)uVar1 * 0x10624dd3 >> 0x20) >> 6;
  lVar4 = getHWRegister(in_HW_RESIM31);
  lVar2 = uVar3 * 4;
  special2(param_1,lVar2,0x1b,0x32);
  lVar6 = special2(param_3,uVar3 * 1000,0,3);
  puVar5 = (ulong *)(lVar2 + -0x7ffee7ff6ffffcb0);
  do {
    uVar3 = getHWRegister(in_HW_RESIM31);
    if ((ulong)(lVar4 + lVar6) < uVar3) goto LAB_ffffffffbfc33dbc;
  } while ((*puVar5 & 0xc0) != 0xc0);
  (*(code *)(long)DAT_ffffffffbfc4400c)(DAT_ffffffffbfc436f4 + 0x24d8,param_1);
  lVar2 = getHWRegister(in_HW_RESIM31);
  while( true ) {
    uVar3 = getHWRegister(in_HW_RESIM31);
    if ((ulong)(lVar2 + lVar6) < uVar3) break;
    if ((*puVar5 & 0x30) == 0x30) {
      return 0;
    }
  }
LAB_ffffffffbfc33dbc:
  (*(code *)(long)DAT_ffffffffbfc4400c)(DAT_ffffffffbfc436f4 + 0x24a8,param_1);
  return 0xffffffffffffffff;
}

