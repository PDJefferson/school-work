# double myfunction (int n)
#  return n == 1 ? 5.0 : ((4.0/n) + n*n*n) * myfunction (n-1); 
#} (n-1)* ((4.0/(n*n*n))+ (31*n*n)- (2*n));

     .data
 q1:     .asciiz "please provide the value of n \n"
 result: .asciiz  "The result is: \n"
    .text 
    .globl main
 main:
      li $v0, 4 
      la $a0, q1 
      syscall

      li $v0, 5 
      syscall

      move $a0, $v0 #holds the value of the user

      jal recFunc

      li $v0, 4
      la $a0, result
      syscall
      
      li $v0, 3
      syscall

end:
      li $v0, 10
      syscall



recFunc:
      addi $sp, $sp, -8
      sw $ra, 0($sp)
      sw $a0, 4($sp)
      
      li $t0, 2   #base case 2 
      bge $a0, $t0, reCall

      lw $ra, 0($sp)  
      lw $a0, 4($sp)
      addi $sp, $sp, 8
      li $t1, 33

      mtc1 $t1, $f12
      cvt.d.w $f12, $f12
      jr $ra
     
	
reCall:
      addi $a0, $a0, -1
	 jal recFunc
      

      lw $ra, 0($sp)
      lw $a0, 4($sp)
      addi $sp, $sp, 8

      li $t1,4
      mtc1 $t1, $f4
      cvt.d.w $f4, $f4
      
      mtc1 $a0, $f6 #n
      cvt.d.w $f6, $f6
      
      li $t5, 2
      mtc1 $t5, $f10
      cvt.d.w $f10, $f10
      
      li $t6 ,31
      mtc1 $t6, $f14
      cvt.d.w $f14, $f14
      
     
      
      mul.d $f8, $f6, $f6 
      mul.d $f8, $f8, $f6 #n^3
      div.d $f4, $f4, $f8 #4/n^3
     
      mul.d $f16, $f10,$f6 #2*n
      
      mul.d $f18, $f6,$f6
      mul.d $f18, $f14, $f18 #31 *n*n
        
      add.d $f20, $f4, $f18 #((4.0/n) + 31*n*n).
      
      sub.d $f22, $f20, $f16
      
      mul.d $f12, $f12,$f22
     
      
      jr $ra
