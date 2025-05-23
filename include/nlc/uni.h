#pragma once

typedef long unsigned int size_t;

#ifndef SYS_READ
    #define SYS_READ 0
#endif
#ifndef SYS_WRITE
    #define SYS_WRITE 1
#endif
#ifndef SYS_BRK
    #define SYS_BRK 12
#endif

typedef long intptr_t;

int write(int fd, const void *buf, size_t count);
int read(int fd, void *buf, size_t count);
int brk(void *addr);
void *sbrk(intptr_t increment);
