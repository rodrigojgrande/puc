#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define NUM 256

int token;

int analex(){ // Analisador Lexico (Retorna o token vigente)
    char ch; // Ler caracter do usuario

    ch = getchar();

    if (ch == '+')
        return '+';
    if (ch == '-')
        return '-';
    if (ch == '/')
        return '/';
    if (ch == '*')
        return '*';
    // ADD PARENTESE

    if (isdigit(ch))
        return NUM;

    // ungetc() (devolve um caractere)

    printf("ERRO LEXICO!\n");
    exit(1);
}