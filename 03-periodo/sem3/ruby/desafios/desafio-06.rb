class Aluno
  attr_accessor :matricula, :nome, :media

  def initialize(matricula, nome, media)
    @matricula = matricula
    @nome = nome
    @media = media
  end
end

class SistemaCadastroAlunos
  def initialize
    @alunos = {} # Cria um hash de alunos
  end

  def cadastra_aluno
    print 'Digite o nome do aluno: '
    nome = gets.chomp
    print 'Digite a matrícula do aluno: '
    matricula = gets.chomp
    print 'Digite a média de notas do aluno: '
    media = gets.chomp

    aluno = Aluno.new(matricula, nome, media) # Instancia um objeto aluno na variável aluno
    @alunos[matricula] = aluno # A hash com chave matricula recebe o objeto aluno
    puts "\e[H\e[2J"

    puts 'Aluno cadastrado com sucesso!'
  end

  def consultar_aluno
    print 'Digite o número da matrícula do aluno: '
    matricula = gets.chomp

    puts "\e[H\e[2J"
    if @alunos.key?(matricula) # Se existir na hash de alunos a chave matricula
      aluno = @alunos[matricula]  # Variabel aluno recebe o valor da chave da hash
      puts 'Dados do aluno:'
      puts "Nome: #{aluno.nome}" # Printa o valor do nome
      puts "Média: #{aluno.media}" # Printa o valor da media
    else
      puts 'Aluno não encontrado.'
    end
  end

  def exibir_todos_alunos
    puts "\e[H\e[2J"
    if @alunos.empty?
      puts 'Nenhum aluno cadastrado.'
    else
      puts 'Lista de alunos cadastrados:'
      @alunos.each do |matricula, aluno| # Loop que percorre a hash de alunos, passando a chave matricula e o valor como objeto aluno
        puts "Matrícula #{matricula} - Nome: #{aluno.nome} - Média: #{aluno.media}"
      end
    end
  end

  def menu
    loop do
      puts
      puts 'HOME - Sistema de Cadastro de Alunos'
      puts
      puts '1. Cadastrar novo aluno'
      puts '2. Consultar aluno por matrícula'
      puts '3. Exibir todos os alunos'
      puts '4. Sair'
      puts
      print 'Escolha uma opção: '

      opcao = gets.chomp.to_i

      case opcao
      when 1
        cadastra_aluno
      when 2
        consultar_aluno
      when 3
        exibir_todos_alunos
      when 4
        puts "\e[H\e[2J"
        puts 'Saindo do sistema. Até mais!'
        break
      else
        puts "\e[H\e[2J"
        puts 'Opção inválida. Tente novamente!'
      end
    end
  end
end

# Inicia o sistema
sistema = SistemaCadastroAlunos.new
sistema.menu
