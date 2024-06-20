char *strcpy(char *dest, const char *src) {
    if (dest == (void *)0 || src == (void *)0)
        return (void *)0;

    long unsigned int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return dest;
}
