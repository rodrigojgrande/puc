%{ 
/* Para simplificar a notação, S é para sintetizar. A atualizar. V verificar */
#include "analex.c" 
#include "codigo.h" 
/* Funcoes auxiliares podem ser declaradas aqui */
void verifica_var_declarada(?);
%}

%union{
	struct no{
		int place;
		char *code;
		int tipo;
	} node;
	int val;
	struct ids{
		int ids[50];
		int tam;
		char *code;
	} id_list;
}

%token <node> NUM 
%token <val> ID 
%token WHILE
%token IF 
%token ELSE
%token ENDIF
%token CHAR
%token INT
%token FLOAT
%token VOID
%token OR
%token AND
%token NOT
%token GE
%token LE
%token EQ
%token NEQ
%token DO
%token STRING

%type <val> Type TypeF
%type <id_list> IDs ParamList ArgList
%type <node> Atribuicao Exp Function Prog Statement Statement_Seq
%type <node> If While Compound_Stt DoWhile FunctionCall For

%right '='

%left OR
%left AND

%nonassoc EQ NEQ

%left '>' '<' GE LE

%left '+' '-'
%left '*' '/' '%'

%right NOT

%right '(' '['


%start ProgL
%% 
ProgL : Prog { printf("%s",$1.code);} /* S código. */
    ;
    
Prog : Prog Function {create_cod(&$$.code); insert_cod(&$$.code,$1.code); insert_cod(&$$.code,$2.code);} /* S código. */
	| Function {$$.cod=$1.code}/* S código. */
	;	

Function :
	TypeF ID '(' ParamList ')' '{' Decls Statement_Seq '}'  {?} /* A. Tabela. S código. */
	| TypeF ID '(' ')' '{' Decls Statement_Seq '}'  {?} /* A. Tabela. S código. */
	;
	
FunctionCall :
    ID '(' ArgList ')' {?} /* V declaração, # argumentos. S código*/
	| ID '(' ')' {?} /* V declaração, # argumentos. S código*/
    ;
    
ArgList:
    Exp ',' ArgList {?} /* S código e Lista de IDs*/
    | Exp  {?} /* S código e Lista de IDs*/
    ;

ParamList: 
    ParamList ',' Type ID  {?} /* S Lista de IDs. A Tabela*/
    | Type ID {?} /* S Lista de IDs. A Tabela*/
	; 
		
Decls:
	  Decl ';' Decls  
	| 
	;

Decl:
	Type IDs {?} /* A tabela. */
	; 
	
IDs :
	  IDs ',' ID {?} /* S Lista de IDs. */
	| IDs ',' Atribuicao {?} /* S Lista de IDs. */
	| IDs ',' ID '[' NUM ']' {?} /* S Lista de IDs. */
	| ID '[' NUM ']' {?} /* S Lista de IDs. */
	| ID {?} /* S Lista de IDs. */
	| Atribuicao {?} /* S Lista de IDs. */
	;
	
TypeF :
	  VOID {?} /* S Tipo. */
	| Type
	;

Type :
	  INT {?} /* S Tipo. */
	| CHAR {?} /* S Tipo. */
	| FLOAT {?} /* S Tipo. */
	;
			
Statement_Seq :
	Statement Statement_Seq {?} /* S Codigo. */
	| Statement { create_cod(&$$.code); insert_cod(&$$.code,$1.code);} /* S Codigo. Exemplo */
	;
		
Statement: 
	  Atribuicao ';' {verifica_var_declarada($1.place); verifica_tipos_atrib(Tabela[$1.place].tipo, $1.tipo);} /* V declaracao, tipos atribuicao. */
	| If  /* S código. */
	| For  /* S código. */
	| While /* S código. */
	| DoWhile /* S código. */
	| FunctionCall ';'  /* S código. */
	;

Compound_Stt :
	  Statement  /* S código. Exemplo resolvido */
	| '{' Statement_Seq '}' {$$ = $2;}  /* S código. Exemplo resolvido */
	;
		
If :
	  IF '(' Exp ')' Compound_Stt ENDIF { If(?,?,?); } /* S código. Exemplo */
	| IF '(' Exp ')' Compound_Stt ELSE Compound_Stt ENDIF {?} /* S código. */
	;

While:
	WHILE '(' Exp ')' Compound_Stt  {?} /* S código. */
	;

DoWhile:
	DO Compound_Stt WHILE '(' Exp ')' ';' {?} /* S código. */
	;
			
Atribuicao : ID '[' NUM ']' '=' Exp {?} /* V tipo indice. S tipo, place, código. */
    | ID '=' Exp {?} /* S tipo, place, código. */
	;
				
Exp :
	  Exp '+' Exp {$$.tipo = retorna_maior_tipo($1.tipo,$2.tipo);} /* S tipo, cod */
	| Exp '-' Exp {?} /* S tipo, cod */
	| Exp '*' Exp {?} /* S tipo, cod */
	| Exp '/' Exp {?} /* S tipo, cod */
	| Exp '>' Exp {?} /* S tipo, cod (bgt) */
	| Exp '<' Exp {?} /* S tipo, cod (blt) */
	| Exp GE Exp {?} /*  S tipo. Não precisa implementar código*/
	| Exp LE Exp {?} /*  S tipo. Não precisa implementar código*/
	| Exp EQ Exp {?} /*  S tipo. Não precisa implementar código*/
	| Exp NEQ Exp {?} /*  S tipo. Não precisa implementar código*/
	| Exp OR Exp {?} /* S tipo, cod */
	| Exp AND Exp {?} /* S tipo, cod */
	| NOT Exp {?} /*  S tipo. Não precisa implementar código*/
	| '(' Exp ')' {?} /*  S tipo, cod*/
	| NUM {$$tipo = $1.tipo} /* S tipo, código */
	| ID '[' NUM ']' {?}  /* V declaracao, indice. S tipo, codigo  */
	| ID  {verifica_var_declarada($1); $$tipo = Tabela[$1].tipo;} /* V declaracao. S tipo, codigo  */
	| STRING {} /* Ignore, não precisa implementar  */
	;   
	
	
%%  
int main(int argc, char **argv) {     
  yyin = fopen(argv[1],"r");
  yyparse();      
} 

/* Funcoes auxiliares podem ser implementadas aqui */
void verifica_var_declarada(?){
	// Verifica na tabela de símbolos se a váriavel foi declarada
	?
}
