.data
S1: .asciiz "Teste para busca de caracteres"
encontrou: .asciiz "\nEncontrou o caracter "
nao_encontrou: .asciiz "\nNao encontrou"
vezes: .asciiz " vez(es)"
digite: .asciiz "Digite um caracter: "

# lembrar que caracteres ocupam apenas 1 byte na mem�ria

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

# se $v0=0 indica que n�o encontrou o caracter
# se $v0=1 indica que encontrou o caracter
beq $v0, $zero, nao # testa se n�o encontrou

la $a0, encontrou
	li $a1, 10
	syscall # feito!
li $v0, 4
syscall

# $v1 contem o n�mero de incid�ncias
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
# 2) $v1 contabiliza o numero de incidencias do caracter procurado


encontra_caracter:
#...
li $v0, 0 # $v0 Recebe 0
li $v1, 0 # v1 Recebe 0 

Loop:
	lb $t0,0($a1) # Carrega $t0 com o endereço da palavra em S1
	beq $t0,$zero, Exit # Se o valor comparado for igual a 0, ele acaba a execução

	beq $t0,$a0, Do # Se o valor de $t0 for igual ao do caractere comparado, entra no loop
	addi $a1, $a1, 1 # Adicioa +1 a $a1 e Vai para o próximo endereço 
	j Loop # Vai para o loop

Do: 
	#addi $a1, $a1,1 # Adiciona +1 para o endereço de base
	li $v0,1 # Carrega 1 para o $v0
	addi $v1, $v1, 1 # Adiciona +1 ao número de ocorrencias
	
	sub $t0, $t0, 32
	sb $t0, $a1
	addi $a1, $a1,1 # Adiciona +1 para o endereço de base
	j Loop
	

Exit: 
	jr $ra
.end main
