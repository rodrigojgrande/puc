pos_neg(X) :- X >= 0, write('positivo'), !.
% ! -> Pode parar!
pos_neg(X) :- X < 0, write('negativo'). 

%pos_neg_v2(X) :- (X >= -> write('positivo') ; write('negativo')).
% Testa isso, se for verdade faz isso e se for falso, faça isso
% , = e
% ; = ou

pos_neg_v2(X) :- (X > 0 -> write('positivo') ; (X < 0 ->write('negativo'); write('zero'))).

% media(N1, N2, N3, Media) :- (Media is N1 + N2 + N3).
%calcula_media(Media) :- (Media < 6 -> write('Ficou abaixo da média'); (Media >6 ->write('Ficou Acima da média'); write('Ficou na média'))).
    
% Dizer se está na média, acima da média ou abaixo (Média 06)

media(N1, N2, N3) :- Media is (N1 + N2 + N3) / 3, 
                            (  Media >= 6 ->  write('esta na media') ; write('abaixo da media')).
