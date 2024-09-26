# A simple program that will read 10 numbers into an array

N_SIZE = 10

.text
# i -> $t0
main:
	li $t0, 0

loop_condition:
	bge $t0, N_SIZE, loop2

	li $v0, 5
	syscall

	# find the address of the start of the array
	la $t1, numbers
	# calculate the offset from the beginning
	mul $t2, $t0, 4
	# add the address and the offset
	add $t3, $t1, $t2

	sw $v0, ($t3)

	addi $t0, $t0, 1
	j loop_condition

loop2:
	# loop through the array again, printing out the contents
	li $t0, 0
loop2_condition:
	bge $t0, N_SIZE, main_epilogue

	# load numbers[i] into a register
	la $t1, numbers
	mul $t2, $t0, 4
	add $t3, $t1, $t2
	lw $a0, ($t3)

	# print out numbers[i]
	li $v0, 1
	syscall

	li $v0, 11
	li $a0, ','
	syscall

	addi $t0, $t0, 1
	j loop2_condition

main_epilogue:
	jr $ra


.data
# numbers: .word 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
numbers: .space 40

