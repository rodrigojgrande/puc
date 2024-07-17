#include<stdio.h>
#include<stdlib.h>

typedef struct noAdjacente {
    int vertice;
    struct noAdjacente *prox;
}NoAdjacente;

typedef struct {
    int tam;
    NoAdjacente *inicio;
    NoAdjacente *fim;
} ListaNoAdjacente;


typedef struct no {
    int vertice;
    ListaNoAdjacente nosAdjacentes;
    struct no *prox;
}No;

typedef struct {
    int tam;
    No *inicio;
    No *fim;
} Grafo;

void criaGrafo(Grafo *g);
void criaListaNoAdjacente(ListaNoAdjacente *l);

int insereVertice(Grafo *g, int vertice);
int existeVertice(Grafo *g, int vertice);
int insereNoListaAdjacente(ListaNoAdjacente *l, int vertice);
int insereAresta(Grafo *g, int vertice, int vAdjacente);

void mostra(Grafo g);
int ehAdjacente(Grafo g, int vertice, int vAdj);


int main(){

    Grafo g;
    criaGrafo(&g);
    mostra(g);

    printf("\n------ Inserindo nos ------\n\n");

    printf("Inserindo 10\n");
    insereVertice(&g, 10);
    printf("Inserindo 5\n");
    insereVertice(&g, 5);
    printf("Inserindo 7\n");
    insereVertice(&g, 7);
    printf("Inserindo 19\n");
    insereVertice(&g, 19);
    printf("Inserindo 22\n");
    insereVertice(&g, 22);


    printf("\n------ Exibindo grafo sem arestas -------\n\n");
    mostra(g);

    printf("\n------ Inserindo arestas -------\n\n");

    printf("Inserindo aresta saindo de 10 e indo para 5\n");
    insereAresta(&g, 10, 5);
    printf("Inserindo aresta saindo de 5 e indo para 10\n");
    insereAresta(&g, 5, 10);
    printf("Inserindo aresta saindo de 10 e indo para 7\n");
    insereAresta(&g, 10, 7);
    printf("Inserindo aresta saindo de 7 e indo para 19\n");
    insereAresta(&g, 7, 19);
    printf("Inserindo aresta saindo de 19 e indo para 22\n");
    insereAresta(&g, 19, 22);
    printf("Inserindo aresta saindo de 22 e indo para 10\n");
    insereAresta(&g, 22, 10);
    printf("Inserindo aresta saindo de 22 e indo para 7\n");
    insereAresta(&g, 22, 7);
    printf("Inserindo aresta saindo de 30 e indo para 7\n");
    insereAresta(&g, 30, 7);
    printf("Inserindo aresta saindo de 5 e indo para 200\n");
    insereAresta(&g, 5, 200);

    printf("\n------ Exibindo grafo com arestas -------\n\n");
    mostra(g);

    if(ehAdjacente(g, 10, 7))
        printf("\n10 e 7 possuem uma aresta saindo de 10 e chegando em 7\n");

    if(!ehAdjacente(g, 7, 10))
        printf("\n10 e 7 nao possuem uma aresta saindo de 7 e chegando em 10\n");



    return 0;
}

void criaGrafo(Grafo *g){

    g->inicio = NULL;
    g->fim = NULL;
    g->tam = 0;
}

void criaListaNoAdjacente(ListaNoAdjacente *l){

    l->inicio = NULL;
    l->fim = NULL;
    l->tam = 0;
}

int insereVertice(Grafo *g, int vertice){

    //criando o no
    No *aux = (No *) malloc(sizeof(No));
    if(aux == NULL){
        return 0;
    }

    aux->vertice = vertice; // atribuo o vertice
    criaListaNoAdjacente(&(aux->nosAdjacentes)); //inicializo a lista de nos adjacentes
    aux->prox = NULL; // insercao eh no fim, ultimo no aponta para null

    //manipulando o grafo
    g->tam++;

    /* 1o caso: Primeiro vertice do grafo */
    if(g->inicio == NULL){
        g->inicio = aux;
        g->fim = aux;
        return 1;
    }

    /* 2o caso: insercao ao final */
    g->fim->prox = aux;
    g->fim = aux;
    return 1;

}

int existeVertice(Grafo *g, int vertice){

    No *aux = g->inicio;

    // percorrendo o grafo desde o inicio
    while(aux != NULL){
        if(aux->vertice == vertice) // achou o vertice
            return 1;
        aux = aux->prox;
    }

    // se o grafo todo foi percorrido, entao o vertice nao existe
    return 0;
}


int insereNoListaAdjacente(ListaNoAdjacente *l, int vertice){

     //aloco um no adjacente (que representa a minha aresta)
    NoAdjacente *noAdj = (NoAdjacente *) malloc(sizeof(NoAdjacente));
    if(noAdj == NULL){
        printf("ERRO: memoria insuficiente \n");
        return 0;
    }

    noAdj->vertice = vertice;
    noAdj->prox = NULL;

    l->tam++;
    if(l->inicio == NULL){
        l->inicio = noAdj;
        l->fim = noAdj;
        return 1;
    }

    l->fim->prox = noAdj;
    l->fim = noAdj;
    return 1;

}

int insereAresta(Grafo *g, int vertice, int vAdjacente){

    // inicializo um no auxiliar no come�o do grafo
    No *aux = g->inicio;
    if(aux == NULL){
        printf("ERRO: Grafo vazio \n");
        return 0;
    }

    //procuro o vertice no grafo
    while((aux != NULL) && (aux->vertice != vertice))
        aux = aux->prox;

    //se o vertice nao for encontrado
    if(aux == NULL){
        printf("ERRO: vertice de origem nao encontrado \n");
        return 0;
    }

    // checando se o vertice adjacente existe, senao nao posso inserir a aresta
    if(!existeVertice(g, vAdjacente)){
        printf("ERRO: vertice adjacente nao existe \n");
        return 0;
    }

    // cheguei ate esse ponto, hora de inserir a aresta
    return insereNoListaAdjacente(&(aux->nosAdjacentes), vAdjacente); //1 sucesso, 0 falha

}

void mostra(Grafo g){

    NoAdjacente *noAdj;
    No *aux = g.inicio;

    if(aux == NULL)
        printf("Grafo vazio... \n");

    else {

        while(aux != NULL){

            printf("Vertice = %d\n", aux->vertice);
            noAdj = aux->nosAdjacentes.inicio;
            if(noAdj != NULL){

                printf("Possui arestas com = ");
                while(noAdj != NULL){
                    printf("%d, ", noAdj->vertice);
                    noAdj = noAdj->prox;
                }
            }
            else {
                printf("Nao possui arestas...");
            }

            printf("\n\n");
            aux = aux->prox;
        }
    }
}


int ehAdjacente(Grafo g, int vertice, int vAdj) {

    NoAdjacente *noAdj;
    No *aux = g.inicio;

    if(aux == NULL)
        return 0;

    while(aux != NULL){

        if(aux->vertice == vertice){
            noAdj = aux->nosAdjacentes.inicio;
            while(noAdj != NULL){
                if(noAdj->vertice == vAdj)
                    return 1;
                noAdj = noAdj->prox;
            }

            //achei o vertice origem, mas nao o destino
            return 0;
        }
        aux = aux->prox;
    }

    //nao achei o vertice origem
    return 0;
}
