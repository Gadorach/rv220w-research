/*
 * Ghidra reconstructed C; not original Cisco source.
 * RV220W boot-chain/U-Boot analysis v1.1.0
 * Entry: ffffffffbfc29f58
 * Function: bcm53115_pseudophy_read
 * Subsystem: bcm53115-switch
 *
 * RV220W BOOT-CHAIN / U-BOOT SEMANTIC ANNOTATION v1.1.0
 * Region: early-boot-and-board-support
 * Subsystem: bcm53115-switch
 * Evidence: address/string/register/call evidence
 * Confidence: high for listed hardware facts; medium for inferred types
 * Interpretation: Broadcom pseudo-PHY read at MDIO address 0x1e: page register 0x10, command/address register 0x11, data window 0x18-0x1b, read opcode 2, busy polling with timeout.
 * Safety: reconstructed pseudocode is not original Cisco source. Do not replay flash, GPIO, MDIO or switch writes without readback and recovery safeguards.
 * 
 * Prior/recovered evidence:
 * RV220W BOOT-CHAIN / U-BOOT SEMANTIC ANNOTATION v1.1.0
 * Region: early-boot-and-board-support
 * Subsystem: bcm53115-switch
 * Evidence: address/string/register/call evidence
 * Confidence: high for listed hardware facts; medium for inferred types
 * Interpretation: Broadcom pseudo-PHY read at MDIO address 0x1e: page register 0x10, command/address register 0x11, data window 0x18-0x1b, read opcode 2, busy polling with timeout.
 * Safety: reconstructed pseudocode is not original Cisco source. Do not replay flash, GPIO, MDIO or switch writes without readback and recovery safeguards.
 * 
 * Prior/recovered evidence:
 * RV220W BOOT-CHAIN / U-BOOT SEMANTIC ANNOTATION v1.1.0
 * Region: early-boot-and-board-support
 * Subsystem: bootloader-support
 * Evidence: Ghidra control-flow/GOT recovery
 * Confidence: medium for boundary; low for original name
 * Interpretation: Broadcom pseudo-PHY read at MDIO address 0x1e: page register 0x10, command/address register 0x11, data window 0x18-0x1b, read opcode 2, busy polling with timeout.
 * Safety: reconstructed pseudocode is not original Cisco source. Do not replay flash, GPIO, MDIO or switch writes without readback and recovery safeguards.
 */

/* RV220W BOOT-CHAIN / U-BOOT SEMANTIC ANNOTATION v1.1.0
   Region: early-boot-and-board-support
   Subsystem: bcm53115-switch
   Evidence: address/string/register/call evidence
   Confidence: high for listed hardware facts; medium for inferred types
   Interpretation: Broadcom pseudo-PHY read at MDIO address 0x1e: page register 0x10,
   command/address register 0x11, data window 0x18-0x1b, read opcode 2, busy polling with timeout.
   Safety: reconstructed pseudocode is not original Cisco source. Do not replay flash, GPIO, MDIO or
   switch writes without readback and recovery safeguards.
   
   Prior/recovered evidence:
   RV220W BOOT-CHAIN / U-BOOT SEMANTIC ANNOTATION v1.1.0
   Region: early-boot-and-board-support
   Subsystem: bcm53115-switch
   Evidence: address/string/register/call evidence
   Confidence: high for listed hardware facts; medium for inferred types
   Interpretation: Broadcom pseudo-PHY read at MDIO address 0x1e: page register 0x10,
   command/address register 0x11, data window 0x18-0x1b, read opcode 2, busy polling with timeout.
   Safety: reconstructed pseudocode is not original Cisco source. Do not replay flash, GPIO, MDIO or
   switch writes without readback and recovery safeguards.
   
   Prior/recovered evidence:
   RV220W BOOT-CHAIN / U-BOOT SEMANTIC ANNOTATION v1.1.0
   Region: early-boot-and-board-support
   Subsystem: bootloader-support
   Evidence: Ghidra control-flow/GOT recovery
   Confidence: medium for boundary; low for original name
   Interpretation: Broadcom pseudo-PHY read at MDIO address 0x1e: page register 0x10,
   command/address register 0x11, data window 0x18-0x1b, read opcode 2, busy polling with timeout.
   Safety: reconstructed pseudocode is not original Cisco source. Do not replay flash, GPIO, MDIO or
   switch writes without readback and recovery safeguards. */

uint bcm53115_pseudophy_read(undefined8 param_1,undefined8 param_2)

{
  long lVar1;
  ulong uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  undefined8 unaff_s0;
  undefined8 unaff_s1;
  undefined8 unaff_s2;
  undefined8 unaff_s3;
  uint uVar7;
  code *pcVar8;
  undefined8 *puVar9;
  undefined8 in_ra;
  
  puVar9 = (undefined8 *)(long)((int)&stack0x00000000 + -0x30);
  puVar9[4] = &_gp;
  puVar9[3] = unaff_s3;
  uVar7 = (int)param_1 << 8;
  pcVar8 = (code *)(long)DAT_ffffffffbfc43b2c;
  puVar9[5] = in_ra;
  puVar9[2] = unaff_s2;
  puVar9[1] = unaff_s1;
  *puVar9 = unaff_s0;
  (*pcVar8)(0x1e,0x10,uVar7 & 0xff01 | 1);
  (*(code *)(long)DAT_ffffffffbfc43b2c)(0x1e,0x11,((uint)param_2 & 0xff) << 8 | 2);
  lVar1 = (*(code *)(long)DAT_ffffffffbfc43b98)();
  do {
    uVar2 = (*(code *)(long)DAT_ffffffffbfc438e0)(0x1e,0x11);
    if ((uVar2 & 3) == 0) break;
    uVar2 = (*(code *)(long)DAT_ffffffffbfc43b98)();
  } while (uVar2 <= lVar1 + 40000000U);
  uVar2 = (*(code *)(long)DAT_ffffffffbfc43b98)();
  if (lVar1 + 40000000U < uVar2) {
    (*(code *)(long)DAT_ffffffffbfc4400c)(DAT_ffffffffbfc436f4 + 0x1780,param_1,param_2);
  }
  uVar3 = (*(code *)(long)DAT_ffffffffbfc438e0)(0x1e,0x18);
  iVar4 = (*(code *)(long)DAT_ffffffffbfc438e0)(0x1e,0x19);
  uVar5 = (*(code *)(long)DAT_ffffffffbfc438e0)(0x1e,0x1a);
  iVar6 = (*(code *)(long)DAT_ffffffffbfc438e0)(0x1e,0x1b);
  (*(code *)(long)DAT_ffffffffbfc43b2c)(0x1e,0x10,uVar7 & 0xff00);
  return uVar3 & 0xffff | iVar4 << 0x10 | iVar6 << 0x10 | uVar5 & 0xffff;
}

