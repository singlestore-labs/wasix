
#include <limits.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>
#include <unimplemented.h>


FILE *tmpfile(void) {
    (void)unimplemented(ENOTSUP);
    return NULL;
}

char *tmpnam(char *s) {
    return NULL;
}
