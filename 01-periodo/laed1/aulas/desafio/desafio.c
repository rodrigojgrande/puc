#include <stdio.h>

#define int x, y;

int main(void) {

    // Solicitar valores ao usuario
    fprintf(stdout, "Digite o valor de x: ");
    scanf("%d", &x);
    getchar();  // Limpar o buffer do teclado

    fprintf(stdout, "Digite o valor de y: ");
    scanf("%d", &y);
    getchar();  // Limpar o buffer do teclado

    // Trocar os valores sem usar variavel temporaria
    x = x + y;
    y = x - y;
    x = x - y;

    // Exibir os valores trocados
    fprintf(stdout, "\nDepois da troca:\n");
    fprintf(stdout, "x = %d\ny = %d\n", x, y);

    return 0;
}
