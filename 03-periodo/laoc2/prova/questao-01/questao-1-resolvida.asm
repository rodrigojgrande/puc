# Considere que no programa abaixo, $f1 represente uma variável a e $f2 represente uma variável b. Ao final do programa, $f0 contém o resultado y de uma função matemática de a e b. Que função é essa?

.data 
.text

main: 
	li $v0, 6               # Configura o serviço de leitura de ponto flutuante.
	syscall                 # Lê um número float do teclado e armazena em $f0.
	mov.s $f1, $f0          # Move o valor lido em $f0 para $f1 (representando a variável 'a').
	
	li $v0, 6               # Configura novamente o serviço de leitura de ponto flutuante.
	syscall                 # Lê outro número float do teclado e armazena em $f0.
	mov.s $f2, $f0          # Move o valor lido em $f0 para $f2 (representando a variável 'b').
	
	mul.s $f3, $f1, $f1     # Calcula a^2 e armazena o resultado em $f3.
	mul.s $f4, $f2, $f2     # Calcula b^2 e armazena o resultado em $f4.
	sub.s $f0, $f3, $f4     # Calcula a^2 - b^2 e armazena o resultado em $f0.
	jal println_float       # Chama o procedimento para imprimir o valor em $f0.
	
feito:
	li $v0, 10              # Configura o serviço de término do programa.
	syscall                 # Finaliza o programa.

# Procedimento para imprimir um valor float e pular uma linha
println_float:              # Início do procedimento.
	li $a0, '\n'            # Configura '\n' (caractere de nova linha) no registrador $a0.
	li $v0, 11              # Configura o serviço de impressão de caractere.
	syscall                 # Imprime uma nova linha.
	
	mov.s $f12, $f0         # Move o valor de $f0 para $f12 (usado para impressão).
	li $v0, 2               # Configura o serviço de impressão de número float.
	syscall                 # Imprime o valor float em $f12.
	
	li $a0, '\n'            # Configura '\n' (caractere de nova linha) no registrador $a0.
	li $v0, 11              # Configura o serviço de impressão de caractere.
	syscall                 # Imprime uma nova linha.
	
	jr $ra                  # Retorna do procedimento para o chamador.
