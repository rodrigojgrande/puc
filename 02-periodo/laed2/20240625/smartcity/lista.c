
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "smartcity.h"

//Funcoes Lista
void criaLista(ListaCDE *l) {
    l->inicio = l->fim = NULL;
    l->tamLista = 0;
}

int insereLista(ListaCDE *l, int numVia) {
    NodeCaminhos *novo = (NodeCaminhos*) malloc(sizeof(NodeCaminhos));
    if (novo == NULL) return 0;
    novo->numVia = numVia;
    novo->prox = novo->ant = NULL;
    if (l->inicio == NULL) {
        l->inicio = l->fim = novo;
    } else {
        l->fim->prox = novo;
        novo->ant = l->fim;
        l->fim = novo;
    }
    l->tamLista++;
    return 1;
}

int retiraLista(ListaCDE *l, int numVia) {
    NodeCaminhos *temp = l->inicio;
    while (temp != NULL && temp->numVia != numVia) {
        temp = temp->prox;
    }
    if (temp == NULL) return 0;
    if (temp->ant != NULL) {
        temp->ant->prox = temp->prox;
    } else {
        l->inicio = temp->prox;
    }
    if (temp->prox != NULL) {
        temp->prox->ant = temp->ant;
    } else {
        l->fim = temp->ant;
    }
    free(temp);
    l->tamLista--;
    return 1;
}

void mostraLista(ListaCDE l, int sentido) {
    if (sentido == 0) { // Sentido do inicio para o fim
        NodeCaminhos *temp = l.inicio;
        while (temp != NULL) {
            printf("%d ", temp->numVia);
            temp = temp->prox;
        }
    } else { // Sentido do fim para o inicio
        NodeCaminhos *temp = l.fim;
        while (temp != NULL) {
            printf("%d ", temp->numVia);
            temp = temp->ant;
        }
    }
    printf("\n");
}
