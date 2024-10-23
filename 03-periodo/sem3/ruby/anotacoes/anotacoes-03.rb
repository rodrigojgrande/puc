# Declaração de Função
def nome_da_funcao(variavel1, variavel2)

end

#POO
class Pessoa # Instanciar um objeto

  def initialize(nome, idade) # Construtor
    @nome = nome # Atributos
    @idade = idade # Atributos
  end

  def falar # Declaração de um método
    puts "Olá, eu sou uma pessoa!"
  end

  def apresentar 
    puts "Olá, meu nome é #{@nome} e tenho #{@idade} anos"
  end

end

var1 = Pessoa.new("Rodrigo", 26)
var1.falar
var1.apresentar