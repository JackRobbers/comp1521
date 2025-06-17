# find the length of a string

main:
	la $t0, string # char *s = &string[0];
	li $t1, 0

loop:
	lb $t2, ($t0)
	beq $t2, '\0', end	

	add $t1, $t1, 1
	add $t0, $t0, 1

	j loop

end:
	jr $ra


.data
string: .asciiz "comp1521"