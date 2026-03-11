# Print the danish flag

FLAG_ROWS = 6
FLAG_COLS = 12

# $t0 is row
# $t1 is col
# $t2 is offset

main:
    li $t0, 0
main__outer_condition:
    bge $t0, FLAG_ROWS, main__end

    li $t1, 0
main_inner_condition:
    bge $t1, FLAG_COLS, main__print_newline

    # offset is row * FLAG_COLS + col
    mul $t2, $t0, FLAG_COLS
    add $t2, $t2, $t1
    # gets flag[row][col] into $a0
    lb $a0, flag($t2)
    li $v0, 11
    syscall

    add $t1, $t1, 1
    j main_inner_condition

main__print_newline:
    li $v0, 11
    li $a0, '\n'
    syscall

    add $t0, $t0, 1
    j main__outer_condition

main__end:
    jr $ra

.data
# memory is 1d, we just decide when to split
flag: 
.byte '#', '#', '#', '#', '#', '.', '.', '#', '#', '#', '#', '#',
.byte '#', '#', '#', '#', '#', '.', '.', '#', '#', '#', '#', '#',
.byte '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.',
.byte '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.',
.byte '#', '#', '#', '#', '#', '.', '.', '#', '#', '#', '#', '#',
.byte '#', '#', '#', '#', '#', '.', '.', '#', '#', '#', '#', '#',