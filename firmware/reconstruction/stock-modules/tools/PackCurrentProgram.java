// SPDX-License-Identifier: Apache-2.0
// @category OpenVTSS.WholeSystem
import ghidra.app.script.GhidraScript;
import ghidra.framework.model.DomainFile;
import java.io.File;
public class PackCurrentProgram extends GhidraScript {
  @Override public void run() throws Exception {
    String[] a=getScriptArgs(); if(a.length!=1) throw new IllegalArgumentException("output-gzf");
    DomainFile df=currentProgram.getDomainFile();
    File out=new File(a[0]); if(out.exists()&&!out.delete()) throw new IllegalStateException("cannot replace "+out);
    df.packFile(out,monitor); println("packed "+out);
  }
}
