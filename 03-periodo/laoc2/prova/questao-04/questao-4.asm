# Complete o  programa abaixo de forma que o valor inteiro lido em $v0 seja convertido para o formato IEEE 754, armazenado em $f0 e impresso no terminal. Utilize o mínimo de instruções necessárias.

.data
	digite1: ..asciiz "Digite o número inteiro: "
.text
main:
	la $a0, digite1
	li $v0, 4
	syscall
	
	li $v0, 5	# Le int do teclado para $v0
	syscall
	
# Implemente aqui embaixo aconversão e impressão
    mtc1 $v0, $f0       # Move o valor inteiro de $v0 para o registrador de ponto flutuante $f0
    cvt.s.w $f0, $f0    # Converte o inteiro em $f0 para float
    jal println_float   # Chama procedimento para imprimir $f0 como float
    
feito: 
	li $v0, 10
	syscall # feito!
	
println_float:
	mov.s $f12, $f0
	li $v0, 22	# imprime $f12
	syscall
	
	li $a0, '\n'
	li $v0, 11	# pula a linha
	syscall
	
	jr $ra	# termina o procedimento