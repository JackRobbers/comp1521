# add 42 to negative numbers

N_SIZE = 10

	.text

# $t0 is i
main:
init:
	li $t0, 0

cond:
	bge	$t0, N_SIZE, end

body:
	# if (numbers[i] < 0)
	mul	$t1, $t0, 4
	lw	$t2, numbers($t1)

	bge	$t2, 0, step

	# numbers[i] += 42;

	add	$t2, 42
	sw	$t2, numbers($t1)

step:
	add	$t0, 1
	j cond
end:


	jr	$ra


	.data
numbers: .word 0, 1, 2, -3, 4, -5, 6, -7, 8, 9 