%{
#include <stdio.h>
#include "semantic.h"
#include "tabsimb.h"
#include <stdio.h>
int linha = 1;

int yyerror(char *s) { 
  printf("%s na linha %d\n",s,linha);
  exit(1); 
}
%}

DIGITO [0-9]
LETRA [a-zA-Z_]

%%


"while" {return WHILE;}
"if"	{return IF;}
"else"	{return ELSE;}
"int"  {return INT;}
"float" {return FLOAT;}
"char"  {return CHAR;} 
"void" {return VOID;}
"endif" {return ENDIF;}


"+" {return '+';}
"-" {return '-';}
"*" {return '*';}
"/" {return '/';}
"%" {return '%';}


">="  {return GE;}
"<=" {return LE;}
">" {return '>';}
"<" {return '<';}
"==" {return EQ;} 	


"&&" {return AND;}
"||" {return OR;}
"!" {return NOT;}


"=" {return '=';}


"["	  {return '[';}
"]"	  {return ']';}
"("	  {return '(';}
")"   {return ')';}
"{"	  {return '{';}
"}"   {return '}';}
";"   {return ';';}
","   {return ',';}


{DIGITO}+("."{DIGITO}+) { yylval.node.tipo = FLOAT; yylval.node.place = atoi(yytext);return NUM;}

{DIGITO}+	{ yylval.node.tipo = INT; yylval.node.place = strtol(yytext, NULL, 10); return NUM;}


{LETRA}({LETRA}|{DIGITO})*  { yylval.val = insere(yytext); return ID;}  
                           
\"[^\"]*\"   { return STRING; }

[ \t\r] {}
\n	{ linha++; }
.	{printf("erro lexico na linha %d - %s\n",
             linha, yytext); }
%%

#ifndef yywrap
int yywrap() { return 1; }
#endif
