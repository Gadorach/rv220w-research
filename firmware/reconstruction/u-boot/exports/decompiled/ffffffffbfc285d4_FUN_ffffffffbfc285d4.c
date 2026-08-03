/*
 * Ghidra reconstructed C; not original Cisco source.
 * RV220W boot-chain/U-Boot analysis v1.1.0
 * Entry: ffffffffbfc285d4
 * Function: FUN_ffffffffbfc285d4
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

void FUN_ffffffffbfc285d4(byte *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  byte *pbVar4;
  byte bVar5;
  undefined8 unaff_s0;
  undefined8 unaff_s1;
  code *pcVar6;
  undefined8 unaff_s2;
  undefined8 uVar7;
  undefined8 *puVar8;
  undefined8 in_ra;
  
  puVar8 = (undefined8 *)(long)((int)&stack0x00000000 + -0x30);
  puVar8[3] = &_gp;
  puVar8[2] = unaff_s2;
  *puVar8 = unaff_s0;
  puVar8[4] = in_ra;
  puVar8[1] = unaff_s1;
  uVar7 = 0;
  pbVar4 = param_1;
  while( true ) {
    if ((ulong)*pbVar4 == 0) break;
    uVar7 = special2(uVar7,(ulong)*pbVar4,0,0x28);
    pbVar4 = (byte *)(long)((int)pbVar4 + 1);
  }
  if (0x800 < (uint)((int)pbVar4 - (int)param_1)) {
    (*(code *)(long)DAT_ffffffffbfc4400c)(DAT_ffffffffbfc436f4 + 0x15b8);
  }
  bVar5 = 0x24;
  iVar1 = DAT_ffffffffbfc436f0;
  do {
    iVar3 = DAT_ffffffffbfc436f0;
    (*(code *)(long)(iVar1 + -0x7d28))(bVar5);
    iVar2 = DAT_ffffffffbfc436f0;
    bVar5 = *param_1;
    param_1 = (byte *)(long)((int)param_1 + 1);
    iVar1 = iVar3;
  } while (bVar5 != 0);
  pcVar6 = (code *)(long)(iVar3 + -0x7d28);
  (*pcVar6)(0x23);
  (*pcVar6)(*(undefined1 *)(long)(int)(((uint)uVar7 >> 4) + iVar2 + 0x6ac0));
  (*pcVar6)(*(undefined1 *)(long)(int)(((uint)uVar7 & 0xf) + iVar2 + 0x6ac0));
  return;
}

