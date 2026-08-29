// SPDX-License-Identifier: GPL-2.0-only
/*
 * Broadcom SSB PCI NVM diagnostics, paired SPROM reads, and explicit OTP shadow initialization.
 *
 * Passive operation remains non-binding and read-only: the module scans
 * already-enumerated PCI devices, maps only the fixed ChipCommon page on
 * compatible SSB devices, validates the core, and exposes OTP/SPROM-selection
 * evidence through sysfs.  No PCI driver is registered and SSB/b43 remain the
 * owner of the function.
 *
 * A read-only paired-SPROM attribute additionally reproduces the stock
 * Broadcom wl access sequence: two consecutive ioread16() transactions at
 * every two-byte SPROM address, preserving both results.  No 32-bit SPROM
 * access or synthetic/interleaved reconstruction is performed in-kernel.
 *
 * A separate write-only sysfs control accepts exactly "init-shadow".  That
 * command is deliberately restricted to BCM4322 devices whose ChipCommon
 * chipstatus says OTP (not SPROM) is the selected stock configuration source.
 * It issues only Broadcom's IPX OTP INIT opcode, with OTPC_PROGEN required to
 * be clear, and never issues BIT_PROG/SET/RESET/ROW_LOCK or writes OTP control,
 * SPROM, PCI config space, radio state, or flash.  Broadcom's own OTP reader
 * uses this INIT opcode to refresh OTP status/shadow state before a read.
 */
#include <linux/delay.h>
#include <linux/device.h>
#include <linux/io.h>
#include <linux/list.h>
#include <linux/module.h>
#include <linux/mutex.h>
#include <linux/pci.h>
#include <linux/slab.h>
#include <linux/ssb/ssb.h>
#include <linux/ssb/ssb_driver_chipcommon.h>
#include <linux/ssb/ssb_regs.h>
#include <linux/string.h>

#define SSB_NVMEM_BAR0_MIN_SIZE          (16 * 1024)
#define SSB_NVMEM_CC_FIXED_OFFSET        (12 * 1024)
#define SSB_NVMEM_CC_PAGE_SIZE           (4 * 1024)
#define SSB_NVMEM_CC_SROMOTP             0x0800
#define SSB_NVMEM_SPROM_WORDS_R4          220
#define SSB_NVMEM_BCM4312_CHIP             0x4312


/* Broadcom IPX OTP status bits. */
#define SSB_NVMEM_OTPS_GUP_HW            0x00000100
#define SSB_NVMEM_OTPS_GUP_SW            0x00000200
#define SSB_NVMEM_OTPS_GUP_CI            0x00000400
#define SSB_NVMEM_OTPS_GUP_FUSE          0x00000800
#define SSB_NVMEM_OTPS_READY             0x00001000
#define SSB_NVMEM_SPROM_OTPIN_USE        0x00000080
#define SSB_NVMEM_OTPGU_SROM_OFF         4
#define SSB_NVMEM_OTPGU_HSB_OFF          0

/* Broadcom rev>=21 OTP control/program fields absent from modern SSB ABI. */
#define SSB_NVMEM_OTPC_PROGEN             0x80000000
#define SSB_NVMEM_OTPP_OC_SHIFT           24
#define SSB_NVMEM_OTPP_OC_MASK            0x0f000000
#define SSB_NVMEM_OTPP_READERR            0x10000000
#define SSB_NVMEM_OTPP_START_BUSY         0x80000000
#define SSB_NVMEM_OTPPOC_INIT             4
#define SSB_NVMEM_OTPP_INIT_CMD \
        (SSB_NVMEM_OTPP_START_BUSY | \
         ((SSB_NVMEM_OTPPOC_INIT << SSB_NVMEM_OTPP_OC_SHIFT) & \
          SSB_NVMEM_OTPP_OC_MASK))
#define SSB_NVMEM_INIT_TIMEOUT_US          10000

/* BCM4322 ChipCommon chipstatus source selector. */
#define SSB_NVMEM_BCM4322_CHIP             0x4322
#define SSB_NVMEM_BCM4322_SEL_MASK         0x000000c0
#define SSB_NVMEM_BCM4322_SEL_SHIFT        6
#define SSB_NVMEM_BCM4322_NO_SPROM_OTP     0
#define SSB_NVMEM_BCM4322_SPROM_PRESENT    1
#define SSB_NVMEM_BCM4322_OTP_PRESENT      2

struct ssb_nvmem_diag {
        void __iomem *cc;
        u32 idhigh;
        u32 chipid;
        u32 capabilities;
        u32 chipstatus;
        u32 otpstatus;
        u32 otpcontrol;
        u32 otpprog;
        u32 spromctl;
        u16 ccrev;
        u16 otp_words;
        u16 otpgu_base;
        u16 hwbase;
        u16 hwlim;
};

struct ssb_nvmem_attachment {
        struct list_head list;
        struct pci_dev *pdev;
        bool status_fresh;
};

static LIST_HEAD(ssb_nvmem_attachments);
static DEFINE_MUTEX(ssb_nvmem_attachments_lock);

static void ssb_nvmem_diag_close(struct pci_dev *pdev,
                                 struct ssb_nvmem_diag *diag)
{
        if (diag->cc)
                pci_iounmap(pdev, diag->cc);
        diag->cc = NULL;
}

static int ssb_nvmem_diag_open(struct pci_dev *pdev,
                               struct ssb_nvmem_diag *diag)
{
        u32 geometry;
        u16 coreid, vendor, hsb;
        int err;

        memset(diag, 0, sizeof(*diag));
        if (!(pci_resource_flags(pdev, 0) & IORESOURCE_MEM) ||
            pci_resource_len(pdev, 0) < SSB_NVMEM_BAR0_MIN_SIZE)
                return -EOPNOTSUPP;

        diag->cc = pci_iomap_range(pdev, 0, SSB_NVMEM_CC_FIXED_OFFSET,
                                   SSB_NVMEM_CC_PAGE_SIZE);
        if (!diag->cc)
                return -ENOMEM;

        diag->idhigh = ioread32(diag->cc + SSB_IDHIGH);
        coreid = (diag->idhigh & SSB_IDHIGH_CC) >> SSB_IDHIGH_CC_SHIFT;
        vendor = (diag->idhigh & SSB_IDHIGH_VC) >> SSB_IDHIGH_VC_SHIFT;
        if (coreid != SSB_DEV_CHIPCOMMON || vendor != SSB_VENDOR_BROADCOM) {
                err = -EOPNOTSUPP;
                goto out_err;
        }

        diag->ccrev = diag->idhigh & SSB_IDHIGH_RCLO;
        diag->ccrev |= (diag->idhigh & SSB_IDHIGH_RCHI) >>
                       SSB_IDHIGH_RCHI_SHIFT;
        diag->chipid = ioread32(diag->cc + SSB_CHIPCO_CHIPID);
        diag->capabilities = ioread32(diag->cc + SSB_CHIPCO_CAP);
        diag->chipstatus = ioread32(diag->cc + SSB_CHIPCO_CHIPSTAT);
        diag->otpstatus = ioread32(diag->cc + SSB_CHIPCO_OTPS);
        diag->otpcontrol = ioread32(diag->cc + SSB_CHIPCO_OTPC);
        diag->otpprog = ioread32(diag->cc + SSB_CHIPCO_OTPP);
        err = pci_read_config_dword(pdev, SSB_SPROMCTL, &diag->spromctl);
        if (err) {
                err = -EIO;
                goto out_err;
        }

        geometry = (diag->capabilities & SSB_CHIPCO_CAP_OTPS) >>
                   SSB_CHIPCO_CAP_OTPS_SHIFT;
        switch (geometry) {
        case 1:
                diag->otp_words = 128;
                break;
        case 2:
                diag->otp_words = 256;
                break;
        case 5:
                diag->otp_words = 384;
                break;
        case 7:
                diag->otp_words = 64;
                break;
        default:
                err = -ENODATA;
                goto out_err;
        }

        /* Broadcom IPX OTP General-Use Region geometry. */
        if (diag->ccrev == 21 || diag->ccrev == 24 || diag->ccrev == 27)
                diag->otpgu_base = 12;
        else if (diag->ccrev == 36)
                diag->otpgu_base = diag->otp_words >= 128 ? 20 : 12;
        else if (diag->ccrev == 23 || diag->ccrev >= 25)
                diag->otpgu_base = 20;
        else {
                err = -EOPNOTSUPP;
                goto out_err;
        }

        diag->hwbase = diag->otpgu_base + SSB_NVMEM_OTPGU_SROM_OFF;
        diag->hwlim = diag->otp_words;
        if (diag->otpstatus & SSB_NVMEM_OTPS_GUP_HW) {
                hsb = ioread16(diag->cc + SSB_NVMEM_CC_SROMOTP +
                               ((diag->otpgu_base + SSB_NVMEM_OTPGU_HSB_OFF) * 2));
                if (!(hsb & 0xf)) {
                        hsb /= 16;
                        if (hsb > diag->hwbase && hsb <= diag->otp_words)
                                diag->hwlim = hsb;
                }
        }

        return 0;

out_err:
        ssb_nvmem_diag_close(pdev, diag);
        return err;
}

static struct ssb_nvmem_attachment *
ssb_nvmem_find_attachment_locked(struct pci_dev *pdev)
{
        struct ssb_nvmem_attachment *attachment;

        list_for_each_entry(attachment, &ssb_nvmem_attachments, list) {
                if (attachment->pdev == pdev)
                        return attachment;
        }
        return NULL;
}

static bool ssb_nvmem_status_fresh(struct pci_dev *pdev)
{
        struct ssb_nvmem_attachment *attachment;
        bool fresh = false;

        mutex_lock(&ssb_nvmem_attachments_lock);
        attachment = ssb_nvmem_find_attachment_locked(pdev);
        if (attachment)
                fresh = attachment->status_fresh;
        mutex_unlock(&ssb_nvmem_attachments_lock);
        return fresh;
}

static void ssb_nvmem_mark_status_fresh(struct pci_dev *pdev)
{
        struct ssb_nvmem_attachment *attachment;

        mutex_lock(&ssb_nvmem_attachments_lock);
        attachment = ssb_nvmem_find_attachment_locked(pdev);
        if (attachment)
                attachment->status_fresh = true;
        mutex_unlock(&ssb_nvmem_attachments_lock);
}

static const char *ssb_nvmem_bcm4322_source_name(u32 selector)
{
        switch (selector) {
        case SSB_NVMEM_BCM4322_NO_SPROM_OTP:
                return "none";
        case SSB_NVMEM_BCM4322_SPROM_PRESENT:
                return "sprom";
        case SSB_NVMEM_BCM4322_OTP_PRESENT:
                return "otp";
        default:
                return "reserved";
        }
}

static u16 ssb_nvmem_sprom_offset(const struct ssb_nvmem_diag *diag)
{
        u16 chip = diag->chipid & SSB_CHIPCO_IDMASK;

        /* Match Linux SSB's SPROM offset selection rules. */
        if (diag->ccrev >= 31)
                return SSB_SPROM_BASE31;
        if (chip == SSB_NVMEM_BCM4312_CHIP &&
            (diag->chipstatus & 0x03) == 2)
                return SSB_SPROM_BASE31;
        return SSB_SPROM_BASE1;
}

static ssize_t ssb_sprom_paired16_show(struct device *dev,
                                       struct device_attribute *attr,
                                       char *buf)
{
        struct pci_dev *pdev = to_pci_dev(dev);
        struct ssb_nvmem_diag diag;
        void __iomem *sprom;
        u16 first[SSB_NVMEM_SPROM_WORDS_R4];
        u16 second[SSB_NVMEM_SPROM_WORDS_R4];
        u16 offset, i;
        unsigned int mismatches = 0;
        ssize_t len = 0;
        int err;

        err = ssb_nvmem_diag_open(pdev, &diag);
        if (err)
                return err;
        offset = ssb_nvmem_sprom_offset(&diag);
        ssb_nvmem_diag_close(pdev, &diag);

        if (pci_resource_len(pdev, 0) < offset + sizeof(first))
                return -EOPNOTSUPP;
        sprom = pci_iomap_range(pdev, 0, offset, sizeof(first));
        if (!sprom)
                return -ENOMEM;

        /*
         * Reproduce the stock Broadcom wl helper exactly at the bus-access
         * level: every 16-bit SPROM address is read twice back-to-back and
         * the second transaction is the value stock wl ultimately retains.
         * Preserve both transactions here for evidence instead of discarding
         * the first.  The SPROM ABI is two-byte only; do not use ioread32().
         */
        for (i = 0; i < SSB_NVMEM_SPROM_WORDS_R4; i++) {
                first[i] = ioread16(sprom + (i * sizeof(u16)));
                second[i] = ioread16(sprom + (i * sizeof(u16)));
                if (first[i] != second[i])
                        mismatches++;
        }
        pci_iounmap(pdev, sprom);

        len += sysfs_emit_at(buf, len,
                             "offset=0x%04x words=%u mismatch_words=%u\nfirst=",
                             offset, SSB_NVMEM_SPROM_WORDS_R4, mismatches);
        for (i = 0; i < SSB_NVMEM_SPROM_WORDS_R4; i++)
                len += sysfs_emit_at(buf, len, "%04X", first[i]);
        len += sysfs_emit_at(buf, len, "\nsecond=");
        for (i = 0; i < SSB_NVMEM_SPROM_WORDS_R4; i++)
                len += sysfs_emit_at(buf, len, "%04X", second[i]);
        len += sysfs_emit_at(buf, len, "\n");
        return len;
}

static ssize_t ssb_otp_info_show(struct device *dev,
                                 struct device_attribute *attr, char *buf)
{
        struct pci_dev *pdev = to_pci_dev(dev);
        struct ssb_nvmem_diag diag;
        unsigned int selector = 0;
        const char *source = "n/a";
        bool fresh;
        ssize_t len;
        int err;

        err = ssb_nvmem_diag_open(pdev, &diag);
        if (err)
                return err;

        if ((diag.chipid & SSB_CHIPCO_IDMASK) == SSB_NVMEM_BCM4322_CHIP) {
                selector = (diag.chipstatus & SSB_NVMEM_BCM4322_SEL_MASK) >>
                           SSB_NVMEM_BCM4322_SEL_SHIFT;
                source = ssb_nvmem_bcm4322_source_name(selector);
        }
        fresh = ssb_nvmem_status_fresh(pdev);

        len = sysfs_emit(buf,
                "chip=0x%04x chiprev=%u package=%u ccrev=%u "
                "capabilities=0x%08x chipstatus=0x%08x "
                "otpstatus=0x%08x otpcontrol=0x%08x otpprog=0x%08x "
                "spromctl=0x%08x otp_words=%u otpgu_base=%u "
                "hwbase=%u hwlim=%u hw_programmed=%u sw_programmed=%u "
                "ci_programmed=%u fuse_programmed=%u ready=%u "
                "otp_in_use=%u status_fresh=%u "
                "bcm4322_sprom_otp_sel=%u bcm4322_stock_source=%s\n",
                diag.chipid & SSB_CHIPCO_IDMASK,
                (diag.chipid & SSB_CHIPCO_REVMASK) >> SSB_CHIPCO_REVSHIFT,
                (diag.chipid & SSB_CHIPCO_PACKMASK) >> SSB_CHIPCO_PACKSHIFT,
                diag.ccrev, diag.capabilities, diag.chipstatus,
                diag.otpstatus, diag.otpcontrol, diag.otpprog, diag.spromctl,
                diag.otp_words, diag.otpgu_base, diag.hwbase, diag.hwlim,
                !!(diag.otpstatus & SSB_NVMEM_OTPS_GUP_HW),
                !!(diag.otpstatus & SSB_NVMEM_OTPS_GUP_SW),
                !!(diag.otpstatus & SSB_NVMEM_OTPS_GUP_CI),
                !!(diag.otpstatus & SSB_NVMEM_OTPS_GUP_FUSE),
                !!(diag.otpstatus & SSB_NVMEM_OTPS_READY),
                !!(diag.spromctl & SSB_NVMEM_SPROM_OTPIN_USE),
                fresh, selector, source);
        ssb_nvmem_diag_close(pdev, &diag);
        return len;
}

static ssize_t ssb_otp_raw_show(struct device *dev,
                                struct device_attribute *attr, char *buf)
{
        struct pci_dev *pdev = to_pci_dev(dev);
        struct ssb_nvmem_diag diag;
        ssize_t len = 0;
        u16 i, word;
        int err;

        err = ssb_nvmem_diag_open(pdev, &diag);
        if (err)
                return err;

        for (i = 0; i < diag.otp_words; i++) {
                word = ioread16(diag.cc + SSB_NVMEM_CC_SROMOTP + (i * 2));
                len += sysfs_emit_at(buf, len, "%04X", word);
        }
        len += sysfs_emit_at(buf, len, "\n");
        ssb_nvmem_diag_close(pdev, &diag);
        return len;
}

static ssize_t ssb_otp_control_store(struct device *dev,
                                     struct device_attribute *attr,
                                     const char *buf, size_t count)
{
        struct pci_dev *pdev = to_pci_dev(dev);
        struct ssb_nvmem_diag diag;
        unsigned int selector;
        u32 st;
        unsigned int waited;
        int err;

        if (!sysfs_streq(buf, "init-shadow"))
                return -EINVAL;

        err = ssb_nvmem_diag_open(pdev, &diag);
        if (err)
                return err;

        /*
         * This active diagnostic is intentionally narrower than passive
         * capture.  The stock BCM4322 wl path selects OTP only when
         * chipstatus[7:6] == 2; any SPROM-selected or reserved state refuses.
         */
        if ((diag.chipid & SSB_CHIPCO_IDMASK) != SSB_NVMEM_BCM4322_CHIP) {
                err = -EOPNOTSUPP;
                goto out;
        }
        selector = (diag.chipstatus & SSB_NVMEM_BCM4322_SEL_MASK) >>
                   SSB_NVMEM_BCM4322_SEL_SHIFT;
        if (selector != SSB_NVMEM_BCM4322_OTP_PRESENT) {
                err = -EPERM;
                goto out;
        }

        /*
         * Broadcom otp_read_region() powers OTP before ipxotp_init().  This
         * standalone diagnostic deliberately does not manipulate PMU power,
         * so INIT is allowed only when the controller already reports READY.
         */
        if (!(diag.otpstatus & SSB_NVMEM_OTPS_READY)) {
                err = -EAGAIN;
                goto out;
        }

        /* Never operate while OTP programming-enable is asserted. */
        if (diag.otpcontrol & SSB_NVMEM_OTPC_PROGEN) {
                err = -EPERM;
                goto out;
        }
        if (diag.otpprog & SSB_NVMEM_OTPP_START_BUSY) {
                err = -EBUSY;
                goto out;
        }

        /*
         * Broadcom _ipxotp_init() issues this exact INIT opcode before
         * reading OTP status/shadow.  INIT is distinct from all programming,
         * SET, RESET, and row-lock opcodes.  We do not touch otpcontrol.
         */
        iowrite32(SSB_NVMEM_OTPP_INIT_CMD, diag.cc + SSB_CHIPCO_OTPP);
        for (waited = 0; waited < SSB_NVMEM_INIT_TIMEOUT_US; waited++) {
                st = ioread32(diag.cc + SSB_CHIPCO_OTPP);
                if (!(st & SSB_NVMEM_OTPP_START_BUSY))
                        break;
                udelay(1);
        }
        if (waited == SSB_NVMEM_INIT_TIMEOUT_US) {
                err = -ETIMEDOUT;
                goto out;
        }
        if (st & SSB_NVMEM_OTPP_READERR) {
                err = -EIO;
                goto out;
        }

        /* Force the status read now, matching the stock initialization order. */
        (void)ioread32(diag.cc + SSB_CHIPCO_OTPS);
        ssb_nvmem_mark_status_fresh(pdev);
        dev_info(dev,
                 "BCM4322 OTP shadow/status INIT completed (no programming opcode issued)\n");
        err = 0;

out:
        ssb_nvmem_diag_close(pdev, &diag);
        return err ? err : count;
}

static DEVICE_ATTR_RO(ssb_sprom_paired16);
static DEVICE_ATTR_RO(ssb_otp_info);
static DEVICE_ATTR_RO(ssb_otp_raw);
static DEVICE_ATTR_WO(ssb_otp_control);

static bool ssb_nvmem_diag_candidate(struct pci_dev *pdev)
{
        struct ssb_nvmem_diag diag;
        int err;

        err = ssb_nvmem_diag_open(pdev, &diag);
        if (err)
                return false;
        ssb_nvmem_diag_close(pdev, &diag);
        return true;
}

static int ssb_nvmem_attach(struct pci_dev *pdev)
{
        struct ssb_nvmem_attachment *attachment;
        int err;

        attachment = kzalloc(sizeof(*attachment), GFP_KERNEL);
        if (!attachment)
                return -ENOMEM;
        attachment->pdev = pci_dev_get(pdev);
        if (!attachment->pdev) {
                kfree(attachment);
                return -ENODEV;
        }

        err = device_create_file(&pdev->dev, &dev_attr_ssb_sprom_paired16);
        if (err)
                goto err_put;
        err = device_create_file(&pdev->dev, &dev_attr_ssb_otp_info);
        if (err)
                goto err_paired;
        err = device_create_file(&pdev->dev, &dev_attr_ssb_otp_raw);
        if (err)
                goto err_info;
        err = device_create_file(&pdev->dev, &dev_attr_ssb_otp_control);
        if (err)
                goto err_raw;

        mutex_lock(&ssb_nvmem_attachments_lock);
        list_add_tail(&attachment->list, &ssb_nvmem_attachments);
        mutex_unlock(&ssb_nvmem_attachments_lock);
        return 0;

err_raw:
        device_remove_file(&pdev->dev, &dev_attr_ssb_otp_raw);
err_info:
        device_remove_file(&pdev->dev, &dev_attr_ssb_otp_info);
err_paired:
        device_remove_file(&pdev->dev, &dev_attr_ssb_sprom_paired16);
err_put:
        pci_dev_put(attachment->pdev);
        kfree(attachment);
        return err;
}

static int __init ssb_nvmem_diag_init(void)
{
        struct pci_dev *pdev = NULL;
        unsigned int attached = 0;
        int err;

        for_each_pci_dev(pdev) {
                if (!ssb_nvmem_diag_candidate(pdev))
                        continue;

                err = ssb_nvmem_attach(pdev);
                if (err)
                        continue;
                attached++;
                dev_info(&pdev->dev,
                         "SSB NVM diagnostics enabled; paired 16-bit SPROM reads are read-only and BCM4322 OTP INIT is explicit/strap-gated\n");
        }

        if (!attached)
                pr_info("ssb_nvmem_diag: no compatible PCI SSB ChipCommon window found\n");
        return 0;
}

static void __exit ssb_nvmem_diag_exit(void)
{
        struct ssb_nvmem_attachment *attachment, *tmp;
        LIST_HEAD(detached);

        /* Do not hold the state mutex while sysfs drains active callbacks. */
        mutex_lock(&ssb_nvmem_attachments_lock);
        list_splice_init(&ssb_nvmem_attachments, &detached);
        mutex_unlock(&ssb_nvmem_attachments_lock);

        list_for_each_entry_safe(attachment, tmp, &detached, list) {
                list_del(&attachment->list);
                device_remove_file(&attachment->pdev->dev,
                                   &dev_attr_ssb_otp_control);
                device_remove_file(&attachment->pdev->dev,
                                   &dev_attr_ssb_otp_raw);
                device_remove_file(&attachment->pdev->dev,
                                   &dev_attr_ssb_otp_info);
                device_remove_file(&attachment->pdev->dev,
                                   &dev_attr_ssb_sprom_paired16);
                pci_dev_put(attachment->pdev);
                kfree(attachment);
        }
}

module_init(ssb_nvmem_diag_init);
module_exit(ssb_nvmem_diag_exit);

MODULE_DESCRIPTION("Broadcom SSB PCI NVM diagnostics with paired SPROM reads and explicit BCM4322 OTP INIT");
MODULE_AUTHOR("OpenWrt SSB NVM diagnostics");
MODULE_LICENSE("GPL");
