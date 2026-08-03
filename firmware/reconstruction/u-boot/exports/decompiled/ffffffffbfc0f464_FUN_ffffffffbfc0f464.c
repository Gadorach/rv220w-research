/*
 * Ghidra reconstructed C; not original Cisco source.
 * RV220W boot-chain/U-Boot analysis v1.1.0
 * Entry: ffffffffbfc0f464
 * Function: FUN_ffffffffbfc0f464
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

undefined8 FUN_ffffffffbfc0f464(long param_1,int param_2,int param_3,undefined1 param_4)

{
  byte bVar1;
  ulong uVar2;
  undefined8 uVar3;
  ulong uVar4;
  undefined8 unaff_s0;
  undefined8 unaff_s1;
  ushort *puVar5;
  ushort *puVar6;
  undefined8 in_ra;
  
  puVar6 = (ushort *)(long)((int)&stack0x00000000 + -0x30);
  *(undefined1 **)(puVar6 + 0x10) = &_gp;
  *(undefined8 *)(puVar6 + 0xc) = unaff_s1;
  *(undefined8 *)(puVar6 + 8) = unaff_s0;
  *(undefined8 *)(puVar6 + 0x14) = in_ra;
  puVar5 = (ushort *)
           (long)(int)(param_3 * (uint)*(byte *)(param_1 + 0xa0c) +
                      *(int *)((long)(param_2 * 4 + (int)param_1) + 0xc));
  (*(code *)(long)(DAT_ffffffffbfc436fc + -0xd84))((int)param_1,param_4,puVar6);
  bVar1 = *(byte *)(param_1 + 0xa0c);
  if (bVar1 == 2) {
    uVar2 = (ulong)*puVar5;
    uVar4 = (ulong)*puVar6;
  }
  else if (bVar1 < 3) {
    if (bVar1 != 1) {
      return 0;
    }
    uVar2 = (ulong)*(byte *)puVar5;
    uVar4 = (ulong)*(byte *)puVar6;
  }
  else {
    if (bVar1 != 4) {
      if (bVar1 != 8) {
        return 0;
      }
      uVar3 = special2(*(undefined8 *)puVar5,*(undefined8 *)puVar6,0,0x2a);
      return uVar3;
    }
    uVar4 = (ulong)*(int *)puVar5;
    uVar2 = (ulong)*(int *)puVar6;
  }
  uVar3 = special2(uVar4,uVar2,0,0x2a);
  return uVar3;
}

