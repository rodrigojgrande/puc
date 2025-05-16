%{ 
#include "analex.c" 
%}

%token NUM 
%token ID 
%token INT
%token IF 
%token ELSE
%token WHILE
%token GE
%token DO
%token VOID
%token CHAR

%left '+' '-'
%left '*' '/'

%start ProgL
%%

ProgL : Prog {printf("Sem erros sintáticos\n");}
    ;

Prog : Exp ';'
	;


Exp :
	  Exp '+' Exp
	| Exp '-' Exp
	| Exp '*' Exp
	| Exp '/' Exp
	| '(' Exp ')'
	| NUM		   
	| ID           
	;   

%%  
void main(int argc, char **argv) {     
  yyin = fopen(argv[1],"r");
  yyparse();      
} 
