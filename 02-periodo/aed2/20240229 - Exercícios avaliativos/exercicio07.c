#include <stdio.h>
#include <stdlib.h>

int main() {
    int n; // N�mero de valores a serem inseridos
    int *vetor; // Ponteiro para o vetor alocado dinamicamente

    // Solicita ao usu�rio o n�mero de valores a serem inseridos
    printf("Informe o numero de valores a serem inseridos: ");
    scanf("%d", &n);

    // Aloca dinamicamente mem�ria para o vetor
    vetor = (int *)malloc(n * sizeof(int));

    // Verifica se a aloca��o de mem�ria foi bem-sucedida
    if (vetor == NULL) {
        printf("Erro na alocacao de memoria.\n");
        return 1; // Retorna c�digo de erro
    }

    // Solicita ao usu�rio inserir os valores no vetor
    printf("Informe os valores a serem inseridos:\n");
    for (int i = 0; i < n; i++) {
        printf("Elemento %d: ", i + 1);
        scanf("%d", &vetor[i]);
    }

    // Imprime os valores inseridos no vetor
    printf("Valores inseridos no vetor:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", vetor[i]);
    }

    // Libera a mem�ria alocada dinamicamente
    free(vetor);

    return 0;
}
