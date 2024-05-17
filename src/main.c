#include "nlclib.h"
#include "uninlc.h"
#include "nlcio.h"
#include "string.h"

int main(int argc, char **argv) {
    char nb = argc + '0';
    write(1, &nb, 1);
    return 0;
}
