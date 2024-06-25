	.text 
main:
main_prologue:
	push $ra

main_body:
	li $a0, 11
	li $a1, 13
	li $a2, 15
	li $a3, 17
	jal sum4
	# result will be in $v0 after sum2
	
	# printf("%d")
	move $a0, $v0
	li $v0, 1
	syscall
	
	# printf('\n')
	li $v0, 11
	li $a0, '\n'
	syscall

	li $v0, 0

main_epilogue:	
	pop $ra
	jr $ra
	
sum2:
	# add $a0 and $a1
	add $v0, $a0, $a1
	
	# return the result
	jr $ra
	
sum4:
sum4_prologue:
	push $ra
	move $s0, $a0
	move $s1, $a1
	move $s2, $a2
	move $s3, $a3

sum4_body:
	# uses sum2
	
	# $a0 and $a1 are already a and b
	jal sum2
	move $s4, $v0
	
	move $a0, $s2
	move $a1, $s3
	jal sum2
	
	move $a0, $s4
	move $a1, $v0
	jal sum2

sum4_epilogue:
	pop $ra
	jr $ra
	
