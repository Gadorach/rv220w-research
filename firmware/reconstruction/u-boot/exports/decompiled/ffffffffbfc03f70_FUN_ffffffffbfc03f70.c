/*
 * Ghidra reconstructed C; not original Cisco source.
 * RV220W boot-chain/U-Boot analysis v1.1.0
 * Entry: ffffffffbfc03f70
 * Function: FUN_ffffffffbfc03f70
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

uint FUN_ffffffffbfc03f70(uint param_1)

{
  bool bVar1;
  int iVar2;
  uint uVar4;
  uint uVar5;
  ulong uVar3;
  uint uVar7;
  long lVar6;
  undefined8 unaff_s0;
  undefined8 unaff_s1;
  int iVar8;
  undefined8 unaff_s2;
  uint uVar9;
  code *pcVar10;
  undefined8 *puVar11;
  undefined8 in_ra;
  undefined8 in_HW_RESIM31;
  
  puVar11 = (undefined8 *)(long)((int)&stack0x00000000 + -0x30);
  puVar11[3] = &_gp;
  puVar11[4] = in_ra;
  puVar11[1] = unaff_s1;
  pcVar10 = (code *)(long)DAT_ffffffffbfc43ef8;
  *puVar11 = unaff_s0;
  puVar11[2] = unaff_s2;
  uVar4 = (*pcVar10)();
  uVar5 = (*(code *)(long)DAT_ffffffffbfc43738)();
  uVar7 = param_1 & uVar5;
  uVar9 = uVar7 & uVar4;
  if (uVar7 == param_1) {
    if (uVar9 != uVar7) {
      (*(code *)(long)DAT_ffffffffbfc4400c)(DAT_ffffffffbfc436f0 + 0x7d90,uVar9,uVar4);
    }
    iVar2 = DAT_ffffffffbfc436f0;
    if ((uVar9 & ~*(uint *)(long)DAT_ffffffffbfc43bac) != 0) {
      iVar8 = 5;
      (*(code *)(long)DAT_ffffffffbfc4400c)(DAT_ffffffffbfc436f0 + 0x7dd8);
      (*(code *)(long)DAT_ffffffffbfc4400c)(iVar2 + 0x7dd8);
      (*(code *)(long)DAT_ffffffffbfc4400c)(iVar2 + 0x7dd8);
      (*(code *)(long)DAT_ffffffffbfc4400c)(iVar2 + 0x7dd8);
      (*(code *)(long)DAT_ffffffffbfc4400c)(iVar2 + 0x7dd8);
      (*(code *)(long)DAT_ffffffffbfc4400c)(iVar2 + 0x7dd8);
      (*(code *)(long)DAT_ffffffffbfc4400c)(iVar2 + 0x7dd8);
      (*(code *)(long)DAT_ffffffffbfc4400c)(DAT_ffffffffbfc436f0 + 0x7de8);
      (*(code *)(long)DAT_ffffffffbfc4400c)(DAT_ffffffffbfc436f0 + 0x7e48);
      (*(code *)(long)DAT_ffffffffbfc4400c)(iVar2 + 0x7dd8);
      (*(code *)(long)DAT_ffffffffbfc4400c)(iVar2 + 0x7dd8);
      (*(code *)(long)DAT_ffffffffbfc4400c)(iVar2 + 0x7dd8);
      (*(code *)(long)DAT_ffffffffbfc4400c)(iVar2 + 0x7dd8);
      (*(code *)(long)DAT_ffffffffbfc4400c)(iVar2 + 0x7dd8);
      (*(code *)(long)DAT_ffffffffbfc4400c)(iVar2 + 0x7dd8);
      (*(code *)(long)DAT_ffffffffbfc4400c)(iVar2 + 0x7dd8);
      do {
        (*(code *)(long)DAT_ffffffffbfc4400c)(DAT_ffffffffbfc436f4 + -0x48a8,iVar8);
        lVar6 = getHWRegister(in_HW_RESIM31);
        do {
          uVar3 = getHWRegister(in_HW_RESIM31);
        } while (uVar3 < lVar6 + 600000000U);
        bVar1 = iVar8 != 0;
        iVar8 = iVar8 + -1;
      } while (bVar1);
    }
  }
  else {
    (*(code *)(long)DAT_ffffffffbfc4400c)(DAT_ffffffffbfc436f0 + 0x7d48,uVar5);
    uVar9 = 0xffffffff;
  }
  return uVar9;
}

