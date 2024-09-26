.data  
arquivo: .asciiz "C:\\Users\\1494305\\Downloads\\arquivo.txt" # caminho do arquivo
buffer:  .space 1024     # espaço para armazenar os dados lidos do arquivo

.text
main:
    # Abrir o arquivo para leitura
    li   $v0, 13          # syscall para abrir o arquivo
    la   $a0, arquivo     # endereço do nome do arquivo
    li   $a1, 0           # abrir para leitura (modo 0)
    li   $a2, 0           # sem permissões adicionais
    syscall
    move $s0, $v0         # salva o descritor de arquivo em $s0

    # Verificar se o arquivo foi aberto corretamente
    bltz $s0, erro_abertura  # se $s0 for negativo, houve erro na abertura

leitura_loop:
    # Ler 1 byte do arquivo
    li   $v0, 14          # syscall para ler arquivo
    move $a0, $s0         # descritor do arquivo em $a0
    la   $a1, buffer      # endereço do buffer em $a1
    li   $a2, 1           # ler 1 byte
    syscall

    # Se $v0 for 0, atingimos o EOF (fim do arquivo)
    beq  $v0, $zero, fechar_arquivo

    # Imprimir o byte lido
    lb   $a0, buffer      # carregar o byte lido em $a0
    li   $v0, 11          # syscall para imprimir caractere
    syscall

    # Voltar para ler mais bytes
    j    leitura_loop

fechar_arquivo:
    # Fechar o arquivo
    li   $v0, 16          # syscall para fechar arquivo
    move $a0, $s0         # descritor do arquivo em $a0
    syscall

    # Finalizar o programa
    li   $v0, 10          # syscall para sair
    syscall

erro_abertura:
    # Exibir mensagem de erro
    li   $v0, 4
    la   $a0, msg_erro
    syscall
    j    fechar_arquivo   # tenta fechar qualquer recurso aberto

.data
msg_erro: .asciiz "Erro ao abrir o arquivo.\n"
