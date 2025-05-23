#include <nlc/uni.h>

int brk(void *addr) {
#ifdef _WIN32
    return -1;
#else
    long result;
    asm volatile (
        "syscall"
        : "=a" (result)
        : "a" (SYS_BRK), "D" (addr)
        : "rcx", "r11", "memory"
    );
    if (result < 0) {
        // errno = -result;
        return -1;
    }
    return 0;
#endif
}
