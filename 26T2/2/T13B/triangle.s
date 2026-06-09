	.text

# $t0 is i
# $t1 is j
main:	
outer_init:
	li	$t0, 1

outer_condition:
	bgt	$t0, 10, return 
outer_body:

inner_init:
	li	$t1, 0

inner_condition:
	bge	$t1, $t0, outer_print

inner_body:
	li	$v0, 11
	li	$a0, '*'
	syscall

inner_step:	
	add	$t1, $t1, 1
	j inner_condition

outer_print:
	li	$v0, 11
	li	$a0, '\n'
	syscall

outer_step:
	add	$t0, $t0, 1
	j	outer_condition

return:
	li	$v0, 0
	jr	$ra