# reverse array

N_SIZE = 10
N_SIZE_M_1 = N_SIZE - 1
N_SIZE_D_2 = N_SIZE / 2

main:
        # $t0 is i
        # $t1 is x
        # $t2 is offset of i
        # $t3 is y
        # $t4 is offset of N - 1- i

        li      $t0, 0
loop_cond:
        bge     $t0, N_SIZE_D_2, loop_end
        mul	$t2, $t0, 4
        lw	$t1, numbers($t2)

        sub	$t4, N_SIZE_M_1, $t0
        mul	$t4, $t4, 4
        lw      $t3, numbers($t4)

        sw	$t3, numbers($t2)
        sw      $t1, numbers($t4)
        add	$t0, $t0, 1
        j loop_cond
loop_end:
        jr	$ra
.data
numbers: .word 0, 1, 2, 3, 4, 5, 6, 7, 8, 9