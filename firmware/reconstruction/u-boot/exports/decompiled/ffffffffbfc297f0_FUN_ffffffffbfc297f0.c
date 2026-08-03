/*
 * Ghidra reconstructed C; not original Cisco source.
 * RV220W boot-chain/U-Boot analysis v1.1.0
 * Entry: ffffffffbfc297f0
 * Function: FUN_ffffffffbfc297f0
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

void FUN_ffffffffbfc297f0(void)

{
  ulong uVar1;
  ulong uVar2;
  long lVar3;
  undefined8 unaff_s0;
  long lVar4;
  undefined8 unaff_s1;
  undefined8 unaff_s2;
  code *pcVar5;
  undefined8 *puVar6;
  undefined8 in_ra;
  
  puVar6 = (undefined8 *)(long)((int)&stack0x00000000 + -0x30);
  puVar6[3] = &_gp;
  puVar6[1] = unaff_s1;
  puVar6[4] = in_ra;
  pcVar5 = (code *)(long)DAT_ffffffffbfc4385c;
  puVar6[2] = unaff_s2;
  *puVar6 = unaff_s0;
  uVar1 = (*pcVar5)();
  lVar3 = (long)DAT_ffffffffbfc436f4;
  do {
  } while (*(int *)(lVar3 + 0x6060) != 0);
  *(undefined4 *)(lVar3 + 0x6060) = 1;
  SYNC(0);
  lVar4 = (long)DAT_ffffffffbfc436f4;
  SYNC(0);
  uVar2 = *(ulong *)(lVar4 + 0x6068) >> 0x20 & 0xffff;
  SYNC(0);
  *(ulong *)(lVar4 + 0x6068) =
       *(ulong *)(lVar4 + 0x6068) & 0xffff0000ffffffff |
       (uVar2 | (long)(1 << ((uint)uVar1 & 0x1f)) & 0xffffU) << 0x20;
  SYNC(4);
  SYNC(0);
  *(undefined4 *)(lVar3 + 0x6060) = 0;
  SYNC(4);
  if (uVar2 == 0) {
    (*(code *)(long)DAT_ffffffffbfc44014)(30000);
    if (*(int *)((long)DAT_ffffffffbfc436f4 + 0x2e88) != 0) {
      (*(code *)(long)DAT_ffffffffbfc437f0)();
    }
    SYNC(0);
    SYNC(0);
    *(ulong *)(lVar4 + 0x6068) =
         *(ulong *)(lVar4 + 0x6068) & 0xffff00000000 | (uVar1 & 0xf) << 0x30 |
         ((*(ulong *)(lVar4 + 0x6068) & 0xffff00000000) >> 0x20) << 0x10;
    SYNC(4);
    *(undefined4 *)((long)DAT_ffffffffbfc436f4 + 0x6064) = 1;
    SYNC(4);
  }
  do {
  } while (*(int *)((long)DAT_ffffffffbfc436f4 + 0x6064) == 0);
  return;
}

