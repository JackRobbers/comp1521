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

	bgt $t0, 100, check
	j small_big

check:
	blt $t0, 1000, medium
	j small_big

medium:
	li $v0, 4
	la $a0, string_medium
	syscall

	j end

small_big:
	li $v0, 4
	la $a0, string_small_big
	syscall

end:
	jr $ra

.data
	string_prompt: .asciiz "Enter a number "
	string_medium: .asciiz "medium\n"
	string_small_big: .asciiz "small/big\n"