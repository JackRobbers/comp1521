main:
# Frame:    [$ra]
# Uses:     [$v0, $a0, $a1, $a2, $a3, $ra`]
# Clobbers: [$v0, $a0, $a1, $a2, $a3]
#
# Locals:           <-- FILL THIS OUT!
#   - .$s1 is row
#   -  $s2 is col 
#
# Structure:        <-- FILL THIS OUT!
#   main
#   -> [prologue]
#       -> body	
#       loop_cond
#        print
#   -> [epilogue]
main__prologue:
	begin
	push	$ra

main__body:
	li	$a0, 10
	li	$a1, 5
	li	$a2, 3
	li	$a3, 4
	jal	sum4

	move	$a0, $v0
	li	$v0, 1
	syscall

	li	$v0, 11
	li	$a0, '\n'
	syscall

main__epilogue:
	li	$v0, 0
	pop	$ra
	end
	jr	$ra

sum4:
# a is $a0,
# b is $a1 and so on
sum4__prologue:
	push	$ra
	push	$s0
	push	$s2
	push	$s3

sum4__body:
	move	$s2, $a2
	move	$s3, $a3
	
# int res1 = sum2(a, b);
	jal	sum2
	move	$s0, $v0

# int res2 = sum2(c, d);
	move	$a0, $s2
	move	$a1, $s3
	jal	sum2

# return sum2 (res1, res2);
	move	$a0, $s0
	move	$a1, $v0
	jal	sum2

sum4__epilogue:
	pop	$s3
	pop	$s2
	pop	$s0
	pop	$ra
	jr	$ra

sum2:
	add	$t0, $a0, $a1
	move	$v0, $t0
	jr	$ra