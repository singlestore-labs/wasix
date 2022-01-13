
#include <pwd.h>

static struct passwd PASSWD_INFO = {
    "",
    "",
    0,
    0,
    "",
    "/",
    "bash"
};

struct passwd *getpwnam(const char *name) {
    return &PASSWD_INFO;
}

struct passwd *getpwuid(uid_t uid) {
    return &PASSWD_INFO;
}
