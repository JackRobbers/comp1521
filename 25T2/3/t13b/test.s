main:
	jr $ra
.data
a:  .word   42
b:  .space  4
c:  .asciiz "abcde"
#     .align  3
d:  .byte   'a', 2, 3, 4
e:  .word   1, 2, 3, 4
f:  .space  1