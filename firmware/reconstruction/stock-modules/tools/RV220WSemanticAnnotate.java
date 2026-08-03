// SPDX-License-Identifier: Apache-2.0
// @category RV220W
// Usage: RV220WSemanticAnnotate.java <module-id>
import ghidra.app.script.GhidraScript;
import ghidra.framework.options.Options;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.*;
import ghidra.program.model.symbol.*;
import java.util.*;

public class RV220WSemanticAnnotate extends GhidraScript {
    private String subsystem(String q) {
        String n=q.toLowerCase(Locale.ROOT);
        if(n.contains("vlan")||n.contains("bcm5398")||n.contains("wanport")||n.contains("brcmtag")||n.contains("portmirror")) return "BCM53115 switch/VLAN datapath";
        if(n.contains("mdio")||n.contains("mii")||n.contains("phy")) return "MDIO/pseudo-PHY access";
        if(n.contains("ipfwd")||n.contains("offload")||n.contains("flow")) return "Octeon hardware-offload/fast-forward path";
        if(n.contains("cvm_oct")||n.contains("ether")||n.contains("rgmii")||n.contains("sgmii")||n.contains("xaui")||n.contains("spi")) return "Octeon Ethernet datapath";
        if(n.contains("led")||n.contains("blink")||n.contains("gpio")) return "Front-panel LED/GPIO control";
        if(n.contains("button")||n.contains("reset")) return "Reset-button/GPIO control";
        if(n.contains("init_module")||n.contains("cleanup_module")) return "Kernel module lifecycle";
        if(n.contains("ioctl")||n.contains("proc")||n.contains("sysctl")) return "Userspace/kernel control interface";
        if(n.startsWith("fun_")) return "Unresolved local helper";
        return "Module-local support";
    }
    private String detail(String module, String q) {
        String n=q.toLowerCase(Locale.ROOT);
        if(q.equals("bcm5398VlanEnable")) return "Enables IEEE 802.1Q VLAN processing in the Broadcom switch through the module's MII register-access layer.";
        if(q.equals("bcm5398VlanDisable")) return "Disables switch VLAN processing through the Broadcom register interface.";
        if(q.equals("bcm5398PortDefaultTagSet")) return "Programs the per-port default VLAN tag/PVID state used for untagged ingress traffic.";
        if(q.equals("bcm5398PortEntrySet")) return "Writes a BCM switch port-table entry; exact bit fields should be correlated with BCM53115/B53 register definitions before reuse.";
        if(q.equals("configWanPort")) return "Board-policy routine that applies special configuration to the designated WAN port. This is a primary target for recovering WAN-vs-LAN switch-port numbering.";
        if(q.equals("wanportCheck")) return "Tests whether a requested logical/physical port matches the module's configured WAN-port parameter.";
        if(q.equals("bcm5398PortLinkStatusQuery")) return "Reads switch port link state through the Broadcom register-access path.";
        if(q.equals("bcm5398PortStateSet")) return "Sets a switch port's forwarding/state control; likely covers disabled/blocking/listening/learning/forwarding encodings.";
        if(q.equals("bcm5398PortConfigSet")) return "Programs per-port switch configuration, including policy fields supplied by the vendor control plane.";
        if(q.equals("bcm5398PortConfigGet")) return "Reads per-port switch configuration for the vendor control plane.";
        if(q.equals("bcm5398VlanEntrySet")) return "Programs a VLAN table entry, including membership and tagging policy.";
        if(q.equals("bcm5398VlanEntryGet")) return "Reads a VLAN table entry from the switch.";
        if(q.equals("bcm5398PortMirrorSet")) return "Programs port-mirroring source/destination controls.";
        if(q.equals("bcm5398Ioctl")||q.equals("bcm5398CompatIoctl")) return "Character-device ioctl dispatcher exposing switch operations to vendor userspace; command decoding is preserved in the decompiled export.";
        if(q.equals("miiSwitchRegisterWrite")) return "Writes an arbitrary-width BCM switch register using the pseudo-PHY/MII transaction protocol.";
        if(q.equals("miiSwitchRegisterRead")) return "Reads an arbitrary-width BCM switch register using the pseudo-PHY/MII transaction protocol.";
        if(q.equals("miiSwitchRegisterRead8")||q.equals("miiSwitchRegisterRead16")||q.equals("miiSwitchRegisterRead32")) return "Width-specific wrapper around the generic BCM switch-register read routine.";
        if(q.equals("mii_phy_read")) return "Recovered exported wrapper around TF1_cvm_oct_mdio_read; brackets the transaction with bottom-half exclusion.";
        if(q.equals("mii_phy_write")) return "Recovered exported wrapper around cvm_oct_mdio_write; brackets the transaction with bottom-half exclusion.";
        if(q.equals("TF1_cvm_oct_mdio_read")) return "Vendor Octeon MDIO read implementation exported to the MII wrapper module.";
        if(q.equals("cvm_oct_mdio_write")) return "Vendor Octeon MDIO write implementation exported to the MII wrapper module.";
        if(q.equals("brcm_miiphy_read")||q.equals("brcm_miiphy_write")) return "Broadcom-oriented MDIO callback used by the Octeon Ethernet/switch integration.";
        if(q.equals("cvm_oct_common_init")) return "Initializes common Octeon Ethernet resources, packet I/O, device state and MDIO integration shared by ports.";
        if(q.equals("cvm_oct_rgmii_init")) return "Initializes an Octeon RGMII interface; critical for correlating the three GMX/RGMII ports reported on RV220W.";
        if(q.equals("cvm_oct_sgmii_init")||q.equals("cvm_oct_xaui_init")||q.equals("cvm_oct_spi_init")) return "Interface-mode-specific Octeon Ethernet initialization retained from the vendor SDK; applicability to RV220W must be established from callers and bootinfo.";
        if(q.equals("cvm_oct_xmit")||q.equals("cvm_oct_transmit_qos")||q.equals("cvm_oct_xmit_pow")) return "Transmit datapath routine, including queue/QoS or POW handling according to the selected entry point.";
        if(q.equals("cvm_oct_tasklet_rx")||q.equals("cvm_oct_do_interrupt")) return "Receive interrupt/tasklet datapath that drains Octeon work entries and submits packets to Linux.";
        if(q.equals("brcmTagAdd")) return "Adds the vendor Broadcom switch tag to CPU-bound transmit traffic; essential evidence for eventual B53/DSA CPU-port configuration.";
        if(q.equals("brcmTagDelete")) return "Removes/parses the vendor Broadcom switch tag from received traffic.";
        if(n.contains("ipfwd")||n.contains("offload")) return "Vendor hardware-offload/fast-forward support. This is not required for initial upstream OpenWrt bring-up and should remain disabled until independently validated.";
        if(q.equals("gpio_config_output")) return "Configures an Octeon GPIO line for output before LED control.";
        if(q.equals("gpio_config_input_sense")) return "Configures an Octeon GPIO line as an input with sensing/interrupt behavior.";
        if(q.equals("led_on")) return "Drives a selected board LED to its active state; polarity and logical LED identifiers are encoded in callers/data tables.";
        if(q.equals("led_off")) return "Drives a selected board LED to its inactive state.";
        if(q.equals("led_blink")) return "Exported board LED blink API used by other stock modules, including reset-button feedback.";
        if(q.equals("blink_wlan")) return "WLAN-specific blink helper; likely services the front-panel WIRELESS indicator rather than switch PHY LEDs.";
        if(q.equals("local_led_proc_read")) return "Stock /proc LED read handler recovered from a function pointer and .pdr entry.";
        if(q.equals("local_led_proc_write")) return "Stock /proc LED command parser/write handler; decompilation exposes accepted LED identifiers and actions.";
        if(q.equals("local_led_timer_callback")) return "Timer callback that advances software-driven LED blink state.";
        if(q.equals("local_push_button_proc_read")) return "Stock /proc push-button read handler; copies the current button state to userspace and advances the file position.";
        if(q.equals("local_push_button_proc_write_or_ack")) return "Stock /proc push-button control/acknowledgement handler; semaphore-protected state update rather than the read-to-userspace path.";
        if(q.equals("local_push_button_timer_callback")) return "Polling/debounce timer callback for the reset button; decompilation contains press-duration and LED-feedback behavior.";
        if(q.equals("set_input")) return "Reset-button helper that updates input/proc state and wakeup/timer behavior.";
        if(module.equals("push_button") && q.equals("init_module")) return "Registers the RV220W push-button GPIO input, timers, wait state and proc/sysctl interface; imports led_blink for visual feedback.";
        if(module.equals("scm-led") && q.equals("init_module")) return "Initializes board LED GPIO state, timers and proc interface. WAN/LAN PHY activity LEDs may instead remain hardware-driven by BCM53115.";
        if(module.equals("bcm5398") && q.equals("init_module")) return "Registers the switch-control character device, module parameters and initial BCM switch policy.";
        if(module.equals("cavium-ethernet") && q.equals("init_module")) return "Vendor Octeon Ethernet module entry point: discovers interfaces/ports, allocates resources, registers network devices and offload controls.";
        if(q.equals("cleanup_module")) return "Module teardown path; reverses registrations and frees runtime resources.";
        if(n.startsWith("local_")) return "Function boundary recovered from the compiler-emitted MIPS .pdr table; the original local function name was stripped. Semantics are constrained by code, data-pointer relocations, imported APIs and referenced strings. See the exported reconstructed C and assembly.";
        if(n.startsWith("fun_")) return "Ghidra-created local function without a source symbol. Semantics are constrained by callers, callees, strings and disassembly exported beside this project.";
        return "Semantics inferred conservatively from the retained source symbol, direct callers/callees, imported APIs and referenced strings. See the per-function exports for evidence.";
    }
    private List<String> refs(Function fn) {
        LinkedHashSet<String> out=new LinkedHashSet<>();
        Listing l=currentProgram.getListing(); ReferenceManager rm=currentProgram.getReferenceManager();
        InstructionIterator ii=l.getInstructions(fn.getBody(),true);
        while(ii.hasNext()) for(Reference r:rm.getReferencesFrom(ii.next().getAddress())) {
            Data d=l.getDataAt(r.getToAddress()); if(d==null)d=l.getDataContaining(r.getToAddress());
            if(d!=null && d.getValue() instanceof String) { String s=((String)d.getValue()).replace("\u0000",""); if(!s.isEmpty())out.add(s); }
        }
        return new ArrayList<>(out);
    }
    private String names(Set<Function> fs, int max) {
        ArrayList<String>x=new ArrayList<>(); for(Function f:fs)x.add(f.getName(true)+"@"+f.getEntryPoint()); Collections.sort(x);
        if(x.size()>max){int more=x.size()-max;x=new ArrayList<>(x.subList(0,max));x.add("...+"+more);} return String.join("; ",x);
    }
    @Override public void run() throws Exception {
        String[] a=getScriptArgs(); if(a.length!=1)throw new IllegalArgumentException("module-id"); String module=a[0];
        int count=0,named=0,auto=0;
        for(Function f:currentProgram.getFunctionManager().getFunctions(true)) {
            monitor.checkCancelled(); count++;
            String q=f.getName(true); boolean isPdr=f.getName().startsWith("local_"); boolean isAuto=f.getName().startsWith("FUN_")||f.getSymbol().getSource()==SourceType.DEFAULT;
            if(isAuto)auto++;else named++;
            Set<Function> callers=new LinkedHashSet<>(),callees=new LinkedHashSet<>();
            for(Function x:f.getCallingFunctions(monitor))callers.add(x); for(Function x:f.getCalledFunctions(monitor))callees.add(x);
            List<String> strings=refs(f);
            String evidence=f.isExternal()?"external kernel/API symbol":isPdr?"function boundary recovered from MIPS .pdr relocation":isAuto?"analysis-created local function":"retained or recovered ELF/source symbol";
            String confidence=f.isExternal()?"identity high; implementation unavailable":isPdr?"high for boundary; low-to-medium for inferred role":isAuto?"low-to-medium; no retained name":"high for identity; medium for detailed semantics";
            StringBuilder c=new StringBuilder();
            c.append("RV220W STOCK MODULE SEMANTIC ANNOTATION v1.0.0\n");
            c.append("Module: ").append(module).append("\nSubsystem: ").append(subsystem(q)).append("\n");
            c.append("Evidence class: ").append(evidence).append("\nConfidence: ").append(confidence).append("\n");
            c.append("Interpretation: ").append(detail(module,f.getName())).append("\n");
            c.append("Callers: ").append(names(callers,16)).append("\nCallees: ").append(names(callees,24)).append("\n");
            c.append("Referenced strings: ").append(strings.isEmpty()?"none recovered":String.join(" | ",strings)).append("\n");
            c.append("Safety note: decompiler output is reconstructed C, not original Cisco source. Register meanings remain hypotheses unless tied to constants, vendor strings, runtime behavior or upstream register definitions.\n");
            String old=f.getComment(); if(old!=null&&!old.isBlank())c.append("\nPrior annotation:\n").append(old);
            f.setComment(c.toString());
            f.setRepeatableComment("RV220W v1.0.0; module="+module+"; subsystem="+subsystem(q)+"; evidence="+evidence+"; confidence="+confidence);
            currentProgram.getBookmarkManager().setBookmark(f.getEntryPoint(),"Analysis","RV220W semantic annotation",subsystem(q)+": "+detail(module,f.getName()));
        }
        Options o=currentProgram.getOptions("Program Information");
        o.setString("RV220W Analysis Version","v1.0.0"); o.setString("RV220W Module",module);
        o.setLong("RV220W Annotated Functions",count); o.setLong("RV220W Named Functions",named); o.setLong("RV220W Auto Functions",auto);
        println("annotated-functions="+count+" named="+named+" auto="+auto);
    }
}
