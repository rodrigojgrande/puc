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