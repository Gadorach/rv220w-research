# v1.14.39 pre-tone fault/rollback gate

Qualified predecessor patch SHA-256: `ba3bfe2ddddcd927ac055487f46c9d8c79cb2be5a67381146507d872e91605c4` (v1.14.38).

This revision exposes only injected failure points 1..5, ending immediately after core-0 BCM2056 radio setup and before the first gain-control/tone path. Normal calibration remains blocked. The kernel transaction always restores captured state and the debugfs wrapper accepts the expected `-ECANCELED` only when cleanup and IQ rollback verify.
