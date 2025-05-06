progenitor(joao, maria).
progenitor(ana, maria).
progenitor(joao, dudu).
progenitor(ana, dudu).
progenitor(geraldo, zezinho).
progenitor(bianca, zezinho).
progenitor(mauricio, ana).
progenitor(helenice, ana).
progenitor(mauricio, geraldo).
progenitor(helenice, geraldo).
progenitor(romulo, mauricio).
progenitor(olga, mauricio).
progenitor(romulo, bruce).
progenitor(olga, bruce).
progenitor(romulo, selina).
progenitor(olga, selina).

mulher(ana).
mulher(bianca).
mulher(maria).
mulher(helenice).
mulher(olga).

homem(joao).
homem(geraldo).
homem(dudu).
homem(zezinho).
homem(mauricio).
homem(romulo).

pai(X, Y) :- progenitor(X, Y), homem(X).
mae(X, Y) :- progenitor(X, Y), mulher(X).

avo(X, Y) :- progenitor(Z, Y), progenitor(X, Z).
irmao(X, Y) :- progenitor(Z, X), progenitor(Z, Y), X \== Y.
tio(Tio, Sobrinho) :- progenitor(Pai, Sobrinho), irmao(Pai, Tio).

