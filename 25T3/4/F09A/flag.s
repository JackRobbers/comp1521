FLAG_ROWS = 6
FLAG_COLS = 12

main:
	# $t0 is row
	# $t1 is col

	li 	$t0, 0
row_condition:
	bge	$t0, FLAG_ROWS, end

	li	$t1, 0
col_condition:
	bge	$t1, FLAG_COLS, print_newline

	# make $a0 = flag[row][col]
	
	# offset is row * FLAG_COLS + col
	mul	$t2, $t0, FLAG_COLS
	add	$t2, $t2, $t1
	lb	$a0, flag($t2)

	# generalised to any array
	# (first_dimension * total_second_dimension + second_dimension) * sizeof(element)

	li	$v0, 11
	syscall

	add	$t1, 1
	j col_condition

print_newline:
	li	$v0, 11
	li	$a0, '\n'
	syscall

	add	$t0, 1
	j row_condition

end:
	jr	$ra


.data
flag:
	.byte '#', '#', '#', '#', '#', '.', '.', '#', '#', '#', '#', '#'
flag_line_2: 
	.byte '#', '#', '#', '#', '#', '.', '.', '#', '#', '#', '#', '#'
	.byte '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.'
	.byte '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.'
	.byte '#', '#', '#', '#', '#', '.', '.', '#', '#', '#', '#', '#'
	.byte '#', '#', '#', '#', '#', '.', '.', '#', '#', '#', '#', '#'