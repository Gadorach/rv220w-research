/*
 * Ghidra reconstructed C; not original Cisco source.
 * RV220W boot-chain/U-Boot analysis v1.1.0
 * Entry: ffffffffbfc03b10
 * Function: FUN_ffffffffbfc03b10
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

void FUN_ffffffffbfc03b10(undefined8 param_1)

{
  ulong uVar1;
  ulong uVar2;
  long lVar3;
  ulong uVar4;
  ulong in_v0;
  int iVar5;
  ulong unaff_s0;
  code *pcVar6;
  ulong *puVar7;
  ulong in_ra;
  
  puVar7 = (ulong *)(long)((int)&stack0x00000000 + -0x30);
  puVar7[3] = (ulong)&_gp;
  puVar7[4] = in_ra;
  pcVar6 = (code *)(long)DAT_ffffffffbfc43a54;
  uVar2 = (long)DAT_ffffffffbfc436f0 + 0x6140U & 7;
  lVar3 = *(long *)(((long)DAT_ffffffffbfc436f0 + 0x6140U) - uVar2);
  iVar5 = DAT_ffffffffbfc436f0 + 0x6140;
  puVar7[2] = unaff_s0;
  uVar1 = (long)iVar5 + 7;
  uVar4 = uVar1 & 7;
  *puVar7 = (lVar3 << uVar2 * 8 | in_v0 & 0xffffffffffffffffU >> (8 - uVar2) * 8) &
            -1L << (uVar4 + 1) * 8 | *(ulong *)(uVar1 - uVar4) >> (7 - uVar4) * 8;
  (*pcVar6)(param_1,0,0x800);
  (*(code *)(long)DAT_ffffffffbfc43e84)(param_1,puVar7,8);
  iVar5 = (int)param_1;
  (*(code *)(long)DAT_ffffffffbfc43e84)(iVar5 + 0x80,puVar7,8);
  (*(code *)(long)DAT_ffffffffbfc43e84)(iVar5 + 0x100,puVar7,8);
  (*(code *)(long)DAT_ffffffffbfc43e84)(iVar5 + 0x180,puVar7,8);
  (*(code *)(long)DAT_ffffffffbfc43e84)(iVar5 + 0x200,puVar7,8);
  (*(code *)(long)DAT_ffffffffbfc43e84)(iVar5 + 0x280,puVar7,8);
  (*(code *)(long)DAT_ffffffffbfc43e84)(iVar5 + 0x300,puVar7,8);
  (*(code *)(long)DAT_ffffffffbfc43e84)(iVar5 + 0x380,puVar7,8);
  (*(code *)(long)DAT_ffffffffbfc43e84)(iVar5 + 0x400,puVar7,8);
  (*(code *)(long)DAT_ffffffffbfc43e84)(iVar5 + 0x480,puVar7,8);
  (*(code *)(long)DAT_ffffffffbfc43e84)(iVar5 + 0x500,puVar7,8);
  (*(code *)(long)DAT_ffffffffbfc43e84)(iVar5 + 0x580,puVar7,8);
  (*(code *)(long)DAT_ffffffffbfc43e84)(iVar5 + 0x600,puVar7,8);
  (*(code *)(long)DAT_ffffffffbfc43e84)(iVar5 + 0x680,puVar7,8);
  return;
}

