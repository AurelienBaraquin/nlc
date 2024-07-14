#include "nlclib.h"
#include "uninlc.h"
#include "nlcio.h"
#include "string.h"

void putnbr(int n) {
    if (n < 0) {
        putchar('-');
        n = -n;
    }
    if (n >= 10)
        putnbr(n / 10);
    putchar(n % 10 + '0');
}

int main(int argc, char **argv) {
    return 0;
}
