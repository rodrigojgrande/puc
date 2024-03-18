/*
Laboratorio de AED II
2024 02 21

- Passagem de Parâmetros por referência
- Ponteiros
- Alocação Dinâmica
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct ps{
    char nome[30];
    float salario;
} Pessoa;

int main(){
    Pessoa elon, *mosca, *turma;
    elon.salario = 700000.0;
    strcpy(elon.nome, "Elon");
    printf("%s (%f)\n", elon.nome, elon.salario);

    mosca = (Pessoa *) malloc(1 * sizeof(Pessoa));
    mosca->salario = 5000.0;
    strcpy(mosca->nome, "Mosca");
    printf("%s (%f)\n", mosca-> nome,mosca->salario);

    int n = 5;
    int *pInt = (int *) malloc(5 * sizeof(int));
    printf("%p\n", pInt); //%p = ponteiro
    printf("%d\n", *pInt);
    printf("%d\n", pInt[0]);

    for(int i=0; i<n; i++){
        pInt[i] = i + 1;
    }

    printf("\n");

    printf("Apos modificacoes:\n");
    printf("%p\n", pInt);
    printf("%d\n", *pInt);
    printf("%d\n", pInt[0]);

    for(int i=0; i<n; i++){
        printf("pInt[%d] = %d\n", i, pInt[i]);
    }

    printf("\n");

    printf("pInt++\n");
    printf("%p\n", pInt);
    for(int i=0; i<n; i++){
        printf("pInt = %p\n", pInt);
        printf("*pInt = %d\n", *pInt);
        pInt++;
    }

    turma = (Pessoa *) malloc(n * sizeof(Pessoa));
    printf("sizeof(Pessoa) = %d\n", sizeof(Pessoa));
    printf("sizeof(float) = %d\n", sizeof(float));

    printf("\n");

    turma[0].salario = 100.0;
    strcpy(turma[0].nome, "Pessoa 1");
    turma[1].salario = 200.0;
    strcpy(turma[1].nome, "Pessoa 2");

    for(int i=0; i<2; i++){
        printf("%s (%f)\n", turma[i].nome, turma[i].salario);
    }

    printf("\n");

    for(int i=0; i<2; i++){
        printf("%p\n", turma);
        printf("%s (%f)\n", turma[0].nome, turma[0].salario);
        turma++;
    }

    return 0;
}
