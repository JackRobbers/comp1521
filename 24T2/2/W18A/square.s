SQUARE_MAX = 46340

.text
main:
	# $t0 is x
	# $t1 is y
	
	la $a0, prompt
	li $v0, 4
	syscall # printf(prompt)

	li $v0, 5
	syscall # scanf("%d",
	move $t0, $v0 # &x);

	bgt $t0, SQUARE_MAX, too_big

	mul $t1, $t0, $t0

	li $v0, 1
	move $a0, $t1 #printf("%d, y);
	syscall

	li $v0, 11
	li $a0, '\n' # printf("\n");
	syscall
	b end

too_big:
	li $v0, 4
	la $a0, error
	syscall
	
end:
	jr $ra
.data
prompt:
	.asciiz "Enter a number: "
error:
	.asciiz "square too big for 32 bits\n"