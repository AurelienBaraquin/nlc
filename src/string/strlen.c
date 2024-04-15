long unsigned int strlen(const char *s) {
    if (s == (void *)0)
        return 0;

    long unsigned int i = 0;
    while (s[i] != '\0') {
        i++;
    }
    return i;
}
