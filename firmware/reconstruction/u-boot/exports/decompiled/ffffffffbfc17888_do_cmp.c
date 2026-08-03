/*
 * Ghidra reconstructed C; not original Cisco source.
 * RV220W boot-chain/U-Boot analysis v1.1.0
 * Entry: ffffffffbfc17888
 * Function: do_cmp
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
 * Recovered from U-Boot command table: command='cmp', maxargs=4, repeatable=1, usage=''.
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
   
   Recovered from U-Boot command table: command='cmp', maxargs=4, repeatable=1, usage=''. */

undefined8 do_cmp(long param_1,undefined8 param_2,long param_3,undefined4 *param_4)

{
  long lVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  ushort uVar5;
  undefined8 unaff_s0;
  undefined8 uVar6;
  long lVar7;
  ushort *puVar8;
  undefined8 unaff_s1;
  ushort *puVar9;
  undefined8 unaff_s2;
  undefined8 unaff_s3;
  undefined8 unaff_s4;
  int iVar10;
  undefined8 *puVar11;
  undefined8 in_ra;
  
  puVar11 = (undefined8 *)(long)((int)&stack0x00000000 + -0x40);
  puVar11[5] = &_gp;
  puVar11[2] = unaff_s2;
  puVar11[6] = in_ra;
  puVar11[4] = unaff_s4;
  puVar11[3] = unaff_s3;
  puVar11[1] = unaff_s1;
  *puVar11 = unaff_s0;
  if (param_3 == 4) {
    lVar1 = (*(code *)(long)DAT_ffffffffbfc43ae8)(*param_4,4);
    if (lVar1 < 0) {
      uVar6 = 1;
    }
    else {
      lVar7 = (long)DAT_ffffffffbfc436f4;
      iVar10 = 0;
      iVar2 = (*(code *)(long)DAT_ffffffffbfc438b0)(param_4[1],0,0x10);
      iVar2 = iVar2 + *(int *)(lVar7 + 0x4bf0);
      iVar3 = (*(code *)(long)DAT_ffffffffbfc438b0)(param_4[2],0,0x10);
      iVar3 = iVar3 + *(int *)(lVar7 + 0x4bf0);
      iVar4 = (*(code *)(long)DAT_ffffffffbfc438b0)(param_4[3],0,0x10);
      while( true ) {
        puVar9 = (ushort *)(long)iVar2;
        puVar8 = (ushort *)(long)iVar3;
        if (iVar10 == iVar4) break;
        if (lVar1 == 4) {
          if (*(int *)puVar9 != *(int *)puVar8) {
            uVar6 = 1;
            (*(code *)(long)DAT_ffffffffbfc4400c)
                      (DAT_ffffffffbfc436f4 + -0x3c40,puVar9,*(int *)puVar9,puVar8);
            goto LAB_ffffffffbfc17a00;
          }
        }
        else if (lVar1 == 2) {
          uVar5 = *puVar9;
          if (uVar5 != *puVar8) {
            iVar2 = DAT_ffffffffbfc436f4 + -0x3c00;
LAB_ffffffffbfc17a68:
            uVar6 = 1;
            (*(code *)(long)DAT_ffffffffbfc4400c)(iVar2,puVar9,uVar5,puVar8);
            goto LAB_ffffffffbfc17a0c;
          }
        }
        else {
          uVar5 = (ushort)*(byte *)puVar9;
          if (uVar5 != *(byte *)puVar8) {
            iVar2 = DAT_ffffffffbfc436f4 + -0x3bc0;
            goto LAB_ffffffffbfc17a68;
          }
        }
        iVar10 = iVar10 + 1;
        iVar2 = iVar2 + (int)lVar1;
        iVar3 = iVar3 + (int)lVar1;
      }
      if (lVar1 == 4) {
        uVar6 = 0;
LAB_ffffffffbfc17a00:
        iVar2 = DAT_ffffffffbfc436f4 + -0x3c08;
      }
      else {
        uVar6 = 0;
LAB_ffffffffbfc17a0c:
        if (lVar1 == 2) {
          iVar2 = DAT_ffffffffbfc436f4 + -0x3b88;
        }
        else {
          iVar2 = DAT_ffffffffbfc436f4 + -0x3b78;
        }
      }
      if (iVar10 == 1) {
        iVar3 = DAT_ffffffffbfc436f4 + -0x3ca8;
      }
      else {
        iVar3 = DAT_ffffffffbfc436f4 + -0x2c30;
      }
      (*(code *)(long)DAT_ffffffffbfc4400c)(DAT_ffffffffbfc436f4 + -0x3b70,iVar10,iVar2,iVar3);
    }
  }
  else {
    uVar6 = 1;
    (*(code *)(long)DAT_ffffffffbfc4400c)
              (DAT_ffffffffbfc436f4 + -0x5320,*(undefined4 *)(param_1 + 0x10));
  }
  return uVar6;
}

