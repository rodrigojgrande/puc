.data
    origem: .asciiz "Qualquer texto a ser copiado"
.text
main:
    # imprime string origem
    la $a0, origem      # Carrega o endereço da string "origem" em $a0
    li $v0, 4      	# Serviço de impressão de string
    syscall		# Chama o serviço de sistema
    
    # imprime '/'
    li $a0, 47    	# Carrega o caractere '/' (ASCII 47)
    li $v0, 11      	# Serviço de impressão de caractere
    syscall		# Chama o serviço de sistema
    
    # Chama o procedimento MEMCOPY para copiar o conteúdo da origem
    la $a0, origem      # Carrega o endereço da string "origem" em $a0
    jal MEMCOPY  	# Faz a copia entre blocos

    # imprime o conteúdo da área destino
    move $a0, $v0  	# Move o endereço da string copiada (destino) para $a0
    li $v0, 4      	# Serviço de impressão de string
    syscall		# Chama o serviço de sistema

    # Finaliza o programa
    li $v0, 10		# Serviço de finalização
    syscall 		# feito!

# Procedimento de cópia do conteúdo de memória (string de origem) para uma 
# área de memória alocada dinamicamente.
# Parâmetro de entrada: $a0 deve conter o endereço dos dados de origem
# Valor de retorno: $v0 conterá o endereço dos dados de destino da cópia 
MEMCOPY:  
    # Alocar dinamicamente 1024 bytes
    move $t0, $a0 	# Faz uma cópia do $a0 para o $t0
    li $t1, 0		# Monta um contador com %t1
    
    CONTADOR:
    	lb $t2, 0($t0)	# Carrega o byte de $t0 para $t2
    	beq $t2, $zero, MEMORY_ALOC	# Se byte carregado for igual a 0 faz o salto
    	addi $t1, $t1, 1   # Incremente $t1 (Contador)
   	addi $t0, $t0, 1   # Incrementa $t0 (Palavra)
    	j CONTADOR         # Repete o processo
    	
    MEMORY_ALOC:
    addi $t1, $t1, 1	# Incrementa o contador com +1
    li $v0, 9		# Serviço de alocação de memória (sbrk)
    move $a0, $t1       # Move o $t1 para o $a0
    syscall          	# Chama o serviço de sistema
    move $t3, $v0       # Aloca o valor de $v0 para $t0
    la $t0, origem	# Carrega o endereço de origem para $t0

    copia_loop:
    lb $t4, 0($t0)     
    sb $t4, 0($t3)       
    beq $t4, $zero, finalizar_copia 
    addi $t0, $t0, 1     
    addi $t3, $t3, 1    
    j copia_loop        
    
    finalizar_copia: 
    move $v0, $t2
    jr   $ra     # termina o procedimento