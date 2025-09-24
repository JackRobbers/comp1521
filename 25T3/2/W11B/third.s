# every third number

main:
	li	$t0, 24

condition:
	bge	$t0, 42, end

	li	$v0, 1
	move	$a0, $t0
	syscall

	li	$v0, 11
	li	$a0, '\n'
	syscall

	add	$t0, $t0, 3
	j	condition

end:	
	li	$v0, 0
	jr 	$ra