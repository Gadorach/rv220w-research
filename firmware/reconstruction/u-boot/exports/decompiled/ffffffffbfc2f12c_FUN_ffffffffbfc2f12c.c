/*
 * Ghidra reconstructed C; not original Cisco source.
 * RV220W boot-chain/U-Boot analysis v1.1.0
 * Entry: ffffffffbfc2f12c
 * Function: FUN_ffffffffbfc2f12c
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
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

undefined8 FUN_ffffffffbfc2f12c(void)

{
  ulong uVar1;
  undefined8 in_zero;
  int iVar4;
  int iVar5;
  undefined8 uVar2;
  long lVar3;
  undefined8 unaff_s0;
  int iVar6;
  undefined8 unaff_s1;
  int iVar7;
  undefined8 unaff_s2;
  undefined8 *puVar8;
  undefined8 in_ra;
  
  puVar8 = (undefined8 *)(long)((int)&stack0x00000000 + -0x30);
  puVar8[3] = &_gp;
  *puVar8 = unaff_s0;
  puVar8[4] = in_ra;
  puVar8[2] = unaff_s2;
  puVar8[1] = unaff_s1;
  uVar1 = _DAT_80014f0000000018;
  setCopReg(2,in_zero,*(undefined4 *)(_DAT_80014f0000000018 + 6));
  (*(code *)(long)DAT_ffffffffbfc4400c)(DAT_ffffffffbfc436f4 + 0x1f90);
  iVar6 = 0;
  (*(code *)(long)(DAT_ffffffffbfc436f0 + -0x1508))(&DAT_80014f0000000018,uVar1 | 1);
  iVar4 = (*(code *)(long)DAT_ffffffffbfc43c04)();
  iVar7 = DAT_ffffffffbfc436f8 + 0x1b38;
  while( true ) {
    if (iVar4 <= iVar6) break;
    if (0 < *(int *)(long)iVar7) {
      iVar5 = (*(code *)(long)DAT_ffffffffbfc43bc0)(iVar6);
      if (iVar5 - 1U < 9) {
                    /* WARNING: Could not recover jumptable at 0xffffffffbfc2f1ec. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
        uVar2 = (*(code *)(long)(*(int *)(long)(int)((iVar5 - 1U) * 4 +
                                                    DAT_ffffffffbfc436f0 + 0x6bb0) + -0x403bc920))()
        ;
        return uVar2;
      }
      (*(code *)(long)DAT_ffffffffbfc43d5c)(iVar6);
    }
    iVar6 = iVar6 + 1;
    iVar7 = iVar7 + 4;
  }
  (*(code *)(long)DAT_ffffffffbfc43e70)();
  iVar4 = DAT_ffffffffbfc436f0 + -0x1680;
  lVar3 = (*(code *)(long)iVar4)(0xd0100);
  if ((lVar3 == 0) && (lVar3 = (*(code *)(long)iVar4)(0x20d0200), lVar3 == 0)) {
    return 0;
  }
  lVar3 = (*(code *)(long)DAT_ffffffffbfc43c60)();
  if (*(short *)(lVar3 + 0x40) != 1) {
    (*(code *)(long)DAT_ffffffffbfc4397c)();
  }
  return 0;
}

