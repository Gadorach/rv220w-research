/*
 * Ghidra reconstructed C; not original Cisco source.
 * RV220W boot-chain/U-Boot analysis v1.1.0
 * Entry: ffffffffbfc30e6c
 * Function: FUN_ffffffffbfc30e6c
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

undefined8 FUN_ffffffffbfc30e6c(undefined8 param_1)

{
  undefined4 uVar1;
  undefined8 extraout_at;
  long lVar2;
  long lVar3;
  undefined8 uVar4;
  ulong *puVar5;
  undefined8 uVar6;
  undefined8 unaff_s0;
  int iVar7;
  undefined8 unaff_s1;
  long lVar8;
  uint uVar9;
  undefined8 unaff_s2;
  undefined8 unaff_s3;
  undefined8 unaff_s4;
  long unaff_s5;
  undefined8 unaff_s6;
  code *pcVar10;
  undefined8 *puVar11;
  undefined8 in_ra;
  
  puVar11 = (undefined8 *)(long)((int)&stack0x00000000 + -0x50);
  puVar11[7] = &_gp;
  puVar11[8] = in_ra;
  puVar11[6] = unaff_s6;
  pcVar10 = (code *)(long)DAT_ffffffffbfc43d30;
  puVar11[5] = unaff_s5;
  puVar11[3] = unaff_s3;
  puVar11[4] = unaff_s4;
  special2(param_1,unaff_s5,0x1b,0x32);
  puVar11[2] = unaff_s2;
  puVar11[1] = unaff_s1;
  *puVar11 = unaff_s0;
  lVar2 = (*pcVar10)();
  (*(code *)(long)DAT_ffffffffbfc43c60)();
  lVar8 = *(long *)(&DAT_80011800080007f8 + unaff_s5);
  setCopReg(2,extraout_at,*(undefined4 *)(lVar8 + 0x92));
  iVar7 = DAT_ffffffffbfc436f0 + 0x410;
  lVar3 = (*(code *)(long)iVar7)(0x30d0001);
  if ((lVar3 != 0) || (lVar3 = (*(code *)(long)iVar7)(0x30d0300), lVar3 != 0)) {
    uVar1 = getCopReg(2,0);
    *(undefined4 *)(lVar8 + 0x83) = uVar1;
  }
  iVar7 = DAT_ffffffffbfc436f0 + 0x6bc;
  uVar9 = ~(uint)(-1L << lVar2) & 0xf;
  (*(code *)(long)iVar7)(&DAT_80011800b0000008 + unaff_s5,uVar9);
  lVar8 = 0;
  lVar3 = (*(code *)(long)iVar7)(&DAT_80011800b0000000 + unaff_s5,uVar9);
  special2(0,lVar3,0xb,0x32);
  while (lVar3 = lVar3 + unaff_s5, lVar8 < lVar2) {
    pcVar10 = (code *)(long)(DAT_ffffffffbfc436f0 + 0x6bc);
    (*pcVar10)(lVar3 + -0x7ffee7fff7fffdf0,0x20);
    puVar5 = (ulong *)(*(code *)(long)(DAT_ffffffffbfc436f0 + 0x60c))(lVar8,param_1);
    (*pcVar10)(puVar5,*puVar5 | 0x40);
    (*pcVar10)(lVar3 + -0x7ffee7fff7fffdc8,20000);
    iVar7 = DAT_ffffffffbfc436f0;
    (*pcVar10)(lVar3 + -0x7ffee7fff7fffdb8,19000);
    lVar3 = (*(code *)(long)(DAT_ffffffffbfc436f0 + 0x410))(0x30d0600);
    if (lVar3 == 0) {
      uVar4 = (*(code *)(long)(DAT_ffffffffbfc436f0 + 0x5b4))(lVar8,param_1);
      (*pcVar10)(uVar4,0x18);
      uVar4 = (*(code *)(long)(iVar7 + 0x588))(lVar8,param_1);
      uVar6 = 0x18;
    }
    else {
      uVar4 = (*(code *)(long)(DAT_ffffffffbfc436f0 + 0x5b4))(lVar8,param_1);
      (*pcVar10)(uVar4,0x10);
      uVar4 = (*(code *)(long)(iVar7 + 0x588))(lVar8,param_1);
      uVar6 = 0x10;
    }
    lVar8 = (long)((int)lVar8 + 1);
    lVar3 = (*pcVar10)(uVar4,uVar6);
    special2(lVar8,lVar3,0xb,0x32);
  }
  (*(code *)(long)DAT_ffffffffbfc43d60)(param_1,lVar2);
  for (lVar3 = 0; lVar3 < lVar2; lVar3 = (long)((int)lVar3 + 1)) {
    uVar4 = (*(code *)(long)DAT_ffffffffbfc43b94)(param_1,lVar3);
    (*(code *)(long)DAT_ffffffffbfc43988)(uVar4);
    puVar5 = (ulong *)(*(code *)(long)(DAT_ffffffffbfc436f0 + 0x5e0))(lVar3,param_1);
    (*(code *)(long)(DAT_ffffffffbfc436f0 + 0x6bc))(puVar5,*puVar5 | 1);
  }
  return 0;
}

