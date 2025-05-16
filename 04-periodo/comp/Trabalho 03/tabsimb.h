#include <string.h>
#define MAX 1000
struct symbol {
	char lexema[50];
	int tam;
	int tipo;
};
int tam_tab=0;
struct symbol Tabela[MAX];

int procura(char *lexema) {
int i;	
	for(i=0; i<tam_tab; i++) 
	  if(strcmp(Tabela[i].lexema,lexema)==0)
	     return i; 
	return -1;     
}
int insere(char *lexema) {
	int i,pos;
	struct symbol aux;	
	pos = procura(lexema);
	if (pos != -1)
		return pos;
	strcpy(aux.lexema,lexema);
	Tabela[tam_tab]=aux; 
	return tam_tab++;	     
}
char lexema[50];
char *obtemLexema(int pos) {
	strcpy(lexema,Tabela[pos].lexema);
	return lexema;
}
void imprime() {
int i;
	printf("\nTABELA DE SIMBOLO\n");
	for(i=0; i<tam_tab; i++)
	   printf("%d - %s\n",i,Tabela[i].lexema);
}
