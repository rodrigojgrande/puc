#include "analex.h"

int token;

// Cabeçalho

int analex();
void consome(int t);
void E();
void E_linha();
void T();
void T_linha();
void F();

void consome(int t){
    if(token == t)
        token = analex();
    else{
        printf("ERRO SINTATICO\n");
        exit(1);
    }
}

void E(){
    T();
    E_linha();
}

void E_linha(){
    if (token == '+' || token == '-'){
        int op = token;
        consome(token);
        T();
        E_linha();
    }
}

void T(){
    F();
    T_linha();
}

void T_linha(){
    if (token == '/' || token == '*'){
        int op = token;
        consome(token);
        F();
        T_linha();
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
        printf("Nao tem erros sintaticos");
    else
        printf("ERRO SINTATICO\n");
    return 1;
}
