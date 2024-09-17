# Estudar o código exemplo, e modificar a equação para f = (g*h)/(i-j) + k.
.data
str1: .ascii "Exemplo " 
str2: .ascii "de soma "
str3: .asciiz "e subtracao. Resultado: " # string terminada em 0
str4: .asciiz "Erro de divisao por zero!"

msg_g: .asciiz "Digite G: "
msg_h: .asciiz "Digite H: "
msg_i: .asciiz "Digite I: " # string terminada em 0
msg_j: .asciiz "Digite J: "
msg_k: .asciiz "Digite K: "

# Inicialização de variáveis
varg: .word 10
varh: .word 20
vari: .word 10
varj: .word 20
varf: .word 0
vark: .word 10

.text
.globl main
.ent main
main:

#f = (g*h)/(i-j);
#g , h , i e j: regs. $s1, $s2 , $s3  e $s4 respect.; f: registrador $s0

# leitura das variáveis e carga nos registradores

	# imprime mensagem #"Digite G:"
	li $v0, 4
	la $a0, msg_g
	syscall
        
        li $v0, 5
        syscall
	sw $v0, varg
	
	# imprime mensagem "Digite H:"
	li $v0, 4
	la $a0, msg_h
	syscall
	
	li $v0, 5
	syscall
	sw $v0, varh
	
	# imprime mensagem "Digite I:"
	li $v0, 4
	la $a0, msg_i
	syscall
	
	li $v0, 5
	syscall
	sw $v0, vari
	
	# imprime mensagem "Digite J:"
	li $v0, 4
	la $a0, msg_j
	syscall

	li $v0, 5
	syscall
	sw $v0, varj
	
	# imprime mensagem "Digite K:"
	li $v0, 4
	la $a0, msg_k
	syscall
	
	li $v0, 5
	syscall
	sw $v0, vark
	
	lw $s1, varg     
	lw $s2, varh     
	lw $s3, vari     
	lw $s4, varj     
	lw $s5, vark
	
#Somas e subtração
	mul $t0, $s1, $s2   #$t0 contem g * h  
	sub $t1, $s3, $s4   #$t1 contem i - j 

	beq $t1, $zero, erro
	div $s0, $t0, $t1   #$s0: resultado
	add $s0, $s0, $s5   # Resultado + k
	sw $s0, varf  	    # armazena resultado em f
	la $a0, str1 	# endereco da string não terminada com NULL
	li $v0, 4 	# imprime string
	syscall
	li $v0, 1 	# imprime inteiro
	lw $a0, varf	# value for int to print
	syscall
	j feito

erro:  
    	la $a0, str4 	# endereco da string não terminada com NULL
	li $v0, 4 	# imprime string
	syscall

feito:
	li $v0, 10
	syscall # feito!

.end main
