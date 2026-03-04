# A short program that reverses an array by swapping elements.

N_SIZE = 10
N_SIZE_M_1 = N_SIZE - 1
N_SIZE_D_2 = N_SIZE / 2

# $t0 is i
# $t1 is &numbers[i]
# $t2 is &numbers[N_SIZE_M_1 - i]
# $t3 &numbers
# $t4 is x
# $t5 is y
# $t6 is offset calc
main:
    li $t0, 0

condition:
    bge $t0, N_SIZE_D_2, end

    la $t1, numbers
    mul $t6, $t0, 4
    add $t1, $t1, $t6
    lw $t4, ($t1)

    sub $t6, N_SIZE_M_1, $t0
    la $t2, numbers
    mul $t6, $t6, 4
    add $t2, $t2, $t6
    lw $t5, ($t2)

    sw $t5, ($t1)
    sw $t4, ($t2)


end:
    jr $ra

.data
numbers: .word 0, 1, 2, 3, 4, 5, 6, 7, 8, 9