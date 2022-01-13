
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <unimplemented.h>


int dup(int x) {
    (void)unimplemented(EBADF);
    return -1;
}

pid_t getpid(void) {
    (void)unimplemented(0);
    char *val = getenv("WASIX_PID");
    char *end = val + strlen(val);
    if (val && val[0] != '\0') {
	return (pid_t)strtol(val, &end, 10);
    }
#ifdef _WASIX_PID
    return (pid_t)(_WASIX_PID);
#else
    return 66600;
#endif
}

pid_t getppid(void) {
    (void)unimplemented(0);
    char *val = getenv("WASIX_PPID");
    char *end = val + strlen(val);
    if (val && val[0] != '\0') {
	return (pid_t)strtol(val, &end, 10);
    }
#ifdef _WASIX_PPID
    return (pid_t)(_WASIX_PPID);
#else
    return 55500;
#endif
}

uid_t getuid(void) {
    (void)unimplemented(0);
    char *val = getenv("WASIX_UID");
    char *end = val + strlen(val);
    if (val && val[0] != '\0') {
	return (uid_t)strtol(val, &end, 10);
    }
#ifdef _WASIX_UID
    return (uid_t)(_WASIX_UID);
#else
    return 1;
#endif
}

uid_t geteuid(void) {
    (void)unimplemented(0);
    char *val = getenv("WASIX_EUID");
    char *end = val + strlen(val);
    if (val && val[0] != '\0') {
	return (uid_t)strtol(val, &end, 10);
    }
#ifdef _WASIX_EUID
    return (uid_t)(_WASIX_EUID);
#else
    return 1;
#endif
}

gid_t getgid(void) {
    (void)unimplemented(0);
    char *val = getenv("WASIX_GID");
    char *end = val + strlen(val);
    if (val && val[0] != '\0') {
	return (gid_t)strtol(val, &end, 10);
    }
#ifdef _WASIX_GID
    return (gid_t)(_WASIX_GID);
#else
    return 100;
#endif
}

gid_t getegid(void) {
    (void)unimplemented(0);
    char *val = getenv("WASIX_EGID");
    char *end = val + strlen(val);
    if (val && val[0] != '\0') {
	return (gid_t)strtol(val, &end, 10);
    }
#ifdef _WASIX_EGID
    return (gid_t)(_WASIX_EGID);
#else
    return 100;
#endif
}

int ttyname_r(int fd, char *buf, size_t buflen) {
    (void)unimplemented(0);
    if (buf && buflen > 0) {
        buf[0] = '\0';
    }
    return 0;
}

int system(const char *command) {
    (void)unimplemented(EAGAIN);
    return -1;
}

int execv(const char *pathname, char *const argv[]) {
    (void)unimplemented(EMFILE);
    return -1;
}

int execve(const char *pathname, char *const argv[], char *const envp[]) {
    (void)unimplemented(EMFILE);
    return -1;
}

int pipe(int pipefd[2]) {
    (void)unimplemented(EFAULT);
    return -1;
}

pid_t fork(void) {
    (void)unimplemented(EAGAIN);
    return -1;
}

int gethostname(char *name, size_t len) {
    (void)unimplemented(EFAULT);
    return -1;
}

