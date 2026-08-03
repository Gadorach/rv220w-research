/*
 * Ghidra reconstructed C; not original Cisco source.
 * RV220W boot-chain/U-Boot analysis v1.1.0
 * Entry: ffffffffbfc34860
 * Function: FUN_ffffffffbfc34860
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

uint FUN_ffffffffbfc34860(uint param_1)

{
  ushort uVar1;
  long lVar2;
  ushort uVar3;
  undefined8 unaff_s0;
  code *pcVar4;
  undefined8 *puVar5;
  undefined8 in_ra;
  
  puVar5 = (undefined8 *)(long)((int)&stack0x00000000 + -0x20);
  puVar5[1] = &_gp;
  *puVar5 = unaff_s0;
  pcVar4 = (code *)(long)DAT_ffffffffbfc43c60;
  puVar5[2] = in_ra;
  lVar2 = (*pcVar4)();
  uVar1 = *(ushort *)(lVar2 + 0x40);
  if (uVar1 == 0xe) {
LAB_ffffffffbfc3497c:
    if (param_1 == 0) {
      return 4;
    }
    if (param_1 != 1) {
      return 0xffffffff;
    }
    return 9;
  }
  if (uVar1 < 0xf) {
    if (uVar1 == 5) {
      if (param_1 < 4) {
        return param_1;
      }
      if (3 < param_1 - 0x10) {
        return 0xffffffff;
      }
      return param_1 - 0xc;
    }
    if (5 < uVar1) {
      if (uVar1 == 8) {
        return 0xffffffff;
      }
      if (uVar1 < 9) {
        if (uVar1 == 6) goto LAB_ffffffffbfc34968;
      }
      else if (uVar1 < 0xd) goto LAB_ffffffffbfc3497c;
      goto LAB_ffffffffbfc34a04;
    }
    if (uVar1 == 2) goto LAB_ffffffffbfc34968;
    uVar3 = 1;
    if (uVar1 == 3) goto LAB_ffffffffbfc3497c;
  }
  else {
    if (uVar1 == 0x13) {
      if (3 < param_1) {
        return 0xffffffff;
      }
      return param_1 + 2;
    }
    if (uVar1 < 0x14) {
      if (0x10 < uVar1) {
        if (param_1 < 4) {
          return param_1 + 1;
        }
        if (3 < param_1 - 0x10) {
          return 0xffffffff;
        }
        return param_1 - 0xb;
      }
LAB_ffffffffbfc34968:
      if (3 < param_1 - 0x10) {
        return 0xffffffff;
      }
      return param_1 - 0x10;
    }
    if (uVar1 == 0x2713) {
      if (param_1 == 2) {
        return 4;
      }
      return 0xffffffff;
    }
    if (0x2713 < uVar1) {
      if (uVar1 - 0x2715 < 3) {
        return 0xffffffff;
      }
      goto LAB_ffffffffbfc34a04;
    }
    uVar3 = 0x14;
  }
  if (uVar1 == uVar3) {
    return 0xffffffff;
  }
LAB_ffffffffbfc34a04:
  lVar2 = (*(code *)(long)DAT_ffffffffbfc43c60)();
  (*(code *)(long)DAT_ffffffffbfc4400c)(DAT_ffffffffbfc436f4 + 0x2570,*(undefined2 *)(lVar2 + 0x40))
  ;
  return 0xffffffff;
}

