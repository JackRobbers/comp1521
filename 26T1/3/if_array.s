# A simple program that will print 10 numbers from an array

N_SIZE = 10

# $t0 is i
main:
    li $t0, 0

add_condition:
    bge $t0, N_SIZE, print_initialise

    # get numbers[i]
    la $t2, numbers
    mul $t3, $t0, 4
    add $t2, $t2, $t3
    lw $t1, ($t2)

    # if numbers[i] < 0
    bge $t1, 0, add_increment_and_jump
    # add 42
    add $t1, 42
    sw $t1, ($t2)

add_increment_and_jump:
    add $t0, $t0, 1
    j add_condition

print_initialise:
    li $t0, 0

print_condition:
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
    j print_condition

end:
    jr $ra

.data
numbers: .word 0, 1, 2, -3, 4, -5, 6, -7, 8, 9