# A simple program that will print 10 numbers from an array

N_SIZE = 10

# $t0 is i
main:
    li $t0, 0

condition:
    bge $t0, N_SIZE, end

    # get numbers[i] into a register
    la $t1, numbers
    mul $t2, $t0, 4
    add $t1, $t1, $t2
    lw $a0, ($t1)

    # print it
    li $v0, 1
    syscall

    li $v0, 11
    li $a0, '\n'
    syscall

    add $t0, $t0, 1
    j condition

end:
    jr $ra

.data
numbers: .word 0, 1, 2, 3, 4, 5, 6, 7, 8, 9