/*
 * Ghidra reconstructed C; not original Cisco source.
 * RV220W boot-chain/U-Boot analysis v1.1.0
 * Entry: ffffffffbfc0d7c0
 * Function: FUN_ffffffffbfc0d7c0
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

void FUN_ffffffffbfc0d7c0(void)

{
  ushort uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  undefined8 uVar6;
  char *pcVar7;
  ulong uVar8;
  undefined8 unaff_s0;
  uint *puVar9;
  ushort *puVar10;
  undefined8 unaff_s1;
  long lVar11;
  int *piVar12;
  undefined8 unaff_s2;
  uint *puVar13;
  code *pcVar14;
  undefined8 *puVar15;
  undefined8 in_ra;
  
  puVar15 = (undefined8 *)(long)((int)&stack0x00000000 + -0x30);
  puVar15[3] = &_gp;
  puVar15[1] = unaff_s1;
  puVar15[4] = in_ra;
  iVar4 = DAT_ffffffffbfc43d3c;
  pcVar7 = (char *)(long)DAT_ffffffffbfc43d3c;
  puVar15[2] = unaff_s2;
  *puVar15 = unaff_s0;
  iVar3 = DAT_ffffffffbfc436f4;
  lVar11 = (long)DAT_ffffffffbfc436f4;
  if (*pcVar7 == '\0') {
    uVar8 = (ulong)(int)*(uint *)(long)DAT_ffffffffbfc43f80;
    (*(code *)(long)DAT_ffffffffbfc439a4)
              (DAT_ffffffffbfc436f4 + 0x4a50,DAT_ffffffffbfc436f4 + -0x5c30,uVar8 & 0xff,
               uVar8 >> 8 & 0xff,uVar8 >> 0x10 & 0xff,*(uint *)(long)DAT_ffffffffbfc43f80 >> 0x18);
    iVar4 = DAT_ffffffffbfc436f4;
    pcVar14 = (code *)(long)DAT_ffffffffbfc4400c;
    *(int *)(lVar11 + 0x4a60) = iVar3 + 0x4a50;
    (*pcVar14)(iVar4 + -0x5c10,iVar3 + 0x4a50);
  }
  else {
    *(int *)(lVar11 + 0x4a60) = iVar4;
  }
  puVar13 = (uint *)(long)DAT_ffffffffbfc43f00;
  uVar6 = (*(code *)(long)DAT_ffffffffbfc43800)();
  puVar9 = (uint *)(long)DAT_ffffffffbfc43f80;
  (*(code *)(long)DAT_ffffffffbfc4400c)(DAT_ffffffffbfc436f4 + -0x5be0,uVar6);
  piVar12 = (int *)(long)DAT_ffffffffbfc43a90;
  (*(code *)(long)DAT_ffffffffbfc43e38)(DAT_ffffffffbfc436f4 + -0x5bc8);
  (*(code *)(long)DAT_ffffffffbfc43d68)(*puVar13);
  (*(code *)(long)DAT_ffffffffbfc43e38)(DAT_ffffffffbfc436f4 + -0x5bb0);
  (*(code *)(long)DAT_ffffffffbfc43d68)(*puVar9);
  pcVar14 = (code *)(long)DAT_ffffffffbfc439f0;
  if (*piVar12 != 0) {
    uVar2 = *(uint *)(long)DAT_ffffffffbfc43c58;
    if (uVar2 != 0) {
      if ((uVar2 & *puVar9) != (uVar2 & *puVar13)) {
        (*(code *)(long)DAT_ffffffffbfc43e38)(DAT_ffffffffbfc436f4 + -0x5b98);
        (*(code *)(long)DAT_ffffffffbfc43d68)(*piVar12);
      }
      pcVar14 = (code *)(long)DAT_ffffffffbfc439f0;
    }
  }
  puVar10 = (ushort *)(long)DAT_ffffffffbfc43c54;
  (*pcVar14)(10);
  (*(code *)(long)DAT_ffffffffbfc4400c)
            (DAT_ffffffffbfc436f4 + -0x5b78,*(undefined4 *)((long)DAT_ffffffffbfc436f4 + 0x4a60));
  uVar1 = *puVar10;
  if (uVar1 != 0) {
    (*(code *)(long)DAT_ffffffffbfc4400c)(DAT_ffffffffbfc436f4 + -0x5b68,(uint)uVar1 << 9);
    (*(code *)(long)DAT_ffffffffbfc43a98)((uint)*puVar10 << 9,DAT_ffffffffbfc436f4 + -0x3ca8);
  }
  (*(code *)(long)DAT_ffffffffbfc439f0)(10);
  (*(code *)(long)DAT_ffffffffbfc4400c)
            (DAT_ffffffffbfc436f4 + -0x5c98,*(undefined4 *)(long)DAT_ffffffffbfc43c14);
  (*(code *)(long)DAT_ffffffffbfc43e38)(DAT_ffffffffbfc436f4 + -0x5c80);
  (*(code *)(long)DAT_ffffffffbfc43fec)(2500000000,DAT_ffffffffbfc436fc + -0x259c);
  (*(code *)(long)DAT_ffffffffbfc4388c)(DAT_ffffffffbfc436fc + -0x2504);
  pcVar14 = (code *)(long)DAT_ffffffffbfc43d0c;
  *(undefined4 *)((long)DAT_ffffffffbfc436f4 + 0x4a30) = 0x45;
  *(undefined4 *)((long)DAT_ffffffffbfc436f4 + 0x4a4c) = 1;
  *(undefined4 *)((long)DAT_ffffffffbfc436f4 + 19000) = 0;
  uVar8 = (*pcVar14)(0);
  pcVar14 = (code *)(long)DAT_ffffffffbfc43a54;
  *(undefined4 *)((long)DAT_ffffffffbfc436f4 + 0x4a3c) = 0;
  uVar5 = DAT_ffffffffbfc43ce0;
  *(int *)((long)DAT_ffffffffbfc436f4 + 0x4a34) = (int)uVar8 + (int)(uVar8 / 0xc00) * -0xc00 + 0x400
  ;
  (*pcVar14)(uVar5,0,6);
  (*(code *)(long)(DAT_ffffffffbfc436fc + -0x2a70))();
  return;
}

