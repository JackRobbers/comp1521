# Prints the square of a number

.text

# $t0 -> x
# $t1 -> y
main: 
	li $v0, 4		# printf
	la $a0, string
	syscall
 
	li $v0, 5	   # scanf(%d
	syscall
	move $t0, $v0  # copy into x

	mul $t1, $t0, $t0 # y = x * x

	li $v0, 1
	move $a0, $t1
	syscall

	li $v0, 11
	li $a0, '\n'
	syscall

	jr $ra

.data
	string: .asciiz "Enter a number: "