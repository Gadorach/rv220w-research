// SPDX-License-Identifier: Apache-2.0
// @category RV220W
// Recover high-confidence Cisco RV220W boot-chain/U-Boot symbols and command table.
import ghidra.app.script.GhidraScript;
import ghidra.framework.options.Options;
import ghidra.program.model.address.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.symbol.*;
import ghidra.util.exception.*;
import java.io.*;
import java.nio.charset.StandardCharsets;
import java.nio.file.*;
import java.util.*;

public class RV220WUBootRecover extends GhidraScript {
    private static final long IMAGE_LO = 0xffffffffbfc00000L;
    private static final long IMAGE_HI = 0xffffffffbfc80000L;
    private Address A(long x) { return currentProgram.getAddressFactory().getDefaultAddressSpace().getAddress(x); }
    private long u32(Address a) throws Exception {
        long x = Integer.toUnsignedLong(getInt(a));
        return (x & 0x80000000L) != 0 ? (x | 0xffffffff00000000L) : x;
    }
    private String cstr(long p, int max) {
        if (p < IMAGE_LO || p >= IMAGE_HI) return "";
        try {
            StringBuilder b=new StringBuilder(); Address a=A(p);
            for(int i=0;i<max;i++) { int v=getByte(a.add(i))&0xff; if(v==0)break; if(v<0x20||v>0x7e)return ""; b.append((char)v); }
            return b.toString();
        } catch(Exception e) { return ""; }
    }
    private String safe(String s) {
        String x=s.replace("?","qmark").replaceAll("[^A-Za-z0-9_]","_");
        if(x.isEmpty())x="unnamed"; if(Character.isDigit(x.charAt(0)))x="cmd_"+x; return x;
    }
    private Function ensureFunction(long p, String name) throws Exception {
        if(p<IMAGE_LO||p>=IMAGE_HI||(p&3)!=0)return null;
        Address a=A(p); FunctionManager fm=currentProgram.getFunctionManager();
        Function f=fm.getFunctionAt(a);
        if(f==null) {
            Function containing=fm.getFunctionContaining(a);
            if(containing!=null && containing.getEntryPoint().equals(a)) f=containing;
            else if(containing==null) { disassemble(a); f=createFunction(a,name); }
        }
        if(f!=null && name!=null && !name.isBlank()) {
            try { f.setName(name,SourceType.USER_DEFINED); }
            catch(DuplicateNameException e) { try { f.setName(name+"_"+Long.toHexString(p),SourceType.USER_DEFINED); } catch(Exception ignored){} }
        }
        return f;
    }
    private void label(long p,String name) {
        try { createLabel(A(p),name,true,SourceType.USER_DEFINED); } catch(Exception ignored){}
    }
    private void comment(long p,String text) {
        try { currentProgram.getListing().setComment(A(p),CodeUnit.PLATE_COMMENT,text); } catch(Exception ignored){}
    }
    private static final LinkedHashMap<Long,String> KNOWN=new LinkedHashMap<>();
    static {
        KNOWN.put(0xffffffffbfc00000L,"boot_vector_start");
        KNOWN.put(0xffffffffbfc01298L,"board_init_r");
        KNOWN.put(0xffffffffbfc035bcL,"octeon_gpio_set_mask");
        KNOWN.put(0xffffffffbfc04278L,"octeon_gpio_read_pin");
        KNOWN.put(0xffffffffbfc0429cL,"octeon_gpio_config_input");
        KNOWN.put(0xffffffffbfc0f640L,"rv220w_flash_probe_ids");
        KNOWN.put(0xffffffffbfc12fccL,"rv220w_read_base_mac_from_flash");
        KNOWN.put(0xffffffffbfc13084L,"rv220w_board_late_init");
        KNOWN.put(0xffffffffbfc16458L,"do_gpio");
        KNOWN.put(0xffffffffbfc1827cL,"rv220w_bcm53115_set_enabled");
        KNOWN.put(0xffffffffbfc183dcL,"do_bcmmii");
        KNOWN.put(0xffffffffbfc1855cL,"do_mii");
        KNOWN.put(0xffffffffbfc18d8cL,"do_tftpboot");
        KNOWN.put(0xffffffffbfc19af0L,"do_setenv");
        KNOWN.put(0xffffffffbfc1b0c4L,"do_pci");
        KNOWN.put(0xffffffffbfc1d950L,"do_bootoctlinux");
        KNOWN.put(0xffffffffbfc27accL,"do_reset");
        KNOWN.put(0xffffffffbfc29c78L,"octeon_mdio_write_c22");
        KNOWN.put(0xffffffffbfc29d5cL,"octeon_mdio_read_c22");
        KNOWN.put(0xffffffffbfc29dd8L,"bcm53115_pseudophy_write64");
        KNOWN.put(0xffffffffbfc29f58L,"bcm53115_pseudophy_read");
        KNOWN.put(0xffffffffbfc30000L,"uboot_partition_entry");
    }
    @Override public void run() throws Exception {
        String[] args=getScriptArgs(); Path out=args.length>0?Paths.get(args[0]):null;
        int recovered=0, gotPointers=0, commands=0;
        for(Map.Entry<Long,String> e:KNOWN.entrySet()) if(ensureFunction(e.getKey(),e.getValue())!=null)recovered++;
        label(0xffffffffbfc436e0L,"_gp");
        label(0xffffffffbfc440a0L,"uboot_command_table");
        comment(0xffffffffbfc00000L,"RV220W full 512 KiB boot chain linked at 0xffffffffbfc00000. Physical x16 NOR reads/writes use the uncached 0xffffffffbdc00000 alias.");
        comment(0xffffffffbfc30000L,"Start of the preserved 0x50000-byte U-Boot partition (flash offset 0x30000), linked at 0xffffffffbfc30000.");
        comment(0xffffffffbfc436e0L,"Recovered MIPS global-pointer value used by the linked boot chain/U-Boot image.");
        // Conservative GOT pointer scan.
        for(long q=0xffffffffbfc43724L;q<0xffffffffbfc44090L;q+=4) {
            try { long p=u32(A(q)); if(p>=IMAGE_LO&&p<IMAGE_HI&&(p&3)==0) { if(ensureFunction(p,"FUN_"+Long.toHexString(p))!=null)gotPointers++; } } catch(Exception ignored){}
        }
        Path cmdFile=out==null?null:out.resolve("uboot-command-table.tsv");
        BufferedWriter cw=cmdFile==null?null:Files.newBufferedWriter(cmdFile,StandardCharsets.UTF_8);
        if(cw!=null)cw.write("record_address\tcommand\tmaxargs\trepeatable\thandler\tusage\thelp\n");
        for(long r=0xffffffffbfc440a0L;r<0xffffffffbfc44800L;r+=0x20) {
            long namep,handler,usagep,helpp; int maxargs,repeat;
            try { namep=u32(A(r)); if(namep==-1L||namep==0L)break; maxargs=getInt(A(r+4)); repeat=getInt(A(r+8)); handler=u32(A(r+12)); usagep=u32(A(r+16)); helpp=u32(A(r+20)); } catch(Exception e){break;}
            String cmd=cstr(namep,64); if(cmd.isEmpty())break;
            String base="do_"+safe(cmd); Function f=ensureFunction(handler,base);
            String usage=cstr(usagep,512),help=cstr(helpp,2048);
            label(r,"cmdtbl_"+safe(cmd));
            comment(r,"U-Boot command table record for '"+cmd+"'. Handler="+String.format("0x%016x",handler)+"; maxargs="+maxargs+"; repeatable="+repeat+". Usage/help strings retained in the binary.");
            if(f!=null) {
                String old=f.getComment(); if(old==null)old="";
                f.setComment(old+"\n\nRecovered from U-Boot command table: command='"+cmd+"', maxargs="+maxargs+", repeatable="+repeat+", usage='"+usage+"'.");
            }
            if(cw!=null)cw.write(String.format("0x%016x\t%s\t%d\t%d\t0x%016x\t%s\t%s\n",r,cmd.replace("\t"," "),maxargs,repeat,handler,usage.replace("\t"," ").replace("\n","\\n"),help.replace("\t"," ").replace("\n","\\n")));
            commands++;
        }
        if(cw!=null)cw.close();
        Options o=currentProgram.getOptions("Program Information");
        o.setString("RV220W U-Boot Analysis","v1.1.0"); o.setLong("RV220W Command Count",commands); o.setLong("RV220W Known Functions",recovered); o.setLong("RV220W GOT Function Pointers",gotPointers);
        println("rv220w-recover known="+recovered+" got="+gotPointers+" commands="+commands);
    }
}
