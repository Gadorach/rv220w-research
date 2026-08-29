# Run12: v1.9.3 full-RJ45 validation

This directory preserves the two successful production-safe DSA snapshots and
UART transcripts collected from the v1.9.3 RAM image.

Proven during the same session:

- raw FDT exported with `d00dfeed` magic;
- kernel taint value `0` before diagnostic uploads;
- all seven NOR partitions enumerated and readable;
- firewall4 loaded;
- WAN linked at 1000/full, received `192.168.1.179/24` by DHCP and installed a
  default route through `192.168.1.1`;
- router-to-gateway and router-to-Internet pings passed without loss;
- LAN client received `192.168.240.214` from the RV220W DHCP server;
- LAN1, LAN2, LAN3 and LAN4 each routed successfully through NAT;
- WAN-side host could ping the router WAN address but could not reach the LAN
  client, proving the intended WAN-to-LAN forwarding rejection;
- no observed FCS, alignment, symbol, jabber, collision or switch RX-drop
  errors in the recorded traffic window.

The raw B53 half of `collect-conduit` did not run because the production image
intentionally excludes `mdio-tools` and `kmod-mdio-netlink`. v1.10.0 treats
that condition as a clean skip unless `--require-b53` is supplied.

The secondary Octeon master `eth1` may report zero RX while the DSA `wan`
netdev and end-to-end WAN traffic work. On this dual-IMP topology, DSA user-port
statistics and end-to-end tests are authoritative.
