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

int scanf(const char *format, ...) {
    va_list args;
    va_start(args, format);
    int n = 0;
    while (format[n] != '\0') {
        if (format[n] == '%') {
            ++n;
            switch (format[n]) {
                case 'c': {
                    char *c = va_arg(args, char *);
                    *c = getchar();
                    break;
                }
                case 's': {
                    char *s = va_arg(args, char *);
                    gets(s);
                    break;
                }
                case 'd': {
                    int *d = va_arg(args, int *);
                    char buf[32];
                    gets(buf);
                    *d = 0;
                    int i = 0;
                    int sign = 1;
                    if (buf[i] == '-') {
                        sign = -1;
                        ++i;
                    }
                    while (buf[i] != '\0') {
                        *d = *d * 10 + buf[i] - '0';
                        ++i;
                    }
                    *d *= sign;
                    break;
                }
                case 'x': {
                    int *x = va_arg(args, int *);
                    char buf[32];
                    gets(buf);
                    *x = 0;
                    int i = 0;
                    while (buf[i] != '\0') {
                        *x = *x * 16 + buf[i] - '0';
                        ++i;
                    }
                    break;
                }
            }
        } else {
            char c = getchar();
            if (c != format[n])
                return -1;
        }
        ++n;
    }
    va_end(args);
    return 0;
}
