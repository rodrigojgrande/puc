pos_neg(X) :- X >= 0, write('positivo'), !.
pos_neg(X) :- X < 0, write('negativo'), !.