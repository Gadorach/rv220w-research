/*
 * Ghidra reconstructed C; not original Cisco source.
 * RV220W boot-chain/U-Boot analysis v1.1.0
 * Entry: ffffffffbfc50a38
 * Function: FUN_ffffffffbfc50a38
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

void FUN_ffffffffbfc50a38(void)

{
  undefined1 uVar1;
  undefined4 uVar2;
  long lVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  int iVar6;
  undefined8 unaff_s0;
  long lVar7;
  undefined8 unaff_s1;
  undefined1 *puVar8;
  undefined8 unaff_s2;
  int iVar9;
  undefined8 unaff_s3;
  undefined8 unaff_s4;
  int iVar10;
  code *pcVar11;
  undefined4 in_k0_hi;
  int in_k0_lo;
  long lVar12;
  undefined8 in_ra;
  int iVar13;
  
  iVar13 = (int)&stack0x00000000;
  lVar12 = (long)(iVar13 + -0x7ff0);
  *(undefined1 **)(lVar12 + 0x7fd8) = &_gp;
  *(undefined8 *)(lVar12 + 0x7fe0) = in_ra;
  pcVar11 = (code *)(long)iRamffffffffbfc55d98;
  *(undefined8 *)(lVar12 + 0x7fd0) = unaff_s4;
  iVar10 = 0;
  *(undefined8 *)(lVar12 + 0x7fc8) = unaff_s3;
  *(undefined8 *)(lVar12 + 0x7fc0) = unaff_s2;
  *(undefined8 *)(lVar12 + 0x7fb8) = unaff_s1;
  *(undefined8 *)(lVar12 + 0x7fb0) = unaff_s0;
  uVar2 = uRamffffffffbfc55ddc;
  lVar3 = CONCAT44(in_k0_hi,in_k0_lo);
  *(undefined4 *)(long)(iVar13 + -0x20050) = 0;
  (*pcVar11)(uVar2,in_k0_lo + 0x78,6);
  (*(code *)(long)iRamffffffffbfc55dd4)
            (iRamffffffffbfc55c28 + 0x4970,*(undefined1 *)(lVar3 + 0x78),
             *(undefined1 *)(lVar3 + 0x79),*(undefined1 *)(lVar3 + 0x7a),
             *(undefined1 *)(lVar3 + 0x7b),*(undefined1 *)(lVar3 + 0x7c),
             *(undefined1 *)(lVar3 + 0x7d));
  (*(code *)(long)iRamffffffffbfc55dd4)(iRamffffffffbfc55c28 + 0x4a10);
  (*(code *)(long)iRamffffffffbfc55cd0)();
  (*(code *)(long)iRamffffffffbfc55cc0)(iVar13 + -0x2004c,0,6);
  (*(code *)(long)iRamffffffffbfc55cc0)(iVar13 + -0x20046,0,6);
  (*(code *)(long)iRamffffffffbfc55c90)(6,0);
  (*(code *)(long)iRamffffffffbfc55c90)(7,0);
  (*(code *)(long)iRamffffffffbfc55c6c)();
  (*(code *)(long)iRamffffffffbfc55cc0)(iVar13 + -0x20040,0,0x20000);
  do {
    if (iVar10 == 100) {
      iVar10 = 0;
      (*(code *)(long)iRamffffffffbfc55dac)(6);
      (*(code *)(long)iRamffffffffbfc55dac)(7);
    }
    iVar6 = iRamffffffffbfc55d34;
    lVar7 = (long)iRamffffffffbfc55d34;
    lVar3 = (*(code *)(long)iRamffffffffbfc55dd0)(lVar7,(undefined4 *)(long)(iVar13 + -0x20050));
    pcVar11 = (code *)(long)iRamffffffffbfc55cec;
    if (lVar3 == 0) {
      (*(code *)(long)iRamffffffffbfc55dd4)
                (iRamffffffffbfc55c28 + 0x4a30,*(undefined2 *)(lVar7 + 0xc));
      pcVar11 = (code *)(long)iRamffffffffbfc55cec;
      if (*(short *)(lVar7 + 0xc) != 0x15) goto LAB_ffffffffbfc50d1c;
      iVar9 = iVar6 + 6;
      lVar3 = (*(code *)(long)iRamffffffffbfc55cd4)(iVar9,uRamffffffffbfc55ddc,6);
      if (lVar3 != 0) {
        puVar8 = (undefined1 *)(long)(iVar13 + -0x20046);
        (*(code *)(long)iRamffffffffbfc55d30)(lVar7,0x14);
        (*(code *)(long)iRamffffffffbfc55d98)(puVar8,iVar6 + 0xe,6);
        (*(code *)(long)iRamffffffffbfc55d98)(iVar13 + -0x2004c,iVar9,6);
        (*(code *)(long)iRamffffffffbfc55d98)
                  ((undefined1 *)(long)(iVar13 + -0x20040),0xffffffffbdc60000,0x20000);
        iVar6 = iVar13 + -0x10140;
        do {
          uVar1 = *puVar8;
          puVar8 = (undefined1 *)(long)((int)puVar8 + 1);
          *(undefined1 *)(long)iVar6 = uVar1;
          iVar6 = iVar6 + 1;
        } while (puVar8 != (undefined1 *)(long)(iVar13 + -0x20040));
        iVar6 = 0;
        (*(code *)(long)iRamffffffffbfc55cf4)(0,0xffffffffbdc60000,0xffffffffbdc7ffff);
        uVar4 = (*(code *)(long)iRamffffffffbfc55d08)(0xffffffffbdc60000);
        uVar5 = (*(code *)(long)iRamffffffffbfc55d08)(0xffffffffbdc7ffff);
        (*(code *)(long)iRamffffffffbfc55cb4)(uVar4,uVar5);
        (*(code *)(long)iRamffffffffbfc55cf0)(500);
        (*(code *)(long)iRamffffffffbfc55d44)(0xffffffffbdc60000,puVar8,0x20000);
        do {
          iVar6 = iVar6 + 1;
          (*(code *)(long)iRamffffffffbfc55cf0)(1000);
        } while (iVar6 != 1000);
        (*(code *)(long)iRamffffffffbfc55cbc)();
        pcVar11 = (code *)(long)iRamffffffffbfc55cec;
        goto LAB_ffffffffbfc50d1c;
      }
      (*(code *)(long)iRamffffffffbfc55dd4)(iRamffffffffbfc55c28 + 0x4a48);
    }
    else {
LAB_ffffffffbfc50d1c:
      lVar3 = (*pcVar11)();
      if (lVar3 != 0) {
        (*(code *)(long)iRamffffffffbfc55da4)();
        (*(code *)(long)iRamffffffffbfc55dd4)(iRamffffffffbfc55c28 + 0x49b8);
        return;
      }
    }
    iVar10 = iVar10 + 1;
  } while( true );
}

