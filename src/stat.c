
#include <sys/stat.h>
#include <unimplemented.h>

typedef unsigned int mode_t;
typedef unsigned int uid_t;
typedef unsigned int gid_t;

int chmod(const char* a, mode_t b) {
    return unimplemented(0);
}

int fchmod(int a, mode_t b) {
    return unimplemented(0);
}

int chown(const char *path, uid_t owner, gid_t group) {
    return unimplemented(0);
}

int fchown(int fd, uid_t owner, gid_t group) {
    return unimplemented(0);
}

mode_t umask(mode_t mask) {
    (void)unimplemented(0);
    return 0755;
}
