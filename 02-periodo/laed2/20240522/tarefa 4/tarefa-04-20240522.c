#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no {
    char url[50];
    struct no *ant;
    struct no *prox;
} No;

typedef struct {
    No *inicio;
    No *fim;
    int tam;
} ListaCDE;

// Funções de manipulação
void cria(ListaCDE *l);
int insere(ListaCDE *l, char url[50]);
int insereOrdenado(ListaCDE *l, char url[50]);
int retira(ListaCDE *l, char url[50]);
int insereNaPosicao(ListaCDE *l, char url[50], int posicao);
char *vizinhoEsquerda(ListaCDE *l, char url[50]);
char *vizinhoDireita(ListaCDE *l, char url[50]);
void fechaTodasAbas(ListaCDE *l);

// Funções de visualização
int estaVazia(ListaCDE l);
char* getInicio(ListaCDE l);
char* getFim(ListaCDE l);
int getTamanho(ListaCDE l);
void mostra(ListaCDE l, int sentido);

int main() {
    ListaCDE l;
    char url[50];
    int sucesso, posicao;
    int opcao;

    cria(&l);

    // Inserindo ordenado
    insereOrdenado(&l, "https://www.google.com");
    insereOrdenado(&l, "https://www.youtube.com");
    insereOrdenado(&l, "https://www.canvas.com");
    insereOrdenado(&l, "https://www.instagram.com");

    if (!estaVazia(l)) { // Exibindo a lista
        printf("\n-------------------------------------------------\n");
        printf("Deseja ver as URLs a partir de onde?\n1 - inicio \n2 - fim\n");
        scanf("%d", &opcao);
        mostra(l, opcao);
    }

    // Inserindo nova aba em qualquer posição
    printf("\n-------------------------------------------------\n");
    printf("Deseja inserir uma nova aba? \n1 - sim \n2 - nao\n");
    scanf("%d", &opcao);

    while (opcao == 1) {
        printf("Digite a URL da nova aba: ");
        getchar(); // Limpa o buffer de entrada
        fgets(url, sizeof(url), stdin);
        url[strcspn(url, "\n")] = '\0'; // Remove a quebra de linha do final

        printf("Digite a posição onde deseja inserir a nova aba: ");
        scanf("%d", &posicao);

        sucesso = insereNaPosicao(&l, url, posicao);
        if (!sucesso) {
            printf("Falha ao inserir a nova aba na posição %d\n", posicao);
        }

        mostra(l, 1); // Exibe a lista atualizada

        printf("\nDeseja inserir mais uma aba? \n1 - sim \n2 - nao\n");
        scanf("%d", &opcao);
    }

    // Removendo aba
    opcao = 1;
    while (opcao == 1) { // Remover até o usuário não querer mais
        printf("\n-------------------------------------------------\n");
        printf("Qual URL deseja remover? ");
        getchar(); // Limpa o buffer de entrada
        fgets(url, sizeof(url), stdin);
        url[strcspn(url, "\n")] = '\0'; // Remove a quebra de linha do final

        sucesso = retira(&l, url); // Remove o elemento solicitado pelo usuário
        if (!sucesso) {
            printf("FALHA EM REMOVER: %s\n\n", url);
        }

        mostra(l, 1); // Exibe a lista atualizada

        printf("\nDeseja remover mais algum elemento? \n1 - sim \n2 - nao\n");
        scanf("%d", &opcao);
    }

    // Obtendo vizinho esquerdo e direito
    printf("\n-------------------------------------------------\n");
    printf("Digite a URL para encontrar seus vizinhos: ");
    getchar(); // Limpa o buffer de entrada
    fgets(url, sizeof(url), stdin);
    url[strcspn(url, "\n")] = '\0'; // Remove a quebra de linha do final

    char *vizinho_esq = vizinhoEsquerda(&l, url);
    char *vizinho_dir = vizinhoDireita(&l, url);

    if (vizinho_esq != NULL) {
        printf("Vizinho da esquerda: %s\n", vizinho_esq);
    } else {
        printf("Nao ha vizinho a esquerda para a URL %s\n", url);
    }

    if (vizinho_dir != NULL) {
        printf("Vizinho da direita: %s\n", vizinho_dir);
    } else {
        printf("Nao ha vizinho a direita para a URL %s\n", url);
    }

    // Fechando todas as abas
    printf("\n-------------------------------------------------\n");
    printf("Deseja fechar todas as abas? \n1 - sim \n2 - nao\n");
    scanf("%d", &opcao);

    if (opcao == 1) {
        fechaTodasAbas(&l);
        printf("Todas as abas foram fechadas.\n");
    }

    // Liberando memória
    while (!estaVazia(l)) {
        retira(&l, getInicio(l)); // Retirando sempre o primeiro elemento
    }
    return 0;
}

void cria(ListaCDE *l){
    l->inicio = NULL;
    l->fim = NULL;
    l->tam = 0;
}

int insere(ListaCDE *l, char url[50]){
    No *aux = (No *) malloc(sizeof(No));
    if (aux == NULL) {
        return 0;
    }

    strcpy(aux->url, url);
    l->tam++;

    if (l->inicio == NULL) {
        l->inicio = aux;
        l->fim = aux;
        aux->ant = l->fim;
        aux->prox = l->inicio;
        return 1;
    }

    aux->ant = l->fim;
    aux->prox = l->inicio;
    l->fim->prox = aux;
    l->fim = aux;
    l->inicio->ant = l->fim;
    return 1;
}

int insereOrdenado(ListaCDE *l, char url[50]){
    No *aux = (No *) malloc(sizeof(No));
    if (aux == NULL) {
        return 0;
    }

    strcpy(aux->url, url);
    l->tam++;

    if (l->inicio == NULL) {
        l->inicio = aux;
        l->fim = aux;
        aux->ant = l->fim;
        aux->prox = l->inicio;
        return 1;
    }

    if (strcmp(url, l->inicio->url) < 0) {
        aux->ant = l->fim;
        aux->prox = l->inicio;
        l->inicio->ant = aux;
        l->inicio = aux;
        l->fim->prox = l->inicio;
        return 1;
    }

    if (strcmp(url, l->fim->url) > 0) {
        aux->ant = l->fim;
        aux->prox = l->inicio;
        l->fim->prox = aux;
        l->fim = aux;
        l->inicio->ant = l->fim;
        return 1;
    }

    No *anterior = l->inicio;
    No *atual = anterior->prox;

    while (strcmp(url, atual->url) > 0) {
        anterior = atual;
        atual = atual->prox;
    }

    aux->ant = anterior;
    aux->prox = atual;
    anterior->prox = aux;
    atual->ant = aux;

    return 1;
}

int retira(ListaCDE *l, char url[50]){
    No *aux;

    if (l->inicio == NULL) {
        printf("Lista vazia\n");
        return 0;
    }

    if ((strcmp(url, l->inicio->url) == 0) && (l->inicio == l->fim)) {
        aux = l->inicio;
        l->inicio = NULL;
        l->fim = NULL;
        free(aux);
        l->tam--;
        return 1;
    }

    if (strcmp(url, l->inicio->url) == 0) {
        aux = l->inicio;
        l->inicio = aux->prox;
        l->inicio->ant = l->fim;
        l->fim->prox = l->inicio;
        free(aux);
        l->tam--;
        return 1;
    }

    if (strcmp(url, l->fim->url) == 0) {
        aux = l->fim;
        l->fim = aux->ant;
        l->fim->prox = l->inicio;
        l->inicio->ant = l->fim;
        free(aux);
        l->tam--;
        return 1;
    }

    aux = l->inicio->prox;

    while ((strcmp(url, aux->url) != 0) && (aux != l->fim))
        aux = aux->prox;

    if (aux == l->fim) {
        printf("O elemento %s nao esta na lista\n", url);
        return 0;
    }

    aux->ant->prox = aux->prox;
    aux->prox->ant = aux->ant;
    free(aux);
    l->tam--;
    return 1;
}

int estaVazia(ListaCDE l) {
    return l.inicio == NULL;
}

char *getInicio(ListaCDE l) {
    if (l.inicio == NULL) {
        return NULL;
    }
    return l.inicio->url;
}

char *getFim(ListaCDE l) {
    if (l.fim == NULL) {
        return NULL;
    }
    return l.fim->url;
}

int getTamanho(ListaCDE l) {
    return l.tam;
}

void mostra(ListaCDE l, int sentido) {
    if (estaVazia(l)) {
        printf("Lista vazia!\n");
        return;
    }

    No *aux = l.inicio;

    if (sentido == 1) {
        do {
            printf("%s\n", aux->url);
            aux = aux->prox;
        } while (aux != l.inicio);
    } else {
        aux = l.fim;
        do {
            printf("%s\n", aux->url);
            aux = aux->ant;
        } while (aux != l.fim);
    }
}

// Função para criar uma nova aba em qualquer posição
int insereNaPosicao(ListaCDE *l, char url[50], int posicao) {
    if (posicao < 1 || posicao > l->tam + 1) {
        return 0; // Posição inválida
    }

    No *aux = (No *)malloc(sizeof(No));
    if (aux == NULL) {
        return 0; // Falha na alocação de memória
    }

    strcpy(aux->url, url);

    if (posicao == 1) {
        if (l->inicio == NULL) {
            l->inicio = aux;
            l->fim = aux;
            aux->ant = l->fim;
            aux->prox = l->inicio;
        } else {
            aux->prox = l->inicio;
            aux->ant = l->fim;
            l->inicio->ant = aux;
            l->inicio = aux;
            l->fim->prox = l->inicio;
        }
    } else {
        No *atual = l->inicio;
        for (int i = 1; i < posicao - 1; i++) {
            atual = atual->prox;
        }
        aux->prox = atual->prox;
        aux->ant = atual;
        if (atual->prox != NULL) {
            atual->prox->ant = aux;
        }
        atual->prox = aux;
        if (atual == l->fim) {
            l->fim = aux;
        }
    }
    l->tam++;
    return 1;
}

// Funções para retornar os vizinhos
char *vizinhoEsquerda(ListaCDE *l, char url[50]) {
    if (l->inicio == NULL) {
        return NULL; // Lista vazia
    }

    No *aux = l->inicio;
    while (aux != NULL) {
        if (strcmp(aux->url, url) == 0) {
            return aux->ant->url;
        }
        aux = aux->prox;
        if (aux == l->inicio) {
            break;
        }
    }

    return NULL; // URL não encontrada
}

char *vizinhoDireita(ListaCDE *l, char url[50]) {
    if (l->inicio == NULL) {
        return NULL; // Lista vazia
    }

    No *aux = l->inicio;
    while (aux != NULL) {
        if (strcmp(aux->url, url) == 0) {
            return aux->prox->url;
        }
        aux = aux->prox;
        if (aux == l->inicio) {
            break;
        }
    }

    return NULL; // URL não encontrada
}

// Função para fechar todas as abas
void fechaTodasAbas(ListaCDE *l) {
    No *aux = l->inicio;
    while (aux != NULL) {
        No *temp = aux;
        aux = aux->prox;
        free(temp);
        if (aux == l->inicio) {
            break;
        }
    }
    l->inicio = NULL;
    l->fim = NULL;
    l->tam = 0;
}