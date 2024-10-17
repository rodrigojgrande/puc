.data
    variavel: .word 0x0000000e	# Variável de 32 bits a ser impressa

.text
.globl main

main:
	# Carrega o valor da variável na memória
	la $t0, variavel	# Carrega o endereço de 'variavel' em $t0
	lw $t1, 0($t0)		# Carrega o valor da palavra em $t1 (32 bits)
	li $t5, 0		# Registrador para contar o valor 1
	li $t6, 0		# Registrador para contar o valor 0

    # Inicializa o contador de bits (começa do bit mais significativo)
    	li $t2, 31          # Contador para iterar sobre os 32 bits (31 a 0)
    	li $t3, 0x80000000  # Valor para fazer a comporação da palavra a ser lida

# Loop de comparação
print_loop:
	blt $t2, $zero, fim # Se o bit for menor que zero, faz o salto para o fim

    	and $t4, $t1, $t3   # Faz uma comparação AND nos registradores passados e salva em $t4
   	sll $t1, $t1, 1     # Faz um Shift Left Logical no registrador $t1 com 1 bit

    	bne $t4, 0, bit1    # Se o bit for diferente de 0, faz o salto para o bit1

    	li $a0, 48          # Lê o valor 0 em ASCII
    	j print_char        # Faz o salto para print_char
    	add $t6, $t6, 1     # Conta os valores de 0	

bit1:
    	li $a0, 49        # Lê o valor 1 em ASCII
    	j  print_char     # Faz o salto para print_char
    	add $t5, $t5, 1   # Conta os valores de 1

print_char:
    	li $v0, 11      # Serviço de impressão de caractere
    	syscall         # Chama o serviço de sistema

    	# Decrementa o contador de bits e repete o loop
    	sub $t2, $t2, 1 # Subtrai 1 do valor de $t2
    	j print_loop    # Faz o salto para print_Loop

# Finaliza o programa
fim:

    	li $v0, 10  # Serviço de finalização
    	syscall     # Chama o serviço de sistema
