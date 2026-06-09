	.text

# x is $t0
main:
	li	$v0, 4
	la	$a0, prompt
	syscall

	li	$v0, 5
	syscall
	move	$t0, $v0

	li	$v0, 4
	ble	$t0, 100, print_small_big
	bge	$t0, 1000, print_small_big
	
	la	$a0, msg_medium
	j 	return

print_small_big:
	la	$a0, msg_small_big
	j 	return

return:
	syscall
	li	$v0, 0
	jr	$ra

	.data
prompt:
	.asciiz "Enter a number: "
msg_medium:
	.asciiz "medium\n"
msg_small_big:
	.asciiz "small/big\n"