#!/usr/bin/env python3
"""Create an RV220W v1.3.2 DTB-repacked candidate from proven v1.3.0/v1.3.1 ELFs.

This performs a constrained `.appended_dtb` replacement for an already-linked ELF.
OpenWrt normally sizes the section before its objcopy population step; this tool
adds the required ELF metadata expansion when the replacement DTB is larger.
Kernel and initramfs bytes come from v1.3.1; the only DT changes are the exact v1.3.0 nor@0,0 child plus the v1.3.1 400 MHz UART
clock. No target access or flash operation is performed.
"""
from __future__ import annotations

import argparse
import copy
import hashlib
import json
import pathlib
import shutil
import struct
import tempfile
from collections import OrderedDict
from dataclasses import dataclass, field
from typing import NoReturn

FDT_MAGIC = 0xD00DFEED
BEGIN = 1
END_NODE = 2
PROP = 3
NOP = 4
END = 9
BOOTBUS_PATH = "/soc@0/bootbus@1180000000000"
UART_PATH = "/soc@0/serial@1180000000800"


def die(message: str) -> NoReturn:
    raise SystemExit(f"error: {message}")


def align4(value: int) -> int:
    return (value + 3) & ~3


def be32(*values: int) -> bytes:
    return b"".join(struct.pack(">I", value & 0xFFFFFFFF) for value in values)


@dataclass
class Node:
    name: str
    props: OrderedDict[str, bytes] = field(default_factory=OrderedDict)
    children: list["Node"] = field(default_factory=list)

    def child(self, name: str) -> "Node | None":
        return next((node for node in self.children if node.name == name), None)

    def path(self, path: str) -> "Node | None":
        node: Node | None = self
        for part in (part for part in path.split("/") if part):
            node = node.child(part) if node else None
            if node is None:
                return None
        return node

    def add(self, node: "Node") -> None:
        self.children = [child for child in self.children if child.name != node.name]
        self.children.append(node)


def parse_fdt(path: pathlib.Path) -> tuple[Node, dict[str, int]]:
    data = path.read_bytes()
    if len(data) < 40:
        die(f"DTB is too small: {path}")
    header = struct.unpack(">10I", data[:40])
    if header[0] != FDT_MAGIC:
        die(f"invalid FDT magic: {path}")
    _, total, off_struct, off_strings, _off_rsv, version, last, cpu, size_strings, _size_struct = header
    if total > len(data):
        die(f"truncated DTB: {path}")
    strings = data[off_strings : off_strings + size_strings]

    def prop_name(offset: int) -> str:
        end = strings.index(b"\0", offset)
        return strings[offset:end].decode()

    position = off_struct

    def parse_node() -> Node:
        nonlocal position
        if struct.unpack_from(">I", data, position)[0] != BEGIN:
            die(f"expected FDT_BEGIN_NODE at 0x{position:x} in {path}")
        position += 4
        end = data.index(b"\0", position)
        node = Node(data[position:end].decode())
        position = align4(end + 1)
        while True:
            token = struct.unpack_from(">I", data, position)[0]
            position += 4
            if token == PROP:
                length, name_offset = struct.unpack_from(">II", data, position)
                position += 8
                node.props[prop_name(name_offset)] = data[position : position + length]
                position = align4(position + length)
            elif token == BEGIN:
                position -= 4
                node.children.append(parse_node())
            elif token == END_NODE:
                return node
            elif token == NOP:
                continue
            else:
                die(f"unexpected FDT token {token} at 0x{position - 4:x} in {path}")

    root = parse_node()
    if struct.unpack_from(">I", data, position)[0] != END:
        die(f"missing FDT_END token: {path}")
    return root, {"version": version, "last_comp_version": last, "boot_cpuid_phys": cpu}


def serialize_fdt(root: Node, meta: dict[str, int]) -> bytes:
    names: OrderedDict[str, int | None] = OrderedDict()

    def collect(node: Node) -> None:
        for key in node.props:
            names.setdefault(key, None)
        for child in node.children:
            collect(child)

    collect(root)
    strings = bytearray()
    for key in names:
        names[key] = len(strings)
        strings.extend(key.encode() + b"\0")

    structure = bytearray()

    def emit(node: Node) -> None:
        structure.extend(be32(BEGIN))
        structure.extend(node.name.encode() + b"\0")
        structure.extend(b"\0" * (align4(len(structure)) - len(structure)))
        for key, value in node.props.items():
            structure.extend(be32(PROP, len(value), int(names[key])))
            structure.extend(value)
            structure.extend(b"\0" * (align4(len(structure)) - len(structure)))
        for child in node.children:
            emit(child)
        structure.extend(be32(END_NODE))

    emit(root)
    structure.extend(be32(END))
    reserve = b"\0" * 16
    off_reserve = 40
    off_structure = off_reserve + len(reserve)
    off_strings = off_structure + len(structure)
    total = off_strings + len(strings)
    header = struct.pack(
        ">10I",
        FDT_MAGIC,
        total,
        off_structure,
        off_strings,
        off_reserve,
        17,
        16,
        meta.get("boot_cpuid_phys", 0),
        len(strings),
        len(structure),
    )
    return header + reserve + structure + strings


def walk(root: Node) -> dict[str, Node]:
    result: dict[str, Node] = {}

    def visit(node: Node, parent: str = "") -> None:
        path = "/" if not node.name else parent.rstrip("/") + "/" + node.name
        result[path] = node
        for child in node.children:
            visit(child, path)

    visit(root)
    return result


def semantic_differences(left: Node, right: Node) -> list[str]:
    lmap, rmap = walk(left), walk(right)
    differences: list[str] = []
    for path in sorted(set(lmap) ^ set(rmap)):
        differences.append(f"node:{path}:{'left-only' if path in lmap else 'right-only'}")
    for path in sorted(set(lmap) & set(rmap)):
        lp, rp = lmap[path].props, rmap[path].props
        for key in sorted(set(lp) ^ set(rp)):
            differences.append(f"property:{path}:{key}:{'left-only' if key in lp else 'right-only'}")
        for key in sorted(set(lp) & set(rp)):
            if lp[key] != rp[key]:
                differences.append(f"value:{path}:{key}:{lp[key].hex()}:{rp[key].hex()}")
    return differences


@dataclass
class ElfSection:
    index: int
    name: str
    sh_name: int
    sh_type: int
    sh_flags: int
    sh_addr: int
    sh_offset: int
    sh_size: int
    sh_link: int
    sh_info: int
    sh_addralign: int
    sh_entsize: int

    def pack(self) -> bytes:
        return struct.pack(
            ">IIQQQQIIQQ",
            self.sh_name,
            self.sh_type,
            self.sh_flags,
            self.sh_addr,
            self.sh_offset,
            self.sh_size,
            self.sh_link,
            self.sh_info,
            self.sh_addralign,
            self.sh_entsize,
        )


@dataclass
class Elf64Be:
    path: pathlib.Path
    data: bytes
    header: list[object]
    sections: list[ElfSection]

    @property
    def e_phoff(self) -> int:
        return int(self.header[5])

    @property
    def e_shoff(self) -> int:
        return int(self.header[6])

    @property
    def e_phentsize(self) -> int:
        return int(self.header[9])

    @property
    def e_phnum(self) -> int:
        return int(self.header[10])

    @property
    def e_shentsize(self) -> int:
        return int(self.header[11])

    @property
    def e_shnum(self) -> int:
        return int(self.header[12])

    def section(self, name: str) -> ElfSection:
        for entry in self.sections:
            if entry.name == name:
                return entry
        die(f"ELF section not found: {name} in {self.path}")


def align(value: int, boundary: int) -> int:
    boundary = max(boundary, 1)
    return (value + boundary - 1) & ~(boundary - 1)


def parse_elf64_be(path: pathlib.Path) -> Elf64Be:
    data = path.read_bytes()
    if len(data) < 64 or data[:4] != b"\x7fELF" or data[4] != 2 or data[5] != 2:
        die(f"expected ELF64 big-endian input: {path}")
    header = list(struct.unpack(">16sHHIQQQIHHHHHH", data[:64]))
    e_phoff, e_shoff = int(header[5]), int(header[6])
    e_phentsize, e_phnum = int(header[9]), int(header[10])
    e_shentsize, e_shnum, e_shstrndx = int(header[11]), int(header[12]), int(header[13])
    if e_phentsize != 56 or e_phnum < 1:
        die(f"unsupported ELF program-header table: {path}")
    if e_shentsize != 64 or e_shnum == 0 or e_shstrndx >= e_shnum:
        die(f"unsupported ELF section table: {path}")
    if e_phoff + e_phentsize * e_phnum > len(data) or e_shoff + e_shentsize * e_shnum > len(data):
        die(f"truncated ELF header table: {path}")

    raw_sections = [
        struct.unpack(">IIQQQQIIQQ", data[e_shoff + i * 64 : e_shoff + (i + 1) * 64])
        for i in range(e_shnum)
    ]
    shstr = raw_sections[e_shstrndx]
    names = data[shstr[4] : shstr[4] + shstr[5]]
    sections: list[ElfSection] = []
    for index, entry in enumerate(raw_sections):
        name_offset = entry[0]
        name = ""
        if name_offset < len(names):
            end = names.find(b"\0", name_offset)
            if end >= 0:
                name = names[name_offset:end].decode(errors="replace")
        sections.append(ElfSection(index, name, *entry))
    return Elf64Be(path, data, header, sections)


def extract_elf64_be_section(elf_path: pathlib.Path, section_name: str) -> bytes:
    elf = parse_elf64_be(elf_path)
    entry = elf.section(section_name)
    if entry.sh_type == 8:  # SHT_NOBITS
        die(f"cannot extract NOBITS section {section_name}: {elf_path}")
    if entry.sh_offset + entry.sh_size > len(elf.data):
        die(f"truncated ELF section {section_name}: {elf_path}")
    return elf.data[entry.sh_offset : entry.sh_offset + entry.sh_size]


def replace_growing_appended_dtb(source: pathlib.Path, output: pathlib.Path, dtb: bytes) -> dict[str, int]:
    """Replace a terminal allocated DTB section and safely expand ELF metadata.

    OpenWrt normally creates the ELF with a correctly sized `.appended_dtb`
    section and then uses objcopy to populate it. For an already-linked ELF,
    LLVM objcopy refuses to grow an allocated section inside PT_LOAD. This
    routine performs the narrowly constrained equivalent layout update:
    preserve all pre-DTB load bytes, extend PT_LOAD p_filesz, relayout only
    post-segment metadata, and rewrite the affected section offsets/sizes.
    """
    elf = parse_elf64_be(source)
    target = elf.section(".appended_dtb")
    if target.sh_type != 1 or not (target.sh_flags & 0x2):  # SHT_PROGBITS, SHF_ALLOC
        die(".appended_dtb is not an allocated PROGBITS section")
    if len(dtb) < target.sh_size:
        die("refusing a shrinking DTB replacement in the v1.3.2 repacker")
    old_end = target.sh_offset + target.sh_size
    new_end = target.sh_offset + len(dtb)

    # The only allocated file bytes at or beyond the DTB must be the DTB itself.
    for section in elf.sections:
        if section.index == target.index or section.sh_type == 8 or section.sh_size == 0:
            continue
        if (section.sh_flags & 0x2) and section.sh_offset >= old_end:
            die(f"allocated section follows .appended_dtb unexpectedly: {section.name}")

    # Locate the unique PT_LOAD whose file image terminates at the old DTB end.
    load_index = -1
    load_entry: tuple[int, ...] | None = None
    for index in range(elf.e_phnum):
        off = elf.e_phoff + index * elf.e_phentsize
        entry = struct.unpack(">IIQQQQQQ", elf.data[off : off + 56])
        p_type, _flags, p_offset, _vaddr, _paddr, p_filesz, _p_memsz, _align = entry
        if p_type == 1 and p_offset <= target.sh_offset < p_offset + p_filesz:
            if load_entry is not None:
                die(".appended_dtb is covered by multiple PT_LOAD entries")
            load_index, load_entry = index, entry
    if load_entry is None:
        die(".appended_dtb is not covered by PT_LOAD")
    if load_entry[2] + load_entry[5] != old_end:
        die("PT_LOAD file image does not end at .appended_dtb")
    delta = len(dtb) - target.sh_size
    if load_entry[5] + delta > load_entry[6]:
        die("expanded DTB would exceed PT_LOAD memory size")

    # Rebuild non-allocated file sections between the segment and section table.
    post_sections = [
        section for section in elf.sections
        if section.sh_type != 8 and section.sh_size > 0 and section.sh_offset >= old_end
        and section.sh_offset < elf.e_shoff
    ]
    post_sections.sort(key=lambda section: (section.sh_offset, section.index))
    cursor = new_end
    post_offsets: dict[int, int] = {}
    post_blob = bytearray()
    for section in post_sections:
        new_offset = align(cursor, section.sh_addralign)
        post_blob.extend(b"\0" * (new_offset - cursor))
        original = elf.data[section.sh_offset : section.sh_offset + section.sh_size]
        if len(original) != section.sh_size:
            die(f"truncated post-DTB section: {section.name}")
        post_offsets[section.index] = new_offset
        post_blob.extend(original)
        cursor = new_offset + section.sh_size
    new_shoff = align(cursor, 8)
    post_blob.extend(b"\0" * (new_shoff - cursor))

    sections = copy.deepcopy(elf.sections)
    sections[target.index].sh_size = len(dtb)
    for section in sections:
        if section.index in post_offsets:
            section.sh_offset = post_offsets[section.index]
        elif section.index != target.index and section.sh_offset == old_end and (
            section.sh_type == 8 or section.sh_size == 0
        ):
            section.sh_offset = new_end

    # Construct the new file and update ELF/program-header metadata in place.
    rebuilt = bytearray(elf.data[: target.sh_offset])
    rebuilt.extend(dtb)
    rebuilt.extend(post_blob)
    if len(rebuilt) != new_shoff:
        die("internal ELF relayout length mismatch")
    rebuilt.extend(b"".join(section.pack() for section in sections))
    # Preserve any opaque trailer after the old section-header table.
    old_sht_end = elf.e_shoff + elf.e_shnum * elf.e_shentsize
    rebuilt.extend(elf.data[old_sht_end:])

    header = list(elf.header)
    header[6] = new_shoff
    rebuilt[:64] = struct.pack(">16sHHIQQQIHHHHHH", *header)
    phoff = elf.e_phoff + load_index * elf.e_phentsize
    updated_load = list(load_entry)
    updated_load[5] += delta
    rebuilt[phoff : phoff + 56] = struct.pack(">IIQQQQQQ", *updated_load)

    output.parent.mkdir(parents=True, exist_ok=True)
    output.write_bytes(rebuilt)
    check = parse_elf64_be(output)
    check_target = check.section(".appended_dtb")
    if extract_elf64_be_section(output, ".appended_dtb") != dtb:
        die("output ELF appended DTB does not match replacement data")
    if check_target.sh_offset != target.sh_offset or check_target.sh_addr != target.sh_addr:
        die("DTB section location changed unexpectedly")
    if check.e_shnum != elf.e_shnum or check.e_phnum != elf.e_phnum:
        die("ELF table counts changed unexpectedly")
    if check.data[target.sh_offset : target.sh_offset + len(dtb)] != dtb:
        die("DTB data verification failed")

    return {
        "old_dtb_size": target.sh_size,
        "new_dtb_size": len(dtb),
        "dtb_growth": delta,
        "old_segment_filesz": load_entry[5],
        "new_segment_filesz": updated_load[5],
        "segment_memsz": load_entry[6],
        "old_section_header_offset": elf.e_shoff,
        "new_section_header_offset": new_shoff,
        "old_file_size": len(elf.data),
        "new_file_size": len(rebuilt),
    }

def sha256(path: pathlib.Path) -> str:
    return hashlib.sha256(path.read_bytes()).hexdigest()


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("--v130-elf", required=True, type=pathlib.Path)
    parser.add_argument("--v131-elf", required=True, type=pathlib.Path)
    parser.add_argument("--output", required=True, type=pathlib.Path)
    parser.add_argument("--dtb-output", type=pathlib.Path)
    parser.add_argument("--report", type=pathlib.Path)
    args = parser.parse_args()

    v130 = args.v130_elf.expanduser().resolve()
    v131 = args.v131_elf.expanduser().resolve()
    output = args.output.expanduser().resolve()
    for path in (v130, v131):
        if not path.is_file():
            die(f"ELF not found: {path}")
    output.parent.mkdir(parents=True, exist_ok=True)

    with tempfile.TemporaryDirectory(prefix="rv220w-v132-") as td:
        temp = pathlib.Path(td)
        dtb130 = temp / "v1.3.0.dtb"
        dtb131 = temp / "v1.3.1.dtb"
        merged_path = temp / "v1.3.2.dtb"
        input_hashes_before = (sha256(v130), sha256(v131))
        dtb130.write_bytes(extract_elf64_be_section(v130, ".appended_dtb"))
        dtb131.write_bytes(extract_elf64_be_section(v131, ".appended_dtb"))

        root130, meta130 = parse_fdt(dtb130)
        root131, meta131 = parse_fdt(dtb131)
        expected_differences = {
            f"node:{BOOTBUS_PATH}/nor@0,0:left-only",
            f"value:{UART_PATH}:clock-frequency:00000000:17d78400",
        }
        actual_differences = set(semantic_differences(root130, root131))
        if actual_differences != expected_differences:
            die("v1.3.0/v1.3.1 DTBs differ beyond the two approved changes: " + repr(sorted(actual_differences)))
        if meta130 != meta131:
            die("v1.3.0/v1.3.1 FDT metadata differs unexpectedly")

        boot130 = root130.path(BOOTBUS_PATH)
        boot131 = root131.path(BOOTBUS_PATH)
        uart131 = root131.path(UART_PATH)
        if not boot130 or not boot131 or not uart131:
            die("required DT node is missing")
        nor = boot130.child("nor@0,0")
        if not nor or nor.props.get("status") != b"okay\0":
            die("v1.3.0 NOR trigger child is missing or not enabled")
        if boot131.child("nor@0,0") is not None:
            die("v1.3.1 unexpectedly already contains the NOR trigger")
        if uart131.props.get("clock-frequency") != be32(400_000_000):
            die("v1.3.1 UART clock is not 400 MHz")

        merged = copy.deepcopy(root131)
        merged_boot = merged.path(BOOTBUS_PATH)
        assert merged_boot is not None
        merged_boot.add(copy.deepcopy(nor))
        merged_data = serialize_fdt(merged, meta131)
        merged_path.write_bytes(merged_data)
        parsed_merged, _ = parse_fdt(merged_path)

        expected = copy.deepcopy(root130)
        expected_uart = expected.path(UART_PATH)
        assert expected_uart is not None
        expected_uart.props["clock-frequency"] = be32(400_000_000)
        remaining = semantic_differences(expected, parsed_merged)
        if remaining:
            die("merged DTB does not equal v1.3.0 + v1.3.1 UART clock: " + repr(remaining))

        layout = replace_growing_appended_dtb(v131, output, merged_data)
        if input_hashes_before != (sha256(v130), sha256(v131)):
            die("input ELF changed during repack; refusing output")

        dtb_output = args.dtb_output.expanduser().resolve() if args.dtb_output else output.with_suffix(".dtb")
        dtb_output.parent.mkdir(parents=True, exist_ok=True)
        shutil.copy2(merged_path, dtb_output)

    report_path = args.report.expanduser().resolve() if args.report else output.with_suffix(output.suffix + ".json")
    report = {
        "type": "RV220W v1.3.2 DTB-repacked RAM-boot candidate",
        "method": "controlled ELF64 big-endian PT_LOAD/.appended_dtb expansion",
        "layout": layout,
        "v1.3.0_elf": v130.name,
        "v1.3.0_sha256": sha256(v130),
        "v1.3.1_elf": v131.name,
        "v1.3.1_sha256": sha256(v131),
        "output_elf": output.name,
        "output_sha256": sha256(output),
        "output_size": output.stat().st_size,
        "tftp_load_address": "0x05500000",
        "tftp_source_buffer_end": f"0x{0x05500000 + output.stat().st_size:08x}",
        "tftp_conservative_limit": "0x07f00000",
        "tftp_size_gate_passed": 0x05500000 + output.stat().st_size < 0x07F00000,
        "output_dtb": dtb_output.name,
        "output_dtb_sha256": sha256(dtb_output),
        "output_dtb_size": dtb_output.stat().st_size,
        "approved_semantic_changes": [
            "retain v1.3.1 uart0 clock-frequency 400000000",
            "restore exact v1.3.0 bootbus nor@0,0 enabled child",
        ],
        "unchanged": "kernel, initramfs, command line, Ethernet fallback, USB disable, disabled B53/reset nodes",
        "safety": "RAM-only candidate; no flash writer or persistent image",
        "hardware_validation": "pending",
    }
    report_path.parent.mkdir(parents=True, exist_ok=True)
    report_path.write_text(json.dumps(report, indent=2) + "\n", encoding="utf-8")
    print(json.dumps(report, indent=2))
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
