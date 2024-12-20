.data
    S1: .asciiz "Teste para busca de caracteres"
    encontrou: .asciiz "\nEncontrou o caracter "
    nao_encontrou: .asciiz "\nNao encontrou"
    vezes: .asciiz " vez(es)"
    digite: .asciiz "Digite um caracter: "

# lembrar que caracteres ocupam apenas 1 byte na memoria

.text
main:
    
    la $a0, digite # Carrega o valor no endereco de memoria 
    li $v0, 4 	 # Printa o endereco de memoria
    syscall
    
    li $v0, 12 # Le o caractere
    syscall
    
    move $a0, $v0 # Salva o caractere lido em $a0
    la $a1, S1  #a1 recebe "Teste para busca de caracteres"
    
    jal encontra_caracter
    
    # se $v0=0 indica que nao encontrou o caracter
    # se $v0=1 indica que encontrou o caracter
    beq $v0, $zero, nao  # testa se nao encontrou
    
    la $a0, encontrou 
    li $v0, 4 	 
    syscall
    
    # $v1 contem o numero de incidincias
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
# 1) $a0 contera o caracter a ser procurado na string
# 2) $a1: endereco base de S1 
#Retornos
# 1) $v0 sera 0 se nao encontrar o caracter, e 1 se encontrar
# 2) $v1 contabiliza o numero de incidincias do caracter procurado


	
encontra_caracter: 
      	#...
	li $v0, 0
	li $v1, 0
	li $t0, 1
	
	beq $t0, $zero, Exit
	lb $t1, 0($a1)
	add $a1, $a1, 1
	beq $t1, $a0, Do
		Do: li $v0, 1
		add $v1, $v1, 1
		j encontra_caracter
	
	Exit: jr   $ra # termina o procedimento

.end main
