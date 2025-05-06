pertence(H, [H|_]).
pertence(H, [_|T]) :- pertence(H, T).

ultimo([Elem], Elem).
ultimo([_|Cauda], Elem) :- ultimo(Cauda, Elem).

consecutivo(X, Y, [X|[Y|_]]).
consecutivo(X, Y, [_|Z]) :- consecutivo(X, Y, Z).

soma([], 0).
soma([Elem|Cauda], S) :- soma(Cauda, Y), S is Elem + Y.

conta_multiplo([], 0).
conta_multiplo([H|T], C) :- (H mod 2 =:= 0; H mod 3 =:= 0), conta_multiplo(T, C1), C is C1 + 1.
conta_multiplo([_|T], C) :- conta_multiplo(T, C).
