.text
main:
main_prologue:	
	push $ra

main_body:
	li $a0, 10
	li $a1, 5
	li $a2, 2
	li $a3, 3

	# jump and link goes to label and modifies $ra to be next instruction after jal
	jal sum4

	move $a0, $v0
	li $v0, 1
	syscall

	li $v0, 11
	li $a0, '\n'
	syscall

main_epilogue:
	pop $ra
	jr $ra

sum4:
	# return sum2(sum2(a, b), sum2(c, d))
	push $ra
	push $s0
	push $s1
	push $s2

	move $s1, $a2
	move $s2, $a3

	jal sum2
	move $s0, $v0

	move $a0, $s1
	move $a1, $s2
	jal sum2

	move $a1, $v0
	move $a0, $s0
	jal sum2

	# always in the reverse order of pushes
	pop $s2
	pop $s1
	pop $s0
	pop $ra
	jr $ra


sum2:
	add $v0, $a0, $a1
	jr $ra

.data

# structs example

COORD_X = 0
COORD_Y = 8

la $t0, _coord_init
lb $t1, COORD_X($t0)
_coord_init:
	.double 10
	.double 5

_coord:
	.space 16




