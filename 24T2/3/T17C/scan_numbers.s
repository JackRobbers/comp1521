N_SIZE = 10

.text
main:
	# $t0 is i
	li $t0, 0

loop_condition:
	bge $t0, N_SIZE, end

	li $v0, 5
	syscall

	la $t1, numbers
	mul $t2, $t0, 4
	add $t1, $t1, $t2
	# $t1 is numbers[i]

	sw $v0, ($t1)


	addi $t0, 1
	b loop_condition

end:
	jr $ra

.data
numbers: .word 0, 0, 0, 0, 0, 0, 0, 0, 0, 0