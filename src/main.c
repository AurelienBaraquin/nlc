#include "nlclib.h"
#include "uninlc.h"
#include "nlcio.h"
#include "string.h"

int main(int argc, char **argv) {
    void *ptr = sbrk(1);

    strcpy(ptr, "Hello, World!\n");

    puts(ptr);
}
