%{ 
/* Para simplificar a notação, S é para sintetizar. A atualizar. V verificar */
#include "analex.c" 
#include "codigo.h" 

/* Funcoes auxiliares podem ser declaradas aqui */
void verifica_var_declarada(int id);
void verifica_funcao_declarada(int id);
void verifica_tipos_atrib(int tipo1, int tipo2);
void verifica_numero_argumentos(int id, int num_args);
void verifica_indice_valido(int id, int indice);
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

%token NUM 
%token STRINGS
%token ID 
%token IF 
%token ELSE
%token FOR
%token WHILE
%token INT
%token FLOAT
%token CHAR
%token VOID
%token AND
%token OR
%token NOT
%token MENOR
%token MAIOR
%token IGUAL
%token RETURN
%token DOUBLE
%token SWITCH
%token CASE
%token BREAK
%token DIFERENTE
%token ENDIF

%type <val> Type TypeF
%type <id_list> IDs ParamList ArgList
%type <node> Atribuicao Exp Function Prog Statement Statement_Seq
%type <node> If While Compound_Stt DoWhile FunctionCall For

%right '='
%right NOT
%left '+' '-'
%left '*' '/'
%left OR
%left AND
%nonassoc IGUAL DIFERENTE
%nonassoc '<' '>' MAIOR MENOR


%start Programa
%%


ProgL : Prog { 
		printf("%s",$1.code);
	} /* S código. */
;
    
Prog : Prog Function {
		create_cod(&$$.code); 
		insert_cod(&$$.code,$1.code); 
		insert_cod(&$$.code,$2.code);
		} /* S código. */
	| Function {
		create_cod(&$$.code); 
		insert_cod(&$$.code,$1.code); 
	}/* S código. */
;	

Function :
	TypeF ID '(' ParamList ')' '{' Decls Statement_Seq '}'  {
		adiciona_funcao_tabela(obtemNome($2), $1, &$4);
		create_cod(&$$.code);
		if($7.code != NULL)
    insert_cod(&$$.code, $7.code);
    Funct(&$$, $2, $7);        
	} /* A. Tabela. S código. */
	| TypeF ID '(' ')' '{'Statement_Seq '}' {
			adiciona_funcao_tabela(obtemNome($2), $1, NULL); 
      create_cod(&$$.code);
      if($6.code != NULL)
        insert_cod(&$$.code, $6.code);
      Funct(&$$, $2, $6);            
	} /* A. Tabela. S código. */
;
	
FunctionCall :
  ID '(' ArgList ')' {
		int funcPos = $1; 
		if (getTipo(funcPos) == -1) {
    	yyerror("Uso de identificador nao declarado");
		} else if (Tabela[funcPos].tam_arg_list != $3.tam) { /* V declaração, # argumentos. S código*/
		verifica_numero_argumentos($1, $3.tam);
  	yyerror("Número de argumentos incompatível!");
 		} create_cod(&$$.code);
    if($3.code != NULL)
    	insert_cod(&$$.code, $3.code);
    Call(&$$, funcPos, $3);
	}
	| ID '(' ')' {
		int funcPos = procura(obtemNome($1));
		if (funcPos == -1) {
			yyerror("Uso de identificador nao declarado");
		} else if (Tabela[funcPos].tam_arg_list != 0) {
			yyerror("Número de argumentos incompatível!");
		}
		Call_blank(&$$, funcPos);
	} /* V declaração, # argumentos. S código*/
;
    
ArgList:
    Exp ',' ArgList {
			create_cod(&$$.code);
			$$.tam = $3.tam;
			for (int i = 0; i < $3.tam; i++) {
					$$.ids[i] = $3.ids[i];
			}
			$$.ids[$$.tam] = $1.place;
			create_cod(&$$.code);
			if($1.code != NULL)
					insert_cod(&$$.code, $1.code);
			if($3.code != NULL)
					insert_cod(&$$.code, $3.code);
			$$.tam++;
		} /* S código e Lista de IDs*/
    | Exp  {
			create_cod(&$$.code);
      $$.tam = 1;
      $$.ids[0] = $1.place;
      if($1.code != NULL)
      	insert_cod(&$$.code, $1.code);
		} /* S código e Lista de IDs*/
  ;

ParamList: 
    ParamList ',' Type ID  {
			$$.tam = $1.tam;
      for (int i = 0; i < $1.tam; i++) {
      	$$.ids[i] = $1.ids[i];
      }
      $$.ids[$$.tam] = $4;  // Add the new identifier
      if(getTipo($4) == -1) {
        set_type($$.ids[$$.tam], $3);
      }
      else 
        if(getTipo($4) != $3)
        	yyerror("Tipos de argumentos incompatíveis!");
      $$.tam++;
		} /* S Lista de IDs. A Tabela*/
    | Type ID {
			$$.tam = 1;
    	$$.ids[0] = $2;  // Handle single ID
      if(getTipo($2) == -1) {
        set_type($$.ids[0], $1);
      }
      else 
        if(getTipo($2) != $1)
          yyerror("Tipos de argumentos incompatíveis!");
		} /* S Lista de IDs. A Tabela*/
; 
		
Decls:
	Type IDs { /* A tabela. */
  	int tipo = -5;
    create_cod(&$$.code);
    if ($2.code != NULL)
    insert_cod(&$$.code, $2.code);

    for (int i = 0; i < $2.tam; i++) {
    	if(&Tabela[$2.ids[i]] != NULL)
      	tipo = getTipo($2.ids[i]);
      if (tipo != $1 && tipo != -1) {
        printf("O tipo %i de %s não é %i\n", tipo, obtemNome($2.ids[i]), $1);
        yyerror("Erro Semântico Decl");
      }
      set_type($2.ids[i], $1);  // Define o tipo corretamente
    }
  }
;
	
IDs :
	IDs ',' ID {
		for ($$.tam = 0; $$.tam < $1.tam; $$.tam++) {
			$$.ids[$$.tam] = $1.ids[$$.tam];
		}
		$$.tam++;  // Increment the tam
		$$.ids[$$.tam] = $3;  // Add the new identifier
		$$.tam++;  // Increment the tam
	} /* S Lista de IDs. */
	| IDs ',' Atribuicao {
		for ($$.tam = 0;$$.tam < $1.tam; $$.tam++) {
            $$.ids[$$.tam] = $1.ids[$$.tam];
  	}
		int pos = $3.place;
		create_cod(&$$.code);
		insert_cod(&$$.code, $3.code);
		$$.tam++;  // Increment the tam
		$$.ids[$$.tam] = pos;
		$$.tam++;  // Increment the tam
	} /* S Lista de IDs. */
	| IDs ',' ID '[' NUM ']' {
		if(yy_tipo != INT) {
			yyerror("Tipos incompatíveis");
		}
		for ($$.tam = 0; $$.tam < $1.tam; $$.tam++) {
				$$.ids[$$.tam] = $1.ids[$$.tam];
		}
		$$.tam++;
		$$.ids[$$.tam] = $3;  // Add the new identifier with array
		$$.tam++;  // Increment the tam
	} /* S Lista de IDs. */
	| ID '[' NUM ']' {
		if(yy_tipo != INT) {
      yyerror("Tipos incompatíveis");
    }
    $$.ids[$$.tam] = $1;  // Handle single array element
	} /* S Lista de IDs. */
	| ID {
		$$.tam = 1;
    $$.ids[$$.tam] = $1;  // Handle single ID
	} /* S Lista de IDs. */
	| Atribuicao {
		int pos = $1.place;
		create_cod(&$$.code);
		insert_cod(&$$.code, $1.code);
		$$.tam++;
		$$.ids[$$.tam] = pos;  // Handle assignment
	} /* S Lista de IDs. */
;
	
TypeF :
	  VOID {$$ = VOID;} /* S Tipo. */
	| Type {$$ = $1;}
;

Type :
 	INT {$$ = INT;} /* S Tipo. */
	| CHAR {$$ = CHAR;} /* S Tipo. */
	| FLOAT {$$ = FLOAT;} /* S Tipo. */
;
			
Statement_Seq :
	Statement Statement_Seq {
		create_cod(&$$.code);
    insert_cod(&$$.code, $1.code);
    insert_cod(&$$.code, $2.code);
	} /* S Codigo. */
	| Statement { 
		create_cod(&$$.code); 
		insert_cod(&$$.code,$1.code);
	} /* S Codigo. Exemplo */
;
		
Statement: 
	Atribuicao ';' {
		if($1.tipo == -1) {
			yyerror("Erro Semântico, var não declarada");
		}
		retorna_maior_tipo(getTipo($1.place), $1.tipo);
		create_cod(&$$.code);
		insert_cod(&$$.code, $1.code);
	} /* V declaracao, tipos atribuicao. */
	If  {
		create_cod(&$$.code);
		insert_cod(&$$.code, $1.code);
  } /* S código. */
	| While {
		create_cod(&$$.code);
		insert_cod(&$$.code, $1.code);
  } /* S código. */
	| DoWhile {
		create_cod(&$$.code);
		insert_cod(&$$.code, $1.code);
  }/* S código. */
	| FunctionCall ';' {
		create_cod(&$$.code);
		insert_cod(&$$.code, $1.code);
  }  /* S código. */
  | Decl ';' {
		create_cod(&$$.code);
		insert_cod(&$$.code, $1.code);
	}
;


Compound_Stt :
	  Statement  /* S código. Exemplo resolvido */
	| '{' Statement_Seq '}' {$$ = $2;}  /* S código. Exemplo resolvido */
;
		
If :
	IF '(' Exp ')' Compound_Stt ENDIF { 
		If(&$$, $3,$5);
	} /* S código. Exemplo */
	| IF '(' Exp ')' Compound_Stt ELSE Compound_Stt ENDIF {
		IfElse(&$$, $3, $5, $7);	
	} /* S código. */
;

While:
	WHILE '(' Exp ')' Compound_Stt {
  	While(&$$, $3, $5);
  } /* S código. */
;

DoWhile:
	DO Compound_Stt WHILE '(' Exp ')' ';' {
    DoWhile(&$$, $2, $5);
  } /* S código. */
;
			
Atribuicao : 
  ID '[' NUM ']' '=' Exp {
    if(yy_tipo != INT) {
      yyerror("Tipos incompatíveis");
    }
    if(tipos_inconsistentes_atrib(getTipo($1), $6.tipo) == -1) {
      yyerror("Tipos incompatíveis");
    }
    $$.place = $1;
    Atrib(&$$, $3);
    $$.tipo = retorna_maior_tipo(getTipo($1), $6.tipo);
    } /* V tipo indice. S tipo, place, código. */
  | ID '=' Exp {
		if(tipos_inconsistentes_atrib(getTipo($1), $3.tipo) == -1) {
			//printf("Var %s tem tipo %i e não pode receber valor de tipo %i\n", obtemNome($1), getTipo($1), $3.tipo);
			yyerror("Tipos incompatíveis");
		}
		$$.place = $1;
		Atrib(&$$, $3);  // Gera o código para a atribuição
		$$.tipo = retorna_maior_tipo(getTipo($1), $3.tipo);
  } /* S tipo, place, código. */
;
				
Exp :
	Exp '+' Exp {
  	$$.tipo = retorna_maior_tipo($1.tipo, $3.tipo);
    ExpAri(&$$, $1, $3, "add");
  } /* S tipo, cod */
	| Exp '-' Exp {
    $$.tipo = retorna_maior_tipo($1.tipo, $3.tipo);
    ExpAri(&$$, $1, $3, "sub");
  } /* S tipo, cod */
	| Exp '*' Exp {        
    $$.tipo = retorna_maior_tipo($1.tipo, $3.tipo);
    ExpAri(&$$, $1, $3, "mul");
  } /* S tipo, cod */
	| Exp '/' Exp {
    $$.tipo = retorna_maior_tipo($1.tipo, $3.tipo);
    ExpAri(&$$, $1, $3, "div");
  } /* S tipo, cod */
	| Exp '>' Exp {
		$$.tipo = INT;
		Bgt(&$$, $1, $3, "bgt");
	} /* S tipo, cod (bgt) */
	| Exp '<' Exp {
		$$.tipo = INT;
		Bgt(&$$, $1, $3, "blt");
	} /* S tipo, cod (blt) */
	| Exp GE Exp  {
		$$.tipo = INT;
		Bgt(&$$, $1, $3, "blt");
	} /*  S tipo. Não precisa implementar código*/
	| Exp LE Exp  {
		$$.tipo = INT;
		Bgt(&$$, $1, $3, "bgt");
	} /*  S tipo. Não precisa implementar código*/
	| Exp EQ Exp  {
		$$.tipo = INT;
		Bgt(&$$, $1, $3, "beq");
	} /*  S tipo. Não precisa implementar código*/
	| Exp NEQ Exp {
		$$.tipo = INT;
		Bgt(&$$, $1, $3, "bne");
	} /*  S tipo. Não precisa implementar código*/
	| Exp OR Exp {
		$$.tipo = INT;
		Explog(&$$, $1, $3, "or");
	} /* S tipo, cod */
	| Exp AND Exp {
		$$.tipo = INT;
		Explog(&$$, $1, $3, "and");
	} /* S tipo, cod */
	| NOT Exp {
		$$.tipo = INT;
	} /*  S tipo. Não precisa implementar código*/
	| '(' Exp ')' {
    create_cod(&$$.code);
    if($2.code != NULL)
      insert_cod(&$$.code, $2.code);
		$$.tipo = $2.tipo;
	} /*  S tipo, cod*/
	| NUM {
    if (yy_tipo == FLOAT) {
      $$.tipo = FLOAT;
      Li(&$$, yylval.fval);
    } else {
      $$.tipo = INT;
      Li(&$$, yylval.ival);
  	}
	} /* S tipo, código */
	| ID '[' NUM ']' {
    if(getTipo($1) == -1) {
      yyerror("Uso de variável não declarada");
    }
    if(yy_tipo != INT) {
      yyerror("Indices de vetor não inteiro");
    }
    create_cod(&$$.code);
    if($3.code != NULL)
      insert_cod(&$$.code, $3.code);
    $$.tipo = getTipo($1);
    }  /* V declaracao, indice. S tipo, codigo  */
	| ID  {
    int tipo = getTipo($1);
    if(tipo != INT && tipo != FLOAT && tipo != CHAR && tipo != VOID) {
      yyerror("Uso de variável não declarada");
    }
    create_cod(&$$.code);
    $$.tipo = getTipo($1);
    } /* V declaracao. S tipo, codigo  */
	| STRING {} /* Ignore, não precisa implementar  */
	;   
	
%%  
int main(int argc, char **argv) {     
  yyin = fopen(argv[1],"r");
  yyparse();      
} 

/* Funcoes auxiliares podem ser implementadas aqui */
void verifica_var_declarada(int id) {
    if (Tabela[id].tipo == 0) { 
        fprintf(stderr, "Erro: Variável %s não foi declarada.\n", Tabela[id].nome);
        exit(1); 
    }
}

void verifica_funcao_declarada(int id) {
    if (Tabela[id].tipo == -1) {
        fprintf(stderr, "Erro: Função %s não foi declarada.\n", Tabela[id].nome);
        exit(1);
    }
}

void verifica_tipos_atrib(int tipo1, int tipo2) {
    if (tipo1 != tipo2) {
        fprintf(stderr, "Erro: Tipos incompatíveis na atribuição.\n");
        exit(1);
    }
}

void verifica_numero_argumentos(int id, int num_args) {
    if (Tabela[id].tam_arg_list != num_args) {
        fprintf(stderr, "Erro: Função %s esperava %d argumentos, mas recebeu %d.\n",
                Tabela[id].nome, Tabela[id].tam_arg_list, num_args);
        exit(1);
    }
}

void verifica_indice_valido(int id, int indice) {
    if (indice < 0 || indice >= Tabela[id].tam) {
        fprintf(stderr, "Erro: Índice %d fora dos limites do vetor %s.\n", indice, Tabela[id].nome);
        exit(1);
    }
}
