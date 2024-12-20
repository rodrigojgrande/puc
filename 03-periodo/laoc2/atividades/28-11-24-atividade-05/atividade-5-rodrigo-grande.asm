.data
msg_z: .asciiz "Digite o valor de z: "
msg_y: .asciiz "Digite o valor de y: "
msg_w: .asciiz "Digite o valor de w: "
resultado_msg: .asciiz "O resultado é: "

.text


main:
        # z
        li $v0, 4               
        la $a0, msg_z
        syscall

        li $v0, 5                
        syscall
        move $t0, $v0            

        #y
        li $v0, 4                
        la $a0, msg_y
        syscall

        li $v0, 5                 
        syscall
        move $t1, $v0             

        # w
        li $v0, 4                
        la $a0, msg_w
        syscall

        li $v0, 5                 
        syscall
        move $t2, $v0             
	
	#armazena nos registradores
	move $a0, $t0
	move $a1, $t1
	move $a2, $t2
	
	#pula pra função
        jal func
	
	#mensagem de resultado
       	move $t0, $v0
        li $v0, 4                
        la $a0, resultado_msg
        syscall
        
        #imprime resultado
	move $a0, $t0
        li $v0, 1                 
        syscall

        #exit
        li $v0, 10
        syscall

func:
	#Empilhando
        addi $sp, $sp, -4        
        sw $s0, 0($sp) 
        addi $sp, $sp, -4                   
        sw $s1,0($sp)      

        # (y + z)
        add $s1, $a0, $a1        

        #Testa divisão por zero
        beqz $a2, div_zero

        # (y + z) / w
        div $v0, $s1, $a2             
	
	#Desempilhando
        addi $sp, $sp, 4        
        lw $s1, 0($sp)    
        addi $sp, $sp, 4                
        lw $s0, 0($sp)           

	#volta
        jr $ra                   
        
div_zero:
        #sai com resultado -1
        li $v0, -1               
        jr $ra                    