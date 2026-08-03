/*
 * Ghidra reconstructed C; not original Cisco source.
 * RV220W boot-chain/U-Boot analysis v1.1.0
 * Entry: ffffffffbfc2d390
 * Function: FUN_ffffffffbfc2d390
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
FUN_ffffffffbfc2d390
          (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
          undefined8 param_5,undefined8 param_6,undefined8 param_7,undefined8 param_8)

{
  bool bVar1;
  uint uVar2;
  undefined8 in_at;
  undefined8 in_v0;
  undefined8 in_v1;
  ulong uVar3;
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
  long *plVar4;
  int iVar5;
  undefined8 in_k1;
  undefined8 unaff_gp;
  undefined8 unaff_s8;
  undefined8 in_ra;
  undefined8 in_hi;
  undefined8 in_lo;
  undefined1 auVar6 [16];
  
  uVar2 = ((EBase._4_4_ & 0xff) * 0x1000 + 0x10000) * 2 + 1 >> 1;
  *(undefined8 *)(long)(int)(uVar2 + 0x80000000) = 0;
  *(undefined8 *)(long)(int)(uVar2 + 0x80000008) = in_at;
  *(undefined8 *)(long)(int)(uVar2 + 0x80000010) = in_v0;
  *(undefined8 *)(long)(int)(uVar2 + 0x80000018) = in_v1;
  *(undefined8 *)(long)(int)(uVar2 + 0x80000020) = param_1;
  *(undefined8 *)(long)(int)(uVar2 + 0x80000028) = param_2;
  *(undefined8 *)(long)(int)(uVar2 + 0x80000030) = param_3;
  *(undefined8 *)(long)(int)(uVar2 + 0x80000038) = param_4;
  *(undefined8 *)(long)(int)(uVar2 + 0x80000040) = param_5;
  *(undefined8 *)(long)(int)(uVar2 + 0x80000048) = param_6;
  *(undefined8 *)(long)(int)(uVar2 + 0x80000050) = param_7;
  *(undefined8 *)(long)(int)(uVar2 + 0x80000058) = param_8;
  *(undefined8 *)(long)(int)(uVar2 + 0x80000060) = in_t4;
  *(undefined8 *)(long)(int)(uVar2 + 0x80000068) = in_t5;
  *(undefined8 *)(long)(int)(uVar2 + 0x80000070) = in_t6;
  *(undefined8 *)(long)(int)(uVar2 + 0x80000078) = in_t7;
  *(undefined8 *)(long)(int)(uVar2 + 0x80000080) = unaff_s0;
  *(undefined8 *)(long)(int)(uVar2 + 0x80000088) = unaff_s1;
  *(undefined8 *)(long)(int)(uVar2 + 0x80000090) = unaff_s2;
  *(undefined8 *)(long)(int)(uVar2 + 0x80000098) = unaff_s3;
  *(undefined8 *)(long)(int)(uVar2 + 0x800000a0) = unaff_s4;
  *(undefined8 *)(long)(int)(uVar2 + 0x800000a8) = unaff_s5;
  *(undefined8 *)(long)(int)(uVar2 + 0x800000b0) = unaff_s6;
  *(undefined8 *)(long)(int)(uVar2 + 0x800000b8) = unaff_s7;
  *(undefined8 *)(long)(int)(uVar2 + 0x800000c0) = in_t8;
  *(undefined8 *)(long)(int)(uVar2 + 0x800000c8) = in_t9;
  *(undefined8 *)(long)(int)(uVar2 + 0x800000d0) = DESAVE;
  *(undefined8 *)(long)(int)(uVar2 + 0x800000d8) = in_k1;
  *(undefined8 *)(long)(int)(uVar2 + 0x800000e0) = unaff_gp;
  *(BADSPACEBASE **)(long)(int)(uVar2 + 0x800000e8) = register0x000000e8;
  *(undefined8 *)(long)(int)(uVar2 + 0x800000f0) = unaff_s8;
  *(undefined8 *)(long)(int)(uVar2 + 0x800000f8) = in_ra;
  *(undefined8 *)(long)(int)(uVar2 + 0x80000100) = Status;
  *(undefined8 *)(long)(int)(uVar2 + 0x80000108) = in_lo;
  *(undefined8 *)(long)(int)(uVar2 + 0x80000110) = in_hi;
  *(undefined8 *)(long)(int)(uVar2 + 0x80000118) = BadVAddr;
  *(undefined8 *)(long)(int)(uVar2 + 0x80000120) = Cause;
  *(undefined8 *)(long)(int)(uVar2 + 0x80000128) = DEPC;
  *(undefined8 *)(long)(int)(uVar2 + 0x80000130) = Index;
  *(undefined8 *)(long)(int)(uVar2 + 0x80000138) = Random;
  *(undefined8 *)(long)(int)(uVar2 + 0x80000140) = EntryLo0;
  *(undefined8 *)(long)(int)(uVar2 + 0x80000148) = EntryLo1;
  *(undefined8 *)(long)(int)(uVar2 + 0x80000150) = Context;
  *(undefined8 *)(long)(int)(uVar2 + 0x80000158) = PageMask;
  *(undefined8 *)(long)(int)(uVar2 + 0x80000160) = PageGrain;
  *(undefined8 *)(long)(int)(uVar2 + 0x80000168) = Wired;
  *(undefined8 *)(long)(int)(uVar2 + 0x80000170) = HWREna;
  *(undefined8 *)(long)(int)(uVar2 + 0x80000178) = Count;
  *(undefined8 *)(long)(int)(uVar2 + 0x80000180) = cop0_reg9_6;
  *(undefined8 *)(long)(int)(uVar2 + 0x80000188) = cop0_reg9_7;
  *(long *)(long)(int)(uVar2 + 0x80000190) = EntryHi;
  *(undefined8 *)(long)(int)(uVar2 + 0x80000198) = Compare;
  *(undefined8 *)(long)(int)(uVar2 + 0x800001a0) = cop0_reg11_7;
  *(undefined8 *)(long)(int)(uVar2 + 0x800001a8) = IntCtl;
  *(undefined8 *)(long)(int)(uVar2 + 0x800001b0) = SRSCtl;
  *(undefined8 *)(long)(int)(uVar2 + 0x800001b8) = EPC;
  *(undefined8 *)(long)(int)(uVar2 + 0x800001c0) = PRId;
  *(undefined8 *)(long)(int)(uVar2 + 0x800001c8) = EBase;
  *(undefined8 *)(long)(int)(uVar2 + 0x800001d0) = Config;
  *(undefined8 *)(long)(int)(uVar2 + 0x800001d8) = Config1;
  *(undefined8 *)(long)(int)(uVar2 + 0x800001e0) = Config2;
  *(undefined8 *)(long)(int)(uVar2 + 0x800001e8) = Config3;
  *(undefined8 *)(long)(int)(uVar2 + 0x800001f0) = WatchLo;
  *(undefined8 *)(long)(int)(uVar2 + 0x800001f8) = WatchLo_1;
  *(undefined8 *)(long)(int)(uVar2 + 0x80000200) = WatchHi;
  *(undefined8 *)(long)(int)(uVar2 + 0x80000208) = WatchHi_1;
  *(undefined8 *)(long)(int)(uVar2 + 0x80000210) = XContext;
  *(undefined8 *)(long)(int)(uVar2 + 0x80000218) = cop0_reg22;
  *(undefined8 *)(long)(int)(uVar2 + 0x80000220) = Debug;
  *(undefined8 *)(long)(int)(uVar2 + 0x80000228) = PerfCnt;
  *(undefined8 *)(long)(int)(uVar2 + 0x80000230) = PerfCnt_2;
  *(undefined8 *)(long)(int)(uVar2 + 0x80000238) = PerfCnt_1;
  *(undefined8 *)(long)(int)(uVar2 + 0x80000240) = PerfCnt_3;
  *(undefined8 *)(long)(int)(uVar2 + 0x80000248) = CacheErr;
  *(undefined8 *)(long)(int)(uVar2 + 0x80000250) = CacheErr_1;
  *(undefined8 *)(long)(int)(uVar2 + 0x80000258) = TagLo;
  *(undefined8 *)(long)(int)(uVar2 + 0x80000260) = TagLo_2;
  *(undefined8 *)(long)(int)(uVar2 + 0x80000268) = DataLo_1;
  *(undefined8 *)(long)(int)(uVar2 + 0x80000270) = DataLo_3;
  *(undefined8 *)(long)(int)(uVar2 + 0x80000278) = TagHi_2;
  *(undefined8 *)(long)(int)(uVar2 + 0x80000280) = DataHi_1;
  *(undefined8 *)(long)(int)(uVar2 + 0x80000288) = DataHi_3;
  *(undefined8 *)(long)(int)(uVar2 + 0x80000290) = ErrorEPC;
  *(undefined8 *)(long)(int)(uVar2 + 0x80000298) = DESAVE;
  *(undefined8 *)(long)(int)(uVar2 + 0x800002a0) = _DAT_ffffffffff301000;
  *(undefined8 *)(long)(int)(uVar2 + 0x800002a8) = _DAT_ffffffffff301100;
  *(undefined8 *)(long)(int)(uVar2 + 0x800002b0) = _DAT_ffffffffff301200;
  *(undefined8 *)(long)(int)(uVar2 + 0x800002b8) = _DAT_ffffffffff301300;
  *(undefined8 *)(long)(int)(uVar2 + 0x800002c0) = _DAT_ffffffffff301400;
  *(undefined8 *)(long)(int)(uVar2 + 0x800002c8) = _DAT_ffffffffff301108;
  *(undefined8 *)(long)(int)(uVar2 + 0x800002d0) = _DAT_ffffffffff301208;
  *(undefined8 *)(long)(int)(uVar2 + 0x800002d8) = _DAT_ffffffffff301308;
  *(undefined8 *)(long)(int)(uVar2 + 0x800002e0) = _DAT_ffffffffff301408;
  *(undefined8 *)(long)(int)(uVar2 + 0x800002e8) = _DAT_ffffffffff301110;
  *(undefined8 *)(long)(int)(uVar2 + 0x800002f0) = _DAT_ffffffffff301210;
  *(undefined8 *)(long)(int)(uVar2 + 0x800002f8) = _DAT_ffffffffff301310;
  *(undefined8 *)(long)(int)(uVar2 + 0x80000300) = _DAT_ffffffffff301410;
  *(undefined8 *)(long)(int)(uVar2 + 0x80000308) = _DAT_ffffffffff301118;
  *(undefined8 *)(long)(int)(uVar2 + 0x80000310) = _DAT_ffffffffff301218;
  *(undefined8 *)(long)(int)(uVar2 + 0x80000318) = _DAT_ffffffffff301318;
  *(undefined8 *)(long)(int)(uVar2 + 0x80000320) = _DAT_ffffffffff301418;
  *(undefined8 *)(long)(int)(uVar2 + 0x80000328) = _DAT_ffffffffff302000;
  *(undefined8 *)(long)(int)(uVar2 + 0x80000330) = _DAT_ffffffffff302100;
  *(undefined8 *)(long)(int)(uVar2 + 0x80000338) = _DAT_ffffffffff302200;
  *(undefined8 *)(long)(int)(uVar2 + 0x80000340) = _DAT_ffffffffff302300;
  *(undefined8 *)(long)(int)(uVar2 + 0x80000348) = _DAT_ffffffffff302400;
  *(undefined8 *)(long)(int)(uVar2 + 0x80000350) = _DAT_ffffffffff302108;
  *(undefined8 *)(long)(int)(uVar2 + 0x80000358) = _DAT_ffffffffff302208;
  *(undefined8 *)(long)(int)(uVar2 + 0x80000360) = _DAT_ffffffffff302308;
  *(undefined8 *)(long)(int)(uVar2 + 0x80000368) = _DAT_ffffffffff302408;
  *(undefined8 *)(long)(int)(uVar2 + 0x80000370) = _DAT_ffffffffff302110;
  *(undefined8 *)(long)(int)(uVar2 + 0x80000378) = _DAT_ffffffffff302210;
  *(undefined8 *)(long)(int)(uVar2 + 0x80000380) = _DAT_ffffffffff302310;
  *(undefined8 *)(long)(int)(uVar2 + 0x80000388) = _DAT_ffffffffff302410;
  *(undefined8 *)(long)(int)(uVar2 + 0x80000390) = _DAT_ffffffffff302118;
  *(undefined8 *)(long)(int)(uVar2 + 0x80000398) = _DAT_ffffffffff302218;
  *(undefined8 *)(long)(int)(uVar2 + 0x800003a0) = _DAT_ffffffffff302318;
  *(long *)(long)(int)(uVar2 + 0x800003a8) = _DAT_ffffffffff302418;
  plVar4 = (long *)(long)(int)(uVar2 + 0x800003b0);
  uVar3 = 0xffffffffffffffff;
  do {
    uVar3 = (ulong)((int)uVar3 + 1);
    setCopReg(0,Index,uVar3);
    EntryHi = TLB_read_indexed_entryHi(Index);
    EntryLo0 = TLB_read_indexed_entryLo0(Index);
    EntryLo1 = TLB_read_indexed_entryLo1(Index);
    PageMask = TLB_read_indexed_entryPageMask(Index);
    *plVar4 = EntryHi;
    iVar5 = (int)plVar4;
    *(undefined8 *)(long)(iVar5 + 8) = PageMask;
    *(undefined8 *)(long)(iVar5 + 0x10) = EntryLo0;
    *(undefined8 *)(long)(iVar5 + 0x18) = EntryLo1;
    *(undefined8 *)(long)(iVar5 + 0x20) = 0;
    plVar4 = (long *)(long)(iVar5 + 0x28);
  } while (uVar3 != ((long)(int)(Config1._4_4_ >> 0x19) & 0x3fU));
  SYNC(4);
  *plVar4 = 1;
  SYNC(4);
  do {
  } while (*plVar4 != 0);
  uVar3 = (long)(int)(Config1._4_4_ >> 0x19) & 0x3f;
  do {
    setCopReg(0,Index,uVar3);
    iVar5 = (int)plVar4;
    plVar4 = (long *)(long)(iVar5 + -0x28);
    TLB_write_indexed_entry
              (Index,*(undefined8 *)((long)(iVar5 + -0x20) + -8),
               *(undefined8 *)((long)(iVar5 + -0x10) + -8),*(undefined8 *)((long)(iVar5 + -8) + -8),
               *(undefined8 *)((long)(iVar5 + -0x18) + -8));
    bVar1 = uVar3 != 0;
    uVar3 = (ulong)((int)uVar3 + -1);
  } while (bVar1);
  _DAT_ffffffffff302418 = plVar4[-1];
  _DAT_ffffffffff302318 = *(undefined8 *)((long)(iVar5 + -0x30) + -8);
  _DAT_ffffffffff302218 = *(undefined8 *)((long)(iVar5 + -0x38) + -8);
  _DAT_ffffffffff302118 = *(undefined8 *)((long)(iVar5 + -0x40) + -8);
  _DAT_ffffffffff302410 = *(undefined8 *)((long)(iVar5 + -0x48) + -8);
  _DAT_ffffffffff302310 = *(undefined8 *)((long)(iVar5 + -0x50) + -8);
  _DAT_ffffffffff302210 = *(undefined8 *)((long)(iVar5 + -0x58) + -8);
  _DAT_ffffffffff302110 = *(undefined8 *)((long)(iVar5 + -0x60) + -8);
  _DAT_ffffffffff302408 = *(undefined8 *)((long)(iVar5 + -0x68) + -8);
  _DAT_ffffffffff302308 = *(undefined8 *)((long)(iVar5 + -0x70) + -8);
  _DAT_ffffffffff302208 = *(undefined8 *)((long)(iVar5 + -0x78) + -8);
  _DAT_ffffffffff302108 = *(undefined8 *)((long)(iVar5 + -0x80) + -8);
  _DAT_ffffffffff302400 = *(undefined8 *)((long)(iVar5 + -0x88) + -8);
  _DAT_ffffffffff302300 = *(undefined8 *)((long)(iVar5 + -0x90) + -8);
  _DAT_ffffffffff302200 = *(undefined8 *)((long)(iVar5 + -0x98) + -8);
  _DAT_ffffffffff302100 = *(undefined8 *)((long)(iVar5 + -0xa0) + -8);
  _DAT_ffffffffff302000 = *(undefined8 *)((long)(iVar5 + -0xa8) + -8);
  _DAT_ffffffffff301418 = *(undefined8 *)((long)(iVar5 + -0xb0) + -8);
  _DAT_ffffffffff301318 = *(undefined8 *)((long)(iVar5 + -0xb8) + -8);
  _DAT_ffffffffff301218 = *(undefined8 *)((long)(iVar5 + -0xc0) + -8);
  _DAT_ffffffffff301118 = *(undefined8 *)((long)(iVar5 + -200) + -8);
  _DAT_ffffffffff301410 = *(undefined8 *)((long)(iVar5 + -0xd0) + -8);
  _DAT_ffffffffff301310 = *(undefined8 *)((long)(iVar5 + -0xd8) + -8);
  _DAT_ffffffffff301210 = *(undefined8 *)((long)(iVar5 + -0xe0) + -8);
  _DAT_ffffffffff301110 = *(undefined8 *)((long)(iVar5 + -0xe8) + -8);
  _DAT_ffffffffff301408 = *(undefined8 *)((long)(iVar5 + -0xf0) + -8);
  _DAT_ffffffffff301308 = *(undefined8 *)((long)(iVar5 + -0xf8) + -8);
  _DAT_ffffffffff301208 = *(undefined8 *)((long)(iVar5 + -0x100) + -8);
  _DAT_ffffffffff301108 = *(undefined8 *)((long)(iVar5 + -0x108) + -8);
  _DAT_ffffffffff301400 = *(undefined8 *)((long)(iVar5 + -0x110) + -8);
  _DAT_ffffffffff301300 = *(undefined8 *)((long)(iVar5 + -0x118) + -8);
  _DAT_ffffffffff301200 = *(undefined8 *)((long)(iVar5 + -0x120) + -8);
  _DAT_ffffffffff301100 = *(undefined8 *)((long)(iVar5 + -0x128) + -8);
  _DAT_ffffffffff301000 = *(undefined8 *)((long)(iVar5 + -0x130) + -8);
  DESAVE = *(undefined8 *)((long)(iVar5 + -0x138) + -8);
  ErrorEPC = *(undefined8 *)((long)(iVar5 + -0x140) + -8);
  DataHi_3 = *(undefined8 *)((long)(iVar5 + -0x148) + -8);
  DataHi_1 = *(undefined8 *)((long)(iVar5 + -0x150) + -8);
  TagHi_2 = *(undefined8 *)((long)(iVar5 + -0x158) + -8);
  DataLo_3 = *(undefined8 *)((long)(iVar5 + -0x160) + -8);
  DataLo_1 = *(undefined8 *)((long)(iVar5 + -0x168) + -8);
  TagLo_2 = *(undefined8 *)((long)(iVar5 + -0x170) + -8);
  TagLo = *(undefined8 *)((long)(iVar5 + -0x178) + -8);
  CacheErr_1 = *(undefined8 *)((long)(iVar5 + -0x180) + -8);
  CacheErr = *(undefined8 *)((long)(iVar5 + -0x188) + -8);
  PerfCnt_3 = *(undefined8 *)((long)(iVar5 + -400) + -8);
  PerfCnt_1 = *(undefined8 *)((long)(iVar5 + -0x198) + -8);
  PerfCnt_2 = *(undefined8 *)((long)(iVar5 + -0x1a0) + -8);
  PerfCnt = *(undefined8 *)((long)(iVar5 + -0x1a8) + -8);
  Debug = *(undefined8 *)((long)(iVar5 + -0x1b0) + -8);
  cop0_reg22 = *(undefined8 *)((long)(iVar5 + -0x1b8) + -8);
  XContext = *(undefined8 *)((long)(iVar5 + -0x1c0) + -8);
  WatchHi_1 = *(undefined8 *)((long)(iVar5 + -0x1c8) + -8);
  WatchHi = *(undefined8 *)((long)(iVar5 + -0x1d0) + -8);
  WatchLo_1 = *(undefined8 *)((long)(iVar5 + -0x1d8) + -8);
  WatchLo = *(undefined8 *)((long)(iVar5 + -0x1e0) + -8);
  Config3 = *(undefined8 *)((long)(iVar5 + -0x1e8) + -8);
  Config2 = *(undefined8 *)((long)(iVar5 + -0x1f0) + -8);
  Config1 = *(undefined8 *)((long)(iVar5 + -0x1f8) + -8);
  Config = *(undefined8 *)((long)(iVar5 + -0x200) + -8);
  EBase = *(undefined8 *)((long)(iVar5 + -0x208) + -8);
  PRId = *(undefined8 *)((long)(iVar5 + -0x210) + -8);
  EPC = *(undefined8 *)((long)(iVar5 + -0x218) + -8);
  SRSCtl = *(undefined8 *)((long)(iVar5 + -0x220) + -8);
  IntCtl = *(undefined8 *)((long)(iVar5 + -0x228) + -8);
  cop0_reg11_7 = *(undefined8 *)((long)(iVar5 + -0x230) + -8);
  Compare = *(undefined8 *)((long)(iVar5 + -0x238) + -8);
  EntryHi = *(undefined8 *)((long)(iVar5 + -0x240) + -8);
  cop0_reg9_7 = *(undefined8 *)((long)(iVar5 + -0x248) + -8);
  cop0_reg9_6 = *(undefined8 *)((long)(iVar5 + -0x250) + -8);
  Count = *(undefined8 *)((long)(iVar5 + -600) + -8);
  HWREna = *(undefined8 *)((long)(iVar5 + -0x260) + -8);
  Wired = *(undefined8 *)((long)(iVar5 + -0x268) + -8);
  PageGrain = *(undefined8 *)((long)(iVar5 + -0x270) + -8);
  PageMask = *(undefined8 *)((long)(iVar5 + -0x278) + -8);
  Context = *(undefined8 *)((long)(iVar5 + -0x280) + -8);
  EntryLo1 = *(undefined8 *)((long)(iVar5 + -0x288) + -8);
  EntryLo0 = *(undefined8 *)((long)(iVar5 + -0x290) + -8);
  Random = *(undefined8 *)((long)(iVar5 + -0x298) + -8);
  Index = *(undefined8 *)((long)(iVar5 + -0x2a0) + -8);
  DEPC = *(undefined8 *)((long)(iVar5 + -0x2a8) + -8);
  Cause = *(undefined8 *)((long)(iVar5 + -0x2b0) + -8);
  BadVAddr = *(undefined8 *)((long)(iVar5 + -0x2b8) + -8);
  Status = *(undefined8 *)((long)(iVar5 + -0x2d0) + -8);
  auVar6._0_8_ = *(undefined8 *)((long)(iVar5 + -0x3b8) + -8);
  auVar6._8_8_ = *(undefined8 *)((long)(iVar5 + -0x3c0) + -8);
  return auVar6;
}

