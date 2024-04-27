                                                                                                                                                                                                                                                    #include "vetordinamico.h"
#include <stdio.h>
#include <stdlib.h>

VetorDinamico *criaVetor(int capacidadeInicial)
{
    VetorDinamico *vetor = malloc(sizeof(VetorDinamico));
    if (vetor == NULL) {
        fprintf(stderr, "Falha na alocação de memória para o VetorDinamico\n");
        /*fprintf para mensagens em arquivos*/
    } return NULL;

    vetor->itens = malloc(sizeof(int) * capacidadeInicial);
    if (vetor->itens == NULL) {
        fprintf(stderr, "Falha na alocação de memória para o VetorDinamico\n");
        free(vetor);
    } return NULL;

    vetor->capacidade = capacidadeInicial;
    vetor->tamanho = 0;

    return vetor;
}

void redimensionaVetor(VetorDinamico *vetor){
    int novaCapacidade = vetor->capacidade * 2;
    int *itensRedimensionados;

    itensRedimensionados = realloc(vetor->itens, sizeof(int) * novaCapacidade);
    if (itensRedimensionados == NULL) {
        fprintf(stderr, "Falha no redimensionamento do vetor\n");
        exit(EXIT_FAILURE);
        //return NULL;
    }

    vetor->itens = itensRedimensionados;
    vetor->capacidade = novaCapacidade;
}

void adicionaElemento(VetorDinamico *vetor, int elemento){
    if(vetor->capacidade == vetor->tamanho){
        redimensionaVetor(vetor);
    } else {
        vetor->itens[vetor->tamanho] = elemento;
        vetor->tamanho++;
    }
}

void removeElemento(VetorDinamico *vetor, int indice){
    if((indice < 0) || (indice >= vetor->tamanho)) {
        fprintf(stderr, "Falha na remoção do índice %d do vetor\n", indice);
        return;
    }

    for(int i = indice; i < vetor->tamanho-1; i++){
        vetor->itens[i] = vetor->itens[i+1];
    }
    vetor->tamanho--;
}
void liberaVetor(VetorDinamico *vetor){
    free(vetor->itens);
    free(vetor);
}
