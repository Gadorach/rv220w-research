// SPDX-License-Identifier: Apache-2.0
// @category RV220W
// Usage: RV220WRecoverPdrFunctions.java <map.tsv>
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;
import ghidra.program.model.mem.MemoryBlock;
import ghidra.program.model.symbol.SourceType;
import java.nio.file.*;
import java.nio.charset.StandardCharsets;

public class RV220WRecoverPdrFunctions extends GhidraScript {
  @Override public void run() throws Exception {
    String[] a=getScriptArgs(); if(a.length!=1)throw new IllegalArgumentException("pdr-map.tsv");
    int created=0,existing=0,failed=0;
    for(String line:Files.readAllLines(Paths.get(a[0]),StandardCharsets.UTF_8)){
      line=line.trim(); if(line.isEmpty()||line.startsWith("#")||line.startsWith("section\t"))continue;
      String[]p=line.split("\t"); if(p.length<3)throw new IllegalArgumentException("bad map line: "+line);
      MemoryBlock b=currentProgram.getMemory().getBlock(p[0]); if(b==null){println("missing block "+p[0]);failed++;continue;}
      Address entry=b.getStart().add(Long.decode(p[1])); Function f=getFunctionAt(entry);
      if(f!=null){existing++;continue;}
      try{
        disassemble(entry); f=createFunction(entry,p[2]);
        if(f==null)throw new IllegalStateException("createFunction returned null");
        f.setName(p[2],SourceType.USER_DEFINED);
        String note="RV220W function recovered from MIPS .pdr relocation at section="+p[0]+" offset="+p[1]+". The original local symbol name was not retained.";
        f.setRepeatableComment(note); currentProgram.getBookmarkManager().setBookmark(entry,"Analysis","RV220W .pdr recovery",note);created++;
      }catch(Exception e){println("PDR recovery failed at "+entry+": "+e);failed++;}
    }
    currentProgram.getOptions("Program Information").setLong("RV220W PDR Functions Created",created);
    currentProgram.getOptions("Program Information").setLong("RV220W PDR Functions Existing",existing);
    currentProgram.getOptions("Program Information").setLong("RV220W PDR Functions Failed",failed);
    println("pdr-created="+created+" existing="+existing+" failed="+failed);
    if(failed!=0)throw new IllegalStateException("PDR recovery failures="+failed);
  }
}
