#include<stdio.h>
#include<string.h>

typedef struct
{
    char nome[50];
    int idade;
} Pessoa;

void imprimeVetor(int vetor[], int tamanho);

int main(){
    int vetor[] = {10, 20};
    int matriz[2][3] = {
        {1, 2, 3},
        {4, 5, 6}
    };
    imprimeVetor(vetor, 2);

    printf("&vetor = %d, &matriz = %d\n", &vetor, &matriz);
    printf("&vetor[0] = %d, &matriz[0] = %d\n", &vetor[0], &matriz[0]);
    printf("&matriz[0][0] = %d\n", &matriz[0][0]);
    printf("matriz[0][1] = %d\n", matriz[0][1]);
    printf("&matriz[0][1] = %d\n", &matriz[0][1]);

    imprimeVetor(matriz, 6);
}

void imprimeVetor(int vetor[], int tamanho){
    printf("Vetor: [");
    for(int i = 0; i < tamanho; i++){
        printf("%d ", vetor[i]);
    }
    printf("]\n");
}