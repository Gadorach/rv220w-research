/*
 * Ghidra reconstructed C; not original Cisco source.
 * RV220W boot-chain/U-Boot analysis v1.1.0
 * Entry: ffffffffbfc53dc4
 * Function: FUN_ffffffffbfc53dc4
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

void FUN_ffffffffbfc53dc4(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  short sVar3;
  undefined8 in_zero;
  int *piVar4;
  undefined2 *puVar5;
  undefined8 unaff_s0;
  int *piVar6;
  long lVar7;
  undefined8 unaff_s1;
  undefined8 unaff_s2;
  int *piVar8;
  undefined8 unaff_s3;
  int *piVar9;
  undefined8 unaff_s4;
  code *pcVar10;
  undefined8 *puVar11;
  undefined8 in_ra;
  
  puVar11 = (undefined8 *)(long)((int)&stack0x00000000 + -0x40);
  puVar11[5] = &_gp;
  puVar11[3] = unaff_s3;
  *puVar11 = unaff_s0;
  piVar9 = (int *)(long)iRamffffffffbfc55cfc;
  piVar6 = (int *)(long)iRamffffffffbfc55d70;
  puVar11[2] = unaff_s2;
  puVar11[1] = unaff_s1;
  piVar8 = (int *)(long)iRamffffffffbfc55dc8;
  iVar1 = *piVar6;
  *piVar9 = param_1 + 0x22;
  piVar4 = (int *)(long)iRamffffffffbfc55c8c;
  pcVar10 = (code *)(long)iRamffffffffbfc55d98;
  *piVar8 = param_1 + 0xe;
  puVar11[6] = in_ra;
  puVar11[4] = unaff_s4;
  *piVar4 = param_1;
  (*pcVar10)(iVar1 + 8,param_1 + 6,6);
  (*(code *)(long)iRamffffffffbfc55d98)(*piVar6 + 4,*piVar8 + 0xc,4);
  lVar7 = (long)*piVar6;
  if (*(short *)(long)iRamffffffffbfc55cc8 == *(short *)(long)iRamffffffffbfc55c60) {
    puVar5 = (undefined2 *)(long)*piVar9;
    *(undefined2 *)(lVar7 + 0x18) = 0x50;
    iVar1 = *piVar8;
    *(undefined2 *)(lVar7 + 0x1a) = *puVar5;
    *(uint *)(lVar7 + 0x24) =
         (uint)*(byte *)((long)puVar5 + 7) |
         (uint)*(byte *)(puVar5 + 3) << 8 |
         (uint)*(byte *)((long)puVar5 + 5) << 0x10 | (uint)*(byte *)(puVar5 + 2) << 0x18;
    *(uint *)(lVar7 + 0x20) =
         (uint)*(byte *)((long)puVar5 + 0xb) |
         (uint)*(byte *)(puVar5 + 5) << 8 |
         (uint)*(byte *)((long)puVar5 + 9) << 0x10 | (uint)*(byte *)(puVar5 + 4) << 0x18;
    *(undefined2 *)(lVar7 + 0x28) = puVar5[7];
    sVar3 = *(short *)((long)iVar1 + 2);
    *(undefined2 *)(lVar7 + 0x2a) = 0;
    *(short *)(lVar7 + 0x1c) = sVar3 + -0x28;
  }
  else {
    *(short *)(long)iRamffffffffbfc55c60 = *(short *)(lVar7 + 0x1a);
  }
  piVar4 = (int *)(long)iRamffffffffbfc55d70;
  iVar1 = *piVar4;
  if (*(int *)(long)iVar1 != 2) {
    uVar2 = getCopReg(2,2);
    *(undefined4 *)((ulong)*(byte *)((long)*(int *)(long)iRamffffffffbfc55cfc + 0xd) + 0xc5) = uVar2
    ;
  }
  piVar6 = (int *)(long)iRamffffffffbfc55cfc;
  if ((*(byte *)((long)*piVar6 + 0xd) & 0x12) == 2) {
    *(int *)(long)iVar1 = 1;
  }
  setCopReg(2,in_zero,*(undefined4 *)((ulong)*(byte *)((long)*piVar6 + 0xd) + 3));
  *(undefined4 *)(long)*piVar4 = 5;
  if (*(int *)(long)*piVar4 - 1U < 5) {
                    /* WARNING: Could not recover jumptable at 0xffffffffbfc53fac. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)(long)(*(int *)(long)(int)((*(int *)(long)*piVar4 - 1U) * 4 +
                                        iRamffffffffbfc55c28 + 0x4780) + -0x403aa3e0))();
    return;
  }
  return;
}

