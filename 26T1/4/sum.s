# add 4 numbers

main:
main__prologue:
    push $ra

main__body:
    li $a0, 11     # sum4(a, b, c, d)
    li $a1, 13
    li $a2, 17
    li $a3, 19
    jal sum4

    move $a0, $v0  # printf("%d")
    li $v0, 1
    syscall

    li $v0, 11     # printf("\n")
    li $a0, '\n'
    syscall

main__epilogue:
    pop $ra
    jr $ra

sum2:
    push $s0

    add $s0, $a0, $a1
    move $v0, $s0

    pop $s0
    jr $ra



# Frame:    [$ra, $s0, $s1, $s2]   <-- FILL THESE OUT!
# Uses:     [$ra, $s0, $s1, $s2, $a0, $a1, $v0]
# Clobbers: [$a0, $a1, $v0]
#
# Locals:           <-- FILL THIS OUT!
#   - $s0 - return value store
#   - $s1 - c
#   - $s2 - d
#
# Structure:        <-- FILL THIS OUT!
#   max
#   -> [prologue]
#       -> body
#   -> [epilogue]
sum4:
    begin
    push $ra
    push $s0
    push $s1
    push $s2

    move $s1, $a2
    move $s2, $a3

    jal sum2
    move $s0, $v0

    move $a0, $s1
    move $a1, $s2
    jal sum2

    move $a0, $s0
    move $a1, $v0
    jal sum2

    pop $s2
    pop $s1
    pop $s0
    pop $ra
    end
    jr $ra