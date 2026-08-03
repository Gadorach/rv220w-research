/*
 * Ghidra reconstructed C; not original Cisco source.
 * RV220W boot-chain/U-Boot analysis v1.1.0
 * Entry: ffffffffbfc16458
 * Function: do_gpio
 * Subsystem: gpio-button
 *
 * RV220W BOOT-CHAIN / U-BOOT SEMANTIC ANNOTATION v1.1.0
 * Region: early-boot-and-board-support
 * Subsystem: gpio-button
 * Evidence: U-Boot command-table entry
 * Confidence: high for identity; medium for exact types
 * Interpretation: U-Boot gpio command handler, retained command syntax provides direct board GPIO diagnostics.
 * Safety: reconstructed pseudocode is not original Cisco source. Do not replay flash, GPIO, MDIO or switch writes without readback and recovery safeguards.
 * 
 * Prior/recovered evidence:
 * RV220W BOOT-CHAIN / U-BOOT SEMANTIC ANNOTATION v1.1.0
 * Region: early-boot-and-board-support
 * Subsystem: gpio-button
 * Evidence: U-Boot command-table entry
 * Confidence: high for identity; medium for exact types
 * Interpretation: U-Boot gpio command handler, retained command syntax provides direct board GPIO diagnostics.
 * Safety: reconstructed pseudocode is not original Cisco source. Do not replay flash, GPIO, MDIO or switch writes without readback and recovery safeguards.
 * 
 * Prior/recovered evidence:
 * RV220W BOOT-CHAIN / U-BOOT SEMANTIC ANNOTATION v1.1.0
 * Region: early-boot-and-board-support
 * Subsystem: gpio-button
 * Evidence: U-Boot command-table entry
 * Confidence: high for identity; medium for exact types
 * Interpretation: U-Boot gpio command handler, retained command syntax provides direct board GPIO diagnostics.
 * Safety: reconstructed pseudocode is not original Cisco source. Do not replay flash, GPIO, MDIO or switch writes without readback and recovery safeguards.
 * 
 * Recovered from U-Boot command table: command='gpio', maxargs=4, repeatable=1, usage=''.
 */

/* RV220W BOOT-CHAIN / U-BOOT SEMANTIC ANNOTATION v1.1.0
   Region: early-boot-and-board-support
   Subsystem: gpio-button
   Evidence: U-Boot command-table entry
   Confidence: high for identity; medium for exact types
   Interpretation: U-Boot gpio command handler, retained command syntax provides direct board GPIO
   diagnostics.
   Safety: reconstructed pseudocode is not original Cisco source. Do not replay flash, GPIO, MDIO or
   switch writes without readback and recovery safeguards.
   
   Prior/recovered evidence:
   RV220W BOOT-CHAIN / U-BOOT SEMANTIC ANNOTATION v1.1.0
   Region: early-boot-and-board-support
   Subsystem: gpio-button
   Evidence: U-Boot command-table entry
   Confidence: high for identity; medium for exact types
   Interpretation: U-Boot gpio command handler, retained command syntax provides direct board GPIO
   diagnostics.
   Safety: reconstructed pseudocode is not original Cisco source. Do not replay flash, GPIO, MDIO or
   switch writes without readback and recovery safeguards.
   
   Prior/recovered evidence:
   RV220W BOOT-CHAIN / U-BOOT SEMANTIC ANNOTATION v1.1.0
   Region: early-boot-and-board-support
   Subsystem: gpio-button
   Evidence: U-Boot command-table entry
   Confidence: high for identity; medium for exact types
   Interpretation: U-Boot gpio command handler, retained command syntax provides direct board GPIO
   diagnostics.
   Safety: reconstructed pseudocode is not original Cisco source. Do not replay flash, GPIO, MDIO or
   switch writes without readback and recovery safeguards.
   
   Recovered from U-Boot command table: command='gpio', maxargs=4, repeatable=1, usage=''. */

void do_gpio(void)

{
  long lVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  int iVar4;
  long in_a3;
  undefined8 unaff_s0;
  undefined8 unaff_s1;
  undefined8 unaff_s2;
  code *pcVar5;
  undefined8 *puVar6;
  undefined8 in_ra;
  
  puVar6 = (undefined8 *)(long)((int)&stack0x00000000 + -0x30);
  puVar6[3] = &_gp;
  puVar6[4] = in_ra;
  puVar6[2] = unaff_s2;
  iVar4 = DAT_ffffffffbfc436f4;
  pcVar5 = (code *)(long)DAT_ffffffffbfc4400c;
  *puVar6 = unaff_s0;
  puVar6[1] = unaff_s1;
  (*pcVar5)(iVar4 + -0x3f30);
  pcVar5 = (code *)(long)DAT_ffffffffbfc4400c;
  (*(code *)(long)DAT_ffffffffbfc437a8)();
  lVar1 = (*(code *)(long)DAT_ffffffffbfc43ab4)
                    (*(undefined4 *)(in_a3 + 4),DAT_ffffffffbfc436f0 + 0x7720,1);
  if (lVar1 == 0) {
    uVar2 = (*(code *)(long)DAT_ffffffffbfc438b0)(*(undefined4 *)(in_a3 + 8),0,10);
    uVar3 = (*(code *)(long)DAT_ffffffffbfc43f70)(uVar2);
    iVar4 = DAT_ffffffffbfc436f4 + -0x3ef0;
  }
  else {
    lVar1 = (*(code *)(long)DAT_ffffffffbfc43ab4)
                      (*(undefined4 *)(in_a3 + 4),DAT_ffffffffbfc436f4 + -0x3ed0,1);
    if (lVar1 != 0) {
      (*pcVar5)(DAT_ffffffffbfc436f4 + -0x3ea8,0,10);
      return;
    }
    uVar2 = (*(code *)(long)DAT_ffffffffbfc438b0)(*(undefined4 *)(in_a3 + 8));
    uVar3 = (*(code *)(long)DAT_ffffffffbfc438b0)(*(undefined4 *)(in_a3 + 0xc),0,10);
    (*(code *)(long)DAT_ffffffffbfc438fc)(uVar2,uVar3);
    iVar4 = DAT_ffffffffbfc436f4 + -0x3ec8;
  }
  (*pcVar5)(iVar4,uVar2,uVar3);
  return;
}

