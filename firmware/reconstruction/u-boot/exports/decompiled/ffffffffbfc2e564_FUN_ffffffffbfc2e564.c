/*
 * Ghidra reconstructed C; not original Cisco source.
 * RV220W boot-chain/U-Boot analysis v1.1.0
 * Entry: ffffffffbfc2e564
 * Function: FUN_ffffffffbfc2e564
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

undefined8 FUN_ffffffffbfc2e564(undefined8 param_1)

{
  bool bVar1;
  byte bVar2;
  int iVar3;
  byte *pbVar4;
  undefined8 uVar5;
  long lVar6;
  int iVar9;
  int *piVar7;
  ulong uVar8;
  undefined8 unaff_s0;
  ulong uVar10;
  undefined8 unaff_s1;
  undefined8 *puVar11;
  undefined8 in_ra;
  
  puVar11 = (undefined8 *)(long)((int)&stack0x00000000 + -0x20);
  puVar11[2] = &_gp;
  puVar11[1] = unaff_s1;
  *puVar11 = unaff_s0;
  iVar3 = DAT_ffffffffbfc436f0;
  puVar11[3] = in_ra;
  pbVar4 = (byte *)(*(code *)(long)(iVar3 + -0x1d60))();
  if (pbVar4 == (byte *)0x0) {
    (*(code *)(long)DAT_ffffffffbfc4400c)(DAT_ffffffffbfc436f4 + 0x1d58);
    uVar5 = 0xfffffffffffffffd;
  }
  else {
    lVar6 = (*(code *)(long)DAT_ffffffffbfc4390c)(param_1);
    if (lVar6 < 1) {
      prefetch(pbVar4,0);
      iVar3 = *(int *)(long)DAT_ffffffffbfc43774;
      iVar9 = (*(code *)(long)(DAT_ffffffffbfc436f0 + -0x1d80))(param_1);
      piVar7 = (int *)(long)(iVar9 * 8 + iVar3);
      iVar3 = *piVar7;
      uVar5 = special2(1,(long)iVar3,0,0x28);
      *piVar7 = (int)uVar5;
      bVar2 = *pbVar4;
      while ((ulong)bVar2 != (long)iVar3) {
        lVar6 = (long)(int)((iVar3 - (uint)bVar2) + -1);
        special2(lVar6,lVar6,5,0x32);
        do {
          bVar1 = lVar6 != 0;
          lVar6 = (long)((int)lVar6 + -1);
        } while (bVar1);
        bVar2 = *pbVar4;
      }
      uVar8 = *(ulong *)(pbVar4 + 8) >> 0x20 & 0x1fffffff;
      if (uVar8 != 0) {
        uVar5 = (*(code *)(long)(DAT_ffffffffbfc436f0 + -0x1ba4))(uVar8 << 7);
        uVar10 = *(ulong *)(pbVar4 + 8);
        uVar8 = (*(code *)(long)(DAT_ffffffffbfc436f0 + -0x1ae8))(uVar5);
        SYNC(4);
        SYNC(4);
        *(undefined8 *)(uVar8 & 0xffffffffff | (uVar10 >> 0x3d | 0x800128) << 0x28) = 0;
        *(ulong *)(pbVar4 + 8) = *(ulong *)(pbVar4 + 8) & 0xe0000000ffffffff;
      }
      *pbVar4 = *pbVar4 + 1;
      SYNC(4);
      SYNC(4);
      uVar5 = 0;
    }
    else {
      (*(code *)(long)DAT_ffffffffbfc4400c)(DAT_ffffffffbfc436f4 + 0x1da0);
      uVar5 = 0xfffffffffffffffe;
    }
  }
  return uVar5;
}

