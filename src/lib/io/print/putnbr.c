#include "nlcio.h"

void putnbr(int n) {
    if (n < 0) {
        putchar('-');
        n = -n;
    }
    if (n >= 10)
        putnbr(n / 10);
    putchar(n % 10 + '0');
}
