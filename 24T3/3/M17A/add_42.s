N_SIZE = 10

.text
# $t0 -> i
main:
	li $t0, 0 # i = 0

loop_condition:
	bge $t0, N_SIZE, main_epilogue # while (i < N_SIZE)

	# make $t3 be numbers[i]
	la $t1, numbers
	mul $t2, $t0, 4
	add $t1, $t1, $t2
	lw $t3, ($t1)

	bge $t3, 0, loop_iterate # if (numbers[i] < 0)
	addi $t3, $t3, 42
	sw $t3, ($t1)

loop_iterate:
	addi $t0, $t0, 1 # i++
	j loop_condition

main_epilogue:
	jr $ra

.data
numbers: .word 0, 1, 2, -3, 4, -5, 6, -7, 8, 9