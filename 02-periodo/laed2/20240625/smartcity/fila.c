
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "smartcity.h"

// Funcoes Fila
void criaFila(Fila *q) {
    q->inicio = q->fim = NULL;
    q->tamFila = 0;
}

int insereFila(Fila *q, char *pedido) {
    NodePedido *novo = (NodePedido*) malloc(sizeof(NodePedido));
    if (novo == NULL) return 0;
    strncpy(novo->pedido, pedido, sizeof(novo->pedido) - 1);
    novo->pedido[sizeof(novo->pedido) - 1] = '\0';
    novo->prox = NULL;
    if (q->fim == NULL) {
        q->inicio = q->fim = novo;
    } else {
        q->fim->prox = novo;
        q->fim = novo;
    }
    q->tamFila++;
    return 1;
}

int retiraFila(Fila *q, char *pedido) {
    if (q->inicio == NULL) return 0;
    NodePedido *temp = q->inicio;
    strncpy(pedido, temp->pedido, 100);
    q->inicio = q->inicio->prox;
    if (q->inicio == NULL) q->fim = NULL;
    free(temp);
    q->tamFila--;
    return 1;
}

void mostraFila(Fila q) {
    NodePedido *temp = q.inicio;
    while (temp != NULL) {
        printf("%s \n", temp->pedido);
        temp = temp->prox;
    }
    printf("\n");
}
