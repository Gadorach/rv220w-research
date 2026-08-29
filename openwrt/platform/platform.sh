#
# Copyright (C) 2021 OpenWrt.org
#

if [ -x /usr/sbin/blkid ]; then
  RAMFS_COPY_BIN="/usr/sbin/blkid"
fi

# The RV220W sysupgrade path writes the parallel-NOR kernel and rootfs
# partitions from the stage2 RAM filesystem. Keep mtd available after pivot.
RAMFS_COPY_BIN="$RAMFS_COPY_BIN /sbin/mtd"
if [ -x /usr/bin/sha256sum ]; then
  RAMFS_COPY_BIN="$RAMFS_COPY_BIN /usr/bin/sha256sum"
elif [ -x /bin/sha256sum ]; then
  RAMFS_COPY_BIN="$RAMFS_COPY_BIN /bin/sha256sum"
fi
REQUIRE_IMAGE_METADATA=1

RV220W_ERASE_SIZE=131072
RV220W_ROOTFS_SIZE=26607616
RV220W_JFFS2_EOF_HEX=deadc0de

rv220w_sysupgrade_dir() {
	local tar_file="$1"
	local board_dir

	board_dir="sysupgrade-cisco,rv220w"
	tar tf "$tar_file" 2>/dev/null | grep -qx "${board_dir}/" || return 1
	printf '%s\n' "$board_dir"
}

rv220w_mtd_size() {
	local name="$1"
	awk -v expected="\"$name\"" '$4 == expected { print $2; exit }' /proc/mtd
}

rv220w_check_layout() {
	# Physical partition indices and sizes are fixed. The automatically split
	# rootfs_data size is intentionally variable because it begins at the next
	# erase boundary after the SquashFS and therefore changes as images grow.
	[ "$(grep -c '^mtd[0-9][0-9]*:' /proc/mtd)" = "5" ] || return 1
	awk '
		$1 == "mtd0:" && $2 == "00080000" && $3 == "00020000" && $4 == "\"boot-chain\"" { p0=1 }
		$1 == "mtd1:" && $2 == "00600000" && $3 == "00020000" && $4 == "\"openwrt-kernel\"" { p1=1 }
		$1 == "mtd2:" && $2 == "01960000" && $3 == "00020000" && $4 == "\"rootfs\"" { p2=1 }
		$1 == "mtd3:" && $2 != "00000000" && $3 == "00020000" && $4 == "\"rootfs_data\"" { p3=1 }
		$1 == "mtd4:" && $2 == "00020000" && $3 == "00020000" && $4 == "\"uboot-env\"" { p4=1 }
		END { exit !(p0 && p1 && p2 && p3 && p4) }
	' /proc/mtd || return 1
	[ "$(grep -c '"rootfs_data"' /proc/mtd)" = "1" ] || return 1
}

rv220w_check_archive_members() {
	local tar_file="$1"
	local board_dir="$2"
	local actual expected

	expected="${board_dir}
${board_dir}/CONTROL
${board_dir}/kernel
${board_dir}/root"
	actual="$(tar tf "$tar_file" 2>/dev/null | sed 's#/$##' | sort)" || return 1
	[ "$actual" = "$expected" ]
}

rv220w_squashfs_bytes_used() {
	local image="$1"
	local b0 b1 b2 b3 b4 b5 b6 b7

	# SquashFS v4 stores bytes_used as a little-endian u64 at offset 40.
	# The RV220W CPU is big-endian, so decode individual bytes using the
	# BusyBox hexdump applet already present in the base image and stage2 RAMFS.
	set -- $(hexdump -v -s 40 -n 8 -e '1/1 "%u "' "$image")
	[ "$#" -eq 8 ] || return 1
	b0="$1"; b1="$2"; b2="$3"; b3="$4"
	b4="$5"; b5="$6"; b6="$7"; b7="$8"
	printf '%s\n' "$((b0 + (b1 << 8) + (b2 << 16) + (b3 << 24) + (b4 << 32) + (b5 << 40) + (b6 << 48) + (b7 << 56)))"
}

rv220w_prepare_root_member() {
	local member="$1"
	local output="$2"
	local member_size raw_size padding nonzero

	member_size="$(wc -c < "$member")" || return 1
	raw_size="$(rv220w_squashfs_bytes_used "$member")" || return 1
	[ "$raw_size" -ge 96 ] || return 1
	[ "$raw_size" -le "$member_size" ] || return 1
	[ "$raw_size" -le 26607616 ] || return 1
	[ $((member_size % 1024)) -eq 0 ] || return 1
	padding=$((member_size - raw_size))
	[ "$padding" -ge 0 ] && [ "$padding" -lt 1024 ] || return 1

	if [ "$padding" -gt 0 ]; then
		nonzero="$(hexdump -v -s "$raw_size" -n "$padding" -e '1/1 "%02x\n"' "$member" | sed '/^00$/d')"
		[ -z "$nonzero" ] || return 1
	fi

	dd if="$member" of="$output" bs="$raw_size" count=1 2>/dev/null || return 1
	[ "$(wc -c < "$output")" -eq "$raw_size" ] || return 1
}

rv220w_config_marker_offset() {
	local root="$1"
	local raw_size marker_offset

	raw_size="$(wc -c < "$root")" || return 1
	[ "$raw_size" -ge 96 ] || return 1
	marker_offset=$(( (raw_size + RV220W_ERASE_SIZE - 1) / RV220W_ERASE_SIZE * RV220W_ERASE_SIZE ))
	[ $((marker_offset % RV220W_ERASE_SIZE)) -eq 0 ] || return 1
	[ "$marker_offset" -ge "$raw_size" ] || return 1
	[ $((marker_offset + RV220W_ERASE_SIZE)) -lt "$RV220W_ROOTFS_SIZE" ] || return 1
	printf '%s\n' "$marker_offset"
}

rv220w_prepare_config_root_image() {
	local root="$1"
	local output="$2"
	local raw_size marker_offset padding image_size marker

	raw_size="$(wc -c < "$root")" || return 1
	marker_offset="$(rv220w_config_marker_offset "$root")" || return 1
	padding=$((marker_offset - raw_size))

	rm -f "$output"
	cp "$root" "$output" || return 1
	if [ "$padding" -gt 0 ]; then
		dd if=/dev/zero bs="$padding" count=1 2>/dev/null >> "$output" || return 1
	fi
	printf '\336\255\300\336' >> "$output" || return 1

	image_size="$(wc -c < "$output")" || return 1
	[ "$image_size" -eq $((marker_offset + 4)) ] || return 1
	marker="$(hexdump -v -s "$marker_offset" -n 4 -e '4/1 "%02x"' "$output")" || return 1
	[ "$marker" = "$RV220W_JFFS2_EOF_HEX" ] || return 1
	printf '%s\n' "$marker_offset"
}

rv220w_validate_upgrade_backup() {
	local backup="$1"
	local list="$2"
	local marker_offset="$3"
	local backup_size available

	[ -n "$backup" ] && [ -f "$backup" ] && [ -s "$backup" ] || return 1
	gzip -t "$backup" >/dev/null 2>&1 || return 1
	tar tzf "$backup" > "$list" 2>/dev/null || return 1
	[ -s "$list" ] || return 1

	backup_size="$(wc -c < "$backup")" || return 1
	available=$((RV220W_ROOTFS_SIZE - marker_offset))
	[ "$available" -gt $((4 * RV220W_ERASE_SIZE)) ] || return 1
	[ "$backup_size" -le $((available - 4 * RV220W_ERASE_SIZE)) ] || return 1
}

rv220w_verify_config_append() {
	local marker_offset="$1"
	local magic

	[ $((marker_offset % RV220W_ERASE_SIZE)) -eq 0 ] || return 1
	magic="$(mtd -q -q -o "$marker_offset" -l 4 dump rootfs 2>/dev/null | hexdump -v -n 4 -e '4/1 "%02x"')" || return 1
	case "$magic" in
	1985*|8519*)
		return 0
		;;
	*)
		echo "RV220W preserved-config JFFS2 node was not written at offset $marker_offset (magic=$magic)."
		return 1
		;;
	esac
}

rv220w_stream_member_size() {
	local tar_file="$1"
	local member="$2"

	tar -Oxf "$tar_file" "$member" 2>/dev/null | wc -c
}

rv220w_stream_squashfs_bytes_used() {
	local tar_file="$1"
	local member="$2"
	local b0 b1 b2 b3 b4 b5 b6 b7

	# Read only the SquashFS bytes_used field from the tar stream. This avoids
	# materializing the root member in /tmp on the RAM-constrained liveboot.
	set -- $(tar -Oxf "$tar_file" "$member" 2>/dev/null | \
		dd bs=1 skip=40 count=8 2>/dev/null | \
		hexdump -v -n 8 -e '1/1 "%u "')
	[ "$#" -eq 8 ] || return 1
	b0="$1"; b1="$2"; b2="$3"; b3="$4"
	b4="$5"; b5="$6"; b6="$7"; b7="$8"
	printf '%s\n' "$((b0 + (b1 << 8) + (b2 << 16) + (b3 << 24) + (b4 << 32) + (b5 << 40) + (b6 << 48) + (b7 << 56)))"
}

rv220w_validate_upgrade_stream() {
	local tar_file="$1"
	local board_dir="$2"
	local kernel_size root_member_size raw_size padding magic

	rv220w_check_archive_members "$tar_file" "$board_dir" || return 1
	tar -Oxf "$tar_file" "$board_dir/CONTROL" 2>/dev/null | grep -qx 'BOARD=cisco,rv220w' || return 1

	kernel_size="$(rv220w_stream_member_size "$tar_file" "$board_dir/kernel")" || return 1
	root_member_size="$(rv220w_stream_member_size "$tar_file" "$board_dir/root")" || return 1
	[ "$kernel_size" -gt 0 ] && [ "$kernel_size" -le 6291456 ] || return 1
	[ "$root_member_size" -ge 1024 ] && [ "$root_member_size" -le "$RV220W_ROOTFS_SIZE" ] || return 1
	[ $((root_member_size % 1024)) -eq 0 ] || return 1

	magic="$(tar -Oxf "$tar_file" "$board_dir/kernel" 2>/dev/null | hexdump -v -n 3 -e '3/1 "%02x"')" || return 1
	[ "$magic" = 1f8b08 ] || return 1
	# gzip -t consumes the stream without retaining the decompressed kernel.
	tar -Oxf "$tar_file" "$board_dir/kernel" 2>/dev/null | gzip -t >/dev/null 2>&1 || return 1
	magic="$(tar -Oxf "$tar_file" "$board_dir/kernel" 2>/dev/null | gzip -dc 2>/dev/null | hexdump -v -n 4 -e '4/1 "%02x"')" || return 1
	[ "$magic" = 7f454c46 ] || return 1

	magic="$(tar -Oxf "$tar_file" "$board_dir/root" 2>/dev/null | hexdump -v -n 4 -e '4/1 "%02x"')" || return 1
	[ "$magic" = 68737173 ] || return 1
	raw_size="$(rv220w_stream_squashfs_bytes_used "$tar_file" "$board_dir/root")" || return 1
	[ "$raw_size" -ge 96 ] && [ "$raw_size" -le "$root_member_size" ] && [ "$raw_size" -le "$RV220W_ROOTFS_SIZE" ] || return 1
	padding=$((root_member_size - raw_size))
	[ "$padding" -ge 0 ] && [ "$padding" -lt 1024 ] || return 1

	printf 'RV220W low-memory image validation: kernel=%s root-member=%s squashfs-bytes-used=%s padding=%s\n' \
		"$kernel_size" "$root_member_size" "$raw_size" "$padding"
}

rv220w_stream_member_sha256() {
	local tar_file="$1"
	local member="$2"
	tar -Oxf "$tar_file" "$member" 2>/dev/null | sha256sum | awk '{print $1}'
}

rv220w_stream_write_member() {
	local tar_file="$1"
	local member="$2"
	local partition="$3"
	local size source_sha target_sha

	size="$(rv220w_stream_member_size "$tar_file" "$member")" || return 1
	[ "$size" -gt 0 ] || return 1
	source_sha="$(rv220w_stream_member_sha256 "$tar_file" "$member")" || return 1
	[ -n "$source_sha" ] || return 1

	mtd unlock "$partition" || return 1
	mtd erase "$partition" || return 1
	# mtd explicitly supports '-' as stdin. Stream the tar member directly so
	# the liveboot never needs a second kernel/rootfs copy in tmpfs.
	tar -Oxf "$tar_file" "$member" 2>/dev/null | mtd write - "$partition" || return 1

	target_sha="$(mtd -q -q -l "$size" dump "$partition" 2>/dev/null | sha256sum | awk '{print $1}')" || return 1
	[ "$target_sha" = "$source_sha" ] || {
		echo "RV220W $partition readback SHA-256 mismatch (source=$source_sha target=$target_sha)."
		return 1
	}
	printf 'RV220W %s stream/readback SHA-256 verified: %s\n' "$partition" "$source_sha"
}

rv220w_extract_upgrade() {
	local tar_file="$1"
	local board_dir="$2"
	local workdir="$3"
	local control kernel root_member root

	rv220w_check_archive_members "$tar_file" "$board_dir" || return 1
	mkdir -p "$workdir" || return 1
	control="$workdir/CONTROL"
	kernel="$workdir/kernel.gz"
	root_member="$workdir/root.member"
	root="$workdir/root.squashfs"

	tar -Oxf "$tar_file" "$board_dir/CONTROL" > "$control" || return 1
	grep -qx 'BOARD=cisco,rv220w' "$control" || return 1
	tar -Oxf "$tar_file" "$board_dir/kernel" > "$kernel" || return 1
	tar -Oxf "$tar_file" "$board_dir/root" > "$root_member" || return 1

	[ -s "$kernel" ] && [ -s "$root_member" ] || return 1
	[ "$(wc -c < "$kernel")" -le 6291456 ] || return 1
	[ "$(dd if="$kernel" bs=3 count=1 2>/dev/null | hexdump -v -e '3/1 "%02x"')" = "1f8b08" ] || return 1
	[ "$(dd if="$root_member" bs=4 count=1 2>/dev/null | hexdump -v -e '4/1 "%02x"')" = "68737173" ] || return 1
	rv220w_prepare_root_member "$root_member" "$root" || return 1
	rm -f "$root_member"
}

rv220w_do_upgrade() {
	local tar_file="$1"
	local board_dir workdir kernel root root_write marker_offset backup_list

	board_dir="$(rv220w_sysupgrade_dir "$tar_file")" || {
		echo "RV220W sysupgrade archive has no board directory."
		return 1
	}

	rv220w_check_layout || {
		echo "RV220W NOR layout does not match the validated full-NOR map."
		return 1
	}

	# The clean-install/liveboot path uses sysupgrade -n and therefore has no
	# configuration backup to merge. Keep this path streaming and low-memory:
	# validate directly from the tar, write rootfs first, verify its readback,
	# then write/verify the kernel last. This is specifically important on the
	# 128 MiB RV220W while the installer initramfs is resident in RAM.
	if [ -z "$UPGRADE_BACKUP" ]; then
		rv220w_validate_upgrade_stream "$tar_file" "$board_dir" || {
			echo "RV220W sysupgrade components failed low-memory validation."
			return 1
		}
		echo "Erasing/writing RV220W rootfs from the sysupgrade stream..."
		rv220w_stream_write_member "$tar_file" "$board_dir/root" rootfs || return 1
		echo "Writing RV220W gzip-compressed ELF kernel last from the sysupgrade stream..."
		rv220w_stream_write_member "$tar_file" "$board_dir/kernel" openwrt-kernel || return 1
		sync
		echo "RV220W streamed kernel/rootfs verified; boot-chain and uboot-env were untouched."
		return 0
	fi

	# Configuration-preserving upgrades retain the previously hardware-qualified
	# extraction/JFFS2 insertion path. Installed SquashFS boots have substantially
	# more free RAM than the liveboot installer because the initramfs is absent.
	workdir=/tmp/rv220w-sysupgrade
	rm -rf "$workdir"
	rv220w_extract_upgrade "$tar_file" "$board_dir" "$workdir" || {
		echo "RV220W sysupgrade components failed validation."
		return 1
	}
	kernel="$workdir/kernel.gz"
	root="$workdir/root.squashfs"
	root_write="$root"
	marker_offset=""

	if [ -n "$UPGRADE_BACKUP" ]; then
		root_write="$workdir/root.with-jffs2-eof"
		marker_offset="$(rv220w_prepare_config_root_image "$root" "$root_write")" || {
			echo "RV220W could not prepare an erase-aligned JFFS2 config marker."
			return 1
		}
		backup_list="$workdir/backup.list"
		rv220w_validate_upgrade_backup "$UPGRADE_BACKUP" "$backup_list" "$marker_offset" || {
			echo "RV220W configuration preservation was requested, but the backup is missing, invalid, empty, or too large."
			return 1
		}
		echo "RV220W configuration backup validated; JFFS2 insertion marker is at rootfs offset $marker_offset."
	fi

	echo "Erasing the complete 25.375 MiB RV220W rootfs region..."
	mtd unlock rootfs || return 1
	mtd erase rootfs || return 1

	echo "Writing RV220W SquashFS rootfs..."
	if [ -n "$marker_offset" ]; then
		echo "Integrating the preserved configuration into the new JFFS2 rootfs_data area..."
		mtd -j "$UPGRADE_BACKUP" write "$root_write" rootfs || return 1
	else
		mtd write "$root" rootfs || return 1
	fi
	mtd verify "$root" rootfs || return 1
	if [ -n "$marker_offset" ]; then
		rv220w_verify_config_append "$marker_offset" || return 1
		echo "RV220W preserved configuration was embedded in rootfs_data."
	fi

	echo "Writing RV220W gzip-compressed ELF kernel last..."
	mtd unlock openwrt-kernel || return 1
	mtd erase openwrt-kernel || return 1
	mtd write "$kernel" openwrt-kernel || return 1
	mtd verify "$kernel" openwrt-kernel || return 1

	sync
	echo "RV220W kernel and rootfs verified; boot-chain and uboot-env were untouched."
}

platform_get_rootfs() {
	local rootfsdev
	local rootpartuuid

	if read cmdline < /proc/cmdline; then
		case "$cmdline" in
			*root=PARTUUID=*)
				rootpartuuid="${cmdline##*root=PARTUUID=}"
				rootpartuuid="${rootpartuuid%% *}"
				rootfsdev="$(blkid -o device -t PARTUUID="${rootpartuuid}")"
			;;
			*root=*)
				rootfsdev="${cmdline##*root=}"
				rootfsdev="${rootfsdev%% *}"
			;;
		esac

		echo "${rootfsdev}"
	fi
}

platform_get_n821_disk() {
	local partnum=$1
	local DEVNAME
	while read line; do
		export -n "${line}"
	done < $(find /sys/bus/platform/devices/16f0000000000.ehci/ -path \*block/sd[a-z]/uevent)
	echo "/dev/${DEVNAME}${partnum}"
}

platform_copy_config_helper() {
	local device=$1
	local fstype=$2

	mount -t "${fstype}" "$device" /mnt
	cp -af "$UPGRADE_BACKUP" "/mnt/$BACKUP_FILE"
	umount /mnt
}

platform_copy_config() {
	case "$(board_name)" in
	ubnt,erlite|\
	ubnt,usg)
		platform_copy_config_helper /dev/sda1 vfat
		;;
	itus,shield-router)
		platform_copy_config_helper /dev/mmcblk1p1 vfat
		;;
	er|\
	ubnt,edgerouter-4|\
	ubnt,edgerouter-6p)
		platform_copy_config_helper /dev/mmcblk0p1 vfat
		;;
	cisco,vedge1000)
		platform_copy_config_helper "$(platform_get_n821_disk 1)" ext2
		;;
	esac
}

platform_do_flash() {
	local tar_file=$1
	local board=$2
	local kernel=$3
	local rootfs=$4

	local board_dir=$(tar tf "$tar_file" | grep -m 1 '^sysupgrade-.*/$')
	board_dir=${board_dir%/}
	[ -n "$board_dir" ] || return 1

	mkdir -p /boot

	if [ $board = "itus,shield-router" ]; then
		# mmcblk1p1 (fat) contains all ELF-bin images for the Shield
		mount /dev/mmcblk1p1 /boot

		echo "flashing Itus Kernel to /boot/$kernel (/dev/mmblk1p1)"
		tar -Oxf $tar_file "$board_dir/kernel" > /boot/$kernel
	else
		if [ "${board}" = "cisco,vedge1000" ]; then
			local rootpartuuid
			rootpartuuid="$(/usr/sbin/blkid -o value -s PARTUUID "${rootfs}")"
			if [ -n "${rootpartuuid}" ]; then
				echo "setting root partition to PARTUUID=${rootpartuuid}"
				fw_setenv bootcmd 'usb start; ext2load usb 0:1 $loadaddr vmlinux.64; bootoctlinux $loadaddr coremask=f endbootargs rootfstype=squashfs rootwait root=PARTUUID='"${rootpartuuid}"
			else
				echo "WARNING: unable to figure out root partition UUID, leaving bootcmd unchanged"
			fi
			mount -t ext2 "${kernel}" /boot
		else
			mount -t vfat "${kernel}" /boot
		fi

		[ -f /boot/vmlinux.64 -a ! -L /boot/vmlinux.64 ] && {
			mv /boot/vmlinux.64 /boot/vmlinux.64.previous
			mv /boot/vmlinux.64.md5 /boot/vmlinux.64.md5.previous
		}

		echo "flashing kernel to $(awk '/\/boot/ {print $1}' /proc/mounts)"
		tar xf $tar_file $board_dir/kernel -O > /boot/vmlinux.64
		md5sum /boot/vmlinux.64 | cut -f1 -d " " > /boot/vmlinux.64.md5
	fi

	echo "flashing rootfs to ${rootfs}"
	tar xf $tar_file $board_dir/root -O | dd of="${rootfs}" bs=4096

	sync
	umount /boot
}

platform_do_upgrade() {
	local tar_file="$1"
	local board=$(board_name)
	local rootfs="$(platform_get_rootfs)"
	local kernel=

	if [ "$board" = "cisco,rv220w" ]; then
		rv220w_do_upgrade "$tar_file" || {
			echo "RV220W sysupgrade failed; refusing the automatic reboot."
			exit 1
		}
		return 0
	fi

	if [ ! -b "${rootfs}" ] && [ "${board}" = "cisco,vedge1000" ]; then
		# Default to the built-in USB disk for N821
		rootfs="$(platform_get_n821_disk 2)"
	fi
	[ -b "${rootfs}" ] || return 1
	case "$board" in
	er | \
	ubnt,edgerouter-4 | \
	ubnt,edgerouter-6p)
		kernel=/dev/mmcblk0p1
		;;
	ubnt,erlite|\
	ubnt,usg)
		kernel=/dev/sda1
		;;
	itus,shield-router)
		kernel=ItusrouterImage
		;;
	cisco,vedge1000)
		kernel="$(platform_get_n821_disk 1)"
		;;
	*)
		return 1
	esac

	platform_do_flash $tar_file $board $kernel $rootfs

	return 0
}

platform_check_image() {
	local board=$(board_name)
	local tar_file="$1"

	local board_dir=$(tar tf "$tar_file" | grep -m 1 '^sysupgrade-.*/$')
	board_dir=${board_dir%/}
	[ -n "$board_dir" ] || return 1

	case "$board" in
	cisco,rv220w)
		rv220w_check_layout || {
			echo "RV220W NOR layout does not match the validated full-NOR map."
			return 1
		}
		rv220w_validate_upgrade_stream "$tar_file" "$board_dir" || {
			echo "The RV220W upgrade image failed low-memory stream validation or has the wrong board identity."
			return 1
		}
		return 0
		;;
	er | \
	itus,shield-router | \
	ubnt,edgerouter-4 | \
	ubnt,edgerouter-6p | \
	ubnt,erlite | \
	ubnt,usg | \
	cisco,vedge1000)
		local kernel_length=$(tar xf $tar_file $board_dir/kernel -O | wc -c 2> /dev/null)
		local rootfs_length=$(tar xf $tar_file $board_dir/root -O | wc -c 2> /dev/null)
		[ "$kernel_length" = 0 -o "$rootfs_length" = 0 ] && {
			echo "The upgrade image is corrupt."
			return 1
		}
		return 0
		;;
	esac

	echo "Sysupgrade is not yet supported on $board."
	return 1
}
