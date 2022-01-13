#ifndef _WASIX_PWD_H
#define _WASIX_PWD_H

#include <unistd.h>
#include <features.h>
#include <bits/alltypes.h>

#define __need_size_t
#include <stddef.h>

/* A record in the user database.  */
struct passwd
{
  char *pw_name;		/* Username.  */
  char *pw_passwd;		/* Hashed passphrase, if shadow database
                                   not in use (see shadow.h).  */
  uid_t pw_uid;		        /* User ID.  */
  gid_t pw_gid;		        /* Group ID.  */
  char *pw_gecos;		/* Real name.  */
  char *pw_dir;			/* Home directory.  */
  char *pw_shell;		/* Shell program.  */
};

struct passwd *getpwnam(const char *name);

struct passwd *getpwuid(uid_t uid);

#endif
