/*
 * Ghidra reconstructed C; not original Cisco source.
 * RV220W boot-chain/U-Boot analysis v1.1.0
 * Entry: ffffffffbfc11bdc
 * Function: FUN_ffffffffbfc11bdc
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

ulong FUN_ffffffffbfc11bdc(long param_1,ulong param_2)

{
  int iVar1;
  long lVar2;
  ulong uVar3;
  undefined8 unaff_s0;
  ulong uVar4;
  ulong uVar5;
  undefined8 unaff_s1;
  undefined8 unaff_s2;
  uint uVar6;
  undefined8 unaff_s3;
  undefined8 unaff_s4;
  uint uVar7;
  undefined8 unaff_s5;
  undefined8 unaff_s6;
  byte bVar8;
  code *pcVar9;
  byte *pbVar10;
  undefined8 in_ra;
  int iVar11;
  
  iVar11 = (int)&stack0x00000000;
  pbVar10 = (byte *)(long)(iVar11 + -0x60);
  *(undefined1 **)(pbVar10 + 0x48) = &_gp;
  *(undefined8 *)(pbVar10 + 0x10) = unaff_s0;
  *(undefined8 *)(pbVar10 + 0x40) = unaff_s6;
  *(undefined8 *)(pbVar10 + 0x38) = unaff_s5;
  *(undefined8 *)(pbVar10 + 0x28) = unaff_s3;
  bVar8 = 0;
  *(undefined8 *)(pbVar10 + 0x18) = unaff_s1;
  *(undefined8 *)(pbVar10 + 0x50) = in_ra;
  *(undefined8 *)(pbVar10 + 0x30) = unaff_s4;
  *(undefined8 *)(pbVar10 + 0x20) = unaff_s2;
  uVar4 = (ulong)((int)param_2 << 0x10);
  for (uVar5 = uVar4; (long)uVar5 < (long)(uVar4 | 0xff00); uVar5 = (ulong)((int)uVar5 + 0x100)) {
    uVar7 = (int)uVar5 >> 8;
    if (uVar5 != (long)(*(int *)(param_1 + 4) << 0x10)) {
      uVar6 = uVar7 & 7;
      if ((uVar6 == 0) || (bVar8 != 0)) {
        (*(code *)(long)DAT_ffffffffbfc43744)(param_1,uVar5,0xe,pbVar10);
        (*(code *)(long)DAT_ffffffffbfc437dc)(param_1,uVar5,0,iVar11 + -0x5e);
        if ((ushort)(*(short *)(pbVar10 + 2) - 1U) < 0xfffe) {
          if (uVar6 == 0) {
            bVar8 = *pbVar10 & 0x80;
          }
          (*(code *)(long)DAT_ffffffffbfc437dc)(param_1,uVar5,2,iVar11 + -0x5c);
          (*(code *)(long)DAT_ffffffffbfc437dc)(param_1,uVar5,10,iVar11 + -0x5a);
          pcVar9 = (code *)(long)DAT_ffffffffbfc43de8;
          if ((*(short *)(pbVar10 + 4) == 0x686) && (*(short *)(pbVar10 + 2) == 0x1106)) {
            (*(code *)(long)DAT_ffffffffbfc4400c)(DAT_ffffffffbfc436f4 + -0x53b8);
            (*(code *)(long)DAT_ffffffffbfc43744)(param_1,uVar5,0x48,iVar11 + -0x5f);
            pcVar9 = (code *)(long)DAT_ffffffffbfc437a4;
            pbVar10[1] = pbVar10[1] & 0xfd;
            (*pcVar9)(param_1,uVar5,0x48);
            pcVar9 = (code *)(long)DAT_ffffffffbfc43de8;
          }
          lVar2 = (*pcVar9)(param_1,*(undefined2 *)(pbVar10 + 6),*(undefined2 *)(pbVar10 + 2),
                            *(undefined2 *)(pbVar10 + 4),uVar5 >> 0x10 & 0xff,uVar5 >> 0xb & 0x1f,
                            uVar7 & 7);
          if (lVar2 == 0) {
            uVar3 = (*(code *)(long)DAT_ffffffffbfc43810)(param_1,uVar5,0);
            if (param_2 < uVar3) {
              param_2 = uVar3;
            }
            iVar1 = *(int *)(param_1 + 0x118);
          }
          else {
            (*(code *)(long)*(int *)(lVar2 + 0x18))(param_1,uVar5);
            iVar1 = *(int *)(param_1 + 0x118);
          }
          if ((code *)(long)iVar1 != (code *)0x0) {
            (*(code *)(long)iVar1)(param_1,uVar5);
          }
        }
      }
    }
  }
  return param_2;
}

