#include "nlcio.h"
#include "uninlc.h"
#include "nlcarg.h"

int getchar() {
    char c;
    int n = read(0, &c, 1);
    if (n == 0)
        return -1;
    return c;
}

int gets(char *s) {
    if (s == NULL)
        return -1;
    int n = 0;
    while (1) {
        char c = getchar();
        if (c == -1 || c == '\n')
            break;
        s[n++] = c;
    }
    s[n] = '\0';
    return n;
}
