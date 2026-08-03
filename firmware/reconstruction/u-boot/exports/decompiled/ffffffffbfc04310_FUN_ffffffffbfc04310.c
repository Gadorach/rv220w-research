/*
 * Ghidra reconstructed C; not original Cisco source.
 * RV220W boot-chain/U-Boot analysis v1.1.0
 * Entry: ffffffffbfc04310
 * Function: FUN_ffffffffbfc04310
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

void FUN_ffffffffbfc04310(ulong param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  long lVar4;
  int iVar6;
  ulong uVar5;
  int iVar7;
  undefined8 unaff_s0;
  undefined8 unaff_s1;
  undefined8 unaff_s2;
  undefined8 unaff_s3;
  undefined8 unaff_s4;
  undefined8 unaff_s5;
  code *pcVar8;
  long in_k0;
  undefined8 *puVar9;
  undefined8 in_ra;
  
  puVar9 = (undefined8 *)(long)((int)&stack0x00000000 + -0x40);
  puVar9[6] = &_gp;
  puVar9[4] = unaff_s4;
  pcVar8 = (code *)(long)DAT_ffffffffbfc43ad0;
  puVar9[5] = unaff_s5;
  puVar9[1] = unaff_s1;
  puVar9[7] = in_ra;
  puVar9[3] = unaff_s3;
  puVar9[2] = unaff_s2;
  *puVar9 = unaff_s0;
  (*pcVar8)(0,~param_1 & 0xffff);
  iVar3 = DAT_ffffffffbfc436f0;
  iVar1 = *(int *)(in_k0 + 0x1c);
  iVar7 = 0;
  do {
    if ((*(char *)(long)(iVar1 + iVar7) == '\0') && (*(char *)((long)(iVar1 + iVar7) + 1) == '\0'))
    break;
    iVar7 = iVar7 + 1;
  } while (iVar7 != 0x1fffb);
  lVar4 = (*(code *)(long)DAT_ffffffffbfc43cec)
                    (iVar7 + 2,0,0x40000000,0,DAT_ffffffffbfc436f0 + 0x7ee8,1);
  iVar6 = (int)lVar4;
  if ((-1 < lVar4) && (iVar6 != 0)) {
    lVar4 = (*(code *)(long)DAT_ffffffffbfc43814)(iVar3 + 0x7ee8,0);
    (*(code *)(long)DAT_ffffffffbfc43a54)(iVar6,0,*(undefined4 *)(lVar4 + 0xc));
    (*(code *)(long)DAT_ffffffffbfc43e84)(iVar6,iVar1,iVar7 + 1);
  }
  uVar5 = (*(code *)(long)DAT_ffffffffbfc43738)();
  *(ulong *)(long)DAT_ffffffffbfc43d94 =
       (cop0_reg9_6 & 0xffffffff00000000) + (cop0_reg9_6 & 0xffffffff);
  SYNC(0);
  (*(code *)(long)(DAT_ffffffffbfc436ec + 0x30b8))(0x8001070000000700,~param_1 & uVar5 & 0xffffffff)
  ;
  uVar2 = getCopReg(2,0);
  *(undefined4 *)(param_1 + 3) = uVar2;
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}

