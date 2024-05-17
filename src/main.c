#include "nlclib.h"
#include "uninlc.h"
#include "nlcio.h"
#include "string.h"

int main(int argc, char **argv) {
    char nb = argc + '0';
    write(1, &nb, 1);
    write(1, "\n", 1);
    for (int i = 0; i < argc; ++i) {
        write(1, argv[i], strlen(argv[i]));
        write(1, "\n", 1);
    }
    return 0;
}
