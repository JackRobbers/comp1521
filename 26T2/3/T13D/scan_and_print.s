# A simple program that will read 10 numbers into an array

N_SIZE = 10

	.text

# $t0 is i
# $t1 is offset
# $t2 is base address
# $t3 is the address of numbers[i]
main:
scan_init:
	li	$t0, 0		# int i = 0;


scan_condition:
	bge	$t0, N_SIZE, scan_end
scan_body:
	# scanf("%d", &numbers[i]);
	li	$v0, 5
	syscall

	# get the offset and base address
	mul $t1, $t0, 4
	la	$t2, numbers
	# offset + base address
	add	$t3, $t1, $t2

	# change the memory
	sw	$v0, ($t3)
scan_step:
	add	$t0, $t0, 1	# i++
	j scan_condition

scan_end:
print_init:
	li $t0, 0
	li $t1, 0
print_condition:
	bge	$t0, N_SIZE, print_end
print_body:
	# printf("%d\n", numbers[i])

	lw $a0, numbers($t1)

	li	$v0, 1
	syscall

	li	$v0, 11
	li	$a0, '\n'
	syscall

print_step:
	add	$t0, $t0, 1	# i++
	add $t1, $t1, 4
	j print_condition
print_end:



	jr	$ra

.data
numbers: .word 0:N_SIZE # int numbers[N_SIZE] = {0};
