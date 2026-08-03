/*
 * Ghidra reconstructed C; not original Cisco source.
 * RV220W boot-chain/U-Boot analysis v1.1.0
 * Entry: ffffffffbfc0b610
 * Function: FUN_ffffffffbfc0b610
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

undefined8 FUN_ffffffffbfc0b610(ulong param_1,undefined8 param_2)

{
  char cVar1;
  ulong uVar2;
  int iVar4;
  long lVar3;
  int iVar5;
  ulong uVar6;
  uint uVar7;
  char *pcVar8;
  undefined8 unaff_s0;
  undefined8 unaff_s1;
  code *pcVar9;
  undefined8 unaff_s2;
  undefined8 unaff_s3;
  undefined8 unaff_s4;
  undefined8 unaff_s5;
  undefined8 uVar10;
  undefined8 unaff_s6;
  int iVar11;
  undefined8 unaff_s7;
  undefined8 in_t8;
  undefined8 in_k0;
  char *pcVar12;
  undefined8 in_ra;
  int iVar13;
  
  iVar13 = (int)&stack0x00000000;
  pcVar12 = (char *)(long)(iVar13 + -0x60);
  *(undefined1 **)(pcVar12 + 0x50) = &_gp;
  *(undefined8 *)(pcVar12 + 0x48) = unaff_s7;
  *(undefined8 *)(pcVar12 + 0x10) = unaff_s0;
  *(undefined8 *)(pcVar12 + 0x58) = in_ra;
  *(undefined8 *)(pcVar12 + 0x40) = unaff_s6;
  *(undefined8 *)(pcVar12 + 0x38) = unaff_s5;
  *(undefined8 *)(pcVar12 + 0x30) = unaff_s4;
  *(undefined8 *)(pcVar12 + 0x28) = unaff_s3;
  *(undefined8 *)(pcVar12 + 0x20) = unaff_s2;
  *(undefined8 *)(pcVar12 + 0x18) = unaff_s1;
  uVar2 = param_1 >> 8 & 0xff;
  uVar10 = special2((long)(int)_DAT_8001070000000728,0,0,0x2c);
  if (uVar2 == 4) {
    uVar6 = _DAT_8001180000001418 | 0x1000000;
  }
  else if ((uVar2 == 6) || (uVar6 = _DAT_8001180000001418, uVar2 == 2)) {
    uVar6 = _DAT_8001180000001418 & 0xfffffffffcffffff | 0x3000000;
  }
  setCopReg(2,in_t8,*(undefined4 *)(uVar6 + 8));
  setCopReg(2,in_k0,*(undefined4 *)(_DAT_8001180000001410 + 4));
  (*(code *)(long)DAT_ffffffffbfc439a4)
            (pcVar12,DAT_ffffffffbfc436f4 + -0x6000,((uint)(param_1 >> 3) & 7) + 1,param_1 & 7);
  uVar7 = (int)uVar10 - 1;
  if (uVar7 < 0x10) {
                    /* WARNING: Could not recover jumptable at 0xffffffffbfc0b758. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
    uVar10 = (*(code *)(long)(*(int *)(long)(int)(uVar7 * 4 + DAT_ffffffffbfc436f0 + 0x62a0) +
                             -0x403bc920))();
    return uVar10;
  }
  if (uVar2 < 9) {
                    /* WARNING: Could not recover jumptable at 0xffffffffbfc0b80c. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
    uVar10 = (*(code *)(long)(*(int *)(long)((int)uVar2 * 4 + DAT_ffffffffbfc436f0 + 0x62e0) +
                             -0x403bc920))();
    return uVar10;
  }
  iVar4 = DAT_ffffffffbfc436f4 + -0x5f58;
  pcVar8 = pcVar12;
  do {
    cVar1 = *(char *)(long)iVar4;
    iVar4 = iVar4 + 1;
    *pcVar8 = cVar1;
    pcVar8 = (char *)(long)((int)pcVar8 + 1);
  } while (cVar1 != '\0');
  iVar4 = DAT_ffffffffbfc436f4 + -0x5ff0;
  iVar11 = DAT_ffffffffbfc436f4 + -0x5ef0;
  lVar3 = (*(code *)(long)DAT_ffffffffbfc43c60)();
  if (lVar3 != 0) {
    (*(code *)(long)DAT_ffffffffbfc43c60)();
  }
  pcVar9 = (code *)(long)(DAT_ffffffffbfc436fc + -0x4a40);
  (*pcVar9)(0x33);
  iVar5 = (*pcVar9)(0x32);
  uVar7 = (*pcVar9)(0x31);
  uVar6 = (*pcVar9)(0x30);
  uVar6 = (long)(int)((iVar5 << 8 | uVar7) << 8) | uVar6;
  uVar2 = uVar6 >> 0xe & 0x1f;
  iVar5 = iVar4;
  if ((uVar6 & 0x7ffff) != 0) {
    if (uVar2 == 0) {
      (*(code *)(long)DAT_ffffffffbfc439a4)(iVar13 + -0x5c,DAT_ffffffffbfc436f0 + 0x70a8);
    }
    else {
      iVar5 = iVar13 + -0x5c;
      if ((uVar6 & 0x3fff) == 0) {
        (*(code *)(long)DAT_ffffffffbfc439a4)
                  (iVar5,DAT_ffffffffbfc436f4 + -0x6020,iVar4,(int)uVar2 + 0x40);
        goto LAB_ffffffffbfc0bc20;
      }
      (*(code *)(long)DAT_ffffffffbfc439a4)(iVar5,DAT_ffffffffbfc436f4 + -0x5ee8);
    }
    iVar4 = iVar13 + -0x5c;
    iVar5 = DAT_ffffffffbfc436f4 + -0x3ca8;
  }
LAB_ffffffffbfc0bc20:
  (*(code *)(long)DAT_ffffffffbfc439a4)
            (param_2,DAT_ffffffffbfc436f4 + -0x6018,iVar4,iVar5,iVar11,pcVar12);
  return param_2;
}

