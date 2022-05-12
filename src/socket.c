
#include <errno.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <unimplemented.h>


int socket(int domain, int type, int protocol) {
    (void)unimplemented(ENOTSUP);
    return -1;
}

int connect(int sockfd, const struct sockaddr *addr, socklen_t addrlen) {
    (void)unimplemented(ENOTSUP);
    return -1;
}

int bind(int sockfd, const struct sockaddr *addr, socklen_t addrlen) {
    (void)unimplemented(ENOTSUP);
    return -1;
}

int listen(int sockfd, int backlog) {
    (void)unimplemented(ENOTSUP);
    return -1;
}

#if WASI_SDK_14
int accept(int sockfd, struct sockaddr *addr, socklen_t *addrlen) {
    (void)unimplemented(ENOTSUP);
    return -1;
}
#endif

int socketpair(int domain, int type, int protocol, int sv[2]) {
    (void)unimplemented(ENOTSUP);
    return -1;
}

ssize_t send(int sockfd, const void *buf, size_t len, int flags) {
    (void)unimplemented(ENOTSUP);
    return -1;
}

ssize_t sendto(int sockfd, const void *buf, size_t len, int flags, const struct sockaddr *dest_addr, socklen_t addrlen) {
    (void)unimplemented(ENOTSUP);
    return -1;
}

ssize_t sendmsg(int sockf, const struct msghdr *msg, int flags) {
    (void)unimplemented(ENOTSUP);
    return -1;
}

ssize_t recv(int sockfd, void *buf, size_t len, int flags) {
    (void)unimplemented(ENOTSUP);
    return -1;
}

ssize_t recvfrom(int sockfd, void *buf, size_t len, int flags, struct sockaddr *src_addr, socklen_t *addrlen) {
    (void)unimplemented(ENOTSUP);
    return -1;
}

ssize_t recvmsg(int sockfd, struct msghdr *msg, int flags) {
    (void)unimplemented(ENOTSUP);
    return -1;
}

int getsockname(int sockfd, struct sockaddr *addr, socklen_t *addrlen) {
    (void)unimplemented(ENOTSUP);
    return -1;
}

int getpeername(int sockfd, struct sockaddr *addr, socklen_t *addrlen) {
    (void)unimplemented(ENOTSUP);
    return -1;
}

int getsockopt(int sockfd, int level, int optname, void *optval, socklen_t *optlen) {
    (void)unimplemented(ENOTSUP);
    return -1;
}

int setsockopt(int sockfd, int level, int optname, const void *optval, socklen_t optlen) {
    (void)unimplemented(ENOTSUP);
    return -1;
}

int shutdown(int sockfd, int how) {
    (void)unimplemented(ENOTSUP);
    return -1;
}
