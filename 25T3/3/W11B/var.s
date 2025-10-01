
# int u;
# int v = 42;
# char w;
# char x = 'a';
# double y;
# int z[20];

main:
	jr $ra

.data
z: .space 80
y: .space 8
u: .space 4
v: .word 42
w: .space 1
x: .byte 'a'
s: .space 10
a: .byte 1