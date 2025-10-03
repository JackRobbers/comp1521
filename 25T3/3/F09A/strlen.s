
main:
	la $t0, string # char *s = &string[0];
	li $t1, 0	 # length = 0

condition:
	lb	$t2, ($t0) # *s
	beq $t2, '\0', end

	add $t1, 1
	add $t0, 1

	j condition

end:
	move $a0, $t1
	li $v0, 1
	syscall

	li $v0, 11
	li $a0, '\n'
	syscall

	jr $ra

.data
string: 
	.asciiz "comp1521 f09a"