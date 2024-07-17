/*
Pergunta 06
Crie um programa que solicite ao usuário que insira dois números inteiros (um intervalo) e,
emseguida, conte e exiba a quantidade de números pares nesse intervalo.
*/

#include <stdio.h>

int calcularPares(int inicio, int fim);

int main() {
    int inicio, fim;
    
    printf("Insira o primeiro numero do intervalo: ");
    scanf("%d", &inicio);

    printf("Insira o segundo numero do intervalo: ");
    scanf("%d", &fim);

    int total = calcularPares(inicio, fim);

    printf("\nTotal de numeros pares: %d\n", total);

    return 0;
}

int calcularPares(int inicio, int fim){
    int quantidadePares = 0;

    if (inicio > fim) {
        int aux = inicio;
        inicio = fim;
        fim = aux;
    }

    printf("Numeros pares no intervalo [%d, %d]:\n", inicio, fim);
    for (int i = inicio; i <= fim; i++) {
        if (i % 2 == 0) {
            printf("%d ", i);
            quantidadePares++;
        }
    }

    return quantidadePares;
}