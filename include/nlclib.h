#pragma once

#ifndef SYS_EXIT
    #define SYS_EXIT 60
#endif

typedef long unsigned int size_t;

void exit(int status);

void *malloc(size_t size);
