extern void exit(int status);
void *sbrk(void *increment);
extern void __nlc_csu_init(void);
extern void __nlc_csu_fini(void);

int main(int argc, char *argv[], char *envp[]);

__attribute__((force_align_arg_pointer))
int __nlc_start_main(int (*main)(int,char **,char **), int argc, char **argv)
{
	char **envp = argv + argc + 1;

    void *ptr = sbrk(0);
    if (ptr == (void *)-1)
        exit(1);

    __nlc_csu_init();

	int ret = main(argc, argv, envp);

    __nlc_csu_fini();

    exit(ret);
}
