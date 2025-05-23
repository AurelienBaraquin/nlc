#include "nlclib.h"
#include "uninlc.h"
#include "nlcio.h"
#include "string.h"

int main(int argc, char **argv) {
    puts("Hello, world!");

    char *msg = (char *)malloc(32);
    if (!msg) {
        puts("malloc failed\n");
        exit(1);
    }

    msg[0] = 'O';
    msg[1] = 'K';
    msg[2] = '\n';
    msg[3] = '\0';

    puts(msg);
    free(msg);

    return 0;
}
