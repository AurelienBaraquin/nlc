#pragma once

typedef unsigned int size_t;

#ifndef SYS_READ
    #define SYS_READ 0
#endif
#ifndef SYS_WRITE
    #define SYS_WRITE 1
#endif

int write(int fd, const void *buf, size_t count);
int read(int fd, void *buf, size_t count);
