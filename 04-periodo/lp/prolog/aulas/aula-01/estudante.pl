estudante(joao).
estudante(maria).
estudante(jorginho).

idade(joao, 28).
idade(clark, 28).
idade(bruce, 44).
idade(maria, 44).
idade(jorginho, 15).

eh_estudante(X) :- estudante(X).
eh_estudante_escola(X) :- estudante(X), idade(X, I), I =< 18.
eh_estudante_ensino_medio(X) :- estudante(X), idade(X, I), I =< 18, I >= 15.
