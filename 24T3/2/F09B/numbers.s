# relevant conditional branches
# ble # <=
# blt # <
# bge # >+
# bgt # >
# beq # ==
# bne # != 

.text
# $t0 -> x
main:	
	li $v0, 4 # printf()
	la $a0, prompt
	syscall

	li $v0, 5 # scanf("%d")
	syscall
	move $t0, $v0 # &x

	ble $t0, 100, notmedium # if (x <= 100)
	bge $t0, 1000, notmedium # if (x >= 1000)

	li $v0, 4 #printf
	la $a0, medium
	syscall

	j epilogue

notmedium:
	li $v0, 4
	la $a0, smallbig
	syscall

epilogue:
	jr $ra

.data
prompt: .asciiz "Enter a number: "
medium: .asciiz "medium\n"
smallbig: .asciiz "small/big\n" 