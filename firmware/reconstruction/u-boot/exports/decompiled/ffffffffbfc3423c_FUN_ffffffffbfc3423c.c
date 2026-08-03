/*
 * Ghidra reconstructed C; not original Cisco source.
 * RV220W boot-chain/U-Boot analysis v1.1.0
 * Entry: ffffffffbfc3423c
 * Function: FUN_ffffffffbfc3423c
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

undefined8 FUN_ffffffffbfc3423c(undefined8 param_1,long param_2,ulong param_3)

{
  ulong uVar1;
  undefined8 uVar2;
  undefined8 in_at;
  ulong uVar3;
  ulong uVar4;
  long lVar5;
  long lVar6;
  undefined8 unaff_s0;
  ulong uVar7;
  int iVar8;
  long unaff_s1;
  undefined8 unaff_s2;
  ulong uVar9;
  ulong uVar10;
  undefined8 unaff_s3;
  code *pcVar11;
  undefined8 unaff_s4;
  undefined8 unaff_s5;
  undefined8 unaff_s6;
  undefined8 unaff_s7;
  undefined8 *puVar12;
  undefined8 in_ra;
  
  puVar12 = (undefined8 *)(long)((int)&stack0x00000000 + -0x50);
  puVar12[8] = &_gp;
  puVar12[5] = unaff_s5;
  puVar12[7] = unaff_s7;
  puVar12[6] = unaff_s6;
  puVar12[9] = in_ra;
  puVar12[4] = unaff_s4;
  puVar12[3] = unaff_s3;
  puVar12[2] = unaff_s2;
  puVar12[1] = unaff_s1;
  setCopReg(2,in_at,*(undefined4 *)(param_2 + 0x3c));
  *puVar12 = unaff_s0;
  lVar6 = (long)(int)(((uint)param_3 & 0xff) - 1);
  uVar2 = special2(param_1,unaff_s1,0x1b,0x32);
  special2(lVar6,lVar6,4,0x32);
  (*(code *)(long)(DAT_ffffffffbfc436f0 + 0x3798))(unaff_s1 + -0x7ffee7ff6ffffe00,lVar6);
  lVar6 = 0;
  uVar7 = 1;
  uVar9 = 0;
  while( true ) {
    iVar8 = (int)uVar7;
    uVar4 = (long)(iVar8 + 1) & 0xf;
    lVar5 = special2(lVar6,uVar4,3,0x32);
    uVar1 = ((long)(iVar8 + 2) & 0xfU) << 0xc;
    lVar6 = (long)((int)lVar6 + 1);
    uVar10 = (ulong)((int)uVar9 + 4);
    if ((long)param_3 <= (long)uVar9) break;
    uVar3 = special2(uVar9 & 0xf | uVar7 << 4 | uVar4 << 8 | uVar1,0,0,0x2d);
    (*(code *)(long)(DAT_ffffffffbfc436f0 + 0x3798))
              (uVar4 + unaff_s1 + lVar5,
               uVar9 & 0xf | uVar7 << 4 | uVar4 << 8 | uVar1 | (~(uVar3 & 1) & 1) << 0x10);
    uVar7 = (long)(iVar8 + 4) & 0xf;
    uVar9 = uVar10;
  }
  (*(code *)(long)(DAT_ffffffffbfc436f0 + 0x3798))
            (unaff_s1 + -0x7ffee7ff6ffffdf8,param_3 & 0x7f | 0x100);
  setCopReg(2,uVar2,*(undefined4 *)(param_2 + 0x58));
  pcVar11 = (code *)(long)(DAT_ffffffffbfc436f0 + 0x3798);
  special2(param_1,uVar10,0x1b,0x32);
  (*pcVar11)(uVar10 + 0x8001180090000608,0);
  (*pcVar11)(uVar10 + 0x80011800080004b0,0x408);
  (*pcVar11)(uVar10 + 0x80011800080004b8,4);
  (*pcVar11)(uVar10 + 0x80011800080004c0,0);
  lVar6 = 0;
  uVar7 = 1;
  (*pcVar11)(uVar10 + 0x8001180090000628,0x20ffff);
  uVar9 = 0;
  while( true ) {
    iVar8 = (int)uVar7;
    uVar1 = ((long)(iVar8 + 1) & 0xfU) << 8;
    uVar4 = (long)(iVar8 + 2) & 0xf;
    lVar5 = special2(lVar6,uVar4,3,0x32);
    lVar6 = (long)((int)lVar6 + 1);
    if ((long)param_3 <= (long)uVar9) break;
    uVar3 = special2(uVar9 & 0xf | uVar7 << 4 | uVar1 | uVar4 << 0xc,0,0,0x2d);
    (*(code *)(long)(DAT_ffffffffbfc436f0 + 0x3798))
              (uVar4 + lVar5,
               uVar9 & 0xf | uVar7 << 4 | uVar1 | uVar4 << 0xc | (~(uVar3 & 1) & 1) << 0x10);
    uVar7 = (long)(iVar8 + 4) & 0xf;
    uVar9 = (long)((int)uVar9 + 4);
  }
  (*(code *)(long)(DAT_ffffffffbfc436f0 + 0x3798))
            (uVar10 + 0x8001180090000630,param_3 & 0x7f | 0x100);
  return 0;
}

