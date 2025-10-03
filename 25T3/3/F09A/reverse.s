N_SIZE = 10
N_SIZE_M_1 = N_SIZE - 1
N_SIZE_D_2 = N_SIZE / 2
END_OFFSET = N_SIZE_M_1 * 4

main:
	li $t0, 0

condition:
	bge $t0, N_SIZE_D_2, end

	mul $t1, $t0, 4 # $t1 is the offset of i
	# int x = numbers[i];
	lw	$t2, numbers($t1)

	# int y = numbers[N_SIZE_M_1 - i];
	sub $t3, END_OFFSET, $t1 # $t3 is the offset of N_SIZE -1 - i
	lw	$t4, numbers($t3)

	# numbers[i] = y;
	sw  $t4, numbers($t1)
	# numbers[N_SIZE_M_1 - i] = x;
	sw  $t2, numbers($t3)

	add $t0, 1
	j condition

end:
	jr $ra 

.data
numbers: .word 0, 1, 2, 3, 4, 5, 6, 7, 8, 9