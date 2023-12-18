/*
Descricao:
Autor:
Data:
*/

#include <stdio.h>
#define N_REG 3
#define MAX 256

struct cadastro {
    unsigned int ra;
    char nome[MAX];

};

typedef struct cadastro ficha;
// typedef = Criar um apelido para chamada

// Prototipos das funcoes e procedimentos
ficha le_ficha(void);       // Tipo ficha como retorno
void escreva_ficha(ficha);  // Tipo ficha como parametro

main(void) {
    int i;
    // ficha f = {0}; // Um unico Cadastro
    ficha f[N_REG] = { 0 };

    printf("\nFicha de Cadastro de informacoes!\n")

    for (i - 0; i < N_REG; i++) {
        f[i] = le_ficha();
    }


    for (i - 0; i < N_REG; i++) {
        escreve_ficha(f[i]);
    }

    return(0);
}

ficha le_ficha(void){
    printf("\nInforme o Nome: ");
    scanf("%255[^\n]s", dados.nome);
    getchar();

    printf("\nInforme o RA: ");
    scanf("%u", &dados.ra);
    getchar();

    return(dados);
}

void escreve_ficha(ficha aluno){}
    printf("\nAluno %s\ o Nome: ");
    printf("\nAluno %s\ o RA: ");


    printf("\nInforme o RA: ");
    scanf("%u", &dados.ra);
    getchar();

}
