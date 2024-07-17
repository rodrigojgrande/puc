/*
Pergunta 10 - a
Crie um programa recursivo que some valores de n a 0, com n passado por parâmetro.
*/

#include <stdio.h>

int somatorio(int n);

int main() {
    int resultado = somatorio(3); 
    printf("O somatorio eh igual a: %d\n", resultado);
    return 0;
}

int somatorio(int n) {
    if (n <= 0) {
        return 0;
    } else {
        return n + somatorio(n - 1);
    }
}
/*FIM A*/