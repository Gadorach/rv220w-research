/*
 * Ghidra reconstructed C; not original Cisco source.
 * RV220W boot-chain/U-Boot analysis v1.1.0
 * Entry: ffffffffbfc078a4
 * Function: FUN_ffffffffbfc078a4
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

undefined8 FUN_ffffffffbfc078a4(char param_1,undefined8 param_2,long param_3)

{
  undefined1 uVar1;
  undefined8 extraout_at;
  undefined8 uVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  int iVar5;
  undefined8 unaff_s0;
  long lVar6;
  undefined8 unaff_s1;
  long in_k0;
  undefined1 *puVar7;
  undefined8 in_ra;
  
  puVar7 = (undefined1 *)(long)((int)&stack0x00000000 + -0x40);
  *(undefined1 **)(puVar7 + 0x30) = &_gp;
  *(undefined8 *)(puVar7 + 0x28) = unaff_s1;
  *(undefined8 *)(puVar7 + 0x38) = in_ra;
  *(undefined8 *)(puVar7 + 0x20) = unaff_s0;
  if (param_1 == '\0') {
    uVar2 = 0;
  }
  else {
    lVar6 = (long)DAT_ffffffffbfc43f40;
    uVar2 = 0;
    if ((*(char *)(lVar6 + 2) == '\b') && (uVar2 = 1, param_3 == 0)) {
      (*(code *)(long)(DAT_ffffffffbfc436ec + 0x6910))(DAT_ffffffffbfc436f4 + -0x6650,lVar6);
      if ((*(byte *)(lVar6 + 0x14) & 0x11) == 0) {
        iVar5 = DAT_ffffffffbfc436f4 + -0x6620;
      }
      else {
        iVar5 = DAT_ffffffffbfc436f4 + -0x6630;
      }
      setCopReg(2,extraout_at,*(undefined4 *)((ulong)*(byte *)(lVar6 + 0xb) + 4));
      (*(code *)(long)(DAT_ffffffffbfc436ec + 0x6910))
                (DAT_ffffffffbfc436f4 + -0x6600,param_2,iVar5,DAT_ffffffffbfc436f4 + -0x6610);
      setCopReg(2,param_2,*(undefined4 *)((long)*(int *)(in_k0 + 4) + 0x18));
      (*(code *)(long)DAT_ffffffffbfc43a54)(puVar7,0,0x13);
      iVar5 = DAT_ffffffffbfc43f40 + 0x5b;
      puVar3 = (undefined1 *)(long)(DAT_ffffffffbfc43f40 + 0x49);
      puVar4 = puVar7;
      do {
        uVar1 = *puVar3;
        puVar3 = (undefined1 *)(long)((int)puVar3 + 1);
        *puVar4 = uVar1;
        puVar4 = (undefined1 *)(long)((int)puVar4 + 1);
      } while (puVar3 != (undefined1 *)(long)iVar5);
      (*(code *)(long)(DAT_ffffffffbfc436ec + 0x6910))(DAT_ffffffffbfc436f4 + -0x65e8,puVar7);
      uVar2 = 1;
    }
  }
  return uVar2;
}

