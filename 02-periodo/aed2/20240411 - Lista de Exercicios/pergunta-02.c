/*
Pergunta 02
Escreva um programa que solicite ao usuário
que insira três números e, em seguida, 
calcule e exibaa média desses números.
*/

#include <stdio.h>

float calcularMedia(float x, float y, float z);

int main() {
    float primeiroNumero, SegundoNumero, terceiroNumero;

    printf("Insira o primeiro numero: ");
    scanf("%f", &primeiroNumero);

    printf("Insira o segundo numero: ");
    scanf("%f", &SegundoNumero);

    printf("Insira o terceiro numero: ");
    scanf("%f", &terceiroNumero);

    float media = calcularMedia(primeiroNumero, SegundoNumero, terceiroNumero);

    printf("A media dos numeros %.2f, %.2f e %.2f eh: %.2f\n", primeiroNumero, SegundoNumero, terceiroNumero, media);

    return 0;
}

float calcularMedia(float x, float y, float z){
    return (x + y + z) / 3;
}