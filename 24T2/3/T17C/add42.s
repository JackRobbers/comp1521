N_SIZE = 10

.text
main:
	# $t0 is i
	li $t0, 0

loop_condition:
	bge $t0, N_SIZE, end

	la $t1, numbers
	mul $t3, $t0, 4
	add $t1, $t1, $t3 
	lw $t2, ($t1)

	bltz $t2, add_42
loop_increment:
	addi $t0, 1
	b loop_condition


add_42:
	addi $t2, 42
	sw $t2, ($t1)
	b loop_increment

end:
	jr $ra


.data
numbers: .word 0, 1, 2, -3, 4, -5, 6, -7, 8, 9