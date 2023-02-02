#ifndef _WASIX_SETJMP_H
#define _WASIX_SETJMP_H

typedef void *jmp_buf;

int setjmp(jmp_buf env);
void longjmp(jmp_buf env, int value);

#endif
