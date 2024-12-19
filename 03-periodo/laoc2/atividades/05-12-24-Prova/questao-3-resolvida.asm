.data
    S1: .asciiz "Eu gosto de assembly   "
    S2: .asciiz "escrever aqui          "
    
# observações:
# 1) endereço base de S1 está em $a1
# 2) endereço base de S2 está em $a0
# lembrar que caracteres apenas ocupam  byte na memória

.text
main: 
    # imprime versão original do string S2
    la $a0, S2            # Carrega o endereço base de S2 em $a0
    li $v0, 4             # Serviço de syscall para imprimir string
    syscall
    
    # Lê endereços dos strings na memória
    la $a1, S1            # Carrega o endereço base de S1 em $a1
    la $a0, S2            # Carrega o endereço base de S2 em $a0
    
    jal strcpy            # Chama o procedimento strcpy
    
    # imprime versão final do string S2
    la $a0, S2            # Carrega o endereço base de S2 novamente para exibir o novo conteúdo
    li $v0, 4             # Serviço de syscall para imprimir string
    syscall
    
    li $v0, 10            # Serviço de syscall para finalizar o programa
    syscall               # Feito
    
strcpy:
    add $t0, $zero, $zero # Inicializa i = 0
L1: 
    add $t1, $a1, $t0     # Calcula o endereço atual de S1 (S1 + i)
    lb $t2, 0($t1)        # Lê o byte atual de S1 no endereço calculado
    
    beq $t2, $zero, out   # Se o byte lido for '\0' (fim da string), sai do laço
    
    add $t3, $a0, $t0     # Calcula o endereço atual de S2 (S2 + i)
    sb $t2, 0($t3)        # Armazena o byte lido de S1 no endereço correspondente em S2
    
    addi $t0, $t0, 1      # Incrementa i (i = i + 1)
    j L1                  # Volta para o início do loop
out:
    jr $ra                # Retorna ao chamador do procedimento
    
.end main
