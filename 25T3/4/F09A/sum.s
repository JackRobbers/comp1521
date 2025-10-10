main:
main_prologue:
	# setup the stack
	push	$ra

main_body:
	# c code translation
	# call sum2(11, 13)
	li	$a0, 11
	li	$a1, 13
	li	$a2, 17
	li	$a3, 19
	jal	sum4
	
	move 	$a0, $v0
	li	$v0, 1
	syscall

	li	$v0, 11
	li	$a0, '\n'
	syscall

main_epilogue:
	# pull down the stack and return
	pop 	$ra
	jr 	$ra


sum4:
sum4_prologue:
	push	$ra
	push	$s0
	push	$s2
	push	$s3

sum4_body:
	move 	$s2, $a2
	move	$s3, $a3

	jal sum2		# res1 = sum2(a, b)
	move	$s0, $v0

	move	$a0, $s2
	move	$a1, $s3
	jal sum2		# res2 = sum2(c, d)

	move 	$a0, $s0 
	move	$a1, $v0
	jal sum2		# return sum2(res1, res2)

sum4_epilogue:
	pop	$s3
	pop	$s2
	pop	$s0
	pop	$ra
	jr	$ra

# args are in $a0, $a1. return in $v0
sum2:
	# sum2 is a leaf function - doesn't call any other functions
	# so it doesn't need prologue or epilogue, unless s regsiters are used.
	add 	$v0, $a0, $a1
	jr	$ra
