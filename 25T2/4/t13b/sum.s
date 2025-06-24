.text
main:	
	push $ra
	# arguments are always in $a0, $a1 ...
	li $a0, 11
	li $a1, 13
	li $a2, 17
	li $a3, 19
	jal sum4

	# return values are always in $v0
	move $a0, $v0
	li $v0, 1
	syscall

	li $v0, 11
	li $a0, '\n'
	syscall

	pop $ra
	jr $ra

sum4:
sum4_prologue:
	# stack setup
	push $ra
	# if an s register is used, it must be pushed and popped, so the the outer function keeps any values stored there.
	push $s0
	push $s1
	push $s2
	
sum4_body:
	# must assume that $a and $t registers are clobbered when calling a function

	move $s1, $a2
	move $s2, $a3

	# c translation
	jal sum2
	move $s0, $v0

	move $a0, $s1
	move $a1, $s2
	jal sum2

	move $a0, $s0
	move $a1, $v0
	jal sum2

sum4_epilogue:
	# stack teardown and return
	pop $s2
	pop $s1
	pop $s0
	pop $ra
	jr $ra

sum2:
	add $v0, $a0, $a1
	jr $ra