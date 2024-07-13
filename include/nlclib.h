#pragma once

#ifndef SYS_EXIT
    #define SYS_EXIT 60
#endif

typedef long unsigned int size_t;

void exit(int status);

int atoi(const char *str);

void *malloc(size_t size);
void free(void *ptr);
