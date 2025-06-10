# check if a number is within a range

.text
# $t0 -> x
main:
	li $v0, 4
	la $a0, string_prompt
	syscall

	li $v0, 5
	syscall
	move $t0, $v0

	li $v0, 4
	ble $t0, 100, small_big
	bge $t0, 1000, small_big

	la $a0, string_medium
	j end

small_big:
	la $a0, string_small_big

end:
	syscall
	jr $ra

.data
	string_prompt: .asciiz "Enter a number "
	string_medium: .asciiz "medium\n"
	string_small_big: .asciiz "small/big\n"