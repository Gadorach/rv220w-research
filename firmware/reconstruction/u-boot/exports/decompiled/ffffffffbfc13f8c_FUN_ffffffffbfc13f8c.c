/*
 * Ghidra reconstructed C; not original Cisco source.
 * RV220W boot-chain/U-Boot analysis v1.1.0
 * Entry: ffffffffbfc13f8c
 * Function: FUN_ffffffffbfc13f8c
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

undefined4 FUN_ffffffffbfc13f8c(long param_1)

{
  ushort uVar1;
  undefined8 in_at;
  undefined8 extraout_at;
  long lVar2;
  int iVar3;
  int iVar4;
  undefined8 unaff_s0;
  int *piVar5;
  undefined8 unaff_s1;
  int iVar6;
  undefined8 unaff_s2;
  int iVar7;
  undefined8 unaff_s3;
  int iVar8;
  undefined8 unaff_s4;
  int iVar9;
  undefined8 *puVar10;
  undefined8 in_ra;
  
  uVar1 = *(ushort *)(param_1 + 0x32);
  puVar10 = (undefined8 *)(long)((int)&stack0x00000000 + -0x40);
  iVar9 = *(int *)(param_1 + 0x20);
  puVar10[1] = unaff_s1;
  iVar6 = (int)param_1;
  puVar10[5] = &_gp;
  lVar2 = (long)(int)(iVar6 + iVar9 + (uint)uVar1 * 0x28);
  iVar9 = *(int *)(lVar2 + 4);
  puVar10[6] = in_ra;
  puVar10[4] = unaff_s4;
  puVar10[3] = unaff_s3;
  puVar10[2] = unaff_s2;
  *puVar10 = unaff_s0;
  if (iVar9 == 3) {
    iVar9 = iVar6 + *(int *)(lVar2 + 0x10);
  }
  else {
    iVar9 = 0;
  }
  iVar7 = 0;
  for (iVar8 = 0; iVar8 < (int)(uint)*(ushort *)(param_1 + 0x30); iVar8 = iVar8 + 1) {
    piVar5 = (int *)(long)(iVar6 + *(int *)(param_1 + 0x20) + iVar7);
    setCopReg(2,in_at,*(undefined4 *)((long)piVar5[2] + 0x27));
    if ((piVar5[3] != 0) && (piVar5[5] != 0)) {
      if (iVar9 != 0) {
        if (piVar5[1] == 8) {
          iVar3 = DAT_ffffffffbfc436f4 + -0x4c08;
        }
        else {
          iVar3 = DAT_ffffffffbfc436f4 + -0x4c00;
        }
        (*(code *)(long)DAT_ffffffffbfc4400c)(DAT_ffffffffbfc436f4 + -0x4bd0,iVar3,iVar9 + *piVar5);
      }
      if (piVar5[1] == 8) {
        iVar4 = 0;
        iVar3 = DAT_ffffffffbfc43a54;
      }
      else {
        iVar4 = iVar6 + piVar5[4];
        iVar3 = DAT_ffffffffbfc43e84;
      }
      (*(code *)(long)iVar3)(piVar5[3],iVar4,piVar5[5]);
      (*(code *)(long)DAT_ffffffffbfc43e48)(piVar5[3],piVar5[5]);
      in_at = extraout_at;
    }
    iVar7 = iVar7 + 0x28;
  }
  return *(undefined4 *)(param_1 + 0x18);
}

