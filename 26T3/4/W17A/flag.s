	.text
FLAG_ROWS = 6
FLAG_COLS = 12

main:

outer_init:
	li	$t0, 0

outer_cond:
	bge	$t0, FLAG_ROWS, outer_end

	li	$t1, 0

outer_body:
inner_cond:
	bge	$t1, FLAG_COLS, inner_end

inner_body:
	# get the address of flag[row][col]
	# offset it row * FLAG_COLS + col
	# more generally (i * width + j) * sizeof(type)

	mul	$t2, $t0, FLAG_COLS
	add	$t2, $t1, $t2

	# load into $a0
	lb	$a0, flag($t2)
	# print it
	li	$v0, 11
	syscall

inner_step:
	add	$t1, $t1, 1
	j	inner_cond

inner_end:
outer_step:
	li	$v0, 11
	li	$a0, '\n'
	syscall

	add	$t0, $t0, 1
	j 	outer_cond

outer_end:
	jr	$ra

	.data
flag: 	.byte '#', '#', '#', '#', '#', '.', '.', '#', '#', '#', '#', '#'	
	.byte '#', '#', '#', '#', '#', '.', '.', '#', '#', '#', '#', '#'	
	.byte '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.'	
	.byte '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.'	
	.byte '#', '#', '#', '#', '#', '.', '.', '#', '#', '#', '#', '#'
	.byte '#', '#', '#', '#', '#', '.', '.', '#', '#', '#', '#', '#'