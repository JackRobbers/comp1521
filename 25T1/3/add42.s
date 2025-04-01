# A simple program that adds 42 to each element of an array, if it is negative

.text
N_SIZE = 10

main: # int main(void) {
        # i is $t0      # int i;
        li      $t0, 0 # i = 0;

loop: # while (i < N_SIZE) {
        bge     $t0, N_SIZE, end

        # $t1 shoulbe be numbers[i[
        la      $t2, numbers
        mul     $t3, $t0, 4
        add     $t2, $t3, $t2
        lw      $t1, ($t2)

        # if (numbers[i] < 0) {
        blt     $t1, 0, add42
        b       increment
add42:
        # numbers[i] += 42;
        addi    $t1, $t1, 42
        sw      $t1, ($t2)
       
increment:
        addi    $t0, $t0, 1 # i++;
        j loop

end:
        jr $ra

.data
# int numbers[N_SIZE] = {0, 1, 2, -3, 4, -5, 6, -7, 8, 9};
numbers: .word 0, 1, 2, -3, 4, -5, 6, -7, 8, 9
