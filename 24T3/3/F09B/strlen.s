.text
# t0 is s, the current character of the string
# t1 -> length
main:
	la $t0, string # char *s = &string[0]

	li $t1, 0

loop_condition:

	lb $t2, ($t0) # *s
	beq $t2, '\0', end
	
	addi $t1, $t1, 1 # length++
	addi $t0, $t0, 1 # s++

	j loop_condition

end:
	li $v0, 1
	move $a0, $t1
	syscall

	jr $ra

.data
string: .asciiz "comp1521"