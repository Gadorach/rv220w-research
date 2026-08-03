/*
 * Ghidra reconstructed C; not original Cisco source.
 * RV220W boot-chain/U-Boot analysis v1.1.0
 * Entry: ffffffffbfc286bc
 * Function: FUN_ffffffffbfc286bc
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

void FUN_ffffffffbfc286bc(void)

{
  undefined4 uVar1;
  ulong uVar2;
  ulong uVar3;
  undefined8 in_zero;
  undefined8 uVar4;
  int iVar5;
  uint uVar6;
  ulong uVar7;
  ulong uVar8;
  int iVar9;
  undefined8 unaff_s0;
  undefined8 *puVar10;
  code *pcVar11;
  undefined8 *puVar12;
  undefined8 in_ra;
  
  puVar12 = (undefined8 *)(long)((int)&stack0x00000000 + -0x20);
  puVar12[1] = &_gp;
  puVar12[2] = in_ra;
  pcVar11 = (code *)(long)DAT_ffffffffbfc4385c;
  *puVar12 = unaff_s0;
  uVar4 = (*pcVar11)();
  do {
  } while (*(int *)((long)DAT_ffffffffbfc436f4 + 0x6060) != 0);
  *(undefined4 *)((long)DAT_ffffffffbfc436f4 + 0x6060) = 1;
  SYNC(0);
  SYNC(0);
  uVar7 = *(ulong *)((long)DAT_ffffffffbfc436f4 + 0x6068);
  uVar2 = uVar7 >> 0x20 & 0xffff;
  uVar8 = ((long)(1 << ((uint)uVar4 & 0x1f)) ^ uVar2) & 0xffff;
  uVar3 = uVar8 << 0x20;
  SYNC(0);
  *(ulong *)((long)DAT_ffffffffbfc436f4 + 0x6068) = uVar7 & 0xffff0000ffffffff | uVar3;
  SYNC(4);
  if ((uVar7 & 0x20000000000000 | uVar3) == 0x20000000000000) {
    (*(code *)(long)(DAT_ffffffffbfc436f0 + -0x7a2c))(DAT_ffffffffbfc436f4 + 0x15e0);
  }
  else {
    special2(uVar4,uVar2,5,0x32);
    puVar10 = (undefined8 *)(uVar2 + 0x1070000000200 | 0x8000000000000000);
    setCopReg(2,in_zero,
              *(undefined4 *)
               ((long)((int)((uint)((ulong)*puVar10 >> 0x22) & 3) >>
                      (*(uint *)((long)DAT_ffffffffbfc436f4 + 0x2e88) & 0x1f)) + 0xd));
    uVar6 = 0;
    iVar9 = (int)uVar8;
    iVar5 = iVar9;
    do {
      uVar1 = getCopReg(2,0);
      *(undefined4 *)((long)iVar5 + -0x22) = uVar1;
      uVar6 = uVar6 + 1;
      iVar5 = iVar9 >> (uVar6 & 0x1f);
    } while (uVar6 != 0x10);
    (*(code *)(long)(DAT_ffffffffbfc436f0 + -0x7f40))(puVar10,0);
  }
  SYNC(0);
  *(undefined4 *)((long)DAT_ffffffffbfc436f4 + 0x6060) = 0;
  SYNC(4);
  return;
}

