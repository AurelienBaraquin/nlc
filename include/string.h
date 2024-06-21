#pragma once

typedef long unsigned int size_t;

// string
size_t strlen(const char *s);
char *strcpy(char *dest, const char *src);

// memory
void *memset(void *s, int c, size_t n);
void *memcpy(void *dest, const void *src, size_t n);
