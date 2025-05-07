% PREDICADO OU FATO
progenitor(joao, maria).
progenitor(ana, maria).
progenitor(geraldo, zezinho). 
progenitor(bianca, zezinho). 
progenitor(joao, dudu). 
progenitor(ana, dudu). 

mulher(ana).
mulher(bianca).
mulher(maria).

homem(joao).
homem(geraldo).
homem(dudu).
homem(zezinho).

% Criar regra de quem é mãe e quem é pai
% Regra para mãe: X é mãe de Y se X é mulher e X é progenitor de Y
mae(X, Y) :- mulher(X), progenitor(X, Y).

% Regra para pai: X é pai de Y se X é homem e X é progenitor de Y
pai(X, Y) :- homem(X), progenitor(X, Y).