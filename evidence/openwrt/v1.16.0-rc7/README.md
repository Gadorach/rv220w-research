# RC7 direct-install qualification

`liveboot-install-transcript.txt` is the recovered UART transcript spanning the late installer qualification attempts. It records:

- low-memory sysupgrade validation;
- the RC6 `IPKG_INSTROOT` failure before any write;
- the corrected RC7 direct installer;
- rootfs stream/write/readback PASS;
- kernel stream/write/readback PASS;
- final installer PASS and reboot;
- stock U-Boot startup followed by persistent Linux 6.12.94 boot.

The release source lock is retained at `../../../openwrt/source-lock.json`. The flash-ready RC7 images and their authoritative distribution hashes are retained under `../../../prebuilt/`.
