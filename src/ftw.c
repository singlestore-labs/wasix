
#include <ftw.h>
#include <unimplemented.h>
#include <errno.h>

int nftw(const char *dirpath,
         int (*fn)(const char *fpath, const struct stat *sb,
                   int typeflag, struct FTW *ftwbuf),
         int nopenfd, int flags) {
    (void)unimplemented(ENOTSUP);
    return 0;
}

int ftw(const char *dirpath,
        int (*fn)(const char *fpath, const struct stat *sb,
                  int typeflag),
        int nopenfd) {
    (void)unimplemented(ENOTSUP);
    return 0;
}
