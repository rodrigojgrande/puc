#include <stdio.h>
#include <stdlib.h>

// Função para calcular a média dos valores em um vetor
float calcularMedia(int *vetor, int tamanho) {
    float soma = 0.0;

    // Soma todos os elementos do vetor
    for (int i = 0; i < tamanho; i++) {
        soma += vetor[i];
    }

    // Calcula a média
    float media = soma / tamanho;

    return media;
}

int main() {
    int n; // Número de valores a serem inseridos
    int *vetor; // Ponteiro para o vetor alocado dinamicamente

    // Solicita ao usuário o número de valores a serem inseridos
    printf("Informe o numero de valores a serem inseridos: ");
    scanf("%d", &n);

    // Aloca dinamicamente memória para o vetor
    vetor = (int *)malloc(n * sizeof(int));

    // Verifica se a alocação de memória foi bem-sucedida
    if (vetor == NULL) {
        printf("Erro na alocacao de memoria.\n");
        return 1; // Retorna código de erro
    }

    // Solicita ao usuário inserir os valores no vetor
    printf("Informe os valores a serem inseridos:\n");
    for (int i = 0; i < n; i++) {
        printf("Elemento %d: ", i + 1);
        scanf("%d", &vetor[i]);
    }

    // Calcula a média usando a função calcularMedia
    float media = calcularMedia(vetor, n);

    // Imprime a média
    printf("A media dos valores inseridos e: %.2f\n", media);

    // Libera a memória alocada dinamicamente
    free(vetor);

    return 0;
}
