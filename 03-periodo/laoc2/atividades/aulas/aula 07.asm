.data
    origem: .asciiz "Qualquer texto a ser copiado"
.text
main:
    # imprime string origem
    la $a0, origem      
    li $v0, 4      
    syscall
    
    # imprime '/'
    li $a0, 47     
    li $v0, 11      
    syscall
    
    la $a0, origem      
    jal MEMCOPY  #faz a copia entre blocos

    # imprime o conteúdo da área destino
    move $a0, $v0  
    li $v0, 4      
    syscall

    li $v0, 10
    syscall # feito!

# Procedimento de cópia do conteúdo de memória (string de origem) para uma 
# área de memória alocada dinamicamente.
# Parâmetro de entrada: $a0 deve conter o endereço dos dados de origem
# Valor de retorno: $v0 conterá o endereço dos dados de destino da cópia 
MEMCOPY:  
    ...          # implementar aqui...
    jr   $ra     # termina o procedimento