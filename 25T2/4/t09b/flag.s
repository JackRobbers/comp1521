# Print the Danish Flag

FLAG_ROWS = 6
FLAG_COLS = 12

.text
# $t0 -> row
# $t1 -> col
main:

	# init
	li	$t0, 0
	# cond
outer_condition:
	bge 	$t0, FLAG_ROWS, end

	li 	$t1, 0
inner_condition:
	bge	$t1, FLAG_COLS, outer_body

	# get flag[row][col]

	# to get the offset
	# do row * FLAG_COLS + col

	# more general form:
	# (i * WIDTH + j) * sizeof(type)

	mul 	$t2, $t0, FLAG_COLS
	add 	$t2, $t2, $t1
	lb	$a0, flag($t2)

	# print out flag[row][col]
	li 	$v0, 11
	syscall

	add 	$t1, $t1, 1
	j 	inner_condition

outer_body:

	li 	$v0, 11
	li	$a0, '\n'
	syscall

	add 	$t0, $t0, 1
	j 	outer_condition
end:
	jr $ra

.data
flag: 
    # version 1
    .byte '#', '#', '#', '#', '#', '.', '.', '#', '#', '#', '#', '#'
    .byte '#', '#', '#', '#', '#', '.', '.', '#', '#', '#', '#', '#'
    .byte '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.'
    .byte '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.'
    .byte '#', '#', '#', '#', '#', '.', '.', '#', '#', '#', '#', '#'
    .byte '#', '#', '#', '#', '#', '.', '.', '#', '#', '#', '#', '#'