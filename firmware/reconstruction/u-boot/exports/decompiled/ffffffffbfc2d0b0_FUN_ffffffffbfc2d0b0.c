/*
 * Ghidra reconstructed C; not original Cisco source.
 * RV220W boot-chain/U-Boot analysis v1.1.0
 * Entry: ffffffffbfc2d0b0
 * Function: FUN_ffffffffbfc2d0b0
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
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

undefined1  [16]
FUN_ffffffffbfc2d0b0
          (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
          undefined8 param_5,undefined8 param_6,undefined8 param_7,undefined8 param_8)

{
  undefined4 uVar1;
  undefined8 in_at;
  undefined8 in_v0;
  undefined8 in_v1;
  undefined8 in_t4;
  undefined8 in_t5;
  undefined8 in_t6;
  undefined8 in_t7;
  undefined8 unaff_s0;
  undefined8 unaff_s1;
  undefined8 unaff_s2;
  undefined8 unaff_s3;
  undefined8 unaff_s4;
  undefined8 unaff_s5;
  undefined8 unaff_s6;
  undefined8 unaff_s7;
  undefined8 in_t8;
  undefined8 in_t9;
  code *UNRECOVERED_JUMPTABLE;
  undefined8 *puVar2;
  long lVar3;
  undefined8 in_k1;
  ulong uVar4;
  int *piVar5;
  undefined8 unaff_gp;
  undefined8 unaff_s8;
  undefined8 in_ra;
  undefined8 in_hi;
  undefined8 in_lo;
  undefined1 auVar6 [16];
  
  puVar2 = (undefined8 *)
           (long)(int)((((EBase & 0xff) * 0x1000 + 0x10000) * 2 + 1 >> 1) + 0x80000000);
  puVar2[0x2c] = in_k1;
  setCopReg(2,unaff_s0,*(undefined4 *)(cop0_reg22 + 0x17));
  uVar4 = (long)Debug._4_4_ & 0x3f;
  if ((uVar4 == 0) && (uVar4 = 0, ((ulong)(long)Debug._4_4_ >> 10 & 0x1f) != 0)) {
    uVar1 = getCopReg(2,0x1f);
    *(undefined4 *)((long)Debug._4_4_ + -1) = uVar1;
    puVar2[0x2d] = in_t9;
    DESAVE = puVar2[0x1a];
    puVar2[0x2c] = 0;
    UNRECOVERED_JUMPTABLE = (code *)(DEPC + 1);
    DEPC = (int *)puVar2[0x25];
                    /* WARNING: Could not recover jumptable at 0xffffffffbfc2d138. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
    auVar6 = (*UNRECOVERED_JUMPTABLE)();
    return auVar6;
  }
  *puVar2 = 0;
  puVar2[1] = in_at;
  puVar2[2] = in_v0;
  puVar2[3] = in_v1;
  puVar2[4] = param_1;
  puVar2[5] = param_2;
  puVar2[6] = param_3;
  puVar2[7] = param_4;
  puVar2[8] = param_5;
  puVar2[9] = param_6;
  puVar2[10] = param_7;
  puVar2[0xb] = param_8;
  puVar2[0xc] = in_t4;
  puVar2[0xd] = in_t5;
  puVar2[0xe] = in_t6;
  puVar2[0xf] = in_t7;
  puVar2[0x10] = unaff_s0;
  puVar2[0x11] = unaff_s1;
  puVar2[0x12] = unaff_s2;
  puVar2[0x13] = unaff_s3;
  puVar2[0x14] = unaff_s4;
  puVar2[0x15] = unaff_s5;
  puVar2[0x16] = unaff_s6;
  puVar2[0x17] = unaff_s7;
  puVar2[0x18] = in_t8;
  puVar2[0x19] = in_t9;
  puVar2[0x1b] = uVar4;
  puVar2[0x1c] = unaff_gp;
  puVar2[0x1d] = register0x000000e8;
  puVar2[0x1e] = unaff_s8;
  puVar2[0x1f] = in_ra;
  puVar2[0x1a] = DESAVE;
  puVar2[0x20] = Status;
  puVar2[0x21] = in_lo;
  puVar2[0x22] = in_hi;
  puVar2[0x23] = BadVAddr;
  puVar2[0x24] = Cause;
  piVar5 = DEPC;
  if (*DEPC == 0x7000007f) {
    piVar5 = (int *)(long)((int)DEPC + 4);
  }
  puVar2[0x25] = piVar5;
  puVar2[0x26] = Debug;
  puVar2[0x27] = cop0_reg22;
  puVar2[0x28] = PerfCnt_1;
  puVar2[0x29] = PerfCnt_3;
  puVar2[0x2a] = PerfCnt;
  puVar2[0x2b] = PerfCnt_2;
  puVar2[0x2c] = 1;
  (*(code *)(long)*(int *)((long)_DAT_ffffffff80000a04 + 0x398))();
  lVar3 = (long)(int)((((EBase & 0xff) * 0x1000 + 0x10000) * 2 + 1 >> 1) + 0x80000000);
  auVar6._8_8_ = *(undefined8 *)(lVar3 + 0x10);
  auVar6._0_8_ = *(undefined8 *)(lVar3 + 0x18);
  Status = *(undefined8 *)(lVar3 + 0x100);
  BadVAddr = *(undefined8 *)(lVar3 + 0x118);
  Cause = *(undefined8 *)(lVar3 + 0x120);
  DEPC = (int *)*(undefined8 *)(lVar3 + 0x128);
  Debug = *(undefined8 *)(lVar3 + 0x130);
  cop0_reg22 = *(ulong *)(lVar3 + 0x138) | 1;
  PerfCnt_1 = *(undefined8 *)(lVar3 + 0x140);
  PerfCnt_3 = *(undefined8 *)(lVar3 + 0x148);
  PerfCnt = *(undefined8 *)(lVar3 + 0x150);
  PerfCnt_2 = *(undefined8 *)(lVar3 + 0x158);
  return auVar6;
}

