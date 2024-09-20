# Prints a right - angled triangle of asterisks, 10 rows high.

.text
main:

	# $t0 -> i
	# $t1 -> j

	li $t0, 1
outer_condition:
	bgt $t0, 10, epilogue

outer_body:
	li $t1, 0

inner_condition:
	bge $t1, $t0, outer_increment
inner_body:
	li $v0, 11
	li $a0, '*'
	syscall
	
	addi $t1, $t1, 1
	j inner_condition

outer_increment:
	li $v0, 11
	li $a0, '\n'
	syscall

	addi $t0, $t0, 1

	j outer_condition


epilogue:
	jr $ra