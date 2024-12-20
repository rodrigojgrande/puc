# S = Primeiro Bit
# E = 8 Bits
# F = 23 Bits

# Descobrindo um valor de S
# li $t1, 0x8000000
# and $t3. $t0, %t1

# Descobrindo o valor de E
# srl $t3, $t0, 23
# li $t1, 0x000000ff
# and $t3, $t3, $t1

# Descobrindo o valor de F
# li $t1, 0xff7fffff
# and $t3, $t0, $t1


.data
prompt: .asciiz "Digite um valor em ponto flutuante: "
S_msg: .asciiz "S: "
E_msg: .asciiz "E: "
F_msg: .asciiz "F: "
newline: .asciiz "\n"

.text
.globl main

main:
    # Exibe o prompt para o usuário inserir um valor em ponto flutuante
    li $v0, 4
    la $a0, prompt
    syscall

    # Leitura de um valor de ponto flutuante do teclado
    li $v0, 6          # syscall 6: ler ponto flutuante para $f0
    syscall

    # Move o valor lido em $f0 para $t0 para manipulação em inteiro
    mfc1 $t0, $f0

    # Extrair S (bit de sinal) - bit 31
    srl $t1, $t0, 31   # Desloca 31 bits para a direita
    andi $t1, $t1, 1   # Mantém apenas o bit menos significativo (S)
    
    # Exibir S
    li $v0, 4
    la $a0, S_msg
    syscall
    li $v0, 1
    move $a0, $t1      # Coloca S no registrador para impressão
    syscall

    # Imprimir nova linha
    li $v0, 4
    la $a0, newline
    syscall

    # Extrair E (expoente) - bits 30 a 23
    srl $t2, $t0, 23   # Desloca 23 bits para a direita
    andi $t2, $t2, 0xFF # Mantém os 8 bits menos significativos para o expoente

    # Exibir E
    li $v0, 4
    la $a0, E_msg
    syscall
    li $v0, 1
    move $a0, $t2      # Coloca E no registrador para impressão
    syscall

    # Imprimir nova linha
    li $v0, 4
    la $a0, newline
    syscall

    # Extrair F (mantissa) - bits 22 a 0
    andi $t3, $t0, 0x7FFFFF # Mantém apenas os bits 22 a 0

    # Exibir F
    li $v0, 4
    la $a0, F_msg
    syscall
    li $v0, 1
    move $a0, $t3      # Coloca F no registrador para impressão
    syscall

    # Imprimir nova linha
    li $v0, 4
    la $a0, newline
    syscall

    # Encerrar o programa
    li $v0, 10
    syscall
