#include "uninlc.h"

int read(int fd, void *buf, size_t count) {
    if (fd < 0 || buf == (void *)0)
        return -1;

    int ret;
    asm volatile (
        "syscall"
        : "=a"(ret)
        : "a"(SYS_READ), "D"(fd), "S"(buf), "d"(count)
    );
    return ret;
}
