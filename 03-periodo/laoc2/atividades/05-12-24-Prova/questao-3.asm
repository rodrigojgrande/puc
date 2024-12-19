# O programa abaixo deve copiar o conteúdo do string S1 sobre o string S2. Esta cópia deve ser  implementada pelo procedimento strcpy. Complete o programa abaixo de forma que acópia seja feita byte à byte até que seja encontrado um byte 0  em S1. 

.data
	S1: .asciiz "Eu gosto de assembly   "
	S2: .asciiz "escrever aqui          "
	
# observações:
# 1) endereço base de S1 está em $a1
# 2) endereço base de S2 está em $a0
# lembrar que caracteres apenas ocupam  byte na memória

. text
main: 
	# imprime verrsão original do string S2
	la $a0, S2
	li $v0, 4
	syscall
	
	# Lê endereços dos strings na memória
	la $a1, S1
	la $a0, S2
	
	jal strcpy
	
	# imprime versão final do string S2
	la $a0, S2
	li $v0, 4
	syscall
	
	li $v0, 10
	syscall # Feito
	
strcpy:
	add $t0, $zero, $zero	# i = 0
	L1: add $t1, $a1, $t0	# atualiza endereço a ser lido de S1
	    lb $t2, 0($t1)	# 
	    			# Se caracter for '\0' deixar o laço
	    			# atualizar o registrador com endereço do elemento em S2
	    			# Armazenar o byte lido em S2
	    addi $t0, $t0, 1	# i = i+ 1
	    j L1		# Volta pro começo do loop
	out:
	    jr $ra		# termina o procedimento
	    
.end main