(format t "Hello, World!~%")
; Tudo funciona com lista e passagem de parametros
; Format = Formata o elemento para saída (printf)
; t = True

; (______________          ________)
; Nome da Funççao          Retorno

; write() = Escreve sem formatação
; ~% = Quebra de linha

(write(+ 5 5 4 3 2))

; (5 * 2) + 3  = Notação Infixa
; (+ (* 5 2) 3) = Lisp trabalha com notação prefixada

; (3-4)+(5*(2+3)) = -1+25=24

(terpri)
; (terpri) = Quebra de linha

(write(* (+ 2 3) 5))
;Dica:  Achar o que está mais de fora e ir entrando

(terpri)

(write(+ (- 3 4) (* 5 (+ 2 3)) (* 2 3)))

(defvar x 0)
; Defvar = Variavel Global
; X = Nome da váriavel
; 0 = Valor Inicializado 

(terpri)

(format t "A variavel x vale ~D" x)
; ~D = Máscara Decimal

(terpri)

(defvar *pi* 3.14)
(format t "A variavel pi vale ~F" *pi*)
; ~F = Máscara Float

; ~A = Máscara Literal
; ~$ = Máscara de dinheiro

; *Nome Váriavel Global* = Convenção para nomeação de variáveis globais

(setq x 10)
; (setq) = Função para Atribuição

(terpri)

(format t "A variavel x vale ~D" x)

(terpri)

; (defun nome (parametros ...) (corpo) )
; (defun) = Define Função

; Função em C
; int x = 10
; int incrementa (int y) {
;   return x + y;
; }
; x = incrementa;

; Função em Lisp
(defun incrementa (y)
  (+ x y)
)

(setq x (incrementa 5))

(format t "A variavel x atualizada vale ~D" x)

; Fazer uma função de soma
(setq x 5)
(setq a 10)

(defun soma (x y)
  (+ x y)
)
(format t "~%A soma de ~D e ~D eh ~D" x a (soma x a))


; (if (condiccao) true false)
; Estrutura de um if
(if (< x a)
  (format t "~D eh o menor" x)
  (format t "~D eh o menor" a)
)

(defun compara (num1 num2)
  (if (< num1 num2)
      (format t "~%Menor: ~D" num1) ; Verdade
        (if (> num1 num2)
          (format t "~%Menor: ~D" num2) ; Verdade
          (format t "~%Sao Iguais!") ; Falsa
        )
    )
)

(terpri)

(compara 4 5)
(compara 10 6)
(compara 4 4)
