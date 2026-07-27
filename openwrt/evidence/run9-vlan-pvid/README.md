# Run9 VLAN/PVID evidence

This directory preserves the UART-collected DSA and passive B53 snapshots used
to promote the first complete wired-router candidate.

## Controlled states

| State | Port 0 PVID | Port 5 PVID | VLAN 0 members | VLAN 1 members | Host result |
|---|---:|---:|---|---|---|
| Original | 0 | 1 | `{0,1,2,3,4,8}` | `{}` | ARP/ICMP failed |
| Port-5 PVID only | 0 | 0 | `{0,1,2,3,4,8}` | `{}` | ARP/ICMP failed |
| Explicit VID-0 domain | 0 | 0 | `{0,1,2,3,4,5,8}` | `{}` | ordinary and full-MTU ICMP passed |
| Restored | 0 | 1 | `{0,1,2,3,4,8}` | `{}` | ARP/ICMP failed again |
| Explicit VID-1 WAN domain | 1 | 1 | `{0,1,2,3,4,8}` | `{0,5}` | ordinary and full-MTU ICMP passed |
| Final restore | 0 | 1 | `{0,1,2,3,4,8}` | `{}` | original failure restored |

The host ping outcome was reported alongside the test. The UART DSA snapshots,
passive B53 reports, controller transcripts, and original submitted B53 result
archive are preserved here. The raw host terminal text was not part of the ZIP,
so the pass/fail labels above follow the contemporaneous test report while all
register transitions are preserved verbatim.

## Conclusion

Port-based VLAN affinity was already correct: WAN `{0,5}` and LAN
`{1,2,3,4,8}`.  EAP BASIC/SIMPLIFIED mode was not causal.  The BCM53115 static
chip mask excludes alternate CPU port 5, so generic B53 default-VLAN setup
skipped that firmware-described conduit.  Untagged ingress on WAN port 0 was
classified into its PVID but could not egress CPU port 5 until that port became
a member of the same ordinary VLAN-table entry.

The production candidate therefore adds firmware-described DSA CPU ports to
`dev->enabled_ports` before generic B53 VLAN setup.  It does not hard-code a
user-visible WAN VID.


## Contents

- `dsa/`: five paired DSA UART snapshots.
- `b53/`: concise passive B53 state reports used by the documentation.
- `b53-serial/`: complete controller and passive-collector UART transcripts.
- `rv220w-b53-results.zip`: original submitted B53 results archive.
