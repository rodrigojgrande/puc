.data
    origem: .asciiz "Qualquer texto a ser copiado"  # String estática de origem

.text
    .globl main

main:
    # Imprime a string de origem
    la $a0, origem       # Carrega o endereço da string estática em $a0
    li $v0, 4            # Syscall para imprimir string
    syscall
    
    # Imprime o caractere '/'
    li $a0, 47           # ASCII de '/'
    li $v0, 11           # Syscall para imprimir caractere
    syscall
    
    # Chama o procedimento MEMCOPY para copiar a string
    la $a0, origem       # Carrega o endereço da string de origem em $a0
    jal MEMCOPY          # Chama o procedimento MEMCOPY

    # Imprime a string de destino (copiada)
    move $a0, $v0        # Move o endereço da string copiada (retornado por MEMCOPY) para $a0
    li $v0, 4            # Syscall para imprimir string
    syscall

    # Finaliza o programa
    li $v0, 10
    syscall              # Syscall para sair do programa

# Procedimento de cópia do conteúdo de memória (string de origem) para uma 
# área de memória alocada dinamicamente.
# Parâmetro de entrada: $a0 deve conter o endereço dos dados de origem
# Valor de retorno: $v0 conterá o endereço dos dados de destino da cópia 

MEMCOPY:
    
    move $t0, $a0       
    li $t1, 0            

contador:
    lb $t2, 0($t0)       
    beq $t2, $zero, alocar_memoria  
    addi $t1, $t1, 1   
    addi $t0, $t0, 1     
    j contador          

alocar_memoria:
    addi $t1, $t1, 1   
    li $v0, 9
    move $a0, $t1        
    syscall          
    move $t3, $v0      
    la $t0, origem    

copia_loop:
    lb $t4, 0($t0)     
    sb $t4, 0($t3)       
    beq $t4, $zero, finalizar_copia 
    addi $t0, $t0, 1     
    addi $t3, $t3, 1    
    j copia_loop        

finalizar_copia:
    jr $ra           
