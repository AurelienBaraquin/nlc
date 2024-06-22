#include "uninlc.h"

#ifdef _WIN32
    #include <windows.h>
#endif

#define NULL ((void *)0)

int read(int fd, void *buf, size_t count) {
    if (fd < 0 || buf == NULL)
        return -1;

    int ret;

#ifdef _WIN32
    DWORD bytesRead;
    HANDLE handle = (HANDLE)_get_osfhandle(fd);
    if (handle == INVALID_HANDLE_VALUE)
        return -1;

    if (!ReadFile(handle, buf, count, &bytesRead, NULL))
        return -1;

    ret = bytesRead;
#else
    asm volatile (
        "syscall"
        : "=a"(ret)
        : "a"(SYS_READ), "D"(fd), "S"(buf), "d"(count)
    );
#endif

    return ret;
}
