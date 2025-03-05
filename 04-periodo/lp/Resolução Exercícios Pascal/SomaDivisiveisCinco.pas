program SomaDivisiveisCinco;
const
  tam = 10;

type 
  arr = array [1..tam] of integer;
  
function somaDivisiveis(v: arr): integer;
var
  soma: integer = 0;
  i: integer;
begin
  for i := 1 to tam do 
    if v[i] mod 5 = 0 then soma := soma + v[i];
  
  somaDivisiveis := soma;
end;

var
  vetor: arr;
  i: integer;
begin
  for i:= 1 to tam do readln(vetor[i]);
  writeln('A soma dos divisiveis por cinco eh: ', somaDivisiveis(vetor));
  
end.