# Simple factorial calculator - without error checking

	.text
# n is $t0
# fac is $t1
# i is $t2
main:
	li	$v0, 4			# printf("n  = ");
	la	$a0, prompt
	syscall

	li	$v0, 5			# scanf("%d", &n);
	syscall
	move	$t0, $v0


	li	$t1, 1			# int fac = 1;

	li	$t2, 1			# for (int i = 1; 

condition:
	bgt	$t2, $t0, print_result	# i <= n

	# BUG i had in the tutorial was multiplying by n instead of i
	mul	$t1, $t1, $t2		# fac *= i;
step:
	add	$t2, $t2, 1		#  i++) {
	j	condition

print_result:
	li	$v0, 4			# printf("n! = ")
	la	$a0, msg_result
	syscall

	li	$v0, 1			# printf("%d", fac)
	move	$a0, $t1
	syscall
	
	li	$v0, 11			# printf("\n")
	li	$a0, '\n'
	syscall

	li	$v0, 0			# return 0
	jr	$ra

	.data
prompt:
	.asciiz "n  = "
msg_result:
	.asciiz "n! = "