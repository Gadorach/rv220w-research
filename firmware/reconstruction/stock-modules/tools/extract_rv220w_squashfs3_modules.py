#!/usr/bin/env python3
"""Read-only extractor for the five RV220W stock modules from SquashFS 3.0 BE.

This intentionally implements only the SquashFS-3 structures needed by the
verified Cisco RV220W root filesystem. It never writes the source image.
"""
from __future__ import annotations
import argparse, hashlib, json, math, os, pathlib, struct, sys, zlib
from dataclasses import dataclass

TARGETS = [
    "lib/modules/swdrv/bcm5398.ko",
    "lib/modules/swdrv/mii.ko",
    "lib/modules/2.6.21.7-Cavium-Octeon/cavium-ethernet.ko",
    "lib/modules/scm-led.ko",
    "lib/modules/push_button.ko",
]
EXPECTED = {
 "bcm5398.ko":"d4660579e780bf9f37c3c34ff9b82f55f4f4dafcb84017882c316ae6dfc1ffc5",
 "mii.ko":"7e9482b22a8c5ee05c0879049a739c9f81976a663749bf3a533f102cbde886d6",
 "cavium-ethernet.ko":"54b737ff533796870f8885d36398f630ab04ba66cb6e80d9e9f9af1bcd99dce0",
 "scm-led.ko":"1e9b504d50c5e75e650a90ceb0d0ef8bd0fb78b98718cd1040f9f61ddcc47c94",
 "push_button.ko":"d7b16272fd178fee5c68ac691322702a2f26e1d6daf0e062934e02e59d7ad04b",
}

def bits(buf: bytes, off: int, n: int) -> int:
    total = len(buf) * 8
    return (int.from_bytes(buf, "big") >> (total - off - n)) & ((1 << n) - 1)

def s16(v: int) -> int:
    return v - 0x10000 if v & 0x8000 else v

@dataclass
class Super:
    inodes:int; root_inode:int; block_size:int; fragments:int
    bytes_used:int; inode_start:int; dir_start:int; frag_table_start:int

class MetadataTable:
    def __init__(self, image: bytes, start: int, end: int):
        self.image=image; self.start=start; self.end=end
        self.blocks=[]; self.flat=bytearray(); self.rel_to_flat={}
        p=start
        while p < end:
            if p+2 > len(image): raise ValueError("truncated metadata header")
            rel=p-start; h=struct.unpack_from(">H",image,p)[0]; p+=2
            size=h & 0x7fff; raw=bool(h & 0x8000)
            if size == 0 or p+size > len(image): raise ValueError(f"bad metadata block at {p-2:#x}")
            payload=image[p:p+size]; p+=size
            data=payload if raw else zlib.decompress(payload)
            self.rel_to_flat[rel]=len(self.flat); self.blocks.append((rel,len(self.flat),len(data)))
            self.flat.extend(data)
    def at_ref(self, ref:int) -> int:
        rel=ref >> 16; off=ref & 0xffff
        if rel not in self.rel_to_flat: raise KeyError(f"metadata block {rel:#x} absent")
        return self.rel_to_flat[rel]+off
    def at_block_offset(self, rel:int, off:int) -> int:
        if rel not in self.rel_to_flat: raise KeyError(f"metadata block {rel:#x} absent")
        return self.rel_to_flat[rel]+off

class Squash3BE:
    def __init__(self,path:pathlib.Path):
        self.path=path; self.image=path.read_bytes(); self.sb=self._super()
        frag_ptrs=[]
        if self.sb.fragments:
            nblocks=math.ceil(self.sb.fragments*16/8192)
            frag_ptrs=[struct.unpack_from(">Q",self.image,self.sb.frag_table_start+i*8)[0] for i in range(nblocks)]
        self.inodes=MetadataTable(self.image,self.sb.inode_start,self.sb.dir_start)
        dir_end=min(frag_ptrs) if frag_ptrs else self.sb.frag_table_start
        self.dirs=MetadataTable(self.image,self.sb.dir_start,dir_end)
        self.frag_entries=[]
        for ptr in frag_ptrs:
            # Each pointer addresses one compressed metadata block containing fragment entries.
            h=struct.unpack_from(">H",self.image,ptr)[0]; size=h&0x7fff; raw=bool(h&0x8000)
            payload=self.image[ptr+2:ptr+2+size]; block=payload if raw else zlib.decompress(payload)
            for o in range(0,len(block)-15,16): self.frag_entries.append(struct.unpack_from(">QII",block,o))
        self.inode_cache={}
    def _super(self)->Super:
        b=self.image[:119]
        magic=bits(b,0,32)
        if magic != 0x73717368: raise ValueError(f"not big-endian SquashFS: magic={magic:#x}")
        major=bits(b,224,16); minor=bits(b,240,16)
        if (major,minor)!=(3,0): raise ValueError(f"expected SquashFS 3.0, got {major}.{minor}")
        return Super(bits(b,32,32),bits(b,344,64),bits(b,408,32),bits(b,440,32),bits(b,504,64),bits(b,696,64),bits(b,760,64),bits(b,824,64))
    def inode(self,ref:int):
        if ref in self.inode_cache:return self.inode_cache[ref]
        p=self.inodes.at_ref(ref); buf=bytes(self.inodes.flat[p:p+4096]); typ=bits(buf,0,4)
        base={"ref":ref,"type":typ,"mode":bits(buf,4,12),"uid":bits(buf,16,8),"guid":bits(buf,24,8),"mtime":bits(buf,32,32),"inode_number":bits(buf,64,32)}
        if typ==1:
            base.update(nlink=bits(buf,96,32),file_size=bits(buf,128,19),offset=bits(buf,147,13),start_block=bits(buf,160,32),parent=bits(buf,192,32),header=28)
        elif typ==8:
            base.update(nlink=bits(buf,96,32),file_size=bits(buf,128,27),offset=bits(buf,155,13),start_block=bits(buf,168,32),i_count=bits(buf,200,16),parent=bits(buf,216,32),header=31)
        elif typ==2:
            base.update(start_block=bits(buf,96,64),fragment=bits(buf,160,32),offset=bits(buf,192,32),file_size=bits(buf,224,32),header=32)
        elif typ==9:
            base.update(start_block=bits(buf,96,64),file_size=bits(buf,160,64),sparse=bits(buf,224,64),nlink=bits(buf,288,32),fragment=bits(buf,320,32),offset=bits(buf,352,32),xattr=bits(buf,384,32),header=52)
        elif typ in (3,10):
            base.update(nlink=bits(buf,96,32),symlink_size=bits(buf,128,16),header=18)
        else: base.update(header=12)
        self.inode_cache[ref]=base; return base
    def listdir(self,ino):
        if ino["type"] not in (1,8): raise ValueError("not directory")
        pos=self.dirs.at_block_offset(ino["start_block"],ino["offset"]); end=pos+ino["file_size"]
        out=[]; d=bytes(self.dirs.flat)
        while pos < end:
            if pos+9>end:break
            h=d[pos:pos+9]; pos+=9; count=bits(h,0,8)+1; start=bits(h,8,32); inode_base=bits(h,40,32)
            for _ in range(count):
                e=d[pos:pos+5]; pos+=5
                off=bits(e,0,13); typ=bits(e,13,3); size=bits(e,16,8)+1; delta=s16(bits(e,24,16))
                name=d[pos:pos+size].decode("utf-8","surrogateescape"); pos+=size
                out.append((name,(start<<16)|off,typ,inode_base+delta))
        return out
    def resolve(self,path:str):
        ino=self.inode(self.sb.root_inode)
        for part in pathlib.PurePosixPath(path).parts:
            if part in ("/",""):continue
            found=None
            for name,ref,typ,num in self.listdir(ino):
                if name==part:found=self.inode(ref);break
            if found is None:raise FileNotFoundError(path)
            ino=found
        return ino
    def read_file(self,ino):
        if ino["type"] not in (2,9):raise ValueError("not regular file")
        size=ino["file_size"]; fragment=ino["fragment"]; block_size=self.sb.block_size
        full=size//block_size; rem=size%block_size; stored_blocks=full+(1 if rem and fragment==0xffffffff else 0)
        p=self.inodes.at_ref(ino["ref"])+ino["header"]; sizes=[struct.unpack_from(">I",self.inodes.flat,p+i*4)[0] for i in range(stored_blocks)]
        src=ino["start_block"]; out=bytearray()
        for ent in sizes:
            csize=ent&0x00ffffff; raw=bool(ent&0x01000000); payload=self.image[src:src+csize];src+=csize
            out.extend(payload if raw else zlib.decompress(payload))
        if fragment!=0xffffffff:
            fstart,fsize,_=self.frag_entries[fragment]; raw=bool(fsize&0x01000000); csize=fsize&0x00ffffff; payload=self.image[fstart:fstart+csize]
            block=payload if raw else zlib.decompress(payload); out.extend(block[ino["offset"]:ino["offset"]+rem])
        return bytes(out[:size])

def main():
    ap=argparse.ArgumentParser();ap.add_argument("image",type=pathlib.Path);ap.add_argument("output",type=pathlib.Path);ap.add_argument("paths",nargs="*",default=TARGETS);ap.add_argument("--no-verify",action="store_true");args=ap.parse_args()
    fs=Squash3BE(args.image);args.output.mkdir(parents=True,exist_ok=True);manifest=[]
    for path in args.paths:
        data=fs.read_file(fs.resolve(path));out=args.output/pathlib.PurePosixPath(path).name;out.write_bytes(data);digest=hashlib.sha256(data).hexdigest();expected=EXPECTED.get(out.name)
        if not args.no_verify and expected and digest!=expected:raise SystemExit(f"hash mismatch {out.name}: {digest} != {expected}")
        manifest.append({"source_path":path,"output":str(out),"size":len(data),"sha256":digest,"verified":expected==digest if expected else None})
        print(f"{digest}  {out}")
    (args.output/"extraction-manifest.json").write_text(json.dumps({"image":str(args.image),"superblock":fs.sb.__dict__,"files":manifest},indent=2)+"\n")
if __name__=="__main__":main()
