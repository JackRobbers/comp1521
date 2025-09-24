# Prints the square of a number

SQUARE_MAX = 46340

main:   # int main(void) {
    # x is $t0
    # y is $t1

	li 	 $v0, 4	# printf("Enter a number: ");
	la	 $a0, prompt
	syscall

	li   $v0, 5	# scanf("%d", &x);
	syscall		# $v0 is the inputed number
	move $t0, $v0

	ble  $t0, SQUARE_MAX, print_correct

	li  $v0, 4
	la  $a0, too_big
	syscall

	j end

print_correct:
	mul	 $t1, $t0, $t0 # y = x * x

	li   $v0, 1 # printf("%d", y)
	move $a0, $t1
	syscall

	li   $v0, 11 # printf("\n")
	li   $a0, '\n'
	syscall
	
end:
    li   $v0, 0  # return 0;
    jr   $ra  



.data
prompt:
    .asciiz "Enter a number: "
too_big:
	.asciiz "square too big for 32 bits\n"