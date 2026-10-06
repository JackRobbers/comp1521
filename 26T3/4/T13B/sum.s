.text
main:   
        push    $ra

        li	$a0, 11
        li	$a1, 13
        li	$a2, 17
        li	$a3, 19
        # modifies $ra to be the adress of t he next instruction
        jal     sum4

        move	$a0, $v0
        li	$v0, 1
        syscall

        li	$v0, 11
        li	$a0, '\n'
        syscall

        pop	$ra
        jr	$ra

sum2:   
        push	$s0
        add	$s0, $a0, $a1
        move	$v0, $s0
        pop	$s0
        jr	$ra

sum4:   
        push	$ra
        push    $s0
        push	$s2
        push	$s3

        move	$s2, $a2
        move	$s3, $a3

        jal	sum2
        move	$s0, $v0

        move	$a0, $s2
        move	$a1, $s3
        jal     sum2

        move	$a0, $s0
        move	$a1, $v0
        jal     sum2

        pop	$s3
        pop	$s2
        pop	$s0
        pop	$ra
        jr      $ra