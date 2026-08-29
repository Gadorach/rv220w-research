// SPDX-License-Identifier: GPL-2.0-only
/*
 * RV220W/CN50xx legacy PCI interrupt provenance.
 *
 * This module is intentionally read-only.  It samples the same CIU summary
 * and enable CSRs consumed by Linux's Octeon interrupt controller and exposes
 * only the legacy PCI INT0..INT3 fields (CIU bits 36..39) plus full raw values.
 * It never acknowledges, masks, unmasks, reroutes or otherwise writes an IRQ.
 */
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/kobject.h>
#include <linux/sysfs.h>

#include <asm/octeon/octeon.h>
#include <asm/octeon/cvmx-ciu-defs.h>
#include <asm/octeon/octeon-model.h>

static struct kobject *rv220w_irq_kobj;

static ssize_t snapshot_show(struct kobject *kobj,
                             struct kobj_attribute *attr, char *buf)
{
    unsigned int core = cvmx_get_core_num();
    unsigned int ciu_index = core * 2;
    u64 sum0 = cvmx_read_csr(CVMX_CIU_INTX_SUM0(ciu_index));
    u64 en0 = cvmx_read_csr(CVMX_CIU_INTX_EN0(ciu_index));
    unsigned int pci_pending = (unsigned int)((sum0 >> 36) & 0xf);
    unsigned int pci_enabled = (unsigned int)((en0 >> 36) & 0xf);

    return sysfs_emit(buf,
        "core=%u ciu_index=%u sum0=0x%016llx en0=0x%016llx "
        "pci_int_pending=0x%x pci_int_enabled=0x%x\n",
        core, ciu_index,
        (unsigned long long)sum0, (unsigned long long)en0,
        pci_pending, pci_enabled);
}

static struct kobj_attribute snapshot_attr = __ATTR_RO(snapshot);

static int __init rv220w_octeon_pci_irq_diag_init(void)
{
    int rc;

    if (!OCTEON_IS_MODEL(OCTEON_CN50XX))
        return -ENODEV;

    rv220w_irq_kobj = kobject_create_and_add("rv220w_octeon_pci_irq_diag",
                                             kernel_kobj);
    if (!rv220w_irq_kobj)
        return -ENOMEM;

    rc = sysfs_create_file(rv220w_irq_kobj, &snapshot_attr.attr);
    if (rc) {
        kobject_put(rv220w_irq_kobj);
        rv220w_irq_kobj = NULL;
        return rc;
    }

    pr_info("rv220w_octeon_pci_irq_diag: read-only CN50xx CIU PCI INTx telemetry enabled\n");
    return 0;
}

static void __exit rv220w_octeon_pci_irq_diag_exit(void)
{
    if (rv220w_irq_kobj) {
        sysfs_remove_file(rv220w_irq_kobj, &snapshot_attr.attr);
        kobject_put(rv220w_irq_kobj);
    }
}

module_init(rv220w_octeon_pci_irq_diag_init);
module_exit(rv220w_octeon_pci_irq_diag_exit);

MODULE_DESCRIPTION("Read-only Octeon CN50xx PCI INTx/CIU diagnostics");
MODULE_AUTHOR("RV220W OpenWrt research project");
MODULE_LICENSE("GPL");
