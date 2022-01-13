
#ifndef _WASIX_SIGNAL_H
#define _WASIX_SIGNAL_H

#include <unistd.h>
#include_next <signal.h>

int kill(pid_t pid, int sig);

#endif
