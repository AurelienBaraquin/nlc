#include <nlc/uni.h>


#ifdef _WIN32
    #include <windows.h>
#endif

int write(int fd, const void *buf, size_t count) {
    if (fd < 0 || buf == (void *)0)
        return -1;

    int ret;

#ifdef _WIN32
    HANDLE handle = (HANDLE)_get_osfhandle(fd);
    if (handle == INVALID_HANDLE_VALUE)
        return -1;

    DWORD bytesWritten;
    if (!WriteFile(handle, buf, count, &bytesWritten, NULL))
        return -1;

    ret = bytesWritten;
#else
    asm volatile (
        "syscall"
        : "=a"(ret)
        : "a"(SYS_WRITE), "D"(fd), "S"(buf), "d"(count)
    );
#endif

    return ret;
}
