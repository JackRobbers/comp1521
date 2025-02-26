# // Print every third number from 24 to 42.
#include <stdio.h>

main:                           # int main(void) {

        # $x is $t0
        # for (int x = 24; x < 42; x += 3) {
        li $t0, 24
condition:
        bge $t0, 42, end

        li $v0, 1               # printf("%d\n", x);
        move $a0, $t0
        syscall
        
        li $v0, 11
        li $a0, '\n'
        syscall
        # }

        addi $t0, $t0, 3
        b condition
end:
        li $v0, 0
        jr $ra