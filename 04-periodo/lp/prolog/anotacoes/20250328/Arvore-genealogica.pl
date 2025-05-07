% PREDICADO OU FATO
estudante(joao).
estudante(maria).
estudante(jorginho).
estudante(grande).

idade(joao, 28).
idade(maria, 44).
idade(clark, 28).
idade(bruce, 44).
idade(jorginho, 15).
idade(27).

% REGRA
eh_estudante(X) :- estudante(X).
eh_estudante_escola(X) :- estudante(X), idade(X, I), I =< 18.
eh_estudante_ensio_medio(X) :- estudante(X), idade(X, I), I =< 18, I >= 14.