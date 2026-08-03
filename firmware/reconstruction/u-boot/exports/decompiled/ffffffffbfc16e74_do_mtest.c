/*
 * Ghidra reconstructed C; not original Cisco source.
 * RV220W boot-chain/U-Boot analysis v1.1.0
 * Entry: ffffffffbfc16e74
 * Function: do_mtest
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
 * Recovered from U-Boot command table: command='mtest', maxargs=4, repeatable=1, usage=''.
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
   
   Recovered from U-Boot command table: command='mtest', maxargs=4, repeatable=1, usage=''. */

undefined8 do_mtest(undefined8 param_1,undefined8 param_2,long param_3,long param_4)

{
  bool bVar1;
  uint uVar3;
  long lVar2;
  undefined8 unaff_s0;
  uint *puVar4;
  undefined8 unaff_s1;
  uint uVar5;
  undefined8 unaff_s2;
  undefined8 unaff_s3;
  int iVar6;
  undefined8 unaff_s4;
  int iVar7;
  undefined8 unaff_s5;
  uint *puVar8;
  undefined8 unaff_s6;
  uint *puVar9;
  undefined8 *puVar10;
  undefined8 in_ra;
  
  puVar10 = (undefined8 *)(long)((int)&stack0x00000000 + -0x50);
  puVar10[7] = &_gp;
  puVar10[1] = unaff_s1;
  *puVar10 = unaff_s0;
  puVar10[8] = in_ra;
  puVar10[6] = unaff_s6;
  puVar10[5] = unaff_s5;
  puVar10[4] = unaff_s4;
  puVar10[3] = unaff_s3;
  puVar10[2] = unaff_s2;
  if (param_3 < 2) {
    puVar9 = (uint *)&DAT_ffffffff80100000;
  }
  else {
    puVar9 = (uint *)(*(code *)(long)DAT_ffffffffbfc438b0)(*(undefined4 *)(param_4 + 4),0,0x10);
  }
  if (param_3 < 3) {
    puVar8 = (uint *)0xffffffff80ffffff;
  }
  else {
    puVar8 = (uint *)(*(code *)(long)DAT_ffffffffbfc438b0)(*(undefined4 *)(param_4 + 8),0,0x10);
  }
  uVar3 = 0;
  if (3 < param_3) {
    uVar3 = (*(code *)(long)DAT_ffffffffbfc438b0)(*(undefined4 *)(param_4 + 0xc),0,0x10);
  }
  iVar7 = 1;
  do {
    lVar2 = (*(code *)(long)DAT_ffffffffbfc43b08)();
    if (lVar2 != 0) {
      (*(code *)(long)DAT_ffffffffbfc439f0)(10);
      return 1;
    }
    (*(code *)(long)DAT_ffffffffbfc4400c)
              (DAT_ffffffffbfc436f4 + -0x3cd0,uVar3,DAT_ffffffffbfc436f4 + -0x3ca8);
    uVar5 = uVar3;
    for (puVar4 = puVar9; puVar4 < puVar8; puVar4 = (uint *)(long)((int)puVar4 + 4)) {
      *puVar4 = uVar5;
      uVar5 = uVar5 + iVar7;
    }
    iVar6 = 0x32;
    (*(code *)(long)DAT_ffffffffbfc43e38)(DAT_ffffffffbfc436f4 + -0x3fe0);
    puVar4 = puVar9;
    uVar5 = uVar3;
    while( true ) {
      if (puVar8 <= puVar4) break;
      if (*puVar4 != uVar5) {
        (*(code *)(long)DAT_ffffffffbfc4400c)(DAT_ffffffffbfc436f4 + -0x3fd0,puVar4,*puVar4,uVar5);
        bVar1 = iVar6 < 1;
        iVar6 = iVar6 + -1;
        if (bVar1) {
          (*(code *)(long)DAT_ffffffffbfc4400c)(DAT_ffffffffbfc436f4 + -0x3f98);
          (*(code *)(long)DAT_ffffffffbfc437f8)();
          return 1;
        }
      }
      uVar5 = uVar5 + iVar7;
      puVar4 = (uint *)(long)((int)puVar4 + 4);
    }
    if ((int)uVar3 < 0) {
      uVar3 = -uVar3;
    }
    else {
      uVar3 = ~uVar3;
    }
    iVar7 = -iVar7;
    (*(code *)(long)DAT_ffffffffbfc437f8)();
  } while( true );
}

