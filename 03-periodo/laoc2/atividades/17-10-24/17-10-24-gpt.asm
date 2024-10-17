.data
    bit_0: .asciiz "0\n"       # String para o bit '0'
    bit_1: .asciiz "1\n"       # String para o bit '1'

.text
main:
    # Carregar a palavra no registrador $s0
    li $s0, 0x0000000e         # Palavra a ser verificada (exemplo: 0000 0000 0000 0000 0000 0000 0000 1110)

    # Inicializar contador de bits "1"
    li $t0, 0                 # $t0 armazena o número de bits "1"
    li $t1, 32                # $t1 armazena o número total de bits (32)
    
count_ones_loop:
    # Verificar o bit menos significativo
    andi $t2, $s0, 1          # $t2 = $s0 & 1 (verifica o bit menos significativo)
    beq $t2, $zero, skip_inc  # Se o bit for 0, pula a incrementação
    addi $t0, $t0, 1          # Incrementa o contador de bits "1"

skip_inc:
    # Deslocar a palavra para a direita para verificar o próximo bit
    srl $s0, $s0, 1           # Desloca $s0 um bit à direita
    subi $t1, $t1, 1          # Decrementa o contador de bits (32 bits no total)
    bgtz $t1, count_ones_loop # Continua o loop até verificar todos os 32 bits

    # Verificar a paridade: se o número de bits "1" for ímpar, imprime '1', caso contrário, imprime '0'
    andi $t3, $t0, 1          # Verifica se o número de bits "1" é ímpar ($t3 = $t0 & 1)
    beq $t3, $zero, print_0   # Se for par, imprime '0'
    b print_1                 # Caso contrário, imprime '1'

print_0:
    la $a0, bit_0             # Carrega a string "0" em $a0
    li $v0, 4                 # Serviço de impressão de string
    syscall                   # Chama o serviço de sistema
    b end                     # Fim do programa

print_1:
    la $a0, bit_1             # Carrega a string "1" em $a0
    li $v0, 4                 # Serviço de impressão de string
    syscall                   # Chama o serviço de sistema

end:
    # Finalizar o programa
    li $v0, 10                # Serviço de finalização do programa
    syscall                   # Chama o serviço de sistema
