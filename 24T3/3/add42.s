N_SIZE = 10

.text
# $t0 -> i
main:
	li $t0, 0
loop_condition:
	bge $t0, N_SIZE, main_epilogue

	la $t1, numbers
	mul $t2, $t0, 4
	add $t1, $t1, $t2 # $t1 is the address of numbers[i]
	lw $t2, ($t1)

	bltz $t2, add_42
	j loop_iterate

add_42:
	addi $t2, $t2, 42
	sw $t2, ($t1)

loop_iterate:
	addi $t0, $t0, 1
	j loop_condition

main_epilogue:
	jr $ra

.data
numbers: 
	.word 0, 1, 2, -3, 4, -5, 6, -7, 8, 9