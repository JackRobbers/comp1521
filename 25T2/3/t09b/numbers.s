# A simple program that will read 10 numbers into an array

N_SIZE = 10

.text

# $t0 -> i
main:	
	li $t0, 0
scan_loop:
	bge $t0, N_SIZE, print_body

	li $v0, 5
	syscall
	# $v0 is the scanned number

	# take v0 and put it in numbers[i]
	mul $t1, $t0, 4 # offset, how many bytes past the start of the array the element is. 
	
	# longer version ---
	# la $t2, numbers # address

	# add $t3, $t2, $t1 # address + offset, is &numbers[i]
	# sw $v0, ($t3)
	# ---

	# short version
	sw $v0, numbers($t1)

	add $t0, $t0, 1
	j scan_loop
print_body:
	# loop again, print out the numbers

	# while (i < N_SIZE) {
	#    printf("%d\n", numbers[i])
	#    i ++ 
	# }	
	
	# can resuse t0, t1, ... since we don't care how they were used before
	li $t0, 0
	la $t2, numbers
print_loop:
	bge $t0, N_SIZE, end

	# load numbers[i]
	mul $t1, $t0, 4

	# reuse $t1 for the address + offset
	add $t1, $t2, $t1
	lw $a0, ($t1)

	# print out variable
	li $v0, 1
	syscall

	li $v0, 11
	li $a0, '\n'
	syscall

	add $t0, $t0, 1
	j print_loop


end:
	li $v0, 0
	jr $ra

.data
numbers: .word 0:N_SIZE # initialise the array to 0.