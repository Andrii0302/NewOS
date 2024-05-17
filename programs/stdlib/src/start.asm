[BITS 32]

global _start
extern c_start
extern newos_exit
section .asm

_start:
    call c_start
    call newos_exit
    ret