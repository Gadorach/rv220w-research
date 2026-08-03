/*
 * Ghidra reconstructed C; not original Cisco source.
 * RV220W boot-chain/U-Boot analysis v1.1.0
 * Entry: ffffffffbfc2077c
 * Function: FUN_ffffffffbfc2077c
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

int FUN_ffffffffbfc2077c(ulong param_1,long param_2)

{
  int iVar2;
  long lVar1;
  uint uVar3;
  uint uVar5;
  long lVar4;
  uint uVar6;
  int iVar7;
  undefined8 unaff_s0;
  undefined8 unaff_s1;
  long lVar8;
  undefined8 unaff_s2;
  code *pcVar9;
  undefined8 *puVar10;
  undefined8 in_ra;
  
  puVar10 = (undefined8 *)(long)((int)&stack0x00000000 + -0x30);
  puVar10[3] = &_gp;
  *puVar10 = unaff_s0;
  puVar10[4] = in_ra;
  puVar10[2] = unaff_s2;
  puVar10[1] = unaff_s1;
  if (-1 < param_2) {
    if (param_1 < 9) {
      iVar2 = (*(code *)(long)DAT_ffffffffbfc43e1c)(param_2);
      return iVar2;
    }
    uVar6 = (int)param_2 + 0xb;
    if (param_1 < 0x10) {
      param_1 = 0x10;
    }
    if ((int)uVar6 < 0x17) {
      uVar6 = 0x10;
    }
    else {
      uVar6 = uVar6 & 0xfffffff8;
    }
    uVar5 = (uint)param_1;
    lVar1 = (*(code *)(long)DAT_ffffffffbfc43e1c)(uVar5 + uVar6 + 0x10);
    if (lVar1 != 0) {
      uVar3 = (uint)lVar1;
      if (param_1 == 0) {
        trap(7);
      }
      iVar2 = uVar3 - 8;
      lVar8 = (long)iVar2;
      lVar1 = lVar8;
      if (uVar3 % uVar5 != 0) {
        pcVar9 = (code *)(long)DAT_ffffffffbfc43734;
        iVar7 = ((uVar3 + uVar5) - 1 & -uVar5) - 8;
        if ((uint)(iVar7 - iVar2) < 0x10) {
          iVar7 = iVar7 + uVar5;
        }
        lVar1 = (long)iVar7;
        uVar5 = (*(uint *)(lVar8 + 4) & 0xfffffffc) - (iVar7 - iVar2);
        lVar4 = (long)(int)(iVar7 + uVar5);
        *(uint *)(lVar1 + 4) = uVar5 | 1;
        *(uint *)(lVar4 + 4) = *(uint *)(lVar4 + 4) | 1;
        *(uint *)(lVar8 + 4) = *(uint *)(lVar8 + 4) & 1 | iVar7 - iVar2;
        (*pcVar9)();
      }
      uVar5 = (*(uint *)(lVar1 + 4) & 0xfffffffc) - uVar6;
      iVar2 = (int)lVar1 + uVar6;
      if (0xf < (int)uVar5) {
        *(uint *)((long)iVar2 + 4) = uVar5 | 1;
        pcVar9 = (code *)(long)DAT_ffffffffbfc43734;
        *(uint *)(lVar1 + 4) = *(uint *)(lVar1 + 4) & 1 | uVar6;
        (*pcVar9)(iVar2 + 8);
      }
      return (int)lVar1 + 8;
    }
  }
  return 0;
}

