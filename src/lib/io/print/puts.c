#include "nlcio.h"
#include "uninlc.h"

int puts(const char *s) {
    if (s == NULL)
        return -1;
    int n = 0;
    while (s[n] != '\0')
        ++n;
    if (write(1, s, n) != n)
        return -1;
    if (write(1, "\n", 1) != 1)
        return -1;
    return 0;
}
