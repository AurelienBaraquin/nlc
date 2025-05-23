#include <nlc/uni.h>

void putnbr(int n) {
    if (n < 0) {
        write(1, "-", 1);
        n = -n;
    }
    if (n >= 10)
        putnbr(n / 10);
    write(1, &((char[]){'0' + n % 10}), 1);
}
