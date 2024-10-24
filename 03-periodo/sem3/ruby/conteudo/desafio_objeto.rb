class Aluno
  attr_accessor :nome, :matricula, :media

  def initialize(nome, matricula, media)
    @nome = nome
    @matricula = matricula
    @media = media
  end

  def exibir_dados
    puts "Nome #{@nome}, Matrícula: #{@matricula}, Média: #{@media}"
  end
end

def cadastra_aluno(alunos)
  print 'Digite o nome do aluno: '
  nome = gets.chomp
  print 'Digite a matrícula do aluno: '
  matricula = gets.chomp
  print 'Digite o média de notas do aluno: '
  media = gets.chomp

  aluno = Aluno.new(nome, matricula, media)
  alunos.push(aluno)
  puts "\e[H\e[2J"

  p 'Aluno cadastrado com suscesso!'
  alunos
end

# Inicializando array vazio para armazenar vários alunos
alunos = []

loop do
  puts
  p 'HOME - Sistema de Cadastro de Alunos'
  puts
  p '1. Cadastrar novo aluno'
  p '2. Consultar aluno por matrícula'
  p '3. Exibir todos os alunos'
  p '4. Sair'
  puts
  print 'Escolha uma opção: '

  opcao = gets.chomp.to_i

  case opcao
  when 1
    alunos = cadastra_aluno(alunos)
  when 2
    print 'Digite o número da matrícula do aluno: '
    matricula = gets.chomp

    puts "\e[H\e[2J"

    aluno_encontrado = alunos.find do |aluno| 
      aluno.matricula == matricula 
    end
    if aluno_encontrado
      aluno_encontrado.exibir_dados
    else
      puts 'Aluno não encontrado'
    end

    puts
  when 3
    puts "\e[H\e[2J"
    if alunos.empty?
      p 'Nenhum aluno cadastrado.'
    else
      p 'Lista de alunos cadastrados:'
      alunos.each do |aluno|
        aluno.exibir_dados
      end
    end
    puts
  when 4
    puts "\e[H\e[2J"
    print 'Saindo do sistema. Até mais!'
    break
  else
    puts "\e[H\e[2J"
    p 'Opção inválida. Tente novamente!'
  end
end