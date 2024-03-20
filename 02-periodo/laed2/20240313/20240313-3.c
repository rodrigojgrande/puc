/*
3 - Escreva uma função recursiva que dado dois números inteiros x, n,
calcula o valor de x^n:
exponencial(x, 0) = 1
exponencial(x, n) = x * exponencial(x, n-1)
*/ 

#include <stdio.h>

int exponencial(int x, int n);

int main() {
    int x, n;

    printf("Digite o valor de x: ");
    scanf("%d", &x);
    printf("Digite o valor de n: ");
    scanf("%d", &n);

    printf("%d elevado a %d eh igual a %d\n", x, n, exponencial(x, n));

    return 0;
}

int exponencial(int x, int n) {
    if (n == 0) {
        return 1;
    } else {
        return x * exponencial(x, n - 1);
    }
}