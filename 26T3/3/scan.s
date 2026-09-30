# A simple program that will read 10 numbers into an array

N_SIZE = 10

        .text
main:

scan_loop_init:
        li      $t0, 0   # int i = 0;

scan_loop_cond:
        bge     $t0, N_SIZE, scan_loop_end

scan_loop_body:
        li	$v0, 5
        syscall

        # want to put &numbers[i] in $t2
        # base address
        la      $t1, numbers
        # offset
        mul	$t2, $t0, 4
        add	$t2, $t2, $t1

        sw      $v0, ($t2)

scan_loop_step:
        add	$t0, $t0, 1
        j       scan_loop_cond

scan_loop_end:
print_loop_init:
        li	$t0, 0

print_loop_cond:
        bge     $t0, N_SIZE, print_loop_end

        # make $a0 the value at &numbers[i]
        mul	$t2, $t0, 4
        lw      $a0, numbers($t2)
# if numbers[i] < 0 {
        bge     $a0, 0, print_num
#       numbers[i] += 42

        add     $a0, $a0, 42
        sw	$a0, numbers($t2)
#       numbers[i] += 42

print_num:
        li	$v0, 1
        syscall

        li	$v0, 11
        li	$a0, '\n'
        syscall

        add	$t0, $t0, 1
        j print_loop_cond

print_loop_end:
        jr      $ra
        .data
numbers: .word 0:N_SIZE