/*
Faça um programa que leia um vetor de 30 posições com as notas de 30
alunos (valores inteiros entre 0 e 10) e desenhe um histograma horizontal
com o número de ocorrências de cada nota. Ex.: Para o vetor (1- 0- 2- 10-
9- 8- 6- 5- 4- 1- 2- 3- 4- 5- 6- 4- 7- 7- 8- 9- 7- 9) o histograma seria:
0 *
1 * *
2 * *
3 *
4 * * *
5 * *
6 * *
7 * * *
8 * *
9 * * *
10
*/
#include <stdio.h>

#define TAM_TURMA 15
#define MAIOR_NOTA 10

void conta_frequencia_nota(int *notas, int n, int *frequencias);
void plota_frequencia_nota(int *frequencias, int n);

int main(void)
{
    int notas_semestre[TAM_TURMA] = {1, 1, 2, 3, 2, 5, 8, 8, 7, 6, 6, 4, 3, 10, 1};
    int frequencias_notas[MAIOR_NOTA + 1] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    conta_frequencia_nota(notas_semestre, TAM_TURMA, frequencias_notas);
    plota_frequencia_nota(frequencias_notas, MAIOR_NOTA + 1);

    return 0;
}

void conta_frequencia_nota(int *notas, int n, int *frequencias)
{
    for (int i = 0; i < n; i++)
        frequencias[notas[i]] += 1;
    return;
}

void plota_frequencia_nota(int *frequencias, int n)
{
    printf("Gráfico de Frequencias de Notas\n");
    printf("------------------------------\n");
    printf("Nota Frequencia\n");
    for (int i = 0; i < n; i++)
    {
        printf("%4d ", i);

        /* imprime asteriscos conforme a frequência da nota. */
        for (int j = 0; j < frequencias[i]; j++)
            printf(" %c", 178);

        printf("\n");
    }

    return;
}
