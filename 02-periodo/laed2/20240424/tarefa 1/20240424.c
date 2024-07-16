#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char *action;       // Ação armazenada no nó
    struct Node *next;  // Ponteiro para o próximo nó na pilha
} Node;

typedef struct {
    Node *top;          // Ponteiro para o topo da pilha
} Stack;

void push(Stack *s, char *action);
char *pop(Stack *s);
char *peek(Stack *s);

int main() {
    Stack s;
    s.top = NULL; // Inicializa a pilha como vazia

    push(&s, "Escreve Hello"); // 0 - Escreve Hello
    push(&s, "Escreve World"); // 1 - Escreve World

    printf("Topo da Pilha: %s\n", peek(&s)); // Escreve World

    char *action = pop(&s); // Remove 1 - Escreve World
    printf("Ação desfeita: %s\n", action); // Ação desfeita - Escreve World
    free(action);

    action = pop(&s); // Remove 0 - Escreve Hello
    printf("Ação desfeita: %s\n", action); // Ação desfeita - Escreve Hello
    free(action);

    /* Testar a peek aqui */
    //char *peek(&s);

    return 0;
}

// Empilha
void push(Stack *s, char *action){
    Node *novoNode = (Node *) malloc(sizeof(Node)); // Aloca o node
    if (novoNode == NULL) { // Verifica se a alocação ocorreu corretamente
        printf("Erro ao alocar memória para novo nó!\n");
        return;
    }

    novoNode->action = strdup(action); // Duplica a string da ação
    novoNode->next = s->top; // O próximo do novoNode recebe o topo da stack
    s->top = novoNode; // O topo da stack recebe o novoNode
}

// Desempilha
char *pop(Stack *s){
    if (s->top == NULL) { // Verifica se o topo da pilha está vazio
        printf("Pilha vazia!\n");
        return NULL;
    }

    Node *topNode = s->top; // Topo do node recebe o topo da pilha
    char *action = topNode->action; // O ponteiro de ações recebe a ação do topNode
    s->top = topNode->next; // Topo da pilha recebe o próximo do topNode
    free(topNode);

    return action;
}

// Visualizar
char *peek(Stack *s){
    if (s->top == NULL) { // Verifica se o topo da pilha está vazio
        printf("Pilha vazia!\n");
        return NULL;
    }

    return s->top->action; // Retorna o topo da pilha
}