# A simple program that will read 10 numbers into an array

N_SIZE = 10

# $t0 is i
main:
	li $t0, 0

scan_loop:
	bge $t0, N_SIZE, print

	# scan
	li $v0, 5
	syscall

	# get numbers[i], longer version
	# put $v0 in numbers[i]
	mul $t1, $t0, 4 # offset, number of bytes past the beginning of the array
	la $t2, numbers	# address
	add $t3, $t1, $t2 # address + offset. &numbers[i]
	sw $v0, ($t3)

	add $t0, $t0, 1
	j scan_loop

	# print out the contents of the array
print:
	li $t0, 0
print_loop:
	bge $t0, N_SIZE, end

	# get numbers[i], shorter version
	mul $t1, $t0, 4
	lw $a0, numbers($t1)

	# print it out
	li $v0, 1
	syscall

	li $v0, 11
	li $a0, '\n'
	syscall

	addi $t0, $t0, 1
	j print_loop

end:
	jr $ra

.data
numbers: .word 0:N_SIZE