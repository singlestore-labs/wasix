
#ifndef _WASIX_SYS_WAIT_H
#define _WASIX_SYS_WAIT_H

#include <bits/alltypes.h>

typedef int pid_t;

pid_t wait(int *wstatus);
pid_t waitpid(pid_t pid, int *status, int options);

#endif
