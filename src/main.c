#include "nlclib.h"
#include "uninlc.h"
#include "nlcio.h"
#include "string.h"

int atoi(const char *s) {
    int n = 0;
    int sign = 1;

    if (*s == '-') {
        sign = -1;
        s++;
    }

    while (*s) {
        n = n * 10 + *s - '0';
        s++;
    }

    return n * sign;
}

int main(int argc, char **argv) {
    int a = atoi(argv[1]);

    char *s = malloc(a);
    strcpy(s, "Hello world!");
    puts(s);
    char *s2 = malloc(a);
    strcpy(s2, "Hello world!");
    puts(s2);
}
