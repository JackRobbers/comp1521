main:
main_prologue:
	# prologue to setup stack
	begin
	push	$ra

main_body:
	# for translation of c code
	# args are in $a0, $a1 ...
	li	$a0, 11
	li	$a1, 13
	li	$a2, 17
	li	$a3, 19
	jal	sum4
	
	# return value is $v0
	move	$a0, $v0
	li	$v0, 1
	syscall

	li	$v0, 11
	li	$a0, '\n'
	syscall

main_epilogue:
	# epilogue for destroy stack and returns
	pop	$ra
	end
	jr	$ra


sum4: 
	
	begin
	push 	$ra
	push 	$s0
	push	$s2
	push	$s3

	move	$s2, $a2
	move	$s3, $a3

	# a and b are already $a0, $a1
	jal 	sum2
	move 	$s0, $v0

	move 	$a0, $s2
	move 	$a1, $s3
	jal 	sum2

	move 	$a0, $v0
	move 	$a1, $s0
	jal 	sum2

	# result is already in $v0, can immediately return
	pop	$s3
	pop	$s2
	pop	$s0
	pop	$ra
	end
	jr 	$ra

# we know that $a0 is x, $a1 is y
sum2:	
	push $s0
	# sum2 is a leaf function
	# doesn't call any other functions
	# so don't have to do any special stack stuff
	# use whatever registers you like
	add $v0, $a0, $a1


	li 	$s0, 10 

	pop 	$s0
	jr 	$ra
