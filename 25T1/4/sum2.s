# sum 4 numbers using function calls


# int sum2(int x, int y) {
# since sum2 is a leaf function, don't need to push and pop $ra. used s registers still need to be restored.
sum2:
        add $v0, $a0, $a1   # return x + y;
        jr $ra

# int sum4(int a, int b, int c, int d) {
# sum4 calls another function so $ra and used $s registers need to be preserved
sum4:
sum4_prologue:
        push $ra
        push $s0

sum4_body:
# int res1 = sum2(a, b);
        jal sum2
        move $s0, $v0

#     int res2 = sum2(c, d);
        move $a0, $a2
        move $a1, $a3
        jal sum2

        move $a0, $v0
        move $a1, $s0
        jal sum2 # res3 = sum2 (res1, res2);

sum4_epilogue:
        pop $s0
        pop $ra
        jr $ra
#     return res3

        
# }

#int main(void) {
main:
main_prologue:
        push $ra

main_body:
        li $a0, 11
        li $a1, 13
        li $a2, 17
        li $a3, 19
        jal sum4  #    int result = sum4(11, 13, 17, 19);

        move $a0, $v0 # printf("%d\n", result);

        li $v0, 1
        syscall

        li $v0, 11
        li $a0, '\n'
        syscall


main_epilogue:
        pop $ra
        li $v0, 0 #  return 0;
        jr $ra
# }

