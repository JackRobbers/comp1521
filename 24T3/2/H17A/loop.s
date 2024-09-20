# Print every third number from 24 to 42.

.text
main:	
	# $t0 -> x
	li $t0, 24 # int x = 24

loop_condition:
	bge $t0, 42, end
loop_body:
	li $v0, 1
	move $a0, $t0
	syscall

	li $v0, 11
	li $a0, '\n'
	syscall

	addi $t0, $t0, 3 # x += 3
	j loop_condition

end:
	jr $ra

.data