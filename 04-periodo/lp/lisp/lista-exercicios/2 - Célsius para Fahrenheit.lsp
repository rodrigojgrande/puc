; 2 - Faça uma função em LISP que converte graus célsius para Fahrenheit
(defun celsius-para-fahrenheit (c)
  "Converte Celsius para Fahrenheit."
  (+ (* c 9/5) 32))

(defun iniciar-conversao ()
  (format t "Digite a temperatura em graus Celsius: ")
  (let ((celsius (read)))
    (let ((fahrenheit (celsius-para-fahrenheit celsius)))
      (format t "~%~a graus Celsius equivalem a ~a graus Fahrenheit.~%" celsius fahrenheit))))
      
(iniciar-conversao)