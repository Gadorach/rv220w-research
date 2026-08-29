# v1.14.40 pre-tone fault gate compile hotfix

This snapshot is the v1.14.39 pre-tone fault/rollback implementation with one source-emission correction: the accidental literal `+` before `static int nphy_rxiq_cal_write_file()` is removed. Runtime scope is unchanged: only carrier, TPC-off, gain-table, core0-PHY and core0-radio fault points are exposed on CA channel 8; gain search, calibration tone, IQ calculation, RCCAL and normal calibration remain blocked.
