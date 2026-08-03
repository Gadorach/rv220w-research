/*
 * Ghidra reconstructed C; not original Cisco source.
 * RV220W boot-chain/U-Boot analysis v1.1.0
 * Entry: ffffffffbfc2b1c4
 * Function: FUN_ffffffffbfc2b1c4
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

void FUN_ffffffffbfc2b1c4(undefined8 param_1,undefined8 param_2,long param_3)

{
  int iVar1;
  int iVar2;
  long lVar3;
  int iVar4;
  undefined8 unaff_s0;
  undefined8 unaff_s1;
  undefined8 unaff_s2;
  undefined8 uVar5;
  undefined8 unaff_s3;
  code *pcVar6;
  long lVar7;
  undefined8 in_ra;
  
  lVar7 = (long)((int)&stack0x00000000 + -0x70);
  *(undefined1 **)(lVar7 + 0x60) = &_gp;
  *(undefined8 *)(lVar7 + 0x50) = unaff_s2;
  uVar5 = special2(param_2,param_3,0,3);
  lVar3 = (long)DAT_ffffffffbfc436f4;
  *(undefined8 *)(lVar7 + 0x48) = unaff_s1;
  iVar2 = *(int *)(lVar3 + 0x6078);
  *(undefined8 *)(lVar7 + 0x40) = unaff_s0;
  iVar1 = DAT_ffffffffbfc436f4;
  pcVar6 = (code *)(long)DAT_ffffffffbfc439a4;
  iVar4 = DAT_ffffffffbfc436f0 + 0x7c78;
  *(undefined8 *)(lVar7 + 0x68) = in_ra;
  *(undefined8 *)(lVar7 + 0x58) = unaff_s3;
  *(int *)(lVar3 + 0x6078) = iVar2 + 1;
  (*pcVar6)(lVar7,iVar1 + 0x1a88,iVar4);
  lVar3 = (*(code *)(long)DAT_ffffffffbfc43cec)(uVar5,0,0x40000000,0x80,lVar7,1);
  if (lVar3 < 0) {
    (*(code *)(long)DAT_ffffffffbfc4400c)(DAT_ffffffffbfc436f4 + 0x1a98,uVar5,param_1);
  }
  else {
    uVar5 = special2(param_3 + -1,param_2,0,3);
    iVar2 = (int)lVar3 + (int)uVar5;
    while( true ) {
      param_3 = param_3 + -1;
      iVar2 = iVar2 - (int)param_2;
      if (param_3 == -1) break;
      (*(code *)(long)(DAT_ffffffffbfc436f0 + -0x5704))(iVar2 + (int)param_2,param_1,0);
    }
  }
  return;
}

