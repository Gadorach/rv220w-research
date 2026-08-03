# RV220W run6e reopened eth1 failure evidence

Source transcript SHA-256: `d82f69fd6bc2ba26457af76b11aa7b6f6f19f4698ca9713dbc0caea876b13d99`

Observed after a real WAN conduit reassignment back to `eth1`, followed by `ifdown wan`, `ifup wan`, and successful 1000/full link renegotiation:

- Linux reports `wan@eth1` and the intended DSA affinity.
- `eth1` remains at zero received packets.
- BCM53115 CPU port 5 remains at zero transmitted octets toward `eth1`.
- CPU-port-5 receive octets continue to increase from Linux-originated traffic.
- ARP and ICMP remain unavailable on `192.168.241.2`.

This rules out a missing port reopen and confines the next investigation to live BCM53115 port-0/5 membership, forwarding-control and Broadcom-header state. The v1.8.2 diagnostic stage does not change forwarding registers automatically.
