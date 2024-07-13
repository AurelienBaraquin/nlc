int atoi(const char *s) {
    int n = 0;
    int sign = 1;

    if (*s == '-') {
        sign = -1;
        s++;
    }
    while (*s) {
        n = n * 10 + *s - '0';
        s++;
    }
    return n * sign;
}
