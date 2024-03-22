#include <stdio.h>

int produto(int n) {
    // Caso base: se n for 0, o produto é 1
    if (n == 0) {
        return 1;
    } else {
        // Chamada recursiva: multiplicar n com o produto dos elementos anteriores
        return n * produto(n - 1);
    }
}

int main() {
    // Exemplo de uso da função
    int resultado = produto(5); // Produto de 1 * 2 * 3 * 4 * 5
    printf("O produto eh: %d\n", resultado);

    return 0;
}
