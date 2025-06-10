# Prints the square of a number
# if too big print an error instead

SQUARE_MAX = 46340

.text
# $t0 -> x
# $t1 -> y
main: 
	li $v0, 4		# printf
	la $a0, string_prompt
	syscall
 
	li $v0, 5	   # scanf(%d
	syscall
	move $t0, $v0  # copy into x

	# if x > SQUARE_MAX
	ble $t0, SQUARE_MAX, success

error:
	li $v0, 4
	la $a0, string_error
	syscall
	j end

success:
	mul $t1, $t0, $t0 # y = x * x

	li $v0, 1
	move $a0, $t1
	syscall

	li $v0, 11
	li $a0, '\n'
	syscall

end:
	jr $ra

.data
	string_prompt: .asciiz "Enter a number: "
	string_error: .asciiz "square too big for 32 bits\n"