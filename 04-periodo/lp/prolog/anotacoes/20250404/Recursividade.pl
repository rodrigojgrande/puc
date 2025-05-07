% Recursividade
conta_x_ate_10(10) :- write(10), !.
% Condição de parada
conta_x_ate_10(X) :- write(X), nl, X1 is X +1, conta_x_ate_10(X1).
% Regra com condição de parada
% nl = New Line (Quebra de linha)

conta_10_ate_x(10) :- write(10), nl, !. 
conta_10_ate_x(X) :- X1 is X+1, conta_10_ate_X(X1), write(X), nl.

conta_ate_0(0) :- write(0), nl, !.
conta_ate_0(X) :- write(X), nl, X1 is X-1, conta_ate_0(X1).

conta_0_ate_x(0) :- write(0), nl, !.
conta_0_ate_x(X) :- X1 is X-1, conta_0_ate_x(X1), write(X), nl.

fatorial(1, 1) :- !.
fatorial(X, Resultado) :- Y is X-1, fatorial(Y, Resultado1), Resultado is X * Resultado1.

multiplicacao(X, 1, X) :- !.
multiplicacao(X, Y, R) :- Y1 is Y-1, multiplicacao(X, Y1, R1), R is X + R1.

fibonacci(1, 1) :- !.
fibonacci(2, 1) :- !.
fibonacci(X, R) :- X1 is X-1,
    X2 is X-2,
    fibonacci(X1, R1),
    fibonacci(X2, R2), 
    R is R1 + R2.
% F(n + 2) = F(n + 1) + F(n), com n ≥ 1 e F(1) = F(2) = 1