pos_neg(X) :- X >= 0, write('positivo'), !.
pos_neg(X) :- X < 0, write('negativo').

pos_neg_v2(X) :- ( X > 0 ->  write('positivo') ; 
                 	( X < 0 ->  write('negativo') ; 
                 		write('zero'))).

media(N1, N2, N3) :- R is (N1 + N2 + N3) / 3, 
    ( R >=6 ->  write('aprovado') ; write('reprovado')).