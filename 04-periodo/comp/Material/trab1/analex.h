#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define NUM 256

int token;

int analex(){
    char ch;

    ch = getchar();

    if(ch == '+')
        return '+';
    if(ch == '-')
        return '-';
    if(ch == '*')
        return '*';
    if(ch == '/')
        return '/';
    //ADD PARENTESE
    if(isdigit(ch))
        return NUM;

        //putchar(token)

    
    
    printf("ERRO LEXICO!!\n");
    exit(1);
}