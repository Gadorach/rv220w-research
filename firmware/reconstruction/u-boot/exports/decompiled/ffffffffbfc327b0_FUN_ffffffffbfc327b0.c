/*
 * Ghidra reconstructed C; not original Cisco source.
 * RV220W boot-chain/U-Boot analysis v1.1.0
 * Entry: ffffffffbfc327b0
 * Function: FUN_ffffffffbfc327b0
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

undefined8 FUN_ffffffffbfc327b0(long param_1,ulong param_2)

{
  long lVar1;
  ulong uVar2;
  undefined8 unaff_s0;
  code *pcVar3;
  long unaff_s1;
  undefined8 unaff_s2;
  undefined8 unaff_s3;
  undefined8 *puVar4;
  undefined8 in_ra;
  
  puVar4 = (undefined8 *)(long)((int)&stack0x00000000 + -0x30);
  puVar4[3] = unaff_s3;
  puVar4[4] = &_gp;
  puVar4[1] = unaff_s1;
  puVar4[2] = unaff_s2;
  special2(param_1,unaff_s1,0x1b,0x32);
  puVar4[5] = in_ra;
  *puVar4 = unaff_s0;
  (*(code *)(long)(DAT_ffffffffbfc436f0 + 0x2018))
            ((ulong *)(unaff_s1 + -0x7ffee7fff7fffb80),
             *(ulong *)(unaff_s1 + -0x7ffee7fff7fffb80) & 0xffffffffffffffe0 | param_2 & 0x1f);
  lVar1 = (*(code *)(long)DAT_ffffffffbfc43bc0)(param_1);
  if (lVar1 == 1) {
LAB_ffffffffbfc32858:
    if (4 < (long)param_2) {
      (*(code *)(long)DAT_ffffffffbfc4400c)(DAT_ffffffffbfc436f4 + 0x2400);
      return 0xffffffffffffffff;
    }
    (*(code *)(long)(DAT_ffffffffbfc436f0 + 0x2018))
              ((ulong *)(unaff_s1 + -0x7ffee7fff7fffbf0),
               *(ulong *)(unaff_s1 + -0x7ffee7fff7fffbf0) & 0xfffffffffffffff8 | param_2 & 7);
  }
  else {
    lVar1 = (*(code *)(long)DAT_ffffffffbfc43bc0)(param_1);
    if ((lVar1 == 6) || (lVar1 = (*(code *)(long)DAT_ffffffffbfc43bc0)(param_1), lVar1 == 2))
    goto LAB_ffffffffbfc32858;
  }
  pcVar3 = (code *)(long)(DAT_ffffffffbfc436f0 + 0x1ea0);
  lVar1 = (*pcVar3)(0x30d0200);
  if (lVar1 != 0) {
    return 0;
  }
  lVar1 = (*pcVar3)(0x30d0100);
  if (lVar1 != 0) {
    return 0;
  }
  lVar1 = (*pcVar3)(0x30d0600);
  if (lVar1 != 0) {
    return 0;
  }
  if (param_1 == 0) {
    uVar2 = 4;
    if (param_2 != 1) {
      if (param_2 == 2) {
        uVar2 = 3;
      }
      else {
        uVar2 = 2;
        if ((4 < (long)param_2) && (uVar2 = 1, 8 < (long)param_2)) {
          uVar2 = _DAT_8001180050000018 & 0xfffffffffffffff8;
          goto LAB_ffffffffbfc32984;
        }
      }
    }
    uVar2 = _DAT_8001180050000018 & 0xfffffffffffffff8 | uVar2;
  }
  else {
    lVar1 = 4;
    if ((((param_2 == 1) || (lVar1 = 3, param_2 == 2)) || (lVar1 = 2, (long)param_2 < 5)) ||
       (lVar1 = 1, (long)param_2 < 9)) {
      uVar2 = _DAT_8001180050000018 & 0xffffffffffffffc7 | lVar1 << 3;
    }
    else {
      uVar2 = _DAT_8001180050000018 & 0xffffffffffffffc7;
    }
  }
LAB_ffffffffbfc32984:
  (*(code *)(long)(DAT_ffffffffbfc436f0 + 0x2018))(&DAT_8001180050000018,uVar2);
  return 0;
}

