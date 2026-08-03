/*
 * Ghidra reconstructed C; not original Cisco source.
 * RV220W boot-chain/U-Boot analysis v1.1.0
 * Entry: ffffffffbfc2ebd8
 * Function: FUN_ffffffffbfc2ebd8
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

undefined8 FUN_ffffffffbfc2ebd8(long param_1)

{
  undefined8 extraout_at;
  undefined8 uVar1;
  long lVar2;
  long lVar3;
  undefined8 unaff_s0;
  int iVar5;
  ulong uVar4;
  undefined8 unaff_s1;
  code *pcVar6;
  undefined8 unaff_s2;
  undefined8 *puVar7;
  undefined8 in_ra;
  
  puVar7 = (undefined8 *)(long)((int)&stack0x00000000 + -0x30);
  puVar7[3] = &_gp;
  puVar7[2] = unaff_s2;
  puVar7[4] = in_ra;
  puVar7[1] = unaff_s1;
  *puVar7 = unaff_s0;
  if (param_1 == 2) {
    uVar1 = 8;
  }
  else if (param_1 == 3) {
    iVar5 = DAT_ffffffffbfc436f0 + -0x1680;
    lVar2 = (*(code *)(long)iVar5)(0x30d0400);
    uVar1 = 9;
    if (lVar2 == 0) {
      lVar2 = (*(code *)(long)iVar5)(0x30d0700);
      if (lVar2 == 0) {
        uVar1 = 0;
      }
      else {
        uVar1 = 9;
      }
    }
  }
  else {
    lVar2 = 1;
    if (param_1 == 0) {
      lVar3 = (*(code *)(long)DAT_ffffffffbfc43c60)();
      lVar2 = 0xc;
      if (*(short *)(lVar3 + 0x40) == 0xc) {
        lVar3 = (*(code *)(long)DAT_ffffffffbfc43c60)();
        lVar2 = 1;
        if (*(char *)(lVar3 + 0x42) == '\x01') {
          return 2;
        }
      }
    }
    else if (param_1 == 1) {
      pcVar6 = (code *)(long)(DAT_ffffffffbfc436f0 + -0x1680);
      lVar2 = (*pcVar6)(0x30d0100);
      if (lVar2 != 0) {
        return 0;
      }
      lVar2 = (*pcVar6)(0x30d0200);
      if (lVar2 != 0) {
        return 0;
      }
      lVar2 = (*pcVar6)(0x30d0600);
      if (lVar2 != 0) {
        return 0;
      }
      lVar3 = (*pcVar6)(0x30d0700);
      lVar2 = 0;
      if (lVar3 != 0) {
        return 0;
      }
    }
    uVar1 = special2(param_1,lVar2,0x1b,0x32);
    uVar4 = *(ulong *)(&DAT_80011800080007f8 + lVar2);
    pcVar6 = (code *)(long)(DAT_ffffffffbfc436f0 + -0x1680);
    lVar2 = (*pcVar6)(0x30d0400);
    if ((lVar2 == 0) && (lVar2 = (*pcVar6)(0x30d0700), lVar2 == 0)) {
      setCopReg(2,extraout_at,*(undefined4 *)(uVar4 + 0x14));
      setCopReg(2,uVar1,*(undefined4 *)(uVar4 + 0x12));
      lVar2 = (*pcVar6)(0x30d0001);
      uVar1 = 3;
      if (lVar2 == 0) {
        lVar2 = (*pcVar6)(0x30d0300);
        uVar1 = 2;
        if (lVar2 != 0) {
          uVar1 = 3;
        }
      }
    }
    else {
      uVar4 = uVar4 >> 4 & 3;
      uVar1 = 6;
      if ((uVar4 != 2) && (uVar1 = 7, uVar4 != 3)) {
        if (uVar4 == 1) {
          uVar1 = 5;
        }
        else {
          uVar1 = 0;
        }
      }
    }
  }
  return uVar1;
}

