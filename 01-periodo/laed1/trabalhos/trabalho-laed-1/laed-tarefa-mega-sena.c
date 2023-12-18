/*
Tarefa: funcao para gerar numeros da Mega Sena
Elabore um c�digo em linguagem C para gerar seis n�meros aleat�rios no intervalo de 1 at� 60 (inclusive).

Integrantes:
Julia Romao
Rodrigo Grande
*/


#include <stdio.h>
#include <stdlib.h> //Biblioteca para chamar a funcao rand()
#include <time.h> // Biblioteca para execucao da funcao time()

//Funcao para gerar numero aleatorio entre 1 e 60
unsigned short int gerarNumeroAleatorio() {
    return (unsigned short int)(rand() % 60 + 1);
}

int main() { // Delaracao da funcao principal

    unsigned short int i; // Contador
    unsigned short int numeroSorteado; // Variavel para armazenar um numero sorteado
    unsigned short int cartela[61] = {0}; // Variavel em array que simula uma cartela de mega sena, onde todo valor 0 eh falso e todo valor 1 eh um valor sorteado

    srand(time(NULL)); // Inicializa o gerador de numeros aleatorios

    for(i = 1; i <= 6; i++) { // Estrutura de repeticao contando ate 6

        do { // Faca
            numeroSorteado = gerarNumeroAleatorio(); // A variavel recebe um valor sorteado pela funcao
        } while (cartela[numeroSorteado] == 1); // Enquanto numero sorteado for = 1 ele ja foi sorteado, e sai da repeticao quando = 0 (nao foi sorteado)

        cartela[numeroSorteado] = 1; // Recebe valor 1 para indicar que ja foi sorteado e nao possa ser sorteado novamente na estrutura de repeticao)

    }

    printf("Os numeros sorteados foram: "); // Lista os numeros de 1 a 60 e identifica aqueles que receberam o valor 1 anteriormente e os exibe na tela
    for(i = 1; i <= 60; i++) { // Estrutura de repeticao contando ate 60
        if (cartela[i] == 1) // Verifica se o valor da cartela foi sorteado
        printf("%hu ", i); // Escreve na tela o valor sorteado
    }
    printf("\n");

    return 0;
}
