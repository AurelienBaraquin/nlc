#include "nlclib.h"
#include "uninlc.h"
#include "nlcio.h"
#include "string.h"

int main(int argc, char **argv) {
    int a = atoi(argv[1]);

    char *s = malloc(a);
    strcpy(s, "Hello world!");
    puts(s);
    free(s);
    char *s2 = malloc(a);
    strcpy(s2, "Hello world!");
    puts(s2);
}
