
#ifndef _WASIX_UNISTD_H
#define _WASIX_UNISTD_H

#include_next <unistd.h>

#include <bits/alltypes.h>

int dup(int);
int dup2(int, int);

uid_t getuid(void);
uid_t geteuid(void);
uid_t getgid(void);
uid_t getegid(void);

pid_t getpid(void);
pid_t getppid(void);

int system(const char *command);
int execv(const char *pathname, char *const argv[]);
int execve(const char *pathname, char *const argv[], char *const envp[]);
int execvp(const char *file, char *const argv[]);
int execvpe(const char *file, char *const argv[], char *const envp[]);

int ttyname_r(int fd, char *buf, size_t buflen);
char *ttyname(int fd);

int pipe(int pipefd[2]);

pid_t fork(void);

int gethostname(char *name, size_t len);

char *realpath(const char *path, char *resolved_path);

#endif
