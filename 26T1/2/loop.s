main:
    # $t0 is x

init:
    li $t0, 24
    
condition:
    bge $t0, 42, end

body:
    move $a0, $t0 # printf("%d\n", x);
    li $v0, 1
    syscall

    li $v0, 11
    li $a0, '\n'
    syscall

increment_and_jump:
    add $t0, $t0, 3
    j condition

end:
    li $v0, 0
    jr $ra