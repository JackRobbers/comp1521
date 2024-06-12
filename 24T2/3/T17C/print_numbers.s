N_SIZE = 10

.text
main:
	# $t0 is i
	li $t0, 0

loop_condition:
	bge $t0, N_SIZE, end

	# get the start of the array
	la $t2, numbers
	# calculate the offset of numbers[i]
	mul $t1, $t0, 4
	# find numbers[i]
	add $t2, $t2, $t1
	lw $a0, ($t2)

	li $v0, 1
	syscall

	li $v0, 11
	li $a0, '\n'
	syscall

	addi $t0, 1
	b loop_condition

end:
	jr $ra

.data
numbers: .word 0, 1, 2, 3, 4, 5, 6, 7, 8, 9