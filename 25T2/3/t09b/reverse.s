# reverse an array

N_SIZE = 10

main:

	# make $t1 N_SIZE / 2
	li $t2, N_SIZE
	div $t1, $t2, 2
	
	# make $t7 N_SIZE - 1
	add $t7, $t2, -1

	li $t0, 0
loop:
	bge $t0, $t1, end

	# t3 is x 
	mul $t3, $t0, 4
	la $t5, numbers
	add $t6, $t3, $t5

	# t4 is y
	sub $t8, $t7, $t0
	mul $t3, $t8, 4 # offset
	add $t9, $t3, $t5 # address + offset

	lw $t3, ($t6)
	lw $t4, ($t9)

	sw $t4, ($t6)
	sw $t3, ($t9)

	add $t0, $t0, 1
	j loop

end:
	jr $ra

.data
numbers: .word 0, 1, 2, 3, 4, 5, 6, 7, 8, 9