/*
 * Ghidra reconstructed C; not original Cisco source.
 * RV220W boot-chain/U-Boot analysis v1.1.0
 * Entry: ffffffffbfc0dfe8
 * Function: FUN_ffffffffbfc0dfe8
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

void FUN_ffffffffbfc0dfe8(void)

{
  int *piVar1;
  ulong uVar2;
  int iVar3;
  long lVar4;
  undefined8 unaff_s0;
  uint uVar5;
  undefined8 unaff_s1;
  long lVar6;
  undefined8 unaff_s2;
  uint *puVar8;
  undefined8 unaff_s3;
  undefined8 unaff_s4;
  int *piVar9;
  undefined8 unaff_s5;
  code *pcVar10;
  undefined8 *puVar11;
  undefined8 in_ra;
  int iVar7;
  
  puVar11 = (undefined8 *)(long)((int)&stack0x00000000 + -0x40);
  puVar11[6] = &_gp;
  puVar11[4] = unaff_s4;
  puVar11[7] = in_ra;
  piVar1 = (int *)(long)DAT_ffffffffbfc43d74;
  iVar7 = *piVar1;
  pcVar10 = (code *)(long)DAT_ffffffffbfc4400c;
  iVar3 = DAT_ffffffffbfc436f4 + -0x5a50;
  piVar9 = (int *)(long)DAT_ffffffffbfc43904;
  puVar11[5] = unaff_s5;
  puVar11[3] = unaff_s3;
  puVar11[2] = unaff_s2;
  puVar11[1] = unaff_s1;
  *puVar11 = unaff_s0;
  *piVar1 = iVar7 + 1;
  (*pcVar10)(iVar3);
  iVar7 = *piVar9;
  puVar8 = (uint *)(long)DAT_ffffffffbfc43af4;
  (*(code *)(long)DAT_ffffffffbfc43a54)(iVar7,0,0x5ee);
  iVar3 = (*(code *)(long)DAT_ffffffffbfc43cf8)(iVar7,DAT_ffffffffbfc43e14,0x800);
  pcVar10 = (code *)(long)DAT_ffffffffbfc43d0c;
  iVar7 = iVar7 + iVar3;
  lVar6 = (long)iVar7;
  *(undefined4 *)(lVar6 + 0x1c) = 0x1010600;
  uVar2 = (*pcVar10)(0);
  pcVar10 = (code *)(long)(DAT_ffffffffbfc436fc + -0x2094);
  *(short *)((long)(iVar7 + 0x1c) + 8) = (short)(uVar2 / 500000000);
  (*pcVar10)(iVar7 + 0x28,0);
  (*pcVar10)(iVar7 + 0x2c,0);
  (*pcVar10)(iVar7 + 0x30,0);
  (*pcVar10)(iVar7 + 0x34,0);
  (*(code *)(long)DAT_ffffffffbfc43e84)(iVar7 + 0x38,DAT_ffffffffbfc43fa8,6);
  (*(code *)(long)DAT_ffffffffbfc43fe4)(iVar7 + 0x88,DAT_ffffffffbfc43d3c,0x80);
  *(undefined1 *)(lVar6 + 0x109) = 0x82;
  *(undefined1 *)(lVar6 + 0x10a) = 0x53;
  *(undefined1 *)(lVar6 + 0x10c) = 1;
  *(undefined1 *)(lVar6 + 0x112) = 3;
  *(undefined1 *)(lVar6 + 0x118) = 0xc;
  *(undefined1 *)(lVar6 + 0x13a) = 0x11;
  lVar4 = (long)DAT_ffffffffbfc43fa8;
  *(undefined1 *)(lVar6 + 0x10b) = 99;
  *(undefined1 *)(lVar6 + 0x108) = 99;
  *(undefined1 *)(lVar6 + 0x113) = 4;
  *(undefined1 *)(lVar6 + 0x13b) = 0x20;
  *(undefined1 *)(lVar6 + 0x15c) = 0xff;
  *(undefined1 *)(lVar6 + 0x10d) = 4;
  *(undefined1 *)(lVar6 + 0x119) = 0x20;
  pcVar10 = (code *)(long)DAT_ffffffffbfc43d0c;
  uVar5 = (uint)*(byte *)(lVar4 + 4) << 8 |
          (uint)*(byte *)(lVar4 + 2) << 0x18 | (uint)*(byte *)(lVar4 + 3) << 0x10 |
          (uint)*(byte *)(lVar4 + 5);
  *puVar8 = uVar5;
  iVar3 = (*pcVar10)(0);
  pcVar10 = (code *)(long)DAT_ffffffffbfc43e84;
  *puVar8 = uVar5 + iVar3;
  (*pcVar10)(iVar7 + 0x20,puVar8,4);
  (*(code *)(long)DAT_ffffffffbfc43a4c)(lVar6,0xffffffffffffffff,0x43,0x44,0x141);
  (*(code *)(long)DAT_ffffffffbfc43fec)(1500000000,DAT_ffffffffbfc436fc + -0x1a18);
  (*(code *)(long)DAT_ffffffffbfc4388c)(DAT_ffffffffbfc436fc + -0x1d9c);
  (*(code *)(long)DAT_ffffffffbfc437e0)(*piVar9,0x16b);
  return;
}

