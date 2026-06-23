        .text
main:   
main_prologue:
        push	$ra

main_body:
        li	$a0, 10
        li	$a1, 20
        li	$a2, 30
        li	$a3, 40
        jal     sum4

        # return value is always $v0
        move	$a0, $v0
        li	$v0, 1
        syscall

        li	$v0, 11
        li	$a0, '\n'
        syscall

main_epilogue:
        pop	$ra
        jr	$ra

sum2:
        add     $t0, $a0, $a1
        move	$v0, $t0
        jr      $ra


 # Frame:    [ $ra, $s0, $s1, $s2 ]   <-- FILL THESE OUT!
# Uses:     [.$ra, $s0, $s1, $s2, $a0, $a1, $v0, $a2, $a3 ]
# Clobbers: [ $a0, $a1, $v0]
#
# Locals:           <-- FILL THIS OUT!
#   - .$s0 is res1
#
# Structure:        <-- FILL THIS OUT!
#   sum4
#   -> [prologue]
#       -> body
#   -> [epilogue]
sum4:
sum4__prologue:
        push	$ra
        push	$s0
        push	$s1
        push	$s2

sum4__body:
        move	$s1, $a2
        move	$s2, $a3

#    int res1 = sum2(a, b);
        jal     sum2
        move    $s0, $v0

#     int res2 = sum2(c, d);
        move    $a0, $s1
        move	$a1, $s2
        jal     sum2
#     return sum2 (res1, res2);
        move	$a0, $s0
        move    $a1, $v0
        jal     sum2

sum4__epilogue:
        pop	$s2
        pop	$s1
        pop	$s0
        pop	$ra
        jr     $ra
