        .text
main:
        jr	$ra

        .data
a: .word 256
b: .space 4
c: .asciiz "abcd"
.align 2
d: .byte 1, 2, 3, 4
e: .word 1, 2, 3, 4

u: .space 4
v: .word 42
w: .space 1
x: .byte 'a'
y: .space 8
z: .space 80