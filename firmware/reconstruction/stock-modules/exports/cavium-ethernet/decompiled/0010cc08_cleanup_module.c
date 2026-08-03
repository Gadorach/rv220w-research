/*
 * Ghidra reconstructed C; not original Cisco source.
 * Analysis: rv220w-stock-modules-v1.0.0
 * Module: cavium-ethernet
 * Entry: 0010cc08
 * Function: cleanup_module
 * Subsystem: module-lifecycle
 * Evidence: retained-or-recovered-symbol
 *
 * Embedded Ghidra annotation:
 * RV220W STOCK MODULE SEMANTIC ANNOTATION v1.0.0
 * Module: cavium-ethernet
 * Subsystem: Kernel module lifecycle
 * Evidence class: retained or recovered ELF/source symbol
 * Confidence: high for identity; medium for detailed semantics
 * Interpretation: Module teardown path; reverses registrations and frees runtime resources.
 * Callers: 
 * Callees: 
 * Referenced strings: none recovered
 * Safety note: decompiler output is reconstructed C, not original Cisco source. Register meanings remain hypotheses unless tied to constants, vendor strings, runtime behavior or upstream register definitions.
 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Removing unreachable block (ram,0x0010d838) */
/* RV220W STOCK MODULE SEMANTIC ANNOTATION v1.0.0
   Module: cavium-ethernet
   Subsystem: Kernel module lifecycle
   Evidence class: retained or recovered ELF/source symbol
   Confidence: high for identity; medium for detailed semantics
   Interpretation: Module teardown path; reverses registrations and frees runtime resources.
   Callers: 
   Callees: 
   Referenced strings: none recovered
   Safety note: decompiler output is reconstructed C, not original Cisco source. Register meanings
   remain hypotheses unless tied to constants, vendor strings, runtime behavior or upstream register
   definitions.
    */

void cleanup_module(void)

{
  undefined4 uVar1;
  int iVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  undefined8 *puVar7;
  ulonglong uVar6;
  undefined8 uVar8;
  undefined8 *puVar9;
  int iVar10;
  longlong lVar11;
  undefined1 *puVar13;
  ulonglong uVar12;
  longlong lVar14;
  ulonglong uVar15;
  longlong lVar16;
  
  uVar8 = special2((longlong)pow_receive_group,(longlong)pow_receive_group,3,0x32);
  lVar16 = 0;
  *(undefined8 *)(pow_receive_group + ((uint)uVar8 | 0x80)) = 0;
  uRam00000018 = uRam00000018 & 0xfffffffffffffffe;
  (*(code *)&free_irq)(pow_receive_group + 8,cvm_oct_device);
  cvm_ipfwd_ptr_flush();
  do {
    lVar14 = 0;
    lVar11 = lVar16 + cvm_gbl_ipfwd_cache + 0x1c;
    do {
      puVar7 = (undefined8 *)*(undefined4 *)lVar11;
      uVar3 = (ulonglong)(int)puVar7;
      special2(uVar3,uVar3,7,0x32);
      if (uVar3 != 0) {
        if (uVar3 == 0) {
          (*(code *)&cvmx_warn)(&UNK_0010e120);
          puVar7 = (undefined8 *)0x0;
code_r0x0010cd8c:
          puVar9 = puVar7;
        }
        else {
          puVar9 = (undefined8 *)((uint)puVar7 & 0x3fffffff);
          if ((longlong)(uVar3 & 0x7fffffffffffffff | 0x8000000000000000) >> 0x3e != 3)
          goto code_r0x0010cd8c;
        }
        SYNC(4);
        SYNC(4);
        *puVar9 = 0;
      }
      lVar14 = lVar14 + 1;
      lVar11 = lVar11 + 0x20;
    } while (lVar14 != 5);
    lVar16 = lVar16 + 0xa8;
  } while (lVar16 != 0x54000);
  lVar16 = (*(code *)&__printk_ratelimit)(0xfa,10);
  if (lVar16 != 0) {
    (*(code *)&printk)(&UNK_0010e150);
  }
  (*(code *)&del_timer)(0x1111f8);
  cvm_oct_rx_shutdown();
  (*(code *)&cvmx_pko_disable)();
  puVar13 = cvm_oct_device;
  do {
    if (*(longlong *)puVar13 != 0) {
      cvm_oct_tx_shutdown();
      (*(code *)&unregister_netdev)(*(longlong *)puVar13);
      (*(code *)&kfree)(*(longlong *)puVar13);
      *(longlong *)puVar13 = 0;
    }
    puVar13 = (undefined1 *)((int)puVar13 + 8);
  } while ((longlong *)puVar13 != (longlong *)0x1111f0);
  (*(code *)&cvmx_pko_shutdown)();
  cvm_oct_proc_shutdown();
  uVar3 = uRam00000320;
  iVar2 = (int)uRam00000320;
  if (PRId == 0xd0200) {
code_r0x0010d7bc:
    uVar1 = getCopReg(2,0x11);
    *(undefined4 *)(iVar2 + -0x209) = uVar1;
  }
  else {
    if ((PRId & 0xffff1f) == 0xd0000) goto code_r0x0010d31c;
    if (PRId == 0xd0200) goto code_r0x0010d7bc;
    if ((PRId & 0xffff1f) == 0xd0001) goto code_r0x0010d31c;
    setCopReg(2,0x1111f0,*(undefined4 *)(iVar2 + 0x13));
    special2(uRam00000360,0x80014f0000000360,7,0x32);
    SYNC(4);
    SYNC(4);
    uRam00000360 = 0;
  }
  uVar4 = uVar3 & 0x7f;
  if (uVar4 != 0) {
    uVar12 = uRam00000340;
    if (uVar4 != 0) {
      uVar15 = 0;
      do {
        uVar12 = uRam00000340 >> 0x36 & 0x7f;
        iVar10 = (int)uVar12;
        if (uVar12 == 0) {
          trap(7);
        }
        uVar12 = uRam00000340 & 0xfffffffffffffe00 |
                 (longlong)
                 ((int)(((uint)(uRam00000340 >> 0x2e) & 0xff) + (int)uVar15) % iVar10 + iVar10) &
                 0xffU;
        uVar6 = (uRam00000340 & 0x3ffffffe00) >> 9;
        uVar5 = uVar6 * 0x80;
        if (uVar6 == 0) {
          uRam00000340 = uVar12;
          (*(code *)&cvmx_warn)(&UNK_0010e120);
          uVar5 = 0;
code_r0x0010d0c4:
          puVar7 = (undefined8 *)uVar5;
        }
        else {
          puVar7 = (undefined8 *)((uint)uVar5 & 0x3fffffff);
          if ((longlong)(uVar5 | 0x8000000000000000) >> 0x3e != 3) goto code_r0x0010d0c4;
        }
        SYNC(4);
        SYNC(4);
        *puVar7 = 0;
        uVar15 = (ulonglong)((int)uVar15 + 1);
        uRam00000340 = uVar12;
      } while (uVar4 != uVar15);
    }
    uRam00000340 = uVar12 | 0x100;
  }
  uVar1 = getCopReg(2,0x12);
  *(undefined4 *)(iVar2 + 0x16d) = uVar1;
  uVar4 = uRam00000350;
  if ((uRam00000350 >> 0x25 & 0x7f) != 0) {
    lVar16 = 0;
    uVar12 = uRam00000350;
    do {
      uVar4 = uVar12 >> 0x25 & 0x7f;
      if (uVar4 == 0) {
        trap(7);
      }
      uVar4 = uVar12 & 0xffffffffffffff00 | (longlong)((int)lVar16 % (int)uVar4) & 0x7fU;
      uVar15 = (uVar12 & 0x1fffffff00) >> 8;
      uVar6 = uVar15 * 0x80;
      if (uVar15 == 0) {
        uRam00000350 = uVar4;
        (*(code *)&cvmx_warn)(&UNK_0010e120);
        uVar6 = 0;
code_r0x0010d1a0:
        puVar7 = (undefined8 *)uVar6;
      }
      else {
        puVar7 = (undefined8 *)((uint)uVar6 & 0x3fffffff);
        if ((longlong)(uVar6 | 0x8000000000000000) >> 0x3e != 3) goto code_r0x0010d1a0;
      }
      SYNC(4);
      SYNC(4);
      lVar16 = (longlong)((int)lVar16 + 1);
      *puVar7 = 0;
      uVar15 = uVar12 & 0xfe000000000;
      uVar12 = uVar4;
    } while (lVar16 < (longlong)(uVar15 >> 0x25));
  }
  uRam00000350 = uVar4 | 0x80;
  uVar4 = uVar3 >> 0xe & 7;
  if (uVar4 != 0) {
    uVar12 = uRam00000348;
    if (uVar4 != 0) {
      uVar15 = 0;
      do {
        uVar12 = uRam00000348 >> 0x24 & 7;
        if (uVar12 == 0) {
          trap(7);
        }
        uVar12 = uRam00000348 & 0xfffffffffffffff0 |
                 (longlong)((int)(((uint)(uRam00000348 >> 0x21) & 7) + (int)uVar15) % (int)uVar12) &
                 7U;
        uVar6 = (uRam00000348 & 0x1fffffff0) >> 4;
        uVar5 = uVar6 * 0x80;
        if (uVar6 == 0) {
          uRam00000348 = uVar12;
          (*(code *)&cvmx_warn)(&UNK_0010e120);
          uVar5 = 0;
code_r0x0010d288:
          puVar7 = (undefined8 *)uVar5;
        }
        else {
          puVar7 = (undefined8 *)((uint)uVar5 & 0x3fffffff);
          if ((longlong)(uVar5 | 0x8000000000000000) >> 0x3e != 3) goto code_r0x0010d288;
        }
        SYNC(4);
        SYNC(4);
        *puVar7 = 0;
        uVar15 = (ulonglong)((int)uVar15 + 1);
        uRam00000348 = uVar12;
      } while (uVar4 != uVar15);
    }
    uRam00000348 = uVar12 | 8;
  }
  if ((uVar3 & 0x3f80) != 0) {
    uVar3 = uVar3 >> 7 & 0x7f;
    uVar4 = uRam00000340;
    if (uVar3 != 0) {
      uVar12 = 0;
      do {
        uVar4 = uRam00000340 >> 0x36 & 0x7f;
        if (uVar4 == 0) {
          trap(7);
        }
        uVar4 = uRam00000340 & 0xfffffffffffffe00 |
                (longlong)((int)(((uint)(uRam00000340 >> 0x26) & 0xff) + (int)uVar12) % (int)uVar4)
                & 0xffU;
        uVar15 = (uRam00000340 & 0x3ffffffe00) >> 9;
        uVar6 = uVar15 * 0x80;
        if (uVar15 == 0) {
          uRam00000340 = uVar4;
          (*(code *)&cvmx_warn)(&UNK_0010e120);
          uVar6 = 0;
code_r0x0010d674:
          puVar7 = (undefined8 *)uVar6;
        }
        else {
          puVar7 = (undefined8 *)((uint)uVar6 & 0x3fffffff);
          if ((longlong)(uVar6 | 0x8000000000000000) >> 0x3e != 3) goto code_r0x0010d674;
        }
        SYNC(4);
        SYNC(4);
        *puVar7 = 0;
        uVar12 = (ulonglong)((int)uVar12 + 1);
        uRam00000340 = uVar4;
      } while (uVar3 != uVar12);
    }
    uRam00000340 = uVar4 | 0x100;
  }
  uRam00000018 = uRam00000018 | 0x100;
  uRama0000030 = uRama0000030 | 1;
code_r0x0010d31c:
  cvm_oct_mem_empty_fpa(0,0x800,0x400);
  cvm_oct_mem_empty_fpa(1,0x80,0x400);
  cvm_oct_mem_empty_fpa(2,0x400,0x80);
  if (lRam00111248 != 0) {
    (*(code *)&unregister_sysctl_table)();
  }
  (*(code *)&printk)(&UNK_0010e1a8);
  if (lRam00111250 != 0) {
    (*(code *)&unregister_sysctl_table)();
  }
  (*(code *)&printk)(&UNK_0010e1d8);
  if (lRam00111258 != 0) {
    (*(code *)&unregister_sysctl_table)();
  }
  (*(code *)&printk)(&UNK_0010e1d8);
  hwOffloadSysctlUnregister();
  (*(code *)&remove_proc_entry)(&UNK_0010de10,0);
  (*(code *)&remove_proc_entry)(&UNK_0010de28,0);
  (*(code *)&remove_proc_entry)(&UNK_0010de30,0);
  (*(code *)&remove_proc_entry)(&UNK_0010de40,0);
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

