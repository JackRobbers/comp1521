.text
main:
	#$t0 is n, int n;

	li $v0, 4
	la $a0, prompt
	syscall	# printf("n  = ");
    
	li $v0, 5
	syscall
	move $t0, $v0 # scanf("%d", &n);

    li $t1, 1 # $t1 is fac. int fac = 1;
   
loop_init: #for (int i = 1; i <= n; i++) {
	li $t2, 1 # $t2 is i

loop_condition:
	bgt $t2, $t0, result_print

loop_body:
    mul $t1, $t1, $t2 #    fac *= i;

loop_increment:
	addi $t2, 1
	b loop_condition

result_print:
	li $v0, 4
	la $a0, result
	syscall
	
	li $v0, 1
	move $a0, $t1
	syscall

	li $v0, 11
	li $a0, '\n'
	syscall
    #printf("n! = %d\n", fac);
end:
	jr $ra

.data
prompt:
	.asciiz "n  = "

result:
	.ascii "n! = "