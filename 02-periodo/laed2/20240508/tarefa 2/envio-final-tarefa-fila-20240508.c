#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definição da estrutura de uma requisição HTTP
typedef struct {
    char operacao[10];   // GET, POST ou PUT
    char url[100];  // URL ou caminho absoluto
    char protocolo[20]; // Versão do protocolo HTTP
} RequisicaoHTTP;

// Definição da estrutura de um nó da fila
typedef struct Node {
    RequisicaoHTTP requisicao;
    struct Node *proximo;
} Node;

// Definição da estrutura da fila
typedef struct {
    Node *inicio;
    Node *fim;
} Fila;


// Escopo de Funções
void inicializarFila(Fila *fila);
int filaVazia(Fila *fila);
void enfileirar(Fila *fila, RequisicaoHTTP requisicao);
RequisicaoHTTP desenfileirar(Fila *fila);
void imprimirRequisicao(RequisicaoHTTP requisicao);


int main() {
    // Inicializando a fila
    Fila fila; // Inicializa o Struct Fila
    inicializarFila(&fila); // Define o inicio e o fim da fila como NULL

    // Definindo os dados das requisições
    RequisicaoHTTP requisicao1 = {"GET", "https://www.exemplo.com", "HTTP/3.0"};
    RequisicaoHTTP requisicao2 = {"POST", "/login", "HTTP/1.1"};
    RequisicaoHTTP requisicao3 = {"PUT", "/atualizar", "HTTP/1.0"};

    // Adiciona as requisições a fila
    enfileirar(&fila, requisicao1); 
    enfileirar(&fila, requisicao2);
    enfileirar(&fila, requisicao3);

    // Remove e imprime as requisições da fila
    printf("Requisições na fila:\n");
    while (!filaVazia(&fila)) {
        RequisicaoHTTP requisicao = desenfileirar(&fila);
        printf("-----\n");
        imprimirRequisicao(requisicao);
    }
    return 0;
}


// Função para inicializar uma fila vazia
void inicializarFila(Fila *fila) {
    fila->inicio = NULL;
    fila->fim = NULL;
}

// Função para verificar se a fila está vazia
int filaVazia(Fila *fila) {
    return (fila->inicio == NULL);
}

// Função para enfileirar uma requisição na fila
void enfileirar(Fila *fila, RequisicaoHTTP requisicao) {
    Node *novoNode = (Node *)malloc(sizeof(Node));
    if (novoNode == NULL) {
        printf("Erro ao alocar a memoria --> enfileirar");
        // return 1;
        exit(EXIT_FAILURE);
    }
    novoNode->requisicao = requisicao;
    novoNode->proximo = NULL;
    if (fila->inicio == NULL) {
        fila->inicio = novoNode;
    } else {
        fila->fim->proximo = novoNode;
    }
    fila->fim = novoNode;
}

// Função para desenfileirar uma requisição da fila
RequisicaoHTTP desenfileirar(Fila *fila) {
    if (filaVazia(fila)) {
        printf("Erro ao desenfileirar --> fila vazia");
        // return 1;
        exit(EXIT_FAILURE);
    }
    Node *temp = fila->inicio;
    RequisicaoHTTP requisicao = temp->requisicao;
    fila->inicio = fila->inicio->proximo;
    if (fila->inicio == NULL) {
        fila->fim = NULL;
    }
    free(temp);
    return requisicao;
}

// Função para imprimir uma requisição HTTP
void imprimirRequisicao(RequisicaoHTTP requisicao) {
    printf("Ação: %s\n", requisicao.operacao);
    printf("Alvo: %s\n", requisicao.url);
    printf("Versão: %s\n", requisicao.protocolo);
}