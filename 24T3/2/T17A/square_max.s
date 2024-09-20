# Squares a number, unless its square is too big for a 32-bit integer.
# If it is too big, prints an error message instead.

SQUARE_MAX = 46340

.text
main:
	# $t0 -> x
	# $t1 -> y

	li $v0, 4	    # printf
	la $a0, prompt
	syscall

	li $v0, 5 # scanf("%d"
	syscall
	move $t0, $v0

	bgt $t0, SQUARE_MAX, too_big

	mul $t1, $t0, $t0

	li $v0, 1
	move $a0, $t1
	syscall

	li $v0, 11
	li $a0, '\n'
	syscall

	j end

too_big:
	li $v0, 4
	la $a0, big_message
	syscall
end:
	jr $ra


.data
prompt: 
	.asciiz "Enter a number: "

big_message:
	.asciiz "square too big for 32 bits\n"