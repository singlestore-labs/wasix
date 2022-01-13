
#ifndef _WASIX_TIME_H
#define _WASIX_TIME_H

#include_next <time.h>

typedef long long clock_t;

int utimes(const char *filename, const struct timeval times[2]);
clock_t clock(void);

#endif
