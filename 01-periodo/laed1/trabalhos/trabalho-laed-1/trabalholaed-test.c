#include <stdio.h>
#include <stdlib.h> //Biblioteca para chamar a funcao rand()

unsigned short int gerarNumeroAleatorio() {
    return (unsigned short int)(rand() % 60 + 1);
}

int main() { // Delaracao da funcao principal

    int i; // Contador
    int numeroSorteado; // Variavel para
    int cartela[61] = {0};

    // Inicializa o gerador de números aleatórios
    srand(time(NULL));

    for(i = 1; i <= 6; i++) {
        do {
            numeroSorteado = (rand() % 60) + 1;
        } while (cartela[numeroSorteado] == 1);

        cartela[numeroSorteado] = 1;

    }

    printf("Os números aleatórios são: ");
    for(i = 1; i <= 60; i++) {
        if (cartela[i] == 1)
        printf("%d ", i);
    }
    printf("\n");

    return 0;
}



printf("Os números aleatórios são: ");

    /
    for(i = 1; i <= 60; i++) {
