# DESAFIO: SISTEMA DE CADASTRO E CONSULTA DE ALUNOS

# DESCRIÇÃO: 
# - Crie um sistema que gerencie o cadastro de alunos em uma turma. Cada aluno tem nome, um número de matrícula e uma média de notas.
# - O sistema deve permitir o usuário:
# 1. Cadastrar novos alunos (inserir nome, matricula e média de notas)
# 2. Consultar os dados de uma aluno através da matrícula.
# 3. Exibir todos os alunos cadastrados

# Requisitos:
# - Utilize um hash para armazenar as informações dos alunos. A chave será o número de matrícula, e o valor será outro hash com os dados do alunos. 
# - O programa deve oferecer um menu de opções para o usuário escolher qual ação realizar (Cadastrar, Consultar, Exibir, Sair)

# aluno 
# nome
# número de matrícula 
# média de notas

# aluno = {matricula: 0, nome: "", media: 0}

# puts "Digite o valor de matricula: " # Escreve na tela

# var_atricula = gets.chomp.to_i # Captura uma informação

# aluno[:matricula] = var_atricula

# puts "Matricula Aluno: #{aluno[:matricula]}"


hash_alunos = {

}

controle = false

while controle != true
  #puts "\e[H\e[2J"
  puts "------DESAFIO ALUNOS---------" # Escreve na tela
  puts "[1] - Cadastrar" # Escreve na tela
  puts "[2] - Consultar" # Escreve na tela
  puts "[3] - Exibir" # Escreve na tela
  puts "[4] - Sair" # Escreve na tela
  puts "Escolha a operação: " # Escreve na tela
  operacao = gets.chomp.to_i # Captura uma informação
  
  case operacao 
      when 1
        flag = false
        # WHILE
        while flag != true
          puts "Digite o valor de matricula: " # Escreve na tela
          var_matricula = gets.chomp.to_i # Captura uma informação
  
          puts "Digite o nome do aluno " # Escreve na tela
          var_nome = gets.chomp # Captura uma informação
  
          puts "Digite a média do aluno " # Escreve na tela
          var_media = gets.chomp.to_f # Captura uma informação
  
          hash_alunos[var_matricula] = [nome: var_nome, media: var_media]
  
          puts "Deseja continuar [s/n]: " # Escreve na tela
          resposta = gets.chomp# Captura uma informação
  
          if resposta == "n"
            flag = true
          end
        end
      when 2
        puts "Digite o valor de matricula a ser pesquisada: " # Escreve na tela
        var_pesquisa_matricula = gets.chomp.to_i # Captura uma informação
          if hash_alunos.key?(var_pesquisa_matricula)
            p hash_alunos[var_pesquisa_matricula]
          else
            puts "Matrícula não encontrada" # Escreve na tela
          end
      when 3
        p hash_alunos
      when 4
        puts "Encerrando"
        controle = true
      else
          puts "Valor não encontrado"
  end

end