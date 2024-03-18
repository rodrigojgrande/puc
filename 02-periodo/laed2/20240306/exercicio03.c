/*
3. Faça um programa que leia um vetor de 10 posições com as notas de 10 alunos,
com valores inteiros de 0 a 10 e desenhe um histograma horizontal com o número de ocorrências de cada nota.

Por exemplo: [1,2,1,8,5,5,7,0,1,2]

0*
1***
2**
4
5**
6
*/

// 1. Contar a Frequência de cada nota
// 2. Plotar o Grfico de barraz horizontais da frequência de cada nota

#include<stdio.h>

#define TAM_TURMA 15
#define MAIOR_NOTA 10

void conta_frequencia_nota(int *notas, int n, int *frequencias);
void plota_frequencia_nota(int *frequencias, int n);

int main(void){
    int notas_semestre[TAM_TURMA] = {1, 1, 2, 3, 2, 5, 8, 8, 7, 6, 6, 4, 3, 10, 1};
    int frequencias_notas[MAIOR_NOTA+1] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    conta_frequencia_nota(notas_semestre, TAM_TURMA, frequencias_notas);
    
    /*
    for(int i; i < MAIOR_NOTA+1; i++){
        printf("nota: %d - Frequencia: %d\n", i, frequencias_notas[i]);
    }
    */

    plota_frequencia_nota(frequencias_notas, MAIOR_NOTA+1);

    return 0;
}

void conta_frequencia_nota(int *notas, int n, int *frequencias){
    for(int i = 0; i < n; i++){
        frequencias[notas[i]] += 1;
    }
    
    return;
}

void plota_frequencia_nota(int *frequencias, int n){
    printf("Grafico de Frequencia de Notas\n");
    printf("------------------------------\n");
    printf("Fotas Frequencia\n");

    for (int i = 0; i< n; i++) {
        
        printf("%4d", i); // Alinhar a direita em 4 espaços
        
        /* Imprime asteriscos conforme a frequência da nota*/
        for (int j = 0; j < frequencias[i]; j++){
            // printf("*");
            printf("%c", 178); // Utilizando a tabela ASCII
        }
            printf("\n");
    }
    
    return;
}