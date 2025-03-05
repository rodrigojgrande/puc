program Ordena;

procedure ordena(num1, num2, num3: integer);
var
  maior, menor, meio: integer;
begin
  if (num1 <= num2) and (num1 <= num3) then begin
    menor := num1;
    if num2 <= num3 then begin
      meio := num2;
      maior := num3;
    end  
    else begin
      meio := num3;
      maior := num2;
    end
  end
  else if (num2 <= num1) and (num2 <= num3) then begin
    menor := num2;
    if num1 <= num3 then begin
      meio := num1;
      maior := num3;
    end
    else begin
      meio := num3;
      maior := num1;
    end
  end
  else begin
    menor := num3;
    if num1 <= num2 then begin
      meio := num1;
      maior := num2;
    end
    else begin
      meio := num2;
      maior := num1;
    end
  end;
       
  writeln(menor, ' ', meio, ' ', maior);
end;

var
num1, num2, num3: integer;
begin
  readln(num1, num2,num3);
  ordena(num1, num2, num3)

end.