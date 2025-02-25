#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define NUM 256

int token;

int analex(){
    char ch;

    // O analisador deverá ignorar os espaços em branco, tabs, e pula linhas.
    do {
        ch = getchar();
    } while (isspace(ch));

    /*
    ' ' (espaço)
    '\t' (tabulação)
    '\n' (nova linha)
    '\v' (tab vertical)
    '\f' (nova página)
    */

    // Operadores ("+", "-", "*" e "/"), "(", ")", ";".
    if(ch == '+')
        return '+';
    if(ch == '-')
        return '-';
    if(ch == '*')
        return '*';
    if(ch == '/')
        return '/';
    if(ch == ';')
        return ';';
    if(ch == '(')
        return '(';
    if(ch == ')')
        return ')';

    /*if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == ';' || ch == '(' || ch == ')' )
        return ch;
    */


    // Constantes Inteiras [0-9]
    if(isdigit(ch)){        // verifica se ch é um dígito numérico (0-9)
        ungetc(ch, stdin);  // Devolve ch para a entrada padrão (stdin).
        int num;
        scanf("%d", &num);
        return NUM;
    }


    printf("ERRO LEXICO!!\n");
    exit(1);
}
