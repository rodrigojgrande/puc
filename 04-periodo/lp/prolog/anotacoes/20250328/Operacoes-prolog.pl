soma(X, Y, R) :- R is X + Y. 

% is -> Checa se é igual (==)
% Faz atribuição de valores (=)

% = -> Atribuição Literal

velocidade(fusca, 40).
velocidade(maverick, 120).
velocidade(monza, 110).
velocidade(brasilia, 50).

tempo(fusca, 20). 
tempo(maverick, 3).
tempo(monza, 6). 
tempo(brasilia, 5).


distancia(Carro, Km) :- tempo(Carro, X), velocidade(Carro, Y), Km is X * Y.