/*
 * Ghidra reconstructed C; not original Cisco source.
 * RV220W boot-chain/U-Boot analysis v1.1.0
 * Entry: ffffffffbfc34a4c
 * Function: FUN_ffffffffbfc34a4c
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

undefined8 FUN_ffffffffbfc34a4c(long param_1)

{
  long lVar1;
  undefined8 uVar2;
  ulong uVar3;
  undefined8 uVar4;
  undefined8 unaff_s0;
  int iVar5;
  undefined8 unaff_s1;
  int iVar6;
  undefined8 unaff_s2;
  int iVar7;
  code *pcVar8;
  undefined8 *puVar9;
  undefined8 in_ra;
  
  puVar9 = (undefined8 *)(long)((int)&stack0x00000000 + -0x30);
  puVar9[3] = &_gp;
  puVar9[1] = unaff_s1;
  pcVar8 = (code *)(long)DAT_ffffffffbfc43c60;
  puVar9[4] = in_ra;
  puVar9[2] = unaff_s2;
  *puVar9 = unaff_s0;
  lVar1 = (*pcVar8)();
  if (*(short *)(lVar1 + 0x40) == 7) {
    if (param_1 < 2) {
      iVar6 = 0;
      do {
        uVar2 = (*(code *)(long)(DAT_ffffffffbfc436f0 + 0x46b4))(iVar6,param_1);
        iVar7 = DAT_ffffffffbfc436f0 + 0x46e0;
        (*(code *)(long)iVar7)(uVar2,0);
        iVar5 = iVar6 + 1;
        uVar2 = (*(code *)(long)(DAT_ffffffffbfc436f0 + 0x4688))(iVar6,param_1);
        (*(code *)(long)iVar7)(uVar2,0x10);
        iVar6 = iVar5;
      } while (iVar5 != 4);
    }
  }
  else {
    lVar1 = (*(code *)(long)DAT_ffffffffbfc43c60)();
    if (*(short *)(lVar1 + 0x40) == 0xc) {
      if (param_1 != 0) {
        return 0;
      }
      iVar5 = DAT_ffffffffbfc436f0 + 0x46b4;
      uVar2 = (*(code *)(long)iVar5)(1,0);
      pcVar8 = (code *)(long)(DAT_ffffffffbfc436f0 + 0x46e0);
      (*pcVar8)(uVar2,0);
      iVar6 = DAT_ffffffffbfc436f0 + 0x4688;
      uVar2 = (*(code *)(long)iVar6)(1,0);
      (*pcVar8)(uVar2,0);
      uVar2 = (*(code *)(long)iVar5)(0,0);
      (*pcVar8)(uVar2,0xc);
      uVar2 = (*(code *)(long)iVar6)(0,0);
      uVar4 = 0xc;
    }
    else {
      lVar1 = (*(code *)(long)DAT_ffffffffbfc43c60)();
      if (*(short *)(lVar1 + 0x40) != 0xb) {
        lVar1 = (*(code *)(long)DAT_ffffffffbfc43c60)();
        if ((*(short *)(lVar1 + 0x40) != 0x2716) &&
           (lVar1 = (*(code *)(long)DAT_ffffffffbfc43c60)(), *(short *)(lVar1 + 0x40) != 0x2717)) {
          return 0;
        }
      }
      if (param_1 != 0) {
        return 0;
      }
      uVar3 = (*(code *)(long)DAT_ffffffffbfc438b4)(0);
      if (uVar3 == 0xffffffffffffffff) {
        return 0;
      }
      lVar1 = (*(code *)(long)(DAT_ffffffffbfc436f0 + 0x4730))((int)uVar3 >> 8,uVar3 & 0xff,2);
      iVar6 = DAT_ffffffffbfc436f4;
      if (lVar1 != 0x143) {
        return 0;
      }
      (*(code *)(long)DAT_ffffffffbfc4400c)(DAT_ffffffffbfc436f4 + 0x1150);
      (*(code *)(long)DAT_ffffffffbfc4400c)(iVar6 + 0x25b0);
      (*(code *)(long)DAT_ffffffffbfc4400c)(DAT_ffffffffbfc436f4 + 0x25b8);
      (*(code *)(long)DAT_ffffffffbfc4400c)(DAT_ffffffffbfc436f4 + 0x2608);
      (*(code *)(long)DAT_ffffffffbfc4400c)(DAT_ffffffffbfc436f4 + 0x2658);
      (*(code *)(long)DAT_ffffffffbfc4400c)(iVar6 + 0x25b0);
      (*(code *)(long)DAT_ffffffffbfc4400c)(iVar6 + 0x1150);
      (*(code *)(long)(DAT_ffffffffbfc436f0 + 0x4710))(1000000000);
      uVar2 = (*(code *)(long)(DAT_ffffffffbfc436f0 + 0x4688))(0,0);
      pcVar8 = (code *)(long)(DAT_ffffffffbfc436f0 + 0x46e0);
      (*pcVar8)(uVar2,5);
      uVar2 = (*(code *)(long)(DAT_ffffffffbfc436f0 + 0x46b4))(0,0);
      uVar4 = 5;
    }
    (*pcVar8)(uVar2,uVar4);
  }
  return 0;
}

