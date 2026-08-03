/*
 * Ghidra reconstructed C; not original Cisco source.
 * RV220W boot-chain/U-Boot analysis v1.1.0
 * Entry: ffffffffbfc139e8
 * Function: do_gunzip
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
 * 
 * 
 * Recovered from U-Boot command table: command='gunzip', maxargs=5, repeatable=0, usage=''.
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
   
   
   Recovered from U-Boot command table: command='gunzip', maxargs=5, repeatable=0, usage=''. */

undefined8 do_gunzip(undefined8 param_1,undefined8 param_2,int param_3,long param_4)

{
  undefined8 *puVar1;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  long lVar2;
  int iVar6;
  undefined8 unaff_s0;
  undefined4 *puVar7;
  int iVar8;
  undefined8 unaff_s1;
  undefined8 unaff_s2;
  undefined8 unaff_s3;
  undefined8 unaff_s4;
  int in_t9_lo;
  undefined8 unaff_gp;
  long lVar9;
  undefined4 *puVar10;
  undefined8 in_ra;
  
  puVar10 = (undefined4 *)(long)((int)&stack0x00000000 + -0x70);
  *(undefined8 *)(puVar10 + 0x16) = unaff_gp;
  *(undefined8 *)(puVar10 + 0x12) = unaff_s3;
  *(undefined8 *)(puVar10 + 0xe) = unaff_s1;
  lVar9 = (long)(in_t9_lo + 0x2fcf8);
  *(undefined8 *)(puVar10 + 0x18) = in_ra;
  *(undefined8 *)(puVar10 + 0x14) = unaff_s4;
  *(undefined8 *)(puVar10 + 0x10) = unaff_s2;
  *(undefined8 *)(puVar10 + 0xc) = unaff_s0;
  if (1 < param_3) {
    puVar1 = (undefined8 *)(*(code *)(long)*(int *)(lVar9 + 0x134))(*(undefined4 *)(param_4 + 4),0);
    iVar8 = 2;
    if (puVar1 == (undefined8 *)0x0) {
      uVar3 = (*(code *)(long)*(int *)(lVar9 + 0x1d0))(*(undefined4 *)(param_4 + 4),0,0x10);
      if (param_3 == 2) goto LAB_ffffffffbfc13bac;
      iVar8 = 3;
      uVar4 = (*(code *)(long)*(int *)(lVar9 + 0x1d0))(*(undefined4 *)(param_4 + 8),0,0x10);
      *puVar10 = uVar4;
    }
    else {
      uVar3 = (undefined4)*puVar1;
      *puVar10 = (int)puVar1[1];
    }
    if (iVar8 < param_3) {
      puVar7 = (undefined4 *)(long)((int)param_4 + iVar8 * 4);
      puVar1 = (undefined8 *)(*(code *)(long)*(int *)(lVar9 + 0x134))(*puVar7,0);
      if (puVar1 == (undefined8 *)0x0) {
        uVar4 = (*(code *)(long)*(int *)(lVar9 + 0x1d0))(*puVar7,0,0x10);
        if (param_3 <= iVar8 + 1) goto LAB_ffffffffbfc13bac;
        uVar5 = (*(code *)(long)*(int *)(lVar9 + 0x1d0))
                          (*(undefined4 *)(long)((iVar8 + 1) * 4 + (int)param_4),0,0x10);
      }
      else {
        uVar5 = (undefined4)puVar1[1];
        uVar4 = (undefined4)*puVar1;
      }
      (*(code *)(long)*(int *)(lVar9 + 0x92c))
                (*(int *)(lVar9 + 0x14) + -0x4f08,*puVar10,uVar3,uVar5,uVar4);
      lVar2 = (*(code *)(long)*(int *)(lVar9 + 0x8a8))(uVar4,uVar5,uVar3,puVar10);
      if (lVar2 == 0) {
        iVar8 = (int)&stack0x00000000 + -0x6c;
        (*(code *)(long)*(int *)(lVar9 + 0x2c4))(iVar8,*(int *)(lVar9 + 0x14) + -0x5ca0,*puVar10);
        (*(code *)(long)*(int *)(lVar9 + 0x434))(*(int *)(lVar9 + 0x10) + 0x7b80,iVar8);
        (*(code *)(long)*(int *)(lVar9 + 0x92c))(*(int *)(lVar9 + 0x14) + -0x4ee0,*puVar10);
        return 0;
      }
      iVar8 = *(int *)(lVar9 + 0x92c);
      iVar6 = *(int *)(lVar9 + 0x14) + -0x4ec0;
      goto LAB_ffffffffbfc13bb8;
    }
  }
LAB_ffffffffbfc13bac:
  iVar8 = *(int *)(lVar9 + 0x92c);
  iVar6 = *(int *)(lVar9 + 0x14) + -0x4eb0;
LAB_ffffffffbfc13bb8:
  (*(code *)(long)iVar8)(iVar6);
  return 0xffffffffffffffff;
}

