/*
 * Ghidra reconstructed C; not original Cisco source.
 * RV220W boot-chain/U-Boot analysis v1.1.0
 * Entry: ffffffffbfc30740
 * Function: FUN_ffffffffbfc30740
 * Subsystem: bootloader-support
 *
 * RV220W BOOT-CHAIN / U-BOOT SEMANTIC ANNOTATION v1.1.0
 * Region: u-boot-proper
 * Subsystem: bootloader-support
 * Evidence: Ghidra control-flow/GOT recovery
 * Confidence: medium for boundary; low for original name
 * Interpretation: Analysis-created function. Boundary is supported by control flow or a recovered GOT pointer, but original source name and detailed role are unknown.
 * Safety: reconstructed pseudocode is not original Cisco source. Do not replay flash, GPIO, MDIO or switch writes without readback and recovery safeguards.
 * 
 * Prior/recovered evidence:
 * RV220W BOOT-CHAIN / U-BOOT SEMANTIC ANNOTATION v1.1.0
 * Region: u-boot-proper
 * Subsystem: bootloader-support
 * Evidence: Ghidra control-flow/GOT recovery
 * Confidence: medium for boundary; low for original name
 * Interpretation: Analysis-created function. Boundary is supported by control flow or a recovered GOT pointer, but original source name and detailed role are unknown.
 * Safety: reconstructed pseudocode is not original Cisco source. Do not replay flash, GPIO, MDIO or switch writes without readback and recovery safeguards.
 * 
 * Prior/recovered evidence:
 * RV220W BOOT-CHAIN / U-BOOT SEMANTIC ANNOTATION v1.1.0
 * Region: u-boot-proper
 * Subsystem: bootloader-support
 * Evidence: Ghidra control-flow/GOT recovery
 * Confidence: medium for boundary; low for original name
 * Interpretation: Analysis-created function. Boundary is supported by control flow or a recovered GOT pointer, but original source name and detailed role are unknown.
 * Safety: reconstructed pseudocode is not original Cisco source. Do not replay flash, GPIO, MDIO or switch writes without readback and recovery safeguards.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* RV220W BOOT-CHAIN / U-BOOT SEMANTIC ANNOTATION v1.1.0
   Region: u-boot-proper
   Subsystem: bootloader-support
   Evidence: Ghidra control-flow/GOT recovery
   Confidence: medium for boundary; low for original name
   Interpretation: Analysis-created function. Boundary is supported by control flow or a recovered
   GOT pointer, but original source name and detailed role are unknown.
   Safety: reconstructed pseudocode is not original Cisco source. Do not replay flash, GPIO, MDIO or
   switch writes without readback and recovery safeguards.
   
   Prior/recovered evidence:
   RV220W BOOT-CHAIN / U-BOOT SEMANTIC ANNOTATION v1.1.0
   Region: u-boot-proper
   Subsystem: bootloader-support
   Evidence: Ghidra control-flow/GOT recovery
   Confidence: medium for boundary; low for original name
   Interpretation: Analysis-created function. Boundary is supported by control flow or a recovered
   GOT pointer, but original source name and detailed role are unknown.
   Safety: reconstructed pseudocode is not original Cisco source. Do not replay flash, GPIO, MDIO or
   switch writes without readback and recovery safeguards.
   
   Prior/recovered evidence:
   RV220W BOOT-CHAIN / U-BOOT SEMANTIC ANNOTATION v1.1.0
   Region: u-boot-proper
   Subsystem: bootloader-support
   Evidence: Ghidra control-flow/GOT recovery
   Confidence: medium for boundary; low for original name
   Interpretation: Analysis-created function. Boundary is supported by control flow or a recovered
   GOT pointer, but original source name and detailed role are unknown.
   Safety: reconstructed pseudocode is not original Cisco source. Do not replay flash, GPIO, MDIO or
   switch writes without readback and recovery safeguards. */

undefined8 FUN_ffffffffbfc30740(undefined8 param_1,ulong param_2)

{
  undefined8 uVar1;
  undefined8 uVar2;
  ulong *puVar3;
  int iVar5;
  undefined8 uVar4;
  ulong uVar6;
  long lVar7;
  undefined8 unaff_s0;
  undefined8 unaff_s1;
  ulong uVar8;
  ulong uVar9;
  undefined8 unaff_s2;
  undefined8 unaff_s3;
  undefined8 unaff_s4;
  undefined8 unaff_s5;
  ulong *puVar10;
  undefined8 unaff_s6;
  undefined8 unaff_s7;
  code *pcVar11;
  int *piVar12;
  undefined8 unaff_s8;
  int iVar13;
  undefined8 in_ra;
  
  piVar12 = (int *)(long)((int)&stack0x00000000 + -0x70);
  *(undefined1 **)(piVar12 + 0x14) = &_gp;
  *(undefined8 *)(piVar12 + 0x18) = in_ra;
  *(undefined8 *)(piVar12 + 0x10) = unaff_s6;
  pcVar11 = (code *)(long)DAT_ffffffffbfc43fb0;
  *(undefined8 *)(piVar12 + 10) = unaff_s3;
  *(undefined8 *)(piVar12 + 8) = unaff_s2;
  *(undefined8 *)(piVar12 + 6) = unaff_s1;
  *(undefined8 *)(piVar12 + 4) = unaff_s0;
  *(undefined8 *)(piVar12 + 0x16) = unaff_s8;
  *(undefined8 *)(piVar12 + 0x12) = unaff_s7;
  *(undefined8 *)(piVar12 + 0xe) = unaff_s5;
  *(undefined8 *)(piVar12 + 0xc) = unaff_s4;
  uVar1 = (*pcVar11)();
  uVar2 = (*(code *)(long)DAT_ffffffffbfc43dd0)(param_1);
  puVar3 = (ulong *)(*(code *)(long)(DAT_ffffffffbfc436f0 + 0x5e0))(uVar2,uVar1);
  uVar8 = *puVar3;
  uVar6 = param_2 & 0x3ffff;
  *(ulong *)(piVar12 + 2) = uVar6;
  uVar9 = (param_2 >> 0x12 & 1) << 2;
  if ((uVar6 == 10) || (*(long *)(piVar12 + 2) == 100)) {
    uVar9 = uVar8 & 0xfffffffffffffff1 | uVar9;
  }
  else {
    uVar9 = uVar8 & 0xfffffffffffffffb | uVar9 | 10;
  }
  if (uVar9 == uVar8) {
    return 0;
  }
  special2(uVar1,uVar6,0x1b,0x32);
  puVar10 = (ulong *)(&DAT_80011800b0000000 + uVar6);
  uVar6 = *puVar10;
  iVar5 = 1 << ((uint)uVar2 & 0x1f);
  piVar12[1] = iVar5;
  pcVar11 = (code *)(long)(DAT_ffffffffbfc436f0 + 0x6bc);
  (*pcVar11)(puVar10,uVar6 & ~(long)iVar5);
  (*pcVar11)(puVar3,uVar8 & 0xfffffffffffffffe);
  iVar5 = ((int)uVar1 * 8 + (uint)uVar2) * 0x100;
  iVar13 = iVar5 + 0x880;
  *piVar12 = iVar5;
  (*pcVar11)(0x80011f0000000008,iVar13);
  iVar5 = *piVar12;
  if ((_DAT_80011f00000001e8 & 7) != 0) {
    (*(code *)(long)DAT_ffffffffbfc4400c)(DAT_ffffffffbfc436f4 + 0x20d0);
    while ((*(code *)(long)(DAT_ffffffffbfc436f0 + 0x6bc))(0x80011f0000000008,iVar13),
          (_DAT_80011f00000001e8 & 7) != 0) {
      (*(code *)(long)(DAT_ffffffffbfc436f0 + 0x6ec))(100);
    }
    iVar5 = *piVar12;
  }
  (*(code *)(long)(DAT_ffffffffbfc436f0 + 0x6bc))(0x80011f0000000008,iVar5 + 0x8c1);
  lVar7 = *(long *)(piVar12 + 2);
  if ((_DAT_80011f00000001e8 & 0xf) != 0) {
    (*(code *)(long)DAT_ffffffffbfc4400c)(DAT_ffffffffbfc436f4 + 0x2118);
    while ((*(code *)(long)(DAT_ffffffffbfc436f0 + 0x6bc))(0x80011f0000000008,iVar5 + 0x8c1),
          (_DAT_80011f00000001e8 & 0xf) != 0) {
      (*(code *)(long)(DAT_ffffffffbfc436f0 + 0x6ec))(100);
    }
    lVar7 = *(long *)(piVar12 + 2);
  }
  iVar5 = DAT_ffffffffbfc436f0;
  if (lVar7 == 10) {
    uVar4 = (*(code *)(long)(DAT_ffffffffbfc436f0 + 0x664))(uVar2,uVar1);
    pcVar11 = (code *)(long)(DAT_ffffffffbfc436f0 + 0x6bc);
    (*pcVar11)(uVar4,0x32);
    uVar4 = (*(code *)(long)(DAT_ffffffffbfc436f0 + 0x690))(uVar2,uVar1);
    (*pcVar11)(uVar4,0x40);
    iVar5 = DAT_ffffffffbfc436f0;
  }
  else {
    if (*(long *)(piVar12 + 2) != 100) {
      pcVar11 = (code *)(long)(DAT_ffffffffbfc436f0 + 0x6bc);
      uVar4 = (*(code *)(long)(DAT_ffffffffbfc436f0 + 0x664))(uVar2,uVar1);
      (*pcVar11)(uVar4,1);
      uVar4 = (*(code *)(long)(iVar5 + 0x690))(uVar2,uVar1);
      (*pcVar11)(uVar4,0x200);
      uVar1 = (*(code *)(long)(iVar5 + 0x638))(uVar2,uVar1);
      uVar2 = 0x2000;
      goto LAB_ffffffffbfc30aec;
    }
    pcVar11 = (code *)(long)(DAT_ffffffffbfc436f0 + 0x6bc);
    uVar4 = (*(code *)(long)(DAT_ffffffffbfc436f0 + 0x664))(uVar2,uVar1);
    (*pcVar11)(uVar4,5);
    uVar4 = (*(code *)(long)(iVar5 + 0x690))(uVar2,uVar1);
    (*pcVar11)(uVar4,0x40);
  }
  uVar1 = (*(code *)(long)(iVar5 + 0x638))(uVar2,uVar1);
  uVar2 = 0;
LAB_ffffffffbfc30aec:
  (*pcVar11)(uVar1,uVar2);
  pcVar11 = (code *)(long)(DAT_ffffffffbfc436f0 + 0x6bc);
  (*pcVar11)(puVar3,uVar9 & 0xfffffffffffffffe);
  (*pcVar11)(puVar10,*puVar10 | (long)piVar12[1]);
  (*pcVar11)(puVar3,uVar9);
  return 0;
}

