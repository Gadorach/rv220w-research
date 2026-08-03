/*
 * Ghidra reconstructed C; not original Cisco source.
 * RV220W boot-chain/U-Boot analysis v1.1.0
 * Entry: ffffffffbfc16bac
 * Function: do_namedalloc
 * Subsystem: u-boot-command
 *
 * RV220W BOOT-CHAIN / U-BOOT SEMANTIC ANNOTATION v1.1.0
 * Region: early-boot-and-board-support
 * Subsystem: u-boot-command
 * Evidence: U-Boot command-table entry
 * Confidence: high for identity; medium for exact types
 * Interpretation: U-Boot command handler recovered from the command-table record. Name identity is high confidence; detailed semantics follow the reconstructed C, strings and callees.
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
 * 
 * Recovered from U-Boot command table: command='namedalloc', maxargs=4, repeatable=0, usage=''.
 */

/* RV220W BOOT-CHAIN / U-BOOT SEMANTIC ANNOTATION v1.1.0
   Region: early-boot-and-board-support
   Subsystem: u-boot-command
   Evidence: U-Boot command-table entry
   Confidence: high for identity; medium for exact types
   Interpretation: U-Boot command handler recovered from the command-table record. Name identity is
   high confidence; detailed semantics follow the reconstructed C, strings and callees.
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
   switch writes without readback and recovery safeguards.
   
   Recovered from U-Boot command table: command='namedalloc', maxargs=4, repeatable=0, usage=''. */

undefined8 do_namedalloc(long param_1,undefined8 param_2,long param_3,long param_4)

{
  undefined4 uVar1;
  int iVar2;
  undefined8 uVar3;
  long lVar4;
  long lVar5;
  long lVar6;
  undefined8 unaff_s0;
  undefined8 unaff_s1;
  undefined8 unaff_s2;
  undefined8 unaff_s3;
  code *pcVar7;
  long lVar8;
  undefined8 in_ra;
  
  lVar8 = (long)((int)&stack0x00000000 + -0x50);
  *(undefined1 **)(lVar8 + 0x40) = &_gp;
  *(undefined8 *)(lVar8 + 0x28) = unaff_s1;
  iVar2 = DAT_ffffffffbfc436f4;
  pcVar7 = (code *)(long)DAT_ffffffffbfc43b14;
  *(undefined8 *)(lVar8 + 0x48) = in_ra;
  *(undefined8 *)(lVar8 + 0x30) = unaff_s2;
  *(undefined8 *)(lVar8 + 0x20) = unaff_s0;
  *(undefined8 *)(lVar8 + 0x38) = unaff_s3;
  (*pcVar7)(iVar2 + -0x3d88,0);
  (*(code *)(long)DAT_ffffffffbfc43b14)(DAT_ffffffffbfc436f4 + -0x3d70,0);
  if (param_3 < 3) {
    (*(code *)(long)DAT_ffffffffbfc4400c)
              (DAT_ffffffffbfc436f4 + -0x5320,*(undefined4 *)(param_1 + 0x10));
    uVar3 = 1;
  }
  else {
    uVar1 = *(undefined4 *)(param_4 + 4);
    lVar4 = (*(code *)(long)DAT_ffffffffbfc43730)(*(undefined4 *)(param_4 + 8),0,0x10);
    lVar5 = 0;
    lVar6 = 0;
    if (param_3 == 4) {
      lVar5 = (*(code *)(long)DAT_ffffffffbfc43730)(*(undefined4 *)(param_4 + 0xc),0,0x10);
      lVar6 = lVar5 + lVar4;
    }
    iVar2 = DAT_ffffffffbfc436f4;
    lVar5 = (*(code *)(long)DAT_ffffffffbfc43cec)(lVar4,lVar5,lVar6,0,uVar1,0);
    if (lVar5 < 0) {
      (*(code *)(long)DAT_ffffffffbfc4400c)(DAT_ffffffffbfc436f4 + -0x3d58);
      uVar3 = 1;
    }
    else {
      (*(code *)(long)DAT_ffffffffbfc4400c)(DAT_ffffffffbfc436f4 + -0x3d38,lVar4,lVar5,uVar1);
      (*(code *)(long)DAT_ffffffffbfc439a4)(lVar8,iVar2 + -0x3d00,lVar5);
      (*(code *)(long)DAT_ffffffffbfc43b14)(DAT_ffffffffbfc436f4 + -0x3d88,lVar8);
      (*(code *)(long)DAT_ffffffffbfc439a4)(lVar8,iVar2 + -0x3d00,lVar4);
      (*(code *)(long)DAT_ffffffffbfc43b14)(DAT_ffffffffbfc436f4 + -0x3d70,lVar8);
      uVar3 = 0;
    }
  }
  return uVar3;
}

