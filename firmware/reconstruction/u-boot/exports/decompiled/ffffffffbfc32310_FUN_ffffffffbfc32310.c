/*
 * Ghidra reconstructed C; not original Cisco source.
 * RV220W boot-chain/U-Boot analysis v1.1.0
 * Entry: ffffffffbfc32310
 * Function: FUN_ffffffffbfc32310
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

undefined8 FUN_ffffffffbfc32310(undefined8 param_1,undefined8 param_2)

{
  int iVar2;
  ulong uVar1;
  undefined8 unaff_s0;
  int iVar3;
  undefined8 unaff_s1;
  int iVar4;
  undefined8 unaff_s2;
  long lVar5;
  undefined8 unaff_s3;
  undefined8 unaff_s4;
  undefined8 *puVar6;
  undefined8 in_ra;
  
  puVar6 = (undefined8 *)(long)((int)&stack0x00000000 + -0x40);
  puVar6[5] = &_gp;
  puVar6[4] = unaff_s4;
  puVar6[3] = unaff_s3;
  puVar6[1] = unaff_s1;
  puVar6[6] = in_ra;
  puVar6[2] = unaff_s2;
  iVar4 = 0;
  *puVar6 = unaff_s0;
  do {
    if (iVar4 == 1) {
      lVar5 = 0x10;
    }
    else if (iVar4 < 2) {
      if (iVar4 == 0) {
        lVar5 = 0;
      }
      else {
        lVar5 = -1;
      }
    }
    else if (iVar4 == 2) {
      lVar5 = 0x20;
    }
    else if (iVar4 == 3) {
      lVar5 = 0x24;
    }
    else {
      lVar5 = -1;
    }
    while( true ) {
      if (iVar4 == 1) {
        iVar3 = 0x10;
      }
      else if (iVar4 < 2) {
        if (iVar4 == 0) {
          iVar3 = 0;
        }
        else {
          iVar3 = -1;
        }
      }
      else if (iVar4 == 2) {
        iVar3 = 0x20;
      }
      else if (iVar4 == 3) {
        iVar3 = 0x24;
      }
      else {
        iVar3 = -1;
      }
      iVar2 = (*(code *)(long)DAT_ffffffffbfc43d30)(iVar4);
      uVar1 = (ulong)(lVar5 < iVar3 + iVar2 + -1);
      special2(lVar5,uVar1,3,0x32);
      if (uVar1 == 0) break;
      lVar5 = (long)((int)lVar5 + 1);
      (*(code *)(long)(DAT_ffffffffbfc436f0 + 0x2018))(uVar1 + 0x80014f0000000028,100);
    }
    iVar4 = iVar4 + 1;
  } while (iVar4 != 2);
  iVar4 = 0;
  do {
    (*(code *)(long)DAT_ffffffffbfc437f4)(iVar4,param_1,param_2);
    iVar4 = iVar4 + 1;
  } while (iVar4 != 8);
  iVar4 = DAT_ffffffffbfc436f0 + 0x2018;
  (*(code *)(long)iVar4)(0x80014f0000000328,0);
  (*(code *)(long)iVar4)(0x80014f00000002d8,0x9c42710fffffffff);
  return 0;
}

