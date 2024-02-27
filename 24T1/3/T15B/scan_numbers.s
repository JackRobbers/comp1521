   .text
main:
	# code for startup
	li $t0, 0
loop:

	# scanf("%d")
	li $v0, 5
	syscall
	
	# store $v0 into numbers[i]
	la $t1, numbers
	mul $t2, $t0, 4
	add $t1, $t1, $t2
	sw $v0, ($t1)
	
	addi $t0, $t0, 1
	bne $t0, 10, loop
end:
	jr   $ra

    .data
numbers: .word 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
