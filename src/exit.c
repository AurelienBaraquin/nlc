#define SYS_EXIT 60

void exit(int status) {
    asm volatile (
        "syscall"
        :
        : "a"(SYS_EXIT), "D"(status)
    );
}
