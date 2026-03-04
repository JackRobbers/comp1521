# A simple program that will read 10 numbers into an array
N_SIZE = 10

# $t0 is i

main:
    li $t0, 0 # i = 0;

condition:
    bge $t0, N_SIZE, end

    # get the number
    li $v0, 5
    syscall

    # get the address of numbers[i]
    la $t1, numbers
    mul $t2, $t0, 4
    add $t1, $t2, $t1

    # put it in numbers[i]
    sw $v0, ($t1)

    add $t0, $t0, 1
    j condition
end:
    jr $ra

.data
numbers: .word 0:N_SIZE
