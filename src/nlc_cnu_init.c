typedef void (*init_fini_fn)(void);

extern init_fini_fn __preinit_array_start[];
extern init_fini_fn __preinit_array_end[];
extern init_fini_fn __init_array_start[];
extern init_fini_fn __init_array_end[];
extern init_fini_fn __fini_array_start[];
extern init_fini_fn __fini_array_end[];

void __nlc_csu_init(void) {
    for (init_fini_fn *fn = __preinit_array_start; fn != __preinit_array_end; ++fn)
        (*fn)();

    for (init_fini_fn *fn = __init_array_start; fn != __init_array_end; ++fn)
        (*fn)();
}

void __nlc_csu_fini(void) {
    for (init_fini_fn *fn = __fini_array_start; fn != __fini_array_end; ++fn)
        (*fn)();
}
