#include "nlclib.h"
#include "uninlc.h"
#include "nlcio.h"
#include "string.h"

int main(int argc, char **argv) {
    if (argc != 2)
        return 1;

    char *str = argv[1];
    puts(str);
    return 0;
}
