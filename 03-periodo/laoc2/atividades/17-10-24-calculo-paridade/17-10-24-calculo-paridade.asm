.data # Segmento de data
    # variavel: .word 0x0000000e  # Variável de 32 bits a ser verificada para paridade
    variavel: .word 0x0000000f  # Variável de 32 bits a ser verificada para impar
    
.text # Segmento de texto
.globl main # Declara o rótulo main como um símbolo global

main:
    # Carrega o valor da variável da memória
    la $t0, variavel      	# (Load Address) Carrega o endereço de 'variavel' em $t0
    lw $t1, 0($t0)        	# (Load Word) Carrega o valor da palavra em $t1 (32 bits)
    li $t5, 0             	# (Load Immediate) Contador para o número de bits "1" encontrados

    # Inicializa o contador de bits (começa do bit mais significativo)
    li $t2, 32             	# (Load Immediate) Contador para iterar sobre os 32 bits

# Loop de contagem de bits "1"
count_bits:
    beq $t2, 0, check_parity  	# (Branch If Equal) Se todos os bits foram contados, vá verificar a paridade

    andi $t4, $t1, 1        	# (And Immediate) [And Bit a Bit] Verifica o bit menos significativo em $t1
    beq $t4, $zero, next_bit 	# (Branch If Equal) Se o bit for 0, vá para o próximo bit

    addi $t5, $t5, 1       	# (Add Immediate) Incrementa o contador de bits "1" se o bit for 1

next_bit:
    srl $t1, $t1, 1        	# (Shift Right Logical) Faz um shift right lógico em $t1 para verificar o próximo bit
    subi $t2, $t2, 1        	# (Subtract Immediate) Decrementa o contador de bits
    j count_bits            	# (Jump) Repete o loop para o próximo bit

# Verificação de paridade
check_parity:
    andi $t6, $t5, 1        	# (And Immediate) Verifica se o contador de bits "1" é par ou ímpar
    beq $t6, $zero, print_zero 	# (Branch If Equal) Se $t6 for 0 (paridade par), o bit de ajuste é 0

    # Imprime o bit de ajuste 1 para paridade par
    li $a0, 1               	# (Load Immediate) O valor de ajuste para paridade par é 1
    j print_result		# (Jump) 

print_zero:
    li $a0, 0               	# (Load Immediate) O valor de ajuste para paridade par é 0

print_result:
    li $v0, 1               	# (Load Immediate) Serviço de impressão de número inteiro
    syscall                 	# (System Call) Chama o serviço de sistema para imprimir o valor de ajuste

# Finaliza o programa
fim:
    li $v0, 10              	# (Load Immediate) Serviço de finalização
    syscall                 	# Chama o serviço de sistema
