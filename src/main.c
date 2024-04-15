#include "nlclib.h"
#include "uninlc.h"
#include "nlcio.h"
#include "string.h"

void _start() {
    char buf[1024];
    scanf("%s", buf);
    printf("%s%d\n", buf, strlen(buf));
    exit(0);
}
