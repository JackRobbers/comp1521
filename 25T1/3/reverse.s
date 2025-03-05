# A short program that reverses an array by swapping elements.

N_SIZE = 10
N_SIZE_END = N_SIZE - 1
N_SIZE_HALF = N_SIZE / 2


# int main(void) {
main:
        # int i;
        # i = 0;
        li      $t0, 0

loop:   
        # while (i < N_SIZE_HALF) {
        bge     $t0, N_SIZE_HALF, end

        # int x = numbers[i];
        mul     $t2, $t0, 4
        lw      $t4, numbers($t2)
        # $t4 is x

        # int y = numbers[N_SIZE_END - i];
        sub     $t3, N_SIZE_END, $t0
        mul     $t3, 4
        lw      $t5, numbers($t3)
        # $t5 is y

        # numbers[i] = y;
        sw      $t5, numbers($t2)
        # numbers[N_SIZE_END - i] = x;
        sw      $t4, numbers($t3)

        # i++;
        addi $t0, $t0, 1
        j loop
end:
        jr $ra
.data
# int numbers[N_SIZE] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
numbers: .word 0, 1, 2, 3, 4, 5, 6, 7, 8, 9