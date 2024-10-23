#nota = 85

#IF ELSIF
#if nota >= 90
#    puts "Nota A"
#elsif nota >= 80
#    p "Nota B"
#elsif nota >= 70
#    p "Nota C"
#else
#    p "Reprovado"
#end

# WHILE
#contador = 0
#while contador < 5
#   p "Contagem while: #{contador}"
#   contador +=1
#end

# UNTIL
#contador = 0
#until contador == 5
#   p "Contagem until: #{contador}"
#   contador +=1
#end


#TIMES
# 5.times do |i|
#     p "(times)Iteração número #{i}"
# end

# #FOR
# for i in 10..15
#     p "Valor de i: #{i}"
# end

# #IT
# frutas = ["Maça", "Banana", "Laranja"]
# frutas.each do |fruta|
#     p "A fruta da interação: #{fruta}"
#end

# ARRAY
# numeros = [1,2,3,4,5,6,10]
# numeros.push(100) # Adiciona ao fim do array
# p "Push"
# p numeros.last # Acessa o ultimo item do array
# ultimo_numero = numeros.pop
# p "Pop"
# p ultimo_numero
# p numeros
# primeiro_numero = numeros.shift # Tira o primeiro item do array
# p "shift"
# p ultimo_numero
# p numeros
# numeros.unshift(0) # Coloca um item no começo do array
# p "Unshift"
# p numeros

# ARRAY MULTIDIMENSIONAL
# pessoa = [["Aluan", 35, "Poços de Caldas"], []]
# pessoa[0][1]

pessoa = {nome: "Aluan", idade: 35, cidade: "Poços de Caldas"}
puts "Nome: #{pessoa[:nome]}"
puts "Idade: #{pessoa[:idade]}"
pessoa[:idade] = 36
puts "Adicionar novo campo"
pessoa[:profissao] = "Engenheiro"
p pessoa

p "Multiplo Hash"
hash_pessoas = {
    pessoas: [
        {nome: "Aluan", idade: 35, cidade: "Poços de Caldas"},
        {nome: "Rodrigo", idade: 26, cidade: "Varginha"}
    ]
}

hash_pessoas[:pessoas].each do |pessoa|
    p "Nome: #{pessoa[:nome]}"
    p "Idade: #{pessoa[:idade]}"
end