#include <stdio.h>

// Fun��o que calcula o MDC usando o Algoritmo de Euclides
int mdc(int x, int y) {
    // Caso base: se y � zero, o MDC � x
    if (y <= x && x%y == 0) {
        return y;
    } else if (x < y){
        return mdc(y,x);
    }else {
        // Chamada recursiva usando o Algoritmo de Euclides
        return mdc(y, x % y);
    }
}

int main() {
    // Exemplo de uso da fun��o
    int resultado = mdc(48, 18); // Exemplo com os n�meros 48 e 18
    printf("O MDC eh: %d\n", resultado);
    return 0;
}
