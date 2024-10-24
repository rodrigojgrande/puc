class Pessoa
  attr_accessor :nome, :idade

  def initialize(nome, idade)
    @nome = nome
    @idade = idade
  end

  def apresentar
    puts "Olá, meu nome é #{@nome} e tenho #{@idade} anos"
  end

  def falar
    puts 'Olá, eu sou uma pessoa!'
  end

  
end

var1 = Pessoa.new("João", 18)
var1.apresentar

var1.idade = 28

var1.apresentar
