# Prints a right - angled triangle of asterisks, 10 rows high.

main:
    # i is $t0
    # j is $t1

outer_init:
    li $t0, 1

outer_condition:
    bgt $t0, 10, end

outer_body:
inner_init:
    li $t1, 0

inner_condition:
    bge $t1, $t0, print_newline

inner_body:
    li $v0, 11
    li $a0, '*'
    syscall

inner_increment_and_jump:
    add $t1, $t1, 1
    j inner_condition

print_newline:
    li $v0, 11
    li $a0, '\n'
    syscall

outer_increment_and_jump:
    add $t0, 1 # same as add $t0, $t0, 1
    j outer_condition 

end:
    li $v0, 0
    jr $ra