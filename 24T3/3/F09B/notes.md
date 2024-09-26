# 2.

data starts at 0x10010020

.data
a:  .word   42 # 0x10010020, 42
b:  .space  4, # 0x10010024, unitialised
c:  .asciiz "abcde" # 0x10010028, 'a', 'b', 'c', 'd', 'e', '\0'
    .align  2 # align 2, aligns the next label to the word boundary. only adds space if it's needed.
d:  .byte   1, 2, 3, 4 #0x10010030, 
e:  .word   1, 2, 3, 4 #0x10010034
f:  .space  1

0 1 2 3 4 5 6 7 8 9 A B C D E F

36 dec to hex 24

in decimal
1s place, 10 place, 100 places so on

in hex
1s place, 16 place, 256s place

# 3

.data
int v = 42; # v: .word 42
int u; # u: .space 4
char w; # w: .space 1
char x = 'a' # x: .byte 'a'
double y; # y: .space 8 
int z[20]; # z: .space 80

# all of this is in the data segment, which has a fixed size.