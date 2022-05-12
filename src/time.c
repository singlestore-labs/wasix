
#include <time.h>
#include <errno.h>
#include <unimplemented.h>


#ifdef WASI_SDK_14
int utimes(const char* filename, const struct timeval times[2]) {
    (void)unimplemented(ENOTSUP);
    return -1;
}
#endif

clock_t clock(void) {
    (void)unimplemented(ENOTSUP);
    return -1;
}
