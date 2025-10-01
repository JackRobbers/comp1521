main:
	la $t0, string # char *s = &string[0];
	li $t1, 0

loop_condition:
	# dereference s
	lb	$t2, ($t0) # *s

	# check != '\0'
	beq $t2, '\0', end

	add $t1, 1
	add $t0, 1

	j loop_condition
end:

	li $v0, 1
	move $a0, $t1
	syscall

	li $v0, 11
	li $a0, '\n'
	syscall

	jr $ra


.data
string: .asciiz "comp15 112"