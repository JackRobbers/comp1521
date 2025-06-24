# Print the Danish flag

FLAG_ROWS = 6
FLAG_COLS = 12

.text

# t0 is row
# t1 is col
# t2 is offset
main:

	li $t0, 0
outer_condition:
	bge $t0, FLAG_ROWS, end

	li $t1, 0
inner_condition:
	bge $t1, FLAG_COLS, outer_body

	# how to get flag[row][col]
	# offset for row col is
	# row * FLAG_COLS + col
	# more general form
	# (i * WIDTH + j) * size(element)

	mul $t2, $t0, FLAG_COLS
	add $t2, $t2, $t1
	lb $a0, flag($t2)

	li $v0, 11
	syscall

	add $t1, $t1, 1
	j inner_condition

outer_body:
	li $v0, 11
	li $a0, '\n'
	syscall

	add $t0, $t0, 1
	j outer_condition

end:
	jr $ra

.data
flag:
# 2d version
    .byte '#', '#', '#', '#', '#', '.', '.', '#', '#', '#', '#', '#'
    .byte '#', '#', '#', '#', '#', '.', '.', '#', '#', '#', '#', '#'
    .byte '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.'
    .byte '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.'
    .byte '#', '#', '#', '#', '#', '.', '.', '#', '#', '#', '#', '#'
    .byte '#', '#', '#', '#', '#', '.', '.', '#', '#', '#', '#', '#'