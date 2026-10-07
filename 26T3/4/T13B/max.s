max:
    # Frame:    [$ra, $s0]   <-- FILL THESE OUT!
    # Uses:     [$ra, $s0, $v0, $a0, $a1]
    # Clobbers: [$v0, $a0, $a1]
    #
    # Locals:           <-- FILL THIS OUT!
    #   - $a0, array
    #     $a1, length
    #   - $s0, first_element
    #
    # Structure:        <-- FILL THIS OUT!
    #   max
    #   -> [prologue]
    #       -> body
    #            -> recurse
    #   -> [epilogue]
max__prologue:
# pushes
        push	$ra
        push	$s0
max__body:
        lw      $s0, ($a0)

        bne     $a1, 1, max__recurse
        
        move	$v0, $s0
        j       max__epiloguew      $s0, ($a0)

        bne     $a1, 1, max__recurse
        
        move	$v0, $s0
        j       max__epilogue

max__recurse:
        add	$a0, $a0, 4
        pop	$ra
        jr	$ra