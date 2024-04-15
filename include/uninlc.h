#pragma once

typedef unsigned int size_t;

#define SYS_WRITE 1

int write(int fd, const void *buf, size_t count);
