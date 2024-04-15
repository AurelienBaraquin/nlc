#include "nlclib.h"
#include "uninlc.h"
#include "nlcio.h"

void _start() {
    char buf[1024];
    int n = read(0, buf, 1024);
    puts("You entered: ");
    buf[n] = '\0';
    printf("%s%d\n", buf, 20);
    exit(0);
}
