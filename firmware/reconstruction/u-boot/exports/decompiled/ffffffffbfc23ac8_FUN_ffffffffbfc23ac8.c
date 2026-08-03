/*
 * Ghidra reconstructed C; not original Cisco source.
 * RV220W boot-chain/U-Boot analysis v1.1.0
 * Entry: ffffffffbfc23ac8
 * Function: FUN_ffffffffbfc23ac8
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

long FUN_ffffffffbfc23ac8(byte *param_1,int *param_2,ulong param_3)

{
  byte bVar1;
  byte bVar2;
  undefined4 uVar3;
  int iVar4;
  undefined8 in_at;
  long lVar5;
  int iVar6;
  ulong uVar7;
  long lVar8;
  
  iVar4 = DAT_ffffffffbfc43a8c;
  if (*param_1 == 0x30) {
    iVar6 = (int)param_1;
    param_1 = (byte *)(long)(iVar6 + 1);
    if ((*param_1 == 0x78) &&
       ((*(byte *)(long)(int)((uint)param_1[1] + DAT_ffffffffbfc43a8c) & 0x44) != 0)) {
      param_3 = 0x10;
      param_1 = (byte *)(long)(iVar6 + 2);
    }
    else if (param_3 == 0) {
      param_3 = 8;
    }
  }
  else if (param_3 == 0) {
    param_3 = 10;
  }
  lVar8 = 0;
  while( true ) {
    bVar1 = *param_1;
    bVar2 = *(byte *)(long)(int)((uint)bVar1 + iVar4);
    if ((bVar2 & 0x44) == 0) break;
    uVar3 = getCopReg(2,2);
    *(undefined4 *)((ulong)bVar2 + 0xb) = uVar3;
    setCopReg(2,in_at,*(undefined4 *)((ulong)bVar2 + 8));
    setCopReg(2,in_at,*(undefined4 *)((ulong)*(byte *)(long)(int)((uint)bVar1 + iVar4) + 2));
    uVar7 = (ulong)(int)((bVar1 - 0x20 & 0xff) - 0x37);
    lVar5 = special2(lVar8,param_3 & 0xffffffff,0,3);
    if ((param_3 & 0xffffffff) <= uVar7) break;
    lVar8 = lVar5 + uVar7;
    param_1 = (byte *)(long)((int)param_1 + 1);
  }
  if (param_2 != (int *)0x0) {
    *param_2 = (int)param_1;
  }
  return lVar8;
}

