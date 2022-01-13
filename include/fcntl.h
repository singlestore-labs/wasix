
#ifndef _WASIX_FCNTL_H
#define _WASIX_FCNTL_H

#include_next <fcntl.h>

#define F_DUPFD 0
#define F_DUPFD_CLOEXEC 1030

#define F_RDLCK 0
#define F_WRLCK 1
#define F_UNLCK 2

#define F_GETLK 36
#define F_SETLK 37
#define F_SETLKW 38

#define F_GETLK64 F_GETLK
#define F_SETLK64 F_SETLK
#define F_SETLKW64 F_SETLKW

#endif
