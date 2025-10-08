X_OFFSET = 0
Y_OFFSET = 8

main:
	la 	$t1, _coord
	lw	$t0, Y_OFFSET($t1)

.data
_coord:
	.space 16