/*
 * Ghidra reconstructed C; not original Cisco source.
 * RV220W boot-chain/U-Boot analysis v1.1.0
 * Entry: ffffffffbfc03758
 * Function: FUN_ffffffffbfc03758
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

ulong FUN_ffffffffbfc03758(long *param_1,ulong param_2,long param_3,ulong param_4)

{
  long lVar1;
  ulong uVar2;
  ulong uVar3;
  ulong uVar4;
  long lVar5;
  undefined8 unaff_s0;
  undefined8 unaff_s1;
  ulong uVar6;
  undefined8 unaff_s2;
  undefined8 unaff_s3;
  uint uVar7;
  undefined8 unaff_s4;
  long lVar8;
  undefined8 unaff_s5;
  undefined8 unaff_s6;
  int iVar9;
  undefined8 *puVar10;
  undefined8 in_ra;
  
  puVar10 = (undefined8 *)(long)((int)&stack0x00000000 + -0x50);
  puVar10[7] = &_gp;
  puVar10[6] = unaff_s6;
  puVar10[5] = unaff_s5;
  puVar10[4] = unaff_s4;
  puVar10[2] = unaff_s2;
  puVar10[1] = unaff_s1;
  *puVar10 = unaff_s0;
  puVar10[8] = in_ra;
  puVar10[3] = unaff_s3;
  iVar9 = 0;
  uVar6 = param_4;
  do {
    iVar9 = iVar9 + 1;
    if (uVar6 == 0) {
      return param_4;
    }
    uVar3 = param_1[2];
    lVar1 = (long)(int)*(uint *)(param_1 + 3);
    uVar7 = 1 << (*(uint *)(param_1 + 3) & 0x1f);
    lVar8 = param_3;
    if (param_2 < uVar3) {
LAB_ffffffffbfc03818:
      special2((long)(int)uVar7,lVar1,1,0x32);
      uVar4 = param_1[2] + lVar1;
      uVar3 = param_1[2] + (ulong)uVar7;
      param_3 = lVar8;
      if (uVar3 <= param_2) {
        uVar2 = uVar4 - param_2;
        lVar1 = param_2 - uVar3;
        uVar3 = uVar6 & 0xffffffff;
        if (uVar2 < (uVar6 & 0xffffffff)) {
          uVar3 = uVar2;
        }
        if (param_2 < uVar4) {
          uVar6 = (ulong)((int)uVar6 - (int)uVar3);
          param_3 = lVar8 + (uVar3 & 0xffffffff);
          param_2 = param_2 + (uVar3 & 0xffffffff);
          (*(code *)(long)DAT_ffffffffbfc438f0)(lVar1 + param_1[1],lVar8);
        }
      }
    }
    else {
      lVar5 = param_2 - uVar3;
      uVar2 = (uVar3 + uVar7) - param_2;
      uVar4 = uVar6 & 0xffffffff;
      if (uVar2 < (uVar6 & 0xffffffff)) {
        uVar4 = uVar2;
      }
      lVar1 = 0;
      if (uVar3 + uVar7 <= param_2) goto LAB_ffffffffbfc03818;
      uVar3 = uVar4 & 0xffffffff;
      uVar6 = (ulong)((int)uVar6 - (int)uVar4);
      lVar8 = param_3 + uVar3;
      param_2 = param_2 + uVar3;
      (*(code *)(long)DAT_ffffffffbfc438f0)(lVar5 + *param_1,param_3,uVar3);
      lVar1 = 0x20;
      param_3 = lVar8;
      if (uVar6 != 0) goto LAB_ffffffffbfc03818;
    }
    param_1 = (long *)(long)((int)param_1 + 0x28);
    if (iVar9 == 0x20) {
      if (uVar6 != 0) {
        param_4 = 0xffffffffffffffff;
        (*(code *)(long)DAT_ffffffffbfc4400c)(DAT_ffffffffbfc436f0 + 0x7c40,uVar6);
      }
      return param_4;
    }
  } while( true );
}

