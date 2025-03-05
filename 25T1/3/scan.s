# A simple program that will read 10 numbers into an array
.text

N_SIZE = 10

main:                           # int main(void) {
        # $t0 is i              #int i;
        li      $t0, 0          # i = 0;

loop:                           #     while (i < N_SIZE) 
        bge     $t0, N_SIZE, end
        # scanf("%d", &numbers[i]);
        # scan into $v0 
        li      $v0, 5
        syscall

        # put $v0 into numbers[i]
        mul     $t1, $t0, 4
        la      $t2, numbers
        add     $t3, $t1, $t2
        sw      $v0, ($t3)

        # shorter way
        # sw      $v0, numbers($t1)

        addi $t0, $t0, 1        # i++;
        j loop

end:
        jr $ra

.data
#     int numbers[N_SIZE] = {0};
numbers: .word 0,0,0,0,0,0,0,0,0,0
#numbers: .space 40