#include<stdio.h>
#include<stdlib.h>

#include "vetordinamico.h"

int main() {
    printf("\nCriando Vetor dinamico!");
    VetorDinamico *vetor = criaVetor(4);
    if (vetor == NULL) {
        return EXIT_FAILURE;
    }
    printf("\nVetor dinamico criado com sucesso!");
    for (int i = 1; i <= 10; i++) {
        adicionaElemento(vetor, i);
        printf("Adicionado: %d, Tamanho: %d, Capacidade: %d\n", i, vetor->tamanho, vetor->capacidade);
    }

    removeElemento(vetor, 3);
    removeElemento(vetor, 5);
    removeElemento(vetor, 7);
    printf("Após remoções, Tamanho: %d, Capacidade: %d\n", vetor->tamanho, vetor->capacidade);

    liberaVetor(vetor);

    return EXIT_SUCCESS;
}
