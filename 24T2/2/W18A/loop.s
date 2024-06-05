#  for (int x = 24; x < 42; x += 3) {
#        printf("%d\n", x);
#    }

.text
main:
	# $t0 is x

	li $t0, 24
	
	
body:
	bge $t0, 42, end # x < 42

	li $v0, 1
	move $a0, $t0 # printf("%d")
	syscall

	li $v0, 11
	li $a0, '\n' # printf("\n")
	syscall

	addi $t0, $t0, 3 # x += 3
	b body
	

end:
	jr $ra