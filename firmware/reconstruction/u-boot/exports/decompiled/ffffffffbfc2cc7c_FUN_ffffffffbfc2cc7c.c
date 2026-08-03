/*
 * Ghidra reconstructed C; not original Cisco source.
 * RV220W boot-chain/U-Boot analysis v1.1.0
 * Entry: ffffffffbfc2cc7c
 * Function: FUN_ffffffffbfc2cc7c
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

void FUN_ffffffffbfc2cc7c(void)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar4;
  uint *puVar3;
  ulong uVar5;
  ulong uVar6;
  undefined8 unaff_s0;
  long lVar7;
  undefined8 unaff_s1;
  undefined8 unaff_s2;
  code *pcVar8;
  undefined8 *puVar9;
  undefined8 in_ra;
  
  puVar9 = (undefined8 *)(long)((int)&stack0x00000000 + -0x30);
  puVar9[3] = &_gp;
  *puVar9 = unaff_s0;
  puVar9[4] = in_ra;
  iVar2 = DAT_ffffffffbfc436f4;
  lVar7 = (long)DAT_ffffffffbfc43d14;
  pcVar8 = (code *)(long)DAT_ffffffffbfc4400c;
  *(int *)(lVar7 + 0x114) = DAT_ffffffffbfc436f4 + 0x6220;
  *(undefined4 *)(lVar7 + 8) = 0xff;
  puVar9[2] = unaff_s2;
  puVar9[1] = unaff_s1;
  *(undefined4 *)(lVar7 + 4) = 0;
  (*pcVar8)(iVar2 + 0x1d08);
  (*(code *)(long)DAT_ffffffffbfc43cc0)();
  (*(code *)(long)(DAT_ffffffffbfc436f0 + -0x3f88))(0x80011f0000000028,0x500000000);
  *(undefined4 *)(lVar7 + 0x20) = 1;
  pcVar8 = (code *)(long)DAT_ffffffffbfc43a68;
  *(undefined4 *)(lVar7 + 0x24) = DAT_ffffffffbfc43ca4;
  uVar4 = DAT_ffffffffbfc43e90;
  *(undefined4 *)(lVar7 + 0x3c) = 0x80000000;
  *(undefined4 *)(lVar7 + 0x28) = uVar4;
  uVar4 = DAT_ffffffffbfc43a14;
  *(undefined4 *)(lVar7 + 0x38) = 0x80000000;
  *(undefined4 *)(lVar7 + 0x2c) = uVar4;
  uVar4 = DAT_ffffffffbfc4384c;
  *(undefined4 *)(lVar7 + 0x18) = 0x1000;
  *(undefined4 *)(lVar7 + 0x30) = uVar4;
  *(undefined4 *)(lVar7 + 0x40) = 0x40000000;
  iVar2 = DAT_ffffffffbfc437b4;
  *(undefined4 *)(lVar7 + 0x14) = 0x1000;
  *(int *)(lVar7 + 0x48) = iVar2;
  uVar4 = DAT_ffffffffbfc43754;
  *(undefined4 *)(lVar7 + 0x1c) = 0x8000000;
  *(undefined4 *)(lVar7 + 0x4c) = uVar4;
  uVar4 = DAT_ffffffffbfc43ba0;
  *(undefined4 *)(lVar7 + 0x44) = 0;
  *(undefined4 *)(lVar7 + 0x50) = uVar4;
  *(undefined4 *)(lVar7 + 0x54) = DAT_ffffffffbfc44050;
  *(undefined4 *)(lVar7 + 0x110) = 3;
  *(int *)(lVar7 + 0x11c) = DAT_ffffffffbfc436f0 + -0x3e94;
  *(int *)(lVar7 + 0x120) = DAT_ffffffffbfc436f0 + -0x3e38;
  *(int *)(lVar7 + 0x124) = DAT_ffffffffbfc436f0 + -0x3ddc;
  *(int *)(lVar7 + 0x128) = DAT_ffffffffbfc436f0 + -0x3844;
  *(int *)(lVar7 + 300) = DAT_ffffffffbfc436f0 + -0x388c;
  *(int *)(lVar7 + 0x130) = DAT_ffffffffbfc436f0 + -0x38d0;
  (*pcVar8)(lVar7);
  uVar4 = (*(code *)(long)DAT_ffffffffbfc43afc)(lVar7);
  *(undefined4 *)(lVar7 + 8) = uVar4;
  uVar1 = _DAT_80011f000000181c;
  *(undefined4 *)(lVar7 + 100) = 0x8000000;
  *(undefined4 *)(lVar7 + 0x78) = 0;
  *(uint *)(lVar7 + 0x5c) = uVar1 & 0xfffffff0;
  *(undefined4 *)(lVar7 + 0x68) = 0x101;
  *(undefined4 *)(lVar7 + 0x60) = 0;
  *(undefined4 *)(lVar7 + 0x6c) = 0;
  *(undefined4 *)(lVar7 + 0x70) = 0;
  *(undefined4 *)(lVar7 + 0x74) = 0;
  uVar5 = ((ulong)(long)_DAT_80011f0000001814 >> 4 & 0xfffffff) << 4;
  puVar3 = (uint *)(*(code *)(long)DAT_ffffffffbfc4400c)
                             (DAT_ffffffffbfc436f4 + 0x1d18,
                              uVar5 | (long)_DAT_80011f0000001810 << 0x20,0,
                              ((ulong)(long)(int)_DAT_80011f000000181c >> 4 & 0xfffffff) << 4 |
                              (long)_DAT_80011f0000001818 << 0x20);
  uVar6 = 0;
  special2(0,puVar3,2,0x32);
  do {
    puVar3 = (uint *)((ulong)(puVar3 + -0x1fffb83ffffffbc0) ^ 4);
    *puVar3 = (uint)((uVar6 & 0x3ff) << 4) | 0xb;
    uVar6 = (ulong)((int)uVar6 + 1);
    special2(uVar6,puVar3,2,0x32);
  } while (uVar6 != 0x20);
  (*(code *)(long)DAT_ffffffffbfc437b4)((int)uVar5 + 0x80);
  return;
}

