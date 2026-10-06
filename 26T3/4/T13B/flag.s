.text

FLAG_COLS = 6
FLAG_ROWS = 6

# $t0 is x ,$t1 is y
main:
outer_init:
        li      $t0, 0	

outer_cond:
        bge	$t0, FLAG_ROWS, outer_end

outer_body:
inner_init:
        li      $t1, 0

inner_cond:
        bge	$t1, FLAG_COLS, inner_end

inner_body:
        # get &flag[row][col]

        # offset is row * FLAG_COLS  + col
        # more generally (i * width + j) * sizeof(type)
        mul	$t3, $t0, FLAG_COLS
        add	$t3, $t3, $t1

        # load into $a0
        lb	$a0, flag($t3)
        #print it
        li	$v0, 11
        syscall

inner_step:
        add	$t1, $t1, 1
        j inner_cond

inner_end:
        li	$v0, 11
        li	$a0, '\n'
        syscall
outer_step:
        add	$t0, $t0, 1
        j outer_cond

outer_end:
        jr	$ra

.data

flag:   .byte '#', '#', '#', '#', '#', '.', '.', '#', '#', '#', '#', '#'
        .byte '#', '#', '#', '#', '#', '.', '.', '#', '#', '#', '#', '#'
        .byte '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.'
        .byte '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.'
        .byte '#', '#', '#', '#', '#', '.', '.', '#', '#', '#', '#', '#'
        .byte '#', '#', '#', '#', '#', '.', '.', '#', '#', '#', '#', '#'