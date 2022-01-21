
#include <sys/stat.h>
#include <unimplemented.h>
#include <errno.h>

typedef unsigned int mode_t;
typedef unsigned long long dev_t;
typedef unsigned int uid_t;
typedef unsigned int gid_t;

int chmod(const char* a, mode_t b) {
    (void)unimplemented(ENOTSUP);
    return -1;
}

int fchmod(int a, mode_t b) {
    (void)unimplemented(ENOTSUP);
    return -1;
}

int chown(const char *path, uid_t owner, gid_t group) {
    (void)unimplemented(ENOTSUP);
    return -1;
}

int fchown(int fd, uid_t owner, gid_t group) {
    (void)unimplemented(ENOTSUP);
    return -1;
}

mode_t umask(mode_t mask) {
    (void)unimplemented(ENOTSUP);
    return 0755;
}

int mknod(const char *pathname, mode_t mode, dev_t dev) {
    (void)unimplemented(ENOTSUP);
    return -1;
}

int mknodat(int dirfd, const char *pathname, mode_t mode, dev_t dev) {
    (void)unimplemented(ENOTSUP);
    return -1;
}

int mkfifo(const char *pathname, mode_t mode) {
    (void)unimplemented(ENOTSUP);
    return -1;
}

dev_t makedev(unsigned int maj, unsigned int min) {
    (void)unimplemented(ENOTSUP);
    return 0;
}
