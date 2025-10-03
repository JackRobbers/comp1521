N_SiZE = 10

main:
	li $t0, 0 # int i = 0 

	la $t1, numbers
scan_condition:
	bge $t0, N_SiZE, print

	# scanf a number
	li $v0, 5
	syscall

	# save it at numbers[i]
	mul $t2, $t0, 4
	add $t2, $t1, $t2
	sw $v0, ($t2)

	add $t0, 1
	j scan_condition

print:
	li $t0, 0
	la $t1, numbers


print_condition:
	bge $t0, N_SiZE, end

	# get numbers[i]
	lw $a0, ($t1)
	add $t1, 4

	# print it
	li $v0, 1
	syscall

	li $v0, 11
	li $a0, '\n'
	syscall
 
	add $t0, 1
	j print_condition

end:

	jr $ra

.data
numbers: .word 0:N_SiZE