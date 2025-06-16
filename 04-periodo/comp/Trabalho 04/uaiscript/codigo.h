#include "semantic.h"
#include "listacodigo.h"

int temp=-1;
int newTemp() {
	return temp--;
}

void freeTemp() {
	temp++;
}
int label = 0;
int newLabel() {
	return ++label;
}

char reg1[5];
char reg2[5];
char reg_temp[5];
void getName(int num, char *name) {
  if (num >= 0 ) {
    sprintf(name,"$s%d",num);
  }
  else 
    sprintf(name,"$t%d",-(num+1));
}

/* Geração de código para criar uma função. Exemplo */
void Funct(struct no* Funct, int Id, struct no Comandos) {
	create_cod(&Funct->code);
	obtemNome(Id);
	sprintf(instrucao,"%s:\n",nome);
	insert_cod(&Funct->code,instrucao);
	insert_cod(&Funct->code,Comandos.code);
	if (strcmp(nome,"main")==0) {
		sprintf(instrucao,"\tli $v0,10\n"); //Define exit
		insert_cod(&Funct->code,instrucao);
		sprintf(instrucao,"\tsyscall\n\n"); //Call exit
		insert_cod(&Funct->code,instrucao);					
	}
	else {
		sprintf(instrucao,"\tjr $ra\n\n"); //Return to previous function
		insert_cod(&Funct->code,instrucao);

	}
}

/* Função pre-implementada para lidar com argumentos de forma simples */
void adiciona_argumentos(char **code, int id, struct ids Args){
  struct symbol simbolo = Tabela[id];
  char name_param[5];
  char name_arg[5];
  for(int i = 0; i<simbolo.tam_arg_list;i++){
    getName(simbolo.arg_list[i], name_param);
    getName(Args.ids[i], name_arg);
    sprintf(instrucao,"\tmove %s,%s\n",name_param,name_arg);
	  insert_cod(code,instrucao);
  }
}

/* Geração de código para chamada de função */
void Call(struct no* Call, int Id, struct ids Args) {
	???
  	adiciona_argumentos(&Call->code, Id, Args);
	???
}


/* Geração de código para chamada de função sem argumentos */
void Call_blank(?) {
	???
}

/* Geração de código para atribuições */
void Atrib(?) {
	???
}

/* Geração de código para carregar constantes */
void Li(?) {
	???
}

/* Geração de código para qualquer expressão aritmética referente parâmetros */
void ExpAri(?) {
	???
}

/* Geração de código para qualquer expressão relacional referente parâmetros */
void ExpRel(?) { 
	???
}

/* Geração de código para ifs sem else */
void If(?)  {  
	???
}


/* Geração de código para ifs com else */
void IfElse(?) {  
	???
}


/* Geração de código para whiles */
void While(?) {  
	???
}


/* Geração de código para do whiles */
void DoWhile(?) {  
	???
}