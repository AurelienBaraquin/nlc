#include "uninlc.h"

int write(int fd, const void *buf, size_t count) {
    if (fd < 0 || buf == (void *)0)
        return -1;

    int ret;
    asm volatile (
        "syscall"
        : "=a"(ret)
        : "a"(SYS_WRITE), "D"(fd), "S"(buf), "d"(count)
    );
    return ret;
}
