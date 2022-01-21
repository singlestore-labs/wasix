
#ifndef _WASIX_SYS_WAIT_H
#define _WASIX_SYS_WAIT_H

#include <bits/alltypes.h>

#define WNOHANG    1
#define WUNTRACED  2

#define WEXITSTATUS(s) (((s) & 0xff00) >> 8)
#define WTERMSIG(s) ((s) & 0x7f)
#define WSTOPSIG(s) WEXITSTATUS(s)
#define WIFEXITED(s) (!WTERMSIG(s))
#define WIFSTOPPED(s) ((short)((((s)&0xffff)*0x10001)>>8) > 0x7f00)
#define WIFSIGNALED(s) (((s)&0xffff)-1U < 0xffu)

typedef int pid_t;

pid_t wait(int *wstatus);
pid_t waitpid(pid_t pid, int *status, int options);

#endif
