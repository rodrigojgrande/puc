# Qual a saída do programa abaixo?

.data

variavel: .word 0x8000000f   # Declara uma variável de 32 bits com o valor hexadecimal 0x8000000f


.text
.globl main   # Declara o rótulo 'main' como global para ser o ponto de entrada do programa
.ent main     # Indica o início do procedimento principal (main)

main: 

	lw $s1, variavel          # Carrega o valor da variável 'variavel' (0x8000000f) no registrador $s1
	li $t1, 0x80000000        # Carrega 0x80000000 em $t1 (representa o bit mais significativo)
	li $t3, 0                 # Inicializa $t3 como contador de iterações (0)


loop:
	and $t2, $s1, $t1         # Realiza a operação AND entre $s1 e $t1; o resultado está em $t2

	beq $t2, $zero, zero      # Se $t2 == 0, o bit é 0 e pula para o rótulo 'zero'
	li $t0, 0                 # Define $t0 como 0 (indica que o bit atual é 1)
	jal imprime               # Chama o procedimento 'imprime'
	j continua                # Pula para o rótulo 'continua'


zero:
	li $t0, 1                 # Define $t0 como 1 (indica que o bit atual é 0)
	jal imprime               # Chama o procedimento 'imprime'


continua:
	srl $t1, $t1, 1           # Desloca $t1 1 bit para a direita (prepara para verificar o próximo bit)
	addi $t3, $t3, 1          # Incrementa o contador $t3
	bne $t3, 32, loop         # Se $t3 for diferente de 32, repete o loop
	j stop                    # Sai do loop e pula para 'stop' ao final

	
imprime:
	li $v0, 1                 # Serviço do syscall para imprimir um inteiro
	move $a0, $t0             # Move o valor de $t0 (0 ou 1) para $a0, que será impresso
	syscall                   # Realiza o serviço de impressão

	li $v0, 11                # Serviço do syscall para imprimir um caractere
	li $a0, ' '               # Define o caractere como espaço (' ')
	syscall                   # Realiza o serviço de impressão
	jr $ra                    # Retorna ao endereço armazenado em $ra

	
stop:
	li $v0, 10                # Serviço do syscall para encerrar o programa
	syscall                   # Finaliza o programa

	
.end main