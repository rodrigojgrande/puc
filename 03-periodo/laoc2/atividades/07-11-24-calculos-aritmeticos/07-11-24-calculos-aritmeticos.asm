.data
    variavel_float1: .float     				# Define uma variável para armazenar o primeiro número float
    variavel_float2: .float     				# Define uma variável para armazenar o segundo número float
    
    digite1: .asciiz "Digite o primeiro numero float: " 	# Mensagem de prompt para o primeiro número
    digite2: .asciiz "Digite o segundo numero float: "   	# Mensagem de prompt para o segundo número

.text
main:
    # Exibir a mensagem de prompt para o primeiro número
    la $a0, digite1             # (Load Address) - Carrega o endereço da mensagem 'digite1' no registrador $a0
    li $v0, 4                   # (Load Immediate) - Serviço de impressão de string
    syscall                     # (System Call) - Chama o serviço de sistema para exibir a mensagem
    
    # Ler o primeiro número float do teclado
    li $v0, 6                   # (Load Immediate) - Serviço para ler float
    syscall                    	# (System Call) - Chama o serviço de sistema
    
    # Armazenar o valor lido em 'variavel_float1'
    la $t0, variavel_float1     # (Load Address) - Carrega o endereço de 'variavel_float1' no registrador $t0
    s.s $f0, 0($t0)             # (Store Single) - Armazena o valor de $f0 (float lido) na memória no endereço de variavel_float1
    mov.s $f1, $f0              # (Move Single) - Copia o valor lido de $f0 para $f1 para operações futuras
    jal println_float           # (Jump And Link) - Chama o procedimento 'println_float' para imprimir o valor em $f1
    
    # Exibir a mensagem de prompt para o segundo número
    la $a0, digite2             # (Load Address) - Carrega o endereço da mensagem 'digite2' no registrador $a0
    li $v0, 4                   # (Load Immediate) - Serviço de impressão de string
    syscall                     # (System Call) - Chama o serviço de sistema para exibir a mensagem
    
    # Ler o segundo número float do teclado
    li $v0, 6                   # (Load Immediate) - Serviço para ler float
    syscall                     # (System Call) - Chama o serviço de sistema, valor lido é colocado em $f0
    
    # Armazenar o valor lido em 'variavel_float2'
    la $t0, variavel_float2     # (Load Address) - Carrega o endereço de 'variavel_float2' no registrador $t0
    s.s $f0, 0($t0)             # (Store Single) - Armazena o valor de $f0 (float lido) na memória no endereço de variavel_float2
    mov.s $f2, $f0              # (Move Single) - Copia o valor lido de $f0 para $f2 para operações futuras
    jal println_float           # (Jump And Link) - Chama o procedimento 'println_float' para imprimir o valor em $f2
    
    # Operações matemáticas com os valores em $f1 e $f2
    add.s $f0, $f1, $f2         # (Add Single) - Soma: $f0 = $f1 + $f2
    jal println_float           # (Jump And Link) - Imprime o valor da soma contido em $f0
    
    sub.s $f0, $f1, $f2         # (Subtract Single) - Subtração: $f0 = $f1 - $f2
    jal println_float           # (Jump And Link) - Imprime o valor da subtração contido em $f0
    
    mul.s $f0, $f1, $f2         # (Multiply Single) - Multiplicação: $f0 = $f1 * $f2
    jal println_float           # (Jump And Link) - Imprime o valor da multiplicação contido em $f0
    
    div.s $f0, $f1, $f2         # (Divide Single) - Divisão: $f0 = $f1 / $f2
    jal println_float           # (Jump And Link) - Imprime o valor da divisão contido em $f0
    
    abs.s $f0, $f1              # (Absolute Single) - Valor absoluto: $f0 = |$f1|
    jal println_float           # (Jump And Link) - Imprime o valor absoluto de $f1
    
    neg.s $f0, $f1              # (Negation Single) - Negação: $f0 = -$f1
    jal println_float           # (Jump And Link) - Imprime o valor negado de $f1
    
feito: 
    li $v0, 10                  # (Load Immediate) - Serviço para encerrar o programa
    syscall                     # (System Call) - Chama o serviço de sistema para terminar o programa

# Procedimento 'println_float' para imprimir o valor de $f0 e pular uma linha
println_float:
    mov.s $f12, $f0             # (Move Single) - Copia o valor de $f0 para $f12, usado pelo serviço de impressão
    li $v0, 2                   # (Load Immediate) - Serviço de impressão de float
    syscall                     # (System Call) - Chama o serviço de sistema para imprimir o valor de $f12
    
    li $a0, '\n'                # (Load Immediate) - Caractere de nova linha em ASCII
    li $v0, 11                  # (Load Immediate) - Serviço para imprimir caractere
    syscall                     # (System Call) - Chama o serviço de sistema para pular uma linha
    
    jr $ra                      # (Jump Register) - Retorna para o ponto de chamada anterior
