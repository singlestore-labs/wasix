
#include <stdlib.h>
#include <pthread.h>
#include <errno.h>
#include <unimplemented.h>


int pthread_attr_init(pthread_attr_t *a)
{
    return 0;
}

int pthread_attr_setstacksize(pthread_attr_t *a, size_t b)
{
    return 0;
}

int pthread_attr_destroy(pthread_attr_t *a)
{
    return 0;
}

int pthread_detach(pthread_t a)
{
    return unimplemented(ESRCH);
}

#ifdef __GNUC__
__attribute__((const))
#endif
pthread_t pthread_self(void)
{
    return (pthread_t)1;
}

_Noreturn void pthread_exit(void *a)
{
    // After  the last thread in a process terminates, the process terminates as
    // by calling exit(3) with an exit status of zero;
    //
    exit(0);
}

int pthread_mutex_init(pthread_mutex_t *__restrict a, const pthread_mutexattr_t *__restrict b){
    return 0;
}

int pthread_mutex_lock(pthread_mutex_t *a){
    return 0;
}

int pthread_mutex_unlock(pthread_mutex_t *a){
    return 0;
}

int pthread_mutex_trylock(pthread_mutex_t *a){
    return 0;
}

int pthread_mutex_timedlock(pthread_mutex_t *__restrict a, const struct timespec *__restrict b){
    return 0;
}

int pthread_mutex_destroy(pthread_mutex_t *a){
    return 0;
}

int pthread_mutex_consistent(pthread_mutex_t *a){
    return 0;
}

int pthread_cond_init(pthread_cond_t *__restrict a, const pthread_condattr_t *__restrict b){
    return 0;
}

int pthread_cond_destroy(pthread_cond_t *a){
    return 0;
}

int pthread_cond_wait(pthread_cond_t *__restrict a, pthread_mutex_t *__restrict b){
    return 0;
}

int pthread_cond_timedwait(pthread_cond_t *__restrict a, pthread_mutex_t *__restrict b, const struct timespec *__restrict c){
    return 0;
}

int pthread_cond_broadcast(pthread_cond_t *a){
    return 0;
}

int pthread_cond_signal(pthread_cond_t *a){
    return 0;
}

int pthread_create(pthread_t *__restrict a, const pthread_attr_t *__restrict b, void *(*c)(void *d), void *__restrict e)
{
    return unimplemented(EAGAIN);
}

void* __pthread_key_values[PTHREAD_MAX_KEYS];
size_t __pthread_key_next_slot;

int pthread_key_create(pthread_key_t *out, void (*destructor)(void *a)){
    if (destructor != NULL)
    {
        return unimplemented(EAGAIN);
    }

    void** key = &__pthread_key_values[__pthread_key_next_slot++];
    if (__pthread_key_next_slot > PTHREAD_MAX_KEYS)
    {
        return unimplemented(EAGAIN);
    }

    _Static_assert(sizeof(pthread_key_t) == sizeof(key), "pthread_key_t needs to be able to store a pointer.");
    *out = (pthread_key_t) key;
    return 0;
}

int pthread_key_delete(pthread_key_t a){
    return 0;
}

void *pthread_getspecific(pthread_key_t key){
    _Static_assert(sizeof(pthread_key_t) == sizeof(key), "pthread_key_t needs to be able to store a pointer.");
    return *(void**) key;
}

int pthread_setspecific(pthread_key_t key, const void *value){
    _Static_assert(sizeof(pthread_key_t) == sizeof(key), "pthread_key_t needs to be able to store a pointer.");
    *(void**)key = (void*)value;
    return 0;
}

int pthread_join(pthread_t thread, void **retval)
{
    retval = PTHREAD_CANCELED;
    return EINVAL;
}

