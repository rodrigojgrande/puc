
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "smartcity.h"


//Funcoes Smart City
// Funcao que retorna um ponteiro com endereco de memoria da cidade, com alocacao
// de memoria de acordo com a capacidade inicial inserida
smart_city* criaCidade(smart_city *cidade, int capacidade) {
    cidade = (smart_city*) malloc(sizeof(smart_city));
    cidade->vias = (via*) malloc(capacidade * sizeof(via));
    cidade->capacidade = capacidade;
    cidade->tamanho = 0;
    return cidade;
}

void redimensionaCapacidade(smart_city *cidade) {
    cidade->capacidade *= 2;
    cidade->vias = (via*) realloc(cidade->vias, cidade->capacidade * sizeof(via));
}

void adicionaVia(smart_city *cidade, via novaVia) {
    if (cidade->tamanho == cidade->capacidade) {
        redimensionaCapacidade(cidade);
    }
    cidade->vias[cidade->tamanho++] = novaVia;
}

void removeVia(smart_city *cidade, int codigo) {
    for (int i = 0; i < cidade->tamanho; i++) {
        if (cidade->vias[i].codigo == codigo) {
            for (int j = i; j < cidade->tamanho - 1; j++) {
                cidade->vias[j] = cidade->vias[j + 1];
            }
            cidade->tamanho--;
            break;
        }
    }
}

void exibeVias(smart_city cidade) {
    for (int i = 0; i < cidade.tamanho; i++) {
        printf("\nCodigo: %d, \n Nome: %s,\n Comprimento: %5.2f, \n Tipo de Piso: %d\n",
               cidade.vias[i].codigo, cidade.vias[i].nome, cidade.vias[i].comprimento, cidade.vias[i].tipo_piso);
    }
}

void liberaMemoria(smart_city *cidade) {
    free(cidade->vias);
    free(cidade);
}
