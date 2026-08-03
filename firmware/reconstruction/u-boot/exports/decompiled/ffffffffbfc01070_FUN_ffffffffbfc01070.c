/*
 * Ghidra reconstructed C; not original Cisco source.
 * RV220W boot-chain/U-Boot analysis v1.1.0
 * Entry: ffffffffbfc01070
 * Function: FUN_ffffffffbfc01070
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

void FUN_ffffffffbfc01070(void)

{
  long lVar1;
  uint uVar2;
  uint uVar3;
  undefined8 uVar4;
  undefined8 unaff_s0;
  int *piVar5;
  uint uVar6;
  undefined8 unaff_s1;
  undefined4 *puVar7;
  undefined8 unaff_s2;
  undefined8 unaff_s3;
  code *pcVar8;
  int *piVar9;
  long lVar10;
  undefined8 in_ra;
  int iVar11;
  
  iVar11 = (int)&stack0x00000000 + -0xc0;
  lVar10 = (long)iVar11;
  *(undefined1 **)(lVar10 + 0xb0) = &_gp;
  *(undefined8 *)(lVar10 + 0xb8) = in_ra;
  *(undefined8 *)(lVar10 + 0xa8) = unaff_s3;
  *(undefined8 *)(lVar10 + 0xa0) = unaff_s2;
  *(undefined8 *)(lVar10 + 0x98) = unaff_s1;
  *(undefined8 *)(lVar10 + 0x90) = unaff_s0;
  piVar9 = (int *)(long)iVar11;
  (*(code *)(long)DAT_ffffffffbfc43a54)(piVar9,0,0x88);
  iVar11 = DAT_ffffffffbfc436ec + 0xa00;
  lVar1 = (*(code *)(long)iVar11)(0xd0001);
  if (lVar1 == 0) {
    lVar1 = (*(code *)(long)iVar11)(0x30d0100);
    if (lVar1 == 0) {
      (*(code *)(long)(DAT_ffffffffbfc436ec + 0xb78))(0x8001070000000738,1);
    }
  }
  lVar1 = (*(code *)(long)(DAT_ffffffffbfc436ec + 0xa00))(0xd0308);
  if (lVar1 != 0) {
    (*(code *)(long)(DAT_ffffffffbfc436ec + 0xb78))(0x8001180000001550,2);
  }
  piVar5 = (int *)(long)DAT_ffffffffbfc43df8;
  while ((code *)(long)*piVar5 != (code *)0x0) {
    lVar1 = (*(code *)(long)*piVar5)(2);
    iVar11 = (int)piVar5;
    piVar5 = (int *)(long)(iVar11 + 4);
    if (lVar1 != 0) {
      piVar5 = (int *)(long)iVar11;
      (*(code *)(long)DAT_ffffffffbfc4400c)(DAT_ffffffffbfc436f0 + 0x6db8);
      (*(code *)(long)DAT_ffffffffbfc43f2c)();
    }
  }
  (*(code *)(long)DAT_ffffffffbfc438fc)(2,0);
  if (*(ulong *)(piVar9 + 4) < 0x100000) {
    uVar3 = (int)*(undefined8 *)(piVar9 + 4) + 0x80000000;
  }
  else {
    uVar3 = 0x80100000;
  }
  uVar2 = DAT_ffffffffbfc43cd0 + 0x40400000;
  pcVar8 = (code *)(long)DAT_ffffffffbfc43e84;
  if (uVar2 < 0x80000) {
    uVar2 = 0x80000;
  }
  uVar6 = (uVar3 & 0xfffff000) - uVar2 & 0xffff0000;
  piVar5 = (int *)(long)(int)(uVar6 - 0x30034);
  puVar7 = (undefined4 *)((long)(int)(uVar6 - 0x340cc) & 0xfffffffffffffff0);
  *piVar9 = uVar6 - 0x30034;
  uVar4 = *(undefined8 *)(piVar9 + 4);
  uVar2 = (int)puVar7 - 0x4000U & 0xffffc000;
  piVar5[0xc] = uVar3 - uVar2;
  piVar5[5] = uVar6 - 0x340bc;
  piVar5[6] = -0x80000000;
  piVar5[7] = (int)uVar4;
  piVar5[0xb] = uVar2;
  iVar11 = piVar9[2];
  *puVar7 = 0;
  puVar7[-1] = 0;
  *piVar5 = iVar11;
  (*pcVar8)(uVar6 - 0x300bc,piVar9,0x88);
  (*(code *)(long)DAT_ffffffffbfc43ed8)(puVar7,uVar6 - 0x300bc,uVar6);
  return;
}

