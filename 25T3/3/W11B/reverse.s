N_SIZE = 10
N_SIZE_MINUS_1 = N_SIZE - 1
OFFSET_N_SIZE_MINUS_1 = N_SIZE_MINUS_1 * 4
N_SIZE_DIVIDE_2 = N_SIZE / 2

main:	
	li	$t0, 0
loop_condition:
	bge	$t0, N_SIZE_DIVIDE_2, end

	# $t1 is offset of i
	# $t2 is x = numbers[i]
	mul	$t1, $t0, 4
	lw	$t2, numbers($t1)

	# $t3 is the offset of N_SIZE - 1 - i
	# $t4 is y = numbers[N_SIZE - 1 - i]
	sub	$t3, OFFSET_N_SIZE_MINUS_1, $t1
	lw	$t4, numbers($t3)

	sw	$t4, numbers($t1)
	sw	$t2, numbers($t3)

	add	$t0, 1
	j loop_condition

end:
	jr	$ra

.data
numbers: .word 0, 1, 2, 3, 4, 5, 6, 7, 8, 9