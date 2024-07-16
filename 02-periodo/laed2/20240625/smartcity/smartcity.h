#ifndef SMART_CITY_H
#define SMART_CITY_H

typedef struct {
    int codigo;
    char nome[30];
    float comprimento;
    int tipo_piso;
} via;

typedef struct {
    via *vias;
    int capacidade;
    int tamanho;
} smart_city;

typedef struct noPedido {
    struct noPedido *prox;
    char pedido[100];
} NodePedido;

typedef struct {
    NodePedido *inicio;
    NodePedido *fim;
    int tamFila;
} Fila;

typedef struct noCaminhos {
    struct noCaminhos *ant;
    struct noCaminhos *prox;
    int numVia;
} NodeCaminhos;

typedef struct {
    NodeCaminhos *inicio;
    NodeCaminhos *fim;
    int tamLista;
} ListaCDE;

// Funcoes smartcity
smart_city* criaCidade(smart_city *cidade, int capacidade);
void redimensionaCapacidade(smart_city *cidade);
void adicionaVia(smart_city *cidade, via novaVia);
void removeVia(smart_city *cidade, int codigo);
void exibeVias(smart_city cidade);
void liberaMemoria(smart_city *cidade);

// funcoes fila
void criaFila(Fila *q);
int insereFila(Fila *q, char *pedido);
int retiraFila(Fila *q, char *pedido); 
void mostraFila(Fila q);

// funcoes lista
void criaLista(ListaCDE *l);
int insereLista(ListaCDE *l, int numVia);
int retiraLista(ListaCDE *l, int numVia);
void mostraLista(ListaCDE l, int sentido);

#endif
