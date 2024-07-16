
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "smartcity.h"

// Funcao que retorna um ponteiro com endereco de memoria da cidade, com alocacao
// de memoria de acordo com a capacidade inicial inserida
smart_city *criaCidade(smart_city *cidade, int capacidade) {
    cidade = malloc(sizeof(smart_city));
    if (cidade == NULL) {
        fprintf(stderr, "\nSinto muito, a alocacao de memoria falhou");
        return NULL;
    }
    cidade->vias = malloc(sizeof(via) * capacidade);
    if (cidade->vias == NULL) {
        fprintf(stderr, "Falha na alocacao de memoria para as vias\n");
        free(cidade);
        return NULL;
    }

    cidade->capacidade = capacidade;
    cidade->tamanho = 0;

    return cidade;
}

// Funcao para realocar a memoria e aumentar a capacidade de vias
void redimensionaCapacidade(smart_city *cidade) {
    int novaCapacidade = cidade->capacidade * 2;
    via *viasRedimensionadas;

    viasRedimensionadas = realloc(cidade->vias, sizeof(via) * novaCapacidade);
    if (viasRedimensionadas == NULL) {
        fprintf(stderr, "Falha do redimensionamento do vetor\n");
        exit(EXIT_FAILURE);
    }

    cidade->vias = viasRedimensionadas;
    cidade->capacidade = novaCapacidade;
}

// Funcao para adicionar uma via a estrutura da cidade, redimensionando
// a capacidade quando necessario
void adicionaVia(smart_city *cidade, via novaVia) {
    if (cidade->capacidade == cidade->tamanho) {
        redimensionaCapacidade(cidade);
    }
    cidade->vias[cidade->tamanho] = novaVia;
    cidade->tamanho++;
}

// Funcao para remover uma via da estrutura da cidade, liberando memoria
void removeVia(smart_city *cidade, int codigo) {
    int i, j;
    for (i = 0; i < cidade->tamanho; i++) {
        if (cidade->vias[i].codigo == codigo) {
            for (j = i; j < cidade->tamanho - 1; j++) {
                cidade->vias[j] = cidade->vias[j + 1];
            }
            cidade->tamanho--;
            return;
        }
    }
    printf("Via com código %d não encontrada.\n", codigo);
}

// Funcao para exibir as vias da cidade
void exibeVias(smart_city cidade) {
    for (int i = 0; i < cidade.tamanho; i++) {
        printf("\nVia %d\n", i + 1);
        printf("Codigo: %d\n", cidade.vias[i].codigo);
        printf("Nome: %s\n", cidade.vias[i].nome);
        printf("Comprimento: %.2f\n", cidade.vias[i].comprimento);
        printf("Tipo do Piso: %d\n", cidade.vias[i].tipo_piso);
    }
}

// Funcao para liberar a memoria utilizada pelas vias e pela cidade
// como nesse caso so ha possibilidade de se inserir uma via, apenas
// essas duas linhas foram necessarias;
void liberaMemoria(smart_city *cidade) {
    free(cidade->vias);
    free(cidade);
}
