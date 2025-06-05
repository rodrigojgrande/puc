#! /bin/bash

if [ "$#" != "0" ]
then
    echo "---------------------------------------------------------------------------------------------------"
    echo "|                         Não são necessários argumentos.                                         |"
    echo "|      Garanta que entradas_saidas_cod e entradas_saidas_semantica estão na raíz                  |"
    echo "---------------------------------------------------------------------------------------------------"
    exit 2
fi



lex -o analex.c analex.l
yacc -o semantic.c semantic.y -d
gcc -o compilador semantic.c -lfl

pasta_arquivos="./entradas_saidas_semantica/"
n_outs=8
echo "---------------------------------------------------------------------------------------------------"
echo "|                           Verificando análise semântica                                         |"
echo "---------------------------------------------------------------------------------------------------"
for (( i=1; i<=${n_outs}; i++ ))
do
    leo_out="$pasta_arquivos/saida${i}_.txt" 
    student_out="$pasta_arquivos/saida${i}.txt"

    ./compilador "${pasta_arquivos}/entrada${i}.c" > ${student_out}

    result_leo=$(cat $leo_out)
    result_student=$(cat $student_out)
    
    if [ "$result_leo" == "$result_student" ]
    then
        echo "entrada${i}.c resultou idêntico"
    else
        echo "entrada${i}.c resultou diferente"
    fi
done

echo "---------------------------------------------------------------------------------------------------"
echo "|                           Verificando geração de código                                         |"
echo "---------------------------------------------------------------------------------------------------"
pasta_arquivos="./entradas_saidas_cod/"
n_outs=4
for (( i=1; i<=${n_outs}; i++ ))
do
    leo_out="$pasta_arquivos/saida${i}_.txt" 
    student_out="$pasta_arquivos/saida${i}.txt"

    ./compilador "${pasta_arquivos}/entrada${i}.c" > ${student_out}

    result_leo=$(cat $leo_out)
    result_student=$(cat $student_out)
    
    if [ "$result_leo" == "$result_student" ]
    then
        echo "entrada${i}.c resultou idêntico"
    else
        echo "entrada${i}.c resultou diferente"
    fi
done

