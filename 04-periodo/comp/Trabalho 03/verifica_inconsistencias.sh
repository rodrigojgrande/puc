#! /bin/bash

if [ "$#" != "1" ]
then
    echo "---------------------------------------------------------------------------------------------------------"
    echo "|Para executar o script, garanta que você está na raíz do seu projeto (onde seus códigos .l e .h estão)  |"
    echo "|Como único argumento do script, informe o caminho relativo onde estão os arquivos entradaX.c e saidaX_.c|"
    echo "|                         Exemplo: ./verifica_inconsistencias entradas_saidas/                           |"
    echo "---------------------------------------------------------------------------------------------------------"
    exit 2
fi

pasta_arquivos=$1

n_outs=12

lex -o analex.c analex.l
yacc -o sint.c sint.y -d
gcc -o sint sint.c -lfl


for (( i=1; i<=${n_outs}; i++ ))
do
    leo_out="$pasta_arquivos/saida${i}_.txt" 
    student_out="$pasta_arquivos/saida${i}.txt"

    ./sint "${pasta_arquivos}/entrada${i}.c" > ${student_out}

    result_leo=$(cat $leo_out)
    result_student=$(cat $student_out)
    
    if [ "$result_leo" == "$result_student" ]
    then
        echo "entrada${i}.c resultou idêntico"
    else
        echo "entrada${i}.c resultou diferente"
    fi
done
