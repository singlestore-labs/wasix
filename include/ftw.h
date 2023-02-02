
#ifndef _WASIX_FTW_H
#define _WASIX_FTW_H

#include_next <ftw.h>

int nftw(const char *dirpath,
         int (*fn)(const char *fpath, const struct stat *sb,
                   int typeflag, struct FTW *ftwbuf),
         int nopenfd, int flags);

int ftw(const char *dirpath,
        int (*fn)(const char *fpath, const struct stat *sb,
                  int typeflag),
        int nopenfd);

#endif
