/*
Pergunta 04
Escreva um programa que converta uma temperatura 
em graus Celsius para Fahrenheit, com basena fórmula:
Fahrenheit = (Celsius * 9/5) + 32
*/

#include <stdio.h>

float conversorParaFahrenheit(float celsius);

int main() {
    float celsius;

    printf("Insira a temperatura em graus Celsius: ");
    scanf("%f", &celsius);

    float fahrenheit = conversorParaFahrenheit(celsius);

    printf("%.2f graus Celsius equivalem a %.2f graus Fahrenheit.\n", celsius, fahrenheit);
    
    return 0;
}

float conversorParaFahrenheit(float celsius){
 return (celsius * 9 / 5) + 32;
}