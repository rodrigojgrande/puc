program Fatorial;

function fatorial(x: integer): integer;
var
  res: integer = 1;
begin
  while x > 1 do
  begin
    res := res * x;
    x := x - 1;
  end;
  fatorial := res;
end;

var
  x: integer;
begin
  readln(x);
  writeln('O fatorial de ', x, ' eh: ', fatorial(x))

end.