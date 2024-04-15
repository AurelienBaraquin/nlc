#include "nlclib.h"
#include "uninlc.h"

void _start() {
    char buf[1024];
    int n = read(0, buf, 1024);
    write(1, buf, n);
    exit(0);
}
