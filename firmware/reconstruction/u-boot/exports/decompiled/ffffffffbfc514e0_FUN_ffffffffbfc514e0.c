/*
 * Ghidra reconstructed C; not original Cisco source.
 * RV220W boot-chain/U-Boot analysis v1.1.0
 * Entry: ffffffffbfc514e0
 * Function: FUN_ffffffffbfc514e0
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

undefined8 FUN_ffffffffbfc514e0(void)

{
  int iVar1;
  long lVar2;
  undefined8 uVar3;
  uint uVar4;
  undefined8 unaff_s0;
  long lVar5;
  undefined8 unaff_s1;
  int iVar6;
  code *pcVar7;
  undefined4 in_k0_hi;
  int in_k0_lo;
  undefined4 *puVar8;
  undefined8 in_ra;
  
  puVar8 = (undefined4 *)(long)((int)&stack0x00000000 + -0x30);
  *(undefined1 **)(puVar8 + 8) = &_gp;
  *(undefined8 *)(puVar8 + 10) = in_ra;
  *(undefined8 *)(puVar8 + 6) = unaff_s1;
  iVar1 = iRamffffffffbfc55c28;
  iVar6 = 0;
  pcVar7 = (code *)(long)iRamffffffffbfc55dd4;
  *(undefined8 *)(puVar8 + 4) = unaff_s0;
  *puVar8 = 0;
  (*pcVar7)(iVar1 + 0x4b88);
  (*(code *)(long)iRamffffffffbfc55cd0)();
  lVar2 = CONCAT44(in_k0_hi,in_k0_lo);
  (*(code *)(long)iRamffffffffbfc55d98)(uRamffffffffbfc55ddc,in_k0_lo + 0x78,6);
  (*(code *)(long)iRamffffffffbfc55dd4)
            (iRamffffffffbfc55c28 + 0x4970,*(undefined1 *)(lVar2 + 0x78),
             *(undefined1 *)(lVar2 + 0x79),*(undefined1 *)(lVar2 + 0x7a),
             *(undefined1 *)(lVar2 + 0x7b),*(undefined1 *)(lVar2 + 0x7c),
             *(undefined1 *)(lVar2 + 0x7d));
  (*(code *)(long)iRamffffffffbfc55dd4)(iRamffffffffbfc55c28 + 0x4ba8);
  (*(code *)(long)iRamffffffffbfc55c90)(6,0);
  (*(code *)(long)iRamffffffffbfc55c90)(7,1);
  (*(code *)(long)iRamffffffffbfc55c70)();
  do {
    if (iVar6 == 100) {
      iVar6 = 0;
      (*(code *)(long)iRamffffffffbfc55dac)(6);
      (*(code *)(long)iRamffffffffbfc55dac)(7);
    }
    iVar1 = iRamffffffffbfc55d34;
    lVar5 = (long)iRamffffffffbfc55d34;
    lVar2 = (*(code *)(long)iRamffffffffbfc55dd0)(lVar5,puVar8);
    pcVar7 = (code *)(long)iRamffffffffbfc55cec;
    if ((lVar2 == 0) && ((*(short *)(lVar5 + 0xc) == -0x7778 || (*(short *)(lVar5 + 0xc) == 0)))) {
      lVar2 = (*(code *)(long)iRamffffffffbfc55cd4)(iVar1 + 6,uRamffffffffbfc55ddc,6);
      if (lVar2 != 0) {
        uVar4 = (uint)(*(ushort *)(lVar5 + 0xe) >> 8) | (*(ushort *)(lVar5 + 0xe) & 0xff) << 8;
        pcVar7 = (code *)(long)iRamffffffffbfc55cec;
        if (uVar4 < 6) {
                    /* WARNING: Could not recover jumptable at 0xffffffffbfc516a4. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
          uVar3 = (*(code *)(long)(*(int *)(long)(int)(uVar4 * 4 + iRamffffffffbfc55c28 + 0x4750) +
                                  -0x403aa3e0))();
          return uVar3;
        }
        goto LAB_ffffffffbfc516dc;
      }
      (*(code *)(long)iRamffffffffbfc55dd4)(iRamffffffffbfc55c28 + 0x4a48);
    }
    else {
LAB_ffffffffbfc516dc:
      lVar2 = (*pcVar7)();
      if (lVar2 != 0) {
        (*(code *)(long)iRamffffffffbfc55da4)();
        (*(code *)(long)iRamffffffffbfc55d8c)(iRamffffffffbfc55c28 + 0x49b8);
        return 0xffffffffffffffff;
      }
    }
    iVar6 = iVar6 + 1;
  } while( true );
}

