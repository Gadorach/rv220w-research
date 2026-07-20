#!/usr/bin/env python3
"""Minimal read-only extractor for the RV220W's big-endian JFFS2 config partition.

Supports the node types and compression methods observed in the RV220W dump:
regular inode nodes, dirent nodes, cleanmarkers, uncompressed data, and zlib data.
It never modifies the source image. It is intentionally conservative and emits a JSON report.
"""
from __future__ import annotations
import argparse, json, os, pathlib, stat, struct, zlib
from dataclasses import dataclass, asdict
MAGIC=0x1985
DIRENT=0xE001
INODE=0xE002
CLEAN=0x2003

@dataclass
class InodeNode:
    pos:int; totlen:int; ino:int; version:int; mode:int; uid:int; gid:int; isize:int
    atime:int; mtime:int; ctime:int; offset:int; csize:int; dsize:int; compr:int; data:bytes
@dataclass
class DirentNode:
    pos:int; totlen:int; pino:int; version:int; ino:int; mctime:int; dtype:int; name:str

def u16(b,o): return struct.unpack_from('>H',b,o)[0]
def u32(b,o): return struct.unpack_from('>I',b,o)[0]
def align4(n): return (n+3)&~3

def parse(img:bytes):
    inodes=[]; dirents=[]; stats={'inode_nodes':0,'dirent_nodes':0,'cleanmarkers':0,'unknown_nodes':0,'bad_nodes':0,'compression':{}}
    p=0
    while p+12<=len(img):
        if img[p:p+4]==b'\xff\xff\xff\xff':
            p+=4; continue
        if u16(img,p)!=MAGIC:
            p+=4; continue
        ntype=u16(img,p+2); tot=u32(img,p+4)
        if tot<12 or p+tot>len(img): stats['bad_nodes']+=1; p+=4; continue
        if ntype==DIRENT and tot>=40:
            pino=u32(img,p+12); version=u32(img,p+16); ino=u32(img,p+20); mctime=u32(img,p+24)
            nsize=img[p+28]; dtype=img[p+29]
            name=img[p+40:p+40+nsize].decode('utf-8','surrogateescape')
            dirents.append(DirentNode(p,tot,pino,version,ino,mctime,dtype,name)); stats['dirent_nodes']+=1
        elif ntype==INODE and tot>=68:
            ino=u32(img,p+12); version=u32(img,p+16); mode=u32(img,p+20); uid=u16(img,p+24); gid=u16(img,p+26)
            isize=u32(img,p+28); atime=u32(img,p+32); mtime=u32(img,p+36); ctime=u32(img,p+40)
            off=u32(img,p+44); csize=u32(img,p+48); dsize=u32(img,p+52); compr=img[p+56]
            raw=img[p+68:p+68+csize]
            if compr==0: payload=raw
            elif compr==6: payload=zlib.decompress(raw)
            else: raise RuntimeError(f'unsupported JFFS2 compression {compr} at 0x{p:x}')
            if len(payload)!=dsize: raise RuntimeError(f'data size mismatch at 0x{p:x}: {len(payload)} != {dsize}')
            inodes.append(InodeNode(p,tot,ino,version,mode,uid,gid,isize,atime,mtime,ctime,off,csize,dsize,compr,payload))
            stats['inode_nodes']+=1; stats['compression'][str(compr)]=stats['compression'].get(str(compr),0)+1
        elif ntype==CLEAN: stats['cleanmarkers']+=1
        else: stats['unknown_nodes']+=1
        p+=align4(tot)
    return inodes,dirents,stats

def reconstruct(inodes,dirents,out:pathlib.Path):
    out.mkdir(parents=True,exist_ok=True)
    # Latest dirent wins. ino=0 deletes the name.
    latest={}
    for d in dirents:
        key=(d.pino,d.name)
        if key not in latest or d.version>latest[key].version: latest[key]=d
    latest={k:d for k,d in latest.items() if d.ino!=0}
    children={}
    for (pino,name),d in latest.items(): children.setdefault(pino,[]).append(d)
    byino={}
    for n in inodes: byino.setdefault(n.ino,[]).append(n)
    paths={1:out}
    unresolved=set(d.ino for d in latest.values())
    # Resolve directory graph iteratively.
    for _ in range(len(latest)+2):
        changed=False
        for (pino,name),d in latest.items():
            if d.ino in paths or pino not in paths: continue
            paths[d.ino]=paths[pino]/name; unresolved.discard(d.ino); changed=True
        if not changed: break
    report=[]
    for ino,path in sorted(paths.items(), key=lambda kv:(len(kv[1].parts),str(kv[1]))):
        nodes=sorted(byino.get(ino,[]),key=lambda n:n.version)
        mode=nodes[-1].mode if nodes else (stat.S_IFDIR|0o755)
        if stat.S_ISDIR(mode):
            path.mkdir(parents=True,exist_ok=True); typ='dir'; size=0
        elif stat.S_ISLNK(mode):
            buf=bytearray()
            final=nodes[-1].isize if nodes else 0
            for n in nodes:
                if len(buf)<n.offset+n.dsize: buf.extend(b'\0'*(n.offset+n.dsize-len(buf)))
                buf[n.offset:n.offset+n.dsize]=n.data
                if len(buf)>n.isize: del buf[n.isize:]
            target=bytes(buf[:final]).decode('utf-8','surrogateescape')
            path.parent.mkdir(parents=True,exist_ok=True)
            try: path.unlink()
            except FileNotFoundError: pass
            os.symlink(target,path); typ='symlink'; size=len(target)
        elif stat.S_ISREG(mode):
            buf=bytearray(); final=nodes[-1].isize if nodes else 0
            for n in nodes:
                need=n.offset+n.dsize
                if len(buf)<need: buf.extend(b'\0'*(need-len(buf)))
                buf[n.offset:need]=n.data
                if len(buf)>n.isize: del buf[n.isize:]
            path.parent.mkdir(parents=True,exist_ok=True); path.write_bytes(bytes(buf[:final])); typ='file'; size=final
        else:
            typ='special'; size=0
        if not path.is_symlink():
            try: os.chmod(path,stat.S_IMODE(mode))
            except PermissionError: pass
        report.append({'inode':ino,'path':str(path.relative_to(out)) if path!=out else '.','type':typ,'size':size,'mode':oct(stat.S_IMODE(mode)),'node_versions':[n.version for n in nodes]})
    return report,sorted(unresolved)

def main():
    ap=argparse.ArgumentParser(); ap.add_argument('image',type=pathlib.Path); ap.add_argument('output',type=pathlib.Path); ap.add_argument('--report',type=pathlib.Path)
    a=ap.parse_args(); img=a.image.read_bytes(); ino,de,stats=parse(img); tree,unresolved=reconstruct(ino,de,a.output)
    result={'source':str(a.image),'source_size':len(img),'stats':stats,'tree':tree,'unresolved_inodes':unresolved}
    rp=a.report or a.output.with_suffix('.json'); rp.write_text(json.dumps(result,indent=2)+'\n')
    print(json.dumps({'stats':stats,'tree_entries':len(tree),'unresolved':unresolved},indent=2))
if __name__=='__main__': main()
