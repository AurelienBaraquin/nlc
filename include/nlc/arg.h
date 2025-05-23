#pragma once

#ifndef __va_list
    #if defined(__GNUC__) && __GNUC__ >= 3
        #define __va_list __builtin_va_list
    #else
        #warning Unsupported architecture: va_list is not supported
        #define __va_list char *
    #endif
#endif

#ifndef va_list
    #define va_list va_list
    typedef __va_list va_list;
#endif

#if defined(__GNUC__) && __GNUC__ >= 3
    #define va_start(ap, arg)	__builtin_va_start((ap), (arg))
    #define va_arg		__builtin_va_arg
    #define va_copy		__builtin_va_copy
    #define va_end(ap)		__builtin_va_end((ap))
#else
    #define va_start(ap, arg)	((ap) = ((va_list)&(arg)) \
        + ((sizeof(long) > sizeof(arg)) ? sizeof(long) : sizeof(arg)))
    #define va_arg(ap, type)	*(type *)(ap), \
        ((ap) += ((sizeof(long) > sizeof(type)) ? sizeof(long) : sizeof(type)))
    #define va_copy(copy, arg)	((copy) = (arg))
    #define va_end(ap)
#endif
