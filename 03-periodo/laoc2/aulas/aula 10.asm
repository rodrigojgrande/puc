.data
   	digite1: .asciiz "Digite o numero float: "
.text
main:
    	la $a0, digite1 	
    	li $v0, 4 	 
	syscall	
	
	li $v0, 6 	 	# le float do teclado para $f0
    	syscall
    		
    	# imprime o valor lido do teclado	
	mov.s  $f1, $f0		#$f1 contém o número float
	jal println_float	
			
	# transfere o float para um inteiro sem conversão		
	mfc1 $t0, $f1   	#move de $f1 para $t0 (sem conversão)
	jal println_int_binario 
	
	# implementar aqui a impressão dos componentes 
	#S, E e F do valor contido em $t0
        # ...
        
feito:  
	li $v0, 10
    	syscall # feito!
    	
# imprime valor float contido em $f0 e pula uma linha
println_float:  
	mov.s  $f12, $f0 
	li $v0, 2 	 # imprime $f12
    	syscall   
    	
    	li $a0, '\n'
    	li $v0, 11 	 # pula a linha
    	syscall  
    	
        jr   $ra         # termina o procedimento
     
# imprime valor inteiro contido em $t0 e pula uma linha   
println_int_binario: 
	move $a0, $t0
	li $v0, 35 	 # imprime $t0
    	syscall   
        	
    	li $a0, '\n'
    	li $v0, 11 	 # pula a linha
    	syscall  
    	
        jr   $ra         # termina o procedimento 

println_int: 
	move $a0, $t0
	li $v0, 1 	 # imprime $t0
    	syscall   
        	
    	li $a0, '\n'
    	li $v0, 11 	 # pula a linha
    	syscall  
    	
        jr   $ra         # termina o procedimento 

.end main
