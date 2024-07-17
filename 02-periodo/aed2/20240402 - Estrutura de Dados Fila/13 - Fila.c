#include<stdio.h>
#include<stdlib.h>
#include<time.h>


typedef struct no {

    int dado;
    struct no *prox;
} No;

// Fila contem ponteiros para o primeiro e o ultimo elemento (No)
typedef struct {

    No *inicio;
    No *fim;
    int tamFila;
} Fila;

// funcoes de manipulacao
void cria(Fila *q);
int insere(Fila *q, int dado);
int retira(Fila *q, int *dado);

// funcoes de checagem / visualizacao
int estaVazia(Fila q);
int getInicio(Fila q);
int getFim(Fila q);
int getTamanho(Fila q);
void mostra(Fila q);

int main(){

    Fila q;
    int dado, sucesso;
    srand(time(NULL));

    cria(&q);
    if(estaVazia(q))
        printf("Fila esta vazia!\n\n");
    else
        printf("Fila nao esta vazia!\n\n");

    //Enfileirando o primeiro elemento
    dado = rand() % 1000;
    printf("Enfileirando %d...\n\n", dado);
    insere(&q, dado);

    if(estaVazia(q))
        printf("Fila esta vazia!\n\n");
    else{
        printf("Fila nao esta vazia! Tem tamanho: %d\n", getTamanho(q));
        printf("Primeiro elemento: %d \nUltimo elemento: %d\n\n", getInicio(q), getFim(q));
    }

    // Enfileirando
    printf("Gerando e enfileirando dados:\n");
    for(int i=0; i < 3; i++){
        dado = rand() % 1000;
        printf("Enfileirando %d...\n", dado);
        sucesso = insere(&q, dado);
        if(!sucesso){
            printf("Problemas ao enfileirar o dado %d", dado);
        }
    }

    // Visualizando
    if(!estaVazia(q)){
        printf("\nTamanho da Fila: %d\nDado no inicio: %d\nDado no fim: %d\n\n", getTamanho(q), getInicio(q), getFim(q));
        printf("Exibindo todos os dados da Fila...\n\n");
        mostra(q);
    }
    else
        printf("Fila esta vazia!\n\n");

    // Desenfileirando
    printf("\nDesenfileirando dados:\n\n");
    while(!estaVazia(q)){
        sucesso = retira(&q, &dado);
        if(sucesso)
            printf("Dado desenfileirado: %d\n", dado);
        else
            printf("Fila vazia...\n");
    }

}

/*
    A funcao 'cria' inicializa a Fila apontando o inicio e o fim para NULL.
*/
void cria(Fila *q){

    q->inicio = NULL;
    q->fim = NULL;
    q->tamFila = 0;
}

/*
    A funcao 'insere' insere um No sempre ao final da fila.
    - Se Fila eh vazia, inicio e fim apontam pra esse no.
    - Se Fila nao eh vazia, insere ao final, fazendo:
        - o ponteiro de proximo do fim atual apontar para o novo no
        - o ponteiro de fim passa a apontar para o novo no
*/
int insere(Fila *q, int dado){

    No *aux;
    aux = (No *) malloc(sizeof(No)); //aloca na heap
    if(aux == NULL) //checa se deu certo
        return 0;

    //inicializa o no
    aux->dado = dado;
    aux->prox = NULL;

    q->tamFila++; //incrementa o tamanho da fila

    //se for o primeiro elemento, tanto inicio quanto fim apontam pra ele
    if(q->inicio == NULL){
        q->inicio = aux;
        q->fim = aux;
        return 1;
    }

    //se nao, prox do antigo fim aponta pro novo no e fim passa a apontar pro novo no
    q->fim->prox = aux;
    q->fim = aux;
    return 1;
}

/*
    A funcao 'retira' remove sempre o dado do comeco da Fila.
    - O inicio passa a apontar para o proximo do inicio.
    - se a fila nao tem mais elementos, tanto inicio quanto fim irao apontar para NULL.
*/
int retira(Fila *q, int *dado){

    No *aux;
    aux = q->inicio;
    if(aux == NULL) // checa se fila esta vazia
        return 0;

    *dado = aux->dado; //recupera o dado
    q->tamFila--; //diminui o tamanho da fila
    q->inicio = aux->prox; //inicio aponta para o segundo elemento

    //se fila esta vazia agora, fim deve apontar para null tambem
    if(q->inicio == NULL) //
        q->fim = NULL;
    free(aux); //libera a memoria

    return 1;
}

/*
    Verifica se esta vazio (1) ou nao (0)
*/
int estaVazia(Fila q){

    if(q.inicio == NULL)
        return 1;

    return 0;
}

/*
    Retorna o dado do No apontado por inicio.
*/
int getInicio(Fila q){

    return q.inicio->dado;
}


/*
    Retorna o dado do No apontado por fim.
*/
int getFim(Fila q){

    return q.fim->dado;
}


/*
    Retorna o tamanho da Fila.
*/
int getTamanho(Fila q){

    return q.tamFila;
}

/*
    Imprime os elementos da Fila, se ela nao estiver vazia.
    Imprime do inicio para o fim.
*/
void mostra(Fila q){

    No *aux;
    aux = q.inicio;
    if (aux == NULL){
        printf("Fila vazia!\n");
    }

    while(aux != NULL){
        printf("Dado enfileirado: %d\n", aux->dado);
        aux = aux->prox;
    }
}

