/*
 * Ghidra reconstructed C; not original Cisco source.
 * RV220W boot-chain/U-Boot analysis v1.1.0
 * Entry: ffffffffbfc32538
 * Function: FUN_ffffffffbfc32538
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
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

undefined8 FUN_ffffffffbfc32538(long param_1)

{
  bool bVar1;
  undefined4 uVar2;
  ulong uVar3;
  undefined1 *puVar4;
  int iVar6;
  ulong *puVar5;
  long lVar7;
  undefined8 unaff_s0;
  ulong uVar8;
  ulong unaff_s1;
  ulong uVar9;
  undefined8 unaff_s2;
  ulong uVar10;
  undefined8 unaff_s3;
  undefined8 unaff_s4;
  code *pcVar11;
  undefined8 *puVar12;
  undefined8 in_ra;
  
  puVar12 = (undefined8 *)(long)((int)&stack0x00000000 + -0x40);
  puVar12[5] = &_gp;
  puVar12[6] = in_ra;
  *puVar12 = unaff_s0;
  puVar12[4] = unaff_s4;
  puVar12[3] = unaff_s3;
  puVar12[2] = unaff_s2;
  puVar12[1] = unaff_s1;
  (*(code *)(long)DAT_ffffffffbfc4400c)(DAT_ffffffffbfc436f4 + 0x22f8,*(undefined2 *)(param_1 + 8));
  (*(code *)(long)DAT_ffffffffbfc4400c)
            (DAT_ffffffffbfc436f4 + 0x2310,*(ulong *)(param_1 + 8) >> 0x2a & 0x3f);
  (*(code *)(long)DAT_ffffffffbfc4400c)
            (DAT_ffffffffbfc436f4 + 9000,*(ulong *)(param_1 + 8) >> 0x27 & 7);
  (*(code *)(long)DAT_ffffffffbfc4400c)
            (DAT_ffffffffbfc436f4 + 0x2340,*(undefined1 *)(param_1 + 0x10));
  if (*(char *)(param_1 + 0x10) == '\0') {
    lVar7 = *(long *)(param_1 + 0x10);
    special2(0xffffffffffffffff,unaff_s1,0xf,0x33);
    uVar9 = _DAT_80014f0000000020 & 7;
    uVar2 = getCopReg(2,9);
    *(undefined4 *)(lVar7 + 9) = uVar2;
    setCopReg(2,param_1,*(undefined4 *)(lVar7 + 3));
    uVar9 = unaff_s1 & 0xf8ffff0000000000 | uVar9 << 0x38 |
            ((long)((int)param_1 + 0x20) & 0x1fffffffU) + 2;
  }
  else {
    uVar9 = *(ulong *)(param_1 + 0x18);
  }
  uVar10 = (ulong)*(ushort *)(param_1 + 8);
  while( true ) {
    if (uVar10 == 0) {
      return 0;
    }
    uVar3 = uVar9 & 0xffffffffff;
    lVar7 = 0;
    (*(code *)(long)DAT_ffffffffbfc4400c)
              (DAT_ffffffffbfc436f4 + 0x2358,
               ((uVar3 >> 7) - (uVar9 >> 0x3b & 0xf) & 0xffffffffff) << 7);
    (*(code *)(long)DAT_ffffffffbfc4400c)(DAT_ffffffffbfc436f4 + 0x2370,uVar9 >> 0x3f);
    uVar8 = uVar9 >> 0x28 & 0xffff;
    (*(code *)(long)DAT_ffffffffbfc4400c)(DAT_ffffffffbfc436f4 + 0x2388,uVar9 >> 0x3b & 0xf);
    (*(code *)(long)DAT_ffffffffbfc4400c)(DAT_ffffffffbfc436f4 + 0x23a0,uVar9 >> 0x38 & 7);
    (*(code *)(long)DAT_ffffffffbfc4400c)(DAT_ffffffffbfc436f4 + 0x23b8,uVar3);
    (*(code *)(long)DAT_ffffffffbfc4400c)(DAT_ffffffffbfc436f4 + 0x23d0,uVar8);
    (*(code *)(long)DAT_ffffffffbfc4400c)(DAT_ffffffffbfc436f4 + 0x23e8);
    puVar4 = (undefined1 *)(*(code *)(long)(DAT_ffffffffbfc436f0 + 0x24e4))(uVar3);
    iVar6 = (int)puVar4;
    while (pcVar11 = (code *)(long)DAT_ffffffffbfc4400c,
          puVar4 < (undefined1 *)(long)(iVar6 + (int)uVar8)) {
      bVar1 = uVar10 == 0;
      uVar10 = uVar10 - 1;
      if (bVar1) {
        (*pcVar11)(DAT_ffffffffbfc436f4 + 0x1150);
        return 0;
      }
      (*pcVar11)(DAT_ffffffffbfc436f4 + 0x23f0,*puVar4);
      if ((uVar10 == 0) || (lVar7 != 7)) {
        lVar7 = lVar7 + 1;
        puVar4 = (undefined1 *)(long)((int)puVar4 + 1);
      }
      else {
        lVar7 = 0;
        (*(code *)(long)DAT_ffffffffbfc4400c)(DAT_ffffffffbfc436f4 + 0x23f8);
        puVar4 = (undefined1 *)(long)((int)puVar4 + 1);
      }
    }
    (*pcVar11)(DAT_ffffffffbfc436f4 + 0x1150);
    if (uVar10 == 0) break;
    puVar5 = (ulong *)(*(code *)(long)(DAT_ffffffffbfc436f0 + 0x24e4))(uVar3 - 8 & 0xffffffffff);
    uVar9 = *puVar5;
  }
  return 0;
}

