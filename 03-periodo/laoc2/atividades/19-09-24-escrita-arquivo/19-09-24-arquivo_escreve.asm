# Este programa escreve um arquivo com o conteúdo de um buffer
# O arquivo é criado na pasta de instalação do Mars
#
.data
arquivo_origem:   .asciiz "arquivo_origem.txt"      # nome do arquivo para escrita
arquivo_destino:   .asciiz "arquivo_destino.txt"      # nome do arquivo para escrita
buffer: .space 1024
fim_arquivo: .ascii  "\Chegou no fim do arquivo - n  bytes lidos: "
mensagem: .asciiz "Numero de bytes copiados"

.text
  # Abre arquivo para leitura
  li   $v0, 13       # chamada de sistema para abrir arquivo
  la   $a0, arquivo_destino  # arquivo de saída
  li   $a1, 1        # abertura para escrita (flags são 0: read, 1: write)
  li   $a2, 0        # modo ignorado
  syscall            # abre arquivo! (descritor do arquivo retornado em $v0)
  move $s6, $v0      # guarda o descritor do arquivo em $s6 
  
   # Abre arquivo para leitura
  li   $v0, 13       # chamada de sistema para abrir arquivo
  la   $a0, arquivo_origem  # arquivo de saída
  li   $a1, 0        # abertura para escrita (flags são 0: read, 1: write)
  li   $a2, 0        # modo ignorado
  syscall            # abre arquivo! (descritor do arquivo retornado em $v0)
  move $s7, $v0      # guarda o descritor do arquivo em $s6 
  
  # Abre arquivo para leitura
  li   $v0, 13       # chamada de sistema para abrir arquivo
  la   $a0, arquivo_destino  # arquivo de saída
  li   $a1, 1        # abertura para escrita (flags são 0: read, 1: write)
  li   $a2, 0        # modo ignorado
  syscall            # abre arquivo! (descritor do arquivo retornado em $v0)
  move $s2, $v0      # guarda o descritor do arquivo em $s6 
  
 # Escreve no arquivo aberto
 la $a1, buffer # Endereço do buffer para receber a leitura
 add $t1, $zero, $zero
 
LOOP: 
	li $v0, 14
	move $a0, $s7
	li $a2, 1
	syscall
	move $t0, $v0 # $t0 contem o caractere lido do arquivo
 
  	li   $v0, 15       # chamada de sistema para abrir arquivo
  	move $a0, $s6      # descritor do arquivo de escrita
  	li   $a2, 1      # número de caracteres a serem escritos
 	syscall            # escreve!
 	
 	addi $a1, $a1, 1 # Incremento do buffer
 	addi $t1, $t1, 1 # Incremento contador
 	
 	beq $t0, 0, EOF
 	j LOOP
 	
 EOF: 	
  # Fecha o arquivo 
  li   $v0, 16       # chamada de sistema para fechar o arquivo
  move $a0, $s6      # descritor do arquivo a ser fechado
  syscall            # fecha arquivo!
  
  li   $v0, 16       # chamada de sistema para fechar o arquivo
  move $a0, $s7      # descritor do arquivo a ser fechado
  syscall            # fecha arquivo!
  
  li $v0, 4
  la $a0, mensagem
  syscall
  li $v0, 1
  move $a0, $t1
  syscall


feito:  
  li $v0, 10
  syscall      	     # feito!
