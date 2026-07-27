#!/usr/bin/env python3
"""Build a conservative RV220W reference DTB from the exact generic OpenWrt DTB."""
from __future__ import annotations
import argparse, json, struct, hashlib
from dataclasses import dataclass, field
from pathlib import Path
from collections import OrderedDict

FDT_MAGIC=0xd00dfeed; BEGIN=1; END_NODE=2; PROP=3; NOP=4; END=9

def align4(x): return (x+3)&~3
def be32(*xs): return b''.join(struct.pack('>I',x & 0xffffffff) for x in xs)
def sprop(*xs): return b''.join(x.encode()+b'\0' for x in xs)
@dataclass
class Node:
    name:str
    props:OrderedDict[str,bytes]=field(default_factory=OrderedDict)
    children:list['Node']=field(default_factory=list)
    def child(self,name):
        return next((x for x in self.children if x.name==name),None)
    def path(self,path):
        n=self
        for p in [x for x in path.split('/') if x]:
            n=n.child(p)
            if n is None:return None
        return n
    def remove(self,name): self.children=[x for x in self.children if x.name!=name]
    def add(self,n): self.remove(n.name); self.children.append(n); return n

def parse(path:Path):
    b=path.read_bytes(); h=struct.unpack('>10I',b[:40]);
    if h[0]!=FDT_MAGIC: raise ValueError('bad magic')
    _,total,off_s,off_str,off_rsv,ver,last,cpu,size_str,size_s=h
    strings=b[off_str:off_str+size_str]
    def pname(off): return strings[off:strings.index(b'\0',off)].decode()
    pos=off_s
    def node():
        nonlocal pos
        if struct.unpack_from('>I',b,pos)[0]!=BEGIN: raise ValueError('expected begin')
        pos+=4; e=b.index(b'\0',pos); name=b[pos:e].decode(); pos=align4(e+1); n=Node(name)
        while True:
            tok=struct.unpack_from('>I',b,pos)[0]; pos+=4
            if tok==PROP:
                ln,no=struct.unpack_from('>II',b,pos); pos+=8; n.props[pname(no)]=b[pos:pos+ln]; pos=align4(pos+ln)
            elif tok==BEGIN: pos-=4; n.children.append(node())
            elif tok==END_NODE:return n
            elif tok==NOP:continue
            else: raise ValueError(f'unexpected token {tok} at {pos-4:x}')
    root=node();
    if struct.unpack_from('>I',b,pos)[0]!=END: raise ValueError('missing end')
    return root, {'version':ver,'last_comp_version':last,'boot_cpuid_phys':cpu}

def serialize(root:Node,meta):
    names=OrderedDict()
    def collect(n):
        for k in n.props:names.setdefault(k,None)
        for c in n.children:collect(c)
    collect(root); sb=bytearray()
    for k in names:names[k]=len(sb);sb+=k.encode()+b'\0'
    st=bytearray()
    def emit(n):
        st.extend(be32(BEGIN)); st.extend(n.name.encode()+b'\0'); st.extend(b'\0'*(align4(len(st))-len(st)))
        for k,v in n.props.items():
            st.extend(be32(PROP,len(v),names[k]));st.extend(v);st.extend(b'\0'*(align4(len(st))-len(st)))
        for c in n.children:emit(c)
        st.extend(be32(END_NODE))
    emit(root);st.extend(be32(END))
    rsv=b'\0'*16; off_rsv=40; off_s=off_rsv+len(rsv); off_str=off_s+len(st); total=off_str+len(sb)
    hdr=struct.pack('>10I',FDT_MAGIC,total,off_s,off_str,off_rsv,17,16,meta.get('boot_cpuid_phys',0),len(sb),len(st))
    return hdr+rsv+st+sb

def max_phandle(n):
    vals=[]
    def walk(x):
        for k in ('phandle','linux,phandle'):
            if k in x.props and len(x.props[k])==4:vals.append(struct.unpack('>I',x.props[k])[0])
        for c in x.children:walk(c)
    walk(n); return max(vals,default=0)

def main():
    ap=argparse.ArgumentParser();ap.add_argument('input');ap.add_argument('output');ap.add_argument('--report',required=True);a=ap.parse_args()
    root,meta=parse(Path(a.input)); soc=root.path('/soc@0'); assert soc
    root.props['model']=sprop('Cisco RV220W'); root.props['compatible']=sprop('cisco,rv220w','cavium,octeon-3860')
    # Prune generic-board devices and PHY fiction.
    smi0=soc.child('mdio@1180000001800'); assert smi0
    smi0.children=[]; smi0.props['status']=sprop('okay')
    sw=Node('switch@1e'); sw.props['compatible']=sprop('brcm,bcm53115'); sw.props['reg']=be32(0x1e); sw.props['status']=sprop('disabled'); smi0.add(sw)
    for n in ['mdio@1180000001900','ethernet@1070000100000','ethernet@1070000100800','i2c@1180000001200','serial@1180000000c00','serial@1180000000400','uctl@118006f000000']:
        soc.remove(n)
    twsi=soc.child('i2c@1180000001000'); twsi.children=[]; twsi.props['status']=sprop('okay')
    uart=soc.child('serial@1180000000800'); uart.props['clock-frequency']=be32(400000000); uart.props['status']=sprop('okay')
    pip=soc.child('pip@11800a0000000'); pip.props['status']=sprop('okay')
    i0=pip.child('interface@0'); i0.props['status']=sprop('okay')
    i0.children=[c for c in i0.children if c.name in ('ethernet@0','ethernet@1','ethernet@2')]
    for idx,name in enumerate(('ethernet@0','ethernet@1','ethernet@2')):
        e=i0.child(name); assert e; e.props['status']=sprop('okay')
        for p in ['phy-handle','cavium,alt-phy-handle']:e.props.pop(p,None)
        for prop in ('rx-delay', 'tx-delay'):
            e.props.pop(prop, None)
        e.remove('fixed-link')
    i1=pip.child('interface@1');
    if i1:i1.children=[]
    boot=soc.child('bootbus@1180000000000'); boot.props['status']=sprop('okay'); nor=boot.child('nor@0,0'); assert nor; boot.children=[nor]; nor.props['status']=sprop('okay')
    usbn=soc.child('usbn@1180068000000');usbn.props['status']=sprop('disabled')
    # Root aliases and chosen.
    aliases=root.child('aliases') or root.add(Node('aliases'))
    aliases.props=OrderedDict((k,v) for k,v in aliases.props.items() if k in ('pip','smi0','twsi0','uart0'))
    aliases.props['uart0']=sprop('/soc@0/serial@1180000000800')
    aliases.props['serial0']=sprop('/soc@0/serial@1180000000800')
    aliases.props['ethernet0']=sprop('/soc@0/pip@11800a0000000/interface@0/ethernet@0')
    aliases.props['ethernet1']=sprop('/soc@0/pip@11800a0000000/interface@0/ethernet@1')
    aliases.props['ethernet2']=sprop('/soc@0/pip@11800a0000000/interface@0/ethernet@2')
    chosen=root.child('chosen') or root.add(Node('chosen')); chosen.props['stdout-path']=sprop('serial0:115200n8')
    # Disabled, evidence-backed reset/recovery button on GPIO 1 active low.
    gpio=soc.child('gpio-controller@1070000000800'); assert gpio
    ph=max_phandle(root)+1
    if 'phandle' in gpio.props: ph=struct.unpack('>I',gpio.props['phandle'])[0]
    else: gpio.props['phandle']=be32(ph)
    keys=Node('rv220w-reset-keys');keys.props['compatible']=sprop('gpio-keys');keys.props['status']=sprop('disabled')
    key=Node('reset');key.props['label']=sprop('reset/recovery');key.props['linux,code']=be32(0x198);key.props['gpios']=be32(ph,1,1);key.props['debounce-interval']=be32(60);keys.add(key);root.add(keys)
    out=serialize(root,meta);Path(a.output).write_bytes(out)
    # Parse the output again as structural validation.
    check,_=parse(Path(a.output)); assert check.props['model']==sprop('Cisco RV220W')
    rep={'input':str(Path(a.input)),'input_sha256':hashlib.sha256(Path(a.input).read_bytes()).hexdigest(),'output':str(Path(a.output)),'output_sha256':hashlib.sha256(out).hexdigest(),'output_size':len(out),'model':'Cisco RV220W','compatible':['cisco,rv220w','cavium,octeon-3860'],'usb':'disabled','dt_bootbus':'v1.3.0 arrangement restored; inherited nor@0,0 enabled as legacy Octeon phys_mapped_flash trigger; redundant generic probe accepted','switch':{'compatible':'brcm,bcm53115','mdio_address':'0x1e','status':'disabled'},'reset':{'gpio':1,'active_low':True,'status':'disabled'},'ethernet':{'interface':0,'ports':[0,1,2],'link_policy':'legacy Octeon board helper retained; no speculative fixed-link'},'validation':'FDT v17 serialized and parsed back successfully'}
    Path(a.report).write_text(json.dumps(rep,indent=2)+'\n')
if __name__=='__main__':main()
