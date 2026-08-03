/*
 * Ghidra reconstructed C; not original Cisco source.
 * RV220W boot-chain/U-Boot analysis v1.1.0
 * Entry: ffffffffbfc1b9d4
 * Function: FUN_ffffffffbfc1b9d4
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

void FUN_ffffffffbfc1b9d4(void)

{
  int iVar1;
  undefined4 uVar2;
  long lVar3;
  long lVar4;
  ulong uVar5;
  long lVar6;
  ulong uVar7;
  undefined8 uVar8;
  ulong *puVar9;
  ulong uVar10;
  undefined8 uVar11;
  ulong uVar12;
  undefined8 unaff_s0;
  int iVar13;
  undefined8 unaff_s1;
  long lVar14;
  code *pcVar15;
  undefined8 *puVar16;
  undefined8 in_ra;
  
  puVar16 = (undefined8 *)(long)((int)&stack0x00000000 + -0x40);
  puVar16[6] = &_gp;
  puVar16[5] = unaff_s1;
  puVar16[4] = unaff_s0;
  pcVar15 = (code *)(long)DAT_ffffffffbfc4385c;
  puVar16[7] = in_ra;
  lVar3 = (*pcVar15)();
  iVar1 = *(int *)((long)((int)lVar3 * 0x20 + -0x80000000) + 0x814);
  lVar14 = (long)iVar1;
  lVar4 = (*(code *)(long)(DAT_ffffffffbfc43700 + -0x4a40))(0xd0000);
  lVar6 = _DAT_80014f0000000338;
  if (lVar4 != 0) {
    if (lVar3 == 0) goto LAB_ffffffffbfc1ba78;
    pcVar15 = (code *)(long)DAT_ffffffffbfc43b98;
    lVar3 = *(long *)(long)DAT_ffffffffbfc43d94 + 0x58;
    *(long *)(long)DAT_ffffffffbfc43d94 = lVar3;
    lVar6 = (*pcVar15)();
    lVar6 = lVar3 + lVar6;
  }
  (*(code *)(long)DAT_ffffffffbfc43bc4)(lVar6);
LAB_ffffffffbfc1ba78:
  (*(code *)(long)DAT_ffffffffbfc43f78)(*(undefined4 *)(lVar14 + 0x518));
  uVar5 = (*(code *)(long)DAT_ffffffffbfc43f64)();
  uVar2 = getCopReg(2,0);
  *(undefined4 *)(*(long *)(lVar14 + 0x528) + 9) = uVar2;
  lVar6 = (*(code *)(long)(DAT_ffffffffbfc43700 + -0x4a40))(0xd0000);
  uVar7 = uVar5 | 0x2000;
  if (lVar6 == 0) {
    uVar7 = uVar5 & 0xffffffffffffdfff;
  }
  (*(code *)(long)DAT_ffffffffbfc43ae0)(uVar7 & 0xfffff3);
  iVar13 = DAT_ffffffffbfc43700 + -0x4a40;
  lVar6 = (*(code *)(long)iVar13)(0xd0001);
  if (lVar6 != 0) {
    uVar5 = (*(code *)(long)DAT_ffffffffbfc44034)();
    (*(code *)(long)DAT_ffffffffbfc43adc)(uVar5 | 0x20000000);
  }
  lVar6 = (*(code *)(long)iVar13)(0x70d0300);
  if (lVar6 == 0) {
    setCopReg(0,CONCAT44(uRegister00002128,PageGrain),(long)PageGrain | 0x40000000);
  }
  lVar6 = 0;
  iVar13 = 0;
  do {
    puVar9 = (ulong *)(long)(iVar1 + iVar13 * 0x28);
    if ((long)*(int *)(puVar9 + 3) != 0) {
      uVar7 = puVar9[4];
      uVar5 = 0;
      uVar12 = *puVar9 >> 6;
      if (*puVar9 == puVar9[1]) {
        uVar7 = uVar7 >> 0x38 & 0x38 | (uVar7 >> 0x3e & 1) << 0x3e | uVar12 | 7;
      }
      else {
        uVar10 = (uVar7 >> 0x3e & 1) << 0x3e;
        uVar5 = uVar7 >> 0x38 & 0x38;
        uVar7 = uVar5 | uVar10 | uVar12 | 7;
        uVar5 = uVar5 | uVar10 | puVar9[1] >> 6 | 7;
      }
      (*(code *)(long)DAT_ffffffffbfc438bc)
                (puVar9[2],uVar7,uVar5,~(-2L << (long)*(int *)(puVar9 + 3)),lVar6);
    }
    lVar6 = lVar6 + 1;
    iVar13 = (int)lVar6;
  } while (lVar6 != 0x20);
  (*(code *)(long)DAT_ffffffffbfc43bd0)();
  uVar11 = *(undefined8 *)(lVar14 + 0x508);
  uVar8 = *(undefined8 *)(lVar14 + 0x500);
  *puVar16 = *(undefined8 *)(lVar14 + 0x510);
  puVar16[1] = uVar8;
  puVar16[2] = uVar11;
  PerfCnt_1 = 0;
  PerfCnt_3 = 0;
  ErrorEPC = *(undefined8 *)(long)((int)&stack0x00000000 + -0x38);
  cop0_reg9_7 = cop0_reg9_7 | 0x1000;
  return;
}

