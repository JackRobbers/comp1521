	.text

# x is $t5
main:	

init:
	li	$t5, 24
condition:
	bge	$t5, 42, return
body:
	li	$v0, 1
	move	$a0, $t5
	syscall

	li	$v0, 11
	li	$a0, '\n'
	syscall
step:
	add	$t5, $t5, 3
	j	condition

return:
	li	$v0, 0
	jr	$ra