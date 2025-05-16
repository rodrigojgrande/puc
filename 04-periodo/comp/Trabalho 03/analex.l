%{
#include <stdio.h>
#include "sint.y"
#include "tabsimb.h"
int linha = 1;
%}

dig [0-9]
letra [a-zA-Z_]
string \"(\\.|[^"])*\"

%%
"uai_so"            { return IF; }
"capai_memo"        { return ELSE; }
"repete_ai_so"      { return FOR; }
"vai_ino"           { return WHILE; }
"interin"           { return INT; }
"picadin"           { return FLOAT; }
"letrin"            { return CHAR; }
"vazio_so"         { return VOID; }
"e_so"             { return AND; }
"ou_sinao"         { return OR; }
"de_jeito_nenhum"  { return NOT; }
"soma_mais"        { return '+'; }
"tira_menos"       { return '-'; }
"vezes"            { return '*'; }
"dividido_pur"     { return '/'; }
"meno_que"         { return '<'; }
"maio_que"         { return '>'; }
"meno_ou_igualzin" { return MENOR; }
"maio_ou_igualzin" { return MAIOR; }
"(" { return '('; }
")" { return ')'; }
"{" { return '{'; }
"}" { return '}'; }
"[" { return '[';}
"]" { return ']';}
"," { return ','; }
";" { return ';'; }
"fica_sendo"       { return '='; }   
"igualzin"         { return IGUAL; }
"vorta"            {return RETURN; }

{dig}+(\.{dig}+)?   { return NUM; }       

{string} {return STRINGS; } 

{letra}({letra}|{dig})* { insere(yytext); return ID; } 

[ \t\r] {}
\n { linha++; }

. {printf("erro lexico na linha %d - %s\n", linha, yytext); }

%%

#ifndef yywrap
int yywrap() { return 1; }
#endif

void main(int argc, char **argv) {
    int token, i = 1;
    yyin = fopen(argv[1], "r");
    token = yylex();
    
    while(token) {
        printf("%d) %d %s\n", i++, token, yytext);
        token = yylex();
    }
    
    imprime();
}