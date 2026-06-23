        .text
FLAG_ROWS = 6
FLAG_COLS = 12


# $t0 is row
# $t1 is col
main:   
        # for (int row = 0; row < FLAG_ROWS; row++) {
outer_init:
        li      $t0, 0
        
outer_cond:
        bge     $t0, FLAG_ROWS, outer_end

outer_body:
        # for (int col = 0; col < FLAG_COLS; col++) {
inner_init:
        li	$t1, 0

inner_cond:
        bge     $t1, FLAG_COLS, inner_end

inner_body:
        # printf("%c", flag[row][col]);

        # offset is row * FLAG_COLS + col
        # more generally: y * WIDTH + x
        mul	$t2, $t0, FLAG_COLS
        add	$t2,  $t2, $t1
        lb	$a0, flag($t2)

        # make $a0 flag[row][col]
        li	$v0, 11
        syscall
inner_step:
        add	$t1, $t1, 1
        j inner_cond
inner_end:
        # }

        # printf("\n");
        li	$v0, 11
        li	$a0, '\n'
        syscall

outer_step:
        add	$t0, $t0, 1
        j outer_cond
        # }
outer_end:
        jr	$ra

        .data
flag: 
    .byte '#', '#', '#', '#', '#', '.', '.', '#', '#', '#', '#', '#'
    .byte '#', '#', '#', '#', '#', '.', '.', '#', '#', '#', '#', '#'
    .byte '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.'
    .byte '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.'
    .byte '#', '#', '#', '#', '#', '.', '.', '#', '#', '#', '#', '#'
    .byte '#', '#', '#', '#', '#', '.', '.', '#', '#', '#', '#', '#'