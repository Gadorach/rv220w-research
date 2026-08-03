/*
 * Ghidra reconstructed C; not original Cisco source.
 * RV220W boot-chain/U-Boot analysis v1.1.0
 * Entry: ffffffffbfc23c08
 * Function: FUN_ffffffffbfc23c08
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

char * FUN_ffffffffbfc23c08
                 (char *param_1,ulong param_2,long param_3,int param_4,int param_5,ulong param_6)

{
  bool bVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined8 in_at;
  uint uVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  ulong uVar8;
  char cVar9;
  int iVar10;
  undefined1 *puVar11;
  int iVar12;
  
  uVar6 = (uint)param_3;
  iVar12 = (int)&stack0x00000000 + -0x50;
  puVar11 = (undefined1 *)(long)iVar12;
  setCopReg(2,param_3,*(undefined4 *)(param_6 + 4));
  iVar10 = DAT_ffffffffbfc436f4 + 0x1288;
  setCopReg(2,param_1,*(undefined4 *)(param_6 + 4));
  uVar8 = param_6 & 0xfffffffffffffffe;
  if (uVar6 - 2 < 0x23) {
    setCopReg(2,in_at,*(undefined4 *)(uVar8 + 0xe));
    cVar9 = '-';
    if ((long)param_2 < 0) {
      param_2 = -param_2;
    }
    else {
      setCopReg(2,0x20,*(undefined4 *)(uVar8 + 3));
      cVar9 = '+';
    }
    iVar7 = param_4 + -1;
    if ((param_6 & 0x20) != 0) {
      special2(param_3,0x10,8,0x2e);
      if (param_3 == 0x10) {
        iVar7 = param_4 + -3;
      }
      else {
        iVar7 = param_4 + -0x11;
      }
    }
    if (param_2 == 0) {
      iVar5 = 1;
      *puVar11 = 0x30;
    }
    else {
      do {
        uVar4 = (uint)param_2;
        uVar3 = uVar4 / uVar6;
        if (param_3 == 0) {
          trap(7);
        }
        param_2 = (ulong)uVar3;
        *puVar11 = *(undefined1 *)(long)(int)(iVar10 + uVar4 % uVar6);
        iVar5 = (int)puVar11 + 1;
        puVar11 = (undefined1 *)(long)iVar5;
      } while (uVar3 != 0);
      iVar5 = iVar5 - iVar12;
    }
    if (param_5 <= iVar5) {
      param_5 = iVar5;
    }
    iVar7 = iVar7 - param_5;
    if ((param_6 & 0x10) == 0) {
      while (bVar1 = 0 < iVar7, iVar7 = iVar7 + -1, bVar1) {
        *param_1 = ' ';
        param_1 = (char *)(long)((int)param_1 + 1);
      }
    }
    if (cVar9 != '\0') {
      *param_1 = cVar9;
      param_1 = (char *)(long)((int)param_1 + 1);
    }
    if ((param_6 & 0x20) != 0) {
      if (param_3 == 8) {
        *param_1 = '0';
        param_1 = (char *)(long)((int)param_1 + 1);
      }
      else if (param_3 == 0x10) {
        *param_1 = '0';
        param_1[1] = *(char *)((long)iVar10 + 0x21);
        param_1 = (char *)(long)((int)param_1 + 2);
      }
    }
    uVar2 = getCopReg(2,4);
    *(undefined4 *)(uVar8 + 0xc) = uVar2;
    while (iVar10 = iVar7 + -1, 0 < iVar7) {
      *param_1 = ' ';
      param_1 = (char *)(long)((int)param_1 + 1);
      iVar7 = iVar10;
    }
    while (bVar1 = iVar5 < param_5, param_5 = param_5 + -1, bVar1) {
      *param_1 = '0';
      param_1 = (char *)(long)((int)param_1 + 1);
    }
    while (bVar1 = 0 < iVar5, iVar5 = iVar5 + -1, bVar1) {
      *param_1 = *(char *)(long)(iVar12 + iVar5);
      param_1 = (char *)(long)((int)param_1 + 1);
    }
    for (; 0 < iVar10; iVar10 = iVar10 + -1) {
      *param_1 = ' ';
      param_1 = (char *)(long)((int)param_1 + 1);
    }
  }
  else {
    param_1 = (char *)0x0;
  }
  return param_1;
}

