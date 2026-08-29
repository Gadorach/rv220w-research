#!/usr/bin/env python3
from __future__ import annotations

import hashlib
import pathlib
import stat
import zipfile

ROOT = pathlib.Path(__file__).resolve().parents[2]
VERSION = (ROOT / "VERSION").read_text().strip()
PREFIX = f"rv220w-openwrt-release-v{VERSION}"
DIST = ROOT / "dist"
ARCHIVE = DIST / f"{PREFIX}.zip"
FIXED_TIME = (2026, 8, 28, 0, 0, 0)


def source_files() -> list[pathlib.Path]:
    files: list[pathlib.Path] = []
    for path in ROOT.rglob("*"):
        if not path.is_file():
            continue
        rel = path.relative_to(ROOT)
        if rel.parts[0] in {"artifacts", "backups", "build", "dist", ".git"}:
            continue
        # The source manifest is generated from this file list and inserted once
        # at archive creation time.  Excluding an existing extracted manifest
        # makes `make package` reproducible even when run from a prior package.
        if rel.as_posix() == "SOURCE-SHA256SUMS":
            continue
        if "__pycache__" in rel.parts or path.suffix == ".pyc":
            continue
        files.append(path)
    return sorted(files, key=lambda p: p.relative_to(ROOT).as_posix())


def sha256(path: pathlib.Path) -> str:
    h = hashlib.sha256()
    with path.open("rb") as fh:
        while block := fh.read(1024 * 1024):
            h.update(block)
    return h.hexdigest()


def zip_info(name: str, mode: int = 0o644) -> zipfile.ZipInfo:
    info = zipfile.ZipInfo(name, FIXED_TIME)
    info.compress_type = zipfile.ZIP_DEFLATED
    info.create_system = 3
    info.external_attr = ((stat.S_IFREG | mode) & 0xFFFF) << 16
    return info


def main() -> None:
    files = source_files()
    manifest_lines = [f"{sha256(p)}  {p.relative_to(ROOT).as_posix()}" for p in files]
    manifest = ("\n".join(manifest_lines) + "\n").encode()

    DIST.mkdir(parents=True, exist_ok=True)
    ARCHIVE.unlink(missing_ok=True)
    with zipfile.ZipFile(ARCHIVE, "w", compression=zipfile.ZIP_DEFLATED, compresslevel=9) as zf:
        for path in files:
            rel = path.relative_to(ROOT).as_posix()
            mode = 0o755 if path.stat().st_mode & stat.S_IXUSR else 0o644
            zf.writestr(zip_info(f"{PREFIX}/{rel}", mode), path.read_bytes())
        zf.writestr(zip_info(f"{PREFIX}/SOURCE-SHA256SUMS"), manifest)

    archive_sha = sha256(ARCHIVE)
    checksum = DIST / f"{ARCHIVE.name}.sha256"
    checksum.write_text(f"{archive_sha}  {ARCHIVE.name}\n")
    (DIST / f"{PREFIX}-SOURCE-SHA256SUMS.txt").write_bytes(manifest)
    print(f"source_files={len(files)}")
    print(f"archive={ARCHIVE}")
    print(f"sha256={archive_sha}")


if __name__ == "__main__":
    main()
