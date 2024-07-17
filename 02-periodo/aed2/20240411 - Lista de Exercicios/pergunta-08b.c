/*
Pergunta 08 - b
Implemente uma fila (queue) usando uma lista encadeada
e implemente as operações de enqueue(inserir) e dequeue (remover).
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int dado;
    struct No *prox;
} Node;

typedef struct {
    Node *primeiro; 
    Node *ultimo; 
    int tamanho;
} Fila;

void cria(Fila *q);
int enfileira(Fila *q, int val);
int desenfileira(Fila *q, int *val);


int main() {
    Fila q;
    int val;
    cria(&q);
    enfileira(&q, 5);
    enfileira(&q, 7);
    desenfileira(&q, &val);
    printf("%d\n", val);
    enfileira(&q, 1);
    return 0;
}

void cria (Fila *q){
    q->primeiro = NULL;
    q->ultimo = NULL;
    q->tamanho = 0;
}

int enfileira(Fila *q, int val){
    Node *aux = (Node *) malloc(sizeof(Node));
    if (aux == NULL) {
        return 0;
    }
    aux->prox = NULL;
    q->ultimo->prox=aux;
    q->ultimo=aux;

    if(q->primeiro == NULL) {
        q->primeiro = aux;
    }
    q->tamanho++;
    return 1;
}

int desenfileira(Fila *q, int *val) {
    if (q->primeiro == NULL) {
        return 0;
    }
    Node *aux = q->primeiro;
    *val = aux->dado;
    q->tamanho--;
    q->primeiro = aux->prox;
    free(aux);
    return 1;
}