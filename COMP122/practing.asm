.data
a: .word 1,2,3,4,5,635,64,7,8 
msg: .asciiz "The average is " 
.text

main:
	li $a1,9 #size 
	mul $a1 ,$a1 ,4 #working with bytes
	
	li $v0,4 #prints msg
	la $a0, msg
	syscall
	
	jal calculateAverage
	
	li $v0,1
	move $a0, $t2
	syscall
	
	li $v0,10
	syscall
calculateAverage:
	li $t1, 0 #i
	li $t2, 0 #n
	
loop:
	bge $t1, $a1,loopOut
	
	lw $t3, a($t1) #store the value of the array at $t3
	
	add $t2,$t3,$t2
	
	addi $t1, $t1 ,4
	j loop
loopOut:
	#divide after
	div $t2,$t2,9
	jr $ra

	
	

