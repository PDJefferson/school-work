.data
theArray: .space 160	#40 * 4
.text

main:
	li $a1, 2 #n 
	mul $a1,$a1 , 4 #working with bytes 
	li $t1,1 #number
	li $t2,0 #index
	
	sw $t1, theArray($t2)
	
	addi $t2 ,$t2,4 #increment I by 4 bits
	
	sw $t1,theArray($t2)

do:
	add $t4,$a1, -4
	lw $t5, theArray($t4)
	
	add $t6, $a1,-8
	lw $t7,theArray($t6)
		
	add $t9, $t7,$t5
	
	sw $t9,theArray($a1)
	addi $a1, $a1,4
while:
	bge $a1, 160,whileOut
	j do
whileOut:

exit:
li $v0 ,10
syscall

	
	
