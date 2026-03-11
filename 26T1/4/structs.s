COORD_X_OFFSET = 0
COORD_Y_OFFSET = 8
COORD_SIZE = 16

main:   
    # get the address of the y coordinate of the 4 coord

    la $t0, coords
    li $t1, 4
    mul $t1, COORD_SIZE
    add $t0, $t1
    add $t0, COORD_Y_OFFSET

.data
coords:
# an array of 10 coordinates
.space 160