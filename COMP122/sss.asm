.data
msg: .asciiz "La respuesta es: "
.text



main:
	
	li $t0,5
	li $t1,5
	mul $t0,$t1,$t0
	sub $t0,$t0,$t1
	add $t0,$t0,$t1
	add $t0,$t1,$t0
	
	li $v0,4
	la $a0, msg
	syscall
	
	li $v0,1
	move $a0,$t0
	syscall
	
	li $v0,10
	syscall
	