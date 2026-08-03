// @category RV220W
import ghidra.app.script.GhidraScript;
import ghidra.program.model.listing.*;
import ghidra.program.model.symbol.SourceType;
import java.util.*;
public class RV220WRenameKnown extends GhidraScript {
 public void run() throws Exception {
  LinkedHashMap<String,String> m=new LinkedHashMap<>();
  m.put("ffffffffbfc00000","boot_vector_start");m.put("ffffffffbfc01298","board_init_r");m.put("ffffffffbfc035bc","octeon_gpio_set_mask");m.put("ffffffffbfc04278","octeon_gpio_read_pin");m.put("ffffffffbfc0429c","octeon_gpio_config_input");m.put("ffffffffbfc0f640","rv220w_flash_probe_ids");m.put("ffffffffbfc12fcc","rv220w_read_base_mac_from_flash");m.put("ffffffffbfc13084","rv220w_board_late_init");m.put("ffffffffbfc16458","do_gpio");m.put("ffffffffbfc1827c","rv220w_bcm53115_set_enabled");m.put("ffffffffbfc183dc","do_bcmmii");m.put("ffffffffbfc1855c","do_mii");m.put("ffffffffbfc18d8c","do_tftpboot");m.put("ffffffffbfc19af0","do_setenv");m.put("ffffffffbfc1b0c4","do_pci");m.put("ffffffffbfc1d950","do_bootoctlinux");m.put("ffffffffbfc27acc","do_reset");m.put("ffffffffbfc29c78","octeon_mdio_write_c22");m.put("ffffffffbfc29d5c","octeon_mdio_read_c22");m.put("ffffffffbfc29dd8","bcm53115_pseudophy_write64");m.put("ffffffffbfc29f58","bcm53115_pseudophy_read");m.put("ffffffffbfc30000","uboot_partition_entry");
  FunctionManager fm=currentProgram.getFunctionManager(); int n=0;
  for(var e:m.entrySet()){Function f=fm.getFunctionAt(toAddr(e.getKey()));if(f==null){println("missing "+e.getKey());continue;}println(e.getKey()+" old="+f.getName()+" new="+e.getValue());f.setName(e.getValue(),SourceType.USER_DEFINED);n++;}
  println("renamed="+n);
 }
}
