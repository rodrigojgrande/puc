pertence([Elem|_], Elem).
% _ = Ignora

pertence([_|Cauda], Elem) :- pertence(Cauda, Elem).

% Descobrir o ultimo elemento
ultimo([Elem], Elem).
ultimo([_|Tail], Elem) :- ultimo(Tail, Elem).

% Descobrir se valores são consecutivos
consecutivo(X, Y, [X|[Y|_]]).
consecutivo(X, Y, [_|T]) :- consecutivo(X, Y, T).

% Somar elementos de uma lista
soma([], 0).
soma([H|T], S) :- soma(T, S1), S is H + S1.

% Contar Múltiplos de 2 e 3
conta_multiplos_2_3([], 0).
conta_multiplos_2_3([H|T], S) :- ( H mod 2 =:= 0; H mod 3 =:= 0 ),
    							 conta_multiplos_2_3(T, S1), S is S1 + 1.
conta_multiplos_2_3([_|T], S) :- conta_multiplos_2_3(T, S).