
#include <stdlib.h>
#include <netdb.h>
#include <unimplemented.h>
#include <errno.h>

struct hostent *gethostbyname(const char *name) {
    (void)unimplemented(ENOTSUP);
    h_errno = NO_RECOVERY;
    return NULL;
}

struct hostent *gethostbyaddr(const void *addr, socklen_t len, int type) {
    (void)unimplemented(ENOTSUP);
    h_errno = NO_RECOVERY;
    return NULL;
}

struct servent *getservent(void) {
    (void)unimplemented(ENOTSUP);
    return NULL;
}

struct servent *getservbyname(const char *name, const char *proto) {
    (void)unimplemented(ENOTSUP);
    return NULL;
}

struct servent *getservbyport(int port, const char *proto) {
    (void)unimplemented(ENOTSUP);
    return NULL;
}

struct protoent *getprotobyname(const char *name) {
    (void)unimplemented(ENOTSUP);
    return NULL;
}

void setservent(int stayopen) {
    (void)unimplemented(ENOTSUP);
}

void endservent(void) {
    (void)unimplemented(ENOTSUP);
}

char *inet_ntoa(struct in_addr in) {
    (void)unimplemented(ENOTSUP);
    return NULL;
}

in_addr_t inet_addr(const char *cp) {
    (void)unimplemented(ENOTSUP);
    return -1;
}
