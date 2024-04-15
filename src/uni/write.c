#include "uninlc.h"

int write(int fd, const void *buf, size_t count) {
    int ret;
    asm volatile (
        "syscall"
        : "=a"(ret)
        : "a"(SYS_WRITE), "D"(fd), "S"(buf), "d"(count)
    );
    return ret;
}
