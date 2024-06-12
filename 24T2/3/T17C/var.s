.text
main:
	jr $ra

.data
u: .space 4 # int u;
v: .word  42 # int v = 42;
w: .space 1   # char w;
x: .byte 'a' # char x = 'a';
y: .space 8  # double y;
z: .space 80 # int z[20]; 4 * 20