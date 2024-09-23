# A simple program that will read 10 numbers into an array

N_SIZE = 10

.text
# $t0 -> i
main:
	li $t0, 0

loop_condition:
	bge $t0, N_SIZE, loop2_initialise

	li $v0, 5
	syscall
	# take $v0 and store it at numbers[i]

	# &numbers -> 0x0040
	# i is 2, so 8 bytes
	# &numbers[i] -> 0x0048

	# make $t1 &numbers[i]
	la $t1, numbers # address
	mul $t2, $t0, 4 # offset
	add $t1, $t1, $t2
	sw $v0, ($t1)

	addi $t0, $t0, 1
	j loop_condition

loop2_initialise:
	# print out the contents of the array
	li $t0, 0

loop2_condition:
	bge $t0, N_SIZE, main_epilogue

	# make $t1 &numbers[i]
	la $t1, numbers
	mul $t2, $t0, 4
	add $t1, $t1, $t2

	# make $a0 numbers[i] and print it
	li $v0, 1
	lw $a0, ($t1)
	syscall

	li $v0, 11
	li $a0, ','
	syscall

	addi $t0, $t0, 1
	j loop2_condition

main_epilogue:
	li $v0, 11
	li $a0, '\n'
	syscall

	jr $ra

.data
numbers: .word 0, 0, 0, 0, 0, 0, 0, 0, 0, 0