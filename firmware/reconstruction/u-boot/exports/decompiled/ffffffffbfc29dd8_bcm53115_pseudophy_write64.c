/*
 * Ghidra reconstructed C; not original Cisco source.
 * RV220W boot-chain/U-Boot analysis v1.1.0
 * Entry: ffffffffbfc29dd8
 * Function: bcm53115_pseudophy_write64
 * Subsystem: bcm53115-switch
 *
 * RV220W BOOT-CHAIN / U-BOOT SEMANTIC ANNOTATION v1.1.0
 * Region: early-boot-and-board-support
 * Subsystem: bcm53115-switch
 * Evidence: address/string/register/call evidence
 * Confidence: high for listed hardware facts; medium for inferred types
 * Interpretation: Broadcom pseudo-PHY write at MDIO address 0x1e: page register 0x10, command/address register 0x11, data window 0x18-0x1b, write opcode 1, busy polling with timeout.
 * Safety: reconstructed pseudocode is not original Cisco source. Do not replay flash, GPIO, MDIO or switch writes without readback and recovery safeguards.
 * 
 * Prior/recovered evidence:
 * RV220W BOOT-CHAIN / U-BOOT SEMANTIC ANNOTATION v1.1.0
 * Region: early-boot-and-board-support
 * Subsystem: bcm53115-switch
 * Evidence: address/string/register/call evidence
 * Confidence: high for listed hardware facts; medium for inferred types
 * Interpretation: Broadcom pseudo-PHY write at MDIO address 0x1e: page register 0x10, command/address register 0x11, data window 0x18-0x1b, write opcode 1, busy polling with timeout.
 * Safety: reconstructed pseudocode is not original Cisco source. Do not replay flash, GPIO, MDIO or switch writes without readback and recovery safeguards.
 * 
 * Prior/recovered evidence:
 * RV220W BOOT-CHAIN / U-BOOT SEMANTIC ANNOTATION v1.1.0
 * Region: early-boot-and-board-support
 * Subsystem: bootloader-support
 * Evidence: Ghidra control-flow/GOT recovery
 * Confidence: medium for boundary; low for original name
 * Interpretation: Broadcom pseudo-PHY write at MDIO address 0x1e: page register 0x10, command/address register 0x11, data window 0x18-0x1b, write opcode 1, busy polling with timeout.
 * Safety: reconstructed pseudocode is not original Cisco source. Do not replay flash, GPIO, MDIO or switch writes without readback and recovery safeguards.
 */

/* RV220W BOOT-CHAIN / U-BOOT SEMANTIC ANNOTATION v1.1.0
   Region: early-boot-and-board-support
   Subsystem: bcm53115-switch
   Evidence: address/string/register/call evidence
   Confidence: high for listed hardware facts; medium for inferred types
   Interpretation: Broadcom pseudo-PHY write at MDIO address 0x1e: page register 0x10,
   command/address register 0x11, data window 0x18-0x1b, write opcode 1, busy polling with timeout.
   Safety: reconstructed pseudocode is not original Cisco source. Do not replay flash, GPIO, MDIO or
   switch writes without readback and recovery safeguards.
   
   Prior/recovered evidence:
   RV220W BOOT-CHAIN / U-BOOT SEMANTIC ANNOTATION v1.1.0
   Region: early-boot-and-board-support
   Subsystem: bcm53115-switch
   Evidence: address/string/register/call evidence
   Confidence: high for listed hardware facts; medium for inferred types
   Interpretation: Broadcom pseudo-PHY write at MDIO address 0x1e: page register 0x10,
   command/address register 0x11, data window 0x18-0x1b, write opcode 1, busy polling with timeout.
   Safety: reconstructed pseudocode is not original Cisco source. Do not replay flash, GPIO, MDIO or
   switch writes without readback and recovery safeguards.
   
   Prior/recovered evidence:
   RV220W BOOT-CHAIN / U-BOOT SEMANTIC ANNOTATION v1.1.0
   Region: early-boot-and-board-support
   Subsystem: bootloader-support
   Evidence: Ghidra control-flow/GOT recovery
   Confidence: medium for boundary; low for original name
   Interpretation: Broadcom pseudo-PHY write at MDIO address 0x1e: page register 0x10,
   command/address register 0x11, data window 0x18-0x1b, write opcode 1, busy polling with timeout.
   Safety: reconstructed pseudocode is not original Cisco source. Do not replay flash, GPIO, MDIO or
   switch writes without readback and recovery safeguards. */

void bcm53115_pseudophy_write64(undefined8 param_1,undefined8 param_2,ulong *param_3)

{
  long lVar1;
  ulong uVar2;
  undefined8 unaff_s0;
  undefined8 unaff_s1;
  undefined8 unaff_s2;
  undefined8 unaff_s3;
  undefined8 unaff_s4;
  uint uVar3;
  code *pcVar4;
  undefined8 *puVar5;
  undefined8 in_ra;
  
  puVar5 = (undefined8 *)(long)((int)&stack0x00000000 + -0x40);
  puVar5[5] = &_gp;
  puVar5[4] = unaff_s4;
  uVar3 = (int)param_1 << 8;
  pcVar4 = (code *)(long)DAT_ffffffffbfc43b2c;
  puVar5[1] = unaff_s1;
  puVar5[6] = in_ra;
  puVar5[3] = unaff_s3;
  puVar5[2] = unaff_s2;
  *puVar5 = unaff_s0;
  (*pcVar4)(0x1e,0x10,uVar3 & 0xff01 | 1);
  (*(code *)(long)DAT_ffffffffbfc43b2c)(0x1e,0x18,(short)*param_3);
  uVar2 = *param_3;
  special2(uVar2,uVar2,0x10,0x3a);
  (*(code *)(long)DAT_ffffffffbfc43b2c)(0x1e,0x19,uVar2 & 0xffff);
  (*(code *)(long)DAT_ffffffffbfc43b2c)(0x1e,0x1a,*(uint *)param_3 & 0xffff);
  (*(code *)(long)DAT_ffffffffbfc43b2c)(0x1e,0x1b,*(undefined2 *)param_3);
  (*(code *)(long)DAT_ffffffffbfc43b2c)(0x1e,0x11,((uint)param_2 & 0xff) << 8 | 1);
  lVar1 = (*(code *)(long)DAT_ffffffffbfc43b98)();
  do {
    uVar2 = (*(code *)(long)DAT_ffffffffbfc438e0)(0x1e,0x11);
    if ((uVar2 & 3) == 0) break;
    uVar2 = (*(code *)(long)DAT_ffffffffbfc43b98)();
  } while (uVar2 <= lVar1 + 40000000U);
  uVar2 = (*(code *)(long)DAT_ffffffffbfc43b98)();
  if (lVar1 + 40000000U < uVar2) {
    (*(code *)(long)DAT_ffffffffbfc4400c)(DAT_ffffffffbfc436f4 + 0x1740,param_1,param_2,*param_3);
  }
  (*(code *)(long)DAT_ffffffffbfc43b2c)(0x1e,0x10,uVar3 & 0xff00);
  return;
}

