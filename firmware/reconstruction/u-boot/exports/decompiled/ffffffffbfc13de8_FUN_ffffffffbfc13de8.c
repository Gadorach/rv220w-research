/*
 * Ghidra reconstructed C; not original Cisco source.
 * RV220W boot-chain/U-Boot analysis v1.1.0
 * Entry: ffffffffbfc13de8
 * Function: FUN_ffffffffbfc13de8
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

ulong FUN_ffffffffbfc13de8(long param_1)

{
  ushort uVar1;
  undefined8 in_at;
  undefined8 extraout_at;
  ulong uVar2;
  int iVar5;
  long lVar3;
  ulong uVar4;
  int iVar6;
  undefined8 unaff_s0;
  int *piVar7;
  undefined8 unaff_s1;
  undefined8 unaff_s2;
  int iVar8;
  undefined8 unaff_s3;
  int iVar9;
  undefined8 *puVar10;
  undefined8 in_ra;
  
  iVar9 = *(int *)(param_1 + 0x2c);
  puVar10 = (undefined8 *)(long)((int)&stack0x00000000 + -0x30);
  uVar1 = *(ushort *)(param_1 + 0x3e);
  puVar10[1] = unaff_s1;
  iVar5 = (int)param_1;
  puVar10[4] = &_gp;
  lVar3 = (long)(int)(iVar5 + iVar9 + (uint)uVar1 * 0x40);
  iVar9 = *(int *)(lVar3 + 4);
  puVar10[5] = in_ra;
  puVar10[3] = unaff_s3;
  puVar10[2] = unaff_s2;
  *puVar10 = unaff_s0;
  if (iVar9 == 3) {
    iVar9 = iVar5 + *(int *)(lVar3 + 0x1c);
  }
  else {
    iVar9 = 0;
  }
  for (iVar8 = 0; iVar8 < (int)(uint)*(ushort *)(param_1 + 0x3c); iVar8 = iVar8 + 1) {
    piVar7 = (int *)(long)(iVar5 + *(int *)(param_1 + 0x2c) + iVar8 * 0x40);
    setCopReg(2,in_at,*(undefined4 *)(*(long *)(piVar7 + 2) + 0x38));
    if ((*(long *)(piVar7 + 4) != 0) && (*(long *)(piVar7 + 8) != 0)) {
      if (iVar9 != 0) {
        if (piVar7[1] == 8) {
          iVar6 = DAT_ffffffffbfc436f4 + -0x4c08;
        }
        else {
          iVar6 = DAT_ffffffffbfc436f4 + -0x4c00;
        }
        (*(code *)(long)DAT_ffffffffbfc4400c)
                  (DAT_ffffffffbfc436f4 + -0x4bf8,iVar6,iVar9 + *piVar7,*(long *)(piVar7 + 4),
                   (int)*(long *)(piVar7 + 8));
      }
      uVar2 = *(ulong *)(piVar7 + 4);
      if (piVar7[1] == 8) {
        uVar4 = uVar2 & 0x87ffffffffffffff;
        if ((~uVar2 & 0xffffffff00000000) == 0) {
          uVar4 = uVar2;
        }
        (*(code *)(long)DAT_ffffffffbfc43bf8)(uVar4,0,*(undefined8 *)(piVar7 + 8));
        iVar6 = piVar7[9];
      }
      else {
        uVar4 = uVar2 & 0x87ffffffffffffff;
        if ((~uVar2 & 0xffffffff00000000) == 0) {
          uVar4 = uVar2;
        }
        (*(code *)(long)DAT_ffffffffbfc438f0)
                  (uVar4,(long)(iVar5 + (int)*(undefined8 *)(piVar7 + 6)) & 0x7fffffffU |
                         0x8000000000000000,*(undefined8 *)(piVar7 + 8));
        iVar6 = piVar7[9];
      }
      (*(code *)(long)DAT_ffffffffbfc43e48)(piVar7[5],iVar6);
      in_at = extraout_at;
    }
  }
  uVar2 = *(ulong *)(param_1 + 0x18);
  if ((~uVar2 & 0xffffffff00000000) != 0) {
    uVar2 = uVar2 & 0x87ffffffffffffff;
  }
  return uVar2;
}

