% 1 - Seja o silogismo clássico [...]
estudante(trabalho).
amar(X):- estudante(X).

% Código que eu usei para o teste:
% amar(trabalho).


% 2) Considere a árvore genealógica a seguir [...]
progenitor(ana, eva).
progenitor(ivo, eva).

progenitor(bia, rai). 
progenitor(gil, rai). 

progenitor(bia, clo). 
progenitor(gil, clo). 

progenitor(bia, ary). 
progenitor(gil, ary). 

progenitor(eva, noe). 
progenitor(rai, noe). 

progenitor(lia, gal). 
progenitor(ary, gal). 

% a)
% Regra para mãe: X é mãe de Y se X é mulher e X é progenitor de Y
mae(Mae, Filho) :- mulher(Mae), progenitor(Mae, Filho).

% Regra para pai: X é pai de Y se X é homem e X é progenitor de Y
pai(Pai, Filho) :- homem(Pai), progenitor(Pai, Filho).

% b)
mulher(ana).
mulher(bia).
mulher(eva).
mulher(lia).
mulher(gal).

homem(ivo).
homem(gil).
homem(rai).
homem(noe).

% c)
gerou(Pais, Filho) :- pai(Pais, Filho).
gerou(Pais, Filho) :- mae(Pais, Filho).


% 3) Sejam as seguintes unificações em listas em Prolog [...]

% a) Joguei no terminal o seguinte código: [1, 2, 3, 4, 5] = [Head | Tail].
% Obtive o seguinte retorno: Head = 1, Tail = [2, 3, 4, 5]

% b) Joguei no terminal o seguinte código: [quod, licet, jovi, non, licet, bovi] = [_, X | _].
% Obtive o seguinte retorno: X = licet
% Explicação do Porquê disso:
% O primeiro _ é uma variável anônima que ignora o primeiro elemento (quod)
% O X unifica com o segundo elemento (licet)
% O | é utilizado para separar a Head do Tail
% O segundo _ ignora o restante da lista ([jovi, non, licet, bovi])


% 4) Escreva o predicado imprima(L) para imprimir na tela do computador os elementos de uma da lista L [...]
% (Condição de Parada) Quando a Head for vazia, significa que chegou no fim da lista
imprima([]).  

% Escreve a Head (Writeln já faz a quebra de linha como o println)
% Chama imprima() passando a Tail de maneira recursiva para o predicado
imprima([Head|Tail]) :- writeln(Head), imprima(Tail).

% Código usado no terminal para testar: imprima([3,5,1,3]).


% 5) Escreva um predicado verificanota(L) que recebe uma lista com as notas [...]

% Fazer as validações dos status das notas
status(Nota, reprovado) :- Nota >= 0, Nota < 30.
status(Nota, recuperacao) :- Nota >= 30, Nota < 60.
status(Nota, aprovado) :- Nota >= 60, Nota < 100.

% (Condição de Parada) Quando a Head for vazia, significa que chegou no fim da lista
verificanota([]).

% Recebe a lista e pega o primeira nota e usa como Head
verificanota([Head|Tail]) :-
    % Chama o predicado de status para validar a nota atual
    status(Head, Status),
    % Escreve a nota atual, diz o status dela e salta a linha
    write(Head), write(' '), writeln(Status),
    % Chama verificanota() passando a Tail de maneira recursiva para o predicado
    verificanota(Tail).

% Código usado no terminal para testar: imprima([3,5,1,3]).
% verificanota([65, 99, 45.7, 23.9, 15.2, 36.7, 83.5]).


% 6) Escreva o predicado contavogal(Lista, Contador) a quantidade de vogais [...]
% Define quais caracteres são vogais
vogal(a).
vogal(e).
vogal(i).
vogal(o).
vogal(u).
vogal('A').
vogal('E').
vogal('I').
vogal('O').
vogal('U').

% Inicializa a quantidade com 0
contavogal(Lista, Contador) :- contavogal(Lista, 0, Contador).

% (Condição de Parada) Quando a Head for vazia, significa que chegou no fim da lista
contavogal([], Contador, Contador).

% Caso recursivo
contavogal([Head|Tail], Quantidade, Contador) :- 
    % Se Head for vogal, faça (-> é como if/else)
    (vogal(Head) ->  
        NovaQuantidade is Quantidade + 1; 
    % Se Head não for vogal, então
        NovaQuantidade is Quantidade),
    % Chama contavogal() passando a Tail de maneira recursiva para o predicado
    contavogal(Tail, NovaQuantidade, Contador).

% Código usado no terminal para testar: contavogal([m,a,d,a,m], 2).