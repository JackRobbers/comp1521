
.text
main:
        # char *s = &string[0];
        la      $t0, string
        # int   length = 0;
        li      $t1, 0

loop:
        # while (*s != '\0') {
        lb      $t2, ($t0)
        beq     $t2, '\0', end

        # length++;  // increment length
        addi    $t1, $t1, 1
        # s++;       // move to next char
        addi    $t0, $t0, 1
        # }
        j loop
end:
        jr $ra

.data
# char *string = "....";
string: .asciiz "hello world"