#!/usr/bin/env python3
from __future__ import annotations
import csv, hashlib, json, re, shutil
from pathlib import Path
from collections import Counter

ROOT=Path('/mnt/data/rv220w-stock-modules-ghidra-annotated-v1.0.0')
MODULES=['mii','bcm5398','scm-led','push_button','cavium-ethernet']

def read_tsv(path):
    with path.open(encoding='utf-8', errors='replace') as f:
        return list(csv.DictReader(f, delimiter='\t'))

def parse_undef(path):
    out=set()
    rx=re.compile(r'^\s*\d+:\s+[0-9a-fA-F]+\s+\d+\s+\S+\s+\S+\s+\S+\s+UND\s+(\S+)')
    for line in path.read_text(errors='replace').splitlines():
        m=rx.match(line)
        if m and m.group(1): out.add(m.group(1))
    return out

def c_calls(text, current, known, imports):
    calls=[]
    # Ghidra's unresolved-indirect notation preserves imported symbol identity.
    calls += re.findall(r'\(\*\(code \*\)&([A-Za-z_][A-Za-z0-9_]*)\)\s*\(', text)
    # Direct calls to locally named functions.
    for n in known:
        if n == current: continue
        if re.search(r'(?<![A-Za-z0-9_])'+re.escape(n)+r'\s*\(', text): calls.append(n)
    # Imports can occasionally appear as direct names.
    for n in imports:
        if re.search(r'(?<![A-Za-z0-9_])'+re.escape(n)+r'\s*\(', text): calls.append(n)
    return Counter(calls)

def parse_annotation(text):
    def one(label, default=''):
        m=re.search(r'^ \* '+re.escape(label)+r':\s*(.*)$', text, re.M)
        if not m: m=re.search(r'^\s*'+re.escape(label)+r':\s*(.*)$', text, re.M)
        return m.group(1).strip() if m else default
    return {
        'subsystem': one('Subsystem'),
        'evidence': one('Evidence class'),
        'confidence': one('Confidence'),
        'interpretation': one('Interpretation'),
    }

for module in MODULES:
    ex=ROOT/'exports'/module
    funcs=read_tsv(ex/'functions.tsv')
    names={r['name'] for r in funcs}
    imports=parse_undef(ROOT/'reports/source-symbols'/f'{module}.symbols.txt')
    rows=[]
    ann=[]
    for r in funcs:
        cpath=ex/r['c_file']
        text=cpath.read_text(errors='replace')
        meta=parse_annotation(text)
        calls=c_calls(text, r['name'], names, imports)
        for callee,count in sorted(calls.items()):
            kind='local' if callee in names else ('kernel-or-module-import' if callee in imports else 'unresolved-symbol')
            rows.append([r['entry'],r['name'],callee,kind,str(count)])
        ann.append((r,meta,calls))
    with (ex/'decompiler-callgraph.tsv').open('w',newline='',encoding='utf-8') as f:
        w=csv.writer(f,delimiter='\t'); w.writerow(['caller_entry','caller_name','callee_name','callee_kind','occurrences']); w.writerows(rows)
    # Helpful imported-symbol inventory.
    with (ex/'imported-symbols.txt').open('w',encoding='utf-8') as f:
        for n in sorted(imports): f.write(n+'\n')
    md=[f'# {module}.ko — per-function annotations','',
        '> All C is Ghidra reconstruction, not original Cisco source. Confidence is deliberately conservative.','.']
    md[-1]=''
    for r,meta,calls in ann:
        md += [f"## `{r['name']}` @ `0x{r['entry']}`",'',
               f"- **Subsystem:** {meta['subsystem'] or r['subsystem']}",
               f"- **Evidence:** {meta['evidence'] or r['evidence']}",
               f"- **Confidence:** {meta['confidence'] or 'not separately classified'}",
               f"- **Interpretation:** {meta['interpretation'] or 'See reconstructed C and assembly.'}",
               f"- **Decompiler:** {r['decompile']}; reconstructed C SHA-256 `{r['decompile_sha256']}`",
               f"- **Artifacts:** `{r['c_file']}`, `{r['asm_file']}`"]
        if calls:
            md.append('- **Recognized calls:** '+', '.join(f'`{k}` ×{v}' for k,v in sorted(calls.items())))
        else:
            md.append('- **Recognized calls:** none; relocatable MIPS/GOT indirection may hide additional edges')
        md.append('')
    (ex/'FUNCTION-ANNOTATIONS.md').write_text('\n'.join(md),encoding='utf-8')

# Rename relocation-derived reports to avoid claiming semantic call edges.
for p in ROOT.glob('reports/*-relocation-callgraph.tsv'):
    q=p.with_name(p.name.replace('-relocation-callgraph.tsv','-r_mips_26-control-transfers.tsv'))
    if q.exists(): q.unlink()
    p.rename(q)

# Top-level result report.
counts={}
for m in MODULES:
    s={r['key']:r['value'] for r in read_tsv(ROOT/'exports'/m/'summary.tsv')}
    counts[m]={k:int(s[k]) for k in ['function_count','decompile_success','decompile_failure']}
total=sum(v['function_count'] for v in counts.values())
results=f'''# RV220W stock module reverse-engineering results

## Scope

Five stock Linux 2.6.21.7 Cavium/Octeon modules were extracted from the preserved RV220W SquashFS 3.0 big-endian root filesystem and imported into Ghidra 12.1.2 as MIPS64 big-endian relocatable ELFs.

| Module | Functions | Reconstructed C | Failures |
|---|---:|---:|---:|
'''
for m in MODULES:
    v=counts[m]; results+=f"| `{m}.ko` | {v['function_count']} | {v['decompile_success']} | {v['decompile_failure']} |\n"
results+=f"| **Total** | **{total}** | **{sum(v['decompile_success'] for v in counts.values())}** | **{sum(v['decompile_failure'] for v in counts.values())}** |\n"
results+='''

Every recovered function has an embedded Ghidra comment with subsystem, evidence class, confidence, interpretation, and safety limits. Each function also has standalone reconstructed C and assembly exports. Compiler-emitted `.pdr` records restored 55 otherwise-missing function boundaries; two were named through `mii.ko` export metadata and 53 remain conservatively named local helpers.

## Hardware-relevant findings

### BCM53115 access and WAN policy

- `mii_phy_read()` and `mii_phy_write()` wrap Octeon MDIO bus 0 with bottom-half exclusion.
- `miiSwitchRegisterRead()` and `miiSwitchRegisterWrite()` access Broadcom pseudo-PHY address `0x1e`, using MDIO register `0x10` for page selection, `0x11` for command/address, and `0x18`–`0x1b` as the data window.
- The transaction timeout is based on `jiffies + 0x19`.
- `bcm5398.ko` recognizes switch strings `bcm5398`, `bcm5395`, and `bcm53115`; its module parameters include `wanportNo`, `privlegedID`, and `bcmswitch`.
- The module chooses a default WAN-port number of 8 for one recognized variant and 5 for another. This is strong evidence about internal Broadcom port numbering, but the correct RV220W branch must be tied to the runtime `bcmswitch` value before encoding a DSA port map.
- `configWanPort()` applies special state through switch page 2 registers `0x10`, `0x12`, and `0x1c`.

### Octeon Ethernet and switch tagging

- `cavium-ethernet.ko` contains the vendor MDIO implementation, RGMII initialization, receive tasklet/interrupt path, transmit paths, and Broadcom tag add/delete routines.
- `brcmTagAdd()` and `brcmTagDelete()` confirm the stock CPU/switch path uses a vendor Broadcom tag format.
- Vendor hardware offload/fast-forward code is substantial but is not required for first-stage upstream OpenWrt support.

### LEDs and reset button

- `scm-led.ko` directly drives Octeon GPIO set/clear registers for software-controlled LEDs.
- `blink_wlan()` selects logical LED record 4, making it the leading WIRELESS-indicator path.
- The five RJ45 link/activity indicators are more likely driven by the BCM53115 hardware LED engine, consistent with their correct operation after U-Boot initializes the switch.
- `push_button.ko:set_input()` configures GPIO candidates 5, 6, 11, 12, and 13 through the vendor input helper. This is a candidate set, not a definitive single reset pin.
- The recovered timer callback invokes `led_blink(2,1,1,1)` after a press-duration counter exceeds 100 ticks.

## Limits

This package does not claim original source recovery. Types, structure layouts, indirect-call edges, local names, and some control flow remain uncertain because these are old relocatable MIPS modules with vendor SDK code and incomplete type information. Constants and register interpretations are annotated only where supported by retained names, strings, relocations, or visible operations.
'''
(ROOT/'RESULTS.md').write_text(results,encoding='utf-8')
