conta_ate_10(10) :- write(10), !.
conta_ate_10(X) :- write(X), X1 is X + 1, conta_ate_10(X1).

conta_10_ate(10) :- write(10), !.
conta_10_ate(X) :-  X1 is X + 1, conta_10_ate(X1), write(X).

conta_ate_X(0) :- write(0), !.
conta_ate_X(X) :- Y is X - 1, conta_ate_X(Y), write(X).

conta_X_ate_0(0) :- write(0), !.
conta_X_ate_0(X) :- write(X), Y is X - 1, conta_X_ate_0(Y).

fatorial(0, 1) :- !.
fatorial(X, R) :- X1 is X - 1, fatorial(X1, R1), R is X * R1.

multiplicacao(X, 1, X) :- !.
multiplicacao(X, Y, R) :- Y1 is Y - 1, multiplicacao(X, Y1, R1), R is X + R1.

fib(2, 1) :- !.
fib(1, 1) :- !.
fib(X, R):- X1 is X-1, 
    	 X2 is X-2,
    	 fib(X1, R1),
    	 fib(X2, R2),
    	 R is R1 + R2.
