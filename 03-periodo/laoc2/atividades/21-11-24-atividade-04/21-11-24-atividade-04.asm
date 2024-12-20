.data
var_x: .asciiz "Digite o valor de x: "
var_y: .asciiz "Digite o valor de y: "
var_z: .asciiz "Digite o valor de z: "
var_t: .asciiz "Digite o valor de t: "
erro_div_zero: .asciiz "Erro: Divisao por zero!\n"
resultado: .asciiz "Resultado da funcao: "
valor_um: .float 1.0

.text

main:
# X
li $v0, 4
la $a0, var_x
syscall

li $v0, 6
syscall
mov.s $f1, $f0 # Armazenar x em $f1

# Y
li $v0, 4
la $a0, var_y
syscall

li $v0, 5
syscall
move $t0, $v0 # Armazenar y em $t0

#Z
li $v0, 4
la $a0, var_z
syscall

li $v0, 6
syscall
mov.s $f2, $f0 # Armazenar z em $f2

# T
li $v0, 4
la $a0, var_t
syscall

li $v0, 6
syscall
mov.s $f4, $f0 # Armazenar t em $f4

#z == 0
li $t1, 0
mtc1 $t1, $f7
cvt.s.w $f7, $f7
c.eq.s $f2, $f7
bc1t div_zero

# x^y
l.s $f8, valor_um
move $t2, $t0
blez $t2, res_expoente

expoente:
mul.s $f8, $f8, $f1 # $f8 = $f8 * x
sub $t2, $t2, 1 # y = y - 1
bgtz $t2, expoente

res_expoente:

# Divisão (x^y)/z
div.s $f10, $f8, $f2

# Subtração (x^y) / z - t
sub.s $f10, $f10, $f4


li $v0, 4
la $a0, resultado
syscall


li $v0, 2
mov.s $f12, $f10
syscall


li $v0, 10
syscall

div_zero:

li $v0, 4
la $a0, erro_div_zero
syscall

li $v0, 10
syscall