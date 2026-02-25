main:
    # $t0 is n
    # $t1 is fac
    # $t2 is i

    li $v0, 4
    la $a0, n_equal
    syscall

    li $v0, 5
    syscall
    move $t0, $v0

    li $t1, 1

    li $t2, 1
condition:
    bgt $t2, $t0, print

    mul $t1, $t1, $t2

    add $t2, $t2, 1
    j condition

print:
    li $v0, 4
    la $a0, n_fac
    syscall

    li $v0, 1
    move $a0, $t1
    syscall

    li $v0, 11
    li $a0, '\n'
    syscall


    li $v0, 0
    jr $ra

.data
n_equal: .asciiz "n = "
n_fac: .asciiz "n! ="