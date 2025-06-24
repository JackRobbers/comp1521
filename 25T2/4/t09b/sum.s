.text
main:
main_prologue:
	# all of your stack setup in prologue
	push $ra

main_body:
	# arguments in a0, a1 ...
	li $a0, 11 
	li $a1, 13
	li $a2, 17
	li $a3, 19
	jal sum4

	# return is in v0
	move $a0, $v0

	# a0 is result
	li $v0, 1
	syscall

	li $v0, 11
	li $a0, '\n'
	syscall

main_epilogue:
	# getting stuff off the stack
	# and returning

	pop $ra
	li $v0, 0
	jr $ra

sum4:
sum4_prologue:
	# when an s register is used it must be pushed and popped, to preserve it's value
	# s registers are guaranteed to be the same across function calls
	push $ra
	push $s0
	push $s1
	push $s2

sum4_body:
	# must assume that $a and $t registers and clobbered (overwritten) when a function is called

	move $s1, $a2
	move $s2, $a3

	jal sum2
	# can't use a t register here
	# since there's a function call coming
	move $s0, $v0

	move $a0, $s1
	move $a1, $s2
	jal sum2

	move $a0, $s0
	move $a1, $v0
	jal sum2

sum4_epilogue:
	pop $s2
	pop $s1
	pop $s0
	pop $ra
	jr $ra


sum2:
	add $v0, $a0, $a1
	jr $ra