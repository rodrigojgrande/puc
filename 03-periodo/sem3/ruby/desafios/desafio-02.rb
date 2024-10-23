puts "Digite o valor de X" # Escreve na tela

x = gets.chomp.to_i # Captura uma informação

puts "Digite o valor de Y" # Escreve na tela

z = gets.chomp.to_i # Captura uma informação

puts "Escolha o tipo de conta a se realizar" # Escreve na tela

conta = gets.chomp # Captura uma informação

case conta 
    when "+"
        teste = x+z
        puts "O valor da conta é #{teste}"
    when "-"
        teste = x-z
        puts "O valor da conta é #{teste}"
    when "/"
        teste = x/z
        puts "O valor da conta é #{teste}"
    when "*"
        teste = x*z
        puts "O valor da conta é #{teste}"
    else
        puts "Valor não encontrado"
end

