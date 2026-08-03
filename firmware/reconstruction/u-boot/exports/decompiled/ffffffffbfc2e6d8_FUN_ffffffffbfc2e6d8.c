/*
 * Ghidra reconstructed C; not original Cisco source.
 * RV220W boot-chain/U-Boot analysis v1.1.0
 * Entry: ffffffffbfc2e6d8
 * Function: FUN_ffffffffbfc2e6d8
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

undefined8 FUN_ffffffffbfc2e6d8(undefined8 param_1,long param_2,ulong param_3,int param_4)

{
  long lVar1;
  undefined8 *puVar2;
  undefined8 uVar3;
  long lVar4;
  ulong uVar5;
  int iVar6;
  ulong uVar7;
  undefined8 unaff_s0;
  undefined8 unaff_s1;
  int *piVar8;
  undefined8 unaff_s2;
  undefined8 unaff_s3;
  undefined8 unaff_s4;
  undefined8 unaff_s5;
  int iVar9;
  undefined8 *puVar10;
  undefined8 in_ra;
  
  puVar10 = (undefined8 *)(long)((int)&stack0x00000000 + -0x40);
  puVar10[6] = &_gp;
  puVar10[1] = unaff_s1;
  puVar10[5] = unaff_s5;
  piVar8 = (int *)(long)DAT_ffffffffbfc43774;
  puVar10[4] = unaff_s4;
  iVar6 = *piVar8;
  puVar10[3] = unaff_s3;
  puVar10[2] = unaff_s2;
  puVar10[7] = in_ra;
  *puVar10 = unaff_s0;
  iVar9 = DAT_ffffffffbfc436f4;
  if (iVar6 == 0) {
    lVar1 = (*(code *)(long)DAT_ffffffffbfc43fd0)(0x7800,0x80,DAT_ffffffffbfc436f4 + 0x1c28);
    *piVar8 = (int)lVar1;
    if (lVar1 == 0) {
      puVar2 = (undefined8 *)(*(code *)(long)DAT_ffffffffbfc437ec)(iVar9 + 0x1c28);
      if (puVar2 == (undefined8 *)0x0) {
        (*(code *)(long)DAT_ffffffffbfc4400c)(DAT_ffffffffbfc436f4 + 0x1de0,iVar9 + 0x1c28);
        return 0xffffffffffffffff;
      }
      iVar6 = (*(code *)(long)(DAT_ffffffffbfc436f0 + -0x1ba4))(*puVar2);
      *piVar8 = iVar6;
    }
    else {
      (*(code *)(long)DAT_ffffffffbfc43a54)(lVar1,0,0x7800);
    }
  }
  lVar1 = (*(code *)(long)(DAT_ffffffffbfc436f0 + -0x1d60))(param_1);
  if (lVar1 == 0) {
    uVar3 = 0xfffffffffffffffd;
  }
  else {
    uVar3 = 0xfffffffffffffffd;
    if (((param_2 == 0) && (uVar3 = 0xfffffffffffffffd, param_3 < 8)) &&
       (uVar3 = 0xfffffffffffffffd, param_4 - 0x80U < 0xff81)) {
      uVar5 = *(ulong *)(lVar1 + 8);
      if ((uVar5 >> 0x20 & 0x1fffffff) == 0) {
        if ((*(long *)((param_3 | 0x800128) << 0x28) == 0) ||
           (lVar4 = (*(code *)(long)(DAT_ffffffffbfc436f0 + -0x1ba4))(), lVar4 == 0)) {
          (*(code *)(long)DAT_ffffffffbfc4400c)(DAT_ffffffffbfc436f4 + 0x1f48);
          uVar3 = 0xffffffffffffffff;
        }
        else {
          (*(code *)(long)DAT_ffffffffbfc43a54)(lVar1,0,0x10);
          uVar5 = (ulong)((param_4 >> 3) + -1);
          special2(uVar5,uVar5,0xd,0x32);
          iVar6 = DAT_ffffffffbfc436f0 + -0x1ae8;
          *(undefined4 *)(lVar1 + 4) = 0;
          *(ulong *)(lVar1 + 8) =
               *(ulong *)(lVar1 + 8) & 0x1ffffffffc001fff | param_3 << 0x3d | uVar5;
          uVar5 = (*(code *)(long)iVar6)(lVar4);
          special2(uVar5,uVar5,7,0x3a);
          lVar4 = special2(uVar5,uVar5,0,0x33);
          iVar9 = DAT_ffffffffbfc436f0 + -0x1d80;
          iVar6 = *(int *)(lVar4 + 0x94);
          *(ulong *)(lVar1 + 8) = *(ulong *)(lVar1 + 8) & 0xe0000000ffffffff | uVar5;
          iVar6 = *(int *)(long)iVar6;
          iVar9 = (*(code *)(long)iVar9)(param_1);
          *(undefined8 *)(long)(iVar9 * 8 + iVar6) = 0;
          SYNC(4);
          SYNC(4);
          uVar3 = 0;
        }
      }
      else {
        uVar7 = (ulong)*(int *)(lVar1 + 4);
        if (uVar7 == 0) {
          uVar7 = uVar5 >> 0x3d;
          if (param_3 == uVar7) {
            uVar5 = uVar5 >> 0xd & 0x1fff;
            if ((long)((param_4 >> 3) + -1) == uVar5) {
              SYNC(4);
              SYNC(4);
              return 0xfffffffffffffffc;
            }
            uVar7 = (ulong)(((int)uVar5 + 1) * 8);
            iVar6 = DAT_ffffffffbfc436f4 + 0x1ee8;
          }
          else {
            iVar6 = DAT_ffffffffbfc436f4 + 0x1e88;
          }
        }
        else {
          iVar6 = DAT_ffffffffbfc436f4 + 0x1e28;
        }
        (*(code *)(long)DAT_ffffffffbfc4400c)(iVar6,uVar7);
        uVar3 = 0xfffffffffffffffd;
      }
    }
  }
  return uVar3;
}

