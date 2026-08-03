/*
 * Ghidra reconstructed C; not original Cisco source.
 * RV220W boot-chain/U-Boot analysis v1.1.0
 * Entry: ffffffffbfc33620
 * Function: FUN_ffffffffbfc33620
 * Subsystem: bootloader-support
 *
 * RV220W BOOT-CHAIN / U-BOOT SEMANTIC ANNOTATION v1.1.0
 * Region: u-boot-proper
 * Subsystem: bootloader-support
 * Evidence: Ghidra control-flow/GOT recovery
 * Confidence: medium for boundary; low for original name
 * Interpretation: Analysis-created function. Boundary is supported by control flow or a recovered GOT pointer, but original source name and detailed role are unknown.
 * Safety: reconstructed pseudocode is not original Cisco source. Do not replay flash, GPIO, MDIO or switch writes without readback and recovery safeguards.
 * 
 * Prior/recovered evidence:
 * RV220W BOOT-CHAIN / U-BOOT SEMANTIC ANNOTATION v1.1.0
 * Region: u-boot-proper
 * Subsystem: bootloader-support
 * Evidence: Ghidra control-flow/GOT recovery
 * Confidence: medium for boundary; low for original name
 * Interpretation: Analysis-created function. Boundary is supported by control flow or a recovered GOT pointer, but original source name and detailed role are unknown.
 * Safety: reconstructed pseudocode is not original Cisco source. Do not replay flash, GPIO, MDIO or switch writes without readback and recovery safeguards.
 * 
 * Prior/recovered evidence:
 * RV220W BOOT-CHAIN / U-BOOT SEMANTIC ANNOTATION v1.1.0
 * Region: u-boot-proper
 * Subsystem: bootloader-support
 * Evidence: Ghidra control-flow/GOT recovery
 * Confidence: medium for boundary; low for original name
 * Interpretation: Analysis-created function. Boundary is supported by control flow or a recovered GOT pointer, but original source name and detailed role are unknown.
 * Safety: reconstructed pseudocode is not original Cisco source. Do not replay flash, GPIO, MDIO or switch writes without readback and recovery safeguards.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* RV220W BOOT-CHAIN / U-BOOT SEMANTIC ANNOTATION v1.1.0
   Region: u-boot-proper
   Subsystem: bootloader-support
   Evidence: Ghidra control-flow/GOT recovery
   Confidence: medium for boundary; low for original name
   Interpretation: Analysis-created function. Boundary is supported by control flow or a recovered
   GOT pointer, but original source name and detailed role are unknown.
   Safety: reconstructed pseudocode is not original Cisco source. Do not replay flash, GPIO, MDIO or
   switch writes without readback and recovery safeguards.
   
   Prior/recovered evidence:
   RV220W BOOT-CHAIN / U-BOOT SEMANTIC ANNOTATION v1.1.0
   Region: u-boot-proper
   Subsystem: bootloader-support
   Evidence: Ghidra control-flow/GOT recovery
   Confidence: medium for boundary; low for original name
   Interpretation: Analysis-created function. Boundary is supported by control flow or a recovered
   GOT pointer, but original source name and detailed role are unknown.
   Safety: reconstructed pseudocode is not original Cisco source. Do not replay flash, GPIO, MDIO or
   switch writes without readback and recovery safeguards.
   
   Prior/recovered evidence:
   RV220W BOOT-CHAIN / U-BOOT SEMANTIC ANNOTATION v1.1.0
   Region: u-boot-proper
   Subsystem: bootloader-support
   Evidence: Ghidra control-flow/GOT recovery
   Confidence: medium for boundary; low for original name
   Interpretation: Analysis-created function. Boundary is supported by control flow or a recovered
   GOT pointer, but original source name and detailed role are unknown.
   Safety: reconstructed pseudocode is not original Cisco source. Do not replay flash, GPIO, MDIO or
   switch writes without readback and recovery safeguards. */

bool FUN_ffffffffbfc33620(ulong param_1)

{
  undefined4 uVar1;
  ushort uVar2;
  ushort uVar3;
  ulong uVar4;
  ulong uVar5;
  ulong uVar6;
  ulong uVar7;
  undefined8 in_k0;
  
  uVar7 = (ulong)PRId;
  uVar1 = getCopReg(2,0x19);
  *(undefined4 *)(param_1 + 0x10) = uVar1;
  if ((uVar7 == 0xd0200) && ((_DAT_80011800800007b8 >> 0x22 & 1) != 0)) {
    uVar7 = 0xd0210;
  }
  uVar2 = (ushort)(param_1 >> 8);
  uVar3 = (ushort)(uVar7 >> 8);
  if (uVar2 < 0xd03) {
    uVar4 = param_1 & 0x7000000;
    if (uVar4 == 0x1000000) {
      uVar4 = 0xffff10;
    }
    else if (uVar4 == 0x2000000) {
      uVar4 = 0xffff0f;
    }
    else {
      if (uVar4 == 0x3000000) {
        if (uVar3 == uVar2) {
          return true;
        }
        goto LAB_ffffffffbfc336e8;
      }
      if (uVar4 != 0) goto LAB_ffffffffbfc336e8;
      uVar4 = 0xffff1f;
    }
    if ((uVar7 & uVar4) != (param_1 & uVar4)) {
LAB_ffffffffbfc336e8:
      setCopReg(2,in_k0,*(undefined4 *)(param_1 + 0x28));
      return (uVar7 & 0xffff10) < (param_1 & 0xffff10);
    }
  }
  else {
    uVar5 = param_1 & 0x7000000;
    uVar4 = (param_1 & 0xffffff) >> 6;
    if (uVar5 == 0x1000000) {
      uVar6 = (uVar7 & 0xffffff) >> 6;
    }
    else if (uVar5 == 0x2000000) {
      uVar6 = param_1 & 0xffff3f;
      uVar4 = uVar7 & 0xffff3f;
    }
    else {
      if (uVar5 == 0x3000000) {
        if (uVar3 == uVar2) {
          return true;
        }
        goto LAB_ffffffffbfc33770;
      }
      uVar6 = uVar7 & 0xffffff;
      if (uVar5 != 0) goto LAB_ffffffffbfc33770;
      uVar4 = param_1 & 0xffffff;
    }
    if (uVar6 != uVar4) {
LAB_ffffffffbfc33770:
      setCopReg(2,in_k0,*(undefined4 *)(param_1 + 6));
      return (uVar7 & 0xffffff) >> 6 < (param_1 & 0xffffff) >> 6;
    }
  }
  return true;
}

