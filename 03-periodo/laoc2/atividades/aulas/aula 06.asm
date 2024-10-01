# Este programa escreve um arquivo com o conte�do de um buffer
# O arquivo � criado na pasta de instala��o do Mars
#
.data
arquivo:   .asciiz "arquivo.txt"      # nome do arquivo para escrita
buffer: .asciiz "Este � um arquivo gravado em texto para ser lido por outro programa MIPS"

.text
  # Abre arquivo
  li   $v0, 13       # chamada de sistema para abrir arquivo
  la   $a0, arquivo  # arquivo de sa�da
  li   $a1, 1        # abertura para escrita (flags s�o 0: read, 1: write)
  li   $a2, 0        # modo ignorado
  syscall            # abre arquivo! (descritor do arquivo retornado em $v0)
  move $s6, $v0      # guarda o descritor do arquivo em $s6 

 # Escreve no arquivo aberto
  li   $v0, 15       # chamada de sistema para abrir arquivo
  move $a0, $s6      # descritor do arquivo
  la   $a1, buffer   # endere�o do buffer com conte�do a escrever no arquivo
  li   $a2, 100      # n�mero de caracteres a serem escritos
  syscall            # escreve!

  # Fecha o arquivo 
  li   $v0, 16       # chamada de sistema para fechar o arquivo
  move $a0, $s6      # descritor do arquivo a ser fechado
  syscall            # fecha arquivo!

feito:  
  li $v0, 10
  syscall      	     # feito!
