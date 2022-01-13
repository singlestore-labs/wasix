
#include <stdlib.h>
#include <netdb.h>
#include <unimplemented.h>

struct hostent *gethostbyname(const char *name) {
    (void)unimplemented(0);
    h_errno = NO_RECOVERY;
    return NULL;
}

struct hostent *gethostbyaddr(const void *addr, socklen_t len, int type) {
    (void)unimplemented(0);
    h_errno = NO_RECOVERY;
    return NULL;
}

struct servent *getservent(void) {
    (void)unimplemented(0);
    return NULL;
}

struct servent *getservbyname(const char *name, const char *proto) {
    (void)unimplemented(0);
    return NULL;
}

struct servent *getservbyport(int port, const char *proto) {
    (void)unimplemented(0);
    return NULL;
}

struct protoent *getprotobyname(const char *name) {
    (void)unimplemented(0);
    return NULL;
}

void setservent(int stayopen) {
    (void)unimplemented(0);
}

void endservent(void) {
    (void)unimplemented(0);
}

char *inet_ntoa(struct in_addr in) {
    (void)unimplemented(0);
    return NULL;
}

in_addr_t inet_addr(const char *cp) {
    (void)unimplemented(0);
    return -1;
}
