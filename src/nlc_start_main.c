#include "sys/types.h"

extern void exit(int status);
extern void __nlc_csu_init(void);
extern void __nlc_csu_fini(void);

int main(int argc, char *argv[], char *envp[]);

void __nlc_start_main(void *stack_pointer) {
    int argc;
    char **argv;
    char **envp;

    argc = *(int *)stack_pointer;
    argv = (char **)((char *)stack_pointer + sizeof(int));
    envp = argv + argc + 1;

    __nlc_csu_init();

    int ret = main(argc, argv, envp);

    __nlc_csu_fini();
    exit(ret);
}
