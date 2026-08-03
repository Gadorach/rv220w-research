/*
 * Ghidra reconstructed C; not original Cisco source.
 * RV220W boot-chain/U-Boot analysis v1.1.0
 * Entry: ffffffffbfc35988
 * Function: FUN_ffffffffbfc35988
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

void FUN_ffffffffbfc35988(void)

{
  long lVar1;
  long lVar2;
  ulong uVar3;
  undefined8 unaff_s0;
  undefined8 unaff_s1;
  undefined8 unaff_s2;
  undefined8 unaff_s3;
  ulong uVar4;
  code *pcVar5;
  undefined8 *puVar6;
  undefined8 in_ra;
  
  puVar6 = (undefined8 *)(long)((int)&stack0x00000000 + -0x30);
  puVar6[4] = &_gp;
  puVar6[3] = unaff_s3;
  uVar4 = 0;
  pcVar5 = (code *)(long)DAT_ffffffffbfc43d7c;
  puVar6[5] = in_ra;
  puVar6[2] = unaff_s2;
  puVar6[1] = unaff_s1;
  *puVar6 = unaff_s0;
  (*pcVar5)();
  while( true ) {
    pcVar5 = (code *)(long)(DAT_ffffffffbfc436f0 + 0x5110);
    lVar1 = (*pcVar5)(0x30d0100);
    lVar2 = 0x20;
    if (lVar1 == 0) {
      lVar1 = (*pcVar5)(0x10d0200);
      lVar2 = 0x20;
      if (lVar1 == 0) {
        lVar1 = (*pcVar5)(0x10d0210);
        lVar2 = 0x20;
        if (lVar1 == 0) {
          lVar1 = (*pcVar5)(0x30d0600);
          lVar2 = 0x20;
          if (lVar1 == 0) {
            lVar1 = (*pcVar5)(0x30d0300);
            lVar2 = 0x100;
            if (lVar1 == 0) {
              lVar1 = (*pcVar5)(0x30d0400);
              lVar2 = 0x80;
              if (lVar1 != 0) {
                lVar2 = 0x100;
              }
            }
          }
        }
      }
    }
    if (lVar2 <= (long)uVar4) break;
    lVar1 = (*(code *)(long)(DAT_ffffffffbfc436f0 + 0x5110))(0x70d0300);
    if (lVar1 == 0) {
      (*(code *)(long)(DAT_ffffffffbfc436f0 + 0x5288))(0x8001180050000100,uVar4 >> 7 & 1);
    }
    (*(code *)(long)(DAT_ffffffffbfc436f0 + 0x5288))(0x8001180050001000,uVar4 & 0x7f | 0x11f80);
    uVar3 = uVar4 & 0xffff;
    uVar4 = (ulong)((int)uVar4 + 1);
    (*(code *)(long)DAT_ffffffffbfc43f8c)(uVar3);
  }
  (*(code *)(long)(DAT_ffffffffbfc436f0 + 0x5288))(&DAT_8001180050000000,_DAT_8001180050000000 | 8);
  return;
}

