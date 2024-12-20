# Calcula a função t = (x^y)/z-t

# #t1 = x (4.0)
# #t2 = z (2.0)
# #t3 = t (1.0)
# #t0 = y (2)
# Resultado deve ser 7

.data
   	digite_x: .asciiz "Digite x: "
   	digite_z: .asciiz "Digite z: "
   	digite_t: .asciiz "Digite t: "
   	digite_y: .asciiz "Digite y: "
   	imprime_f: .asciiz "A função vale: "
   	imprime_div0: .asciiz "Divisão por zero "
.text
main:
    	la $a0, digite_x 	
    	li $v0, 4 	 
	syscall	
	li $v0, 6 	 	# le float do teclado para $f0
    	syscall
    	mov.s $f1, $f0 		# $f1 contem x
    		
	la $a0, digite_z 
    	li $v0, 4 	 
	syscall
	li $v0, 6 	 	# le float do teclado para $f0
    	syscall
    	mov.s $f2, $f0 		# $f2 contem z
    	
    	la $a0, digite_t 
    	li $v0, 4 	 
	syscall
	li $v0, 6 	 	# le float do teclado para $f0
    	syscall
    	mov.s $f3, $f0 		# $f3 contem t
    	
    	la $a0, digite_y 
    	li $v0, 4 	 
	syscall
	li $v0, 5 	 	# le float do teclado para $f0
    	syscall
    	move $t0, $v0 		# $t0 contem y
    	
	bne $t0,$zero, POT 	
	li $t1, 1		# atribuir 1 para um reg float
	mtc1 $t1, $f4		# $f4 contem resultato da potencia
	cvt.s.w $f4, $f4  
	j SAI
	
POT:	mov.s $f4, $f1
LOOP:   beq $t0, 1 , SAI
	mul.s $f4, $f4, $f1 
	addi $t0, $t0, -1
	j LOOP
SAI: 
	# mov.s $f0, $f4
	# jal println_float
	
	# inserir aqui teste para evitar div por zero
	li $t1, 0		# Atribuir 0 para um reg float
	mtc1 $t1, $f7		# $f7 contem zero
	cvt.s.w $f7, $f7	#
	c.eq.s $f2, $f7		# testa se $f2 (z) = 0,
	bc1t SEM_SOLUCAO
	
	
	div.s $f5, $f4, $f2	#$f5 contem resultado da divisao
	sub.s $f6, $f5, $f3 	#$f6 contem o resultado final
	
	la $a0, imprime_f
	li $v0, 4
	syscall
	mov.s $f0, $f6
	jal println_float
	j feito
	
SEM_SOLUCAO:
	la $a0, imprime_div0
	li $v0, 4
	syscall
	mov.s $f0, $f6
	jal println_float
	j feito

	
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
println_int: 
	move $a0, $t0
	li $v0, 1 	 # imprime $t0
    	syscall   
        	
    	li $a0, '\n'
    	li $v0, 11 	 # pula a linha
    	syscall  
    	
        jr   $ra         # termina o procedimento 

.end main
