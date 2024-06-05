#      for (int i = 1; i <= 10; i++) {
#        for (int j = 0; j < i; j++) {
#           printf("*");
#        }
#        printf("\n");
#    }

.text
main:
	# $t0 is i
	# $t1 is j

outer_loop_init:
	li $t0, 1

outer_loop_condition:
	bgt $t0, 10, end
	
inner_loop_init:
	li $t1, 0

inner_loop_condition:
	bge $t1, $t0, outer_loop_body

inner_loop_body:
	li $v0, 11
	li $a0, '*'
	syscall

inner_loop_increment:
	addi $t1, 1
	b inner_loop_condition

outer_loop_body:
	li $v0, 11
	li $a0, '\n'
	syscall

outer_loop_increment:
	addi $t0, 1
	b outer_loop_condition

end:
	jr $ra