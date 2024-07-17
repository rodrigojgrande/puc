#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
    int dado;
    struct no *esq;
    struct no *dir;
} Node;

// funcoes de manipulacao
void cria(Node **t);
int insere(Node **t, int dado);
Node *encontraMaxDireita(Node **t);
int retira(Node **t, int dado);

// funcoes de visualizacao
void preOrdem(Node *t);
void emOrdem(Node *t);
void emDesordem(Node *t);
void posOrdem(Node *t);

int main()
{

    Node *arvore;
    int sucesso;

    cria(&arvore);

    sucesso = insere(&arvore, 12);
    sucesso = insere(&arvore, 5);
    sucesso = insere(&arvore, 4);
    sucesso = insere(&arvore, 3);
    sucesso = insere(&arvore, 9);
    sucesso = insere(&arvore, 1);
    sucesso = insere(&arvore, 6);
    sucesso = insere(&arvore, 11);
    sucesso = insere(&arvore, 8);
    sucesso = insere(&arvore, 7);
    sucesso = insere(&arvore, 15);
    sucesso = insere(&arvore, 20);

    printf("PRE ORDEM: ");
    preOrdem(arvore);

    /*
    printf("\n\nEM ORDEM: ");
    emOrdem(arvore);

    printf("\n\nPRE ORDEM: ");
    posOrdem(arvore);
    */

    printf("\n\nREMOVENDO NO 1 - caso 1, sem filhos:\n");
    sucesso = retira(&arvore, 1);
    printf("PRE ORDEM: ");
    preOrdem(arvore);

    printf("\n\nREMOVENDO NO 4: caso 2, filho a esquerda:\n");
    sucesso = retira(&arvore, 4);
    printf("PRE ORDEM: ");
    preOrdem(arvore);

    printf("\n\nREMOVENDO NO 15: caso 3, filho a direita:\n");
    sucesso = retira(&arvore, 15);
    printf("PRE ORDEM: ");
    preOrdem(arvore);

    printf("\n\nREMOVENDO NO 9: caso 4, dois filhos:\n");
    sucesso = retira(&arvore, 9);
    printf("PRE ORDEM: ");
    preOrdem(arvore);
}
/*

    Inicializo um no como nulo.

    Essa funcao recebe ponteiro de ponteiro devido a necessitar setar o conteudo de uma variavel
    ponteiro como nulo. Se nao for ponteiro de ponteiro, e fizermos um t = NULL, ela estara setando
    a variavel "t" do ESCOPO DA FUNCAO "CRIA".

*/
void cria(Node **t)
{

    *t = NULL;
}

/*

    Insiro um no na posicao correta de uma arvore ABB. Primeiro eu percorro a arvore recursivamente
    ate encontrar a posicao certa, e entao eu insiro meu No naquela posicao.

    Essa funcao recebe ponteiro de ponteiro devido a necessitar setar o conteudo de uma variavel
    ponteiro (esq ou dir) como o endereco do novo no. O ponteiro de ponteiro garante que estou
    manipulando o conteudo da variavel correta, ao inves da variavel do escopo dessa funcao.

*/
int insere(Node **t, int dado)
{

    if (*t == NULL)
    {                                      // cheguei na posicao certa, devo inserir
        *t = (Node *)malloc(sizeof(Node)); // aloco um No na memoria e devolvo seu endereco para o conteudo de t
        if (*t == NULL)                    // falha na alocacao
            return 0;

        (*t)->dado = dado; // atribuo o dado ao novo No
        (*t)->esq = NULL;  // esq do meu novo No eh NULL
        (*t)->dir = NULL;  // dir do meu novo No eh NULL

        return 1;
    }

    // se (*t) aponta para um No, recursivamente procuro a posicao certa para inserir

    if (dado < (*t)->dado)               // se o dado eh menor que o dado do No corrente
        return insere(&(*t)->esq, dado); // chamo a funcao recursivamente para o No da esquerda

    return insere(&(*t)->dir, dado); // senao, chamo recursivamente para o No da direita
}

Node *encontraMaxDireita(Node **t)
{
    if ((*t)->dir != NULL) // enquanto nao chegar no No mais a direita, vou descendo para a direita
        return encontraMaxDireita(&(*t)->dir);

    Node *aux = *t;
    if ((*t)->esq != NULL) // se meu no escolhido tiver um filho a esquerda
        *t = (*t)->esq;    // eu movo ele para a sua antiga posicao
    else
        *t = NULL; // se o escolhido nao tem filho, entao quem esta apontando pra ele deve apontar pra NULL

    return aux; // devolvo o no escolhido
}

int retira(Node **t, int dado)
{

    if (*t == NULL)
    { // se cheguei em um no vazio, sinal que o dado nao existe, retorno FALHA
        printf("Elemento inexistente: %d\n\n", dado);
        return 0;
    }

    if (dado < (*t)->dado) // dado menor, movo pra subarvore da esquerda
        return retira(&(*t)->esq, dado);

    if (dado > (*t)->dado) // dado maior, movo para subarvore da direita
        return retira(&(*t)->dir, dado);

    // se nao passei pelas condicoes acima, estou no lugar certo
    // REMOCAO DO NO

    Node *aux = *t; // aux guarda o no a ser removido

    /* 1o caso: nao tenho filhos */
    if (((*t)->esq == NULL) && ((*t)->dir == NULL))
    {
        *t = NULL; // o ponteiro para o no a ser removido recebe null
        free(aux); // libero a memoria
        return 1;
    }

    /* 2o caso: tenho somente o filho da esquerda */
    if ((*t)->dir == NULL)
    {
        *t = (*t)->esq; // o ponteiro para o no a ser removido passa a apontar para o filho esquerdo
        free(aux);      // libero a memoria
        return 1;
    }

    /* 3o caso: tenho somente o filho da direita */
    if ((*t)->esq == NULL)
    {
        *t = (*t)->dir; // o ponteiro para o no a ser removido passa a apontar para o filho direito
        free(aux);
        return 1;
    }

    /*
        4o caso: tenho dois filhos. Nesse caso eu preciso:
        - encontrar o sucessor mais correto, que eh o elemento mais a direita da subarvore a esquerda
        - fazer o sucessor apontar para os filhos do no a ser removido
        - colocar o sucessor no lugar do no a ser removido
        - liberar a memoria
    */

    Node *substituto = encontraMaxDireita(&(*t)->esq); // encontro o no substituto (no mais a direita da subarvore a esquerda)
    substituto->esq = (*t)->esq;                       // substituto recebe o filho a esquerda do no a ser removido
    substituto->dir = (*t)->dir;                       // substituto recebe o filho a direita do no a ser removido
    *t = substituto;                                   // o ponteiro para o no a ser removido passa a apontar para o no substituto
    free(aux);                                         // libero a memoria
    return 1;
}

void preOrdem(Node *t)
{

    if (t != NULL)
    {
        printf("%d ", t->dado);
        preOrdem(t->esq);
        preOrdem(t->dir);
    }
}

void emOrdem(Node *t)
{

    if (t != NULL)
    {
        emOrdem(t->esq);
        printf("%d ", t->dado);
        emOrdem(t->dir);
    }
}

void emDesordem(Node *t)
{

    if (t != NULL)
    {
        emDesordem(t->dir);
        printf("%d ", t->dado);
        emDesordem(t->esq);
    }
}

void posOrdem(Node *t)
{

    if (t != NULL)
    {
        posOrdem(t->esq);
        posOrdem(t->dir);
        printf("%d ", t->dado);
    }
}
