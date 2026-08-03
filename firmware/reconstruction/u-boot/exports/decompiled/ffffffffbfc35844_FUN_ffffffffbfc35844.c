/*
 * Ghidra reconstructed C; not original Cisco source.
 * RV220W boot-chain/U-Boot analysis v1.1.0
 * Entry: ffffffffbfc35844
 * Function: FUN_ffffffffbfc35844
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

void FUN_ffffffffbfc35844(void)

{
  long lVar1;
  int iVar2;
  undefined8 unaff_s0;
  code *pcVar3;
  undefined8 unaff_s1;
  undefined8 unaff_s2;
  undefined8 unaff_s3;
  long lVar4;
  undefined8 unaff_s4;
  undefined8 *puVar5;
  undefined8 in_ra;
  
  puVar5 = (undefined8 *)(long)((int)&stack0x00000000 + -0x50);
  puVar5[7] = &_gp;
  iVar2 = DAT_ffffffffbfc436f0;
  puVar5[5] = unaff_s3;
  puVar5[8] = in_ra;
  puVar5[6] = unaff_s4;
  puVar5[4] = unaff_s2;
  puVar5[3] = unaff_s1;
  puVar5[2] = unaff_s0;
  *puVar5 = 8;
  (*(code *)(long)(iVar2 + 0x5288))(0x8001180050000010,0x20007f);
  lVar4 = 0;
  while( true ) {
    pcVar3 = (code *)(long)(DAT_ffffffffbfc436f0 + 0x5110);
    lVar1 = (*pcVar3)(0x30d0100);
    iVar2 = 0x20;
    if (lVar1 == 0) {
      lVar1 = (*pcVar3)(0x10d0200);
      iVar2 = 0x20;
      if (lVar1 == 0) {
        lVar1 = (*pcVar3)(0x10d0210);
        iVar2 = 0x20;
        if (lVar1 == 0) {
          lVar1 = (*pcVar3)(0x30d0600);
          iVar2 = 0x20;
          if (lVar1 == 0) {
            lVar1 = (*pcVar3)(0x30d0300);
            iVar2 = 0x100;
            if (lVar1 == 0) {
              lVar1 = (*pcVar3)(0x30d0400);
              iVar2 = 0x80;
              if (lVar1 != 0) {
                iVar2 = 0x100;
              }
            }
          }
        }
      }
    }
    if (iVar2 <= (int)lVar4) break;
    (*(code *)(long)DAT_ffffffffbfc43c10)(0x3f,lVar4,1,puVar5);
    lVar4 = lVar4 + 1;
  }
  return;
}

