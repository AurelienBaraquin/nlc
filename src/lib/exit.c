#include "nlclib.h"

#ifdef _WIN32
    #include <Windows.h>
#endif

void exit(int status) {
#ifdef _WIN32
    ExitProcess(status);
#else
    asm volatile (
        "syscall"
        :
        : "a"(SYS_EXIT), "D"(status)
    );

    while (1);
#endif
}
