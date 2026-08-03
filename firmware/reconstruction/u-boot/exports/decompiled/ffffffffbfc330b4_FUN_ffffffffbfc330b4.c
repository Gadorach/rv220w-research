/*
 * Ghidra reconstructed C; not original Cisco source.
 * RV220W boot-chain/U-Boot analysis v1.1.0
 * Entry: ffffffffbfc330b4
 * Function: FUN_ffffffffbfc330b4
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

ulong FUN_ffffffffbfc330b4(undefined8 param_1,ulong param_2)

{
  undefined4 uVar1;
  long lVar2;
  uint uVar4;
  ulong uVar3;
  int *piVar5;
  undefined8 in_t2;
  undefined8 in_t7;
  undefined8 unaff_s0;
  undefined8 unaff_s1;
  undefined8 unaff_s2;
  undefined8 unaff_s3;
  int iVar7;
  ulong uVar6;
  undefined8 *puVar8;
  undefined8 in_ra;
  
  puVar8 = (undefined8 *)(long)((int)&stack0x00000000 + -0x30);
  puVar8[4] = &_gp;
  puVar8[2] = unaff_s2;
  iVar7 = DAT_ffffffffbfc436f8;
  puVar8[1] = unaff_s1;
  *puVar8 = unaff_s0;
  iVar7 = *(int *)(long)((int)param_1 * 4 + iVar7 + 0x1c88);
  puVar8[5] = in_ra;
  puVar8[3] = unaff_s3;
  if ((iVar7 == 0) || (9 < (long)param_2)) {
    return 0;
  }
  (*(code *)(long)(DAT_ffffffffbfc436f0 + 0x2d4c))(param_1,0x680,(param_2 & 0x1f) << 8 | 0x120011);
  iVar7 = DAT_ffffffffbfc436f0 + 0x2e98;
  lVar2 = (*(code *)(long)iVar7)(param_1,0x680);
  uVar1 = getCopReg(2,0x14);
  *(undefined4 *)(lVar2 + -6) = uVar1;
  uVar4 = (*(code *)(long)iVar7)(param_1,0x681);
  uVar3 = (ulong)(int)(uVar4 >> 0x10);
  setCopReg(2,in_t2,*(undefined4 *)(uVar3 + 2));
  uVar6 = uVar3 & 0xe400;
  iVar7 = (int)param_2;
  piVar5 = (int *)(long)(iVar7 * 4 + DAT_ffffffffbfc436f4 + 0x6250);
  if (uVar6 == (long)*piVar5) {
    if ((uVar3 & 0x400) != 0) {
      setCopReg(2,in_t7,*(undefined4 *)(uVar6 + 3));
      goto LAB_ffffffffbfc33208;
    }
  }
  else {
    *piVar5 = (int)uVar6;
    if ((uVar3 & 0x400) != 0) {
      setCopReg(2,in_t7,*(undefined4 *)(uVar6 + 8));
      (*(code *)(long)(DAT_ffffffffbfc436f0 + 0x2d4c))(param_1,iVar7 << 7 | 0x10,3);
LAB_ffffffffbfc33208:
      uVar6 = 5;
      goto LAB_ffffffffbfc33220;
    }
    (*(code *)(long)(DAT_ffffffffbfc436f0 + 0x2d4c))(param_1,iVar7 << 7 | 0x10,3);
  }
  uVar6 = 4;
LAB_ffffffffbfc33220:
  return uVar6 | (uVar3 >> 0xd & 1) << 3;
}

