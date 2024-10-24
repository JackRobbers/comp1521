.text
main:	 
	# push takes the given register and places it on the next stack position
	push $ra

	# arguments are in $a0, $a1 ...
	li $a0, 2
	li $a1, 3
	li $a2, 10
	li $a3, 7
	jal sum4

	# results are always in $v0
	move $a0, $v0
	li $v0, 1
	syscall
	
	li $v0, 11
	li $a0, '\n'
	syscall

	# pop takes the last putshed thing and puts it into the given register
	pop $ra
	jr $ra

sum4:
sum4_prologue:
	# prologue is for setting up the stack
	push $ra
	push $s0 
	push $s1
	push $s2

sum4_body:
	# is for actual code / c translation
	# return sum2(sum2(a, b), sum2(c,d))

	# preserve a2 and a3
	move $s1, $a2
	move $s2, $a3

	jal sum2
	move $s0, $v0

	move $a0, $s1
	move $a1, $s2
	jal sum2

	move $a0, $v0
	move $a1, $t0
	jal sum2


sum4_epilogue:
	# epilogue is for restoring registers
	pop $s2
	pop $s1
	pop $s0
	pop $ra
	jr $ra

sum2:
	# since sum2 doesn't call another function don't need to push and pop
	add $v0, $a0, $a1
	jr $ra
