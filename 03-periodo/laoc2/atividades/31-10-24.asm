.data
dna_original: .asciiz "GAGCCTACTAACGGGAT"	 				# Sequência de DNA fixa no programa
dna_testado:  .asciiz "CAGTCAGTCAGTCAGTC"			 		# Debug
diferenca: .asciiz "12" # Debug
entrada: .asciiz "Digite a sequência de DNA com 17 caracteres: " 		# Mensagem para o usuário
erro: .asciiz "Erro: As sequências têm tamanhos diferentes.\n"			# Mensagem para o usuário
erro_caractere: .asciiz "Erro: Sequência contém caracteres inválidos.\n" 	# Erro para caracteres inválidos
hamming: .asciiz "Distância de Hamming: "					# Mensagem para o usuário
buffer: .space 19								# Buffer para a entrada do usuário

.text
.globl main

main:
	# Exibir mensagem de entrada
	li $v0, 4				# (Load Immediate) syscall 4: impressão de string
	la $a0, entrada				# (Load Address) carregar endereço da mensagem de entrada
	syscall					# (System Call) executar syscall para imprimir

	# Ler a sequência de DNA do usuário
	li $v0, 8				# (Load Immediate) syscall 8: leitura de string
	la $a0, buffer				# (Load Address) carregar endereço do buffer para entrada do usuário
	li $a1, 19				# (Load Immediate) limite de 29 caracteres para a entrada
	syscall					# (System Call) executar syscall para leitura

	# Remover o caractere de nova linha da entrada do usuário
	li $t0, 0				# (Load Immediate) inicializar índice para percorrer a string
	
remove_nova_linha:
	lb $t1, buffer($t0)			# (Load Byte) carregar caractere atual do buffer
	beq $t1, 0x0A, fim_remove_nova_linha	# (Branch If Equal) se caractere é '\n' (0x0A), termina
	beq $t1, 0, fim_remove_nova_linha	# (Branch If Equal) se caractere é nulo, termina
	addi $t0, $t0, 1			# (Add Immediate) incrementa índice para próximo caractere
	j remove_nova_linha			# (Jump) repete até encontrar '\n' ou nulo
	
fim_remove_nova_linha:
	sb $zero, buffer($t0)			# (Store Byte) substitui '\n' ou caractere extra por nulo
	
 	# Validar caracteres da sequência do usuário (permitidos: C, A, G, T)
   	li $t0, 0  				# (Load Immediate) Reiniciar índice para validar a sequência do usuário

valida_caractere:
    	lb $t1, buffer($t0)  			# (Load Byte) Carregar caractere atual
    	beq $t1, 0, verifica_comprimento  	# (Branch If Equal) Se caractere nulo, termina a validação e inicia a comparação

  	# Checar se caractere é 'C', 'A', 'G' ou 'T'
   	li $t2, 'C'				# (Load Immediate) Carrega o caractere 'C' no registrador $t2
   	li $t3, 'A'				# (Load Immediate) Carrega o caractere 'A' no registrador $t3
   	li $t4, 'G'				# (Load Immediate) Carrega o caractere 'G' no registrador $t4
   	li $t5, 'T'				# (Load Immediate) Carrega o caractere 'T' no registrador $t5
   	beq $t1, $t2, checa_proximo_caractere  	# (Branch If Equal) Se é 'C', vá para o próximo caractere
   	beq $t1, $t3, checa_proximo_caractere 	# (Branch If Equal) Se é 'A', vá para o próximo caractere
   	beq $t1, $t4, checa_proximo_caractere  	# (Branch If Equal) Se é 'G', vá para o próximo caractere
   	beq $t1, $t5, checa_proximo_caractere  	# (Branch If Equal) Se é 'T', vá para o próximo caractere

 	# Exibir mensagem de erro de caractere inválido
   	li $v0, 4				# (Load Immediate) Configura $v0 para 4 (serviço de impressão de string do sistema)
   	la $a0, erro_caractere			# (Load Address) Carrega o endereço da mensagem de erro em $a0
   	syscall					# (System Call) Chama o sistema para exibir a mensagem de erro
  	j fim					# (Jump) Salta para o final do programa, encerrando a execução
    
checa_proximo_caractere:
   	addi $t0, $t0, 1  			# (Add Immediate) Próximo caractere
   	j valida_caractere  			# (Jump) Repetir para verificar o próximo caractere

verifica_comprimento:
	# Comparar comprimento das sequências
	la $t0, dna_original 			# (Load Address) Ponteiro para a sequência fixa
	la $t1, buffer 				# (Load Address) Ponteiro para a sequência do usuário

verifica_comprimento_loop:
	lb $a0, ($t0)				# (Load Byte) carregar caractere da sequência fixa
	lb $a1, ($t1)				# (Load Byte) carregar caractere da sequência do usuário
	beq $a0, 0, calcula_hamming 		# (Branch If Equal) se ambas sequências chegaram ao fim, iniciar cálculo
	beq $a1, 0, mensagem_erro		# (Branch If Equal) se apenas uma terminou, erro de comprimento

	# Avançar para o próximo caractere
	addi $t0, $t0, 1			# (Add Immediate) próximo caractere na sequência fixa
	addi $t1, $t1, 1			# (Add Immediate) próximo caractere na sequência do usuário
	j verifica_comprimento_loop		# (Jump) repetir verificação de comprimento

mensagem_erro:
	# Exibir mensagem de erro de tamanho
	li $v0, 4				# (Load Immediate) syscall 4: impressão de string
	la $a0, erro				# (Load Address) carregar endereço da mensagem de erro
	syscall					# (System Call) executar syscall para imprimir
	j fim					# (Jump) terminar o programa

calcula_hamming:
	# Resetando ponteiros para o cálculo
	la $t0, dna_original			# (Load Address) ponteiro para a sequência fixa
	la $t1, buffer				# (Load Address) ponteiro para a sequência do usuário
	li $t2, 0 				# (Load Immediate) Contador de diferenças (distância de Hamming)

conta_diferencas:
	lb $a0, 0($t0)				# (Load Byte) carregar caractere da sequência fixa
	lb $a1, 0($t1)				# (Load Byte) carregar caractere da sequência do usuário
	beq $a0, 0, exibe_resultado		# (Branch If Equal) Se fim da sequência, exibir resultado

	# Comparar caracteres nas mesmas posições
	bne $a0, $a1, incrementa_hamming	# (Branch If Not Equal) se caracteres diferentes, incrementar distância

proximo_charactere:
	# Avançar para o próximo caractere
	addi $t0, $t0, 1			# (Add Immediate) próximo caractere na sequência fixa
	addi $t1, $t1, 1			# (Add Immediate) próximo caractere na sequência do usuário
	j conta_diferencas			# (Jump) repetir para o próximo par de caracteres

incrementa_hamming:
	addi $t2, $t2, 1			# (Add Immediate) incrementar contador de distância de Hamming
	j proximo_charactere			# (Jump) retornar ao laço para verificar próximo par

exibe_resultado:
	# Exibir mensagem de distância de Hamming
	li $v0, 4				# (Load Immediate) syscall 4: impressão de string
	la $a0, hamming				# (Load Address) carregar endereço da mensagem "Distância de Hamming"
	syscall					# (System Call) executar syscall para imprimir

	# Exibir valor da distância de Hamming
	li $v0, 1				# (Load Immediate) syscall 1: impressão de inteiro
	move $a0, $t2				# Mover valor da distância de Hamming para $a0
	syscall					# (System Call) executar syscall para imprimir o inteiro

fim:
	li $v0, 10 				# (Load Immediate) syscall 10: terminar o programa
	syscall					# (System Call) executar syscall para encerrar
