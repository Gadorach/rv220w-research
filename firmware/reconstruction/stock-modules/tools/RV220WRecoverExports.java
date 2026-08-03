// SPDX-License-Identifier: Apache-2.0
// @category RV220W
// Usage: RV220WRecoverExports.java <map.tsv>
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;
import ghidra.program.model.mem.MemoryBlock;
import ghidra.program.model.symbol.SourceType;
import java.nio.file.*;
import java.nio.charset.StandardCharsets;
import java.util.*;

public class RV220WRecoverExports extends GhidraScript {
    @Override public void run() throws Exception {
        String[] a = getScriptArgs();
        if (a.length != 1) throw new IllegalArgumentException("map.tsv");
        int recovered = 0;
        for (String line : Files.readAllLines(Paths.get(a[0]), StandardCharsets.UTF_8)) {
            line = line.trim();
            if (line.isEmpty() || line.startsWith("#") || line.startsWith("section\t")) continue;
            String[] p = line.split("\t");
            if (p.length < 3) throw new IllegalArgumentException("bad map line: " + line);
            MemoryBlock block = currentProgram.getMemory().getBlock(p[0]);
            if (block == null) throw new IllegalStateException("missing section block " + p[0]);
            long offset = Long.decode(p[1]);
            Address entry = block.getStart().add(offset);
            Function fn = getFunctionAt(entry);
            if (fn == null) {
                disassemble(entry);
                fn = createFunction(entry, p[2]);
            }
            if (fn == null) throw new IllegalStateException("unable to create function at " + entry);
            if (!fn.getName().equals(p[2])) fn.setName(p[2], SourceType.USER_DEFINED);
            String note = "RV220W recovered exported symbol from Linux __ksymtab relocation evidence. " +
                "Section=" + p[0] + " offset=" + p[1] + ". Name=" + p[2] + ".";
            fn.setRepeatableComment(note);
            currentProgram.getBookmarkManager().setBookmark(entry, "Analysis", "RV220W recovered export", note);
            recovered++;
        }
        currentProgram.getOptions("Program Information").setLong("RV220W Recovered Exported Symbols", recovered);
        println("recovered-exported-symbols=" + recovered);
    }
}
