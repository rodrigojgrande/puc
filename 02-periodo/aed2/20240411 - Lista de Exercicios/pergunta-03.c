/*
Pergunta 03
Crie um programa que solicite ao usuário que insira um número e,
em seguida, imprima a tabuadadesse número de 1 a 10.
*/

#include <stdio.h>

int geraTabuada(int valor);

int main() {
    int numero;

    printf("Insira um numero: ");
    scanf("%d", &numero);

    geraTabuada(numero);

}

int geraTabuada(int valor){
    printf("Tabuada do %d:\n", valor);
    for (int i = 1; i <= 10; i++) {
        printf("%d x %d = %d\n", valor, i, valor * i);
    }
    return 0;
}
