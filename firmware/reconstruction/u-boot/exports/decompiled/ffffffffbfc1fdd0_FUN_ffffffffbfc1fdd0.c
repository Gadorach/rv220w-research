/*
 * Ghidra reconstructed C; not original Cisco source.
 * RV220W boot-chain/U-Boot analysis v1.1.0
 * Entry: ffffffffbfc1fdd0
 * Function: FUN_ffffffffbfc1fdd0
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

/* WARNING: Removing unreachable block (ram,0xffffffffbfc1ff34) */
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

void FUN_ffffffffbfc1fdd0(long param_1)

{
  undefined4 uVar1;
  bool bVar2;
  uint uVar3;
  uint uVar5;
  long lVar4;
  long lVar6;
  long lVar8;
  int iVar10;
  uint uVar11;
  long lVar12;
  int iVar7;
  int iVar9;
  
  iVar10 = DAT_ffffffffbfc436f4;
  if (param_1 != 0) {
    iVar9 = (int)param_1 + -8;
    lVar8 = (long)iVar9;
    uVar5 = *(uint *)(lVar8 + 4) & 0xfffffffe;
    uVar11 = *(uint *)(lVar8 + 4) & 1;
    iVar7 = iVar9 + uVar5;
    lVar6 = (long)iVar7;
    lVar12 = (long)(DAT_ffffffffbfc436f4 + 0x32a8);
    uVar3 = *(uint *)(lVar6 + 4) & 0xfffffffc;
    if (lVar6 == *(int *)(lVar12 + 8)) {
      uVar5 = uVar5 + uVar3;
      if (uVar11 == 0) {
        lVar8 = (long)(iVar9 - *(int *)(param_1 + -8));
        uVar5 = uVar5 + *(int *)(param_1 + -8);
        iVar10 = *(int *)(lVar8 + 0xc);
        iVar7 = *(int *)(lVar8 + 8);
        *(int *)((long)iVar10 + 8) = iVar7;
        *(int *)((long)iVar7 + 0xc) = iVar10;
      }
      lVar6 = (long)DAT_ffffffffbfc436f4;
      *(int *)(lVar12 + 8) = (int)lVar8;
      uVar3 = *(uint *)(lVar6 + 0x2910);
      *(uint *)(lVar8 + 4) = uVar5 | 1;
      if (uVar3 <= uVar5) {
        (*(code *)(long)DAT_ffffffffbfc43ab0)(*(undefined4 *)((long)DAT_ffffffffbfc436f4 + 0x4f60));
        return;
      }
    }
    else {
      *(uint *)(lVar6 + 4) = uVar3;
      if (uVar11 == 0) {
        lVar8 = (long)(iVar9 - *(int *)(param_1 + -8));
        iVar9 = *(int *)(lVar8 + 8);
        uVar5 = uVar5 + *(int *)(param_1 + -8);
        if ((long)iVar9 == (long)(iVar10 + 0x32b0)) {
          bVar2 = true;
        }
        else {
          iVar10 = *(int *)(lVar8 + 0xc);
          bVar2 = false;
          *(int *)((long)iVar10 + 8) = iVar9;
          *(int *)((long)iVar9 + 0xc) = iVar10;
        }
      }
      else {
        bVar2 = false;
      }
      uVar1 = getCopReg(2,0);
      *(undefined4 *)((long)*(int *)((long)(int)(iVar7 + uVar3) + 4) + 0x16) = uVar1;
      uVar5 = uVar5 + uVar3;
      iVar10 = (int)lVar8;
      if (!bVar2) {
        iVar7 = *(int *)(lVar6 + 8);
        lVar4 = (long)iVar7;
        if (lVar4 == DAT_ffffffffbfc436f4 + 0x32b0) {
          *(int *)(lVar4 + 0xc) = iVar10;
          *(uint *)(long)(int)(iVar10 + uVar5) = uVar5;
          *(int *)(lVar4 + 8) = iVar10;
          *(uint *)(lVar8 + 4) = uVar5 | 1;
          *(int *)(lVar8 + 8) = iVar7;
          *(int *)(lVar8 + 0xc) = iVar7;
          return;
        }
      }
      iVar7 = *(int *)(lVar6 + 8);
      iVar9 = *(int *)(lVar6 + 0xc);
      *(int *)((long)iVar9 + 8) = iVar7;
      *(int *)((long)iVar7 + 0xc) = iVar9;
      *(uint *)(lVar8 + 4) = uVar5 | 1;
      *(uint *)(long)(int)(iVar10 + uVar5) = uVar5;
      if (!bVar2) {
        uVar3 = uVar5 >> 9;
        if (uVar5 < 0x200) {
          uVar3 = *(uint *)(lVar12 + 4);
          iVar9 = (uVar5 >> 3) * 8 + DAT_ffffffffbfc436f4 + 0x32a8;
          *(int *)(lVar8 + 0xc) = iVar9;
          iVar7 = *(int *)((long)iVar9 + 8);
          *(uint *)(lVar12 + 4) = uVar3 | 1 << ((int)(uVar5 >> 3) >> 2 & 0x1fU);
          *(int *)(lVar8 + 8) = iVar7;
          *(int *)((long)iVar7 + 0xc) = iVar10;
          *(int *)((long)iVar9 + 8) = iVar10;
          return;
        }
        if (uVar3 < 5) {
          iVar7 = (uVar5 >> 6) + 0x38;
        }
        else if (uVar3 < 0x15) {
          iVar7 = uVar3 + 0x5b;
        }
        else if (uVar3 < 0x55) {
          iVar7 = (uVar5 >> 0xc) + 0x6e;
        }
        else if (uVar3 < 0x155) {
          iVar7 = (uVar5 >> 0xf) + 0x77;
        }
        else if (uVar3 < 0x555) {
          iVar7 = (uVar5 >> 0x12) + 0x7c;
        }
        else {
          iVar7 = 0x7e;
        }
        lVar4 = (long)(iVar7 * 8 + DAT_ffffffffbfc436f4 + 0x32a8);
        lVar6 = (long)*(int *)(lVar4 + 8);
        if (lVar6 == lVar4) {
          *(uint *)(lVar12 + 4) = *(uint *)(lVar12 + 4) | 1 << (iVar7 >> 2 & 0x1fU);
          lVar12 = lVar6;
        }
        else {
          do {
            if ((*(uint *)(lVar6 + 4) & 0xfffffffc) <= uVar5) break;
            lVar6 = (long)*(int *)(lVar6 + 8);
          } while (lVar6 != lVar4);
          lVar12 = (long)*(int *)(lVar6 + 0xc);
        }
        *(int *)(lVar8 + 0xc) = (int)lVar12;
        *(int *)(lVar8 + 8) = (int)lVar6;
        *(int *)(lVar6 + 0xc) = iVar10;
        *(int *)(lVar12 + 8) = iVar10;
      }
    }
  }
  return;
}

