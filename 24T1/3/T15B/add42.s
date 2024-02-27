   .text
main:
	# t0 is the counter
	li $t0, 0
loop:
	# t3 is numbers[i]
	la $t1, numbers
	mul $t2, $t0, 4
	add $t1, $t1, $t2
	lw $t3, ($t1)
	# is numbers[i] < 0
	bltz $t3, add_42
loop_end:
	addi $t0, $t0, 1
	bne $t0, 10, loop
	b end
	
add_42:
	# add 42 to numbers[i]
	addi $t3, $t3, 42
	sw $t3, ($t1)
	b loop_end
	
	
end:
	jr   $ra

    .data
numbers: .word 0, 1, -2, -10, 5, 10, 4, -4, -3, 3