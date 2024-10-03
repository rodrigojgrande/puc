.data
    mensagem:    .asciiz "Digite o valor do primeiro octeto do endereco IPv4 (0-255): "
    classeA:     .asciiz "Classe A\n"
    classeB:     .asciiz "Classe B\n"
    classeC:     .asciiz "Classe C\n"
    invalido:    .asciiz "Valor invalido, necessita ser de 0 a 255\n"

.text

main:
    li $v0, 4
    la $a0, mensagem
    syscall

    li $v0, 5
    syscall
    move $t0, $v0
	
    li $t1 , -1
    li $t2, 127
    ble $t0, $t1, printInvalido #checa se o valor digitado é menor que 0
    ble $t0, $t2, printClasseA #checa se o valor digitado é menor ou igual à 127

    li $t2, 191
    ble $t0, $t2, printClasseB #checa se o valor digitado é menor ou igual à 191

    li $t2, 255
    ble $t0, $t2, printClasseC #checa se o valor digitado é menor ou igual à 255
    j printInvalido

printClasseA:
    li $v0, 4
    la $a0, classeA
    syscall
    j end

printClasseB:
    li $v0, 4
    la $a0, classeB
    syscall
    j end

printClasseC:
    li $v0, 4
    la $a0, classeC
    syscall
    j end

printInvalido:
    li $v0, 4
    la $a0, invalido
    syscall

end:
    li $v0, 10
    syscall
