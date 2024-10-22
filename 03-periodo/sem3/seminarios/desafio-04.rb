# A2 - Calculo de Média
# - Desenvolva um sistema que calcula a média de uma lista de notas inderida pelo usuário

numeros = []

flag = false

# WHILE
while flag != true
  puts "Digite um valor: " # Escreve na tela
  n1 = gets.chomp.to_i # Captura uma informação

  numeros.push(n1) # Adiciona ao fim do array

  puts "Deseja continuar [s/n]: " # Escreve na tela
  resposta = gets.chomp# Captura uma informação

  if resposta == "n"
    flag = true
  end
  
end

total = 0
contador = 0
# #IT
numeros.each do |numero|
    total += numero
    contador += 1
end

media = total/contador

p "Lista de Números: #{numeros}"
p "Média: #{media}"
                