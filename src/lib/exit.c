#include "nlclib.h"

void exit(int status) {
    asm volatile (
        "syscall"
        :
        : "a"(SYS_EXIT), "D"(status)
    );
}
