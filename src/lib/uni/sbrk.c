#include <nlc/uni.h>

#include <stdint.h>
#include <stddef.h>

#define SYS_BRK 12

void *sbrk(intptr_t increment) {
#ifdef _WIN32
    return (void *) -1;
#else
    void *cur_brk;
    asm volatile (
        "syscall"
        : "=a" (cur_brk)
        : "a" (SYS_BRK), "D" (0)
        : "rcx", "r11", "memory"
    );

    if ((intptr_t)cur_brk == -1)
        return (void *) -1;

    void *new_brk = (char *)cur_brk + increment;
    void *res;
    asm volatile (
        "syscall"
        : "=a" (res)
        : "a" (SYS_BRK), "D" (new_brk)
        : "rcx", "r11", "memory"
    );

    if (res == new_brk)
        return cur_brk;
    else
        return (void *) -1;
#endif
}
