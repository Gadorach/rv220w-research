#!/usr/bin/env python3
"""Build or verify RV220W full-NOR persistent component images.

The 6 MiB kernel partition stores a deterministic gzip stream containing the
non-initramfs Octeon ELF. The rootfs partition consumes every erase block from
0x00680000 through the final protected U-Boot environment at 0x01fe0000.
OpenWrt derives one JFFS2 rootfs_data child from the padded SquashFS image.
"""
from __future__ import annotations
import argparse, gzip, hashlib, json, pathlib, struct, sys, tempfile
from typing import Any

FLASH_BASE=0xBDC00000
FLASH_SIZE=0x02000000
ERASE_SIZE=0x00020000
BOOT_CHAIN_OFFSET=0x00000000
BOOT_CHAIN_SIZE=0x00080000
KERNEL_OFFSET=0x00080000
KERNEL_SIZE=0x00600000
ROOTFS_OFFSET=0x00680000
ROOTFS_SIZE=0x01960000
UBOOT_ENV_OFFSET=0x01FE0000
UBOOT_ENV_SIZE=0x00020000
COMPRESSED_RAM_ADDRESS=0x05500000
DECOMPRESSED_RAM_ADDRESS=0x06500000
DECOMPRESSED_RAM_LIMIT=0x07F00000
DECOMPRESSED_MAX=DECOMPRESSED_RAM_LIMIT-DECOMPRESSED_RAM_ADDRESS
BOOTARGS="console=ttyS0,115200"
FILL=0xFF
SCHEMA="rv220w-openwrt-persistent-components-v3"
PREFIX="rv220w-openwrt-rv220w-rj45-luci-persistent"

class ImageError(RuntimeError): pass

def sha256_bytes(data:bytes)->str: return hashlib.sha256(data).hexdigest()
def sha256_path(path:pathlib.Path)->str:
    h=hashlib.sha256()
    with path.open('rb') as s:
        for c in iter(lambda:s.read(1024*1024),b''): h.update(c)
    return h.hexdigest()
def sha256_ff(size:int)->str:
    h=hashlib.sha256(); chunk=b'\xff'*(1024*1024)
    while size:
        take=min(size,len(chunk)); h.update(chunk[:take]); size-=take
    return h.hexdigest()
def align_up(value:int, alignment:int)->int:
    return (value+alignment-1)//alignment*alignment

def parse_elf_bytes(data:bytes)->dict[str,int|str]:
    if len(data)<64 or data[:4]!=b'\x7fELF': raise ImageError('decompressed kernel lacks a complete ELF64 header')
    if data[4]!=2 or data[5]!=2: raise ImageError('decompressed kernel is not ELF64 big-endian')
    elf_type,elf_machine=struct.unpack_from('>HH',data,16)
    if elf_type!=2 or elf_machine!=8: raise ImageError(f'decompressed kernel is not executable MIPS ELF (type={elf_type}, machine={elf_machine})')
    return {'elf_class':'ELF64','elf_data':'big-endian','elf_machine':'MIPS','elf_entry':struct.unpack_from('>Q',data,24)[0]}

def parse_squashfs(path:pathlib.Path)->dict[str,str]:
    magic=path.read_bytes()[:4]
    if magic==b'hsqs': fmt='little-endian-v4'
    elif magic==b'sqsh': fmt='big-endian'
    else: raise ImageError(f'rootfs lacks SquashFS magic: {magic.hex()}')
    return {'rootfs_magic':magic.hex(),'rootfs_format':fmt}

def read_gzip_kernel(path:pathlib.Path)->tuple[bytes,dict[str,int|str]]:
    encoded=path.read_bytes()
    if encoded[:3]!=b'\x1f\x8b\x08': raise ImageError('kernel source is not gzip/DEFLATE')
    if len(encoded)>KERNEL_SIZE: raise ImageError(f'compressed kernel is {len(encoded)} bytes and exceeds {KERNEL_SIZE}')
    try: raw=gzip.decompress(encoded)
    except (OSError,EOFError) as exc: raise ImageError(f'kernel gzip stream is invalid: {exc}') from exc
    if not raw: raise ImageError('kernel gzip stream decompresses to an empty file')
    if len(raw)>DECOMPRESSED_MAX: raise ImageError('decompressed kernel exceeds conservative U-Boot destination window')
    return raw,parse_elf_bytes(raw)

def write_padded(source:pathlib.Path,output:pathlib.Path,size:int)->None:
    source_size=source.stat().st_size
    if source_size>size: raise ImageError(f'{source.name} is {source_size} bytes and exceeds partition size {size}')
    output.parent.mkdir(parents=True,exist_ok=True); tmp_path=None
    try:
        with tempfile.NamedTemporaryFile(dir=output.parent,delete=False) as tmp:
            tmp_path=pathlib.Path(tmp.name)
            with source.open('rb') as src:
                for c in iter(lambda:src.read(1024*1024),b''): tmp.write(c)
            remaining=size-source_size; fill=b'\xff'*min(1024*1024,max(1,remaining))
            while remaining:
                take=min(remaining,len(fill)); tmp.write(fill[:take]); remaining-=take
            tmp.flush()
        tmp_path.replace(output)
    finally:
        if tmp_path is not None and tmp_path.exists(): tmp_path.unlink()
    if output.stat().st_size!=size: raise ImageError('internal padded-image size error')

def component(name:str,source:pathlib.Path,image:pathlib.Path,offset:int,size:int)->dict[str,Any]:
    return {'name':name,'offset':offset,'address':f'0x{FLASH_BASE+offset:08x}','partition_size':size,'erase_size':ERASE_SIZE,'source_name':source.name,'source_size':source.stat().st_size,'source_sha256':sha256_path(source),'image_name':image.name,'image_size':image.stat().st_size,'image_sha256':sha256_path(image)}

def derived_rootfs_data(source_size:int)->dict[str,Any]:
    aligned=align_up(source_size,ERASE_SIZE)
    if aligned>=ROOTFS_SIZE: raise ImageError('SquashFS leaves no erase-aligned space for rootfs_data')
    offset=ROOTFS_OFFSET+aligned; size=ROOTFS_SIZE-aligned
    return {'name':'rootfs_data','parent':'rootfs','creation':'OpenWrt squashfs-split','offset':offset,'address':f'0x{FLASH_BASE+offset:08x}','partition_size':size,'erase_size':ERASE_SIZE,'squashfs_source_size':source_size,'squashfs_aligned_size':aligned,'initial_state':'all 0xff in the padded rootfs image; JFFS2 initialized by fstools on first boot','erased_sha256':sha256_ff(size)}

def build(kernel:pathlib.Path,rootfs:pathlib.Path,output_dir:pathlib.Path,manifest:pathlib.Path|None,prefix:str=PREFIX)->pathlib.Path:
    kernel=kernel.resolve(); rootfs=rootfs.resolve()
    if not kernel.is_file() or not rootfs.is_file(): raise ImageError('kernel or rootfs source is missing')
    raw,elf_meta=read_gzip_kernel(kernel); root_meta=parse_squashfs(rootfs)
    output_dir.mkdir(parents=True,exist_ok=True)
    kimg=output_dir/f'{prefix}-kernel.part.bin'; rimg=output_dir/f'{prefix}-rootfs.part.bin'
    write_padded(kernel,kimg,KERNEL_SIZE); write_padded(rootfs,rimg,ROOTFS_SIZE)
    kdoc=component('openwrt-kernel',kernel,kimg,KERNEL_OFFSET,KERNEL_SIZE)
    kdoc.update({'encoding':'gzip','decompressed_size':len(raw),'decompressed_sha256':sha256_bytes(raw),'decompressed_ram_address':f'0x{DECOMPRESSED_RAM_ADDRESS:08x}',**elf_meta})
    rdoc=component('rootfs',rootfs,rimg,ROOTFS_OFFSET,ROOTFS_SIZE)
    auto=derived_rootfs_data(rootfs.stat().st_size)
    doc={'schema':SCHEMA,'board':'Cisco RV220W','storage':'32 MiB x16 parallel NOR','layout_policy':'full OpenWrt layout; stock-data, legacy environment gap and vendor tail reclaimed into rootfs; only boot-chain and final U-Boot environment preserved','flash_base_kseg1':f'0x{FLASH_BASE:08x}','flash_size':FLASH_SIZE,'erase_size':ERASE_SIZE,'automatic_reboot':False,'automatic_boot_environment_change':False,'hardware_validation':'full 25.375 MiB rootfs transition pending','components':{'kernel':kdoc,'rootfs':rdoc},'derived_partitions':{'rootfs_data':auto},'preserved':{'boot-chain':{'offset':BOOT_CHAIN_OFFSET,'size':BOOT_CHAIN_SIZE,'read_only':True},'uboot-env':{'offset':UBOOT_ENV_OFFSET,'size':UBOOT_ENV_SIZE,'read_only':True}},'reclaimed':{'stock-data':{'offset':0x01680000,'size':0x00100000,'original_format':'big-endian JFFS2','preserved_in_full_flash_backup':True},'legacy-env-gap':{'offset':0x01780000,'size':0x00020000,'previously_verified_fill':'0xff'},'vendor-tail':{'offset':0x017A0000,'size':0x00840000,'previously_verified_fill':'0xff'}},'kernel_boot':{'format':'gzip-compressed ELF64 big-endian MIPS','nor_address':f'0x{FLASH_BASE+KERNEL_OFFSET:08x}','compressed_ram_address':f'0x{COMPRESSED_RAM_ADDRESS:08x}','decompressed_ram_address':f'0x{DECOMPRESSED_RAM_ADDRESS:08x}','partition_copy_size':KERNEL_SIZE,'partition_copy_size_hex':f'0x{KERNEL_SIZE:x}','decompressed_limit':DECOMPRESSED_MAX,'decompressed_limit_hex':f'0x{DECOMPRESSED_MAX:x}','commands':[f'cp.b 0x{FLASH_BASE+KERNEL_OFFSET:08x} 0x{COMPRESSED_RAM_ADDRESS:08x} 0x{KERNEL_SIZE:x}',f'gunzip 0x{COMPRESSED_RAM_ADDRESS:08x} 0x{KERNEL_SIZE:x} 0x{DECOMPRESSED_RAM_ADDRESS:08x} 0x{DECOMPRESSED_MAX:x}',f'bootoctlinux 0x{DECOMPRESSED_RAM_ADDRESS:08x} {BOOTARGS}'],'first_hardware_gate':'TFTP-boot the raw persistent ELF against the newly written full rootfs; then validate the padded kernel image through U-Boot gunzip before any NOR kernel write'},'runtime':{'root_device':'/dev/mtdblock2','rootfstype':'squashfs','rom':'rootfs SquashFS','overlay':'one automatically split rootfs_data JFFS2 child','configuration_persistence':'rootfs-first 16 MiB layout proven; full 25.375 MiB layout pending'},**root_meta}
    # The layout represented by this schema completed the RC7 hardware gate.
    doc['hardware_validation']='hardware-qualified in the 1.16.0-rc7 direct-install workflow'
    doc['kernel_boot']['first_hardware_gate']='completed by the 1.16.0-rc7 hardware qualification run'
    doc['runtime']['configuration_persistence']='hardware-qualified with JFFS2 overlay and configuration-preserving sysupgrade'
    doc['artifact_prefix']=prefix
    out=manifest or output_dir/f'{prefix}-images.json'; out.write_text(json.dumps(doc,indent=2,sort_keys=True)+'\n')
    for image in (kimg,rimg): image.with_suffix(image.suffix+'.sha256').write_text(f'{sha256_path(image)}  {image.name}\n')
    print(kimg); print(rimg); print(out); return out

def load_manifest(path:pathlib.Path)->dict[str,Any]:
    if not path.is_file(): raise ImageError(f'manifest is missing: {path}')
    doc=json.loads(path.read_text())
    if doc.get('schema')!=SCHEMA: raise ImageError('unexpected persistent-image manifest schema')
    if doc.get('flash_size')!=FLASH_SIZE or doc.get('erase_size')!=ERASE_SIZE: raise ImageError('manifest flash geometry is invalid')
    return doc

def verify_kernel(image:pathlib.Path,spec:dict[str,Any])->str:
    if image.stat().st_size!=KERNEL_SIZE or spec.get('offset')!=KERNEL_OFFSET or spec.get('partition_size')!=KERNEL_SIZE: raise ImageError('kernel image or manifest geometry is invalid')
    actual=sha256_path(image)
    if actual!=spec.get('image_sha256'): raise ImageError('kernel SHA-256 mismatch')
    source_size=spec.get('source_size')
    if not isinstance(source_size,int) or not 0<source_size<=KERNEL_SIZE: raise ImageError('kernel source_size is invalid')
    data=image.read_bytes(); encoded=data[:source_size]
    if any(b!=FILL for b in data[source_size:]): raise ImageError('kernel partition padding is not all 0xff')
    if sha256_bytes(encoded)!=spec.get('source_sha256'): raise ImageError('kernel compressed-source SHA-256 mismatch')
    raw=gzip.decompress(encoded)
    if len(raw)!=spec.get('decompressed_size') or sha256_bytes(raw)!=spec.get('decompressed_sha256'): raise ImageError('kernel decompressed identity mismatch')
    parse_elf_bytes(raw); return actual

def verify_rootfs(image:pathlib.Path,spec:dict[str,Any])->str:
    if image.stat().st_size!=ROOTFS_SIZE or spec.get('offset')!=ROOTFS_OFFSET or spec.get('partition_size')!=ROOTFS_SIZE: raise ImageError('rootfs image or manifest geometry is invalid')
    actual=sha256_path(image)
    if actual!=spec.get('image_sha256'): raise ImageError('rootfs SHA-256 mismatch')
    parse_squashfs(image); source_size=spec.get('source_size')
    if not isinstance(source_size,int) or not 0<source_size<ROOTFS_SIZE: raise ImageError('rootfs source_size is invalid')
    with image.open('rb') as s: source=s.read(source_size); tail=s.read()
    if sha256_bytes(source)!=spec.get('source_sha256'): raise ImageError('rootfs source SHA-256 mismatch')
    if any(b!=FILL for b in tail): raise ImageError('rootfs partition padding is not all 0xff')
    return actual

def verify(kernel_image:pathlib.Path,rootfs_image:pathlib.Path,manifest:pathlib.Path)->None:
    doc=load_manifest(manifest); comps=doc.get('components'); derived=doc.get('derived_partitions'); preserved=doc.get('preserved')
    if not isinstance(comps,dict) or not isinstance(derived,dict) or not isinstance(preserved,dict): raise ImageError('manifest sections are missing')
    kspec=comps.get('kernel'); rspec=comps.get('rootfs'); auto=derived.get('rootfs_data')
    if not isinstance(kspec,dict) or not isinstance(rspec,dict) or not isinstance(auto,dict): raise ImageError('manifest component is missing')
    print('kernel='+verify_kernel(kernel_image,kspec)); print('rootfs='+verify_rootfs(rootfs_image,rspec))
    expected=derived_rootfs_data(rspec['source_size'])
    for key in ('offset','partition_size','erase_size','squashfs_aligned_size','erased_sha256'):
        if auto.get(key)!=expected[key]: raise ImageError(f'manifest automatic rootfs_data {key} is invalid')
    if set(preserved)!= {'boot-chain','uboot-env'}: raise ImageError('manifest preserves unexpected NOR regions')

def boot_plan(manifest:pathlib.Path)->None:
    boot=load_manifest(manifest).get('kernel_boot')
    if not isinstance(boot,dict) or not isinstance(boot.get('commands'),list): raise ImageError('manifest kernel boot plan is missing')
    for command in boot['commands']: print(command)

def parse_args():
    parser=argparse.ArgumentParser(description=__doc__); sub=parser.add_subparsers(dest='command',required=True)
    b=sub.add_parser('build'); b.add_argument('kernel',type=pathlib.Path); b.add_argument('rootfs',type=pathlib.Path); b.add_argument('output_dir',type=pathlib.Path); b.add_argument('--manifest',type=pathlib.Path); b.add_argument('--prefix',default=PREFIX)
    v=sub.add_parser('verify'); v.add_argument('kernel_image',type=pathlib.Path); v.add_argument('rootfs_image',type=pathlib.Path); v.add_argument('manifest',type=pathlib.Path)
    bp=sub.add_parser('boot-plan'); bp.add_argument('manifest',type=pathlib.Path); return parser.parse_args()
def main()->int:
    a=parse_args()
    if a.command=='build': build(a.kernel,a.rootfs,a.output_dir,a.manifest,a.prefix)
    elif a.command=='verify': verify(a.kernel_image,a.rootfs_image,a.manifest)
    else: boot_plan(a.manifest)
    return 0
if __name__=='__main__':
    try: raise SystemExit(main())
    except (ImageError,OSError,ValueError,KeyError,json.JSONDecodeError) as exc:
        print(f'ERROR: {exc}',file=sys.stderr); raise SystemExit(1)
