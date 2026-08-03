/*
 * Ghidra reconstructed C; not original Cisco source.
 * Analysis: rv220w-stock-modules-v1.0.0
 * Module: cavium-ethernet
 * Entry: 0010ba80
 * Function: init_module
 * Subsystem: module-lifecycle
 * Evidence: retained-or-recovered-symbol
 *
 * Embedded Ghidra annotation:
 * RV220W STOCK MODULE SEMANTIC ANNOTATION v1.0.0
 * Module: cavium-ethernet
 * Subsystem: Kernel module lifecycle
 * Evidence class: retained or recovered ELF/source symbol
 * Confidence: high for identity; medium for detailed semantics
 * Interpretation: Vendor Octeon Ethernet module entry point: discovers interfaces/ports, allocates resources, registers network devices and offload controls.
 * Callers: 
 * Callees: 
 * Referenced strings: none recovered
 * Safety note: decompiler output is reconstructed C, not original Cisco source. Register meanings remain hypotheses unless tied to constants, vendor strings, runtime behavior or upstream register definitions.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* RV220W STOCK MODULE SEMANTIC ANNOTATION v1.0.0
   Module: cavium-ethernet
   Subsystem: Kernel module lifecycle
   Evidence class: retained or recovered ELF/source symbol
   Confidence: high for identity; medium for detailed semantics
   Interpretation: Vendor Octeon Ethernet module entry point: discovers interfaces/ports, allocates
   resources, registers network devices and offload controls.
   Callers: 
   Callees: 
   Referenced strings: none recovered
   Safety note: decompiler output is reconstructed C, not original Cisco source. Register meanings
   remain hypotheses unless tied to constants, vendor strings, runtime behavior or upstream register
   definitions.
    */

undefined8 init_module(void)

{
  bool bVar1;
  int iVar2;
  int iVar9;
  longlong lVar3;
  undefined8 uVar4;
  longlong lVar5;
  longlong lVar6;
  longlong lVar7;
  longlong *plVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  ulonglong uVar8;
  ulonglong uVar14;
  ulonglong *puVar15;
  undefined8 extraout_a0;
  undefined8 uVar16;
  undefined8 in_t6;
  int *piVar17;
  longlong lVar18;
  int iVar19;
  int iVar20;
  
  iVar9 = (*(code *)&create_proc_entry)(&UNK_0010de10,0,0);
  if (iVar9 != 0) {
    *(undefined8 *)(iVar9 + 0x30) = 0x1101e8;
  }
  iVar9 = (*(code *)&create_proc_entry)(&UNK_0010de28,0,0);
  if (iVar9 != 0) {
    *(undefined8 *)(iVar9 + 0x30) = 0x1102c0;
  }
  iVar9 = (*(code *)&create_proc_entry)(&UNK_0010de30,0,0);
  if (iVar9 != 0) {
    *(undefined8 *)(iVar9 + 0x30) = 0x110398;
  }
  iVar9 = (*(code *)&create_proc_entry)(&UNK_0010de40,0,0);
  if (iVar9 != 0) {
    *(undefined8 *)(iVar9 + 0x30) = 0x110470;
  }
  iVar9 = (*(code *)&create_proc_entry)(&UNK_0010de50,0,0);
  if (iVar9 != 0) {
    *(undefined8 *)(iVar9 + 0x30) = 0x110548;
  }
  (*(code *)&printk)(&UNK_0010de58,&UNK_0010de70);
  cvm_oct_proc_initialize();
  hwOffloadSysctlRegister();
  ip_fastfwd_proc_tbl_init();
  cvm_oct_rx_initialize();
  setCopReg(2,in_t6,*(undefined4 *)((int)uRam28000050 + 9));
  (*(code *)&printk)(&UNK_0010dea8);
  uRam28000050 = 0x4000;
  (*(code *)&printk)(&UNK_0010dee0,0,0x800,0x400);
  cvm_oct_mem_fill_fpa(0,0x800,0x400);
  (*(code *)&printk)(&UNK_0010dee0,1,0x80,0x400);
  cvm_oct_mem_fill_fpa(1,0x80,0x400);
  (*(code *)&printk)(&UNK_0010dee0,3,0x80,0x2800);
  cvm_oct_mem_fill_fpa(3,0x80,0x2800);
  cvm_oct_mem_fill_fpa(2,0x400,0x80);
  (*(code *)&cvmx_helper_setup_red)(0x100,0x80);
  lVar3 = (*(code *)&octeon_is_simulation)();
  if (lVar3 == 0) {
    uRam00001820 = 1;
  }
  (*(code *)&request_irq)(pow_receive_group + 8,cvm_oct_do_interrupt,0x80,&UNK_0010def8);
  allocateCacheMemory();
  lRam00111248 = (*(code *)&register_sysctl_table)(0x110620);
  if (lRam00111248 != 0) {
    (*(code *)&printk)(&UNK_0010df08);
  }
  lRam00111250 = (*(code *)&register_sysctl_table)(0x1106c0);
  if (lRam00111250 != 0) {
    (*(code *)&printk)(&UNK_0010df38);
  }
  lRam00111258 = (*(code *)&register_sysctl_table)(0x110760);
  if (lRam00111258 != 0) {
    (*(code *)&printk)(&UNK_0010df68);
  }
  (*(code *)&cvmx_helper_initialize_packet_io_global)();
  lVar3 = (*(code *)&cvmx_helper_get_number_of_interfaces)();
  if (0 < lVar3) {
    lVar18 = 0;
    do {
      uVar4 = (*(code *)&cvmx_helper_ports_on_interface)(lVar18);
      lVar5 = (*(code *)&cvmx_helper_get_ipd_port)(lVar18,0);
      lVar7 = lVar5;
      while( true ) {
        lVar6 = (*(code *)&cvmx_helper_get_ipd_port)(lVar18,uVar4);
        special2(lVar7,extraout_a0,3,0x32);
        if (lVar6 <= lVar5) break;
        lVar5 = (longlong)((int)lVar5 + 1);
        puVar15 = (ulonglong *)((int)extraout_a0 + -0x5ffffc00);
        lVar7 = lVar7 + 1;
        *puVar15 = *puVar15 & 0xfffffffffffffff0 | (longlong)pow_receive_group & 0xfU;
      }
      lVar18 = (longlong)((int)lVar18 + 1);
    } while (lVar18 != lVar3);
  }
  (*(code *)&cvmx_helper_ipd_and_packet_input_enable)();
  (*(code *)&memset)(cvm_oct_device,0,0x148);
  (*(code *)&printk)(&UNK_0010dfa8,999);
  uRam000027fc = 0;
  (*(code *)&printk)(&UNK_0010dfa8,0x3ea);
  if (pow_send_group != -1) {
    (*(code *)&printk)(&UNK_0010dfb0);
    lVar18 = (*(code *)&alloc_etherdev)(0x290);
    if (lVar18 == 0) {
      (*(code *)&printk)(&UNK_0010e048);
    }
    else {
      (*(code *)&memset)(lVar18 + 0x560,0,0x290);
      iVar9 = (int)lVar18;
      *(ulonglong *)(iVar9 + 0x50) = ZEXT48(cvm_oct_common_init);
      *(undefined4 *)(iVar9 + 0x56c) = 0;
      *(undefined8 *)(iVar9 + 0x560) = 0x28ffffffff;
      (*(code *)&strcpy)(lVar18,&UNK_0010dfe0);
      lVar5 = 0;
      lVar7 = lVar18 + 0x570;
      do {
        plVar10 = (longlong *)lVar7;
        *plVar10 = lVar7;
        lVar5 = lVar5 + 1;
        plVar10[1] = lVar7;
        *(undefined4 *)(plVar10 + 2) = 0;
        lVar7 = lVar7 + 0x18;
      } while (lVar5 != 0x10);
      lVar7 = (*(code *)&register_netdev)(lVar18);
      if (lVar7 < 0) {
        (*(code *)&printk)(&UNK_0010dfe8);
        (*(code *)&kfree)(lVar18);
      }
      else {
        cvm_oct_device._320_8_ = lVar18;
        (*(code *)&printk)(&UNK_0010e018,lVar18,pow_send_group,pow_receive_group);
      }
    }
  }
  (*(code *)&printk)(&UNK_0010dfa8,0x410);
  iVar9 = (*(code *)&cvmx_helper_get_number_of_interfaces)();
  (*(code *)&printk)(&UNK_0010dfa8,0x412);
  iVar19 = 0;
  if (0 < iVar9) {
    iVar20 = 0x7fc;
    do {
      uVar4 = (*(code *)&cvmx_helper_interface_get_mode)(iVar19);
      special2(uVar4,lVar3,0,0x3a);
      uVar4 = (*(code *)&cvmx_helper_ports_on_interface)(iVar19);
      iVar11 = (*(code *)&cvmx_helper_get_ipd_port)(iVar19,0);
      iVar12 = (*(code *)&cvmx_helper_get_ipd_port)(iVar19,uVar4);
      if (iVar11 < iVar12) {
        do {
          lVar18 = (*(code *)&alloc_etherdev)(0x290);
          if (lVar18 == 0) {
            (*(code *)&printk)(&UNK_0010e078,iVar11);
          }
          else {
            (*(code *)&printk)(&UNK_0010e0b0,iVar11);
            (*(code *)&memset)(lVar18 + 0x560,0,0x290);
            iVar2 = (int)lVar18;
            *(int *)(iVar2 + 0x560) = iVar11;
            iVar12 = *(int *)(iVar2 + 0x560);
            *(int *)(iVar2 + 0x56c) = (int)lVar3;
            if ((((0xf < iVar12) && (0xf < iVar12 - 0x10U)) && (3 < iVar12 - 0x20U)) &&
               (3 < iVar12 - 0x24U)) {
              iVar12 = 0xffff;
            }
            *(int *)(iVar2 + 0x564) = iVar12;
            bVar1 = iVar11 < 0x10;
            *(undefined8 *)(iVar2 + 0x7d8) = 0;
            if (bVar1) {
LAB_0010cb1c:
              iVar12 = 4;
            }
            else {
              iVar12 = 4;
              if (0x1f < iVar11) {
                if (iVar11 < 0x24) goto LAB_0010cb1c;
                iVar12 = (uint)(iVar11 < 0x28) << 2;
              }
            }
            lVar5 = 0;
            *(int *)(iVar2 + 0x568) = iVar20 - iVar12;
            lVar7 = lVar18 + 0x570;
            do {
              plVar10 = (longlong *)lVar7;
              *plVar10 = lVar7;
              lVar5 = lVar5 + 1;
              plVar10[1] = lVar7;
              *(undefined4 *)(plVar10 + 2) = 0;
              lVar7 = lVar7 + 0x18;
            } while (lVar5 != 0x10);
            iVar12 = 0;
            if (bVar1) goto LAB_0010c630;
            while( true ) {
              if (iVar11 < 0x20) goto LAB_0010c630;
              if (iVar11 < 0x24) goto LAB_0010c630;
              if ((int)(uint)(iVar11 < 0x28) <= iVar12) break;
              while( true ) {
                iVar13 = iVar12 * 4;
                iVar12 = iVar12 + 1;
                *(undefined4 *)(iVar13 + *(int *)(iVar2 + 0x568) & 0x7ffU | 0x2000) = 0;
                if (!bVar1) break;
LAB_0010c630:
                if (0 < iVar12) goto LAB_0010c638;
              }
            }
LAB_0010c638:
            uVar14 = (ulonglong)*(int *)(iVar2 + 0x56c);
            uVar8 = (ulonglong)(uVar14 < 10);
            special2(uVar14,uVar8,3,0x32);
            if (uVar8 != 0) {
              uVar4 = (*(code *)*(undefined8 *)(&DAT_0010d8c0 + (uVar14 < 10)))();
              return uVar4;
            }
            if (*(longlong *)(iVar2 + 0x50) == 0) {
              (*(code *)&kfree)(lVar18);
            }
            else {
              lVar7 = (*(code *)&register_netdev)(lVar18);
              piVar17 = (int *)(lVar18 + 0x560);
              if (lVar7 < 0) {
                (*(code *)&printk)(&UNK_0010e0e0,iVar19,*piVar17);
                (*(code *)&kfree)(lVar18);
              }
              else {
                *(longlong *)(cvm_oct_device + *piVar17 * 8) = lVar18;
                iVar12 = *piVar17;
                if (((iVar12 < 0x10) || (iVar12 < 0x20)) || (iVar12 < 0x24)) {
                  iVar20 = iVar20 + -4;
                }
                else {
                  iVar20 = iVar20 + (uint)(iVar12 < 0x28) * -4;
                }
              }
            }
          }
          iVar11 = iVar11 + 1;
          iVar12 = (*(code *)&cvmx_helper_get_ipd_port)(iVar19,uVar4);
        } while (iVar11 < iVar12);
      }
      iVar19 = iVar19 + 1;
    } while (iVar19 != iVar9);
  }
  lVar18 = (longlong)pow_receive_group;
  uVar4 = special2(lVar18,lVar18,3,0x32);
  lVar3 = (longlong)(int)(*(uint *)((int)_octeon_bootinfo + 0x44) / 0x2710000);
  uVar16 = special2(lVar3,lVar3,8,0x32);
  *(longlong *)((uint)uVar4 | 0x208) = lVar3;
  *(undefined8 *)(lVar18 + -0x7ffe98ffffffff80) = 0x1f000000;
  (*(code *)&init_timer)(0x1111f8,lVar18 + -0x7ffe98ffffffff80,uVar16);
  uRam00111210 = ZEXT48(local_cavium_ethernet_text_001038);
  uRam00111218 = 0;
  (*(code *)&mod_timer)(0x1111f8,_jiffies + 0xfa);
  return 0;
}

