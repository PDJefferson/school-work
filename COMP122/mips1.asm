.data
msg: .asciiz "i + j = "
.text

global:
li $t0, 0
li $t1,0

loopOuter:
beq $t0, 20, loopOuterOut 

loopInner:
beq $t1, 4 ,loopInner0ut
 li $v0, 4
 la $a0 , msg
 syscall
jal addValue 
add $t1,$t1,1
j loopInner
loopInner0ut:
addi $t0, $t0, 1
j loopOuter
loopOuterOut:



addValue:
add $t2, $t0,$t1
move $a0, $t2
li $v0 , 1 
move $a0, $t2
syscall
jr $ra
exit:
li $v0 , 10
syscall