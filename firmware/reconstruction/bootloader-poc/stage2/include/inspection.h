#ifndef RV220W_INSPECTION_H
#define RV220W_INSPECTION_H

void command_bootbus(void);
void command_csr(int argc, char **argv);
void command_env(void);
void command_fwcheck(void);
void command_mac(void);
void command_bootcmd_audit(void);

#endif
