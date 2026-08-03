/*
 * Ghidra reconstructed C; not original Cisco source.
 * RV220W boot-chain/U-Boot analysis v1.1.0
 * Entry: ffffffffbfc2c804
 * Function: FUN_ffffffffbfc2c804
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

void FUN_ffffffffbfc2c804(void)

{
  bool bVar1;
  uint uVar2;
  long lVar3;
  ulong uVar4;
  undefined8 uVar5;
  int iVar6;
  undefined4 *puVar7;
  undefined8 in_t4;
  undefined8 unaff_s0;
  code *pcVar8;
  undefined8 unaff_s1;
  undefined8 unaff_s2;
  ulong uVar9;
  undefined8 unaff_s3;
  code *pcVar10;
  undefined8 unaff_s4;
  undefined8 *puVar11;
  undefined8 in_ra;
  
  puVar11 = (undefined8 *)(long)((int)&stack0x00000000 + -0x40);
  puVar11[5] = &_gp;
  *puVar11 = unaff_s0;
  puVar11[6] = in_ra;
  iVar6 = DAT_ffffffffbfc436f0;
  puVar11[4] = unaff_s4;
  puVar11[3] = unaff_s3;
  pcVar8 = (code *)(long)(iVar6 + -0x4100);
  puVar11[2] = unaff_s2;
  puVar11[1] = unaff_s1;
  lVar3 = (*pcVar8)(0xd0000);
  if (lVar3 == 0) {
    lVar3 = (*pcVar8)(0xd0001);
    bVar1 = false;
    if (lVar3 != 0) goto LAB_ffffffffbfc2c87c;
    lVar3 = (*pcVar8)(0x30d0100);
    bVar1 = true;
    if (lVar3 == 0) goto LAB_ffffffffbfc2c87c;
  }
  bVar1 = false;
LAB_ffffffffbfc2c87c:
  pcVar10 = (code *)(long)(DAT_ffffffffbfc436f0 + -0x3f88);
  (*pcVar10)(&DAT_8001070000000748,1);
  (*(code *)(long)DAT_ffffffffbfc43b18)(2000);
  pcVar8 = (code *)(long)(DAT_ffffffffbfc436f0 + -0x4100);
  lVar3 = (*pcVar8)(0x30d0100);
  if (((lVar3 == 0) && (lVar3 = (*pcVar8)(0x30d0200), lVar3 == 0)) &&
     (lVar3 = (*pcVar8)(0x30d0600), lVar3 == 0)) {
    uVar5 = 4;
  }
  else {
    uVar5 = 0;
    pcVar10 = (code *)(long)(DAT_ffffffffbfc436f0 + -0x3f88);
  }
  (*pcVar10)(&DAT_8001070000000748,uVar5);
  (*(code *)(long)DAT_ffffffffbfc43b18)(2000);
  _DAT_80011f0000001188 = 0x10;
  if (bVar1) {
    _DAT_80011f0000001188 = 0x500010;
  }
  (*(code *)(long)DAT_ffffffffbfc43b18)(2000);
  uVar9 = (long)_DAT_80011f0000001188 & 0x2000;
  if (uVar9 == 0) {
    iVar6 = DAT_ffffffffbfc436f4 + 0x1c78;
  }
  else {
    iVar6 = DAT_ffffffffbfc436f4 + 0x1c80;
  }
  setCopReg(2,in_t4,*(undefined4 *)((long)_DAT_80011f0000001188 + 4));
  (*(code *)(long)DAT_ffffffffbfc4400c)
            (DAT_ffffffffbfc436f4 + 0x1c90,iVar6,DAT_ffffffffbfc436f4 + 0x1c88);
  iVar6 = DAT_ffffffffbfc436f0 + -0x4100;
  lVar3 = (*(code *)(long)iVar6)(0x30d0300);
  if ((lVar3 != 0) || (lVar3 = (*(code *)(long)iVar6)(0x30d0400), lVar3 != 0)) {
    uVar2 = (uint)((ulong)_DAT_80011f00000011b8 >> 0x20);
    puVar7 = (undefined4 *)(long)(int)((uVar2 & 3) * 4 + DAT_ffffffffbfc436f0 + 0x6b30);
    uVar5 = (*(code *)(long)DAT_ffffffffbfc4400c)
                      (DAT_ffffffffbfc436f4 + 0x1ca8,
                       *(undefined4 *)
                        (long)(int)((uVar2 >> 1 & 0xc) + DAT_ffffffffbfc436f0 + 0x6b30),*puVar7,
                       puVar7[1]);
    uVar4 = _DAT_80011f0000000130 >> 8 & 0xf;
    setCopReg(2,uVar4,*(undefined4 *)(uVar4 + 0x11));
    setCopReg(2,uVar5,*(undefined4 *)(uVar4 + 4));
    (*(code *)(long)DAT_ffffffffbfc4400c)
              (DAT_ffffffffbfc436f4 + 0x1cd8,DAT_ffffffffbfc436f4 + 0x1c80,
               *(undefined4 *)
                (long)(int)(((uint)(_DAT_80011f0000000130 >> 8) & 3) * 4 +
                           DAT_ffffffffbfc436f0 + 0x6b30));
  }
  if (uVar9 != 0) {
    _DAT_80011f0000001848 = 0x82000004;
  }
  _DAT_80011f0000001800 = 0x346;
  (*(code *)(long)(DAT_ffffffffbfc436f0 + -0x3f88))(&DAT_80011f0000000130,0x10);
  _DAT_80011f0000001844 = 1;
  _DAT_80011f000000185c = 0x4ff00;
  _DAT_80011f00000018e4 = 0x37e807;
  _DAT_80011f0000001184 = 0x22;
  _DAT_80011f0000001180 = 0x33;
  _DAT_80011f000000118c = 0x33;
  if (bVar1) {
    _DAT_80011f0000001814 = 0;
    _DAT_80011f000000181c = 0xffffffff;
  }
  else {
    _DAT_80011f0000001814 = 0x8000000;
    _DAT_80011f000000181c = 0;
  }
  _DAT_80011f0000001810 = 0;
  _DAT_80011f0000001818 = _DAT_80011f000000181c;
  _DAT_80011f0000001824 = 0;
  _DAT_80011f0000001820 = 0x80;
  return;
}

