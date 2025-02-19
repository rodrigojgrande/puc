#include "analex.c"

int token;

// Cabeçalho de funções

void E(){
    T();
    E_linha();
}

void consome (int t){
    if(token == t){
        if(token == t)
            token - analex();
        else{
            print("ERRO SINTÁTICO\n");
            exit(1);
        }
    }
}

void F(){
    if(token == NUM)
        consome (NUM);
    else if(token == '('){
        consome ('(');
        E();
        consome(')');
    } else {
        print("ERRO SINTATICO\n");
        exit(1);
    }
}

int main(){
    token - analex();
    E();
    if(token == ;)
        printf("Nao tem erros sintáticos");
    else
        printf("ERRo SINTATICO\n");
    return 1;
}