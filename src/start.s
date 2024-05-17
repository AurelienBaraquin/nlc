.section .text
.global _start

_start:
    xor %rbp, %rbp              # Clear rbp
    mov %rsp, %rdi              # Give rdi the address of the first argument
    call __nlc_start_main       # Call __nlc_start_main
