/*
 * Ghidra reconstructed C; not original Cisco source.
 * RV220W boot-chain/U-Boot analysis v1.1.0
 * Entry: ffffffffbfc1bc74
 * Function: FUN_ffffffffbfc1bc74
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

ulong FUN_ffffffffbfc1bc74(long *param_1,ulong param_2,undefined1 param_3,ulong param_4)

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
  undefined8 unaff_s5;
  int iVar8;
  undefined8 unaff_s6;
  undefined8 *puVar9;
  undefined8 in_ra;
  
  puVar9 = (undefined8 *)(long)((int)&stack0x00000000 + -0x50);
  puVar9[7] = &_gp;
  puVar9[6] = unaff_s6;
  puVar9[5] = unaff_s5;
  puVar9[4] = unaff_s4;
  puVar9[2] = unaff_s2;
  puVar9[1] = unaff_s1;
  *puVar9 = unaff_s0;
  puVar9[8] = in_ra;
  puVar9[3] = unaff_s3;
  iVar8 = 0;
  uVar6 = param_4;
  do {
    iVar8 = iVar8 + 1;
    if (uVar6 == 0) {
      return param_4;
    }
    uVar3 = param_1[2];
    lVar1 = (long)(int)*(uint *)(param_1 + 3);
    uVar7 = 1 << (*(uint *)(param_1 + 3) & 0x1f);
    if (param_2 < uVar3) {
LAB_ffffffffbfc1bd30:
      special2((long)(int)uVar7,lVar1,1,0x32);
      uVar4 = param_1[2] + lVar1;
      uVar3 = param_1[2] + (ulong)uVar7;
      if (uVar3 <= param_2) {
        uVar2 = uVar4 - param_2;
        lVar1 = param_2 - uVar3;
        uVar3 = uVar6 & 0xffffffff;
        if (uVar2 < (uVar6 & 0xffffffff)) {
          uVar3 = uVar2;
        }
        if (param_2 < uVar4) {
          uVar6 = (ulong)((int)uVar6 - (int)uVar3);
          param_2 = param_2 + (uVar3 & 0xffffffff);
          (*(code *)(long)DAT_ffffffffbfc43bf8)(lVar1 + param_1[1],param_3);
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
      if (uVar3 + uVar7 <= param_2) goto LAB_ffffffffbfc1bd30;
      uVar6 = (ulong)((int)uVar6 - (int)uVar4);
      param_2 = param_2 + (uVar4 & 0xffffffff);
      (*(code *)(long)DAT_ffffffffbfc43bf8)(lVar5 + *param_1,param_3,uVar4 & 0xffffffff);
      lVar1 = 0x20;
      if (uVar6 != 0) goto LAB_ffffffffbfc1bd30;
    }
    param_1 = (long *)(long)((int)param_1 + 0x28);
    if (iVar8 == 0x20) {
      if (uVar6 != 0) {
        param_4 = 0;
        (*(code *)(long)DAT_ffffffffbfc4400c)(DAT_ffffffffbfc436f4 + -0xe68);
      }
      return param_4;
    }
  } while( true );
}

