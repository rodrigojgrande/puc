# contador = 0
# while contador < 5
#   p "Contagem while: #{contador}"
#   contador += 1
# end

# contador = 0
# until contador == 5
#   p "Contagem until: #{contador}"
#   contador += 1
# end

# 5.times do |i|
#   p "(times) Iteração numero #{i}"
# end

# for i in 10..15
#   p "Valor de i: #{i}"
# end

# frutas = ["Maçã", "Banana", "Laranja"]
# frutas.each do |fruta|
#   p "A fruta da iteração: #{fruta}"
# end

# numeros = [1,2,3,4,5,6,10]
# numeros.push(100)
# p "Pop"
# ultimo_numero = numeros.pop
# p ultimo_numero
# p numeros
# p "Shift"
# primeiro_numero = numeros.shift
# p primeiro_numero
# p numeros
# numeros.unshift(0)
# p "Unshift"
# p numeros

pessoa = { nome: "Aluan", idade: 35, cidade: "Poços de Caldas" }
puts "Nome: #{pessoa[:nome]}"
puts "Idade #{pessoa[:idade]}"
pessoa[:idade] = 36
puts pessoa
p "Adicionar novo campo"
pessoa[:profissao] = "Engenheiro"
p pessoa

p "Multiplo Hash"
hash_pessoa = { 
  pessoas: [
    { nome: "Aluan", idade: 35, cidade: "Poços de Caldas" },
    { nome: "Roberto", idade: 39, cidade: "São Paulo"}
  ]
}
hash_pessoa[:pessoas].each do |pessoa| 
  p "Nome: #{pessoa[:nome]}"
  p "Idade: #{pessoa[:idade]}"
end