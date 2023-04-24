.data

ar: .space 40 

.text

     li $t0, 0
     li $t1, 20
boo: 
     bge $t0, $t1, out
     lw $a0, ar($t0)
     jal fun
     addi $t0,$t0,4
     j boo

fun:
     li $v0, 1
     syscall
     jr $ra

out: 
li $v0, 10
syscall