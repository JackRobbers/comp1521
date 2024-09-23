# 2     

data segment starts at 0x10010020

where does the label start? and what are the contents?

.data
a:  .word   42  -- # 0x10010020, 42 
b:  .space  4 -- # 0x10010024, nothing/unitialised
c:  .asciiz "abcde" -- #0x10010028, 'a', 'b', 'c', 'd' 'e', '\0'
    .align  2 -- # align 2 aligns the next label to a word boundary. in this case uses up 2 bytes, since the string used 6 bytes. 
d:  .byte   1, 2, 3, 4 -- # 0x10010030. 1, 2, 3, 4 each taking a byte of space
e:  .word   1, 2, 3, 4 -- # 0x10010034. 1, 2, 3, 4 each taking up a word.
f:  .space  1 -- # 0x10010044. takes up 1 byte unitialised.

# 3 

turn c code into mips data directives

int u; # u: .space 4

int v = 42; # v: .word 42

char w; # w: .space 1
char x = 'a'; # x: .ascii "a" or x: .byte 'a'
double y; # y: .space
int z[20]; # z: .space 80