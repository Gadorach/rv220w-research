/*
 * Ghidra reconstructed C; not original Cisco source.
 * RV220W boot-chain/U-Boot analysis v1.1.0
 * Entry: ffffffffbfc28944
 * Function: FUN_ffffffffbfc28944
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

void FUN_ffffffffbfc28944(void)

{
  undefined4 uVar1;
  undefined8 in_zero;
  uint uVar3;
  long lVar2;
  long lVar4;
  undefined8 unaff_s0;
  undefined8 unaff_s1;
  ulong uVar5;
  undefined8 unaff_s2;
  undefined8 unaff_s3;
  undefined8 unaff_s4;
  undefined8 unaff_s5;
  undefined8 unaff_s6;
  undefined8 unaff_s7;
  code *pcVar6;
  long lVar7;
  undefined8 unaff_s8;
  undefined8 in_ra;
  
  lVar7 = (long)((int)&stack0x00000000 + -0xd0);
  *(undefined1 **)(lVar7 + 0xb0) = &_gp;
  *(undefined8 *)(lVar7 + 0xc0) = in_ra;
  *(undefined8 *)(lVar7 + 0xb8) = unaff_s8;
  pcVar6 = (code *)(long)DAT_ffffffffbfc4385c;
  *(undefined8 *)(lVar7 + 0xa0) = unaff_s6;
  *(undefined8 *)(lVar7 + 0x98) = unaff_s5;
  *(undefined8 *)(lVar7 + 0x78) = unaff_s1;
  *(undefined8 *)(lVar7 + 0xa8) = unaff_s7;
  *(undefined8 *)(lVar7 + 0x90) = unaff_s4;
  *(undefined8 *)(lVar7 + 0x88) = unaff_s3;
  *(undefined8 *)(lVar7 + 0x80) = unaff_s2;
  *(undefined8 *)(lVar7 + 0x70) = unaff_s0;
  uVar3 = (*pcVar6)();
  lVar2 = (*(code *)(long)DAT_ffffffffbfc43f44)();
  lVar4 = (long)DAT_ffffffffbfc436f4;
  *(ulong *)(lVar2 + 0x138) = *(ulong *)(lVar2 + 0x138) | 0x1100;
  uVar5 = *(ulong *)(lVar2 + 0x130);
  SYNC(0);
  uVar1 = getCopReg(2,0);
  *(undefined4 *)
   ((long)((int)((uint)((ulong)*(undefined8 *)(lVar4 + 0x6068) >> 0x10) & 0xffff) >> (uVar3 & 0x1f))
   + 10) = uVar1;
  if ((uVar5 & 0x23) == 0) {
    *(ulong *)(lVar2 + 0x130) = *(ulong *)(lVar2 + 0x130) & 0xfffffffffffffeff;
  }
  else {
    setCopReg(2,in_zero,*(undefined4 *)((long)*(int *)(long)(int)(uVar3 * 4 + -0x7ffff5d8) + 6));
    (*(code *)(long)DAT_ffffffffbfc43ba8)();
  }
  return;
}

