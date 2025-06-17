

# $t0 -> i
# $t1 -> j
main:

	li $t0, 1

outer_condition:
	bgt $t0, 10, end

	li $t1, 0
	
inner_condition:
	bge $t1, $t0, outer_body

	li $v0, 11
	li $a0, '*'
	syscall

	add $t1, $t1, 1
	j inner_condition

outer_body:
	li $v0, 11		# printf("\n")
	li $a0, '\n'
	syscall

	add $t0, $t0, 1
	j outer_condition


end:
	li $v0, 0
	jr $ra

