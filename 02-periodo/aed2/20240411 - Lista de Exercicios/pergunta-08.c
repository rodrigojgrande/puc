/*
Pergunta 08 - a
Implemente uma pilha (stack) usando arrays e
implemente as operações de push (inserir) e pop(remover).
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int dado;
    struct No *prox;
} No;

typedef struct {
    No *topo; 
    int tamanho;
} Pilha;

void cria(Pilha *s);
int empilha(int val, Pilha *s);
int desempilha(Pilha *s, int *val);


int main() {
    Pilha s;
    cria(&s);
    printf("Pilha Criada\n");
    int val;

    do {
        printf("Digite o Numero p/ empilhar (-1 sair)\n");
        scanf("%d", &val);
        if(empilha(&s, val) == 0) {
            printf("F\n");
            exit(0);
        }
    } while (val != -1);

    while (s.tamanho > 0) {
        int topo;
        if(desempilha(&s, &topo) == 0) {
            printf("ta foda\n");
            exit(0);
        }
        printf("%d\n", topo);
    }
    return 0;
}

void cria (Pilha *s){
    s->topo = NULL;
    s->tamanho = 0;
}

int empilha(int val, Pilha *s) {
    No *aux = (No *) malloc(sizeof(No));
    if (aux == NULL) {
        return 0;
    }
    aux->prox = s->topo;
    aux->dado = val;
    s->topo = aux;
    s->tamanho++;
    return 1;
}

int desempilha(Pilha *s, int * val) {
    if (s->topo == NULL) {
        return 0;
    }
    No *aux = s->topo;
    *val = aux->dado;
    s->topo = aux->prox;
    s->tamanho--;
    free(aux);
    return 1;
}