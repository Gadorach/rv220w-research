/*
 * Ghidra reconstructed C; not original Cisco source.
 * RV220W boot-chain/U-Boot analysis v1.1.0
 * Entry: ffffffffbfc1f5b4
 * Function: FUN_ffffffffbfc1f5b4
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

undefined8 FUN_ffffffffbfc1f5b4(void)

{
  undefined4 uVar1;
  undefined8 in_zero;
  undefined8 extraout_at;
  int iVar3;
  int *piVar2;
  undefined8 unaff_s0;
  undefined4 *puVar4;
  undefined8 unaff_s1;
  int iVar6;
  int iVar7;
  int *piVar5;
  undefined8 unaff_s2;
  int *piVar8;
  undefined8 unaff_s3;
  code *pcVar9;
  long in_k0;
  undefined8 *puVar10;
  undefined8 in_ra;
  
  puVar10 = (undefined8 *)(long)((int)&stack0x00000000 + -0x30);
  puVar10[4] = &_gp;
  puVar10[3] = unaff_s3;
  puVar10[2] = unaff_s2;
  piVar8 = (int *)0x0;
  pcVar9 = (code *)(long)DAT_ffffffffbfc43a38;
  uVar1 = *(undefined4 *)(long)DAT_ffffffffbfc43a24;
  puVar10[1] = unaff_s1;
  *puVar10 = unaff_s0;
  puVar10[5] = in_ra;
  iVar3 = (*pcVar9)(uVar1);
  piVar5 = (int *)0x0;
  iVar7 = 1;
  while (iVar7 <= iVar3) {
    if ((piVar8 != (int *)0x0) && (piVar5 != (int *)0x0)) goto LAB_ffffffffbfc1f658;
    iVar6 = iVar7 + 1;
    piVar2 = (int *)(*(code *)(long)DAT_ffffffffbfc4394c)
                              (*(undefined4 *)(long)DAT_ffffffffbfc43a24,iVar7);
    setCopReg(2,in_zero,*(undefined4 *)((long)*piVar2 + 2));
    if (piVar8 == (int *)0x0) {
      piVar8 = piVar2;
    }
    setCopReg(2,extraout_at,*(undefined4 *)((long)*piVar2 + 3));
    iVar7 = iVar6;
    if (piVar5 == (int *)0x0) {
      piVar5 = piVar2;
    }
  }
  if (piVar5 != (int *)0x0) {
LAB_ffffffffbfc1f658:
    iVar7 = DAT_ffffffffbfc43700 + -0xdc0;
    (*(code *)(long)iVar7)(1,piVar5);
    (*(code *)(long)iVar7)(2,piVar5);
  }
  if (piVar8 != (int *)0x0) {
    (*(code *)(long)(DAT_ffffffffbfc43700 + -0xdc0))(0,piVar8);
  }
  iVar7 = DAT_ffffffffbfc439f8;
  puVar4 = (undefined4 *)(long)DAT_ffffffffbfc43974;
  *(uint *)(in_k0 + 4) = *(uint *)(in_k0 + 4) | 2;
  do {
    piVar5 = (int *)(long)iVar7;
    iVar7 = iVar7 + 4;
    uVar1 = *puVar4;
    puVar4 = (undefined4 *)(long)((int)puVar4 + 4);
    (*(code *)(long)DAT_ffffffffbfc43b14)(uVar1,*piVar5 + 8);
  } while (puVar4 != (undefined4 *)(long)(DAT_ffffffffbfc43974 + 0xc));
  return 0;
}

