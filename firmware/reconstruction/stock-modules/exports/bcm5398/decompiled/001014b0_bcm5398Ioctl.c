/*
 * Ghidra reconstructed C; not original Cisco source.
 * Analysis: rv220w-stock-modules-v1.0.0
 * Module: bcm5398
 * Entry: 001014b0
 * Function: bcm5398Ioctl
 * Subsystem: bcm53115-switch
 * Evidence: retained-or-recovered-symbol
 *
 * Embedded Ghidra annotation:
 * RV220W STOCK MODULE SEMANTIC ANNOTATION v1.0.0
 * Module: bcm5398
 * Subsystem: BCM53115 switch/VLAN datapath
 * Evidence class: retained or recovered ELF/source symbol
 * Confidence: high for identity; medium for detailed semantics
 * Interpretation: Character-device ioctl dispatcher exposing switch operations to vendor userspace; command decoding is preserved in the decompiled export.
 * Callers: 
 * Callees: 
 * Referenced strings: none recovered
 * Safety note: decompiler output is reconstructed C, not original Cisco source. Register meanings remain hypotheses unless tied to constants, vendor strings, runtime behavior or upstream register definitions.
 */

/* WARNING: Type propagation algorithm not settling */
/* RV220W STOCK MODULE SEMANTIC ANNOTATION v1.0.0
   Module: bcm5398
   Subsystem: BCM53115 switch/VLAN datapath
   Evidence class: retained or recovered ELF/source symbol
   Confidence: high for identity; medium for detailed semantics
   Interpretation: Character-device ioctl dispatcher exposing switch operations to vendor userspace;
   command decoding is preserved in the decompiled export.
   Callers: 
   Callees: 
   Referenced strings: none recovered
   Safety note: decompiler output is reconstructed C, not original Cisco source. Register meanings
   remain hypotheses unless tied to constants, vendor strings, runtime behavior or upstream register
   definitions.
    */

uint bcm5398Ioctl(undefined8 param_1,undefined8 param_2,ulonglong param_3,ulonglong param_4)

{
  uint uVar1;
  longlong lVar2;
  uint uVar3;
  uint extraout_a1_lo;
  longlong extraout_a2;
  longlong extraout_a2_00;
  longlong extraout_a2_01;
  ushort *puVar4;
  longlong extraout_a2_02;
  longlong extraout_a2_03;
  longlong extraout_a2_04;
  longlong extraout_a2_05;
  longlong extraout_a2_06;
  longlong extraout_a2_07;
  longlong extraout_a2_08;
  longlong extraout_a2_09;
  longlong extraout_a2_10;
  longlong extraout_a2_11;
  longlong extraout_a2_12;
  longlong extraout_a2_13;
  longlong extraout_a2_14;
  longlong extraout_a2_15;
  longlong extraout_a2_16;
  longlong extraout_a2_17;
  longlong extraout_a2_18;
  longlong extraout_a2_19;
  longlong extraout_a2_20;
  ushort *puVar5;
  ulonglong uVar6;
  int unaff_gp_lo;
  ushort uStack_30;
  ushort uStack_2e;
  ushort uStack_2c;
  undefined2 uStack_2a;
  undefined1 auStack_28 [2];
  undefined1 auStack_26 [6];
  
  if (param_3 == 0xffffffff8005530c) {
    if (((param_4 | param_4 + 4) & *(ulonglong *)(unaff_gp_lo + 0x28)) != 0) {
      return 0xfffffff2;
    }
    (*(code *)&__copy_user)(&uStack_2a,param_4,5);
    if (extraout_a2_02 != 0) {
      return 0xfffffff2;
    }
    if (0xfff < uStack_2a) {
      return 0xfffffffb;
    }
    if (8 < (ushort)auStack_28) {
      return 0xfffffffb;
    }
    lVar2 = bcm5398VlanEntryGet(param_1,uStack_2a,&uStack_2c,&uStack_2e);
    if (lVar2 == -1) {
      return 0xfffffffb;
    }
    lVar2 = bcm5398VlanEntrySet(param_1,uStack_2a,uStack_2c);
  }
  else if (param_3 < 0xffffffff8005530d) {
    if (param_3 == 0xffffffff80045304) {
      if (((param_4 | param_4 + 3) & *(ulonglong *)(unaff_gp_lo + 0x28)) != 0) {
        return 0xfffffff2;
      }
      (*(code *)&__copy_user)(&uStack_2a,param_4,4);
      if (extraout_a2_06 != 0) {
        return 0xfffffff2;
      }
      if (8 < uStack_2a) {
        return 0xfffffffb;
      }
      if (8 < (ushort)auStack_28) {
        return 0xfffffffb;
      }
      lVar2 = bcm5398PortEntryGet(param_1,uStack_2a & 0xff,&uStack_30);
      if (lVar2 == -1) {
        return 0xfffffffb;
      }
      uStack_30 = (ushort)(1L << (ulonglong)(ushort)auStack_28) | uStack_30;
      lVar2 = bcm5398PortEntrySet(param_1,(undefined1)uStack_2a);
    }
    else if (param_3 < 0xffffffff80045305) {
      if (param_3 != 0x20005302) {
        if (0x20005302 < param_3) {
          if (param_3 == 0x20005319) {
            if (8 < (param_4 & 0xffff)) {
              return 0xfffffffb;
            }
            uVar3 = bcm5398PortLinkStatusQuery(param_1,param_4 & 0xff);
            return uVar3;
          }
          if (param_3 == 0xffffffff80045303) {
            if (((param_4 | param_4 + 3) & *(ulonglong *)(unaff_gp_lo + 0x28)) != 0) {
              return 0xfffffff2;
            }
            (*(code *)&__copy_user)(&uStack_2a,param_4,4);
            if (extraout_a2_04 != 0) {
              return 0xfffffff2;
            }
            if (8 < uStack_2a) {
              return 0xfffffffb;
            }
            if ((ushort)auStack_28 < 9) {
              lVar2 = bcm5398PortEntryGet(param_1,uStack_2a & 0xff,&uStack_30);
              if (lVar2 == -1) {
                return 0xfffffffb;
              }
              return uStack_30 >> (ulonglong)(ushort)auStack_28 & 1;
            }
            return 0xfffffffb;
          }
code_r0x00101af0:
          (*(code *)&printk)(&UNK_001030d8);
          return 0xffffffe7;
        }
        if (param_3 != 0x20005300) {
          if (param_3 == 0x20005301) {
            lVar2 = bcm5398VlanEnable();
            goto joined_r0x00101d5c;
          }
          goto code_r0x00101af0;
        }
      }
      lVar2 = bcm5398VlanDisable();
    }
    else if (param_3 == 0xffffffff80055309) {
      if (((param_4 | param_4 + 4) & *(ulonglong *)(unaff_gp_lo + 0x28)) != 0) {
        return 0xfffffff2;
      }
      (*(code *)&__copy_user)(&uStack_2a,param_4,5);
      if (extraout_a2_10 != 0) {
        return 0xfffffff2;
      }
      if (0xfff < uStack_2a) {
        return 0xfffffffb;
      }
      if (8 < (ushort)auStack_28) {
        return 0xfffffffb;
      }
      lVar2 = bcm5398VlanEntryGet(param_1,uStack_2a,&uStack_2e,&uStack_2c);
      if (lVar2 == -1) {
        return 0xfffffffb;
      }
      lVar2 = bcm5398VlanEntrySet(param_1,uStack_2a,
                                  (uint)(1L << (ulonglong)(ushort)auStack_28) & 0xffff |
                                  (uint)uStack_2e,uStack_2c);
    }
    else if (param_3 < 0xffffffff8005530a) {
      if (param_3 != 0xffffffff80045305) {
        if (param_3 != 0xffffffff80055308) goto code_r0x00101af0;
        if (((param_4 | param_4 + 4) & *(ulonglong *)(unaff_gp_lo + 0x28)) != 0) {
          return 0xfffffff2;
        }
        (*(code *)&__copy_user)(&uStack_2a,param_4,5);
        if (extraout_a2_20 != 0) {
          return 0xfffffff2;
        }
        if (0xfff < uStack_2a) {
          return 0xfffffffb;
        }
        if (8 < (ushort)auStack_28) {
          return 0xfffffffb;
        }
        puVar4 = &uStack_2c;
        puVar5 = &uStack_2e;
code_r0x001016d0:
        lVar2 = bcm5398VlanEntryGet(param_1,uStack_2a,puVar4,puVar5);
        if (lVar2 == -1) {
          return 0xfffffffb;
        }
        return uStack_2c >> (ulonglong)(ushort)auStack_28 & 1;
      }
      if (((param_4 | param_4 + 3) & *(ulonglong *)(unaff_gp_lo + 0x28)) != 0) {
        return 0xfffffff2;
      }
      (*(code *)&__copy_user)(&uStack_2a,param_4,4);
      if (extraout_a2_19 != 0) {
        return 0xfffffff2;
      }
      if (8 < uStack_2a) {
        return 0xffffffff;
      }
      if (8 < (ushort)auStack_28) {
        return 0xffffffff;
      }
      lVar2 = bcm5398PortEntryGet(param_1,uStack_2a & 0xff,&uStack_30);
      if (lVar2 == -1) {
        return 0xffffffff;
      }
      uStack_30 = uStack_30 & ~(ushort)(1L << (ulonglong)(ushort)auStack_28);
      lVar2 = bcm5398PortEntrySet(param_1,(undefined1)uStack_2a);
    }
    else {
      if (param_3 != 0xffffffff8005530a) {
        if (param_3 != 0xffffffff8005530b) goto code_r0x00101af0;
        if (((param_4 | param_4 + 4) & *(ulonglong *)(unaff_gp_lo + 0x28)) != 0) {
          return 0xfffffff2;
        }
        (*(code *)&__copy_user)(&uStack_2a,param_4,5);
        if (extraout_a2_01 != 0) {
          return 0xfffffff2;
        }
        if (0xfff < uStack_2a) {
          return 0xfffffffb;
        }
        if (8 < (ushort)auStack_28) {
          return 0xfffffffb;
        }
        puVar4 = &uStack_2e;
        puVar5 = &uStack_2c;
        goto code_r0x001016d0;
      }
      if (((param_4 | param_4 + 4) & *(ulonglong *)(unaff_gp_lo + 0x28)) != 0) {
        return 0xfffffff2;
      }
      (*(code *)&__copy_user)(&uStack_2a,param_4,5);
      if (extraout_a2_13 != 0) {
        return 0xfffffff2;
      }
      if (0xfff < uStack_2a) {
        return 0xfffffffb;
      }
      if (8 < (ushort)auStack_28) {
        return 0xfffffffb;
      }
      lVar2 = bcm5398VlanEntryGet(param_1,uStack_2a,&uStack_2c,&uStack_2e);
      if (lVar2 == -1) {
        return 0xfffffffb;
      }
      lVar2 = bcm5398VlanEntrySet(param_1,uStack_2a,
                                  (uint)uStack_2c & ~(uint)(1L << (ulonglong)(ushort)auStack_28),
                                  uStack_2e);
    }
  }
  else if (param_3 == 0xffffffff8006531d) {
    if (((param_4 | param_4 + 5) & *(ulonglong *)(unaff_gp_lo + 0x28)) != 0) {
      return 0xfffffff2;
    }
    (*(code *)&__copy_user)(&uStack_2a,param_4,6);
    if (extraout_a2_05 != 0) {
      return 0xfffffff2;
    }
    uVar3 = (uint)&uStack_2a & 3;
    if (8 < (ushort)auStack_26._0_2_) {
      return 0xfffffffb;
    }
    uVar1 = (uint)(auStack_28 + 1) & 3;
    lVar2 = bcm5398PortMirrorSet
                      (param_1,((*(int *)((int)&uStack_2a - uVar3) << uVar3 * 8 |
                                extraout_a1_lo & 0xffffffffU >> (4 - uVar3) * 8) &
                                -1 << (uVar1 + 1) * 8 |
                               *(uint *)(auStack_28 + 1 + -uVar1) >> (3 - uVar1) * 8) & 0xffff);
  }
  else {
    if (0xffffffff8006531d < param_3) {
      if (param_3 == 0xffffffffc005530e) {
        uVar6 = param_4 | param_4 + 4;
        if ((uVar6 & *(ulonglong *)(unaff_gp_lo + 0x28)) != 0) {
          return 0xfffffff2;
        }
        (*(code *)&__copy_user)(&uStack_2a,param_4,5);
        if (extraout_a2_11 != 0) {
          return 0xfffffff2;
        }
        if (0xfff < uStack_2a) {
          return 0xfffffffb;
        }
        lVar2 = bcm5398VlanEntryGet(param_1,uStack_2a,&uStack_2c,&uStack_2e);
        if (lVar2 == -1) {
          return 0xfffffffb;
        }
        if ((uVar6 & *(ulonglong *)(unaff_gp_lo + 0x28)) != 0) {
          return 0xfffffff2;
        }
        (*(code *)&__copy_user)(param_4,&uStack_2a,5);
        lVar2 = extraout_a2_12;
      }
      else {
        if (param_3 < 0xffffffffc005530f) {
          if (param_3 == 0xffffffff8007531b) {
            if (((param_4 | param_4 + 6) & *(ulonglong *)(unaff_gp_lo + 0x28)) != 0) {
              return 0xfffffff2;
            }
            (*(code *)&__copy_user)(&uStack_2a,param_4,7);
            if (extraout_a2_18 != 0) {
              return 0xfffffff2;
            }
            if (8 < uStack_2a) {
              return 0xfffffffb;
            }
            lVar2 = bcm5398PortConfigSet(param_1,uStack_2a & 0xff,auStack_26[0],auStack_26[1]);
          }
          else {
            if (param_3 != 0xffffffff8007531c) goto code_r0x00101af0;
            if (((param_4 | param_4 + 6) & *(ulonglong *)(unaff_gp_lo + 0x28)) != 0) {
              return 0xfffffff2;
            }
            (*(code *)&__copy_user)(&uStack_2a,param_4,7);
            if (extraout_a2_07 != 0) {
              return 0xfffffff2;
            }
            lVar2 = bcm5398PortStateSet(param_1,(undefined1)uStack_2a,auStack_28);
          }
          goto joined_r0x00101d5c;
        }
        if (param_3 != 0xffffffffc0065306) {
          if (param_3 == 0xffffffffc007531a) {
            uVar6 = param_4 | param_4 + 6;
            if ((uVar6 & *(ulonglong *)(unaff_gp_lo + 0x28)) != 0) {
              return 0xfffffff2;
            }
            (*(code *)&__copy_user)(&uStack_2a,param_4,7);
            if (extraout_a2 != 0) {
              return 0xfffffff2;
            }
            if (8 < uStack_2a) {
              return 0xfffffffb;
            }
            lVar2 = bcm5398PortConfigGet(param_1,uStack_2a & 0xff,auStack_28 + 2,auStack_28 + 3);
            if (lVar2 != -1) {
              if ((uVar6 & *(ulonglong *)(unaff_gp_lo + 0x28)) != 0) {
                return 0xfffffff2;
              }
              (*(code *)&__copy_user)(param_4,&uStack_2a,7);
              if (extraout_a2_00 != 0) {
                return 0xfffffff2;
              }
              return 0;
            }
            return 0xfffffffb;
          }
          goto code_r0x00101af0;
        }
        uVar6 = param_4 | param_4 + 5;
        if ((uVar6 & *(ulonglong *)(unaff_gp_lo + 0x28)) != 0) {
          return 0xfffffff2;
        }
        (*(code *)&__copy_user)(&uStack_2a,param_4,6);
        if (extraout_a2_16 != 0) {
          return 0xfffffff2;
        }
        if (8 < uStack_2a) {
          return 0xfffffffb;
        }
        lVar2 = bcm5398PortDefaultTagGet(param_1,uStack_2a & 0xff,&uStack_2c,&uStack_2e);
        if (lVar2 == -1) {
          return 0xfffffffb;
        }
        if ((uVar6 & *(ulonglong *)(unaff_gp_lo + 0x28)) != 0) {
          return 0xfffffff2;
        }
        (*(code *)&__copy_user)(param_4,&uStack_2a,6);
        lVar2 = extraout_a2_17;
      }
      if (lVar2 != 0) {
        return 0xfffffff2;
      }
      return 0;
    }
    if (param_3 == 0xffffffff80055310) {
      if (((param_4 | param_4 + 4) & *(ulonglong *)(unaff_gp_lo + 0x28)) != 0) {
        return 0xfffffff2;
      }
      (*(code *)&__copy_user)(&uStack_2a,param_4,5);
      if (extraout_a2_09 != 0) {
        return 0xfffffff2;
      }
      if (0xfff < uStack_2a) {
        return 0xfffffffb;
      }
      lVar2 = bcm5398VlanEntrySet(param_1);
    }
    else if (param_3 < 0xffffffff80055311) {
      if (param_3 == 0xffffffff8005530d) {
        if (((param_4 | param_4 + 4) & *(ulonglong *)(unaff_gp_lo + 0x28)) != 0) {
          return 0xfffffff2;
        }
        (*(code *)&__copy_user)(&uStack_2a,param_4,5);
        if (extraout_a2_15 != 0) {
          return 0xfffffff2;
        }
        if (0xfff < uStack_2a) {
          return 0xfffffffb;
        }
        if (8 < (ushort)auStack_28) {
          return 0xfffffffb;
        }
        lVar2 = bcm5398VlanEntryGet(param_1,uStack_2a,&uStack_2e,&uStack_2c);
        if (lVar2 == -1) {
          return 0xfffffffb;
        }
        lVar2 = bcm5398VlanEntrySet(param_1,uStack_2a,uStack_2e);
      }
      else {
        if (param_3 != 0xffffffff8005530f) goto code_r0x00101af0;
        if (((param_4 | param_4 + 4) & *(ulonglong *)(unaff_gp_lo + 0x28)) != 0) {
          return 0xfffffff2;
        }
        (*(code *)&__copy_user)(&uStack_2a,param_4,5);
        if (extraout_a2_03 != 0) {
          return 0xfffffff2;
        }
        if (0xfff < uStack_2a) {
          return 0xfffffffb;
        }
        if (0xf < auStack_26[0]) {
          return 0xfffffffb;
        }
        lVar2 = bcm5398VlanEntryGet(param_1,uStack_2a,&uStack_2e,&uStack_2c);
        if (lVar2 == -1) {
          return 0xfffffffb;
        }
        uStack_30 = CONCAT11(auStack_26[0],(undefined1)uStack_30);
        lVar2 = bcm5398VlanEntrySet(param_1,uStack_2a,uStack_2e,uStack_2c);
      }
    }
    else if (param_3 == 0xffffffff80065307) {
      if (((param_4 | param_4 + 5) & *(ulonglong *)(unaff_gp_lo + 0x28)) != 0) {
        return 0xfffffff2;
      }
      (*(code *)&__copy_user)(&uStack_2a,param_4,6);
      if (extraout_a2_14 != 0) {
        return 0xfffffff2;
      }
      if (8 < uStack_2a) {
        return 0xfffffffb;
      }
      if (0xfff < (ushort)auStack_28) {
        return 0xfffffffb;
      }
      if (3 < auStack_26[0]) {
        return 0xfffffffb;
      }
      if (1 < auStack_26[1]) {
        return 0xfffffffb;
      }
      lVar2 = bcm5398PortDefaultTagSet(param_1,uStack_2a & 0xff);
    }
    else {
      if (param_3 != 0xffffffff80065311) goto code_r0x00101af0;
      if (((param_4 | param_4 + 5) & *(ulonglong *)(unaff_gp_lo + 0x28)) != 0) {
        return 0xfffffff2;
      }
      (*(code *)&__copy_user)(&uStack_2a,param_4,6);
      if (extraout_a2_08 != 0) {
        return 0xfffffff2;
      }
      if (8 < uStack_2a) {
        return 0xfffffffb;
      }
      uVar3 = (uint)(auStack_28 + 3) & 3;
      lVar2 = bcm5398VlanNon8021QSet
                        (param_1,uStack_2a,
                         _auStack_28 & -1 << (uVar3 + 1) * 8 |
                         *(uint *)(auStack_28 + 3 + -uVar3) >> (3 - uVar3) * 8);
    }
  }
joined_r0x00101d5c:
  if (lVar2 == -1) {
    return 0xfffffffb;
  }
  return 0;
}

