#include <stdio.h>


int main(void) {
    // Declaração de variaveis locais
    char caractere = 65; //'A' = 65
    int contador = 0, idade = 1;
    float tempo = 50.30;
    double distancia = 123.4;
    unsigned short int ano = 65535;

    printf("\nEsse eh o conteudo das variaveis.\n\n");
    printf("Caractere: %\c\n", caractere);
    printf("Contador: %\i\n", contador);
    printf("Idade: %\d\n", idade);
    printf("Tempo: %5.2\f\n", tempo);
    printf("Distancia: %\lf\n", distancia);
    printf("Ano: %\hu\n", ano);

    return 0;
    }

