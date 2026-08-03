#!/usr/bin/env python3
from __future__ import annotations
import pathlib, subprocess, tempfile, textwrap
ROOT=pathlib.Path(__file__).resolve().parents[1]
STAGE=ROOT/'stage2'
HARNESS=r'''
#include <stdio.h>
#include <string.h>
#include "include/types.h"
#include "include/crc32.h"
#include "include/sha256.h"
void *mem_copy(void *d,const void *s,usize n){return memcpy(d,s,n);}
void *mem_set(void *d,int v,usize n){return memset(d,v,n);}
int mem_compare(const void*a,const void*b,usize n){return memcmp(a,b,n);}
static void hex(const u8*d){for(int i=0;i<32;i++)printf("%02x",d[i]);puts("");}
int main(void){u8 d[32]; const char*s="abc"; sha256_compute(s,3,d); hex(d); printf("%08x\n",crc32_compute("123456789",9));return 0;}
'''

def main():
    with tempfile.TemporaryDirectory() as td:
        td=pathlib.Path(td); (td/'h.c').write_text(HARNESS)
        exe=td/'h'
        subprocess.run(['cc','-std=c99','-Wall','-Wextra','-Werror','-I',str(STAGE),str(td/'h.c'),str(STAGE/'sha256.c'),str(STAGE/'crc32.c'),'-o',str(exe)],check=True)
        lines=subprocess.check_output([str(exe)],text=True).splitlines()
        assert lines==['ba7816bf8f01cfea414140de5dae2223b00361a396177a9cb410ff61f20015ad','cbf43926'],lines
    print('stage2 SHA-256 and CRC-32 vectors passed')
if __name__=='__main__': main()
