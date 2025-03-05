program MaiorMenorVetor;
const
  tam = 10;

type 
  arr = array [1..tam] of integer;
  
procedure maiorMenor(v: arr);
var
  maior, menor, i: integer;
begin
  maior := v[1];
  menor := v[1];
  
  for i := 2 to tam do begin
    if maior < v[i] then maior := v[i];
    if menor > v[i] then menor := v[i];
  end;
  
  writeln('Maior valor eh: ', maior);
  writeln('Menor valor eh: ', menor);
end;

var
  vetor: arr;
  i: integer;
begin
  for i:= 1 to tam do readln(vetor[i]);
  maiorMenor(vetor);
  
end.