# // Prints a right - angled triangle of asterisks, 10 rows high.

#include <stdio.h>

main:                           # int main(void) {
        # i is $t0, j is $t1
        li $t0, 1
outer_condition:                # for (int i = 1; i <= 10; i++) {
        bgt $t0, 15, end
        li $t1, 0

inner_condition:                # for (int j = 0; j < i; j++) {
        bge $t1, $t0, outer_increment

        li $v0, 11              # printf("*");
        li $a0, '*'
        syscall

        addi $t1, $t1, 1
        j inner_condition

outer_increment:
        li $v0, 11              # printf("\n");
        li $a0, '\n'
        syscall

        addi $t0, $t0, 1
        j outer_condition

end: 
        li $v0, 0               # return 0;
        jr $ra