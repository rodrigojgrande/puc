.data
    mensagem: .asciiz "Digite o primeiro octeto do endereço IPv4 (0 a 255): "
    mensagem_classe_A: .asciiz "\nClasse A\n"
    mensagem_classe_B: .asciiz "\nClasse B\n"
    mensagem_classe_C: .asciiz "\nClasse C\n"
    invalido: .asciiz "\nValor invalido! Insira um valor entre 0 e 255.\n"

.text

    main:
        # Exibe o mensagem ao usuário
        li $v0, 4		# Chamada do syscall para imprimir string
        la $a0, mensagem        # Carrega o endereço do mensagem em $a0
        syscall                 # Chama o sistema para imprimir

        # Lê o primeiro octeto do teclado
        li $v0, 5 	# Chamada do syscall para ler inteiro
        syscall         # Chama o sistema para ler o valor
        move $t0, $v0   # Move o valor lido para $t0

        # Verifica se o valor está fora do intervalo (0-255)
        li $t1, 0             		# Define valor mínimo (0)
        li $t2, 255           		# Define valor máximo (255)
        blt $t0, $t1, INPUT_INVALIDO  	# Se valor < 0, vai para mensagem de erro
        bgt $t0, $t2, INPUT_INVALIDO  	# Se valor > 255, vai para mensagem de erro

        # Verifica a classe do endereço IPv4
        # Classe A: 0xxxxxxx (0 a 127)
        li $t1, 128		# Limite superior da classe A
        blt $t0, $t1, CLASSE_A  # Se t0 < 128, é classe A

        # Classe B: 10xxxxxx (128 a 191)
        li $t1, 192		# Limite superior da classe B
        blt $t0, $t1, CLASSE_B  # Se t0 < 192, é classe B

        # Classe C: 110xxxxx (192 a 223)
        li $t1, 224 		 # Limite superior da classe C
        blt $t0, $t1, CLASSE_C   # Se t0 < 224, é classe C

        # Se passar daqui, é inválido (não estamos considerando outras classes)
        j INPUT_INVALIDO

    # Classe A: imprime "Classe A"
    CLASSE_A:
        li $v0, 4			# Chamada do syscall para imprimir string
        la $a0, mensagem_classe_A       # Carrega o endereço da string "Classe A"
        syscall                     	# Chama o sistema para imprimir
        j FIM          			# Finaliza o programa

    # Classe B: imprime "Classe B"
    CLASSE_B:
        li $v0, 4			# Chamada do syscall para imprimir string
        la $a0, mensagem_classe_B       # Carrega o endereço da string "Classe B"
        syscall                     	# Chama o sistema para imprimir
        j FIM          			# Finaliza o programa

    # Classe C: imprime "Classe C"
    CLASSE_C:
        li $v0, 4              		# Chamada do syscall para imprimir string
        la $a0, mensagem_classe_C       # Carrega o endereço da string "Classe C"
        syscall                     	# Chama o sistema para imprimir
        j FIM          			# Finaliza o programa

    # Input inválido: imprime mensagem de erro
    INPUT_INVALIDO:
        li $v0, 4		# Chamada do syscall para imprimir string
        la $a0, invalido        # Carrega o endereço da string "Valor invalido!"
        syscall                 # Chama o sistema para imprimir

    # Fim do programa
    FIM:
        li $v0, 10	# Chamada do syscall para encerrar o programa
        syscall		# Chama o sistema para encerrar
