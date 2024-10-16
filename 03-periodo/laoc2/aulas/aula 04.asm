.data
    S1: .asciiz "Teste para busca de caracteres"
    encontrou: .asciiz "\nEncontrou o caracter "
    nao_encontrou: .asciiz "\nNao encontrou"
    vezes: .asciiz " vez(es)"
    digite: .asciiz "Digite um caracter: "

# lembrar que caracteres ocupam apenas 1 byte na memória

.text
main:
    
    la $a0, digite 
    li $v0, 4 	 
    syscall
    
    li $v0, 12
    syscall
    
    move $a0, $v0
    la $a1, S1  
    
    jal encontra_caracter
    
    # se $v0=0 indica que não encontrou o caracter
    # se $v0=1 indica que encontrou o caracter
    beq $v0, $zero, nao  # testa se não encontrou
    
    la $a0, encontrou 
    li $v0, 4 	 
    syscall
    
    # $v1 contem o número de incidências
    move $a0, $v1
    li $v0, 1 	 
    syscall
    
    la $a0, vezes 
    li $v0, 4 	 
    syscall
   
    j feito
nao: 
    la $a0, nao_encontrou 
    li $v0, 4 	 
    syscall
feito:    
    li $v0, 10
    syscall # feito!

# procedimento "encontra_caracter"
# Argumentos
# 1) $a0 conterá o caracter a ser procurado na string
# 2) $a1: endereço base de S1 
#Retornos
# 1) $v0 será 0 se não encontrar o caracter, e 1 se encontrar
# 2) $v1 contabiliza o número de incidências do caracter procurado

encontra_caracter: 
      	#...

	
        jr   $ra                 # termina o procedimento

.end main
