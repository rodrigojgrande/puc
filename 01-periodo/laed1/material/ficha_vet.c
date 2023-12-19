/* Nome: Claudio Correa
   Exemplo com struct
   Compilar: clang -Wall estrutura.c -o estrutura
 */

#include <stdio.h>

#define N_REG 3
#define MAX 256

struct cadastro {
	unsigned int ra;
	char nome[MAX];
};

// Definicao de um novo tipo
typedef struct cadastro ficha;

// Prototipos das funcoes e procedimentos
ficha le_ficha(void);
void escreve_ficha(ficha);

int main(void) {
	int i;
	// ficha f = {0}; // Um unico cadasdro
    ficha f[N_REG] = {0};

	printf("\nFicha de cadastro de informacoes!\n");

	for (i = 0; i < N_REG; i++) {
	    f[i] = le_ficha();
	}

	for (i = 0; i < N_REG; i++) {
	     escreve_ficha(f[i]);
	}
	return(0);
}

ficha le_ficha(void) {
	ficha dados;

	printf("\nInforme a nome: ");
	scanf("%255[^\n]s", dados.nome);
	getchar();

	printf("Informe o RA: ");
	scanf("%u", &dados.ra);
	getchar();

	return(dados);
}

void escreve_ficha(ficha aluno) {
	printf("\nAluno: %s\tRA: %u\n\n", aluno.nome, aluno.ra);
	return;
}
