/*
 * Ghidra reconstructed C; not original Cisco source.
 * RV220W boot-chain/U-Boot analysis v1.1.0
 * Entry: ffffffffbfc2bd08
 * Function: FUN_ffffffffbfc2bd08
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

void FUN_ffffffffbfc2bd08(long param_1)

{
  long lVar1;
  ulong *puVar2;
  undefined8 uVar3;
  long lVar4;
  ulong uVar5;
  undefined8 unaff_s0;
  undefined8 unaff_s1;
  int iVar6;
  undefined8 unaff_s2;
  ulong uVar7;
  undefined8 unaff_s3;
  int *piVar8;
  undefined8 unaff_s4;
  code *pcVar9;
  undefined8 *puVar10;
  undefined8 in_ra;
  
  puVar10 = (undefined8 *)(long)((int)&stack0x00000000 + -0x40);
  puVar10[5] = &_gp;
  puVar10[3] = unaff_s3;
  piVar8 = (int *)(long)*(int *)(param_1 + 0x34);
  pcVar9 = (code *)(long)DAT_ffffffffbfc43bc0;
  lVar4 = (long)piVar8[1];
  puVar10[6] = in_ra;
  puVar10[4] = unaff_s4;
  puVar10[2] = unaff_s2;
  puVar10[1] = unaff_s1;
  *puVar10 = unaff_s0;
  lVar1 = (*pcVar9)();
  if (lVar1 != 1) {
    lVar4 = (long)piVar8[1];
    lVar1 = (*(code *)(long)DAT_ffffffffbfc43bc0)();
    if (lVar1 != 2) {
      return;
    }
  }
  iVar6 = piVar8[1];
  special2((long)iVar6,lVar4,0x1b,0x32);
  pcVar9 = (code *)(long)(DAT_ffffffffbfc436f0 + -0x6504);
  (*pcVar9)(&DAT_80011800b0000000 + lVar4,
            *(ulong *)(&DAT_80011800b0000000 + lVar4) & ~(1L << ((long)*piVar8 & 3U)));
  uVar5 = (ulong)(uint)piVar8[1];
  special2(uVar5,uVar5,0x1b,0x32);
  uVar7 = (long)iVar6 & 3;
  (*pcVar9)(&DAT_80011800b0000008 + uVar5,
            *(ulong *)(&DAT_80011800b0000008 + uVar5) & ~(1L << ((long)*piVar8 & 3U)));
  iVar6 = DAT_ffffffffbfc436f0 + -0x6588;
  puVar2 = (ulong *)(*(code *)(long)iVar6)(uVar7,piVar8[1]);
  uVar5 = *puVar2;
  (*pcVar9)(puVar2,uVar5 & 0xfffffffffffffffe);
  uVar3 = (*(code *)(long)(DAT_ffffffffbfc436f0 + -0x6530))(uVar7,piVar8[1]);
  (*pcVar9)(uVar3,1);
  uVar3 = (*(code *)(long)(DAT_ffffffffbfc436f0 + -0x655c))(uVar7,piVar8[1]);
  (*pcVar9)(uVar3,0);
  uVar3 = (*(code *)(long)iVar6)(uVar7,piVar8[1]);
  (*pcVar9)(uVar3,uVar5);
  return;
}

