#ifndef VETOR_DINAMICO_H
#define VETOR_DINAMICO_H
typedef struct
{
    int *itens;
    int capacidade;
    int tamanho;
} VetorDinamico;

VetorDinamico *criaVetor(VetorDinamico *vetor, 
    int capacidadeInicial);
void redimensionaVetor(VetorDinamico *vetor);
void adicionaElemento(VetorDinamico *vetor, int elemento);
void removeElemento(VetorDinamico *vetor, int indice);
void liberaVetor(VetorDinamico *vetor);
#endif