/*
 * Ghidra reconstructed C; not original Cisco source.
 * RV220W boot-chain/U-Boot analysis v1.1.0
 * Entry: ffffffffbfc115b4
 * Function: FUN_ffffffffbfc115b4
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

ulong FUN_ffffffffbfc115b4(uint *param_1,int param_2)

{
  bool bVar1;
  int iVar2;
  long lVar3;
  uint *puVar4;
  undefined8 unaff_s0;
  ulong uVar5;
  undefined8 unaff_s1;
  int *piVar7;
  undefined8 unaff_s2;
  int iVar8;
  undefined8 unaff_s3;
  undefined8 unaff_s4;
  undefined8 unaff_s5;
  byte bVar9;
  byte *pbVar10;
  undefined8 in_ra;
  int iVar6;
  int iVar11;
  
  iVar11 = (int)&stack0x00000000;
  pbVar10 = (byte *)(long)(iVar11 + -0x50);
  *(undefined1 **)(pbVar10 + 0x40) = &_gp;
  *(undefined8 *)(pbVar10 + 0x18) = unaff_s1;
  *(undefined8 *)(pbVar10 + 0x38) = unaff_s5;
  lVar3 = (long)DAT_ffffffffbfc436f4;
  bVar9 = 0;
  *(undefined8 *)(pbVar10 + 0x30) = unaff_s4;
  iVar2 = *(int *)(lVar3 + 0x4aa0);
  *(undefined8 *)(pbVar10 + 0x28) = unaff_s3;
  *(undefined8 *)(pbVar10 + 0x48) = in_ra;
  *(undefined8 *)(pbVar10 + 0x20) = unaff_s2;
  *(undefined8 *)(pbVar10 + 0x10) = unaff_s0;
  do {
    piVar7 = (int *)(long)iVar2;
    if (piVar7 == (int *)0x0) {
      return 0xffffffffffffffff;
    }
    iVar2 = piVar7[1];
    while (iVar8 = iVar2, iVar8 <= piVar7[2]) {
      iVar6 = iVar8 << 0x10;
      while( true ) {
        uVar5 = (ulong)iVar6;
        iVar2 = iVar8 + 1;
        if ((long)((iVar8 + 1) * 0x10000) <= (long)uVar5) break;
        if ((uVar5 >> 8 & 7) == 0) {
          (*(code *)(long)DAT_ffffffffbfc437d4)(uVar5,0xe,pbVar10);
          bVar9 = *pbVar10 & 0x80;
LAB_ffffffffbfc11638:
          (*(code *)(long)DAT_ffffffffbfc43b3c)(uVar5,0,iVar11 + -0x4e);
          (*(code *)(long)DAT_ffffffffbfc43b3c)(uVar5,2,iVar11 + -0x4c);
          for (puVar4 = param_1; *puVar4 != 0; puVar4 = (uint *)(long)((int)puVar4 + 8)) {
            if ((((uint)*(ushort *)(pbVar10 + 2) == *puVar4) &&
                ((uint)*(ushort *)(pbVar10 + 4) == puVar4[1])) &&
               (bVar1 = param_2 < 1, param_2 = param_2 + -1, bVar1)) {
              return uVar5;
            }
          }
        }
        else if (bVar9 != 0) goto LAB_ffffffffbfc11638;
        iVar6 = iVar6 + 0x100;
      }
    }
    iVar2 = *piVar7;
  } while( true );
}

