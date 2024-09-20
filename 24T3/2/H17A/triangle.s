.text
main:

	# $t0 -> i
	# $t1 -> j

	li $t0, 1
outer_loop_condition:
	bgt $t0, 10, end
outer_loop_body:
	li $t1, 0
inner_loop_condition:
	bge $t1, $t0, print_newline
inner_loop_body:

	li $v0, 11
	li $a0, '*'
	syscall

	addi $t1, $t1, 1
	j inner_loop_condition
print_newline:
	li $v0, 11
	li $a0, '\n'
	syscall

	addi $t0, $t0, 1
	j outer_loop_condition

end:
	jr $ra