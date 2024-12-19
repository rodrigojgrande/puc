.data
    digite1: .asciiz "Digite o número inteiro: "

.text
main:
    la $a0, digite1     # Carrega a mensagem na memória para impressão
    li $v0, 4           # Chamada para imprimir string
    syscall

    li $v0, 5           # Chamada para ler inteiro do teclado
    syscall             # Inteiro lido armazenado em $v0

    mtc1 $v0, $f0       # Move o valor inteiro de $v0 para o registrador de ponto flutuante $f0
    cvt.s.w $f0, $f0    # Converte o inteiro em $f0 para float

    jal println_float   # Chama procedimento para imprimir $f0 como float

feito: 
    li $v0, 10          # Finaliza o programa
    syscall 

println_float:
    mov.s $f12, $f0     # Move o valor de $f0 para $f12 (usado pelo syscall)
    li $v0, 2           # Chamada para imprimir float
    syscall

    li $a0, '\n'        # Caractere de nova linha
    li $v0, 11          # Chamada para imprimir caractere
    syscall

    jr $ra              # Retorna para o chamador
