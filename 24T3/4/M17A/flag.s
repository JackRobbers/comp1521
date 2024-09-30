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
	bge $t1, FLAG_COLS, outer_loop_increment

	# load current flag character into $a0

	# load the address
	la $t2, flag
	# calculate the offset
	# offset is col + FLAG_COLS * row
	mul $t3, FLAG_COLS, $t0
	add $t4, $t3, $t1
	add $t2, $t2, $t4 # &flag[row][col]

	lb $a0, ($t2)

	# and print it
	li $v0, 11
	syscall 


	addi $t1, $t1, 1
	j inner_loop_condition

outer_loop_increment:
	# print a newline
	li $v0, 11
	li $a0, '\n'
	syscall

	addi $t0, $t0, 1
	j outer_loop_condition;


end:
	jr $ra
.data
flag:
	.byte '#', '#', '#', '#', '#', '.', '.', '#', '#', '#', '#', '#'
	.byte '#', '#', '#', '#', '#', '.', '.', '#', '#', '#', '#', '#'
	.byte '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.'
	.byte '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.'
	.byte '#', '#', '#', '#', '#', '.', '.', '#', '#', '#', '#', '#'
	.byte '#', '#', '#', '#', '#', '.', '.', '#', '#', '#', '#', '#'