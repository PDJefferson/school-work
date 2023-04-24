.data

.text
main:
      addi $s1, $0, 0   	#1	1 fetch	
      addi $s0, $0, 1		#2	2 fetch 1 decode
      addi $t0, $0, 10		#3	3 fetch 2 decode 1 execute
loop:				#4	4 fetch 3 decode 2 execute 1 store
      slt $t1, $s0, $t0 	#5	5 fetch 4 decode 3 execute 2 store
      beq $t1, $0, done		#6	6 fetch 5 decode 4 execute 3 store
      add $s1, $s1, $s0		#7	7 fetch 6 decode 5 execute 4 store
      sll $s0, $s0, 1		#8	8 fetch 7 decode 6 execute 5 store
  				#9		8 decode 7 execute 6 store
     				#10		         8 exectue 7 store 
    				#11	
      j loop			#12	4 fetch 
 done:				#13	5 fetch	4 decode 
 				#14     6 fetch 5 decode 4 execute
 				#15     7 fetch 6 decode 5 execute 4 store
 				#16	8 fetch 7 decode 6 execute 5 store
 				#17		8 decode 7 execute 6 store
 				#18 			 8 exectue 7 store 
 				#19
 				#20	4 fetch 
 				#21	5 fetch	4 decode 
 				#22	6 fetch 5 decode 4 execute
 				#23	7 fetch 6 decode 5 execute 4 store
 				#24	8 fetch 7 decode 6 execute 5 store
 				#25		8 decode 7 execute 6 store
 				#26 			 8 exectue 7 store 
 				#27
 				#28	4 fetch 
 				#29	5 fetch	4 decode
 				#30	6 fetch 5 decode 4 execute
 				#31	7 fetch 6 decode 5 execute 4 store
 				#32	8 fetch 7 decode 6 execute 5 store
 				#33		8 decode 7 execute 6 store
 				#34			 8 exectue 7 store 
 				#35	
 				#36	4 fetch
 				#37	5 fetch 4 decode
 				#38	6 fetch 5 decode 4 execute
 				#39 	7 fetch 6 decode 5 execute 4 store