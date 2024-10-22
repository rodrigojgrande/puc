# A1 - Crie um programa que descubra os números pares/impares
# - Sistema pede número e fala se é par ou impares
# - O usuário demonstra que quer parar
# - No final o sistema mostra quais números foram pares e quais impares
# * Durante o uso vai mostrando se o número digitado for par ou impar

numeros_pares = []
numeros_impares = []

flag = false

# WHILE
while flag != true
  puts "Digite um valor: " # Escreve na tela
  n1 = gets.chomp.to_i # Captura uma informação


  if n1%2 == 0
    puts "Número digitado foi par" # Escreve na tela
    numeros_pares.push(n1) # Adiciona ao fim do array
  else
    puts "Número digitado foi ímpar" # Escreve na tela
    numeros_impares.push(n1) # Adiciona ao fim do array
  end

  puts "Deseja continuar [s/n]: " # Escreve na tela
  resposta = gets.chomp# Captura uma informação

  if resposta == "n"
    flag = true
  end
end

p "Números Pares: #{numeros_pares}"
p "Números Pares: #{numeros_impares}"