/*
 * Ghidra reconstructed C; not original Cisco source.
 * RV220W boot-chain/U-Boot analysis v1.1.0
 * Entry: ffffffffbfc0f640
 * Function: rv220w_flash_probe_ids
 * Subsystem: nor-environment
 *
 * RV220W BOOT-CHAIN / U-BOOT SEMANTIC ANNOTATION v1.1.0
 * Region: early-boot-and-board-support
 * Subsystem: nor-environment
 * Evidence: address/string/register/call evidence
 * Confidence: high for listed hardware facts; medium for inferred types
 * Interpretation: Macronix/AMD-command-set NOR identification. Writes autoselect command sequence through physical alias 0xbdc00000 and reads manufacturer/device IDs before reset-to-read-array.
 * Safety: reconstructed pseudocode is not original Cisco source. Do not replay flash, GPIO, MDIO or switch writes without readback and recovery safeguards.
 * 
 * Prior/recovered evidence:
 * RV220W BOOT-CHAIN / U-BOOT SEMANTIC ANNOTATION v1.1.0
 * Region: early-boot-and-board-support
 * Subsystem: nor-environment
 * Evidence: address/string/register/call evidence
 * Confidence: high for listed hardware facts; medium for inferred types
 * Interpretation: Macronix/AMD-command-set NOR identification. Writes autoselect command sequence through physical alias 0xbdc00000 and reads manufacturer/device IDs before reset-to-read-array.
 * Safety: reconstructed pseudocode is not original Cisco source. Do not replay flash, GPIO, MDIO or switch writes without readback and recovery safeguards.
 * 
 * Prior/recovered evidence:
 * RV220W BOOT-CHAIN / U-BOOT SEMANTIC ANNOTATION v1.1.0
 * Region: early-boot-and-board-support
 * Subsystem: bootloader-support
 * Evidence: Ghidra control-flow/GOT recovery
 * Confidence: medium for boundary; low for original name
 * Interpretation: Macronix/AMD-command-set NOR identification. Writes autoselect command sequence through physical alias 0xbdc00000 and reads manufacturer/device IDs before reset-to-read-array.
 * Safety: reconstructed pseudocode is not original Cisco source. Do not replay flash, GPIO, MDIO or switch writes without readback and recovery safeguards.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* RV220W BOOT-CHAIN / U-BOOT SEMANTIC ANNOTATION v1.1.0
   Region: early-boot-and-board-support
   Subsystem: nor-environment
   Evidence: address/string/register/call evidence
   Confidence: high for listed hardware facts; medium for inferred types
   Interpretation: Macronix/AMD-command-set NOR identification. Writes autoselect command sequence
   through physical alias 0xbdc00000 and reads manufacturer/device IDs before reset-to-read-array.
   Safety: reconstructed pseudocode is not original Cisco source. Do not replay flash, GPIO, MDIO or
   switch writes without readback and recovery safeguards.
   
   Prior/recovered evidence:
   RV220W BOOT-CHAIN / U-BOOT SEMANTIC ANNOTATION v1.1.0
   Region: early-boot-and-board-support
   Subsystem: nor-environment
   Evidence: address/string/register/call evidence
   Confidence: high for listed hardware facts; medium for inferred types
   Interpretation: Macronix/AMD-command-set NOR identification. Writes autoselect command sequence
   through physical alias 0xbdc00000 and reads manufacturer/device IDs before reset-to-read-array.
   Safety: reconstructed pseudocode is not original Cisco source. Do not replay flash, GPIO, MDIO or
   switch writes without readback and recovery safeguards.
   
   Prior/recovered evidence:
   RV220W BOOT-CHAIN / U-BOOT SEMANTIC ANNOTATION v1.1.0
   Region: early-boot-and-board-support
   Subsystem: bootloader-support
   Evidence: Ghidra control-flow/GOT recovery
   Confidence: medium for boundary; low for original name
   Interpretation: Macronix/AMD-command-set NOR identification. Writes autoselect command sequence
   through physical alias 0xbdc00000 and reads manufacturer/device IDs before reset-to-read-array.
   Safety: reconstructed pseudocode is not original Cisco source. Do not replay flash, GPIO, MDIO or
   switch writes without readback and recovery safeguards. */

undefined8 rv220w_flash_probe_ids(void)

{
  short sVar1;
  int iVar2;
  undefined8 uVar3;
  code *pcVar4;
  short *psVar5;
  undefined8 in_ra;
  
  _DAT_ffffffffbdc00554 = 0x55;
  _DAT_ffffffffbdc00aaa = 0x90;
  psVar5 = (short *)(long)((int)&stack0x00000000 + -0x20);
  *(undefined1 **)(psVar5 + 8) = &_gp;
  *psVar5 = _DAT_ffffffffbdc00000;
  sVar1 = _DAT_ffffffffbdc00002;
  *(undefined8 *)(psVar5 + 0xc) = in_ra;
  iVar2 = DAT_ffffffffbfc436f4;
  psVar5[1] = sVar1;
  pcVar4 = (code *)(long)DAT_ffffffffbfc4400c;
  psVar5[2] = _DAT_ffffffffbdc0001c;
  psVar5[3] = _DAT_ffffffffbdc0001e;
  _DAT_ffffffffbdc00000 = 0xf0;
  (*pcVar4)(iVar2 + -0x5870,*psVar5,psVar5[1],psVar5[2],psVar5[3],0xf0);
  uVar3 = 0;
  if (((*psVar5 == 0xec) && (psVar5[1] == 0x257e)) && (uVar3 = 0, psVar5[2] == 0x2506)) {
    uVar3 = special2(0x2501,(ulong)(ushort)psVar5[3],0,0x2a);
  }
  return uVar3;
}

