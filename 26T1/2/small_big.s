main:
    # t0 is x

    li $v0, 4
    la $a0, prompt
    syscall

    li $v0, 5
    syscall
    move $t0, $v0

    ble $t0, 100, print_small_big
    bge $t0, 1000, print_small_big

print_medium:
    li $v0, 4
    la $a0, medium
    syscall
    
    j end


print_small_big:
    li $v0, 4
    la $a0, small_big
    syscall

end:
    li $v0, 0
    jr $ra


.data
prompt: .asciiz "Enter a number: "
medium: .asciiz "medium\n"
small_big: .asciiz "small/big\n"