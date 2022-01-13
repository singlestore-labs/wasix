
#include <errno.h>
#include <signal.h>
#include <sys/stat.h>
#include <unimplemented.h>

typedef int pid_t;

int kill(pid_t pid, int sig) {
    (void)unimplemented(errno);
    return -1;
}
