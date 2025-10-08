FLAG_COLS = 12
FLAG_ROWS = 6


main:
	li 	$t0, 0

outer_condition:
	bge	$t0, FLAG_ROWS, end

	li 	$t1, 0
inner_condition:
	bge 	$t1, FLAG_COLS, print_newline

	# $t0 is row, $t1 is col
	# the offset is 
	# row * FLAG_COLS + col
	# more generally
	# (first_dimension * size_of_second + second_dimension) * sizeof(element)
	mul	$t2, $t0, FLAG_COLS
	add	$t2, $t2, $t1
	lb	$a0, flag($t2)

	# $a0 is flag[row][col]
	li	$v0, 11
	syscall

	add	$t1, 1
	j 	inner_condition

print_newline:
	li	$v0, 11
	li	$a0, '\n'
	syscall

	add	$t0, 1
	j outer_condition

end:
	jr	$ra

.data
flag:
    .byte '#', '#', '#', '#', '#', '.', '.', '#', '#', '#', '#', '#'
    .byte '#', '#', '#', '#', '#', '.', '.', '#', '#', '#', '#', '#'
    .byte '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.'
    .byte '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.'
    .byte '#', '#', '#', '#', '#', '.', '.', '#', '#', '#', '#', '#'
    .byte '#', '#', '#', '#', '#', '.', '.', '#', '#', '#', '#', '#'
