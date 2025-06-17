# reverse the array

N_SIZE = 10


main:
	li $t0, 0

	# N_SIZE / 2, $t8
	li $t1, N_SIZE
	div $t8, $t1, 2

	# N_SIZE - 1, $t9
	sub $t9, $t1, 1

loop:
	bge $t0, $t8, end

	# x is $t1, $t2 is it's offset
	mul $t2, $t0, 4
	lw $t1, numbers($t2)

	# y is $t3, $t4 is it's offset
	sub $t4, $t9, $t0
	mul $t4, $t4, 4
	lw $t3, numbers($t4)

	sw $t3, numbers($t2) # numbers[i] = y;
	sw $t1, numbers($t4) # numbers[N_SIZE_M_1 - i] = x;

	add $t0, $t0, 1
	j loop

end:
	jr $ra

.data
numbers: .word 1, 2, 3, 4, 5, 6, 7, 8, 9, 10