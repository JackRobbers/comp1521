# Prints the square of a number

.text
main:
	# $t0 -> x
	# $t1 -> y

	li $v0, 4 # printf
	la $a0, prompt
	syscall 

	li $v0, 5 # scanf("%d")
	syscall # $v0 is now the result of scanning
	move $t0, $v0 
 
	mul $t1, $t0, $t0 # y = x * x

	li $v0, 1 # printf("%d")
	move $a0, $t1
	syscall

	li $v0, 11 # printf("\n")
	li $a0, '\n'
	syscall

	li $v0, 0 # return 0, optional. return values are always in $v0
	jr $ra

.data
prompt: 
	.asciiz "Enter a number: "