/*
 * Ghidra reconstructed C; not original Cisco source.
 * RV220W boot-chain/U-Boot analysis v1.1.0
 * Entry: ffffffffbfc17aa4
 * Function: do_mw
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
 * Recovered from U-Boot command table: command='mw', maxargs=4, repeatable=1, usage=''.
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
   
   Recovered from U-Boot command table: command='mw', maxargs=4, repeatable=1, usage=''. */

undefined8 do_mw(long param_1,undefined8 param_2,long param_3,undefined4 *param_4)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  long lVar4;
  int iVar6;
  undefined4 uVar7;
  undefined4 *puVar5;
  int iVar8;
  undefined8 unaff_s0;
  undefined8 unaff_s1;
  long lVar9;
  undefined8 unaff_s2;
  undefined8 unaff_s3;
  undefined8 unaff_s4;
  undefined8 unaff_s5;
  undefined8 *puVar10;
  undefined8 in_ra;
  
  puVar10 = (undefined8 *)(long)((int)&stack0x00000000 + -0x40);
  puVar10[6] = &_gp;
  puVar10[4] = unaff_s4;
  *puVar10 = unaff_s0;
  puVar10[7] = in_ra;
  puVar10[5] = unaff_s5;
  puVar10[3] = unaff_s3;
  puVar10[2] = unaff_s2;
  puVar10[1] = unaff_s1;
  if ((int)param_3 - 3U < 2) {
    lVar3 = (*(code *)(long)DAT_ffffffffbfc43ae8)(*param_4,4);
    if (lVar3 < 1) {
      uVar2 = 1;
    }
    else {
      if (lVar3 == 8) {
        lVar4 = (*(code *)(long)DAT_ffffffffbfc43730)(param_4[1],0,0x10);
        uVar2 = (*(code *)(long)DAT_ffffffffbfc43730)(param_4[2],0,0x10);
        if (param_3 == 4) {
          lVar9 = (*(code *)(long)DAT_ffffffffbfc43730)(param_4[3],0,0x10);
        }
        else {
          lVar9 = 1;
        }
        while( true ) {
          lVar9 = lVar9 + -1;
          if (lVar9 == -1) break;
          (*(code *)(long)(DAT_ffffffffbfc436fc + 0x6350))(lVar4,uVar2);
          lVar4 = lVar4 + 8;
        }
      }
      iVar6 = (*(code *)(long)DAT_ffffffffbfc438b0)(param_4[1],0,0x10);
      iVar1 = *(int *)((long)DAT_ffffffffbfc436f4 + 0x4bf0);
      uVar7 = (*(code *)(long)DAT_ffffffffbfc438b0)(param_4[2],0,0x10);
      if (param_3 == 4) {
        iVar8 = (*(code *)(long)DAT_ffffffffbfc438b0)(param_4[3],0,0x10);
      }
      else {
        iVar8 = 1;
      }
      iVar6 = iVar6 + iVar1;
      while( true ) {
        puVar5 = (undefined4 *)(long)iVar6;
        iVar8 = iVar8 + -1;
        if (iVar8 == -1) break;
        if (lVar3 == 4) {
          *puVar5 = uVar7;
        }
        else if (lVar3 == 2) {
          *(short *)puVar5 = (short)uVar7;
        }
        else {
          *(char *)puVar5 = (char)uVar7;
        }
        iVar6 = iVar6 + (int)lVar3;
      }
      uVar2 = 0;
    }
  }
  else {
    (*(code *)(long)DAT_ffffffffbfc4400c)
              (DAT_ffffffffbfc436f4 + -0x5320,*(undefined4 *)(param_1 + 0x10));
    uVar2 = 1;
  }
  return uVar2;
}

