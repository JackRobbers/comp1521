   .text
main:
	# t0 is the counter
	li $t0, 0
loop:

	# printf(%d\n)
	li $v0, 1
	# put the address of numbers[i] in $t2
	la $t2, numbers
	mul $t1, $t0, 4
	add $t2, $t2, $t1
	# load numbers[i] in $a0
	lw $a0, ($t2)
	syscall
	
	li $v0, 11
	li $a0, '\n'
	syscall
	
	addi $t0, $t0, 1
	bne $t0, 10, loop
end:
	jr   $ra

    .data
numbers: .word 0, 1, 2, 3, 4, 5, 6, 7, 8, 9
