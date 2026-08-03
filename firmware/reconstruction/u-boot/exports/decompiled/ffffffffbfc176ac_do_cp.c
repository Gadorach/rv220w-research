/*
 * Ghidra reconstructed C; not original Cisco source.
 * RV220W boot-chain/U-Boot analysis v1.1.0
 * Entry: ffffffffbfc176ac
 * Function: do_cp
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
 * Recovered from U-Boot command table: command='cp', maxargs=4, repeatable=1, usage=''.
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
   
   Recovered from U-Boot command table: command='cp', maxargs=4, repeatable=1, usage=''. */

undefined8 do_cp(long param_1,undefined8 param_2,long param_3,undefined4 *param_4)

{
  long lVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  undefined8 unaff_s0;
  long lVar6;
  undefined4 *puVar7;
  undefined8 unaff_s1;
  undefined4 *puVar8;
  undefined8 unaff_s2;
  undefined8 unaff_s3;
  int iVar9;
  undefined8 unaff_s4;
  undefined8 unaff_s5;
  undefined8 unaff_s6;
  undefined8 *puVar10;
  undefined8 in_ra;
  
  puVar10 = (undefined8 *)(long)((int)&stack0x00000000 + -0x50);
  puVar10[7] = &_gp;
  puVar10[1] = unaff_s1;
  puVar10[8] = in_ra;
  puVar10[6] = unaff_s6;
  puVar10[5] = unaff_s5;
  puVar10[4] = unaff_s4;
  puVar10[3] = unaff_s3;
  puVar10[2] = unaff_s2;
  *puVar10 = unaff_s0;
  if (param_3 != 4) {
    (*(code *)(long)DAT_ffffffffbfc4400c)
              (DAT_ffffffffbfc436f4 + -0x5320,*(undefined4 *)(param_1 + 0x10));
    return 1;
  }
  lVar1 = (*(code *)(long)DAT_ffffffffbfc43ae8)(*param_4,4);
  if (-1 < lVar1) {
    lVar6 = (long)DAT_ffffffffbfc436f4;
    iVar2 = (*(code *)(long)DAT_ffffffffbfc438b0)(param_4[1],0,0x10);
    iVar9 = *(int *)(lVar6 + 0x4bf0);
    iVar3 = (*(code *)(long)DAT_ffffffffbfc438b0)(param_4[2],0,0x10);
    iVar5 = *(int *)(lVar6 + 0x4bf0);
    uVar4 = (*(code *)(long)DAT_ffffffffbfc438b0)(param_4[3],0,0x10);
    if (uVar4 == 0) {
      iVar5 = DAT_ffffffffbfc436f4 + -0x3c78;
      iVar9 = DAT_ffffffffbfc43e38;
    }
    else {
      puVar7 = (undefined4 *)(long)(iVar3 + iVar5);
      puVar8 = (undefined4 *)(long)(iVar2 + iVar9);
      lVar6 = (*(code *)(long)DAT_ffffffffbfc438a8)(puVar7);
      iVar9 = (int)lVar1;
      if (lVar6 == 0) {
        while (uVar4 = uVar4 - 1, uVar4 != 0xffffffff) {
          if (lVar1 == 4) {
            *puVar7 = *puVar8;
          }
          else if (lVar1 == 2) {
            *(undefined2 *)puVar7 = *(undefined2 *)puVar8;
          }
          else {
            *(undefined1 *)puVar7 = *(undefined1 *)puVar8;
          }
          puVar8 = (undefined4 *)(long)((int)puVar8 + iVar9);
          puVar7 = (undefined4 *)(long)((int)puVar7 + iVar9);
          if ((uVar4 & 0x7ffff) == 0) {
            (*(code *)(long)DAT_ffffffffbfc43f38)(2);
          }
        }
        return 0;
      }
      (*(code *)(long)DAT_ffffffffbfc43e38)(DAT_ffffffffbfc436f4 + -0x3c60);
      iVar5 = (*(code *)(long)DAT_ffffffffbfc4407c)(puVar8,puVar7,uVar4 * iVar9);
      iVar9 = DAT_ffffffffbfc43864;
      if (iVar5 == 0) {
        (*(code *)(long)DAT_ffffffffbfc43e38)(DAT_ffffffffbfc436f4 + -0x3c48);
        return 0;
      }
    }
    (*(code *)(long)iVar9)(iVar5);
  }
  return 1;
}

