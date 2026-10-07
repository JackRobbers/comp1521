	.text
max:
    # Frame:    [$ra, $s0] 
    # Uses:     [$ra, $s0, $v0, $a0, $a1]
    # Clobbers: [$v0, $a0, $a1]
    #
    # Locals:
    #   - $a0 - &array
    #	- $a1 - length
    #	- $s0 - first_element
    #     $v0 - max_so_far
    #
    # Structure:
    #   max
    #   -> [prologue]
    #       -> body
    #           -> recusive_case
    #   -> [epilogue]
max__prologue:
	# pushes

	push	$ra
	push	$s0

max__body:
	lw	$s0, ($a0)

	bne	$a1, 1, max__recursive_case

	move	$v0, $t0
	j  max__epilogue

max__recursive_case:

	add	$a0, $a0, 4
	sub	$a1, $a1, 1
	jal max

	ble	$s0, $v0, max__epilogue

	move	$v0, $s0

max__epilogue:
	# pops + jr $ra
	pop	$s0
	pop	$ra
	jr	$ra