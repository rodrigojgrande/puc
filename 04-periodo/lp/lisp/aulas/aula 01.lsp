(format t "Hello, World!~%")
(write (+ 5 5)) 
(terpri)
(write (+ (- 3 4) (* 5 (+ 2 3)) (* 2 3)))

(defvar x 0)
(defvar *pi* 3.1415)
(format t "~%A variavel x vale ~D" x)
(format t "~%A variavel *pi* vale ~$" *pi*)

(setq x 10)
(format t "~%A variavel x vale ~D" x)
(setq a 33)
(format t "~%A variavel a vale ~D" a)

(defun incrementa (y) 
  (+ x y))
  
(setq x (incrementa 5))
(format t "~%A variavel x atualizada vale ~D" x) 

(defun soma (x y) (+ x y))
(format t "~%A soma de ~D e ~D eh ~D" x a (soma 10 a))

(defun compara (num1 num2)
  (if (< num1 num2)
    (format t "~%Menor: ~D" num1) ; Verdade
    (if (> num1 num2) ; Falsa
      (format t "~%Menor: ~D" num2) ; Verdade
      (format t "~%Sao iguais!") ; Falsa
    )
  )
)

(write (compara 4 5))
(write (compara 10 6))
(write (compara 4 4))

