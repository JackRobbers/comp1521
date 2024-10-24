# Print of the danish flag
# As 6x12 ascii art

FLAG_ROWS = 6
FLAG_COLS = 12

.text
# $t0 -> row
# $t1 -> col
main:	
	li $t0, 0
outer_loop_condition:
	bge $t0, FLAG_ROWS, end 

	li $t1, 0
inner_loop_condition:
	bge $t1, FLAG_COLS, outer_loop_iter

	# get &flag[row][col] into $t2
	# &flag + row * FLAG_COLS + col 
	la $t2, flag
	mul $t3, $t0, FLAG_COLS
	add $t4, $t3, $t1
	add $t2, $t4, $t2

	lb $a0, ($t2)

	# print flag[row][col]
	li $v0, 11
	syscall

	addi $t1, $t1, 1
	j inner_loop_condition

outer_loop_iter:

	# print a newline
	li $v0, 11
	li $a0, '\n'
	syscall

	addi $t0, $t0, 1
	j outer_loop_condition
	
end:
	jr $ra

.data
# memory is like a 1D array. we are just deciding where the
# new row starts for 2D arrays.
flag: 
	.byte '#', '#', '#', '#', '#', '.', '.', '#', '#', '#', '#', '#'
	.byte '#', '#', '#', '#', '#', '.', '.', '#', '#', '#', '#', '#'
	.byte '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.'
	.byte '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.'
	.byte '#', '#', '#', '#', '#', '.', '.', '#', '#', '#', '#', '#'
	.byte '#', '#', '#', '#', '#', '.', '.', '#', '#', '#', '#', '#'