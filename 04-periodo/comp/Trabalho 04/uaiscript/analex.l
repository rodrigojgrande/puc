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
"vazio_so"          { return VOID; }
"e_so"              { return AND; }
"ou_sinao"          { return OR; }
"de_jeito_nenhum"   { return NOT; }
"meno_ou_igualzin"  { return MENOR; }
"maio_ou_igualzin"  { return MAIOR; }
"soma_mais"         { return '+'; }
"tira_menos"        { return '-'; }
"veis"              { return '*'; }
"dividido_pur"      { return '/'; }
"meno_que"          { return '<'; }
"maio_que"          { return '>'; }
"("                 { return '('; }
")"                 { return ')'; }
"{"                 { return '{'; }
"}"                 { return '}'; }
"["                 { return '[';}
"]"                 { return ']';}
","                 { return ','; }
";"                 { return ';'; }
":"                 { return ':'; }
"fica_sendo"        { return '='; }   
"igualzin"          { return IGUAL; }
"vorta"             { return RETURN; }

"grandin_dimais"    { return DOUBLE;}
"muda_o_trem"       { return SWITCH;}
"casim"             { return CASE;}
"larga_mao"         { return BREAK;}
"num_ehigual"       { return DIFERENTE;}
"acabo_uai"         { return ENDIF;}

{dig}+(\.{dig}+)?   { ylval.node.tipo = FLOAT; yylval.node.place = atoi(yytext); return NUM; }       

{string} { return STRINGS; } 

{letra}({letra}|{dig})* { insere(yytext); return ID; } 

[ \t\r] {}
\n { linha++; }

. {printf("erro lexico na linha %d - %s\n", linha, yytext); }

%%

#ifndef yywrap
int yywrap() { return 1; }
#endif
