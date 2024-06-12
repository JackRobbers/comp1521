.text
main:
	# $t0 is length
	# $t1 is *s

	li $t0, 0
	lb $t1, string($t0) 

loop_condition:
	beq $t1, '\0', end

	addi $t0, 1
	lb $t1, string($t0) 

	b loop_condition

end:
	jr $ra

.data
string:
	.asciiz "comp1521 is"