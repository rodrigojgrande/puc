#include <stdio.h>

int somatorio(int n);

int main() {
    // Exemplo de uso da fun��o
    int resultado = somatorio(3); // Somat�rio de 1 + 2 + 3 + 4 + 5
    printf("O somatorio eh igual a: %d\n", resultado);

    return 0;
}

int somatorio(int n) {
    // Caso base: se n for 0, o somat�rio � 0
    if (n <= 0) {
        return 0;
    } else {
        // Chamada recursiva: somar n com o somat�rio dos elementos anteriores
        return n + somatorio(n - 1);
    }
}
