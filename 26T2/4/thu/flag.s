FLAG_COLS = 6
FLAG_ROWS = 6

main:
# for (int row = 0; row < FLAG_ROWS; row++) {
	li	$t0, 0
outer_cond:
	bge	$t0, FLAG_ROWS, end

# for (int col = 0; col < FLAG_COLS; col++) {
	li	$t1, 0
inner_cond:
	bge	$t1, FLAG_COLS, outer_print
# offset = (row * FLAG_COLS + col) * size of element	
# printf("%c", flag[row][col]);

	mul	$t2, $t0, FLAG_COLS
	add	$t2, $t2, $t1

	lb	$a0, flag($t2)
	li	$v0, 11
	syscall

	add	$t1, 1
	j 	inner_cond
# }
outer_print:
	# printf("\n");
	li	$v0, 11
	li	$a0, '\n'
	syscall
# }
	add	$t0, 1
	j 	outer_cond


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