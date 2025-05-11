; Faça uma função em LISP que recebe duas notas, tira a média e diz se está aprovado ou não

(defun avaliar-aluno (nota1 nota2)
  "Calcula a média de duas notas e informa se o aluno está aprovado ou reprovado."
  (let ((media (/ (+ nota1 nota2) 2.0)))
    (format t "~%Média: ~,2f~%" media)
    (force-output)  ;; força a exibição da média
    (if (>= media 7.0)
        (progn
          (format t "Situação: Aprovado~%")
          (force-output))
        (progn
          (format t "Situação: Reprovado~%")
          (force-output)))))

(defun iniciar-avaliacao ()
  (format t "Digite a primeira nota: ")
  (force-output)
  (let ((nota1 (read)))
    (format t "Digite a segunda nota: ")
    (force-output)
    (let ((nota2 (read)))
      (avaliar-aluno nota1 nota2))))

(iniciar-avaliacao)