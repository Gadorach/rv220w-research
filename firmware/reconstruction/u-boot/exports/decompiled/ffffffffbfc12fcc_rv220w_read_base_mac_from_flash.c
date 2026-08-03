/*
 * Ghidra reconstructed C; not original Cisco source.
 * RV220W boot-chain/U-Boot analysis v1.1.0
 * Entry: ffffffffbfc12fcc
 * Function: rv220w_read_base_mac_from_flash
 * Subsystem: nor-environment
 *
 * RV220W BOOT-CHAIN / U-BOOT SEMANTIC ANNOTATION v1.1.0
 * Region: early-boot-and-board-support
 * Subsystem: nor-environment
 * Evidence: address/string/register/call evidence
 * Confidence: high for listed hardware facts; medium for inferred types
 * Interpretation: Reads and validates six bytes at physical flash address 0xbdc6ff00 (flash offset 0x6ff00) as the base Ethernet MAC address; warns when zero or erased.
 * Safety: reconstructed pseudocode is not original Cisco source. Do not replay flash, GPIO, MDIO or switch writes without readback and recovery safeguards.
 * 
 * Prior/recovered evidence:
 * RV220W BOOT-CHAIN / U-BOOT SEMANTIC ANNOTATION v1.1.0
 * Region: early-boot-and-board-support
 * Subsystem: nor-environment
 * Evidence: address/string/register/call evidence
 * Confidence: high for listed hardware facts; medium for inferred types
 * Interpretation: Reads and validates six bytes at physical flash address 0xbdc6ff00 (flash offset 0x6ff00) as the base Ethernet MAC address; warns when zero or erased.
 * Safety: reconstructed pseudocode is not original Cisco source. Do not replay flash, GPIO, MDIO or switch writes without readback and recovery safeguards.
 * 
 * Prior/recovered evidence:
 * RV220W BOOT-CHAIN / U-BOOT SEMANTIC ANNOTATION v1.1.0
 * Region: early-boot-and-board-support
 * Subsystem: bootloader-support
 * Evidence: Ghidra control-flow/GOT recovery
 * Confidence: medium for boundary; low for original name
 * Interpretation: Reads and validates six bytes at physical flash address 0xbdc6ff00 (flash offset 0x6ff00) as the base Ethernet MAC address; warns when zero or erased.
 * Safety: reconstructed pseudocode is not original Cisco source. Do not replay flash, GPIO, MDIO or switch writes without readback and recovery safeguards.
 */

/* RV220W BOOT-CHAIN / U-BOOT SEMANTIC ANNOTATION v1.1.0
   Region: early-boot-and-board-support
   Subsystem: nor-environment
   Evidence: address/string/register/call evidence
   Confidence: high for listed hardware facts; medium for inferred types
   Interpretation: Reads and validates six bytes at physical flash address 0xbdc6ff00 (flash offset
   0x6ff00) as the base Ethernet MAC address; warns when zero or erased.
   Safety: reconstructed pseudocode is not original Cisco source. Do not replay flash, GPIO, MDIO or
   switch writes without readback and recovery safeguards.
   
   Prior/recovered evidence:
   RV220W BOOT-CHAIN / U-BOOT SEMANTIC ANNOTATION v1.1.0
   Region: early-boot-and-board-support
   Subsystem: nor-environment
   Evidence: address/string/register/call evidence
   Confidence: high for listed hardware facts; medium for inferred types
   Interpretation: Reads and validates six bytes at physical flash address 0xbdc6ff00 (flash offset
   0x6ff00) as the base Ethernet MAC address; warns when zero or erased.
   Safety: reconstructed pseudocode is not original Cisco source. Do not replay flash, GPIO, MDIO or
   switch writes without readback and recovery safeguards.
   
   Prior/recovered evidence:
   RV220W BOOT-CHAIN / U-BOOT SEMANTIC ANNOTATION v1.1.0
   Region: early-boot-and-board-support
   Subsystem: bootloader-support
   Evidence: Ghidra control-flow/GOT recovery
   Confidence: medium for boundary; low for original name
   Interpretation: Reads and validates six bytes at physical flash address 0xbdc6ff00 (flash offset
   0x6ff00) as the base Ethernet MAC address; warns when zero or erased.
   Safety: reconstructed pseudocode is not original Cisco source. Do not replay flash, GPIO, MDIO or
   switch writes without readback and recovery safeguards. */

void rv220w_read_base_mac_from_flash(void)

{
  long lVar1;
  undefined8 unaff_s0;
  int iVar2;
  code *pcVar3;
  undefined8 *puVar4;
  undefined8 in_ra;
  int iVar5;
  
  iVar5 = (int)&stack0x00000000;
  puVar4 = (undefined8 *)(long)(iVar5 + -0x40);
  puVar4[5] = &_gp;
  pcVar3 = (code *)(long)DAT_ffffffffbfc43e84;
  puVar4[4] = unaff_s0;
  iVar2 = iVar5 + -0x30;
  puVar4[1] = 0;
  puVar4[6] = in_ra;
  *(undefined1 *)((long)puVar4 + 0xd) = 0xff;
  *puVar4 = 0;
  *(undefined1 *)(puVar4 + 1) = 0xff;
  *(undefined1 *)((long)puVar4 + 9) = 0xff;
  *(undefined1 *)((long)puVar4 + 10) = 0xff;
  *(undefined1 *)((long)puVar4 + 0xb) = 0xff;
  *(undefined1 *)((long)puVar4 + 0xc) = 0xff;
  puVar4[2] = 0;
  (*pcVar3)(iVar2,0xffffffffbdc6ff00,6);
  lVar1 = (*(code *)(long)DAT_ffffffffbfc43ab4)(iVar2,puVar4,6);
  if ((lVar1 == 0) ||
     (lVar1 = (*(code *)(long)DAT_ffffffffbfc43ab4)(iVar2,iVar5 + -0x38,6), lVar1 == 0)) {
    (*(code *)(long)DAT_ffffffffbfc4400c)(DAT_ffffffffbfc436f4 + -0x52e8);
  }
  return;
}

