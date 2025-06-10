.text
# $t0 -> x
main:
	li $v0, 4			# printf
	la $a0, string
	syscall

	li $v0, 5 			# scanf
	syscall
	move $t0, $v0

	# if (x > 100 && x < 1000)


	# printf("medium\n")


	ble $t0, 100, small_big
	bge $t0, 1000, small_big

medium:	
	li $v0, 4
	la $a0, medium_string
	syscall

	j end

small_big:
	li $v0, 4
	la $a0, small_big_string
	syscall

end:	
	li $v0, 0
	jr $ra

.data
string: .asciiz "Enter a number: "
medium_string: .asciiz "medium\n"
small_big_string: .asciiz "small/big\n"