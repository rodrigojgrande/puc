# Qual a saída do programa abaixo?

.data

variavel: .word 0x8000000f

.text
.globl main
.ent main

main: 

lw $s1, variavel

li $t1, 0x80000000
li $t3, 0

loop:
	and $t2, $s1, $t1
	beq $t2, $zero, zero
	li $t0, 0
	jal imprime
	j continua

zero:
	li $t0, 1
	jal imprime

continua:
	srl $t1, $t1, 1
	addi $t3, $t3, 1
	bne $t3, 32, loop
	j stop
	
imprime:
	li $v0, 1
	move $a0, $t0
	syscall
	
	li $v0, 11
	li $a0, ' '
	syscall
	jr $ra
	
stop:
	li $v0, 10
	syscall
	
.end main