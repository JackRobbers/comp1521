# // Prints the square of a number

SQUARE_MAX = 46340              #define SQUARE_MAX 46340

#include <stdio.h>
.text 
main:                           # int main(void) {
        # $t0 is x, $t1 is y # int x, y;

        li      $v0, 4          # printf("Enter a number: ");
        la      $a0, prompt_string
        syscall
        
        li      $v0, 5          #scanf("%d", &x);
        syscall
        move    $t0, $v0

        ble $t0, SQUARE_MAX, else # if (x > SQUARE_MAX) {

        li $v0, 4               # printf("square too big for 32 bits\n");
        la $a0, too_big_string
        syscall
        b end

else:                           # } else {
        mul     $t1, $t0, $t0   # y = x * x;
  
        li      $v0, 1          # printf("%d\n", y);
        move    $a0, $t1
        syscall

        li      $v0, 11
        li      $a0, '\n'
        syscall
end:
        li      $v0, 0          # return 0;
        jr      $ra             # }


.data
prompt_string: .asciiz "Enter a number: "
too_big_string: .asciiz "square too big for 32 bits\n"