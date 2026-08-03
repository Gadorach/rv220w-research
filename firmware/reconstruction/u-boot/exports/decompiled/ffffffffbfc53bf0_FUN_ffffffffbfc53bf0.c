/*
 * Ghidra reconstructed C; not original Cisco source.
 * RV220W boot-chain/U-Boot analysis v1.1.0
 * Entry: ffffffffbfc53bf0
 * Function: FUN_ffffffffbfc53bf0
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

void FUN_ffffffffbfc53bf0
               (long param_1,undefined8 param_2,undefined8 param_3,long param_4,long param_5)

{
  byte bVar1;
  undefined1 uVar2;
  undefined4 uVar3;
  undefined8 in_at;
  undefined8 uVar4;
  undefined2 uVar5;
  undefined8 unaff_s0;
  undefined1 *puVar6;
  undefined8 unaff_s1;
  undefined8 unaff_s2;
  long lVar7;
  undefined8 unaff_s3;
  int iVar8;
  undefined8 unaff_s4;
  int iVar9;
  undefined8 unaff_s5;
  undefined8 unaff_s6;
  undefined8 unaff_s7;
  code *pcVar10;
  undefined4 *puVar11;
  undefined8 in_ra;
  
  puVar11 = (undefined4 *)(long)((int)&stack0x00000000 + -0x60);
  *(undefined8 *)(puVar11 + 0xc) = unaff_s4;
  *(undefined1 **)(puVar11 + 0x14) = &_gp;
  *(undefined8 *)(puVar11 + 0x12) = unaff_s7;
  *(undefined8 *)(puVar11 + 0x10) = unaff_s6;
  *(undefined8 *)(puVar11 + 0xe) = unaff_s5;
  *(undefined8 *)(puVar11 + 10) = unaff_s3;
  *(undefined8 *)(puVar11 + 8) = unaff_s2;
  *(undefined8 *)(puVar11 + 6) = unaff_s1;
  *(undefined8 *)(puVar11 + 4) = unaff_s0;
  iVar9 = (int)param_2;
  puVar6 = (undefined1 *)(long)(iVar9 + 0x22);
  *(undefined8 *)(puVar11 + 0x16) = in_ra;
  bVar1 = puVar6[0xc];
  pcVar10 = (code *)(long)iRamffffffffbfc55d98;
  lVar7 = (long)(iVar9 + 0xe);
  iVar8 = (int)param_3 + -0x22;
  setCopReg(2,in_at,*(undefined4 *)(param_4 + 8));
  *puVar11 = 0x20405c0;
  puVar6[0xc] = bVar1 & 0xf | 0x60;
  (*pcVar10)(iVar9 + 0x36,puVar11,4);
  *(undefined2 *)(param_1 + 0x1c) = 0;
  pcVar10 = (code *)(long)iRamffffffffbfc55d98;
  puVar6[0xc] = puVar6[0xc] & 0xf0;
  uVar3 = uRamffffffffbfc55ca4;
  *(undefined4 *)(puVar6 + 8) = *(undefined4 *)(param_1 + 0x20);
  *(undefined4 *)(puVar6 + 4) = *(undefined4 *)(param_1 + 0x24);
  puVar6[0x10] = 0;
  puVar6[0x11] = 0;
  if (param_5 == 0) {
    *puVar6 = *(undefined1 *)(param_1 + 0x18);
    puVar6[1] = *(undefined1 *)(param_1 + 0x19);
    puVar6[2] = (char)((ushort)*(undefined2 *)(param_1 + 0x1a) >> 8);
    uVar2 = *(undefined1 *)(param_1 + 0x1b);
    puVar6[0xd] = (byte)param_4;
    puVar6[3] = uVar2;
    if (*(short *)(param_1 + 0x1c) != 0) {
      puVar6[0xd] = (byte)param_4 | 8;
    }
    puVar6[0xe] = *(undefined1 *)(param_1 + 0x28);
    uVar2 = *(undefined1 *)(param_1 + 0x29);
    puVar6[0x12] = 0;
    puVar6[0xf] = uVar2;
    puVar6[0x13] = 0;
    (*pcVar10)(iVar9 + 0x1a,uVar3,4);
    (*(code *)(long)iRamffffffffbfc55d98)(iVar9 + 0x1e,(int)param_1 + 4,4);
    *(undefined1 *)(lVar7 + 9) = 6;
  }
  pcVar10 = (code *)(long)iRamffffffffbfc55cb0;
  *(char *)(lVar7 + 3) = (char)iVar8;
  *(char *)(lVar7 + 2) = (char)((uint)iVar8 >> 8);
  uVar4 = (*pcVar10)(lVar7);
  uVar5 = (*(code *)(long)iRamffffffffbfc55d5c)(puVar6,iVar8,uVar4);
  pcVar10 = (code *)(long)iRamffffffffbfc55cdc;
  puVar6[0x11] = (char)uVar5;
  puVar6[0x10] = (char)((ushort)uVar5 >> 8);
  (*pcVar10)(param_2,param_3,6,(int)param_1 + 4);
  return;
}

