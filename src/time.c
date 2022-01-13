
#include <time.h>
#include <errno.h>
#include <unimplemented.h>


int utimes(const char* filename, const struct timeval times[2]) {
    (void)unimplemented(EACCES);
    return -1;
}

clock_t clock(void) {
    (void)unimplemented(EACCES);
    return -1;
}
