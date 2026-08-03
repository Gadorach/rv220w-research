// SPDX-License-Identifier: Apache-2.0
// @category RV220W
import ghidra.app.script.GhidraScript;
import ghidra.framework.options.Options;
import ghidra.program.model.listing.*;
import ghidra.program.model.symbol.*;
import java.util.*;
public class RV220WUBootAnnotate extends GhidraScript {
  private String region(long a){ if(Long.compareUnsigned(a,0xffffffffbfc30000L)<0)return "early-boot-and-board-support"; if(Long.compareUnsigned(a,0xffffffffbfc80000L)<0)return "u-boot-proper"; return "outside-preserved-image"; }
  private String subsystem(String n){ String x=n.toLowerCase(Locale.ROOT); if(x.contains("bcm53115")||x.contains("bcmmii"))return "bcm53115-switch"; if(x.contains("mdio")||x.contains("mii"))return "mdio"; if(x.contains("gpio")||x.contains("button"))return "gpio-button"; if(x.contains("flash")||x.contains("env"))return "nor-environment"; if(x.contains("mac"))return "mac-address"; if(x.startsWith("do_"))return "u-boot-command"; if(x.contains("board"))return "board-init"; return "bootloader-support"; }
  private String detail(Function f){ long a=f.getEntryPoint().getOffset(); String n=f.getName();
    if(a==0xffffffffbfc01298L)return "Late relocated board initialization. Relocation/GOT repair, flash discovery, RV220W board identity, PCI/network setup and U-Boot service initialization are visible. Identity is supported by the retained CVMX_BOARD_TYPE_CUST_RV200W string.";
    if(a==0xffffffffbfc0f640L)return "Macronix/AMD-command-set NOR identification. Writes autoselect command sequence through physical alias 0xbdc00000 and reads manufacturer/device IDs before reset-to-read-array.";
    if(a==0xffffffffbfc12fccL)return "Reads and validates six bytes at physical flash address 0xbdc6ff00 (flash offset 0x6ff00) as the base Ethernet MAC address; warns when zero or erased.";
    if(a==0xffffffffbfc13084L)return "RV220W late board/recovery initialization. Selects octeth0, initializes board networking/switch state, configures GPIO 1 as an input, reads it, prints PUSH_BUTTON, and enters recovery logic when asserted low.";
    if(a==0xffffffffbfc1827cL)return "BCM53115 enable/disable helper. Writes page 0 registers 1 through 4 through the Broadcom pseudo-PHY transaction helper and delays. Exact bit-0x20 semantics remain intentionally unnamed.";
    if(a==0xffffffffbfc29c78L)return "Clause-22 Octeon SMI/MDIO write using CSRs near 0x8001180000001800/1808.";
    if(a==0xffffffffbfc29d5cL)return "Clause-22 Octeon SMI/MDIO read wrapper.";
    if(a==0xffffffffbfc29dd8L)return "Broadcom pseudo-PHY write at MDIO address 0x1e: page register 0x10, command/address register 0x11, data window 0x18-0x1b, write opcode 1, busy polling with timeout.";
    if(a==0xffffffffbfc29f58L)return "Broadcom pseudo-PHY read at MDIO address 0x1e: page register 0x10, command/address register 0x11, data window 0x18-0x1b, read opcode 2, busy polling with timeout.";
    if(a==0xffffffffbfc04278L)return "Reads one Octeon GPIO input bit from the GPIO RX-data CSR.";
    if(a==0xffffffffbfc0429cL)return "Clears the output-enable bit in the selected Octeon per-pin GPIO configuration CSR, configuring that line as input.";
    if(a==0xffffffffbfc035bcL)return "Writes a one-bit mask to an Octeon GPIO set/clear control CSR; exact set-versus-clear naming is constrained by caller context.";
    if(a==0xffffffffbfc16458L)return "U-Boot gpio command handler, retained command syntax provides direct board GPIO diagnostics.";
    if(a==0xffffffffbfc183dcL)return "U-Boot bcmmii command handler for direct Broadcom switch pseudo-PHY register diagnostics.";
    if(n.startsWith("do_"))return "U-Boot command handler recovered from the command-table record. Name identity is high confidence; detailed semantics follow the reconstructed C, strings and callees.";
    if(n.startsWith("FUN_"))return "Analysis-created function. Boundary is supported by control flow or a recovered GOT pointer, but original source name and detailed role are unknown.";
    return "Function identity or role inferred conservatively from address, retained strings, command table, callers and hardware register operations.";
  }
  @Override public void run() throws Exception { int count=0; for(Function f:currentProgram.getFunctionManager().getFunctions(true)){ monitor.checkCancelled(); count++; long a=f.getEntryPoint().getOffset(); String n=f.getName(); String evidence=n.startsWith("do_")?"U-Boot command-table entry":n.startsWith("FUN_")?"Ghidra control-flow/GOT recovery":"address/string/register/call evidence"; String confidence=n.startsWith("do_")?"high for identity; medium for exact types":n.startsWith("FUN_")?"medium for boundary; low for original name":"high for listed hardware facts; medium for inferred types"; String prior=f.getComment(); if(prior==null)prior=""; String c="RV220W BOOT-CHAIN / U-BOOT SEMANTIC ANNOTATION v1.1.0\nRegion: "+region(a)+"\nSubsystem: "+subsystem(n)+"\nEvidence: "+evidence+"\nConfidence: "+confidence+"\nInterpretation: "+detail(f)+"\nSafety: reconstructed pseudocode is not original Cisco source. Do not replay flash, GPIO, MDIO or switch writes without readback and recovery safeguards."; if(!prior.isBlank())c+="\n\nPrior/recovered evidence:\n"+prior; f.setComment(c); f.setRepeatableComment("RV220W U-Boot v1.1.0; "+subsystem(n)+"; "+confidence); currentProgram.getBookmarkManager().setBookmark(f.getEntryPoint(),"Analysis","RV220W U-Boot annotation",detail(f)); }
    Options o=currentProgram.getOptions("Program Information"); o.setLong("RV220W Annotated Functions",count); println("annotated-functions="+count); }
}
