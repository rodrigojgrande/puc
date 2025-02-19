#include "analex.h"

int token;

//cabeçalho

void E(){
    T();
    E_linha();
}

void consome(int t){
    if(token == t)
        token = analex();
    else{
        printf("ERRO SINTATICO\n");
        exit(1);
    }
}

void F(){
    if(token == NUM)
        consome(NUM);
    else if(token == '('){
        consome('(');
        E();
        consome(')');
    } else{
        printf("ERRO SINTATICO\n");
        exit(1);
    }
}

int main(){
    token = analex();
    E();
    if(token == ';')
        printf("Nao tem erros sintáticos");
    else
        printf("ERRO SINTATICO\n");
    return 1;
}