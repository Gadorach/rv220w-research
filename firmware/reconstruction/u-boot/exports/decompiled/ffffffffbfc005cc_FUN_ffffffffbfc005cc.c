/*
 * Ghidra reconstructed C; not original Cisco source.
 * RV220W boot-chain/U-Boot analysis v1.1.0
 * Entry: ffffffffbfc005cc
 * Function: FUN_ffffffffbfc005cc
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

/* WARNING: This function may have set the stack pointer */
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

void FUN_ffffffffbfc005cc(void)

{
  bool bVar1;
  long lVar2;
  ulong uVar3;
  long unaff_s8;
  int *piVar4;
  
  setCopReg(0,WatchLo,0);
  setCopReg(0,WatchHi,0);
  setCopReg(0,CONCAT44(uRegister00002060,Status),(long)Status & 0xfffffffffffffffe);
  setCopReg(0,Cause,0);
  setCopReg(0,CONCAT44(uRegister00002060,Status),(long)Status | 0xe0);
  setCopReg(0,PageGrain,0x20000000);
  EntryLo0 = 0;
  EntryLo1 = 0;
  setCopReg(0,PageMask,0);
  uVar3 = (long)(int)(Config1 >> 0x19) & 0x3f;
  Context = 0;
  XContext = 0;
  setCopReg(0,Wired,0);
  lVar2 = -0x70000000;
  do {
    do {
      EntryHi = lVar2;
      Index = TLB_probe_for_matching_entry(EntryHi);
      lVar2 = EntryHi + 0x2000;
    } while (-1 < Index._4_4_);
    setCopReg(0,Index,uVar3);
    TLB_write_indexed_entry(Index,EntryHi,0,0,PageMask);
    bVar1 = uVar3 != 0;
    uVar3 = (ulong)((int)uVar3 + -1);
  } while (bVar1);
  setCopReg(0,CONCAT44(uRegister00002060,Status),(long)Status & 0xffffffffffff0000U | 0x500000e5);
  setCopReg(0,HWREna,0xc000000f);
  if (PRId == 0xd0000) {
    cop0_reg9_7 = cop0_reg9_7 | 0x2000;
  }
  cop0_reg9_7 = cop0_reg9_7 | 0x4000;
  cop0_reg11_7 = cop0_reg11_7 | 0x104;
  Compare = 0;
  Count = 0;
  PerfCnt_1 = 0;
  PerfCnt_3 = 0;
  if ((EBase & 0xff) != 0) {
                    /* WARNING: Could not emulate address calculation at 0xffffffffbfc00728 */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)(long)*(int *)((long)(int)((EBase & 0xff) * 0x20 + -0x7ffff800) + 8))();
    return;
  }
  cop0_reg11_7 = (long)(int)((uint)cop0_reg11_7 & 0xfffffe00) | 0x136;
  piVar4 = (int *)0xffffffffbfc00758;
  FUN_ffffffffbfc00760();
  cacheOp(4,unaff_s8 + 0x36e0);
  cacheOp(0,unaff_s8 + 0x758);
                    /* WARNING: Could not recover jumptable at 0xffffffffbfc00778. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)(long)*(int *)((long)((int)piVar4 + (*piVar4 - piVar4[1])) + 0x2a4))();
  return;
}

