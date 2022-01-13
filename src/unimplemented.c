
#include <stdlib.h>
#include <pthread.h>
#include <errno.h>

int unimplemented(int err)
{
#ifdef _WASIX_ABORT_ON_ERROR
    extern void abort();
    abort();
#endif
    if (err != 0) {
        errno = err;
    }
    return err;
}
