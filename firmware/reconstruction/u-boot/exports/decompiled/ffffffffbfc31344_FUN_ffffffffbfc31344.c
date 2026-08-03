/*
 * Ghidra reconstructed C; not original Cisco source.
 * RV220W boot-chain/U-Boot analysis v1.1.0
 * Entry: ffffffffbfc31344
 * Function: FUN_ffffffffbfc31344
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

undefined8 FUN_ffffffffbfc31344(undefined8 param_1,undefined8 param_2)

{
  undefined4 uVar1;
  int iVar2;
  ulong *puVar3;
  long lVar4;
  undefined8 uVar5;
  long *plVar6;
  undefined8 unaff_s0;
  ulong uVar7;
  long lVar8;
  undefined8 unaff_s1;
  long lVar9;
  undefined8 unaff_s2;
  undefined8 unaff_s3;
  undefined8 *puVar10;
  undefined8 in_ra;
  undefined8 in_HW_RESIM31;
  
  puVar10 = (undefined8 *)(long)((int)&stack0x00000000 + -0x30);
  puVar10[4] = &_gp;
  puVar10[2] = unaff_s2;
  iVar2 = DAT_ffffffffbfc436f0;
  puVar10[3] = unaff_s3;
  puVar10[1] = unaff_s1;
  puVar10[5] = in_ra;
  *puVar10 = unaff_s0;
  puVar3 = (ulong *)(*(code *)(long)(iVar2 + 0x1268))(param_2,param_1);
  uVar7 = *puVar3;
  lVar4 = (*(code *)(long)DAT_ffffffffbfc43c60)();
  if (*(short *)(lVar4 + 0x40) != 1) {
    (*(code *)(long)(DAT_ffffffffbfc436f0 + 0x12ec))(puVar3,uVar7 | 0x8000);
    (*(code *)(long)(DAT_ffffffffbfc436f0 + 0x131c))(100);
    uVar7 = *puVar3;
    uVar1 = getCopReg(2,0xf);
    *(undefined4 *)(uVar7 - 5) = uVar1;
  }
  (*(code *)(long)(DAT_ffffffffbfc436f0 + 0x12ec))(puVar3,uVar7 & 0xffffffffffffe7ff | 0x1200);
  lVar4 = (*(code *)(long)DAT_ffffffffbfc43c60)();
  uVar5 = 0;
  if (*(short *)(lVar4 + 0x40) != 1) {
    lVar9 = getHWRegister(in_HW_RESIM31);
    lVar8 = getHWRegister(in_HW_RESIM31);
    lVar4 = (*(code *)(long)DAT_ffffffffbfc43c60)();
    if ((ulong)(long)(int)((ulong)*(uint *)(lVar4 + 0x38) * 0x51eb851f >> 0x20) >> 5 <
        (ulong)(lVar8 - lVar9)) {
      uVar5 = 0xffffffffffffffff;
    }
    else {
      (*(code *)(long)(DAT_ffffffffbfc436f0 + 0x131c))(100);
      plVar6 = (long *)(*(code *)(long)(DAT_ffffffffbfc436f0 + 0x1294))(param_2,param_1);
      setCopReg(2,param_1,*(undefined4 *)(*plVar6 + -0x1a));
      uVar5 = 0;
    }
  }
  return uVar5;
}

