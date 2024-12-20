.data
dna_original: .asciiz "GAGCCTACTAACGGGAT"
entrada: .asciiz "Digite a sequência de DNA: "
erro: .asciiz "As sequências são de tamanhos diferentes. Tente de novo\n"
hamming: .asciiz "Distância de Hamming: "
buffer: .space 19 # Buffer de entrada do usuário

.text

main:

li $v0, 4
la $a0, entrada
syscall


li $v0, 8

la $a0, buffer
li $a1, 19
syscall


li $t0, 0

remove_linhanova:

lb $t1, buffer($t0)
beq $t1, 0x0A, end_remove_linha

beq $t1, 0, end_remove_linha

addi $t0, $t0, 1
j remove_linhanova

end_remove_linha:
sb $zero, buffer($t0)

la $t0, dna_original
la $t1, buffer

tamanho:
lb $a0, ($t0)

lb $a1, ($t1)

beq $a0, 0, hamming_calculo

beq $a1, 0, erro_msg


addi $t0, $t0, 1

addi $t1, $t1, 1
j tamanho

erro_msg:

li $v0, 4
la $a0, erro
syscall
j end

hamming_calculo:

la $t0, dna_original

la $t1, buffer
li $t2, 0

cotagem_diferencas:
lb $a0, ($t0)
lb $a1, ($t1)
beq $a0, 0, print

bne $a0, $a1, hamming_incrementa

char_prox:

addi $t0, $t0, 1

addi $t1, $t1, 1
j cotagem_diferencas

hamming_incrementa:
addi $t2, $t2, 1

j char_prox

print:

li $v0, 4
la $a0, hamming
syscall

li $v0, 1
move $a0, $t2
syscall

end:
li $v0, 10
syscall