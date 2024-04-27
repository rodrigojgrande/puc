#include "vetordinamico.h"
#include <stdio.h>
#include <stdlib.h>

VetorDinamico *criaVetor(VetorDinamico *vetor, int capacidadeInicial)
{
    VetorDinamico *vetor  = malloc(sizeof(VetorDinamico)); 
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

void redimensionaVetor(VetorDinamico *vetor){}
void adicionaElemento(VetorDinamico *vetor, int elemento){}
void removeElemento(VetorDinamico *vetor, int indice){}
void liberaVetor(VetorDinamico *vetor){}