/*
Pergunta 07
Escreva um programa que solicite ao usuário que insira um número inteiro
não negativo e calcule eexiba o fatorial desse número 
(Fatorial de N = N! = N * (N-1) * (N-2) * ... * 1).
*/

#include <stdio.h>

float calcularFatorial(int numero);

int main() {
    int numero, flag;

    do{
        printf("Insira um numero inteiro nao negativo: ");
        scanf("%d", &numero);
        if (numero < 0) {
            printf("Numero negativo inserido. Por favor, insira um numero nao negativo.\n");
            flag = 1;
        } else {
            flag = 0;
        }

    } while (flag == 1);

    printf("O fatorial de %d eh: %.2f\n", numero, calcularFatorial(numero));

    return 0;
}

float calcularFatorial(int numero) {
    if (numero == 0) {
        return 1;
    }
    else {
        return numero * calcularFatorial(numero - 1);
    }
}