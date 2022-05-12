
#ifndef _WASIX_TIME_H
#define _WASIX_TIME_H

#include_next <time.h>

typedef long long clock_t;

#ifdef WASI_SDK_14
int utimes(const char *filename, const struct timeval times[2]);
#endif
clock_t clock(void);

#endif
