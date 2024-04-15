#include "nlcio.h"
#include "uninlc.h"
#include "nlcarg.h"

int putchar(int c) {
    return write(1, &c, 1);
}

int puts(const char *s) {
    if (s == NULL)
        return -1;
    int n = 0;
    while (s[n] != '\0')
        ++n;
    return write(1, s, n);
}

int printf(const char *format, ...) {
    va_list args;
    va_start(args, format);
    int n = 0;
    while (format[n] != '\0') {
        if (format[n] == '%') {
            ++n;
            switch (format[n]) {
                case 'c': {
                    char c = va_arg(args, int);
                    putchar(c);
                    break;
                }
                case 's': {
                    const char *s = va_arg(args, const char *);
                    puts(s);
                    break;
                }
                case 'd': {
                    int d = va_arg(args, int);
                    char buf[32];
                    int i = 0;
                    if (d < 0) {
                        buf[i++] = '-';
                        d = -d;
                    }
                    int j = i;
                    while (d > 0) {
                        buf[i++] = d % 10 + '0';
                        d /= 10;
                    }
                    for (int k = j; k < i / 2; ++k) {
                        char t = buf[k];
                        buf[k] = buf[i - k - 1];
                        buf[i - k - 1] = t;
                    }
                    buf[i] = '\0';
                    puts(buf);
                    break;
                }
                case 'x': {
                    int x = va_arg(args, int);
                    char buf[32];
                    int i = 0;
                    int j = i;
                    while (x > 0) {
                        int t = x % 16;
                        if (t < 10)
                            buf[i++] = t + '0';
                        else
                            buf[i++] = t - 10 + 'a';
                        x /= 16;
                    }
                    for (int k = j; k < i / 2; ++k) {
                        char t = buf[k];
                        buf[k] = buf[i - k - 1];
                        buf[i - k - 1] = t;
                    }
                    buf[i] = '\0';
                    puts(buf);
                    break;
                }
                default:
                    break;
            }
        } else {
            putchar(format[n]);
        }
        ++n;
    }
    va_end(args);
    return 0;
}
