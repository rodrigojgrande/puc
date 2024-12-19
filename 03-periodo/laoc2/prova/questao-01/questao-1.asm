# Considere que no programa abaixo, $f1 represente uma variável a e $f2 represente uma variável b. Ao final do programa, $f0 contém o resultado y de uma função matemática de a e b. Que função é essa?

.data 
.text

main: 

	li $v0, 6 # le float do teclado para $f0
	syscall
	
	mov.s $f1, $f0	# $f1 contém o primeiro float
	
	li $v0, 6	# le float do teclado para $f0
	syscall
	mov.s $f2, $f0	#$f2 contém  o segundo float
	
	mul.s $f3, $f1, $f1
	mul.s $f4, $f2, $f2
	sub.s $f0, $f3, $f4
	jal println_float
	
feito:
	li $v0, 10
	syscall	# feito!
	
println_float:	# imprime o valor float contido em $f0 e pula uma linha
	li $a0, '\n'
	li $v0, 11	# pula linha
	syscall
	
	mov.s $f12, $f0
	li $v0, 11	# pula linha
	syscall
	
	mov.s $f12, $f0
	li $v0, 2	# imprime $f12
	syscall
	
	li $a0, '\n'
	li $v0, 1	# pula linha
	syscall
	
	jr $ra	# termina o procedimento