#include "uninlc.h"

void *sbrk(intptr_t increment) {
#ifdef _WIN32
    return (void *) -1;
#else
    void *prev_break;
    asm volatile (
        "syscall"
        : "=a" (prev_break)
        : "a" (SYS_BRK), "D" (0)
        : "rcx", "r11", "memory"
    );

    if (prev_break == (void *) -1) {
        // errno = ENOMEM;
        return (void *) -1;
    }

    void *new_break = (void *)((char *)prev_break + increment);
    void *result;
    asm volatile (
        "syscall"
        : "=a" (result)
        : "a" (SYS_BRK), "D" (new_break)
        : "rcx", "r11", "memory"
    );

    if (result == (void *) -1) {
        // errno = ENOMEM;
        return (void *) -1;
    }

    return prev_break;
#endif
}
