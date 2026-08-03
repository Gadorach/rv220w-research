/*
 * Ghidra reconstructed C; not original Cisco source.
 * RV220W boot-chain/U-Boot analysis v1.1.0
 * Entry: ffffffffbfc11eb0
 * Function: FUN_ffffffffbfc11eb0
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

/* WARNING: Removing unreachable block (ram,0xffffffffbfc1200c) */
/* WARNING: Removing unreachable block (ram,0xffffffffbfc12028) */
/* WARNING: Removing unreachable block (ram,0xffffffffbfc12014) */
/* WARNING: Removing unreachable block (ram,0xffffffffbfc12038) */
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

void FUN_ffffffffbfc11eb0
               (undefined8 param_1,undefined8 param_2,int param_3,undefined8 param_4,
               undefined8 param_5)

{
  undefined8 in_zero;
  long lVar1;
  uint uVar2;
  undefined8 unaff_s0;
  undefined8 unaff_s1;
  undefined8 unaff_s2;
  undefined8 unaff_s3;
  int iVar3;
  undefined8 unaff_s4;
  undefined8 unaff_s5;
  undefined8 unaff_s6;
  undefined8 unaff_s7;
  code *pcVar4;
  undefined4 *puVar5;
  undefined8 in_ra;
  int iVar6;
  
  iVar6 = (int)&stack0x00000000;
  puVar5 = (undefined4 *)(long)(iVar6 + -0x60);
  *(undefined1 **)(puVar5 + 0x14) = &_gp;
  *(undefined8 *)(puVar5 + 0x12) = unaff_s7;
  pcVar4 = (code *)(long)DAT_ffffffffbfc43fa0;
  *(undefined8 *)(puVar5 + 0x10) = unaff_s6;
  *(undefined8 *)(puVar5 + 0xe) = unaff_s5;
  *(undefined8 *)(puVar5 + 10) = unaff_s3;
  *(undefined8 *)(puVar5 + 8) = unaff_s2;
  *(undefined8 *)(puVar5 + 6) = unaff_s1;
  *(undefined8 *)(puVar5 + 4) = unaff_s0;
  *(undefined8 *)(puVar5 + 0x16) = in_ra;
  *(undefined8 *)(puVar5 + 0xc) = unaff_s4;
  puVar5[2] = 0;
  (*pcVar4)(param_1,param_2,4,iVar6 + -0x58);
  puVar5[2] = puVar5[2] & 0xfffffffc | 4;
  for (iVar3 = 0x10; iVar3 <= param_3 * 4 + 0x10; iVar3 = iVar3 + 4) {
    (*(code *)(long)DAT_ffffffffbfc43910)(param_1,param_2,iVar3,0xffffffffffffffff);
    (*(code *)(long)DAT_ffffffffbfc43fa0)(param_1,param_2,iVar3,iVar6 + -0x5c);
    uVar2 = puVar5[1];
    if ((long)(int)uVar2 != 0) {
      setCopReg(2,in_zero,*(undefined4 *)((long)(int)uVar2 + 7));
      lVar1 = (*(code *)(long)DAT_ffffffffbfc43888)(param_5,-(uVar2 & 0xfffffffc),puVar5);
      if (lVar1 == 0) {
        (*(code *)(long)DAT_ffffffffbfc43910)(param_1,param_2,iVar3,*puVar5);
        uVar2 = 1;
        if ((puVar5[1] & 1) == 0) {
          uVar2 = 2;
        }
        puVar5[2] = puVar5[2] | uVar2;
      }
      else {
        (*(code *)(long)DAT_ffffffffbfc43910)(param_1,param_2,iVar3,0xffffffffffffffff);
      }
    }
  }
  (*(code *)(long)DAT_ffffffffbfc43910)(param_1,param_2,4,puVar5[2]);
  (*(code *)(long)DAT_ffffffffbfc437a4)(param_1,param_2,0xc,8);
  (*(code *)(long)DAT_ffffffffbfc437a4)(param_1,param_2,0xd,0x80);
  return;
}

