N_SIZE = 10

main:
	# i is $t0
	li $t0, 0

scan_condition:
	bge $t0, N_SIZE, add_42
	
	# scanf
	li $v0, 5
	syscall
	# $v0 is the input

	# put into the array
	la $t2, numbers
	mul $t3, $t0, 4
	add $t1, $t2, $t3

	# $t1 should be numbers[i]
	sw $v0, ($t1) 

	add $t0, 1
	j scan_condition

add_42:
	li $t0, 0

add_42_condition:
	bge $t0, N_SIZE, print

	# get numbers[i]
	mul $t2, $t0, 4
	lw  $t1, numbers($t2)

	# test if < 0
	bgez $t1, add_42_step
	# add 42 to numbers[i]
	add $t1, 42
	sw $t1, numbers($t2)

add_42_step:
	add $t0, 1
	j add_42_condition


print:
	li $t0, 0

print_condition:
	bge $t0, N_SIZE, end

	# get numbers[i] from memory
	mul $t1, $t0, 4
	lw $a0, numbers($t1)

	# print it
	li $v0, 1
	syscall

	li $v0, 11
	li $a0, '\n'
	syscall

	add $t0, 1
	j print_condition

end:
	jr $ra

.data
numbers: .word 0, 0, 0, 0, 0, 0, 0, 0, 0, 0