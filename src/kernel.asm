[BITS 32]
global _start
global kernel_registers
extern kernel_main
CODE_SEG equ 0x08
DATA_SEG equ 0x10

_start:
    mov ax, DATA_SEG
    mov ds, ax
    mov es, ax
    mov fs, ax
    mov gs, ax
    mov ss, ax
    mov ebp, 0x00200000
    mov esp, ebp

    ; Enable the A20 line
    in al, 0x92
    or al, 2
    out 0x92, al
    ;remap the master pic
    mov al, 00010001b
    out 0x20, al ;tell master pic

    mov al, 0x20 ;is where master isr start
    out 0x21, al

    mov al, 000000001b
    out 0x21, al
    ;end remap of master pic
    
    call kernel_main
    jmp $

kernel_registers:
    mov ax, 0x10
    mov ds, ax
    mov es, ax
    mov gs, ax
    mov fs, ax
    ret
times 512-($ - $$) db 0