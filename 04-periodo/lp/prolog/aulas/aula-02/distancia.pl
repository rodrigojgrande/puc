soma(X, Y, R) :- R = X + Y.

velocidade(fusca, 40).
velocidade(maverick, 120).
velocidade(monza, 110).
velocidade(brasilia, 50).

tempo(fusca, 20).
tempo(maverick, 3).
tempo(monza, 6).
tempo(brasilia, 5).

distancia(Carro, Km) :- velocidade(Carro, V), tempo(Carro, T), Km is V * T.